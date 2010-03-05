	;; Para generar el codigo objeto escribir este comando en linux
	;; nasm -f elf op.s
	
extern printf
    SECTION .data
    ;; Formato que necesita el printf para imprimir un
    ;; entero de 32 bits en pantalla, con un fin de liena al
    ;; al final.
    ;; Equivalente a printf("%d\n") en c
fmt:	 db "%d",10,0
    SECTION .text
    ;; Labels globales
    global sumar_imprimir
    global restar_imprimir
    global multiplicar_imprimir
    global potencia_imprimir

    ;; Suma los numeros a y b e imprime en pantalla
    ;; a es el primer parametro
    ;; b es el segundo parametro
sumar_imprimir:
    push ebp
    mov ebp, esp
    mov eax, dword[ebp+0x8]
    add eax, dword[ebp+0xC]
    push eax
    push fmt	
    call printf
    leave
    ret

    ;; Resta los numeros a y b e imprime en pantalla
    ;; a es el primer parametro, el sumando
    ;; b es el segundo parametro, el sustraendo
restar_imprimir:
    push ebp
    mov ebp, esp
    mov eax, dword[ebp+0x8]
    sub eax, dword[ebp+0xC]
    push eax
    push fmt	
    call printf
    leave
    ret

    ;; Multiplica los numeros a y b e imprime en pantalla
    ;; a es el primer parametro
    ;; b es el segundo parametro
multiplicar_imprimir:
    push ebp
    mov ebp, esp
    mov eax, dword[ebp+0x8]
    mul dword[ebp+0xC]		;El primer operando es eax, es implicito
    				;y n el queda el resultado 
    
    push eax
    push fmt	
    call printf
    leave
    ret

    ;; Esta funcion multiplica un numero n veces consigo mismo
    ;; Primer parametro a, el numero que se desea elevar
    ;; Segundo parametro b, la potencia a la cual elevar
potencia_imprimir:
    push ebp
    mov ebp, esp
    mov eax, 1
    mov ebx, dword[ebp+0xC]
    ;; Mientras ebx > 0, se multiplica el valor en eax
    ;; por el parametro uno, esto es lo mismo que hacer
    ;; a*a*a...*a b veces
ciclo:
    cmp ebx, 0 
    jz fin			;Sale del ciclo si ebx = 0
    mul dword[ebp+0x8]		;El primer operando es eax, es implicito
				;y en el queda el resultado
    dec ebx
    jmp ciclo
fin:				;Salida del ciclo
    push eax
    push fmt
    call printf
    leave
    ret
 