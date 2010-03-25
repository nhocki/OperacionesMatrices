%define numN	ebp+8
%define numM	ebp+12
%define A    	ebp+16
%define	B    	ebp+20
%define C	ebp+24
%define i       ebp-4
%define j       ebp-8
%define k	ebp-12
    
section .text
    	global suma
	global resta
	global smultiplicacion
	global transpuesta
	global multiplicacion
	;; Funcion que suma dos matrices
	;; La firma de la funcion en C seria
	;; void(int numN, int numM, float A[], float B[], float *C)
	;; se necesita que para llamar la función los arreglos
	;; A, B, C sean inicializados de la siguiente manera (en C)
	;; float A[numN][numM], foat B[numN][numM], float C[numN][numM]
	;; El resultado es almacenado en la matriz C.
suma:
	push 	ebp
	mov 	ebp, esp
	mov  	edx, 0
	mov	eax, 1	    	;eax = 1
	mul	dword[numN]     ;eax = eax*numN
	mov 	edx, 0
	mul     dword[numM]	;eax = eax*numM
	mov     ebx, dword[A]	;current element of A
	mov     ecx, dword[B]	;current element of B
	mov     edx, dword[C]	;current element of C
ciclosuma:	
	cmp	eax, 0
	je	finsuma		    ;if eax > 0 continue
	fld	dword[ebx]	    ;st0 = a[i]
	fadd	dword[ecx]	    ;st0 = a[i] + b[i]
	fstp	dword[edx]	    ;c[i] = st0
	add 	ebx, 4		    ;next element of A
	add 	ecx, 4		    ;next element of B
	add 	edx, 4		    ;next element of C
	dec 	eax
	jmp 	ciclosuma
finsuma:
	leave
	ret

	;; Funcion que resta dos matrices
	;; La firma de la funcion en C seria
	;; void(int numN, int numM, float A[], float B[], float *C)
	;; se necesita que para llamar la función los arreglos
	;; A, B, C sean inicializados de la siguiente manera (en C)
	;; float A[numN][numM], float B[numN][numM], float C[numN][numM]
	;; El resultado es almacenado en la matriz C.
resta:
	push 	ebp
	mov 	ebp, esp
	mov     edx, 0
	mov	eax, 1		;eax = 1
	mul	dword[numN]	;eax = eax*numN
	mov 	edx, 0
	mul	dword[numM]	;eax = eax*numM
	mov	ebx, dword[A]	;current element of A
	mov	ecx, dword[B]	;current element of B
	mov	edx, dword[C]	;current element of C
cicloresta:	
	cmp	eax, 0
	je      finresta	    ;if eax > 0 continue
	fld     dword[ebx]	    ;st0 = a[i]
	fsub	dword[ecx]	    ;st0 = a[i] - b[i]
	fstp	dword[edx]	    ;c[i] = st0
	add 	ebx, 4		    ;next element of A
	add 	ecx, 4		    ;next element of B
	add 	edx, 4		    ;next element of C
	dec 	eax
	jmp 	cicloresta
finresta:
	leave
	ret

    ;; Funcion que multiplica una matriz por un escalar.
    ;; La firma de la funcion en C seria
    ;; void smultiplicacion(int numN,int numM,float s,float B[],float *C)
    ;; Las matrices B y C deben ser inicializadas de la siguiete manera
    ;; antes de llamar a la funcion.
    ;; float B[numN][numM] y float C[numN][numM]
    ;; la respuesta se guarda en C.
smultiplicacion:
	push 	ebp
	mov	ebp, esp
	mov	edx, 0
	mov 	eax, 1		;eax = 1
	mul   	dword[numN]	;eax = eax*numN
	mov	edx, 0
	mul   	dword[numM]	;eax = eax*numM
	mov    	ecx, dword[B]	;current element of B
	mov    	edx, dword[C]	;current element of C
	fld    	dword[ebp+16]   ;load the scalar
ciclosmul:	
	cmp    	eax, 0
	je 	finsmul	        ;if eax > 0 continue
	fld    	dword[ecx]	    ;st0 = b[i]
	fmul	st1	            ;st0 = b[i]*st1(=s)
	fstp	dword[edx]	    ;c[i] = st0
	add 	ecx, 4		    ;next element of B 
	add 	edx, 4		    ;next element of C
	dec 	eax
	jmp 	ciclosmul
finsmul:
	fstp    	st0             ;clear the stack
	leave
	ret

    ;; Funcion que halla la transpuesta de la matriz dada.
    ;; La firma de la función en C seria.
    ;; void transpuesta(int numN, int numM, float A[], float *B)
    ;; Las matrices deben ser inicializadas de la siguiente manera.
    ;; float A[numN][numM] y float B[numM][numN].
    ;; La respuesta queda gurdada en la matriz C.
