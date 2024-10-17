#include "Memoire.h"
void FIFO(struct cases *p1,int *p2,int n1,int n2,int *defaut){
    int test,k=0;
    for(int i=0;i<n1;i++){
        test=0;
        for(int j=0;j<n2;j++){
            if (*(p2+i)==((p1+j)->contenu)&&(((p1+j)->state)==1)){
                test=1;
            }
        }
        if(test==0){
            *defaut=*defaut+1;
            if(k<n2){
                ((p1+k)->contenu)=(*(p2+i));
                ((p1+k)->state)=1;
                k++;
            }else{
                k=0;
                ((p1+k)->contenu)=(*(p2+i));
                ((p1+k)->state)=1;
                k++;
            }
        }
    }
}
