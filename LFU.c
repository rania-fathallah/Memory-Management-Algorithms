#include "Memoire.h"
void LFU(struct cases *p1, int *p2,struct pages *p,int n1,int n2,int *defaut){
    int test,m,k,M,o;
    for(int i=0;i<n1;i++){
        M=((p)->compteur);
        m=0;
        k=0;
        test=0;
        o=((p)->N1);
        for(int j=0;j<n2;j++){
            if((((p+j)->compteur)<=M)&&(((p+j)->N1)<o)||(((p+j)->compteur)<M)){
                M=((p+j)->compteur);
                o=(((p+j)->N1)<o);
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
            ((p+m))->N1=i;
            ((p1+m)->contenu)=(*(p2+i));
            ((p1+m)->state)=1;
            ((p+m)->compteur)=1;
        }else{
            ((p+k)->compteur)=((p+k)->compteur)+1;
        }
    }
}