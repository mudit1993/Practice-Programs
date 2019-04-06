; read and write procedures for 16 bit decimal number and ADDITION

Print MACRO msg
	push ax
	push dx
	mov dx, offset msg
	mov ah, 09h
	int 21h
	pop dx
	pop ax
ENDM

DATA SEGMENT
	Rmsg db 13, 10, 'Enter the number: $'
	Result db 13, 10, 'Result = $'
	
	
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

	Print Rmsg
	call ReadNum
	mov num1, dx
	
	Print Rmsg
	call ReadNum
	mov num2, dx
	
ADDITION:
	mov ax, num1
	add ax, num2
	
	Print Result
	call PrintNum
	
	jmp EXIT
	
EXIT:
	mov ax, 4c00h
	int 21h

CODE ENDS
END START