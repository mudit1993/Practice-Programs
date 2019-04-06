Data segment
data ends
code segment
Assume cs:code, ds:data
start:
mov ah, 2
mov dl,0
mov cl,ah

l1:
       add dl,ah
       dec cl
       cmp cl,0
       jg l1
	mov ah,2
       add dl,48
       int 21h

mov ah,4ch
int 21h
code ends
end start
