#include <stdio.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lb, int ub){
    int pivot = arr[ub];
    int i = lb - 1;

    for(int j = lb;j<ub;j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[ub]);
    return (i+1);
}


void sort(int arr[], int lb, int ub){
    if (lb < ub){
        int pi = partition(arr, lb, ub);

        sort(arr, lb, pi-1);
        sort(arr, pi+1, ub);
    }
}

int main(void){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0;i<n;i++) scanf("%d", &arr[i]);

    sort(arr, 0, n-1);

    for(int i = 0;i<n;i++) printf("%d ", arr[i]);
//    int arr[8] = {7,2,1,5,3,6,8,4};
//    partition(arr,0, 7);
//    for(int i = 0;i<8;i++) printf("%d ", arr[i]);
}

