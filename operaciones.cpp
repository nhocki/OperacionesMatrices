/**
 * Avance #1 
 *   Juan Felipe Arango
 *   Nicolás Hock Isaza
 *   Alejandro Peláez Roldán
 **/

#include <cstdio>

/**
 * Suma la matriz A y la matriz B. El resultado se almacena en la matriz Respuesta
 * La suma de dos matrices, A+B = C se define como C(i,j) = A(i,j) + B(i,j)
 **/
int suma(int n, int m, float *a[], float *b[], float **&respuesta){     
    respuesta = new float*[n];
    for(int i = 0; i < n; ++i){
        respuesta[i] = new float[m];
        for(int j = 0; j < m; ++j){
            respuesta[i][j] = a[i][j] + b[i][j];
        }
    }
    return 1;
}

/**
 * Resta la matriz A y la matriz B. El resultado se almacena en la matriz Respuesta
 * La resta de dos matrices, A-B = C se define como C(i,j) = A(i,j) - B(i,j)
 **/
int resta(int n, int m, float *a[], float *b[], float **&respuesta){
    respuesta = new float*[n];
    for(int i = 0; i < n; ++i){
        respuesta[i] = new float[m];
        for(int j = 0; j < m; ++j){
            respuesta[i][j] = a[i][j] - b[i][j];
        }
    }
    return 1;
}

/**
 * Se multiplica la matriz A por el real C. El resultado es almacenado en la matriz Respuesta
 * La multiplicación por escalar de una matriz, cA = B, se define como B(i,j) = c * A(i,j)
 **/
int smultiplicacion(int n, int m, float c, float *a[], float **&respuesta){
    respuesta = new float*[n];
    for(int i=0;i<n;++i){
	respuesta[i] = new float[m];
	for(int j=0;j<m;++j){
	    respuesta[i][j] = a[i][j]*c;
	}
    }
    return 1;
}


/**
 * Se multiplican (si se puede) las matrices A(na x ma) y B(nb x mb).
 * Se verifica que las matrices se puedan multiplicar. 
 * La multiplicación de dos matrices es válida si el número de columnas de la primera es igual el número de filas de la segunda.
 * La multiplicación AxB=C se define como C(i,k) = A(i,j)*B(j,k)
 **/

int multiplicacion(int na, int ma, int nb, int mb, float *a[], float *b[], float **&respuesta){
    if(ma!=nb) return 0;  // Error. No se pueden multiplicar estas matricesxs
    respuesta = new float*[na];
    for(int i = 0; i < na; ++i){
        respuesta[i] = new float[mb];
        for(int j = 0; j < mb; ++j){
            float sum = 0.0;
            for(int k = 0; k < ma; ++k)
                sum += a[i][k]*b[k][j];
            
            respuesta[i][j] = sum;
        }
    }
    return 1;
}

/**
 * Se encuentra la matriz transpuesta (A') de una matriz A. El resultado se almacena en la matriz Respuesta
 * La transpuesta de una matriz, A', se define como A'(i,j) = A(j,i).
 * Claramente, si A es una matriz de dimensiones (m x n), entonces A' es una matriz de dimensiones (n x m)
 **/

int transpuesta(int n, int m, float *a[], float **&respuesta){
    respuesta = new float*[m];
    for(int j=0;j<m;++j){
	respuesta[j] = new float[n];
	for(int i=0;i<n;++i){
	    respuesta[j][i] = a[i][j];
	}
    }
    return 1;
}

int main(){
    const int n = 2, m = 3;
    float **a, **b;
    float **ans1, **ans2;

    a = new float*[n];
    b = new float*[m];

    for(int i = 0; i < n; ++i)
        a[i] = new float[m];

    for(int i = 0; i < m; ++i)
        b[i] = new float[n];

    float c = 0.0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            a[i][j] = c*2;
            c += 1.5;
        }
    }

    float tt=1;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
	    b[i][j] = tt++;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            printf("%f ", b[i][j]);
	
        printf("\n");
    }
    
    //smultiplicacion(m,n,0.5,b,ans1);
    transpuesta(m,n,b,ans1);
    puts("\n\n");
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            printf("%f, ", ans1[i][j]);;

        printf("\n");
    }

    return 0;
}
