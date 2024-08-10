//
// Created by simon on 2024-08-05.
//

#include <bits/stdc++.h>

const int N = 1e5 + 10;

int* solve(int list[], int n, int p) {
    int *tmp = new int[N];
    if (p % n == 0) {
        // 如果移动的等于数组长度，相当于没移动
        tmp = list;
        return tmp;
    }

    for (int i = 0; i < n - p; i ++ ) tmp[i] = list[i + p];

    for (int i = 0; i < p; i ++) tmp[i + n - p] = list[i];

    return tmp;
}

int main() {

    int a[N] = {1, 2, 3, 4, 5, 6};
    int *result = solve(a, 6, 6);

    for (int i = 0; i < 6; i ++) std::cout << result[i] << " ";

    return 0;
}
