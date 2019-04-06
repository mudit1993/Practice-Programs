print macro message
	mov ah,09h
	mov dx,offset message
	int 21h
endm

data segment 
	msg db 13,10,"enter the no$"
data ends



code segment		
	assume cs:code,ds:data
start:
	mov ax,data
	mov ds,ax
	mov dx,0	
	
	print msg
	read:
		mov ah,01h
		int 21h
		mov cx,0
		mov bh,0
		
		cmp al,13
		je done
		mov bx,10
		sub al,48
		mov cl,al
		mov ch,0
		mov ax,dx
		mul bx
		add ax,cx
		mov dx,ax
		jmp read

	done:
		mov bl,10
		mov ax,dx
		div bl
		mov dl,ah
		mov dh,0
		push dx
		inc cx
		mov ah,0
		mov dx,ax
		cmp al,10
		jge done
		mov ah,02h
		mov dl,al
		add dl,48
		int 21h

	x:
		pop dx
		add dx,48
		int 21h
	loop x	
		
		
		
	

	mov ah,4ch
	int 21h
code ends 
end start		
	


