data segment 
msg db 13,10,'Hello !!!!! $'
data end

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ah,09h
mov dx,offset msg
int 21h
mov ax,4c00h
int 21h
code ends
end start