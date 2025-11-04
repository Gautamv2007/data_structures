#include <stdio.h>
#include <time.h>

int* find(int n, int arr[], int i, int len){
    if (i == len - 1) return NULL;
    if (arr[i] == n) return &arr[i];
    find(n, arr, ++i, len);
}

int main(void){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int *ptr;
    time_t starttime1 = time(NULL);
    ptr = find(3, arr, 0, 6);
    time_t endtime1 = time(NULL);
    printf("%p\n", find(2, arr, 0, 6));
    printf("%p\n", ptr);
    printf("The time taken for the first address is %f minutes", (float)difftime(endtime1, starttime1) / 60);
}