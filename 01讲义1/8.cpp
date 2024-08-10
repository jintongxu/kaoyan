//
// Created by simon on 2024-08-01.
//

#include <bits/stdc++.h>

int* solve(int list1[], int lenght) {
    int i = 0, j = lenght - 1;


    int *p = new int[lenght];
    for (int k = 0; k < lenght; k ++) {
        if (list1[k] % 2 == 0) {
            p[i++] = list1[k];
        } else {
            p[j--] = list1[k];
        }
    }

    return p;
}

int main() {

    int nums[] = {5, 2, 3, 6, 8, 9, 4};

    int length = sizeof nums / sizeof nums[0];


    int *result = solve(nums, length);

    for (int i = 0; i < length; i ++ ) std::cout << result[i] << " ";

    return 0;
}
