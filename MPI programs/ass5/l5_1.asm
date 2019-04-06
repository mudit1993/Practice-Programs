; Create File

PrintString MACRO msg
	mov ah, 09h
	mov dx, offset msg
	int 21h
ENDM

DATA SEGMENT
	Imsg DB 13,10,'Enter the file name: $'
	Smsg DB 13,10,'The file was created successfully.$'
	Fmsg DB 13,10,'There was an error in creating the file.$'
	Dname DB 20 DUP(0)
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data
START:
	mov ax, data
	mov ds, ax

	PrintString Imsg
	
	mov si, offset Dname
	
R1:	mov ah, 01h
	int 21h
	cmp al, 13
	je CRD
	mov [si], al
	inc si
	jmp R1
	
CRD:
	mov ah, 5Bh
	mov dx, offset Dname
	mov cx, 0000h
	int 21h
	jnc SUCC
	PrintString Fmsg
	jmp EXIT

SUCC:
	PrintString Smsg
	
EXIT:
	mov ax, 4c00h
	int 21h
CODE ENDS
END START