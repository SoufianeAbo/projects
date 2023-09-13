#include stdio.h
 int main ()
 {
    char myLastName[17];
    char myName[16]; 
    int Age;
    char Sex;
    float NumPhone;

    printf(Your Last Name );
    scanf(%s, &myLastName);
    printf(nYour Name );
    scanf(%s , &myName);
    printf(nYour Age );
    scanf(%d , &Age);
    printf(nYour sex );
    scanf(%s , &Sex);
    printf(nYour phone Num +);
    scanf(%f, &NumPhone);

    return 0;
 }