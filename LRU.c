#include "Memoire.h"

void LRU(struct cases *p1, int *p2,struct pages *p,int n1,int n2,int *defaut){
    int test,m,k,M;
    for(int i=0;i<n1;i++){
        M=0;
        m=0;
        k=0;
        test=0;
        for(int j=0;j<n2;j++){
            if(((p+j)->compteur)>M){
                M=((p+j)->compteur);
                m=j;
            }
            if (*(p2+i)==((p1+j)->contenu)&&(((p1+j)->state)==1)){
                test=1;
                k=j;
            }
        }
        if(test==0){
            *defaut=*defaut+1;
            for(int j=0;j<n2;j++){
                if(((p1+j)->state)==0){
                    m=j;
                    break;
                }
            }
            ((p1+m)->contenu)=(*(p2+i));
            ((p1+m)->state)=1;
            ((p+m)->compteur)=0;
            for(int j=0;j<n2;j++){
                if(j!=m){
                    ((p+j)->compteur)=((p+j)->compteur)+1;
                }
            }
        }else{
            ((p+k)->compteur)=0;
            for(int j=0;j<n2;j++){
                if(j!=k){
                    ((p+j)->compteur)=((p+j)->compteur)+1;
                }
            }
        }
    }
}