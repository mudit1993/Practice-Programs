print macro msg
    mov ah,09h
    mov dx,offset ,sg
    int 21h
endm  

data segment
   imsg db 13,10,'Enter the string $'
   omsg db 13,10,'The entered string is $'
   lmsg db 13,10,'The length of the string is $'
  ; rmsg db 13,10,'The reverse of the string is $'
  ; npal db 13,10,'The string is not a paplindrome $'
  ; pal db 13,10,'The string is a palindrome $'
  buf label byte
  mlen db 40
  alen db?
  str db 40 dup('$')
data ends

code segment
   asuume cs:code,ds:data
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
         print str
         print lmsg
         mov al,alen
         mov ah,00h
         call printnum

         mov cl,alen
         mov ch,00h
         mov si,offset str
         add si,cx
         dec si
        ; print rmsg

exit:    mov ax,4c00h
          int 21h

code ends
end start