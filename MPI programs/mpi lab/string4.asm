; print a string

data segment

na db 13,10,'Hello World $'

data ends

code segment
   assume cs:code,ds:data

start:mov ax,data
          mov ds,ax
         mov ah,09h
          mov dx,offset na
          int 21h

exit:   mov ax,4c00h
           int 21h

code ends
end start