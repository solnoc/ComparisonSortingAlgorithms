void inline swap(long long& a, long long& b) {
    long long temp = a;
    a = b;
    b = temp;
}

bool inline min(long long a, long long b) {
    return a < b;
}

void bubble_sort(long long* arr, long long size) {
    for (long long i = 0; i < size; i++) {
        for (long long j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selection_sort(long long* arr, long long size) {
    for (long long i = 0; i < size; i++) {
        long long min = i;
        for (long long j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void heapify(long long* arr, long long size, long long i) {
    long long largest = i;
    long long left = 2 * i + 1;
    long long right = 2 * i + 2;
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heap_sort(long long* arr, long long size) {
    for (long long i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    for (long long i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void merge(long long* arr, long long l, long long m, long long r) {
    long long n1 = m - l + 1;
    long long n2 = r - m;
    long long* L = new long long[n1];
    long long* R = new long long[n2];
    for (long long i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (long long j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    long long i = 0;
    long long j = 0;
    long long k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void merge_sort(long long* arr, long long size)
{
    long long* temp = new long long[size];
    for (long long i = 1; i < size; i *= 2) {
        for (long long j = 0; j < size - i; j += 2 * i) {
            long long l = j;
            long long m = j + i - 1;
            long long r = min(j + 2 * i - 1, size - 1);
            merge(arr, l, m, r);
        }
    }
    delete[] temp;
}

void quick_sort(long long* arr, long long l, long long r) {
    if (l < r) {
        long long pivot = arr[r];
        long long i = l - 1;
        for (long long j = l; j < r; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[r]);
        long long p = i + 1;
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
    }
}

void quick_sort(long long* arr, long long size) {
    quick_sort(arr, 0, size - 1);
}

void counting_sort(long long* arr, long long size) {
    long long max = arr[0];
    for (long long i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    long long* count = new long long[max + 1];
    for (long long i = 0; i < max + 1; i++) {
        count[i] = 0;
    }
    for (long long i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    for (long long i = 1; i < max + 1; i++) {
        count[i] += count[i - 1];
    }
    long long* output = new long long[size];
    for (long long i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (long long i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    delete[] count;
    delete[] output;
}

void radix_sort(long long* arr, long long size)
{
    long long max = arr[0];
    for (long long i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (long long exp = 1; max / exp > 0; exp *= 10) {
        long long* output = new long long[size];
        long long count[10] = { 0 };
        for (long long i = 0; i < size; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        for (long long i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (long long i = size - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (long long i = 0; i < size; i++) {
            arr[i] = output[i];
        }
        delete[] output;
    }
}