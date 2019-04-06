terminal 1


gcc tcpserver.c -o server -pthread 

./server





terminal 2


gcc tcpclient.c -o client -pthread

./client 192.168.0.4 
