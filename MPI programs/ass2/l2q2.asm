DATA SEGMENT
DATA ENDS

CODE SEGMENT
assume cs:code, ds: data
START: mov ah, 2
	mov dh, 63
l1:	add dh, 2
	mov dl, dh
	int 21h
	mov dl, 32
	int 21h
	cmp dh, 73
	jl l1
	
	mov ax, 4c00h
	int 21h
CODE ENDS
END START