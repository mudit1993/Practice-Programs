Data Segment

NB db 50 DUP('$');

Data Ends

Code Segment

assume cs:code,ds:data

   Start: MOV ax,data	;move to gpr
          Mov ds,ax	;address of dx
          
          MOV ah,47H          ;to display a working directory
          mov dl,0
	  mov si,offset NB
          int 21h


	mov ah,09h
	mov dx,offset NB
	int 21h

 
          MOV AX,4C00H
          INT 21H
Code Ends 

End Start