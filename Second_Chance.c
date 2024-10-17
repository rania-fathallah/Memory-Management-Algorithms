#include "Memoire.h"
void SecondChance(struct cases *p1, int *p2,struct pages *p,int n1,int n2,int *defaut){
    int test,q,auxC,auxS,test2,q1;
    for(int i=0;i<n1;i++){
        q1=-1;
        test=0;
        test2=0;
        for(int j=0;j<n2;j++){
            if (*(p2+i)==((p1+j)->contenu)&&(((p1+j)->state)==1)){
                test=1;
                q=j;
            }
            if((((p1+j)->state)==0)&&(q1<0)){
                q1=j;
            }
        }
        if(test==0){
            *defaut=*defaut+1;
            if(q1>-1){
                ((p1+q1)->contenu)=(*(p2+i));
                ((p1+q1)->state)=1;
                ((p+q1)->compteur)=1;}
            else{
                do{
                    if(((p)->compteur)==0){
                        test2=1;
                        for(int j=0;j<n2-1;j++){
                            ((p1+j)->contenu)=((p1+j+1)->contenu);
                            ((p1+j)->state)= ((p1+j+1)->state);
                            ((p+j)->compteur)=((p+j+1)->compteur);
                        }
                        ((p1+n2-1)->contenu)=(*(p2+i));
                        ((p1+n2-1)->state)=1;
                        ((p+n2-1)->compteur)=1;
                    }else{
                        auxC=((p1)->contenu);
                        auxS=((p1)->state);
                        for(int j=0;j<n2-1;j++){
                            ((p1+j)->contenu)=((p1+j+1)->contenu);
                            ((p1+j)->state)= ((p1+j+1)->state);
                            ((p+j)->compteur)=((p+j+1)->compteur);
                        }
                        ((p1+n2-1)->contenu)=auxC;
                        ((p1+n2-1)->state)=auxS;
                        ((p+n2-1)->compteur)=0;
                    }
                }while(test2==0);
            }
        }else{
            ((p+q)->compteur)=1;
        }
    }
}