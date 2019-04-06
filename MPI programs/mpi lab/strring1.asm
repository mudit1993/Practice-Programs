Data Segment
msg db 13,10,'Enter a String $'
Name db 20 DUP(0)
Data Ends
Code Segment
assume cs:code,ds:data
   Start: MOV ax,data;move to gpr
          Mov ds,ax;address of dx
          Mov ah,09h;to print a string
          Mov dx,offset msg
          int 21h
   R1:    MOV si,offset Name;address of dname
          MOV ah,01;to take input from standard io device
          int 21h
          CMP AL,13; to check whether the user has entered or not
          JE R2
          MOV [si],AL; store character in an array
          INC si;advance the index of the array 
          JMP R1
   R2:    Mov ah,09h;to print a string
          Mov dx,offset Name
          int 21h
 
          MOV AX,4C00H
          INT 21H
Code Ends
End Start