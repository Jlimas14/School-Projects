; -----------------------------------------------------------------------------
; A basic calculator that can do addition, subtraction, division, and multiplication.
; To assemble and run:
;
;     nasm -felf64 calculator.asm 
;     gcc -no-pie calculator.o -o calculator.out 
;     ./calculator.out
; -----------------------------------------------------------------------------

	    global	main
	    extern	printf
	    extern	scanf

	    section	.text
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32

options:
        mov     edi, add
        call    printf
        mov     edi, sub        
        call    printf
        mov     edi, mul        
        call    printf
        mov     edi, div        
        call    printf
        mov     edi, intro        
        call    printf
        lea     rax, [rbp-16]
        mov     rsi, rax
        mov     edi, number        
        call    scanf
        mov     eax, DWORD [rbp-16]
        cmp     eax, 1
        jne     subtract
	jmp	adding

adding:
        mov     edi, choice        
        call    printf
        lea     rax, [rbp-8]
        mov     rsi, rax
        mov     edi, number        
        call    scanf
        mov     edi, choice2        
        call    printf
        lea     rax, [rbp-12]
        mov     rsi, rax
        mov     edi, number        
        call    scanf
        mov     edx, DWORD [rbp-8]
        mov     eax, DWORD [rbp-12]
        add     eax, edx
        mov     DWORD [rbp-4], eax
        mov     eax, DWORD [rbp-4]
        mov     esi, eax
        mov     edi, outro        
        call    printf

subtract:
        mov     eax, DWORD [rbp-16]
        cmp     eax, 2
        jne     multiply
        mov     edi, choice        
        call    printf
        lea     rax, [rbp-8]
        mov     rsi, rax
        mov     edi, number        
        call    scanf
        mov     edi, choice2        
        call    printf
        lea     rax, [rbp-12]
        mov     rsi, rax
        mov     edi, number        
        call    scanf
        mov     eax, DWORD [rbp-8]
        mov     edx, DWORD [rbp-12]
        sub     eax, edx
        mov     DWORD [rbp-4], eax
        mov     eax, DWORD [rbp-4]
        mov     esi, eax
        mov     edi, outro        
        call    printf

multiply:
        mov     eax, DWORD [rbp-16]
        cmp     eax, 3
        jne     divide
        mov     edi, choice        
        call    printf
        lea     rax, [rbp-8]
        mov     rsi, rax
        mov     edi, number        
        call    scanf
        mov     edi, choice2        
        call    printf
        lea     rax, [rbp-12]
        mov     rsi, rax
        mov     edi, number        
        call    scanf
        mov     edx, DWORD [rbp-8]
        mov     eax, DWORD [rbp-12]
        imul    eax, edx
        mov     DWORD [rbp-4], eax
        mov     eax, DWORD [rbp-4]
        mov     esi, eax
        mov     edi, outro        
        call    printf

divide:
        mov     eax, DWORD [rbp-16]
        cmp     eax, 4
        jne     continue
        mov     edi, choice        
        call    printf
        lea     rax, [rbp-8]
        mov     rsi, rax
        mov     edi, number        
        call    scanf
        mov     edi, choice2
        call    printf
        lea     rax, [rbp-12]
        mov     rsi, rax
        mov     edi, number        
        call    scanf
        mov     eax, DWORD [rbp-8]
        mov     ecx, DWORD [rbp-12]
        cdq
        idiv    ecx
        mov     DWORD [rbp-4], eax
        mov     eax, DWORD [rbp-4]
        mov     esi, eax
        mov     edi, outro
        call    printf

continue:
        mov     edi, con        
        call    printf
        lea     rax, [rbp-17]
        mov     rsi, rax
        mov     edi, ychar        
        call    scanf
        movzx   eax, BYTE [rbp-17]
        cmp     al, 121
        je      options
        movzx   eax, BYTE [rbp-17]
        cmp     al, 89
        jne     exit
        jmp     options

exit:
        xor	eax, eax
        leave
        ret


	    section .data
choice:
        db "Enter the first number: ", 0

choice2:
        db "Enter the second number: ", 0
number:
        db "%d", 8
outro:
        db "The sum is %d", 0ah, 0
add:
        db "1: Addition", 0ah, 0
sub:
        db "2: Subtraction", 0ah, 0
mul:
        db "3: Multiplication", 0ah, 0
div:
        db "4: Division", 0ah, 0
intro:
        db "Pick your arithmetic: ", 0
con:
        db "Continue? Y/N: ", 0
ychar:
        db " %c", 8