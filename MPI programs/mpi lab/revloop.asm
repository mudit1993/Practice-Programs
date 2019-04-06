x segment
 str db "enter string: $"
 str1 db "   The reverse of the entered string is : $"
x ends

y segment
 main proc far
 assume ds:x,cs:y
 push ds
 push 0000H
 mov ax,x
 mov ds,ax
 mov ah,09h
 mov dx,offset str
 int 21h

 mov cx,4

  input:
	mov ah,01h
	int 21h
	mov ah,00h
	push ax
	loop input

 mov ah,09h
 mov dx,offset str1
 int 21h

 mov cx,4
   disp:
	pop ax
	mov dl,al
	mov ah,02h
	int 21h
	loop disp


ret
main endp
y ends
end main