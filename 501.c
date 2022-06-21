#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// 1
void maior(){
    int x=INT_MIN;
    int n;
    while(n!=0){
        scanf("%d",&n);
        if(n>x){
            x=n;
        }
    }
    printf("%d",x);
}

//2
void media(){
    int i,n;
    float r=0;
    n=INT_MIN;
    for(i=0;n!=0;i++){
        scanf("%d",&n);
        r+=n;
    }
    r=r/(i-1);
    printf("%f",r);
}

//3
void segundo(){
    int p=INT_MIN,s=INT_MIN,n=0;
    while(1){
        scanf("%d",&n);
        if (n==0) {break;}
        if (n>p){
            s=p; 
            p=n;
        }
        if (n>s && n<p){ s=n;}
}
printf("%d",s);
}

//4  - ja dei check
int bitsUm(unsigned int x){
    int c=0;
    while(x>0){
        if(x%2 !=0){
            c+=1;
        }
        x=x/2;
    }
    return c;
}

//5 - ja dei check
int trailingz (unsigned int x){
    int c=0, i=0;
    while (i==0 && x!=0){
        if (x%2 == 0){
            c=c+1;}
        else (i=1);
        x=x/2;
    }
    return c;
}

//6 - ja dei check
int qdig(unsigned int x){
    int c=0;
    while (x!=0){
        c++;
        x=x/10;
    }
    return c;
}

//7  - ja dei check
char *strcatm (char s1[], char s2[]){
    int i,j;
    // ciclo para avançar até ao fim de s1
    for(i=0;s1[i]!='\0';i++);
    for(j=0;s2[j]!='\0';j++){
        s1[i+j]=s2[j];
    }
    s1[i+j]='\0';
    return s1;
}

//8 - ja dei check
char *strcpym (char *dest, char source[]){
    int i;
    for(i=0;source[i]!='\0';i++){
        dest[i]=source[i];
    }
    dest[i]=source[i];
    return dest;
}

//9 - ja die check
int strcmpm (char s1[], char s2[]){
    int i;
    for(i=0; s1[i]!='\0' && s2[i]!='\0'&& s2[i]==s1[i];i++);
    if (s1[i]<s2[i]) return -1;  
    if (s1[i]>s2[i]) return 1;
    return 0;
}

//10
char *mystrstr (char s1[], char s2[]){
    int i,j;
    if (s1[0]=='\0'||s2[0]=='\0') return s1;
    for(i=0;s1[i]!='\0' ;i++){
        for(j=0;s2[j]==s1[i+j] && s2[j]!='\0' &&s1[i+j]!='\0';j++);
        if (s2[j]=='\0') {return s1+i;}
    }
    return NULL;
}

//11
void strrevm (char s[]){
    char aux;
    int tam,i;
    tam=strlen(s);
    for(i=0;i<tam/2;i++){
       aux=s[i];
       s[i]=s[tam-1-i];
       s[tam-1-i]=aux; 
    }
}

//12
int vogal(char s){

    if ((s=='a')||(s=='A')||(s=='e')||(s=='E')||(s=='i')||(s=='I')||(s=='o')||(s=='O')||(s=='U')||(s=='u')) return 0;
    return 1;
}
void strnoV (char s[]){
    int i=0,j;
    char aux;
    while(s[i]!='\0'){
        for(j=i;!vogal(s[j]) && s[j]!='\0';j++);
        if (s[j]=='\0') {s[i]='\0'; break;}
        aux=s[i];
        s[i]=s[j];
        s[j]=aux;  //limpar
        i++;
    }
}

//13 - dificil
void truncW (char t[], int n){
    int i,j=0,rep=n;
    for(i=0; t[i] != '\0'; i++)
    {
        if(t[i] == ' ')
        {
            t[j]= ' ';
            j++;
            rep=n;
        }
        else
        {
            if(rep != 0)
            {
                t[j] = t[i];
                j++;
                rep--;
            }
        }
    }
    t[j] = '\0';
}

