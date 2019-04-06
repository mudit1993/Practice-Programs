 PRINTMSG macro msg

 mov ah,09H
 mov dx,offset msg
 int 21h

 endm


DATA SEGMENT
PMSG DB 13,10, 'Hello World $'
KMSG DB 13,10, ' KIIT $'
DATA ENDS

CODE SEGMENT

        assume CS:CODE , DS:DATA

 START: MOV ax,data
        MOV ds,ax
        PRINTMSG PMSG
        PRINTMSG KMSG
        MOV ax,4C00H
        INT 21H

 CODE ENDS
 END START
