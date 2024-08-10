//
// Created by simon on 2024-08-05.
//
#include <bits/stdc++.h>

const int N = 1e5 + 10;

int* solve(int b[], int m, int n) {
    int *result = new int[N];

    for (int i =0 ; i < n; i ++ ) {
        result[i] = b[i + m];
    }

    for (int i = 0; i < m; i ++) {
        result[i + n] = b[i];
    }

    return result;
}

int main() {

    int m = 2, n = 3;

    int a[N] = {1, 2, 3, 4, 5};

    int *result = solve(a, m, n);

    for (int i = 0; i < n + m; i ++) std::cout << result[i] << " ";

    return 0;
}