#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Exercício 1
int isVogal(char s){
    if(s=='a'||s=='A'||s=='e'||s=='E'||s=='i'||s=='I'||s=='o'||s=='O'||s=='U'||s=='u') return 1;
    return 0;
}
int contaVogais (char *s){
    int i,count=0;
    for(i=0;s[i]!='\0';i++){
        if (isVogal(s[i])) count++;
    }
    return count;

}

//Exercício 2 
int retiraVogaisRep (char *s){
    int i,j=0,count=0;
    for(i=0;s[i]!='\0';){
        s[j]=s[i];
        i++;
        while(isVogal(s[i])&&s[i]==s[j]){i++;count++;}
        j++;
    }
    s[j]='\0';
    return count;
}

//Exercício 3
int duplicaVogais (char *s){
    int vogais,j,i=0,count=0;
    vogais=contaVogais(s);
    j=strlen(s);
    i=j;
    j=j+vogais;
    while(i>=0){
        s[j]=s[i];
        j--;
        if (isVogal(s[i])){
            s[j]=s[i];
            j--;
            count++;
        }
        i--;
    }
    return count;
}

// Parte 2 - arrays ordenados
//Exercício 1
int ordenado (int v[], int N){
    int i;
    for(i=0;i<N-1;i++){
        if (v[i+1]<v[i]) return 0;
    }
    return 1;
}

//Exercicio 2
void merge (int a[], int na, int b[], int nb, int r[]){
    int i=0,j=0;
    while(i!=na && j!=nb){
        if (a[i]<=b[j]) {r[i+j]=a[i];i++;}
        else {r[i+j]=b[j];j++;}
    }
    while(i!=na){
       r[i+j]=a[i];i++;
    }
    while(j!=nb){  
        r[i+j]=b[j];j++;
    }
}

//Exercício 3
void swapV(int v[], int i, int j){
    int aux;
    aux=v[i];
    v[i]=v[j];
    v[j]=aux;
}
int partition (int v[], int N, int x){
    int i,j;
    i=0;
    j=N-1;
    while(i!=j){
        if(v[i]<=x)i++;
        else{swapV(v,i,j);j--;}
    }
    if (i==N-1) i=N;
    return i;
}

int main()
{
    char x[60]="Ola";
    int i;
    int c[10]={2,2,3,4,5,6,7,8,9,90};
    i=partition(c,10,5);
    printf("  %d ",i);
    return EXIT_SUCCESS;
}
