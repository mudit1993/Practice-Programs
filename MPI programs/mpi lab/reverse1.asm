data segment
	msg db 13,10,"enter the string$"
	
data ends
code segment
assume cs:code,ds:data
start:
	mov ax,data
	mov ds,ax
	mov ah,09h
	mov dx,offset msg
	int 21h
	mov cx,0
	
	l1:	mov ah,01h
		int 21h
		mov ah,0
		push ax
		inc cx
		cmp al,13
		jne l1
		mov bx,cx
	l2:
		dec bx
		pop dx
		mov ah,02h
		int 21h
		cmp bx,0
		jne l2
	
	mov ah,4ch
	int 21h
code ends
end start
		
		