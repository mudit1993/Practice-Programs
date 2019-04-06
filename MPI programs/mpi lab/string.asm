;string program

Print MACRO msg
Push AX
Push DX
mov  ah,09h
mov dx,offset msg
INT 21h
Pop DX
Pop AX
ENDM

DATA SEGMENT

Imsg DB 13,10,'Enter the String $'
Omsg DB 13,10,' The Entered String is $'
Lmsg DB 13,10,'The length of the String is $'
Rmsg DB 13,10,'The reverse of the String is $'
Npalm DB 13,10,'The String is not Palindrome $'
Palm DB 13,10,'The String is Palindrome $'

msg1 DB 13,10,'******STRING******$'
msg2 DB 13,10,'1.Length$'
msg3 DB 13,10,'2.Reverse$'
msg4 DB 13,10,'3.Palindrome$'
Cmsg DB 13,10,'Enter your choice $'

Buf Label byte
mlen DB 40
alen DB ?
str DB 40 DUP('$')

DATA ENDS

CODE SEGMENT
Assume CS:CODE,DS:DATA


 Printnum Proc
	

	Push BX
	Push CX
	Push DX
	mov cx,0
	mov bx,10

     D1:mov dx,0
	DIV BX
	ADD dx,48
	Push DX
	INC cx
	CMP ax,10
	JGE D1
	ADD ax,48
	Push ax
	INC cx
	mov ah,02h

   PNUM:Pop DX
	INT 21h
	LOOP PNUM
	Pop DX
	Pop CX
	Pop BX


 Ret
 ENDP

  start:mov ax,DATA
	mov ds,ax
	
	Print Imsg
	mov ah,0Ah
	mov dx,offset Buf
	INT 21h

	Print Omsg
	Print str
	Print Lmsg
	mov al,alen
	mov ah,00h
	Call Printnum

	mov cl,alen
	mov ch,00h
	mov SI,offset str
	ADD SI,cx
	DEC SI
        Print Rmsg

     L1:mov dl,[SI]
	mov ah,02h
	INT 21h
	DEC SI
	LOOP L1

	mov cl,alen
	mov ch,00h
	mov SI,offset str
	mov DI,SI
	ADD DI,cx
	DEC DI

     L2:mov al,[SI]
	CMP al,[DI]
	JNE NPAL
	INC SI
	DEC DI
        CMP DI,SI
	JGE L2
	Print Palm
	JMP EXIT

   NPAL:Print Npalm


   EXIT:mov ax,4C00h
            INT 21h
CODE ENDS
END start
