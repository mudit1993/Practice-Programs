PrintString MACRO msg
	mov dx, offset msg
	int 21h
ENDM

DATA SEGMENT
	mname db 13,10,'Sujeet Raj$'
	branch db 13,10,'CSE$'
	roll db 13,10,'1205315$'
	email db 13,10,'sujeet711@yahoo.in$'
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data
START:
	mov ax, data
	mov ds, ax
	
	mov ah, 09h
	PrintString mname
	PrintString branch
	PrintString roll
	PrintString email
	
	mov ax, 4c00h
	int 21h
CODE ENDS
END START