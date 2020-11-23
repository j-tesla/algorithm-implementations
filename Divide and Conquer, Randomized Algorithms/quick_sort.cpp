#include <iostream>

using namespace std;

typedef int size_type;
typedef int key_type;

/*
 *  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
 *        i       j           k
 *    ^       ^         ^            ^
 *    |       |         |            |
 *   < p     == p   unprocsed       > p   
 */
void partition(key_type Arr[], size_type left, size_type right, size_type &pivot_l, size_type &pivot_r) {
    key_type p = Arr[pivot_l];
    swap(Arr[left], Arr[pivot_l]);
    size_type i = left, j = left + 1, k = right;

    while (j <= k) {
        if (Arr[j] == p)
            ++j;
        else if (Arr[j] < p) {
            swap(Arr[i], Arr[j]);
            ++i;
            ++j;
        } else {
            swap(Arr[j], Arr[k]);
            --k;
        }
    }

    pivot_l = i;
    pivot_r = j - 1;
}

void quick_sort(key_type Arr[], size_type left, size_type right) {
    if (right > left) {
        // choose pivot
        // size_type pivot_l = left;                                // left as pivot (not random)

        size_type pivot_l = left + rand() % (right - left + 1);     // random pivot

        size_type pivot_r = pivot_l;
        partition(Arr, left, right, pivot_l, pivot_r);
        quick_sort(Arr, left, pivot_l - 1);
        quick_sort(Arr, pivot_r + 1, right);
    }
}

int main() {
    size_type n = 6;
    key_type array[] = {1, -10, 5, 6, 9, 2};

    quick_sort(array, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }

    return 0;
}
