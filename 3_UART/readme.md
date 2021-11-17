# The UART HAL driver can be used as follows:

1. (#) Declare a UART_HandleTypeDef handle structure.

2. (#) Initialize the UART low level resources by implementing the HAL_UART_MspInit() API:
    1. (##) Enable the USARTx interface clock.
    (##) UART pins configuration:
        (+++) Enable the clock for the UART GPIOs.
        (+++) Configure these UART pins as alternate function pull-up.
    2. (##) NVIC configuration if you need to use interrupt process (HAL_UART_Transmit_IT()
            and HAL_UART_Receive_IT() APIs):
        (+++) Configure the USARTx interrupt priority.
        (+++) Enable the NVIC USART IRQ handle.
    3. (##) DMA Configuration if you need to use DMA process (HAL_UART_Transmit_DMA()
            and HAL_UART_Receive_DMA() APIs):
        (+++) Declare a DMA handle structure for the Tx/Rx stream.
        (+++) Enable the DMAx interface clock.
        (+++) Configure the declared DMA handle structure with the required 
                Tx/Rx parameters.                
        (+++) Configure the DMA Tx/Rx Stream.
        (+++) Associate the initialized DMA handle to the UART DMA Tx/Rx handle.
        (+++) Configure the priority and enable the NVIC for the transfer complete 
                interrupt on the DMA Tx/Rx Stream.

3. (#) Program the Baud Rate, Word Length, Stop Bit, Parity, Hardware 
    flow control and Mode(Receiver/Transmitter) in the Init structure.

4. (#) For the UART asynchronous mode, initialize the UART registers by calling
    the HAL_UART_Init() API.
