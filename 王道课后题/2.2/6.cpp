//
// Created by simon on 2024-08-05.
//
#include <bits/stdc++.h>

const int N = 1e5 + 10;

typedef struct {
    int data[N];
    int length = 0;
}SqList;

SqList* solve(SqList list1, SqList list2) {
    SqList* result = new SqList;

    int i = 0, j = 0, k = 0;  // k 是 result的索引

    while(i < list1.length and j < list2.length) {
        if (list1.data[i] > list2.data[j]) {
            result->data[k++] = list2.data[j++];
        } else {
            result->data[k++] = list1.data[i++];
        }
        result->length++;
    }

    // 注意 后面这两个 while 循环的条件+
    while(i < list1.length) {
        result->data[k++] = list1.data[i++];
        result->length++;
    }

    while(j < list2.length) {
        result->data[k++] = list2.data[j++];
        result->length++;
    }

    return result;
}


int main() {
    SqList sqlist1;
    sqlist1.data[0] = 1;
    sqlist1.data[1] = 2;
    sqlist1.data[2] = 3;
    sqlist1.data[3] = 4;
    sqlist1.length = 4;

    SqList sqlist2;
    sqlist2.data[0] = 5;
    sqlist2.data[1] = 8;
    sqlist2.data[2] = 7;
    sqlist2.length = 3;

    SqList *result = solve(sqlist1, sqlist2);

    for (int i = 0; i < result->length; i ++) {
        std::cout << result->data[i] << " ";
    }


    delete result;

    return 0;
}