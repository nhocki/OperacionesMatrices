/** 
 * @file operaciones.h
 */

#ifndef OPERACIONES_H
#define OPERACIONES_H

extern int suma(int n, int m, float a[n][m], float b[n][m], float c[n][m]);
extern int resta(int n, int m, float a[n][m], float b[n][m], float c[n][m]);
extern int smultiplicacion(int n,int m, float, float[n][m],float[n][m]);
extern int transpuesta(int n, int m, float a[n][m], float b[m][n]);
extern int multiplicacion(int na, int ma, int nb, int mb, float a[na][ma], float b[nb][mb], float c[na][mb]);

#endif /* OPERACIONES_H */

