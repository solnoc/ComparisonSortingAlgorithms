class bench_mark_core
{
public:
    struct benchmark_result
    {
        double average_time_ms;
        long long nr_of_sorts;
        long long nr_of_elements;
        long long max_nr;
    };
    struct banchmark_settings
    {
        long long* nr_of_elements;
        long long nr_of_elements_size;
        long long* max_nr;
        long long max_nr_size;
        long long seconds;
    };

private:
    long long* generate_array_with_random_numbers(long long n, long long max_nr);
    double benchmark_sorting_algorithm(long long nr_of_elements, long long max_nr, void (*sorting_alg)(long long*, long long));
    benchmark_result get_result_n_sec(long long nr_of_elements, long long max_nr, long long seconds, void (*sorting_alg)(long long*, long long));
    bool isSorted(long long* array, long long n);

public:
    benchmark_result benchmark(void (*sorting_alg)(long long*, long long), long long nr_of_elements, long long max_nr, long long seconds);
    benchmark_result* progressive_benchmark(void (*sorting_alg)(long long*, long long), banchmark_settings settings);
    void total_banchmark();
    void print_benchmark_result(benchmark_result result);

};