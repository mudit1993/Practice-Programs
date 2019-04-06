;output : the reverse of a string
print macro msg
push ax
push dx
mov dx,offset msg
mov ah,09h
int 21h
pop dx
pop ax
endm

data segment 
	buf label byte
	len db 40
	alen db ?
	strl db 40 dup('$')
	imsg db 13,10,'Enter a string: $'
	omsg1 DB 13,10,'The entered string is: $'
	omsg db 13,10,'The reverse of the entered string is: $'
data ends

code segment
	assume cs:code,ds:data
	
start:
	mov ax,data
	mov ds,ax
	
	print imsg
	mov ah,0ah
	mov dx,offset buf
	int 21h
	
	print omsg1
	print strl
	print omsg
	mov cl,alen
	mov ch,00h
	mov si,offset strl
	add si,cx
	dec si
	mov ah,02h
	
disp_char:
	mov dl,[si]
	int 21h
	dec si
	loop disp_char
	
	mov ax,4c00h
	int 21h
	
	code ends
	end start