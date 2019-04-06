
printstring macro msg
	mov ah, 09h
	mov dx, offset msg
	int 21h
	endm



DATA segment
dos equ 21h
cr equ 0dh
lf equ 0ah

buff db 80 dup(0)
revbuff db 80 dup(0)

msg1 db 'Enter the string ','$'
msg2 db cr, lf, 'Reverse of string = ','$'
DATA ends

CODE segment
assume cs: CODE, ds: DATA

start:  mov ax,DATA
        mov ds,ax
     
	printstring msg1
	mov si, offset buff

rdchar1:
	mov ah, 01h
	int dos

	mov [si], al
	inc si
	cmp al, cr
	je rdchar1

	mov si, offset buff
	mov bx, 00

nxtchar2:
	mov al, [si]
	cmp al, cr
	jne skip1
	mov [si], al
	inc si
	inc bx
	jmp nxtchar2

skip1:
	mov si, offset buff
	add si, bx
	mov di, offset revbuff
	mov cx, bx

nxtchar3:
	dec si
	mov al, [si]
	mov [di], al
	inc di

	loop nxtchar3

	mov al, '$'
	mov [di], al

	printstring msg2
	printstring revbuff

	mov ah, 4ch
	mov al, 00h
	int dos
CODE ends
end start
