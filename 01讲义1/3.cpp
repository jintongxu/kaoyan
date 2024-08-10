//
// Created by simon on 2024-07-31.
//

#include <iostream>

void solve(int num) {
    if (num < 0 || (num % 10 ==0 && num != 0)) {
        std::cout << "false" << std::endl;
        return;
    }

    int revertedNum = 0;
    while(num > revertedNum) {
        revertedNum = revertedNum * 10 + num % 10;
        num /= 10;
    }

    if (num == revertedNum || num == revertedNum / 10) {
        std::cout << "true" << std::endl;
    }
}

int main() {

    int num = 1221;

    solve(num);

    return 0;
}