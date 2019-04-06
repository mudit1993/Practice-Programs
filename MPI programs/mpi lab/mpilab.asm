segment x
msg db "src $"
ends x
segment y
dest db "kiit $"
ends y
segment code
assume cs:code,ds:x,es:y
start:
mov ax,x
mov ds,ax
mov ax,y
mov es,ax
mov si,offset msg
mov di,offset dest
movsb
push ds
mov ax,y
mov ds,ax
mov ah,09h
mov dx,offset msg
int 21h
pop ds
mov ah,4ch
int 21h
ends code
end start

