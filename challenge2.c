#include <stdio.h>
 int main ()
 {
    float degre ;
    printf("enter your temperature :");
    scanf("%f" , &degre);
    
    float Celsius = (degre - 32 ) * 5/9;
    
    printf("\n your temperature %.2f" , Celsius );
    if (Celsius < 5)
    {
        printf(" its very cold");
    }else if (Celsius < 20)
    {
        printf(" its cold");
    }
    else if (Celsius < 30)
    {
        printf(" its hot");
    }else {
        printf(" its very hot");
    }
    
    
    
    return 0;
 }