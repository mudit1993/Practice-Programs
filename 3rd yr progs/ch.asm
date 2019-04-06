CODE SEGMENT
ASSUME CS:CODE
START:
MOV AH,01H
INT 21H
MOV DL,AL
MOV AH,02H
INT 21H
MOV AH,4CH
INT 21H
CODE ENDS
END START
                                                                                                                              