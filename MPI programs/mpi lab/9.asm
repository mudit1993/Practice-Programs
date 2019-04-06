print macro msg
push ax
push dx
mov ah, 09H
mov dx, offset msg
int 21H
pop dx
pop ax
endm

data segment
        imsg db 13,10,'Enter old file name: $'
        nmsg db 13,10,'Enter new file name: $'
        smsg db 13,10,'File Successfully renamed!$'
        fmsg db 13,10,'File renaming unsuccessful! Try Again!$'
        oldname db 20 dup (0)
        newname db 20 dup (0)
data ends

code segment
assume ds:data, cs:code

start:
        mov ax, data
        mov ds, ax
        mov es, ax
        print imsg
        mov si, offset oldname

read_next_char:
        mov ah, 01H
        int 21H
        cmp al,13
        je read2nd
        mov [si], al
        inc si
        jmp read_next_char

read2nd: print nmsg
         mov si, offset newname

read_next_char1:
        mov ah, 01H
        int 21H
        cmp al,13
        je renfile
        mov [si], al
        inc si
        jmp read_next_char1

renfile:
        mov ah, 56H
        mov dx, offset oldname
	mov di, offset newname
        int 21H
        jc error
        print smsg
        jmp exit

error:
        print fmsg

exit:
        mov ax, 4C00H
        int 21H

code ends
end start
