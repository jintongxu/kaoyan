//
// Created by simon on 2024-08-05.
//

#include <bits/stdc++.h>

const int N = 1e5 + 10;

typedef struct {
    int data[N];
    int length;
}SqList;

bool solve(SqList &sq, int s, int t) {
    if (sq.length == 0 or s > t or s < 0 or t > sq.length) {
        return false;
    }

    int count = 0;
    for (int i = 0; i < sq.length; i ++) {
        if (sq.data[i] >= s and sq.data[i] <= t) {
            count++;
            continue;
        }
        sq.data[i - count] = sq.data[i];
    }

    sq.length -= count;

    return true;
}

int main() {
    SqList sqlist;
    sqlist.data[0] = 2;
    sqlist.data[1] = 2;
    sqlist.data[2] = 5;
    sqlist.data[3] = 4;

    sqlist.length = 4;

    int s = 2, t = 4;
    if (solve(sqlist, s, t)) {
        for (int i = 0; i < sqlist.length; i ++) {
            std::cout << sqlist.data[i] <<  " ";
        }
    } else {
        std::cout << "error";
    }

    return 0;

}
