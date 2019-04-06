Data Segment
Pmsg DB 13,10, 'Welcome to kiit $'
P DB 13,10, 'Welcome to cs-1 $'
H db 13,10,'welcome $' 
s db 123,'$'
Data ends


Code Segment
Assume cs:Code,ds:Data
start:
	mov ax,Data
	mov ds,ax
	mov ah,09h
	mov dx,offset Pmsg
	int 21h

	mov dx,offset P
	int 21h

	mov ah,02h
	mov dl,65
	int 21h

	mov ax,4C00H
	int 21h
Code ends
end  start
