#include <iostream>

using namespace std;

#include "minFunc.h"

int main() {
   //int arrSize;
   /*cin >> arrSize;
   if (arrSize > 0) {
      int arr[arrSize];
      for (int i = 0; i < arrSize; ++i) {
         cin >> arr[i];
      }
      const int *minLoc = min(arr, arrSize);
      cout << *minLoc << endl;
   } */

   int arr[4] = {1, 2, 3, 4};
   const int *minLoc = min(arr, 4);
   cout << *minLoc << endl;
   return 0;
}
