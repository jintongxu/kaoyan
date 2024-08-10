//
// Created by simon on 2024-07-31.
//

#include <iostream>

int* solve(int nums[], int target, int length) {
    int *p = new int[2];
    for (int i = 0; i < length - 1; i ++ ) {
        for (int j = 1; j < length; j ++ ) {
            if (nums[i] + nums[j] == target) {
                p[0] = i;
                p[1] = j;
                return p;
            }
        }
    }
}

int main() {
    int num1[] = {3, 2, 6, 9};
    int target = 11;

    int num2[] = {1, 3, 5, 7, 9, 10};
    int target2 = 11;

    int num_length = sizeof(num2) / sizeof(num2[0]);

    int *result = solve(num2, target, num_length);

    std::cout << result[0] << " " << result[1] << std::endl;
}