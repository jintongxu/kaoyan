//
// Created by simon on 2024-08-05.
//

#include <bits/stdc++.h>

typedef struct {
    int data[100];
    int length;
}SqList;

//目标值比数组中所有元素都大：此时，l 最终会指向数组的最后一个元素。如果我们没有检查 target > sq.data[l] 并且直接插入，那么目标值会插入到倒数第二个位置，而不是最后一个位置。这就是为什么需要 if (target > sq.data[l]) l++; 这一检查。
//
//目标值比数组中所有元素都小：l 会指向数组的第一个元素，target 应插入到数组的开头位置。
//
//目标值在数组中的某个位置之间：l 会指向比 target 大的最小元素的位置，此时需要将 target 插入到 l 的位置，将 l 及其后面的元素向后移动一位。
void solve(SqList &sq, int target) {
    int l = 0, r = sq.length - 1;
    while(l < r) {
        int mid = l + r >> 1;
        if (target <= sq.data[mid]) r = mid;
        else l = mid + 1;
    }

    // 若最后一个元素与target相等，则不会有交换
    if (sq.data[l] == target and l != sq.length - 1) {
        std::swap(sq.data[l], sq.data[l+1]);
    }

//    std::cout << l;
    // 处理边界情况，当目标值大于最后一个元素时
    if (target > sq.data[l]) l++;

    for (int i = sq.length; i > l; i --) sq.data[i] = sq.data[i - 1];
    sq.data[l] = target;
    sq.length++;
}


int main() {

    SqList sqlist;
    sqlist.data[0] = 1;
    sqlist.data[1] = 2;
    sqlist.data[2] = 5;
    sqlist.data[3] = 6;
    sqlist.data[4] = 7;

    sqlist.length = 5;

    solve(sqlist, 8);

    for (int i = 0; i < sqlist.length; i ++) {
        std::cout << sqlist.data[i] <<  " ";
    }

    return 0;
}
