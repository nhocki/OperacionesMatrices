#include <math.h>
#include <stdio.h>
#include <operaciones.h>
const float eps = 1e-2;

/**
 * Funcion que escribe una matriz a la salida estandar.
 */
void escribirMatriz(int n, int m, float mat[n][m]){
    int i,j;
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < m; ++j)
            printf("%.2f ", mat[i][j]);
        printf("\n");
    }
}

/**
 * Funcion que chequea si dos matrices son iguales.
 * 0 si son diferentes.
 * 1 si son iguales.
 */
int check(int n, int m, float a[n][m], float b[n][m]){
    int i,j;
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
            if(fabs(a[i][j]-b[i][j]) > eps)
                return 0;
    return 1;
}

void suma1(int n, int m, float(*a)[m], float(*b)[m],float(*c)[m]){
    int i,j;
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
            c[i][j] = a[i][j] + b[i][j];
}

void resta1(int n, int m, float(*a)[m], float(*b)[m],float(*c)[m]){
    int i,j;
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
            c[i][j] = a[i][j] - b[i][j];
}

void smult1(int n, int m, float s, float(*a)[m],float(*c)[m]){
    int i,j;
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
            c[i][j] = a[i][j]*s;
}

void trans1(int n, int m, float(*a)[m],float(*c)[n]){
    int i,j;
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
            c[j][i] = a[i][j];
}

void mult1(int na, int ma, int nb, int mb, float(*a)[ma],float(*b)[mb], float(*c)[mb]){
    int i,j,k;
    for(i = 0; i < na; ++i){
        for(j = 0; j < mb; ++j){
            float sum = 0.0;
            for(k = 0; k < ma; ++k)
                sum += a[i][k]*b[k][j];
            c[i][j] = sum;
        }
    }
}

void main(){
    const n = 6;
    const m = 4;
    int i,j;
    float a[n][m], a1[n][m];
    float b[n][m], b1[n][m];
    float c[n][m], c1[n][m];
    float cc[m][n], cc1[m][n];
    float d[n][n], d1[n][n];
    float s = 2.57886;

    float k = 0.1;
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j){
            a[i][j] = a1[i][j] = 2*k;
            b[i][j] = b1[i][j] = 2*k + 1;
            ++k;
        }
    }

    int r;
    int ans = suma(n,m,a,b,c);
    if(ans == 0){
        printf("\nSuma a + b:\n");
        escribirMatriz(n,m,c);
        suma1(n,m,a1,b1,c1);
        r = check(n,m,c,c1);
        if(r > 0)printf("\nSuma OK\n");
        else printf("\nSuma not OK\n");
    }
    else
        printf("Error en la suma\n");

    ans = resta(n,m,a,b,a);
    if(ans == 0){
        printf("\n Resta (a-b):\n");
        escribirMatriz(n,m,a);
        resta1(n,m,a1,b1,a1);
        r = check(n,m,a,a1);
        if(r > 0)printf("\nResta OK\n");
        else printf("Resta not OK\n");
    }
    else
        printf("Error en la resta\n");

    ans = smultiplicacion(n,m,s,c,c);
    if(ans == 0){
        printf("\nMultiplicacion escalar s*(a+b):\n");
        escribirMatriz(n,m,c);
        smult1(n,m,s,c1,c1);
        r = check(n,m,c,c1);
        if(r > 0)printf("\nMultiplicacion por escalar OK\n");
        else printf("\nMultiplicacion or escalar not OK\n");
    }
    else
        printf("Error en la multiplicacion por escalar\n");

    ans = transpuesta(n,m,c,cc);    
    if(ans == 0){
        printf("\nTranspuesta s*(a+b)^T:\n");
        escribirMatriz(m,n,cc);
        trans1(n,m,c1,cc1);
        r = check(m,n,cc,cc1);
        if(r > 0)printf("\nTranspuesta OK\n");
        else printf("\nTranspuesta not OK\n");
    }
    else
        printf("Error en la transpuesta\n");

    ans = multiplicacion(n,m,m,n,c,cc,d);
    if(ans == 0){
        printf("\nMultiplicacion: s*(a+b)xs*(a+b^T)\n");
        escribirMatriz(n,n,d);
        mult1(n,m,m,n,c1,cc1,d1);
        printf("\n");
        r = check(n,n,d,d1);
        if(r > 0)printf("\nMultiplicacion OK\n");
        else printf("\nMultiplicacion not OK\n");
    }
    else
        printf("Los tamaños de las matrices fueron incompatibles\n");
}
