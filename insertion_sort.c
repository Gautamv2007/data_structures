#include <stdio.h>


void sort(int arr[], int n){
  for(int i = 1;i<n;i++){
    int x = arr[i];
    int j;
    for(j = i-1;j>=0;j--){
      if(arr[j] > x){
        arr[j+1] = arr[j];
      }
      else break;
    }
    arr[j+1] = x;
  }
}

int main(void){
  printf("Enter the number of elements: ");
  int n;
  scanf("%d", &n);
  int arr[100];
  for(int i = 0;i<n;i++){
    scanf("%d", &arr[i]);
  }
  int *k = arr;
  sort(k, n);
  for(int i = 0;i<n;i++){
    printf("%d ", arr[i]);
  }
}