//14
int procura(char c, char s[]){
    int i, count=0;
    for(i=0;s[i]!='\0';i++){
        if (s[i]==c) count++;
    }
    return count;
}
char charMaisfreq (char s[]){
    int i,mx=0;
    char c=0;
    for(i=0;s[i]!='\0';i++){
        if (procura(s[i],s)>mx){
            mx=procura(s[i],s);
            c=s[i];
        }
    }
    return c;
}

//15
 int iguaisConsecutivos (char s[]){
     int i,max=0,count=0;
     for(i=0;s[i]!='\0';i++){
         for(count=1;s[i+count-1]==s[i+count] && s[i+count-1]!='\0';count++);
         if (count>max) max=count;
     }
     return max;
 }

//16 - refazer
int diff(char s[],int l){
    int i,j;
    for (i=0;i<l;i++){
        for(j=i+1;j<l;j++){
            if(s[i]==s[j]) return 0;
        }
    }
    return 1;
}
int difConsecutivos(char s[]){
    int i,j, max=0, n=0;
    for(i=0; s[i] != '\0'; i++){
      for(j=i;s[j]!='\0';j++){
          if (diff(s+i,j+1-i)) n=j-i+1;
          if (n>max) max=n;
      }}
    return max;
}

//17
int maiorPrefixo (char s1 [], char s2 []){
    int i;
    for(i=0;s1[i]!='\0'&& s2[i]!='\0'&&s1[i]==s2[i];i++);
    return i;
}

//18
int mairoSufixo(char s1[], char s2[]){
    int i,c1,c2;
    c1=strlen(s1);
    c2=strlen(s2);
    for(i=0;i<c1 && i<c2 && s1[c1-1-i]==s2[c2-1-i];i++);
    return i;
}

//19
int sufPref (char s1[], char s2[]){
    int c,i,j,max=0;
    c=strlen(s1);
    for(i=0;s1[i]!='\0' && s2[i]!='\0';i++){
        for(j=0;j<=i && s2[j]==s1[c-1-i+j];j++);
        if(j>max) max=j;
    }
    return max;
}

//20 - ja dei check 
int contaPal (char s[]){
    int i,count=0;
    if (s[0]=='\0'||s[0]=='\n') return 0;
    for(i=0;s[i]!='\0';i++){
        if (s[i]!=' '&& s[i+1]==' ') count++;
    }
    if (s[i-1]==' ') count--;
    return count+1;
}

//21
int contaVogais (char s[]){
    int count=0,i;
    for(i=0;s[i]!='\0';i++){
        if (!vogal(s[i])) count++;}
    return count;
}

//22 check
int contida (char a[], char b[]){
    int i,j;
    for(i=0;a[i]!='\0';i++){
        for(j=0; a[i]!=b[j] && b[j]!='\0';j++);
        if (b[j]=='\0') return 0;
    }
    return 1;
}

//23 - check
int palindorome (char s[]){
    int c,i;
    c=strlen(s);
    for(i=0;i<c/2;i++){
        if (s[i]!=s[c-1-i]) return 0;
    }
    return 1;
}

//24 - dei check
int remRep (char x[]){
    int i=0,j=0;
    if (x[0]=='\0') return 0;
    while(x[i]!='\0'){
        x[j]=x[i];
        j++;
        while(x[i]==x[i+1]){i++;}
        i++;
    }
    x[j]='\0';
    return j;
}

//25 - dei check
int limpaEspacos (char t[]){
    int i,j=0;
    for(i=0;t[i]!='\0';i++){
        if (t[i]!=' '){t[j]=t[i];j++;}
        else{ if (t[j-1]!=' ' && t[i]==' ') {t[j]=' '; j++;}}
    }
    t[j]='\0';
    return j;
}

