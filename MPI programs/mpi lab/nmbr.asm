y segment
             msg db "enter the first digit:$"
           msg db "enter the 2nd digit :$"
           msg db "enter the 3rd digit:$"
        y ends
print macro message
  mov ah,09h
  x segment
       cs:x,ds:y
start:
        mov ax,y
       mov ds,ax
       print msg
       mov ah , 01h
       int 21h

      mov ax,y
       mov ds,ax
       print msg1
       mov ah , 01h
       int 21h

      mov ax,y
       mov ds,ax
       print msg2
       mov ah , 01h
       int 21h