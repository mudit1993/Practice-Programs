Data Segment
pmsg db 13,10,'Childhood is a kingdom where nobody dies $';db reserves memory
Data ends
Code Segment
assume cs:code,ds:data

Start: MOV ax,data;data moved to gpr
       MOV ds,ax;
       MOV ah,09h;ah when 9 displays a string
       MOV dx,offset pmsg
       int 21h
       
       MOV ax,4c00h;to terminate
       int 21h
Code Ends
End Start