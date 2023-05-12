#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0) {
        return nullptr;
    }
    if (arrSize == 1) {
        return &(arr[0]);
    }
    else {
        const int *minLocation = min(arr, arrSize - 1);
        if (*minLocation < arr[arrSize - 1]) {
            return minLocation;
        }
        else {
            return &(arr[arrSize - 1]);
        }
    }
}