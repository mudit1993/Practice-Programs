; to print a singl e 'B'


 data segment
 data ends

code segment
     assume cs:code,ds:data

start: mov ah,02h      ; to print a character
           mov dl,66 
           int 21h                ; dos service call

exit:     mov ax,4c00h
             int 21h

code ends
end start