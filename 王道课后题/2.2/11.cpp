//
// Created by simon on 2024-08-05.
//

#include <bits/stdc++.h>

const int N = 1e5 + 10;

int solve(int list1[], int list2[], int length) {
    int i = 0, j = 0, k = 0;  // list1 list2 tmp的指针索引

    // 先将序列按升序合并到临时数组
    int tmp[N] = {};
    while(i < length and j < length) {
        if (list1[i] <= list2[j]) tmp[k++] = list1[i++];
        else tmp[k++] = list2[j++];
    }

    while(i < length) {
        tmp[k++] = list1[i++];
    }

    while(j < length) {
        tmp[k++] = list2[j++];
    }

    // 然后找中位数
    return tmp[length];
}

int main() {

    int a[] = {11, 13, 15, 17, 19};
    int b[] = {2, 4, 6, 8, 20};

    int result = solve(a, b, 5);

    std::cout << result;

    return 0;
}
