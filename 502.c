#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Listas Ligadas
typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

// 1
int length (LInt l){
    int i;
    for(i=0;l!=NULL;i++) l=l->prox;
    return i;
}

//2
void freeL (LInt l){
    int i;
    LInt temp;
    for(i=0;l!=NULL;i++) {temp=l;l=l->prox;free(temp);}
}

//3
void imprimeL (LInt l){
    int i;
    for(i=0;l!=NULL;i++){printf("%d \n",l->valor); l=l->prox;}
}

//4 - refazer sozinha
LInt reverseL (LInt l){
   LInt aux , ant = NULL;
    while (l != NULL){
        aux = l->prox;
        l->prox = ant;
        ant = l;
        l = aux;
    }
    return ant;
}

//5 - rever
LInt newLInt(int x, LInt l){
    LInt r;
    r=malloc(sizeof(struct lligada));
    r->valor=x;
    r->prox=l;
    return r;
}
void insertOrd (LInt *l, int x){
    LInt *sitio,nova;
    sitio=l;
    while(*sitio!=NULL && (*sitio)->valor<x){sitio=&((*sitio)->prox);}
    nova=newLInt(x,*sitio);
    *sitio=nova;
}

//6  - refazer
int removeOneOrd (LInt *l, int x){
   int r = 1;
    LInt aux = *l;


    if (aux == NULL);
    else if ( aux->prox == NULL && (aux)->valor == x) {
        free(*l);
        *l = NULL;
        r=0;
    }

    LInt prev;
    while (aux != NULL && r == 1){
        if (aux->valor == x){
            prev->prox = aux->prox;
            free(aux);
            r=0;
        }
        prev = aux;
        aux= aux->prox;
    }

    return r;
}

// 7
void merge (LInt *r, LInt a, LInt b){
    LInt *ultimo=r;
    if (a==NULL) *r=b;
    if (b==NULL) *r=a;
    while(a!=NULL && b!=NULL){
         if(a->valor<b->valor){*ultimo=a;a=a->prox;ultimo=&((*ultimo)->prox);}
        else{*ultimo=b;b=b->prox;ultimo=&((*ultimo)->prox);}
    }
    if (a==NULL) *ultimo=b;
    if (b==NULL) *ultimo=a;

}

//8 - ver do novo
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    *mx = NULL; *Mx = NULL;
    
    while(l){
        if(l->valor < x){
            *mx = l;
            mx = &((*mx)->prox);
        }else{
            *Mx = l;
            Mx = &((*Mx)->prox);
        }
        l = l->prox;
    }
    
    *mx = NULL; *Mx = NULL;
}

//9 - ver de novo
LInt parteAmeio (LInt *l){
    int mid = length(*l)/2;
    LInt y = *l; LInt* curr = &y;
    
    while(mid > 0){
        curr = &((*curr)->prox);
        mid--;
    }
    
    *l = *curr;
    *curr = NULL;
    return y;
}
// 10 - rever
int removeAll (LInt *l, int x){
    int c = 0;
    while(*l){
        if((*l)->valor == x){
            LInt temp = (*l)->prox;
            free(*l);
            *l = temp;
            c++;
        }else{
            l = &((*l)->prox);
        }
    }
    return c;
}

//11
int removeDups (LInt *l){
    int c=0;
    while(*l){
        int valore=(*l)->valor;
        LInt *ciclo=&((*l)->prox);
        while(*ciclo){
            if((*ciclo)->valor == valore){
            LInt temp = (*ciclo)->prox;
            free(*ciclo);
            *ciclo = temp;
            c++;
        }else{
            ciclo = &((*ciclo)->prox);
        }
        }
        l=&((*l)->prox);
    }
    return c;
}

//12
int removeMaiorL (LInt *l){
    LInt *sitio=l;
    int maior = (*l)->valor;
    while(*l){
        if((*l)->valor>maior){maior=(*l)->valor;sitio=l;}
        l=&((*l)->prox);
    }
    LInt tmp=(*sitio)->prox;
    free(*sitio);
    *sitio=tmp;
    return maior;
}

