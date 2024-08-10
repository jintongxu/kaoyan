//
// Created by simon on 2024-08-01.
//

#include <bits/stdc++.h>

int solve(int nums[], int length,int target) {
    for (int i = 0; i < length; i ++) {
        if (nums[i] == target) return i;
        if (i < length - 1 && nums[i] < target && nums[i + 1] > target) return i + 1;
    }
}

int main() {
    int target1 = 50;
    int nums1[] = {2,5,6,9,11,30,45,66};

    int pos = solve(nums1, sizeof(nums1) / sizeof(nums1[0]),target1);
    std::cout << pos << std::endl;
    return 0;
}
