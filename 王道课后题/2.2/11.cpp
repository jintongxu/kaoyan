//
// Created by simon on 2024-08-05.
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
    quick_sort(q, j + 1, r );
}

int solve(int a1[], int a2[], int n, int m) {

    // 将两个数组合并成一个大数组
    int tmp_length = n + m;
    int tmp[tmp_length];

    for (int i = 0; i < n; i ++) tmp[i] = a1[i];

    for (int i = n; i < n + m; i ++) tmp[i] = a2[i - n];

    

    // 快排
    quick_sort(tmp, 0, n + m - 1);
    for (int i = 0; i < n + m; i ++) std::cout << tmp[i] <<  " \n"[i == n + m - 1];
    std::cout << (n + m) / 2 << std::endl;

    return (tmp[(n + m - 1) / 2]);

}


int main() {
    int n = 5, m = 5;
    int a[] = {11, 13, 15, 17, 19};
    int b[] = {2, 4, 6, 8, 20};

    int result = solve(a, b, n, m);

    std::cout << result << std::endl;


    return 0;

}



// 第一次自己做的解，结果没问题，思路太慢
// const int N = 1e5 + 10;

// int solve(int list1[], int list2[], int length) {
//     int i = 0, j = 0, k = 0;  // list1 list2 tmp的指针索引

//     // 先将序列按升序合并到临时数组
//     int tmp[N] = {};
//     while(i < length and j < length) {
//         if (list1[i] <= list2[j]) tmp[k++] = list1[i++];
//         else tmp[k++] = list2[j++];
//     }

//     while(i < length) {
//         tmp[k++] = list1[i++];
//     }

//     while(j < length) {
//         tmp[k++] = list2[j++];
//     }

//     // 然后找中位数
//     return tmp[length];
// }

// int main() {

//     int a[] = {11, 13, 15, 17, 19};
//     int b[] = {2, 4, 6, 8, 20};

//     int result = solve(a, b, 5);

//     std::cout << result;

//     return 0;
// }
