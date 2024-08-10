//
// Created by simon on 2024-08-04.
//
#include <bits/stdc++.h>

const int N = 1e5 + 10;

typedef struct {
    int data[N];
    int length;
}SqList;

bool solve(SqList &sqList, int &result) {
    if (sqList.length == 0) {
        // 如果表空，返回false
        return false;
    }

    result = sqList.data[0];
    int pos = 0;
    for (int i = 0; i < sqList.length; i ++) {
        if (result > sqList.data[i]) {
            result = sqList.data[i];
            pos = i;
        }
    }

    sqList.data[pos] = sqList.data[sqList.length - 1];
    sqList.length --;

    return true;
}


int main() {

    SqList sqlist;
    sqlist.data[0] = 5;
    sqlist.data[1] = 2;
    sqlist.data[2] = 1;
    sqlist.data[3] = 4;

    sqlist.length = 4;

    int result = 0;
    int flag = solve(sqlist, result);
    if (!flag) {
        std::cout << "error" << std::endl;
    } else {
        std::cout << "minnumber is " << result << std::endl;
        std::cout << "删除后: ";
        for (int i = 0; i < sqlist.length; i ++) {
            std::cout << sqlist.data[i] <<  " ";
        }
    }



    return 0;
}