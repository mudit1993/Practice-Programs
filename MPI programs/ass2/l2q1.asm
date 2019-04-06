DATA SEGMENT
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data
START: mov ah, 2
	mov bh, 1
l2:	mov dh, 1
	mov dl, 65
l1:	int 21h
	add dh, 1
	cmp dh, bh
	jle l1
	add bh, 1
	cmp bh, 6
	je l3
	mov dl, 44
	int 21h
	cmp bh, 6
	jle l2
	
l3:	mov ax, 4c00h
	int 21h
CODE ENDS
END START