DATA SEGMENT
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data
START: 	mov ah, 2
	mov dl, 65
	int 21h
	
	mov ax, 4c00h
	int 21h
CODE ENDS
END START