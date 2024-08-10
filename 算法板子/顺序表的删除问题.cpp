
// 前面删除几个，后面就向前移动几位

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
