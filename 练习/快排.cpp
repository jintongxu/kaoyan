#include <iostream>


const int N = 1e5 + 10;

void quick_sort(int a[], int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = a[(l + r) / 2];
    while(i < j) {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if (i < j) std::swap(a[i], a[j]);
    }

    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}


int main()
{

    int n = 6;
    int q[] = {1, 5, 2, 4, 6, 8};

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i ++ ) std::cout << q[i] << ' ';

    return 0;
}