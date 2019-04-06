Data Segment
Data Ends
Code Segment

assume cs:code,ds:data

Start:MOV ah,2;to print the o/p
      MOV dl,65
      
L2:   int 21h
      ADD dl,2
      ADD dh,1
      CMP dh,8
      JE L3
    ;  MOV bl,',';to print a comma
    ;  int 21h
      CMP dh,8
      JLE L2

L3:   MOv ax,4c00h
      int 21h
Code Ends
End Start