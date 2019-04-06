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

                    
        mmsg db 13,10,'**Menu**$'
        msg1 db 13,10,'1:CREATE$'
	msg2 db 13,10,'2:DELETE$'
	msg3 db 13,10,'3:CHANGE DIRECTORY$'
	msg4 db 13,10,'4:DISPLAY PRESENT WORKING DIRECTORY$'
	msg5 db 13,10,'5:EXIT$'
	cmsg DB 13,10,'Enter your choice$'
	wchmsg db 13,10,'Illegal choice!$'
	imsg db 13,10,'Enter the name of the Directory:$'
	smsg db 13,10,'Success$'
	fmsg db 13,10,'Failure! Try again$'
	ssmsg db 13,10,'The present working directory is:$'
	dname db 20 dup (0)
	dname1 db 20 dup('$')

	
data ends

code segment
assume ds:data, cs:code


start:
        mov ax, data
        mov ds, ax

menu:
	print mmsg
	print msg1 
	print msg2
	print msg3
	print msg4
	print msg5
	print cmsg

        mov ah, 01h
	int 21h
	cmp al,'1'
	call p1
	cmp al,'2'
	call p2
	cmp al,'3'
        call p3
	cmp al,'4'
        call p4
	;cmp al,'5'
        ;call p5
	print wchmsg
        jmp exit
	
P1 PROC NEAR
	push si 
	push ax
	push dx
	print imsg
	mov si,offset dname

read_next_char:
        mov ah, 01H
        int 21H
        cmp al,13

        je make_dir
        mov [si], al
        inc si
        jmp read_next_char

make_dir:
        mov ah, 39H
        mov dx, offset dname
        int 21H
        jc error
        print smsg
        jmp exit

error:
        print fmsg
        
exit:   pop dx
	pop ax
	pop si
	ret
P1 endp

P2 PROC NEAR
	push si 
	push ax
	push dx
	print imsg
	mov si,offset dname

read_next_char2:
        mov ah, 01H
        int 21H
        cmp al,13

        je del_dir
        mov [si], al
        inc si
        jmp read_next_char2

del_dir:
        mov ah, 3aH
        mov dx, offset dname
        int 21H
        jc error2
        print smsg
        jmp exit

error2:
        print fmsg

exit2:   pop dx
	pop ax
	pop si
	ret
P2 endp

P3 PROC NEAR
	push si 
	push ax
	push dx
	print imsg
	mov si,offset dname

read_next_char3:
        mov ah, 01H
        int 21H
        cmp al,13

        je ch_dir
        mov [si], al
        inc si
        jmp read_next_char3

ch_dir:
        mov ah, 39H
        mov dx, offset dname
        int 21H
        jc error3
        print smsg
        jmp exit

error3:
        print fmsg

exit3:   pop dx
	pop ax
	pop si
	ret
P3 endp

P4 PROC NEAR
	push si
	push ax
	push dx
        mov ah, 47H
	mov dl,0
	mov si,offset dname1
	int 21h
	jc error4
        print ssmsg
	print dname1
        jmp exit

error4:
        print fmsg
        
exit4:   pop dx
	pop ax
	pop si
	ret
P4 endp
code ends
end start
