PrintString MACRO p;macro
     MOV ah,09h;ah when 9 displays a string
     MOV ds,ax;
     int 21h
ENDM

Data Segment

msg1 db 13,10,'Name$';db reserves memory
msg2 db 13,10,12
msg3 db 13,10,'Course$'
msg4 db 13,10,'Branch$'
msg5 db 13,10,'Email$'

Data ends 



Code Segment

assume cs:code,ds:data

Start: MOV ax,data;data moved to gpr
       MOV dx,offset pmsg
       PrintString msg1
       PrintString msg2
       PrintString msg3
       PrintString msg4
       PrintString msg5 

       MOV ax,4c00h;to terminate
       int 21h
Code Ends
End Start