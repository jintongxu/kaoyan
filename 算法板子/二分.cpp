目标值比数组中所有元素都大：此时，l 最终会指向数组的最后一个元素。如果我们没有检查 target > sq.data[l] 并且直接插入，那么目标值会插入到倒数第二个位置，而不是最后一个位置。这就是为什么需要 if (target > sq.data[l]) l++; 这一检查。

目标值比数组中所有元素都小：l 会指向数组的第一个元素，target 应插入到数组的开头位置。

目标值在数组中的某个位置之间：l 会指向比 target 大的最小元素的位置，此时需要将 target 插入到 l 的位置，将 l 及其后面的元素向后移动一位。

int bsearch(int l, int r, int target)
{
    while(l < r)
    {
        int mid = l + r >> 1;
        if (target <= q[mid]) r = mid;
        else l = mid + 1;
    }

    if (q[l] != target) return -1;
    else return l;
}