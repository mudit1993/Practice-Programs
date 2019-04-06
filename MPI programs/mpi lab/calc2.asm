print macro msg
push ax
push dx
mov ah,09h
mov dx,offset msg
int 21h
pop dx
pop ax
endm

data segment
num1 dw ?
num2 dw ?
input1 db 13,10,'enter 1st number $'
input2 db 13,10,'enter 2nd number $'
result db 13,10,'the result is $'
remainder db 13,10,'the remainder is $'
cmsg db 13,10,'enter choice$'
mmsg db 13,10,'* Menu* $'
msg1 db 13,10,'1.to add $'
msg2 db 13,10,'2.to substract $'
msg3 db 13,10,'3.to multiply $'
msg4 db 13,10,'4.to divide $'
msg5 db 13,10,'5.to exit $'

data ends

code segment
assume cs:code,ds:data

readnum proc
push ax
push bx
push cx
mov cx,0
mov bx,10
mov dx,0

r1: mov ah,01h
    int 21h
    cmp al,13
    je e1
    sub al,48
    mov cl,al
    mov ax,dx
    mul bx
    add ax,cx
    mov dx,ax
    jmp r1

e1:pop cx
   pop bx
   pop ax
   ret
readnum endp

printnum proc
push ax
push bx
push cx
push dx
mov cx,0
mov bx,10

d1: mov dx,0
    div bx
    add dx,48
    push dx
    inc cx
    cmp ax,10
    jge d1
    add ax,48
    push ax
    inc cx
    mov ah,02h

pnum: pop dx
      int 21h
      loop pnum

pop dx
pop cx
pop bx
pop ax
ret
printnum endp

start: mov ax,data
       mov ds,ax

  menu: print input1
        call readnum
        mov num1,dx
        print input2
        call readnum
        mov num2,dx

       print mmsg
       print msg1
       print msg2
       print msg3
       print msg4
       print msg5
       print cmsg

     r5:mov ah,01h
           int 21h
           cmp al,'1'
           je add1
           cmp al,'2'
           je sub1
           cmp al,'3'
           je mul1
           cmp al,'4'
           je div1
           cmp al,'5'
           je exit

       add1: mov ax,num1
           add ax,num2
           print result
           call printnum
           jmp menu

       sub1: mov ax,num1
           sub ax,num2
           print result
           call printnum
           jmp menu
           
       mul1:mov ax,num1
           mul num2
           print result
           call printnum
           jmp menu

       div1: 
			
			mov dx,0000h
			mov bx,08
            mov ax,num1
            div num2
            print result
            call printnum
            ;mov ax,dx
			print dx
			mov num1,ax
			cmp num1,08
			jge div1
            print remainder
            call printnum
            jmp menu

       exit:mov ax,4c00h
            int 21h

       code ends

       end start
       
               