//26 dei check
void swapV(int v[],int a,int b){
    int aux;
    aux=v[a];
    v[a]=v[b];
    v[b]=aux;
}
void insere (int v[], int N, int x){
    int i;
    for(i=0;v[i]<x && i<N;i++);
    v[N]=x;
    for(;i<=N;i++){
        swapV(v,i,N);
    }
}

//27 - dei check
void merge (int r [], int a[], int b[], int na, int nb){
    int i,j;
    i=0;
    j=0;
    while(i<na && j<na){
        if (a[i]<b[j]) {r[i+j]=a[i];i++;}
        else{r[i+j]=b[j];j++;}
    }
    while(i<na){
        r[i+j]=a[i];i++;
    }
    while(j<nb){
        r[i+j]=b[j];j++;
    }
} 

//28 dei check
int crescente (int a[], int i, int j){
    while(i<j && a[i]<=a[i+1])i++;
    if (i==j) return 1;
    return 0;
}

//29 - check
int retiraNeg (int v[], int N){
    int i,j=0;
    for(i=0;i<N;i++){
        if (v[i]>=0) {v[j]=v[i];j++;}
    }
    return j;
}

//30 - check
int menosFreq(int v[], int N){
    int i,j,min=v[0], n=N, cont;
    for(i=0; i<N;){
        cont =0;
        for(j=0; j<N; j++){
            if(v[i] == v[j]) cont++;
        }
        if(cont<n){
            min=v[i];
            n=cont;
        }
        i+=cont;
    }
    return min;
}

//31 - check
int maisFreq (int v[], int N){
    int i,j,max=v[0], n=0, cont;
    for(i=0; i<N;i++){
        cont =0;
        for(j=0; j<N; j++){
            if(v[i] == v[j]) cont++;
        }
        if(cont>n){
            max=v[i];
            n=cont;
        }
    }
    return max;
}

//32 - check
int maxCresc (int v[], int N){
    int i,j,max=0,count=0;
    for(i=0;i<N;i++){
        count=1;
        for(j=i;j<N && v[j]<=v[j+1];j++){count++;}
        if(count>max){
            max=count;
        }
    }
    return max;
}

//33 - check
int esta(int v,int tmp[],int n){
    int i;
    for(i=0;i<n;i++){
        if (tmp[i]==v) return 1;
    }
    return 0;
}
int elimRep (int v[], int n){
    int i,tmp[n],j;
    tmp[0]=v[0];
    j=1;
    for (i=1;i<n;i++){
        if (!esta(v[i],tmp,i)) {tmp[j]=v[i];j++;}
    }
    for(i=0;i<j;i++){v[i]=tmp[i];}
    return j;
}

// 34 check
int elimRepOrd (int v[], int n){
    int i,j;
    j=0;
    for(i=0;i<n;i++){
        v[j]=v[i];
        j++;
        while(v[i]==v[i+1]){i++;}
    }
    return j;
}

//35 - check
int comunsOrd(int a[], int na, int b[], int nb){
    int i,j,com=0;
    i=j=0;
    while (i<na && j<nb){
        if(a[i]<b[j]) i++;
        else if (a[i]>b[j]) j++;
        else if (a[i] == b[j]){
            com++;
            i++;
            j++;
        }
    }
    return com;
}

//36 - check
int comuns(int a[], int na, int b[], int nb){
    int i,j,com=0;
    for(i=0; i<na; i++){
        for(j=0;j<nb; j++){
            if (a[i] == b[j]){
                com++;
                break;    // não pode encontrar 2 vezes
            }
        }
    }
    return com;
}

//37
int minInd (int v[], int n){
    int i,j,min=0;
    for(i=0;i<n;i++){
        if (v[i]<v[min]) min=i;
    }
    return min;
}

//38
void somasAc (int v[], int Ac [], int N){
    int i;
    Ac[0]=v[0];
    for(i=1;i<N;i++){
        Ac[i]=v[i]+Ac[i-1];
    }
}

