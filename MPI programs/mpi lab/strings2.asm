Print MACRO msg
      MOV ah,09h
      MOV dx,offset msg
      int 21h
ENDM
Data Segment

msg1 db 13,10,'Enter a message$'
msg2 db 13,10,' $'
msg3 db 13,10,'The character entered is $'
op db 13,10,'Thank You$'

Data Ends

Code Segment

assume cs:code,ds:data

Start:MOV ax,data
      MOV ds,ax
      Print msg1
      MOV ah,01;to take input
      int 21h
      Print msg2
      Print msg3
      MOv ah,2
      MOV dl,al
      int 21h
      Print op     
      
      MOv ax,4c00h
      int 21h
Code Ends
End Start