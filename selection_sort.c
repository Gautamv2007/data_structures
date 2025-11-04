#include <stdio.h>

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void selection_sort(int arr[], int n){
    for(int i = 0;i<n-1;i++){
        int k = i;
        for(int j = i;j<n;j++){
            if(arr[k] > arr[j]){
                k = j;
            }
        }
        swap(&arr[i], &arr[k]);
    }
}


int main(void){
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n);
    for(int i = 0;i<n;i++){
        printf("%d ", arr[i]);
    }
}