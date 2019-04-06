Print MACRO message
  MOV ah,09h
  Mov dx,offset message
  int 21h
ENDm

;Print1 MACRO message2
;   MOV ah,01h
;   int 21h
;ENDM

Data Segment

msg db 13,10,'Enter a name $'
N db 20 DUP('$')   ;  to input a String
N2 DB 20 dup('$')  
N3 db 20 DUP('$')
cho db 13,10,'$'    ;  to input a single element
cho2 db 13,10,'$'  
msg1 db 13,10,'Enter y our choice $'
msg2 db 13,10,'Press 1 to create directory $'
msg3 db 13,10,'Press 2 to delete directory $'
msg7 db 13,10,'Press 3 to find the present working directory $'
msg8 db 13,10,'Press 4 to exit $'
msg9 db 13,10,'Press 0 to exit else continue $'
msg4 db 13,10,'-------Menu------- $'
msg5 db 13,10,'You chose to exit $'
msg6 db 13,10,'$'
msg10 db 13,10,'Enter the name of the directory to be deleted $'
Data Ends

Code Segment

assume cs:code,ds:data

P1 proc
PUSH ax     ; to push registers onto the stack
PUSH dx
PUSH si

Print msg
MOV si,offset N;address of name

R1:    MOV ah,01h	;to take input from standard io device
       int 21h
       CMP al,13	; to check whether the user has entered or not
       JE R2
       MOV [si],al	; store character in an array
       INC si	        ; advance the index of the array 
       JMP R1

R2:   mov al,'$'
      mov [si],al 
      MOV ah,39h	;to create a directory
         
       MOV dx,offset N
       int 21h


E:     POP Si          ; to empty registers for other  procedures
       POP dx
       POP ax

ret    ; return to the start segment
ENDP

P2 proc              ; procedure for deleting a directory
PUSH ax
PUSH dx
PUSH si

Print msg10
MOv si,offset N2

S1:    MOV ah,01h	;to take input from standard io device
       int 21h
       CMP al,13	; to check whether the user has entered or not
       JE S2
       MOV [si],al	; store character in an array
       INC si	        ;advance the index of the array 
       JMP S1

S2:    MOV AH,3AH	;to delete a directory
         
       MOV dx,offset N2
       int 21h

F:     POP Si          ; to empty registers for other  procedures
       POP dx
       POP ax

RET                     ; return to the start segment
ENDP

P3 proc             ; procedure for current working directory
PUSH ax
PUSH dx
PUSH si
         
T1:   MOV ah,47H          ;to display a working directory
      mov dl,01h
      MOV dx,offset N3
      int 21h

      MOv ah,09h
      MOv dx,offset N3
      int 21h
 
G:     POP Si          ; to empty registers for other  procedures
       POP dx
       POP ax

RET                     ; return to the start segment
ENDP

Start: MOV ax,data         ;move to gpr
       Mov ds,ax           ;address of dx

       Print msg4
       Print msg2
       Print msg3
       Print msg7
       Print msg8

         
choice: Print msg1       ; asks for entering
        MOV ah,01h      ; to input the choice
        INT 21H


        CMP al,'1'
        JE A1
        CMp al,'2'
        JE a2
        CMP al,'3'
        JE a3
        CMP al,'4'
        JE a4

A1:     call P1
        Print msg9
        MOV ah,01h
        INT 21H
        CMP al,'0'
        JE exit
        JMP choice

A2:     call P2
        Print msg9
        MOV ah,01h
        INT 21H
        CMP al,'0'
        JE exit
        JMP choice

A3:     call P3
        Print msg9
        MOV AH,01H
        INT 21H
        CMP al,'0'
        JE exit
        JMP choice

A4:     print msg5
        JMP exit

exit:   MOV ax,4c00h
        int 21h


code ends
end start 
