#include <stdio.h>
int main(void){
  int arr[10] = {1, 2, 3, 4, 5};
  int temp;
  scanf("%d", &temp);
  for(int i = 0;i<5;i++){
    int k = arr[i];
    arr[i] = temp;
    temp = k;
  }
  arr[5] = temp;
  for(int i = 0;i<6;i++){
    printf("%d ", arr[i]);
  }
}
