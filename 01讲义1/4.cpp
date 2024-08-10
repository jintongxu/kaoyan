//
// Created by simon on 2024-08-01.
//

#include <bits/stdc++.h>

const int N = 100;

// 定义顺序表结构
typedef struct {
    int data[N] = {3, 5, 6, 9, 2, 3,10, 3, 11};
    int length=9;
}sqllist;

// 时间复杂度太高
//void solve(sqllist &list1, int target) {
//    for (int i = 0; i < list1.length; i ++) {
//        if (list1.data[i] == target) {
//            if (i == list1.length - 1) {
//                list1.length --;
//            } else {
//                for (int j = i; j < list1.length; j ++) {
//                    std::swap(list1.data[j], list1.data[j + 1]);
//                }
//            }
//            list1.length--;
//            i--;
//        }
//    }
//
//}



void solve(sqllist &l, int target) {
    int count = 0;
    for (int i = 0; i < l.length; i ++) {
        if (l.data[i] == target) {
            count ++;
        } else {
            l.data[i - count] = l.data[i];
        }
    }
    l.length -= count;

}

int main() {

    sqllist a1;
    int target1 = 3;



//    int a2[] = {2, 5, 6, 9, 11, 5, 30, 45, 66};
//    int target2 = 5;
//    int length2 = 9;


//    solve(a1, target1, length1);
     solve(a1, target1);

//    std::cout << length;
    for (int i = 0; i < a1.length; i ++ )  std::cout << a1.data[i] << std::endl;


    return 0;
}