#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Exercício 2
void swapM (int *x, int *y){
    int aux;
    aux=*x;  // aux fica com o conteudo de x
    *x=*y;
    *y=aux;
}
// & apontador, &x apontador para x

// Exercício 3
void swap (int v[], int i, int j){
    int aux;
    aux=v[i];
    v[i]=v[j];
    v[j]=aux;
}

// Exercício 4
int soma (int v[], int N){
    int r=0;
    for(;N>=1;N--){
        r+=v[N-1];
    }
    return r;
}

//Exercício 5
void inverteArray (int v[], int N){
    int i;
    for(i=0;i<N/2; i++){
        swap(v,i,N-1-i);
    }
}

// Exercício 6
int maximum1 (int v[], int N, int *m){
    *m=v[0];
    int i;
    for(i=1;i<N;i++){
        if (v[i]>*m){
            *m=v[i];
        }
    }
    return 0;
}

// Exercício 7
void quadrados (int q[], int N){
    q[0]=0;
    int i;
    for (i=1;i<N;i++){
        q[i]=q[i-1]+2*(i-1)+1;
    }
}

// Exercício 8 
//a)
void pascal (int v[], int N){
    int l,c;
    v[0]=1;
    for(l=1;l<N;l++){
        v[l]=1;
        for(c=l-1;c>0;c--){
            v[c]=v[c]+v[c-1];
        }
        
    }
}

// b)  Fazer um ciclo para imprimir

int main()
{
    int x[5]={10,1,2,3,4};
    int *i;
    int c;
    pascal(x,4);
    printf("%d  %d  %d  %d ", x[0],x[1],x[2],x[3]);
    return EXIT_SUCCESS;
}