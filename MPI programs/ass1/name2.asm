DATA SEGMENT
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data
START: 	mov ah, 2
	mov dl, 83
	int 21h
	mov dl, 44
	int 21h
	mov dl, 117
	int 21h
	mov dl, 44
	int 21h
	mov dl, 106
	int 21h
	mov dl, 44
	int 21h
	mov dl, 101
	int 21h
	mov dl, 44
	int 21h
	mov dl, 101
	int 21h
	mov dl, 44
	int 21h
	mov dl, 116
	int 21h
	mov dl, 44
	int 21h
	mov dl, 82
	int 21h
	mov dl, 44
	int 21h
	mov dl, 97
	int 21h
	mov dl, 44
	int 21h
	mov dl, 106
	int 21h
	
	mov ax, 4c00h
	int 21h
CODE ENDS
END START