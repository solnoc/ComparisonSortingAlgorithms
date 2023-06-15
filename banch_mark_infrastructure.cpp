#include "back_mark_core.hpp"
#include "sorting_algorithms.cpp"
#include <iostream>

long long* bench_mark_core::generate_array_with_random_numbers(long long n, long long max_nr)
{
    long long* a = new long long[n];
    for (long long i = 0; i < n; i++)
    {
        a[i] = rand() % max_nr;
    }
    return a;
}

double bench_mark_core::benchmark_sorting_algorithm(long long nr_of_elements, long long max_nr, void (*sorting_alg)(long long*, long long))
{
    long long* array = generate_array_with_random_numbers(nr_of_elements, max_nr);

    clock_t start = clock();
    sorting_alg(array, nr_of_elements);
    clock_t stop = clock();

    if (!isSorted(array, nr_of_elements))
    {
        std::cout << "Array is not sorted!" << std::endl;
    }

    delete[] array;
    return (stop - start) / double(CLOCKS_PER_SEC) * 1000;
}

bench_mark_core::benchmark_result bench_mark_core::get_result_n_sec(long long nr_of_elements, long long max_nr, long long seconds, void (*sorting_alg)(long long*, long long))
{
    benchmark_result result;
    result.nr_of_elements = nr_of_elements;
    result.max_nr = max_nr;
    result.nr_of_sorts = 0;
    result.average_time_ms = 0;

    double time = 0;
    while (time < seconds * 1000)
    {
        time += benchmark_sorting_algorithm(nr_of_elements, max_nr, sorting_alg);
        result.nr_of_sorts++;
    }
    result.average_time_ms = time / result.nr_of_sorts;

    return result;
}

bench_mark_core::benchmark_result bench_mark_core::benchmark(void (*sorting_alg)(long long*, long long), long long nr_of_elements, long long max_nr, long long seconds)
{
    return get_result_n_sec(nr_of_elements, max_nr, seconds, sorting_alg);
}

bench_mark_core::benchmark_result* bench_mark_core::progressive_benchmark(void (*sorting_alg)(long long*, long long), banchmark_settings settings)
{
    benchmark_result* results = new benchmark_result[settings.nr_of_elements_size * settings.max_nr_size];
    long long index = 0;
    for (long long i = 0; i < settings.nr_of_elements_size; i++)
    {
        for (long long j = 0; j < settings.max_nr_size; j++)
        {
            results[index] = get_result_n_sec(settings.nr_of_elements[i], settings.max_nr[j], settings.seconds, sorting_alg);

            print_benchmark_result(results[index]);
            std::cout<<std::endl;

            index++;
        }
    }
    
    return results;
}

void bench_mark_core::total_banchmark()
{
    for(long long nr_of_elements = 10; nr_of_elements < 1000000000000000000; nr_of_elements *= 10)
    {
        long double times[6];
        for(int time = 0 ; time < 10 ; time++)
        {
            long long* starting_array = generate_array_with_random_numbers(nr_of_elements, 500000);

            void (*sorting_alg)(long long*, long long);
            for (int i = 0 ;i<6; i++)
            {    
                long long* array = new long long[nr_of_elements];
                for (long long i = 0; i < nr_of_elements; i++)
                {
                    array[i] = starting_array[i];
                }
                try
                {
                    switch(i)
                    {
                    case 0:
                        if(nr_of_elements > 100000)
                        {
                            std::cout << "Bubble sort is too slow for this number of elements!" << std::endl;
                            times[0] = -1;
                            continue;
                        }

                        sorting_alg = bubble_sort;
                        break;
                    case 1:
                        sorting_alg = heap_sort;
                        break;
                    case 2:
                        if(nr_of_elements > 100000)
                        {
                            std::cout << "Counting sort is too slow for this number of elements!" << std::endl;
                            times[0] = -1;
                            continue;
                        }
                        sorting_alg = selection_sort;
                        break;
                    case 3:
                        sorting_alg = quick_sort;
                        break;
                    case 4:
                        sorting_alg = counting_sort;
                        break;
                    case 5:
                        sorting_alg = radix_sort;
                        break;
                    }
            
                    clock_t start = clock();
                    sorting_alg(array, nr_of_elements);
                    clock_t stop = clock();

                    if (!isSorted(array, nr_of_elements))
                    {
                        std::cout << "Array is not sorted!" << std::endl;
                    }

                    times[i] += (stop - start) / double(CLOCKS_PER_SEC) * 1000;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';

                    std::cerr << "i = " << i << std::endl;
                    std::cerr << "Failed to sort!" << std::endl;
                }
                delete[] array;
            }
            delete[] starting_array;
        }
        for(int q =0; q<6; q++)
        {
            times[q] /= 10;
        }
        std::cout << "Nr of elements: " << nr_of_elements << std::endl;
        std::cout << "Bubble sort: " << times[0] << " ms average" << std::endl;
        std::cout << "Heap sort: " << times[1] << " ms average" << std::endl;
        std::cout << "Selection sort: " << times[2] << " ms average" << std::endl;
        std::cout << "Quick sort: " << times[3] << " ms average" << std::endl;
        std::cout << "Counting sort: " << times[4] << " ms average" << std::endl;
        std::cout << "Radix sort: " << times[5] << " ms average" << std::endl;
        std::cout << std::endl;

        for(int q =0; q<6; q++)
        {
            times[q] = 0;
        }
    }
}

void bench_mark_core::print_benchmark_result(benchmark_result result)
{
    std::cout << "Average time: " << result.average_time_ms << " ms" << std::endl;
    std::cout << "Nr of sorts: " << result.nr_of_sorts << std::endl;
    std::cout << "Nr of elements: " << result.nr_of_elements << std::endl;
    std::cout << "Max nr: " << result.max_nr << std::endl;
}

bool bench_mark_core::isSorted(long long* array, long long n)
{
    for (long long i = 0; i < n - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}