; Menu driven program for file

Print MACRO msg
	mov ah, 09h
	mov dx, offset msg
	int 21h
ENDM

DATA SEGMENT
	Imsg DB 13,10,'Enter the file name: $'
	Omsg DB 13,10,'Enter the file name to be renamed: $'
	Nmsg DB 13,10,'Enter the new name of the file: $'
	Smsg1 DB 13,10,'The file was created successfully.$'
	Smsg2 DB 13,10,'The file was deleted successfully.$'
	Smsg3 DB 13,10,'The file was renamed successfully.$'
	Fmsg1 DB 13,10,'There was an error in creating the file.$'
	Fmsg2 DB 13,10,'There was an error in deleting the file.$'
	Fmsg3 DB 13,10,'There was an error in renaming the file.$'
	msg1 DB 13,10,'**********Menu**********$'
	msg2 DB 13,10,'1. Create a file$'
	msg3 DB 13,10,'2. Delete a file$'
	msg4 DB 13,10,'3. Rename a file$'
	msg5 DB 13,10,'4. Exit$'
	Cmsg DB 13,10,'Enter your choice: $'
	
	Dname DB 20 DUP(0)
	Nname DB 20 DUP(0)
DATA ENDS

CODE SEGMENT
assume cs:code, ds:data

P1 Proc ; create a file procedure
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
	
C1: mov ah, 5Bh
	mov dx, offset Dname
	mov cx, 0000h
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


P2 Proc ; delete a file procedure
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
	
C2: mov ah, 41h
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



P3 Proc ; rename a file procedure
	PUSH ax
	PUSH dx
	PUSH si
	PUSH es
	Print Omsg
	mov si, offset Dname
R3:	mov ah, 01h
	int 21h
	cmp al, 13
	je RN
	mov [si], al
	inc si
	jmp R3
	
RN:	Print Nmsg
	mov si, offset Nname
	
RF:	mov ah, 01h
	int 21h
	cmp al, 13
	je C3
	mov [si], al
	inc si
	jmp RF
	
C3: mov ah, 56h
	mov dx, offset Dname
	mov di, offset Nname
	int 21h
	jnc S3
	Print Fmsg3
	jmp E3
	
S3: Print Smsg3

E3:	POP es
	POP si
	POP dx
	POP ax
	
Ret
ENDP


START:
	mov ax, data
	mov ds, ax
	mov es, ax
	
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
	je RMF
	cmp al, '4'
	je Exit
	
CRD:
	call P1
	jmp choice
	
DELD:
	call P2
	jmp choice
	
RMF:
	call P3
	jmp choice
	
EXIT:
	mov ax, 4c00h
	int 21h
CODE ENDS
END START