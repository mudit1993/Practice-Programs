Data Segment
Pmsg DB 13,10, 'additon prg $'
Data ends


Code Segment
Assume cs:Code,ds:Data
start:mov ax,Data
mov ds,ax
mov ah,09h
mov dx,offset Pmsg
int 21h

mov ah,1
add ah,65
push ax

inc ah

mov dl,ah
mov ah,02h
int 21h

pop ax

mov dl,ah
mov ah,02h
int 21h

mov ax,4C00H
int 21h

Code ends
end  start
