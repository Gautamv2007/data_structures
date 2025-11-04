#include <stdio.h>

int recurse(int arr[], int lb, int ub, int key){
  if (lb > ub) return -1;
  int mid = (lb + ub) / 2;
  if(arr[mid] == key) return mid;
  else if (key < arr[mid]) return recurse(arr, lb, mid - 1, key);

  else return recurse(arr, mid + 1, ub, key);
}

int main(void){
  int arr[10];
  printf("Enter 5 numbers: ");
  for(int i = 0;i<5;i++){
    scanf("%d", &arr[i]);
  }
  printf("Enter the number to search:\n");
  int out;
  scanf("%d", &out);
  int k = recurse(arr, 0, 4, out);
  printf("%d", k);
}
