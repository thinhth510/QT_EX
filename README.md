# QT_EX

Examples about **QThread**

1. **Thread Intro**  
   Demonstrates transmitting and receiving between two devices, each running in a different thread.

2. **Thread Pools**  
   Demonstrates an album containing songs, where a `QThreadPool` receives a song and processes it.

3. **Thread Concurrent**  
   Demonstrates using `<QFuture>` and `<QtConcurrent>` to run two independent tasks without manually creating or managing `QThread` objects.

Examples about **QNetwork**

1. **TCP-IP_Communication**  
   Demonstrates using '<QtNetwork/QTcpSocket>' and '<QtNetwork/QHostAddress>' to transmit and receive message form QT(client) and PC(server)
   'nc -l -p 8080' 

2. **TCP-IP_Servers**  
   Demonstrates using '<QtNetwork/QTcpSocket>' and `<QtNetwork/QTcpServer>` to transmit and receive message form QT(server) and PC(client)
   'nc 127.0.0.1 8080' - each terminal window  similar like a client

3. **TCP-IP_File_Transfer**  
   Demonstrates using '<QtNetwork/QTcpSocket>' and `<QtNetwork/QTcpServer>` to transmit and receive file form QT(server) and PC(client)
   'File (*.jpg *.png *.txt *.bmp)'
