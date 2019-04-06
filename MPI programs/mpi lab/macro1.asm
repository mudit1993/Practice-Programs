PrintString MACRO msg;macro begins
     MOV ah,09h;ah when 9 displays a string
     MOV dx,offset msg
     int 21h
ENDM;ends macro

Data Segment

N db 13,10,'Seth Everett$';db reserves memory
Roll db 13,10,'12$'
Course db 13,10,'English$'
Branch db 13,10,'Arts$'
Email db 13,10,'sethev.12@gmail.com$'

Data ends 



Code Segment

assume cs:code,ds:data

Start: MOV ax,data;data moved to gpr
       MOV ds,ax

       PrintString N
       PrintString Roll
       PrintString Course
       PrintString Branch
       PrintString Email 

       MOV ax,4c00h;to terminate
       int 21h
Code Ends
End Start