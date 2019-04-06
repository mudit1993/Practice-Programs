DATA SEGMENT
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data
START:
	mov ah, 01h
	int 21h
	mov dl, al
	mov ah, 02h
	int 21h
	
	mov ax, 4c00h
	int 21h
CODE ENDS
END START