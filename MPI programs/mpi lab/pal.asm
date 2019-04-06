Data segment
msg1 db 10,13,'enter the number: $'
msg2 db 10,13,'number is palindrome$'
msg3 db 10,13,'number is not palindrome$'
new db 10,13,'$'
inst db 20 dup(0)
data ends
code segment              
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
lea dx,msg1
mov ah,09h
int 21h
mov bx,00

up:
mov ah,01h
int 21h
cmp al,0dh
je down
mov [inst+bx],al
inc bx
loop up

down:
mov di,0
dec bx
jnz check

check:
mov al,[inst+bx]
cmp al,[inst+di]
jne fail
inc di
dec bx
jnz check
lea dx,new
mov ah,09h
int 21h
lea dx,msg2
mov ah,09h
int 21h
jmp finish

fail:
lea dx,msg3
mov ah,09h
int 21h

finish:
int 3
ret
code ends
end start
end