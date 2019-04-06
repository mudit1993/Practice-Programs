print macro msg
push ax
push dx
mov ah,09h
mov dx, offset msg
int 21h
pop dx
pop ax
endm
data segment
        imsg db 13,10,'Enter the name of directory to be created:$'
        smsg db 13,10,'Succesfully created$'
        fmsg db 13,10,'Failure!!$'
        dname db 20 dup(0)
data ends

CODE segment
assume ds:data,cs:code

start:
        mov ax,data
        mov ds,ax
        print imsg
mov si,offset dname
read_next_char:
        mov ah,01h
        int 21h
        cmp al,13
je MAKE_DIR
        mov [si],al
        inc si
        jmp read_next_char

MAKE_DIR:

        mov ah,39h
        mov dx,offset dname
        int 21h
        jc error
        print smsg
        jmp exit

error:
        print fmsg
exit:
        mov ax,4c00h
        int 21h
code ends
end start
