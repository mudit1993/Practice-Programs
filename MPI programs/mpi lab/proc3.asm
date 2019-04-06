print macro msg
       push ax
       push dx
       mov ah,09h
       mov dx,offset msg
       int 21h
       pop dx
       pop ax
endm

Data Segment
       pmsg db 13,10,'Enter a number$'
       psmsg db 13,10,'The sum is $'
       psmsg2 db 13,10,'The sub is $'
       psmsg3 db 13,10,'The div is $'
       num1 dw 0
       num2 dw 0
       msga db 13,10,'Enter your choice $'
       input db 13,10,'$'
       msg1 db 13,10,'Press 1 $'
       msg2 db 13,10,'Press 2 $'
       msg3 db 13,10,'Press 3 $'
       msg4 db 13,10,'Press 4 $'
       msg5 db 13,10,'Press 5(To exit) $'
Data Ends

Code Segment

       assume cs:code,ds:data

  readnum proc
           push ax
           push bx
           push cx

        mov cx,0
        mov dx,0
        mov bx,10

R1: mov ah,01h;                   get a character from keyboard
      int 21h
      cmp al,13;                    comparing ascii of entered with the currently entered
      je E1;                           if the character entered is 'enter'-13
      sub al,48;                      getting the decimal equivalent of the entered number by subtracting it from the ascii of 0 i.e 48
      mov cl,al;                      store the inputted character in the cl register
      mov ax,dx;                    store the previously contained character which was in dx in ax
      mul bx;                         multiplied previously stored number which was in ax with bx which is 10
      add ax,cx;                     add the currently inputted digit with the previous one
      mov dx,ax;                    store in dx
      jmp R1;                          jump for next digit

E1:  pop cx
       pop bx
       pop ax
ret
endp;                                 end of procedure

printnum proc

      push bx
      push cx
      push dx

      mov cx,0
      mov bx,0ah

D1: mov dx,0
      div bx;                        divide by 10
      add dx,48;    remainder is converted to ascii is it <10
      push dx
      inc cx;                        counter for tracking digit
      cmp ax,10;                  quotient is compared to 10 for decimal 
      jge D1;                        if quotient > 10 , we'll divide

      add ax,48;
      push ax;
      inc cx
      mov ah,02h;                write to standard o/p device

pnum: pop dx
          int 21h
          loop pnum
          
          pop dx
          pop cx
          pop bx
ret
endp
                         
Start: mov ax,data
         mov ds,ax
         print pmsg
         call readnum
         mov num1,dx
  
      ;   mov ax,dx
      ;   call printnum

         print pmsg
         call readnum
          mov num2,dx

      ;   mov ax,dx
     ;    call printnum
      ;   jmp exit
        
          print msga
          mov ah,01h
          mov dx,offset input
          int 21h                 ;dos service call  

        CMP al,'1'
        JE addition
        CMP al,'2'
        JE subtraction
        CMP al,'3'
        JE multiplication
      ;  CMP al,'4'
     ;   JE A4
        CMP al,'5'
        JE exit

addition:     mov ax,num1
                 add ax,num2
                 print psmsg
                 call printnum
                 jmp exit

subtraction:  mov ax,num1
                   sub ax,num2
                   print psmsg2
                   call printnum
                   jmp exit

multiplication:   mov ax,num1
                       mov cx,num2
                       mul cx
                      print psmsg3
                       call printnum
                       jmp exit

exit:  mov ax,4c00h
        int 21h

code ends
end start
         