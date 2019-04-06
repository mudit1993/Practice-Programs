Print MACRO message
  MOV ah,09     ; to print
  MOV dx,offset message      ; add offset
  int 21h
ENDM

Data Segment
msg db 13,10,'Enter your choice $'
input db 13,10,'$'
msg1 db 13,10,'Press 1 $'
msg2 db 13,10,'Press 2 $'
msg3 db 13,10,'Press 3 $'
msg4 db 13,10,'Press 4 $'
msg5 db 13,10,'Press 5(To exit) $'
msga db 13,10,'You chose 1 $'
msgb db 13,10,'You chose 2 $'
msgc db 13,10,'You chose 3 $'
msgd db 13,10,'You chose 4 $'
msge db 13,10,'You chose to exit $'
msgf db 13,10,'------------------$'
Data Ends

Code Segment

assume cs:code,ds:data

Start: MOV ax,data
       MOv ds,ax
       
Choice: Print msgf
        Print msg1
        Print msg2
        Print msg3
        Print msg4
        Print msg5
 
        Print msg
        MOv ah,01h             ;for user input
        MOV dx,offset input
        int 21h                 ;dos service call
   
        CMP al,'1'
        JE A1
        CMP al,'2'
        JE A2
        CMP al,'3'
        JE A3
        CMP al,'4'
        JE A4
        CMP al,'5'
        JE A5

A1:  Print msga
     JMP choice
     
A2:  Print msgb
     JMP choice

A3:  Print msgc
     JMP choice

A4:  Print msgd
     JMP choice

A5:  Print msge  
     JMP exit     

exit: MOV ax,4c00h
      int 21h
code ends
end start