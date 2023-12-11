# M031BSP_UART_FIFO
 M031BSP_UART_FIFO


update @ 2023/12/11

1. init UART1(COM5 , PC send data to MCU) , and UART0(COM6 , MCU display LOG message:data from PC)

![image](https://github.com/released/M031BSP_UART_FIFO/blob/main/device_manager_COM5.jpg)

![image](https://github.com/released/M031BSP_UART_FIFO/blob/main/device_manager_COM6.jpg)


2. below is the log message when PC(COM5) send data to MCU:UART1 , and MCU:UART0 log data result (COM6)

when UART1(COM5) send 4K data , MCU receive 4K data as well 

![image](https://github.com/released/M031BSP_UART_FIFO/blob/main/log_4K.jpg)

when UART1(COM5) send 12K data , MCU receive 12K data as well 

![image](https://github.com/released/M031BSP_UART_FIFO/blob/main/log_12K.jpg)

when UART1(COM5) send 12K data with 5 times , MCU receive 12K data 5 times as well 

![image](https://github.com/released/M031BSP_UART_FIFO/blob/main/log_12K_5times.jpg)


3. if enable define : USE_UART_TX 

below is the log message when PC(COM5) send data to MCU:UART1 , MCU:UART0 log data result (COM6) , also send UART1 TX to COM5 

MCU:UART1 receive 4K data and send 4K data to PC(COM5)

![image](https://github.com/released/M031BSP_UART_FIFO/blob/main/log_COM5_TX_teraterm_4K.jpg)


MCU:UART1 receive 12K data and send 12K data to PC(COM5)

![image](https://github.com/released/M031BSP_UART_FIFO/blob/main/log_COM5_TX_teraterm_12K.jpg)

