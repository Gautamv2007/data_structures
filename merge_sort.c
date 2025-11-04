#include <stdio.h>

void merge(int arr[], int lb, int mid, int ub){
    int n1 = mid - lb + 1;
    int n2 = ub - mid;

    int L[n1];
    int R[n2];

    for(int i = 0;i<n1;i++){
        L[i] = arr[lb + i];
    }
    for(int j = 0;j<n2;j++){
        R[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0, k = lb;

    while(i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}


void sort(int arr[], int lb, int rb){
    if (lb < rb){
        int mid = (lb + rb) / 2;
        sort(arr, lb, mid);
        sort(arr, mid + 1, rb);
        merge(arr, lb, mid, rb);
    }
}


int main(void){
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0;i<n;i++) scanf("%d", &arr[i]);

    sort(arr, 0, n-1);
    for(int i = 0;i<n;i++) printf("%d ", arr[i]);
}







