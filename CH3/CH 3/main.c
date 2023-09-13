#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int b;

    printf("type here: ");
    scanf("%d %d", &a,&b);

    printf("\n a+b  %d", a + b);
    printf("\n a-b  %d", a-b );
    printf("\n a*b  %d", a*b );
    printf("\n a/b  %d", a / b);
    printf("\n a%b  %d",a % b);
}
