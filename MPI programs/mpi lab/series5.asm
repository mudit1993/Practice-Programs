; series A,C,F,J,O

data segment
data ends

code segment
  assume cs:code,ds:data
  
start: mov ah,02h
           mov dh,1
           mov bh,1
           mov dl,65

L1:     int 21h
           add dh,1
           add dl,dh
           add bh,1
           cmp bh,6
           je exit
           cmp bh,6
           jle L1

exit:   mov ax,4c00h
           int 21h 

code ends
end start