CODE SEGMENT 
ASSUME CS:CODE
START:
 MOV AH,01H
INT 21H

CMP AL,64
JLE L1
CMP AL,91
JGE L2

MOV AH,02H
ADD AL,32
MOV DL,AL
INT 21H

MOV AH,4CH
INT 21H

L2:CMP AL,96
JLE L1
CMP AL,123
JGE L1

MOV AH,02H
SUB AL,32
MOV DL,AL
INT 21H

MOV AH,4CH
INT 21H

L1:MOV AH,02H
MOV DL,78
INT 21H

MOV AH,4CH
INT 21H

CODE ENDS
END START