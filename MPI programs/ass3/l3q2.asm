PrintString MACRO msg
	mov dx, offset msg
	int 21h
ENDM

DATA SEGMENT
Imsg DB 13,10,'Enter the string: $'
Smsg DB 13,10,'The entered string is: $'
Dname DB 20 DUP('$') ;Initializes an array with $ as the value for all indexes
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data
START:
	mov ax, data
	mov ds, ax

	mov ah, 09h					;display string function
	PrintString Imsg
	
	mov si, offset Dname		;giving the address of the Dname
	
R1:	mov ah, 01h					;Read character from standard input device
	int 21h
	cmp al, 13					;compare al to ASCII code of enter
	je SUCC
	mov [si], al				;stores character into array
	inc si						;advance array index
	jmp R1
	
SUCC:
	mov ah, 09h					;display string function
	PrintString Smsg
	PrintString Dname
	
	mov ax, 4c00h
	int 21h
CODE ENDS
END START