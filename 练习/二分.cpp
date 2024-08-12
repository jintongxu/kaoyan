#include <iostream>

const int N = 1e5 + 10;


int bsearch(int a[], int l, int r, int target) {
    while(l < r) {
        int mid = (l + r) / 2;
        if (target <= a[mid]) r = mid;
        else l = mid + 1;
    }

    if (a[l] != target) return -1;
    else return l;
}


int main() {

    int a[N] = {1, 4, 5, 7};

    int result = bsearch(a, 0, 3, 7);

    std::cout << result;


    return 0;
}