; input a string and print the same
print macro msg
     mov ah,09h
     mov dx,offset msg
     int 21h
endm
data segment
   N db 13,10,'Enter a string $'
   N2 db 13,10,'The entered string is $'
   N3 db 20 dup('$')
data ends

code segment
   assume cs:code,ds:data
start: mov ax,data
            mov ds,ax
            print N
            mov ah,01h
            mov si,offset N3
R1:     int 21h
            cmp al,13
            je R2
            mov [si],al
            inc si
            jmp R1

R2:     print N2
            print N3

exit: mov ax,4c00h
         int 21h

code ends
end start