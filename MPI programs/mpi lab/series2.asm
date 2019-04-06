  d segment
  d ends

  c segment
       assume cs:c,ds:d
 
start:  mov  ah,02h      ;        to print the output
            mov dl,65
            int 21h
 
           mov dl,44
           int 21h

           mov dl,66
           int 21h
  
          mov dl,44
          int 21h
  
         mov dl,67
         int 21h
   
        mov  dl,44
        int 21h

       mov dl,68
       int 21h
   
       mov dl,44
       int 21h

 
       mov dl,69
        int 21h

exit:  mov ax,4c00h
          int 21h

c ends
end start