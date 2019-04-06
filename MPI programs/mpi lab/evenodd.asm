Segment Y
Msg1 DB "Even$"
Msg2 DB "Odd$"
Y ends


Segment X
Assume Cs:X,DS:Y
Start:

mov ax,Y
mov ds,ax
mov ax,3
SHL ax,15
CMP ax,0
JE XX
JNE YY


XX:

    mov ah,09h
    mov dx,offset Msg1
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