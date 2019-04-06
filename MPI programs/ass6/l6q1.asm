; Menu driven program for directory

Print MACRO msg
	mov ah, 09h
	mov dx, offset msg
	int 21h
ENDM

DATA SEGMENT
	Imsg DB 13,10,'Enter the directory name: $'
	Smsg1 DB 13,10,'The directory was created successfully.$'
	Smsg2 DB 13,10,'The directory was deleted successfully.$'
	Smsg3 DB 13,10,'The Present Working Directory is: $'
	Fmsg1 DB 13,10,'There was an error in creating the directory.$'
	Fmsg2 DB 13,10,'There was an error in deleting the directory.$'
	Fmsg3 DB 13,10,'Error$'
	msg1 DB 13,10,'**********Menu**********$'
	msg2 DB 13,10,'1. Create a directory$'
	msg3 DB 13,10,'2. Delete a directory$'
	msg4 DB 13,10,'3. Present working directory$'
	msg5 DB 13,10,'4. Exit$'
	Cmsg DB 13,10,'Enter your choice: $'
	
	Dname DB 20 DUP(0)
	DnamePWD DB 20 DUP('$')
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data

P1 Proc ; create a directory procedure
	PUSH ax
	PUSH dx
	PUSH si
	Print Imsg
	mov si, offset Dname
R1:	mov ah, 01h
	int 21h
	cmp al, 13
	je C1
	mov [si], al
	inc si
	jmp R1
	
C1: mov ah, 39h
	mov dx, offset Dname
	int 21h
	jnc S1
	Print Fmsg1
	jmp E1
	
S1: Print Smsg1

E1:	POP si
	POP dx
	POP ax
	
Ret
ENDP


P2 Proc ; delete a directory procedure
	PUSH ax
	PUSH dx
	PUSH si
	Print Imsg
	mov si, offset Dname
R2:	mov ah, 01h
	int 21h
	cmp al, 13
	je C2
	mov [si], al
	inc si
	jmp R2
	
C2: mov ah, 3Ah
	mov dx, offset Dname
	int 21h
	jnc S2
	Print Fmsg2
	jmp E2
	
S2: Print Smsg2

E2:	POP si
	POP dx
	POP ax
	
Ret
ENDP


P3 Proc ; present working directory procedure
	PUSH ax
	PUSH dx
	PUSH si
	
	mov ah, 47h
	mov dl, 0h
	mov si, offset DnamePWD
	int 21h
	jnc S3
	Print Fmsg3
	jmp E3

S3:	Print Smsg3
	Print DnamePWD

E3:	POP si
	POP dx
	POP ax
	
Ret
ENDP


START:
	mov ax, data
	mov ds, ax
	
choice:
	Print msg1
	Print msg2
	Print msg3
	Print msg4
	Print msg5
	Print Cmsg
	mov ah, 01h
	int 21h
	cmp al, '1'
	je CRD
	cmp al, '2'
	je DELD
	cmp al, '3'
	je PWD
	cmp al, '4'
	je Exit
	
CRD:
	call P1
	jmp choice
	
DELD:
	call P2
	jmp choice
	
PWD:
	call P3
	jmp choice

EXIT:
	mov ax, 4c00h
	int 21h
CODE ENDS
END START