/**
 * author: Jayanth PSY
 * GitHub: https://github.com/j-tesla
 *
 * # MERGE SORT
 * Time Complexity: worst case O( nlogn)
 */

#include <iostream>

using namespace std;

typedef int size_type;
typedef int key_type;

void merge(key_type Arr[], size_type start, size_type mid, size_type end) {
    // create a temp array
    key_type temp[end - start + 1];

    // crawlers for both intervals and for temp
    size_type i = start, j = mid + 1, k = 0;

    // traverse both arrays and in each iteration add smaller of both elements in temp
    while (i <= mid && j <= end) {
        if (Arr[j] > Arr[i]) {
            temp[k] = Arr[i];
            k += 1;
            i += 1;
        } else {
            temp[k] = Arr[j];
            k += 1;
            j += 1;
        }
    }

    // add elements left in the first interval
    while (i <= mid) {
        temp[k] = Arr[i];
        k += 1;
        i += 1;
    }

    // add elements left in the second interval
    while (j <= end) {
        temp[k] = Arr[j];
        k += 1;
        j += 1;
    }

    // copy temp to original interval
    for (i = start; i <= end; i += 1) {
        Arr[i] = temp[i - start];
    }
}

void merge_sort(key_type Arr[], size_type start, size_type end) {
    if (start < end) {
        size_type mid = (start + end) / 2;
        merge_sort(Arr, start, mid);
        merge_sort(Arr, mid + 1, end);
        merge(Arr, start, mid, end);
    }
}

int main() {
    size_type n = 10;
    key_type array[] = {3, 20, 5, 6, 88, 46, 123, -5, 555, 66};

    merge_sort(array, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << array[i] << ", ";
    }
    cout << endl;
    return 0;
}
