Data Segment
Data Ends

Code Segment
assume cs:code,ds:data
Start:mov ax,2;
      mov dl,65;
      int 21h
      mov ax,2;
      mov dl,66;
      int 21h
      mov ax,2;
      mov dl,67;
      int 21h
      mov ax,2;
      mov dl,68;
      int 21h
      
     mov ax,4c00h
     int 21h
Code Ends
End Start