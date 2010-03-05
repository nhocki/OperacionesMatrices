/**
 * Se importan las funciones que se llamaran del codigo objeto
 * hecho en ensamblador.
 */
extern float sumar_imprimir();
extern float restar_imprimir();
extern float multiplicar_imprimir();
extern float potencia_imprimir();

int main()
{
    int a = 8, b= 4;
    
    sumar_imprimir(a,b);
    restar_imprimir(a,b);
    multiplicar_imprimir(a,b);
    potencia_imprimir(a,b);

    return 0;
}

/**
 * Compilar en linux con el siguiente comando
 * gcc op.c op.o -o op
 * op.c es este archivo
 * op.o es el codigo objeto generado por nasm del archivo
 * o.s
 */
