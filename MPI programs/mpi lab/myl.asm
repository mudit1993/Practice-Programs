print macro msg
push ax
push dx
mov ah, 09h
mov dx, offset msg
int 21h
pop dx
pop ax
endm

data segment
	imsg db 13, 19, 'Enter a number','$'
	omsg db 13, 10, 'you have inputed','$'

	num dw 10 dup(0)
data ends

code segment
	main proc far
	assume cs: code, ds: data
	push ds
	push 0000h
	mov ax, data
	mov ds, ax
	print msg
	mov cx, 0
	mov bx, 0
	mov dx, 0

	r1: mov ah, 01h
	int 21h
	cmp al, 13
	je e1
	sub al, 48
	mov cl, al
	mov ax, dx
	mul bx
	add ax, cx
	mov dx, ax
	jmp r1
	
	e1:print omsg
	int 21h
	mov ax, 0
	mov ax, dx
	
	xx: mov cl, 10
	div cl
	push ax
	
	int num
	mov ah, 0
	cmp al, 0
	jne xx

	yy: pop ax
	add ah, 48
	mov dl, ah
	mov ah, 02h
	int 21h
	dec num
	cmp num, 0
jne yy
main endp	
code ends
endm