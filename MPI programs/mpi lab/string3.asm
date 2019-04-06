print macro msg
    mov ah,09h
    mov dx,offset msg
    int 21h
endm  

data segment

   imsg db 13,10,'Enter the string $'
   omsg db 13,10,'The entered string is $'
   lmsg db 13,10,'The length of the string is $'
   rmsg db 13,10,'The reverse of the string is $'
   npal db 13,10,'The string is not a palindrome $'
   pal db 13,10,'The string is a palindrome $'

   buf label byte
   mlen db 40
   alen db ?
   s db 40 dup('$')

data ends

code segment
   assume cs:code,ds:data
printnum proc
      push bx
      push cx
      push dx

      mov cx,0
      mov bx,0ah

D1: mov dx,0
      div bx;                        divide by 10
      add dx,48;    remainder is converted to ascii is it <10
      push dx
      inc cx;                        counter for tracking digit
      cmp ax,10;                  quotient is compared to 10 for decimal 
      jge D1;                        if quotient > 10 , we'll divide

      add ax,48;
      push ax;
      inc cx
      mov ah,02h;                write to standard o/p device

pnum: pop dx
          int 21h
          loop pnum
          
          pop dx
          pop cx
          pop bx
ret
endp

start:  mov ax,data
         mov ds,ax
         print imsg
         mov ah,0ah
         mov dx,offset buf
         int 21h
         print omsg
         print s
         print lmsg
         mov al,alen
         mov ah,00h
         call printnum

         mov cl,alen
         mov ch,00h
         mov si,offset s
         add si,cx
         dec si

         print rmsg

L1:    mov dl,[si]
         mov ah,02h
         int 21h
         dec si
         loop L1

         mov cl,alen
         mov ch,00h
         mov si,offset s
         mov di,si
         mov di,cx
         dec di

L2:    mov al,[si]
         cmp al,[di]
         jne L3
         inc si
         dec di
         cmp di,si
         jge L2
         print pal
         jmp exit

L3:    print npal
         jmp exit

exit:    mov ax,4c00h
          int 21h

code ends
end start