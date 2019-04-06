; delete a directory
print macro msg
      mov ah,09h
      mov dx,offset msg
      int 21h
endm
data segment
      N db 13,10,'Enter a name $'
      N2 db 13,10,'directory deleted $'
      N3 db 20 dup ('$')
data ends
code segment
  assume cs:code,ds:data
start: mov ax,data
           mov ds,ax
           print N
           mov si,offset N3
R1:    mov ah,01h
           int 21h
           cmp al,13
           je R2
           mov[si],al
           inc si
           je R1
R2:    mov ah,3ah
           mov dx,offset N3
           int 21h
exit:  mov ax,4c00h
          int 21h

code ends
end start
         