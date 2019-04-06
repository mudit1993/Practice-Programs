; current working directory
data segment
   N db 50 dup('$')
data ends

code segment
  assume cs:code,ds:data
start: mov ax,data
           mov ds,ax
          
          mov ah,47h
         ; mov dl,01h
          mov si,offset N
          int 21h

         mov ah,09h
         mov dx,offset N
         int 21h

exit:  mov ax,4c00h
          int 21h

code ends
end start
         