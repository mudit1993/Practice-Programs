; Rename File

PrintString MACRO msg
	mov ah, 09h
	mov dx, offset msg
	int 21h
ENDM

DATA SEGMENT
	Omsg DB 13,10,'Enter the file name to be renamed: $'
	Nmsg DB 13,10,'Enter the new name of the file: $'
	Smsg DB 13,10,'The file was renamed successfully: $'
	Fmsg DB 13,10,'There was an error in renaming the file.$'
	Oname DB 20 DUP(0)
	Nname DB 20 DUP(0)
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data
START:
	mov ax, data
	mov ds, ax
	mov es, ax

	PrintString Omsg
	
	mov si, offset Oname
	
R1:	mov ah, 01h
	int 21h
	cmp al, 13
	je RN
	mov [si], al
	inc si
	jmp R1
	
RN:	PrintString Nmsg
	
	mov si, offset Nname
	
R2:	mov ah, 01h
	int 21h
	cmp al, 13
	je RF
	mov [si], al
	inc si
	jmp R2
	
RF:
	mov ah, 56h
	mov dx, offset Oname
	mov di, offset Nname
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