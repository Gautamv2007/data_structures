#include <stdio.h>
#include <time.h>

int main(void){
    int p;
    scanf("%d", &p);
    time_t starttime1 = time(NULL);
    int a = 0;
    for(int i = 2;i<p;i++){
        if (p % i == 0){
            a = 1;
            break;
        }
    }
    time_t endtime1 = time(NULL);
    if (a == 1) printf("Not a prime.\n");
    else printf("It is a prime.\n");
    printf("The time taken is %f.", difftime(starttime1, endtime1));

}