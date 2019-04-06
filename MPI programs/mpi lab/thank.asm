print macro msg
      mov ah,09h
      mov dx,offset msg
      int 21h
endm
     data segment
          msg1 db 13,10,'Enter the message $'
          msg2 db 13,10,'Thankyou $'
   data ends
   
code segment
     assume cs:code,ds:data
            start:   mov ax,data
                         mov ds,ax
                        print msg1
                       mov ah,01
	int 21h
	print msg2
	mov ax,4c00h
	int 21h
code ends
end start