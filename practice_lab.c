#include <stdio.h>

void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

void sort(int arr[], int n){
  for(int i = 1;i<n;i++){
    int x = arr[i];
    int j;
    for(j = i-1;j>=0;j--){
      if (arr[j] > x){
        arr[j+1] = arr[j];

      }
      else break;
    }
    arr[j+1] = x;
  }
}

int main(void){
  int arr[5] = {1, 4, 3, 2, 5};
  sort(arr, 5);
  for(int i = 0;i<5;i++){
    printf("%d ", arr[i]);
  }
}

