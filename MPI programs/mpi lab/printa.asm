DATA SEGMENt
DATA ENDS

CODE SEGMENT
assume cs:code,ds:data
START: mov ah,2;write to o/p
       mov dl,69;ascii value
       int 21h;calling dos service
  
       mov ax,4c00h
       int 21h

CODE ENDS
END START