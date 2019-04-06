; to print the series A,C,E,G,I,K

data segment
data ends

code segment
    assume cs:code,ds:data
   
start: mov ah,02h
           mov dl,65
           mov bh,1
          
           
L1:     int 21h
           add dl,2
           add bh,1

           mov dh,dl
           mov dl,','
           int 21h
           mov dl,dh
           cmp bh,6
           jle L1


            
exit:    mov ax,4c00h
            int 21h

code ends
end start
            