//13
void init (LInt *l) {
    while((*l)->prox!=NULL) l=&((*l)->prox);
    LInt tmp=*l;
   free(*l);
   *l=NULL;
}

//14
void appendL (LInt *l, int x){
    if((*l)==NULL) *l=newLInt(x,NULL);
     else{while((*l)->prox!=NULL) l=&((*l)->prox);
    (*l)->prox=newLInt(x,NULL);}
}

//15
void concatL (LInt *a, LInt b){
    while((*a)!=NULL) a=&((*a)->prox);
    *a=b;
}

//16
LInt cloneL (LInt l){
    LInt out=NULL;
    while(l!=NULL){
        out=newLInt(l->valor,NULL);
        out=out->prox;
        l=l->prox;
    }
    return out;
}

//17
 LInt cloneRev (LInt l){
    LInt out=NULL;
    while(l!=NULL){
        out=newLInt(l->valor,out);
        l=l->prox;
    }
    return out;
 }

//18
int maximo (LInt l){
    int max=l->valor;
    while(l){
        if(l->valor>max)max=l->valor;
        l=l->prox;
    }
    return max;
}

//19
int take (int n, LInt *l){
    int count=n;
    while(count && *l!=NULL){
        l=&((*l)->prox);
        count--;
    }
    n=n-count;
    while(*l!=NULL){
        LInt tmp = (*l)->prox;
        free(*l);
        *l=tmp;
    }
    return n;
}

//20
int drop (int n, LInt *l){
     int count=n;
    while(count && *l!=NULL){
        LInt tmp=(*l)->prox;
        free(*l);
        *l=tmp;
        count--;
    }
    return n-count;
}

//21
LInt Nforward (LInt l, int N){
    while(N){
        l=l->prox;
        N--;
    }
    return l;
}

//22
int listToArray (LInt l, int v[], int N){
    int ll=N;
    while(l && N){
        v[ll-N]=l->valor;
        N--;
        l=l->prox;
    }
    return ll-N;
}

//23 - Rever
LInt arrayToList (int v[], int N){
    int i = 0;
    LInt new = NULL;
    LInt* newAd = &new;
    
    for(; i < N; i++, newAd = &(*newAd)->prox){
        *newAd = malloc(sizeof(struct lligada));
        (*newAd)->valor = v[i];
        (*newAd)->prox = NULL;
    }
    
    return new;
}

//24
LInt somasAcL (LInt l){
    int acum=0;
    LInt sol;
    LInt *ssol=&sol;
    while(l!=NULL){
        *ssol=malloc(sizeof(struct lligada));
        acum+=l->valor;
        (*ssol)->valor=acum;
        (*ssol)->prox=NULL;
        ssol=&(*ssol)->prox;
        l=l->prox;
    }
    return sol;

}

//25
     void remreps (LInt l){
       while(l){
             int valore=l->valor;
             LInt *ciclo=&(l->prox);
             while(*ciclo && (*ciclo)->valor==valore){
                LInt temp=(*ciclo)->prox;
                free(*ciclo);
                *ciclo=temp;
             }
             l=l->prox;
         }
     }

//26
LInt rotateL (LInt l){
    if(l==NULL || l->prox==NULL) return l;
    LInt prim=l;
    LInt out=l->prox;
    while(l->prox!=NULL){
        l=l->prox;
    }
    l->prox=prim;
    prim->prox=NULL;
    return out;
}

//27 -rever
LInt parte (LInt l){
       LInt y = NULL; LInt* yad = &y;
    LInt L = l;    LInt* Lad = &l;
    
    if(l){
        int i = 1;
        Lad = &(*Lad)->prox;
        l = l->prox;
        
        while(l){
            if(i % 2 == 0){
                *Lad = l;
                Lad = &(*Lad)->prox;
            }else{
                *yad = l;
                yad = &(*yad)->prox;
            }
            l = l->prox;
            i++;
        }
        *Lad = *yad = NULL;
    }
    return y;
}