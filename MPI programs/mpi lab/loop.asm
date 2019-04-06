Data Segment
Data Ends
Code Segment

assume cs:code,ds:data

Start:MOV ah,2;to write to o/p device
      MOV bh,1

L2: MOV dh,1
    MOV dl,65

L1: int 21h;to call dos service
    ADD dh,1
    CMP dh,bh
    JLE L1;jump less than equal to segment L2
    ADD bh,1
    CMP bh,6;we're printing 5 times so one less
    JE L3
    MOV dl,44;to print comma
    int 21h
    CMP bh,6
    JLE L2

L3: MOV ax,4c00h
    int 21h
    Code Ends
    End Start