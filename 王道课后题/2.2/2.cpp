//
// Created by simon on 2024-08-04.
//
#include <bits/stdc++.h>

const int N = 1e5 + 10;

typedef struct {
    int data[N];
    int length;
}SqList;

void solve(SqList &sq) {
    for (int i = sq.length - 1; i > 0; i -- ) {
        for (int j = 0; j < i; j ++ ) {
            std::swap(sq.data[j], sq.data[j + 1]);
        }
    }
}

int main() {
    SqList sqlist;
    sqlist.data[0] = 1;
    sqlist.data[1] = 2;
    sqlist.data[2] = 3;
    sqlist.data[3] = 4;

    sqlist.length = 4;

    solve(sqlist);
    for (int i = 0; i < sqlist.length; i ++) {
        std::cout << sqlist.data[i] <<  " ";
    }

    return 0;
}