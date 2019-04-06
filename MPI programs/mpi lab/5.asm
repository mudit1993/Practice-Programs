print macro msg
push ax
push dx
mov ah,09h
mov dx,offset msg
int 21H
pop dx
pop ax
endm

DATA SEGMENT
        imsg db 13,10,'ENTER THE NAME OF THE DIRECTORY TO BE CHANGED: $'
        smsg db 13,10,'Successfully changed! $'
        fmsg db 13,10,'FAILED!! Try again! $'
        dname db 20 dup(0)
DATA ENDS


CODE SEGMENT
ASSUME DS:DATA,CS:CODE

START:

        MOV AX, DATA
        MOV DS,AX

        PRINT IMSG
        MOV SI,OFFSET DNAME

READ_NEXT_CHAR:

        MOV AH,01H
        INT 21H
        CMP AL,13

        JE CHN_DIR
        MOV[SI],AL
        INC SI
        JMP READ_NEXT_CHAR

CHN_DIR:
        MOV AH, 3BH
        MOV DX,OFFSET DNAME
        INT 21H

        JC ERROR
        PRINT SMSG
        JMP EXIT


ERROR:

        PRINT FMSG


EXIT:

        MOV AX,4C00H
        INT 21H
CODE ENDS
        END START

