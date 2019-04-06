Segment x
assume cs:x
start:

mov ax,x
mov ds,ax
mov ah,01h
int 21h

mov cl,ah
neg cl
mov ah,01h
int 21h

mov ch,ah
neg ch
int 21h
x ends
end start

