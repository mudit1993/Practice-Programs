Data Segment
msg db 13,10,'Enter a String $'
msg2 db 13,10,'The Entered string is $'
N db 20 DUP('$');duplication of bytes

Data Ends

Code Segment

assume cs:code,ds:data

   Start: MOV ax,data;move to gpr
          Mov ds,ax;address of dx
          Mov ah,09h;to print a string
          Mov dx,offset msg
          int 21h
          MOV si,offset N;address of name

   R1:    MOV ah,01;to take input from standard io device
          int 21h
          CMP al,13; to check whether the user has entered or not
          JE R2
          MOV [si],al; store character in an array
          INC si;advance the index of the array 
          JMP R1

   R2:    MOV ah,09h
          MOV dx,offset msg2
          int 21h
          Mov ah,09h;to print a string
          Mov dx,offset N
          int 21h
 
          MOV AX,4C00H
          INT 21H
Code Ends 

End Start