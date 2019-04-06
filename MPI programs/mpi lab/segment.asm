Y segment 
msg DB "kiit$"
Y ENDS
X segment
assume CS:X, DS:Y
START:
mov AX,Y
mov DS,AX
mov ah,09h
mov dx, offset msg
int 21h
X ENDS
END START