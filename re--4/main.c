#include <stdio.h>
#include <stdlib.h>



 int main(){
     char nom [10];
     char prenom[15];
     int age ;
     char sex [10];
     char tele[30];

 printf ("votre nom ; ");
  scanf ("%s",nom) ;
  printf("votre prénom ; ");
  scanf("%s",prenom);
  printf ("votre age ; ");
  scanf ("%d",&age);
  printf("votre sex ; ");
  scanf("%s",sex);
  printf("entrer votre numéro de téléphone ; ");
  scanf( "%s", tele);
  printf(" *VOTRE NOM est: %s",nom);
  printf("\n *VOTRE PRENOM est: %s",prenom);
  printf("\n *VOTRE AGE est: %d",age);
  printf("\n *VOTRE SEX est: %s",sex);
  printf("\n *votre TELE est: %s",tele);

 }




