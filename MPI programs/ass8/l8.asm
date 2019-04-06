Print MACRO msg
	PUSH ax
	PUSH dx
	mov ah, 09h
	mov dx, offset msg
	int 21h
	POP dx
	POP ax
ENDM

DATA SEGMENT

	Imsg db 13, 10, 'Enter the string: $'
	Omsg db 13, 10, 'The entered string is: $'
	Lmsg db 13, 10, 'The length of the string is: $'
	Rmsg db 13, 10, 'The reversed string is: $'
	Npalm db 13, 10, 'The string is not a palindrome$'
	Palm db 13, 10, 'The string is a palindrome$'
	
	Buf label byte
	mlen db 40
	alen db ?
	str db 40 DUP('$')
	
DATA ENDS


CODE SEGMENT
assume cs:code, ds:data

Printnum Proc
	PUSH bx
	PUSH cx
	PUSH dx
	
	mov cx, 0
	mov bx, 10 ; or mov bx, 0Ah -> hex for 10

D1:
	mov dx, 0
	div bx
	add dx, 48
	PUSH dx
	inc cx
	cmp ax, 10
	jge D1
	add ax, 48
	PUSH ax
	inc cx
	mov ah, 02h

PNUM:
	POP dx
	int 21h
	loop PNUM

	POP dx
	POP cx
	POP bx
	
Ret
ENDP

START:
	mov ax, data
	mov ds, ax
	
	Print Imsg
	mov ah, 0Ah
	mov dx, offset Buf
	int 21h
	Print Omsg
	Print str
	Print Lmsg
	
	mov al, alen
	mov ah, 00h
	call Printnum
	
	mov cl, alen
	mov ch, 00h
	mov si, offset str
	add si, cx
	dec si
	Print Rmsg
	
	; Reverse print
	
L1:
	mov dl,[si]
	mov ah, 02h
	int 21h
	dec si
	loop L1
	mov cl, alen
	mov ch, 00h
	mov si, offset str
	mov di, si
	add di, cx
	dec di
	
	; checking palindrome or not
	
L2:
	mov al, [si]
	cmp al, [di]
	jne NPAL
	inc si
	dec di
	cmp di, si
	jge L2
	Print Palm
	jmp EXIT
NPAL:	Print Npalm

EXIT:
	mov ax, 4c00h
	int 21h
	
CODE ENDS
END START