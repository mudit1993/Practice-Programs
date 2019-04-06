Y segment 
	msg DB "name"
        msg1 DB 10 "IT-3"
Y ENDS
X segment
assume DS:X, DS:Y
	START:
	mov AX,Y
	mov DS,AX
	mov ah,09h
	mov dx, offset msg
	int 21h
	mov dx, offset msg1
	int 21h
	mov ah, 4ch
	int 21h
X ENDS
END START