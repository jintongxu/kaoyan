//
// Created by simon on 2024-08-01.
//
#include <bits/stdc++.h>

const int N = 1e5 + 10;

int* solve(int a1[], int length1, int a2[], int length2) {
    int *result = new int[N];

    int i = 0, j = 0, k = 0;
    int cur = 0;

    while(i < length1 || j < length2) {
        if (i == length1) {
            cur = a2[j++];
        } else if (j == length2) {
            cur = a1[i++];
        } else if (a1[i] <= a2[j]) {
            cur = a1[i++];
        } else {
            cur = a2[j++];
        }

        result[k++] = cur;
    }

    return result;
}

int main() {
    int nums1[] = {3, 5, 6, 9};
    int nums2[] = {1, 3, 5, 7};

    int *p = solve(nums1, sizeof nums1 / sizeof nums1[0], nums2, sizeof nums2 / sizeof nums2[0]);

    for (int i = 0; i < 8; i++) std::cout << p[i] << " ";

    return 0;
}