//
//  main.cpp
//  quick-sort
//
//  Created by John Liao on 12/9/15.
//  Copyright © 2015 John Liao. All rights reserved.
//

#include <iostream>

void swap(int *x, int*y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int * A, int lo, int hi) {
    int i = lo;
    int pivot = A[hi];
    
    for (int j=lo; j<hi; j++) {
        if (A[j] <= pivot) {
            swap(&A[i],&A[j]);
            i++;
        }
    }
    swap(&A[i],&A[hi]);
    
    return i;
}

void quicksort(int * A, int lo, int hi) {
    if (lo<hi) {
        int p = partition(A, lo, hi);
        quicksort(A, lo, p-1);
        quicksort(A, p+1, hi);
    }
}

int main() {

    int arr[] = {9,1,3,2,8};
    std::cout << "Starting array" << std::endl;
    
    for (int x=0; x<5; x++) {
        std::cout << arr[x] << " ";
    }
    std::cout << std::endl;
    quicksort(arr,0,4);

    for (int x=0; x<5; x++) {
        std::cout << arr[x] << " ";
    }
}
