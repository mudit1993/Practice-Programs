; input a character and print the same inputted cgaracter and a message
print macro msg
    mov ah,09h
    mov dx,offset msg
    int 21h
endm
data segment
N db 13,10,'Thankyou$'
N2 db 13,10,'The entered character is $'
N3 db 13,10,'Enter a character $'
data ends

code segment
   assume cs:code,ds:data
start: mov ax,data
           mov ds,ax
           print N3
           
           mov ah,01h
           int 21h

            print N2
           mov dl,al
           mov ah,02h

           int 21h
           
           print N

exit: mov ax,4c00h
         int 21h

code ends
end start

           