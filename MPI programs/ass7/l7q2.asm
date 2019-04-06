; Calculator

Print MACRO msg
	push ax
	push dx
	mov dx, offset msg
	mov ah, 09h
	int 21h
	pop dx
	pop ax
ENDM

ReadNumbers MACRO msg1, msg2, msg3
	Print msg1
	call ReadNum
	mov msg2, dx
	
	Print msg1
	call ReadNum
	mov msg3, dx
	
ENDM

DATA SEGMENT
	Rmsg db 13, 10, 'Enter the number: $'
	Result db 13, 10, 'Result = $'
	
	msg1 db 13, 10, '*******Menu*******$'
	msg2 db 13, 10, '1. Addition$'
	msg3 db 13, 10, '2. Subtraction$'
	msg4 db 13, 10, '3. Multiplication$'
	msg5 db 13, 10, '4. Division$'
	msg6 db 13, 10, '5. Exit$'
	msg7 db 13, 10, '******************$'
	Cmsg db 13, 10, 'Enter your choice: $'
	Dmsg db 13, 10, 'Divide by Zero Exception$'
	
	num1 dw 0
	num2 dw 0
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data

ReadNum PROC

; this procedure reads 16-bit number
; input: none
; output: returns the 16-bit number in decimal in DX register

	push ax	; store all the registers used in the procedure onto the stack
	push bx
	push cx
	mov cx, 0
	mov bx, 10
	mov dx, 0
	
R1:
	mov ah, 01h		; get character from keyboard
	int 21h
	
	cmp al, 13		; compares the ASCII code of the currently read digit with the ASCII code of the 'ENTER' key
	je E1			; if the comparison result matches, stop reading
	
	sub al, 48		; get the decimal digit from the entered ASCII code
	mov cl, al		; store it in the cl register
	mov ax, dx		; store previously read number into ax
	mul bx			; multiply previously stored number with 10
	add ax, cx		; add the currently read digit with the result of the multiplication
	mov dx, ax		; store the number in dx register
	
	jmp R1			; jump to read the next digit

E1:
	pop cx	; restore back all the registers used in the procedure
	pop bx
	pop ax

Ret
ENDP

PrintNum PROC

; this procedure displays a 16-bit number
; input: the number to be printed in AX register
; output: none

	push bx
	push cx
	push dx
	
	mov cx, 0
	mov bx, 0Ah
	
D1:
	mov dx, 0
	
	div bx			; divide ax by 10
	add dx, 48		; the last, less than 10 reminder is converted to ASCII
	push dx
	inc cx			; the counter used for tracking no. of digits in incremented
	
	cmp ax, 10		; after division, the left out quotient is compared with 10
	jge D1			; if quotient is greater than 10, go for another round of division
	
	add ax, 48		; the last, less than 10 quotient is converted to ASCII
	push ax
	inc cx			; again the counter is incremented
	mov ah, 02h		; write character to standard o/p device

Pnum:
	pop dx
	int 21h
	LOOP Pnum		; display the count no digits of a number
	pop dx			; restore back all the registers used in the procedure
	pop cx
	pop bx

Ret
ENDP

START:
	mov ax, data
	mov ds, ax

choice:
	Print msg1
	Print msg2
	Print msg3
	Print msg4
	Print msg5
	Print msg6
	Print msg7
	Print Cmsg
	mov ah, 01h
	int 21h
	cmp al, '1'
	je ADDITION
	cmp al, '2'
	je LABEL2
	cmp al, '3'
	je LABEL3
	cmp al, '4'
	je LABEL4
	cmp al, '5'
	je LABEL5
	
ADDITION:
	ReadNumbers Rmsg, num1, num2
	mov ax, num1
	add ax, num2
	Print Result
	call PrintNum
	jmp choice
LABEL2: jmp SUBTRACTION
LABEL3: jmp MULTIPLICATION
LABEL4: jmp DIVISION
LABEL5: jmp EXIT
SUBTRACTION:
	ReadNumbers Rmsg, num1, num2
	mov ax, num1
	sub ax, num2
	Print Result
	call PrintNum
	jmp far ptr choice

MULTIPLICATION:
	ReadNumbers Rmsg, num1, num2
	mov ax, num1
	mul num2
	Print Result
	call PrintNum
	jmp far ptr choice

DIVISION:
	ReadNumbers Rmsg, num1, num2
	cmp num2, 0
	je DivideByZero
	mov dx, 0000h
	mov bx, 08
	mov ax, num1
	div num2
	Print Result
	call PrintNum
	jmp far ptr choice
	
DivideByZero:
	Print Dmsg
	jmp far ptr choice
	
EXIT:
	mov ax, 4c00h
	int 21h

CODE ENDS
END START