//
// Created by simon on 2024-08-05.
//

#include <bits/stdc++.h>

const int N = 1e5 + 10;

void solve(int list1[], int list2[], int list3[], int n) {
    int i = 0, j = 0, k = 0;

    while(i < n and j < n and k < n) {
        // 三个相同就输出
        if (list1[i] == list2[j] and list2[j] == list3[k]) {
            std::cout << list1[i] << std::endl;
            i++, j++, k++;      // 每个指针都向前走一下，递增的，当前输出了，该值肯定就不能用了。
        } else {
            int nowMaxValue = std::max(list1[i], std::max(list2[j], list3[k]));
            // 相同的不可能是最小值，因为递增的；可能是最大值，因为递增，有可能都递增到最大值
            if (list1[i] < nowMaxValue) i++;
            if (list2[j] < nowMaxValue) j++;
            if (list3[k] < nowMaxValue) k++;
        }


    }
}

int main() {

    int a[N] = {1, 2, 3};
    int b[N] = {2, 3, 4};
    int c[N] = {-1, 0, 2};

    solve(a, b, c, 3);

    return 0;
}
