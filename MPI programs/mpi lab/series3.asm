;to print the series A,AA,AAA,AAAA,AAAAA

data segment
data ends

code segment
   assume cs:code,ds:data
 
start: mov bh,1
           mov ah,02h

L1:    mov dl,65
          mov dh,1

L2:   int 21h
         add dh,1
         cmp dh,bh
         jle L2

         add bh,1
         cmp bh,6
         je exit

         mov dl,','
         int 21h
         cmp bh,6
         jle L1

exit: mov ax,4c00h
         int 21h

code ends
end start
         
 
           
              

             