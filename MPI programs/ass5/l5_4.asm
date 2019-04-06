; Menu driven program which ask the user its choice and based in its choice print the o/p

; choice Print MSG1 (Ex: u have pressed 1)
;		 Print MSG2
;		 Print MSG3
;		 Print MSG4
;		 Print MSG5 (Exit)

PrintString MACRO msg
	mov ah, 09h
	mov dx, offset msg
	int 21h
ENDM

DATA SEGMENT
	choice DB 13,10,'Enter a choice between 1 and 4 to see a message accordingly or 5 to exit: $'
	msg1 DB 13,10,'You have pressed 1'
	msg2 DB 13,10,'You have pressed 2'
	msg3 DB 13,10,'You have pressed 3'
	msg4 DB 13,10,'You have pressed 4'
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data
START:
	mov ax, data
	mov ds, ax

	PrintString choice
	
	mov ah, 01h
	int 21h
	cmp al, 13
	
	cmp al, '1'
	je M1
	cmp al, '2'
	je M2
	cmp al, '3'
	je M3
	cmp al, '4'
	je M4
	cmp al, '5'
	je EXIT

M1:	PrintString msg1
	jmp EXIT
	
M2:	PrintString msg2
	jmp EXIT
	
M3:	PrintString msg3
	jmp EXIT
	
M4:	PrintString msg4
	jmp EXIT

EXIT:
	mov ax, 4c00h
	int 21h
CODE ENDS
END START