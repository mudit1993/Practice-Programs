DATA SEGMENT
	mname db 13,10,'Sujeet Raj$'
	roll db 13,10,'1205315$'
	branch db 13,10,'CSE$'
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data
START:
	mov ax, data
	mov ds, ax
	
	mov ah, 09h
	mov dx, offset mname
	int 21h
	mov dx, offset roll
	int 21h
	mov dx, offset branch
	int 21h
	
	mov ax, 4c00h
	int 21h
CODE ENDS
END START