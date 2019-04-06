Y segment 
	M DB "KIIT$"
        N DB "BBSR$"
Y ENDS
print macro message
	mov AH,09h
	mov DX,offset message
	int 21h
ENDS message
X segment
assume DS:X,DS:Y
START:
mov AX,Y
mov DS,AX
print M
print N
mov AH,4ch
int 21h
X ends 
END START