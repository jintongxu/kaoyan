//
// Created by simon on 2024-08-06.
//

#include <bits/stdc++.h>

const int N = 1e5 + 10;

int solve(int a1[], int a2[], int a3[], int len1, int len2, int len3) {

    int minValue = 0x3f3f3f3f;

    for (int i = 0; i < len1; i ++ ) {
        for (int j = 0; j < len2; j ++) {
            for (int k = 0; k < len3; k ++) {
                int tmp = std::abs(a1[i] - a2[j]) + abs(a2[j] - a3[k]) + std::abs(a3[k] - a1[i]);
                minValue = std::min(minValue, tmp);
            }
        }
    }

    return minValue;

}


int main() {

    int s1[] = {-1, 0, 9};
    int s2[] = {-25, -10, 10, 11};
    int s3[] = {2, 9, 17, 30, 41};

    int n = 3, m = 4, z = 5;
    int result = solve(s1, s2, s3, n, m, z);

    std::cout << result;

    return 0;
}