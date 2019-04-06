; create a file
print macro msg
     mov ah,09h
     mov dx,offset msg
     int 21h
endm
data segment
   N db 20 Dup('$')
   N2 db 13,10,'Enter a name $'
data ends
code segment
   assume cs:code,ds:data
start: mov ax,data
            mov ds,ax
            print N2
            mov si,offset N
R1:     mov ah,01h
           int 21h
           cmp al,13
           je R2
           mov[si],al
           int 21h
           inc si
           jmp R1
R2:   mov ah,5bh
          mov cx,0000h
          mov dx,offset N
          int 21h
exit:  mov ax,4c00h
          int 21h
code ends
end start
            