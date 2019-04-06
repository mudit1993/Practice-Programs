Segment Y
Msg1 DB"Even$"
Msg2 DB"Odd$"
Msg3 DB"Enter a number:$"
Y ends

Segment X
Assume CS:X,DS:Y
Start:

mov ax,Y
mov ds,ax

mov ah,09h
mov dx,offset Msg3
int 21h
mov ah,01h
int 21h
mov ch,al
SHL ch,7
CMP ch,0
JE XX
JNE YY


XX:

mov ah,09h
mov dx,offset MSg1
int 21h
mov ah,4ch
int 21h


YY:

mov ah,09h
mov dx,offset Msg2
int 21h
mov ah,4ch
int 21h


X ends
end Start