#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Exercício 1
float multInt1 (int n, float m){
    float i,r=0;
    for(i=n;i>0;i--){
        r+=m;
    }
    return r;
}

// Exercício 2
float multInt2 (int n, float m){
    float r=0;
    while(n>0){
        if (n%2!=0) r+=m;
        n=n/2;
        m=m*2;
    }
    return r;
}

// Exercício 3
int mdc1 (int a, int b){
    if(a<b){
        for(int r=a;r>0;r--){
            if(a%r==0 && b%r==0) return r;
        }
    }
    for(int r=b;r>0;r--){
            if(a%r==0 && b%r==0) return r;
        }
    return 1;
}

//Exercício 4
int mdc2 (int a, int b){
    if (a<b) mdc2(a,b-a);
    if (a>b) mdc2(a-b,b);
    if (a==b) return a;
    // return 1;
}

//Exercício 5
int mdc3 (int a, int b){
    if (a<b) mdc2(a,b/a);
    if (a>b) mdc2(a/b,b);
    if (a==b) return a;
    // return 1;
}

//Exercício 6
//a)
int fib1(int n){
    if (n<2) return 1;
    return fib1(n-1)+fib1(n-2);
}

//b)
int fib2(int n){
    int aux;
    if (n<2) return 1;
    int i,n1=1,n2=1;
    for(i=2;i<n;i++){
        aux=n1;
        n1=n2+n1;
        n2=aux;
    }
    return n1+n2;
}

int main()
{
    float s=5.0;
    int i=5;
    float c;
    c=fib2(4);
    printf("%f  ",c);
    
    
    return EXIT_SUCCESS;
}
