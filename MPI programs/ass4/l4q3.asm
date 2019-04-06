; Present Working Directory

PrintString MACRO msg
	mov ah, 09h
	mov dx, offset msg
	int 21h
ENDM

DATA SEGMENT
	Smsg DB 13,10,'The Present Working Directory is: $'
	Dname DB 20 DUP('$')
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data
START:
	mov ax, data
	mov ds, ax
	mov si, offset Dname

	mov ah, 47h
	mov dl, 0
	int 21h
	
	PrintString Smsg
	PrintString Dname
	
EXIT:
	mov ax, 4c00h
	int 21h
CODE ENDS
END START