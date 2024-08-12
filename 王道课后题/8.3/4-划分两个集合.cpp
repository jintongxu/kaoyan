//
// Created by simon on 2024-08-09.
//
#include <iostream>

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[(l + r) / 2];

    while(i < j) {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if (i < j) std::swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {

    int n = 6;      // 数组长度
    int a[] = {1, 4, 5, 6, 16, 2};
    quick_sort(a, 0, 5);

    for (int i = 0; i < n; i ++ ) std::cout << a[i] << " \n"[i == n - 1];




    int s1 = 0, s2 = 0;
    for (int i = 0; i < n / 2; i ++) {
        s1 += a[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i ++ ) sum += a[i];

    s2 = sum - s1;

    std::cout << std::abs(s1-s2) << std::endl;



    return 0;
}
