#include <stdio.h>
void hanoi(int n,char t1,char t2,char t3);

main(void){
        int n;
        printf("please in put the num of the first tower");
        scanf("%d",&n);
        hanoi(n,'1','2','3');
}

void hanoi(int n,char t1,char t2,char t3){

        if (n==1)
                printf(" move No.%d from tower%c to tower%c\n",n,t1,t3);
        else {
        hanoi(n-1,t1,t3,t2);
        printf(" move No.%d from tower%c to tower%c\n",n,t1,t3);
        hanoi(n-1,t2,t1,t3);
        }
}       
