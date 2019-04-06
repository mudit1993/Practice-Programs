DATA SEGMENT
	pmsg db 13,10,'Hello World$'
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data
START:
	mov ax, data
	mov ds, ax
	
	mov ah, 09h
	mov dx, offset pmsg
	int 21h
	
	mov ax, 4c00h
	int 21h
CODE ENDS
END START