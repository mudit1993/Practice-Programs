Data Segment
Pmsg DB 13,10, 'Welcome to kiit $'
P DB 13,10, 'Welcome to cs-2 $'
H db 13,10,'welcome $' 
Data ends
Code Segment
Assume cs:Code,ds:Data
start:mov ax,Data
mov ds,ax
mov ah,09h
mov dx,offset Pmsg
int 21h
mov dx,offset P
int 21h
mov dx,offset H
int 21h
mov ax,4C00H
int 21h
Code ends
end  start
