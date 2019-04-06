Data Segment
Pmsg DB 13,10, 'disp prg $'
Data ends


Code Segment
Assume cs:Code,ds:Data
start:mov ax,Data
mov ds,ax
mov ah,09h
mov dx,offset Pmsg
int 21h
mov ax,123
;mov dx,0
mov bx,10
div bx
;add al,48
mov dl,al
mov ah,02h
int 21h

mov ax,4C00H
int 21h

Code ends
end  start
