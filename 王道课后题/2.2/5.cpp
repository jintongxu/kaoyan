//
// Created by simon on 2024-08-05.
//

#include <bits/stdc++.h>

const int N = 1e5 + 10;

typedef struct {
    int data[N];
    int length;
}SqList;

void solve(SqList &sq) {
    int count = 0;
    int flag[N];
    std::memset(flag, 0, sizeof flag);

    for (int i = 0; i < sq.length; i ++) {
        if (++flag[sq.data[i]] > 1) {
            count++;
            continue;
        }

        sq.data[i - count] = sq.data[i];
    }

    sq.length -= count;
}

int main(){
    SqList sqlist;
    sqlist.data[0] = 1;
    sqlist.data[1] = 2;
    sqlist.data[2] = 3;
    sqlist.data[3] = 2;
    sqlist.data[4] = 3;

    sqlist.length = 5;

    solve(sqlist);

    for (int i = 0; i < sqlist.length; i ++) {
        std::cout << sqlist.data[i] <<  " ";
    }


    return 0;
}