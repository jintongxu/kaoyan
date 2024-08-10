//
// Created by simon on 2024-08-05.
//
#include <bits/stdc++.h>

const int N = 1e5 + 10;

int solve(int list[], int length) {
    int flag[N];
    std::memset(flag, 0, sizeof flag);

    for (int i = 0; i < length; i ++) {
        if (++flag[list[i]] > length / 2) return list[i];
    }

    return -1;


}

int main() {

    int a[8] = {0, 5, 5,3,5,1,5,7};

    int result = solve(a, 8);

    std::cout << result;

    return 0;
}
