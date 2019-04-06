PrintString MACRO msg
mov ah,09h
mov DX,offset msg
int 21h
endm
Data Segment
Imsg DB,30,10,'the current path is $'
smsg DB,13,10,'Success$'
fmsg DB,13,10,'Failure$'
Dname DB 40 DUP('$')
data ends
Code segment
Assume CS:code,DS:data
start:mov ax,data
      mov ds,ax
      mov SI,offset Dname
crd:mov ah,47H
    mov Dl,0
int 21h
jnc succ
printstring fmsg
jmp exit
succ:Printstring Imsg
     Printstring Dname
Exit:mov ax,4c00h
     int 21h
     code ends
     end start
