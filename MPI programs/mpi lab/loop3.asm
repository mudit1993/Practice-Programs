Data Segment
Data Ends
Code Segment

assume cs:code,ds:data

Start:MOV ah,2;to print the o/p
      MOV dl,65
      MOV bh,1
      MOv dh,1
      
L2:   int 21h
      ADD dh,1
      ADD dl,dh
      ADD bh,1
      CMP bh,6
      JE L3
      MOV dl,',';to print a comma
      int 21h
      CMP bh,6
      JLE L2

L3:   MOv ax,4c00h
      int 21h
Code Ends
End Start