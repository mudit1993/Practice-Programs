data segment
	msg db 13,10,"not match$"
	msg1 db 13,10,"cracked$"
	pas db 4 dup('m','o','n','i')
	p db 4 dup(0)
data ends

code segment
	assume cs:code,ds:data
start:
	mov ax,data
	mov ds,ax

	mov bx,0
	mov cx,4
xx:
	mov ah,08h
	int 21h
	mov [p+bx],al
	mov ah,02h
	mov dl,'#'
	int 21h
	
	
	
	inc bx
	loop xx
	mov bx,0
	
pass:
	mov al,[p+bx]
	cmp al,[pas+bx]
	jne fail
	inc bx
	cmp bx,4
	je success
	jmp pass

success: mov ah,09h
	mov dx,offset msg1
	int 21h
	jmp exit

fail:
	mov ah,09h
	mov dx,offset msg	
	int 21h
	jmp exit
exit:
	

	mov ah,4ch
	int 21h
code ends
end start
 