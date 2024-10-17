#ifndef GESTION_DE_MEMOIRE_MEMOIRE_H
#define GESTION_DE_MEMOIRE_MEMOIRE_H
struct cases {
    int N;
    int state;
    int contenu;
};
struct pages{
    int N1;
    int compteur;
};

void FIFO(struct cases *p1,int *p2,int n1,int n2,int *defaut);
void LRU(struct cases *p1, int *p2,struct pages *p,int n1,int n2,int *defaut);
void LFU(struct cases *p1, int *p2,struct pages *p,int n1,int n2,int *defaut);
void SecondChance(struct cases *p1, int *p2,struct pages *p,int n1,int n2,int *defaut);
#endif //GESTION_DE_MEMOIRE_MEMOIRE_H
