PrintString MACRO msg
mov ah,09h
mov DX,offset msg
int 21h
endm
Data Segment
Imsg DB,30,10,'Enter the name of the file to be deleted$'
smsg DB,13,10,'Success$'
fmsg DB,13,10,'Failure$'
Dname DB 20 DUP(0)
data ends
Code segment
Assume CS:code,DS:data
start:mov ax,data
mov ds,ax
Printstring Imsg
mov SI,offset Dname
R1:mov ah,01h
int 21h
cmp al,13
je crd;jump on equal



mov [si],al
inc si
jmp R1
crd:mov ah,41h
mov DX,offset Dname
mov cx,02h
int 21h
jnc succ
printstring fmsg
jmp exit
succ:Printstring Smsg
Exit:mov ax,4c00h
int 21h
code ends
end start
