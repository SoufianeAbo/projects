#include <stdio.h>
#include <stdlib.h>

int main()
{
    int F,C ;
    printf ("entrer la temperature farenheit: ");
    scanf("%d",&F);
C = (F-32)/1.8;
printf ("la temperature celciuce:  %d",C);

     if (C<10){
            printf(" tres froid");
     } else if (C>10 && C<30) {
   printf(" froid");
     }else if (C>30 && C<40) {
        printf(" chaud");
     }else{
        printf(" tres chaud");
     }


}
