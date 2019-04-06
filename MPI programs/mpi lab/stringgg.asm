data segment
	msg db 'Enter first string','$'
	msg1 db 'Entered string is: ','$'
	msg2 db 'Enter 2nd string','$'
	buff db 50 dup(0)
	buff1 db 50 dup(?)
	buff2 db 100 dup(?)
data ends

code segment
	assume cs:code, ds:data
	start:
	push ds
	push 0000H

	mov ax, data
	mov ds, ax

	mov ah, 09h
	mov dx, offset msg
	int 21h
	
	
	mov si, offset buff
	mov cx,5
rdchar1:
	mov ah, 01h
	int 21h

	mov [si], al
loop rdchar1
inc si
mov dx, offset msg1
mov cx,5
l2:
	mov dl,buff
	mov ah,02h
	int 21h
loop l2


ret
code ends
end start