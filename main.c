
#include <stdio.h>

extern void suma();
extern void resta();
extern void smultiplicacion(int,int,float,float(*)[],float(*)[]);
extern void transpuesta();
extern void multiplicacion();

void main(){
    const n = 3;
    const m = 6;
    int i,j;
    float a[n][m];
    float b[n][m];
    float c[n][m];
    float cc[m][n];
    float d[n][n];
    float s = 2.57886;

    float k = 0.1;
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j){
            a[i][j] = 2*k;
            b[i][j] = 2*k + 1;
            ++k;
        }
    }

    suma(n,m,a,b,c);
    printf("\nSuma:\n");
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j)
            printf("%f, ", c[i][j]);
        printf("\n");
    }
    smultiplicacion(n,m,s,c,c);
    printf("\nMultiplicacion escalar:\n");
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j)
            printf("%f, ", c[i][j]);
        printf("\n");
    }

    transpuesta(n,m,c,cc);    
    printf("\nTranspuesta:\n");
    for(i = 0; i < m; ++i){
        for(j = 0; j < n; ++j)
            printf("%f, ", cc[i][j]);
        printf("\n");
    }

    multiplicacion(n,m,m,n,c,cc,d);
    printf("\nMultiplicacion:\n");
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j)
            printf("%f, ", d[i][j]);
        printf("\n");
    }
}
