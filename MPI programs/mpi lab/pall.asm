print macro msg
	mov ah,09h
	mov dx,offset msg
	int 21h
endm
data segment
	emsg db 13,10,"enter the number$"
	pmsg db 13,10,"pallindrome$"
	npmsg db 13,10,"not a pallindrome$"
	new db 13,10,"$"
	n db 40 DUP(?)
data ends
code segment 
	assume cs:code,ds:data
	start:
		mov ax,data
		mov ds,ax
		print emsg
		mov bx,0
		
	read:
		mov ah,01h
		int 21h
		cmp al,13
		je r1
		mov [n+bx],al
		inc bx
		jmp read
	r1:
		mov di,0
		dec bx
		jmp p1
	p1:
		mov al,[n+bx]
		cmp al,[n+di]
		jne fail
		inc di
		dec bx
		jnz p1
		mov dx, offset new
		
		print pmsg
		jmp exit
	fail:
		print npmsg
		jmp exit
	exit:
		mov ah,4ch
		int 21h
	
code ends
end start
		