transpuesta:
	push    ebp
	mov     ebp, esp
	sub     esp, 8
	mov	dword[i], 0
	mov     dword[j], 0
ciclo1:
	mov     eax, dword[numN]
	cmp     dword[i], eax       ;i < numN?
	jge     finciclo1           ;jump if i >= numN
	mov     dword[j], 0
ciclo2:
	mov     eax, dword[numM]
	cmp     dword[j], eax       ;j < numM?
	jge     finciclo2           ;jump if j >= numM
	mov     eax, dword[i]       ;eax = i
	mov     edx, 0
	mul     dword[numM]         ;eax = i*numM
	add     eax, dword[j]       ;eax = i*numM + j
	mov     ebx, 4
	mov     edx, 0
	mul     ebx                 ;eax = 4*(i*numM + j)
	mov     ebx, eax
	mov     eax, dword[j]       ;eax = j
	mov     edx, 0
	mul     dword[numN]         ;eax = j*numN
	add     eax, dword[i]       ;eax = j*numN + i
	mov     ecx, 4
	mov     edx, 0
	mul     ecx                 ;eax = 4*(j*numN + i)
	mov     ecx, eax
	mov     eax, dword[A]
	add     ebx, eax
	mov     edx, dword[ebx]
	mov     eax, dword[B]
	add     ecx, eax
	mov     dword[ecx], edx
	inc     dword[j]            ;++j
	jmp     ciclo2
finciclo2:
	inc     dword[i]            ;++i
	jmp     ciclo1
finciclo1:
	leave
	ret

    ;; Funcion que multiplica dos matrices
    ;; La firma de la funcion en C seria
    ;; void(int numNA, int numMA, int numNB, int numMB, float A[], float B[], float *C)
    ;; se necesita que para llamar la función los arreglos
    ;; A, B, C sean inicializados de la siguiente manera (en C)
    ;; float A[numNA][numMA], foat B[numNB][numMB], float C[numNA][numMB]
    ;; El resultado es almacenado en la matriz C.
%define numNA	ebp+8
%define numMA	ebp+12
%define numNB	ebp+16
%define numMB	ebp+20
%define temp	ebp-16
multiplicacion:
	push 	ebp
	mov	ebp, esp
	mov	ebx, dword[ebp+24] 	;Base element of A
	mov	ecx, dword[ebp+28] 	;Base element of B
	mov	edx, dword[ebp+32] 	;Base element of C
	sub	esp, 16		   	;reserve some space
	mov	dword[i], 0
	mov	dword[j], 0
	mov	dword[k], 0
ciclom1:
    	mov	eax, dword[i]		;eax = i
    	cmp	eax, dword[numNA]	;i < NA?
    	jge	fin_ciclom1		;jump if i >= NA
    	mov	dword[j], 0		;j = 0
ciclom2:
    	mov	eax, dword[j]		;eax = j
    	cmp	eax, dword[numMB]	;j < MB?
    	jge	fin_ciclom2		;jump if j >= MB
    	mov	dword[k], 0		;k = 0
    	fldz				;sum = 0.0
ciclom3:
    	mov	eax, dword[k]		;eax = k
    	cmp	eax, dword[numMA]	;k < MA?
    	jge	fin_ciclom3		;jump if k >= MB
    	mov	dword[temp], edx	;saves edx
    	mov	eax, dword[i]		;eax = i
    	mov	edx, 0
    	mul	dword[numMA]		;eax = i*MA
    	add	eax, dword[k]		;eax = i*MA + k
    	fld	dword[ebx+4*eax]	;st0 = a[i][k]
    	mov	eax, dword[k]		;eax = k
    	mov	edx, 0
    	mul	dword[numMB]		;eax = k*MB
    	add	eax, dword[j]		;eax = k*MB + j
    	fld	dword[ecx+4*eax]	;st0 = b[k][j]
    	fmulp	st1			;st0 = a[i][k]*b[k][j]
    	faddp	st1			;st0 = sum + a[i][k]*b[k][j]
    	mov	edx, dword[temp]	;restores edx
    	inc	dword[k]
    	jmp	ciclom3
fin_ciclom3:
    	mov	dword[temp], edx 	;saves edx
    	mov	eax, dword[i]		;eax = i
    	mov	edx, 0
    	mul	dword[numMB]		;eax = i*MB
    	add	eax, dword[j]		;eax = i*MB + j
    	mov	edx,dword[temp]		;restores edx
    	fstp	dword[edx+4*eax]	;C[i][j] = sum
    	inc	dword[j]		;++j
    	jmp	ciclom2
fin_ciclom2:
    	inc	dword[i]		;++i
    	jmp	ciclom1
fin_ciclom1:	
	leave
	ret