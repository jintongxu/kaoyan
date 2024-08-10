//
// Created by simon on 2024-08-05.
//
#include <bits/stdc++.h>

const int N = 1e5 + 10;

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l+r>>1];

    while(i < j) {
        do i ++; while(q[i] < x);
        do j --; while(q[j] > x);
        if (i < j) std::swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int solve(int a[], int n) {
    int flag = 1;
    for (int i = 0; i < n; i ++ ) {
        if (a[i] < 0) continue;
        if (a[i] == flag){
            flag++;
        } else {
            return flag;
        }

    }

    // 1 2 3 这种，前面都匹配 是最后缺少的
    return flag;
}



int main() {

    int a[] = {1,2,3};
    int n = 3;

    quick_sort(a, 0, n - 1);

    int result = solve(a, n);

//    for (int i = 0; i < n; i ++ ) std::cout << a[i] << " ";

    std::cout << result;



    return 0;
}