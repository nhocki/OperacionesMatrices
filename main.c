#include <stdio.h>

extern suma();
extern resta();
extern smultiplicacion();

void main(){
    const n = 7;
    const m = 4;
    int i,j;
    float a[n][m];
    float b[n][m];
    float c[n][m];
    float s = 2.0;

    float k = 0.1;
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j){
            a[i][j] = 2*k;
            b[i][j] = 2*k + 1;
            ++k;
        }
    }

    suma(n,m,a,b,c);
    smultiplicacion(n,m,s,c,c);
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j)
            printf("%f, ", c[i][j]);
        printf("\n");
    }
}
