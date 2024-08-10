//
// Created by simon on 2024-08-05.
//

#include <bits/stdc++.h>

const int N = 1e5 + 10;

typedef struct {
    int data[N];
    int length;
}SqList;

void solve(SqList &sq, int length, int target) {
    int count = 0;
    for (int i = 0; i < length; i ++) {
        if (sq.data[i] == target) {
            count ++;
            continue;
        }
        sq.data[i - count] = sq.data[i];
    }
    sq.length -= count;
}


int main() {

    SqList sqlist;
    sqlist.data[0] = 1;
    sqlist.data[1] = 3;
    sqlist.data[2] = 3;
    sqlist.data[3] = 3;
    sqlist.data[4] = 3;

    sqlist.length = 5;

    solve(sqlist, sqlist.length, 3);

    for (int i = 0; i < sqlist.length; i ++) {
        std::cout << sqlist.data[i] <<  " ";
    }



    return 0;
}
