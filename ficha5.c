#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a){
    int n=0;
    n=0.75*a.teste +  0.25*10*(a.miniT[0]+a.miniT[1]+a.miniT[2]+a.miniT[3]+a.miniT[4]+a.miniT[5])/6;
    if (n<10) return 0;
    return n;
}

int procuraNum (int num, Aluno t[], int N){
    int i;
    for(i=0;i<N;i++){
        if(t[i].numero==num) return i;
    }
    return -1;
}
void swapV(Aluno v[], int i, int j){
    Aluno aux;
    aux=v[i];
    v[i]=v[j];
    v[j]=aux;
}
void ordenaPorNum (Aluno t [], int N){
    int i,j;
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
            if (t[j].numero<t[i].numero) swapV(t,i,j);
        }
    }

}


int main()
{
    Aluno b={2,"paulo",{2,2,2,2,2,2},15};
    char x[60]="Ola";
    int i;
    int c[10]={2,2,3,4,5,6,7,8,9,90};
    i=nota(b);
    printf("  %d ",i);
    return EXIT_SUCCESS;
}