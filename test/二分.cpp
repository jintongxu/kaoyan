//
// Created by simon on 2024-08-05.
//

#include <bits/stdc++.h>

int bsearch(int a[], int l, int r, int target) {
    while(l < r) {
        int mid = l + r >> 1;
        if (target <= a[mid]) r = mid;
        else l = mid + 1;
    }

    if (a[l] != target) return -1;
    else return l;
}

int main() {

    int b[] = {1, 2, 3, 4, 5, 6};

    std::cout << bsearch(b, 0, 6, 5);

    return 0;
}
