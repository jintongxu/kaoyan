#include <iostream>

void solve(int nums[], int num_length) {
    if (nums[0] < nums[1]) {
        // ??????
        for (int i = 1; i < num_length; i ++ ) {
            if (nums[i] < nums[i - 1]) {
                // ??? ????????????????
                std::cout << "??????" << std::endl;
                return;
            }
        }
    } else {
        for (int i = 1; i < num_length; i ++ ) {
            if (nums[i] > nums[i - 1]) {
                // ??? ?????????s????????
                std::cout << "??????" << std::endl;
                return;
            }
        }
    }

    std::cout << "????" << std::endl;
}


int main() {

    int num1[] = {1,3,47,5,9,10};

    solve(num1, sizeof(num1) / sizeof(num1[0]));





    return 0;
}

