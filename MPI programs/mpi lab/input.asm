; input a character and print a thankyou message
print macro msg
       mov ah,09h
       mov dx,offset msg
       int 21h
endm
data segment

N db 13,10,'Thankyou$'
N2 db 13,10,'Enter a character $'

data ends

code segment
   assume cs:code,ds:data
  
start: mov ax,data
            mov ds,ax
            print N2
            mov ah,01h  ; when ah=01 we can take an input
            int 21h
            print N

exit:  mov ax,4c00h
          int 21h

code ends
end start