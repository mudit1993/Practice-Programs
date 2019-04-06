Data Segment
Pmsg DB 13,10, 'WELCOME TO KIIT $'
P DB 13,10, 'WELCOME TO CS-1 $'
H DB 13,10, 'WELCOME $'
Data ends

code Segment
Assume cs:Code, ds:data
start:mov ax, Data
mov ds,ax
mov ah, 09h
mov dx, offset Pmsg
int 21h
mov dx, offset P
int 21h
mov dx, offset H
int 21h
mov ax, 4C00H
int 21h
Code ends
end start
