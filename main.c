#include <stdio.h>
#include <stdlib.h>
#include "Memoire.h"
int main() {
    int n,nr,choice,defaut;
    defaut=0;

    struct cases *pt;

    do{
        printf("Donner le nombre de cases  :");
        scanf("%i",&n);}
    while(n<0);


    pt = (struct cases*) malloc(n * sizeof(struct cases));

    for(int i=0;i<n;i++){
        ((pt+i)-> N)=i+1;
        ((pt+i)-> state)=0;
        ((pt+i)-> contenu)=0;

    }
    printf("Les adresse des pages frames aloues libre sont: \n");
    printf("Numeros de Case \t Adresse \t\t State \t\t Contenu\n");

    for(int i=0;i<n;i++){
        printf("%d \t\t\t %p \t %d \t\t %d \n",(pt+i)->N,pt+i,(pt+i)->state,(pt+i)->contenu);
    }


    printf("le nombre de pages a referencier est:\n");
    scanf("%d",&nr);

    int *ptr;
    ptr=(int*)malloc(nr*4);

    printf("donner les pages a referencier :\n");
    for(int i=0;i<nr;i++){
        scanf("%d",ptr+i);
    }


    printf("choissir l'algorithme d'allocation :\n\t [1]:FIFO \n\t [2]:LRU \n\t [3]:LFU \n\t [4]:Second Chance \n");
    scanf("%d",&choice);
    struct pages *ptr1;
    ptr1=(struct pages*)malloc(2*(n*4));

    switch(choice){
        case 1: FIFO(pt,ptr,nr,n,&defaut); break;
        case 2: LRU(pt,ptr,ptr1,nr,n,&defaut); break;
        case 3: LFU(pt,ptr,ptr1,nr,n,&defaut); break;
        case 4: SecondChance(pt,ptr,ptr1,nr,n,&defaut); break;
        default: printf("ERREUR"); return -1;
    }

    printf("Les adresse des pages frames aloues libre sont: \n");
    printf("Numeros de Case \t Adresse \t\t State \t\t Contenu\n");


    for(int i=0;i<n;i++){
        printf("%d \t\t\t %p \t %d \t\t %d \n",(pt+i)-> N,pt+i,(pt+i)->state,(pt+i)->contenu);
    }


    printf("le defaut de page est : %d \n",defaut);

    free(pt);
    free(ptr);
    free(ptr1);
    return 0;
}
