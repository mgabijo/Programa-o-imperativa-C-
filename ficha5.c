#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>





int main()
{
    char x[60]="Ola";
    int i;
    int c[10]={2,2,3,4,5,6,7,8,9,90};
    i=partition(c,10,5);
    printf("  %d ",i);
    return EXIT_SUCCESS;
}