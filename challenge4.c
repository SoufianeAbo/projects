#include <stdio.h>

int main()
{
    int a;
    int b; 
    int c;
    int d;

    printf("enter your enteger: ");
    scanf("%d %d %d %d" , &a , &b , &c , &d);
    int sum = a + b + c + d;
    printf("\n votre sum is %d: " , sum);
    printf("\n votre sum is %d: " , sum / 4);

    return 0;
}