Y segment 
	msg DB "PALLAV$"
        msg1 DB 10 "IT-3$"
	msg2 DB "KIIT$"
Y ENDS

X segment
assume DS:X,DS:Y

START:
	mov AX,Y
	mov DS,AX
	mov ah,09h
	mov dx,offset msg
	
	int 21h

	mov dx,offset msg1
	int 21h
	mov ah,02h
	mov dl,10
	
	int 21h
	mov ah,09h
	
	mov dx,offset msg2
	int 21h
	mov AH,4ch
	int 21h
X ENDS
END START