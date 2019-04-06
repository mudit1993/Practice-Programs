;sum of digits of  number

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

Imsg DB 13,10,'Enter a number $'
Omsg DB 13,10,'The sum of digits of numbers are $'
num DW 10 dup(0)

DATA ENDS

CODE SEGMENT
Assume CS:CODE,DS:DATA


 Readnum Proc

	Push AX
	Push BX
	Push CX
	mov cx,0
	mov bx,10
	mov dx,0

     R1:mov ah,01h
	INT 21h
	CMP AL,13
	JE E1
	SUB AL,48
	mov cl,al
	mov ax,dx
	MUL BX
	ADD ax,cx
	mov dx,ax
	JMP R1
  
     E1:Pop CX
	Pop BX
	Pop AX
 Ret
 ENDP
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
        print Imsg
        call readnum
        
          call printnum
   EXIT:mov ax,4C00h
            INT 21h
CODE ENDS
END start



        