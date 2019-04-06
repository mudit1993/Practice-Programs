ext segment
	h db 13,10,"world$"
ext ends
data segment
	w db 13,10,"hello$"
data ends
code segment
	assume cs:code ,ds:data,es:ext
start:
	mov ax,data
	mov ds,ax
	mov ax,ext
	mov es,ax
	mov ah,09h
	mov dx,offset w
	int 21h
	
	
	mov ax,ext
	mov ds,ax
	mov ah,09h
	mov dx,offset w
	int 21h
	
	mov ah,4ch
	int 21h
code ends
end start