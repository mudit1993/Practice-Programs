data segment
        pmsg1 db 13,10, 'welcome to kiit $'
        pmsg2 db 13,10, 'this is year 2012 $'
        pmsg3 db ' and 18th of january $'
data ends

code segment
        assume cs:code,ds:data
        start:mov ax,data
        mov ds,ax

        mov ah,09h
        mov dx,offset pmsg1
        int 21h

        mov ah,09h
        mov dx,offset pmsg2
        int 21h

        mov ah,09h
        mov dx,offset pmsg3
        int 21h

        mov ax,4c00h
        int 21h

code ends
end start
