/** 
  * @file main2.c
  */

#include <stdio.h>
#include <operaciones.h>

void escribirMatriz(int n, int m, float a[n][m]){
    int i,j;
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j)
            printf("%.3f ", a[i][j]);
        printf("\n");
    }
}

int main(){
    int operacion;
    int na, ma, nb, mb;
    int i,j,k;
    
    printf("Escoja la operacion (termine con 0)\n");
    printf("1: Suma\n2: Resta\n3: Multiplicacion por escalar\n4: Transpuesta\n5: Multiplicacion\n");
    while(scanf("%d",&operacion)==1 && operacion){
        if(operacion == 1 || operacion == 2){ //Resta
            printf("Ingrese el numero de filas\n");
            scanf("%d",&na);
            printf("Ingrese el numero de columnas\n");
            scanf("%d",&ma);
            float a[(const)na][(const)ma];
            float b[(const)na][(const)ma];
            float c[(const)na][(const)ma];
            printf("Ingrese la matriz A(cada elemento separado por espacio)\n");
            for(i = 0; i < na; ++i)
                for(j = 0; j < ma; ++j)
                    scanf("%f",&a[i][j]);
            printf("Ingrese la matriz B(cada elemento separado por espacio)\n");
            for(i = 0; i < na; ++i)
                for(j = 0; j < ma; ++j)
                    scanf("%f",&b[i][j]);
            int ans;
            if(operacion == 1)
                ans = suma(na,ma,a,b,c);
            else
                ans = resta(na,ma,a,b,c);
            if(ans == 0){
                printf("Respuesta:\n");
                escribirMatriz(na,ma,c);
            }
            else
                printf("Hubo un error\n");
        }
        else if(operacion == 3){            //Multiplicacion por escalar
            printf("Ingrese el numero de filas\n");
            scanf("%d",&na);
            printf("Ingrese el numero de columnas\n");
            scanf("%d",&ma);
            float a[(const)na][(const)ma];
            float b[(const)na][(const)ma];

            float escalar;
            printf("Ingrese el escalar\n");
            scanf("%f",&escalar);
            
            printf("Ingrese la matriz A(cada elemento separado por espacio)\n");
            for(i = 0; i < na; ++i)
                for(j = 0; j < ma; ++j)
                    scanf("%f",&a[i][j]);

            int ans = smultiplicacion(na,ma,escalar,a,b);            
            
            if(ans == 0){
                printf("Respuesta:\n");
                escribirMatriz(na,ma,b);
            }
            else
                printf("Hubo un error\n");
        }

        else if(operacion == 4){            //Transpuesta
            printf("Ingrese el numero de filas\n");
            scanf("%d",&na);
            printf("Ingrese el numero de columnas\n");
            scanf("%d",&ma);
            float a[(const)na][(const)ma];
            float b[(const)ma][(const)na];
            
            printf("Ingrese la matriz A(cada elemento separado por espacio)\n");
            for(i = 0; i < na; ++i)
                for(j = 0; j < ma; ++j)
                    scanf("%f",&a[i][j]);

            int ans = transpuesta(na,ma,a,b);
            if(ans == 0){
                printf("Respuesta:\n");
                escribirMatriz(ma,na,b);
            }
            else
                printf("Hubo un error\n");
        }
        else if(operacion == 5){
            printf("Ingrese el numero de filas de A\n");
            scanf("%d",&na);
            printf("Ingrese el numero de columnas de A\n");
            scanf("%d",&ma);
            float a[(const)na][(const)ma];
            printf("Ingrese la matriz A(cada elemento separado por espacio)\n");
            for(i = 0; i < na; ++i)
                for(j = 0; j < ma; ++j)
                    scanf("%f",&a[i][j]);

            printf("Ingrese el numero de filas de B\n");
            scanf("%d",&nb);
            printf("Ingrese el numero de columnas de B\n");
            scanf("%d",&mb);
            float b[(const)na][(const)mb];
            printf("Ingrese la matriz A(cada elemento separado por espacio)\n");
            for(i = 0; i < nb; ++i)
                for(j = 0; j < mb; ++j)
                    scanf("%f",&b[i][j]);

            float c[(const)na][(const)mb];
            int ans = multiplicacion(na,ma,nb,mb,a,b,c);
            if(ans == 0){
                printf("Respuesta:\n");
                escribirMatriz(na,mb,c);
            }
            else
                printf("Los tamaños de las matrices no cuadraron\n");
        }
        
        printf("\nEscoja la operacion (termine con 0)\n");
        printf("1: Suma\n2: Resta\n3: Multiplicacion por escalar\n4: Transpuesta\n5: Multiplicacion\n");
    }
    return 0;
}
