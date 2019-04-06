DATA SEGMENT
END SEGMENT
CODE SEGMENT
ASSUME CS: CODE,DS: DATA
START: 
	mov ah,1
	int 21h
	mov dl,al
	
	mov ah,2
	int 21h
	mov ah,4ch
	int 21h
code ends
end start