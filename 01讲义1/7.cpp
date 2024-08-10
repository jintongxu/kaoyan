//
// Created by simon on 2024-08-01.
//
#include <bits/stdc++.h>

const int N = 1e5 + 10;

int a[N];

int solve(int L[], int length) {
    for (int i = 0; i < length; i ++) a[L[i]] ++;
    for (int i = 0; i < 1e5 + 10; i ++) {
        if (a[L[i]] == 1) return L[i];
    }
}

int main() {
    int nums[] = {11, 11, 45};

    std::cout << solve(nums, sizeof nums / sizeof nums[0]);

    return 0;
}