//39 - rever
int triSup(int N, float m[N][N]){
    int l,c, r=1;
    for(l=0; l<N; l++){
        for(c=0; c<N; c++){
            if(c<l){
                if(m[l][c] != 0) r = 0;
            }
        }
    }
    return r;
}

//40
void transposta (int N, float m [N][N]){
    int l,c;
    float aux;
    for(l=0;l<N;l++){
        for(c=l;c<N;c++){
            if(c!=l){
                aux=m[l][c];
                m[l][c]=m[c][l];
                m[c][l]=aux;
            }
        }
    }
}

//41

void addTo (int N, int M, int a [N][M], int b[N][M]) {
    int l,c;
    for (l=0;l<N;l++){
        for(c=0;c<M;c++){
            a[l][c]=a[l][c]+b[l][c];
        }
    }
}

//42
int unionSet(int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0; i<N; i++){
        if (v1[i] == 1 || v2[i] == 1) r[i] = 1;
        else r[i]=0;
    }
    return 0;
}

//43
int intersectSet (int N, int v1[N], int v2[N],int r[N]){
    int i;
    for(i=0; i<N; i++){
        if (v1[i] == 1 && v2[i] == 1) r[i] = 1;
        else r[i]=0;
    }
    return 0;
}

//44
int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0;i<N;i++){
        if(v1[i]<=v2[i]) r[i]=v1[i];
        else{r[i]=v2[i];}
    }
    return 0;
} 

//45
int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for(i=0;i<N;i++){
        if(v1[i]>=v2[i]) r[i]=v1[i];
        else{r[i]=v2[i];}
    }
    return 0;
}

//46
int cardinalMSet (int N, int v[N]){
    int i,count=0;
    for(i=0;i<N;i++){
        count+=v[i];
    }
    return count;
}

//47
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for(i=0;i<N;i++){
        if (mov[i]==Norte) inicial.y+=1;
        if (mov[i]==Sul) inicial.y+=-1;
        if (mov[i]==Este) inicial.x+=1;
        if (mov[i]==Oeste) inicial.x+=-1;
    }
    return inicial;
}

//48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i, r=0;
    for(i=0; (inicial.x != final.x) || (inicial.y != final.y); i++){
        if (inicial.x < final.x) {
            mov[i] = Este;
            inicial.x++;
        }
        else if(inicial.x > final.x) {
            mov[i] = Oeste;
            inicial.x--;
        }
        else if(inicial.y < final.y) {
            mov[i] = Norte;
            inicial.y++;
        }
        else if(inicial.y > final.y) {
            mov[i] = Sul;
            inicial.y--;
        }
        r++;
    }
    if (r>N) return -1;
    return r;
}

//49
int dist(Posicao pos){
    int dist;
    dist = abs(pos.x) + abs(pos.y);
    return dist;
}

int maiscentral (Posicao pos[], int N){
    int i, mC=0, min= dist(pos[0]);
    for(i=0; i<N; i++){
        if ( dist(pos[i]) < min){
            min = dist(pos[i]);
            mC=i;
        }
    }
    return mC;
}

//50
int viz(Posicao p, Posicao pos){
    int r=1;
    if (p.x==pos.x && p.y== pos.y + 1);
    else if(p.x==pos.x && p.y == pos.y - 1);
    else if(p.y==pos.y && p.x == pos.x + 1);
    else if(p.y==pos.y && p.x == pos.x -1);
    else r=0;
    return r;
}

int vizinhos (Posicao p, Posicao pos[], int N){
    int i, contador=0;
    for(i=0; i<N; i++){
        if(viz(p, pos[i])) contador++;
    }
    return contador;
}

int main()
{
    float s1[3][3]={{1,1,1},{1,1,0},{1,0,0}};
    int s2[6]={0,1,2,3,4,5};
    int s3[6]={};
    int c;
    char s[50]="Mundo Cruel!!";
    c=diff(s+2,12);
    printf("%d  ",s+2);
    
    
    return EXIT_SUCCESS;
}
