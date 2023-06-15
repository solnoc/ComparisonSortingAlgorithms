#include "back_mark_core.hpp"
#include <iostream>

int main()
{
    bench_mark_core bmc;

    bmc.total_banchmark();
    
 /* 
    long nr_of_elements = 1000;
    long max_nr = 1000;
    long long seconds = 10;

    std::cout<<"Please enter the number of elements: ";
    std::cin>>nr_of_elements;
    std::cout<<"Please enter the maximum number: ";
    std::cin>>max_nr;
    std::cout<<"Please enter the number of seconds: ";
    std::cin>>seconds;

    bench_mark_core::benchmark_result bubble_sort_result = bmc.benchmark(bubble_sort, nr_of_elements, max_nr, seconds);
    bench_mark_core::benchmark_result heap_sort_result = bmc.benchmark(heap_sort, nr_of_elements, max_nr, seconds);
    bench_mark_core::benchmark_result selection_sort_result = bmc.benchmark(selection_sort, nr_of_elements, max_nr, seconds);
    bench_mark_core::benchmark_result quick_sort_result = bmc.benchmark(quick_sort, nr_of_elements, max_nr, seconds);
    bench_mark_core::benchmark_result counting_sort_result = bmc.benchmark(counting_sort, nr_of_elements, max_nr, seconds);
    bench_mark_core::benchmark_result radix_sort_result = bmc.benchmark(radix_sort, nr_of_elements, max_nr, seconds);

    std::cout<<"Bubble sort:"<<std::endl;
    bmc.print_benchmark_result(bubble_sort_result);

    std::cout<<"Heap sort:"<<std::endl;
    bmc.print_benchmark_result(heap_sort_result);

    std::cout<<"Selection sort:"<<std::endl;
    bmc.print_benchmark_result(selection_sort_result);

    std::cout<<"Quick sort:"<<std::endl;
    bmc.print_benchmark_result(quick_sort_result);

    std::cout<<"Counting sort:"<<std::endl;
    bmc.print_benchmark_result(counting_sort_result);

    std::cout<<"Radix sort:"<<std::endl;
    bmc.print_benchmark_result(radix_sort_result);
*/
    return 0;
}