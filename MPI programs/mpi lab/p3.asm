print macro msg
mov ah,09h
mov dx,offset msg
int 21h
endm

data segment
	msg db 13,10, 'prakash $'
	msg1 db ' chandra $'
	msg2 db 'from patna $'
data ends

code segment
	assume cs:code,ds:data
	start:mov ax,data
	mov ds,ax
	
	print msg
	print msg2
	print msg1
mov ax,4c00h
int 21h
code ends
end start

