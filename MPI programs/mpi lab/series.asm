 ; to print ABCD

data segment
 data ends

code segment
 assume cs:code,ds:data

start: mov ah,02h         ; to print an output
            mov dl,65
            int 21h
            
           mov dl,66
           int 21h

           mov dl,67
           int 21h


          mov dl,68
          int 21h

exit:   mov ax,4c00h
           int 21h

code ends
end start