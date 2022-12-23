#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"

#define BUF_SIZE (1024)

#define UART0_PRINT(str,len) {uart_write_bytes(UART_NUM_0, str , len);}
#define UART0_PRINT_AUTO(str) {uart_write_bytes(UART_NUM_0, str , strlen(str));}

void app_main()
{
    //xTaskCreate(uart_echo_task, "uart_echo_task", 1024, NULL, 10, NULL);

    // UART 设置

    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
        /*
        * - Port: UART0
        * - Receive (Rx) buffer: on
        * - Transmit (Tx) buffer: off
        * - Flow control: off
        * - Event queue: off
        * - Freq: 115200
        */
    };
    uart_param_config(UART_NUM_0, &uart_config);
    uart_driver_install(UART_NUM_0, BUF_SIZE * 2, 0, 0, NULL, 0);
    uint8_t *data = (uint8_t *) malloc(BUF_SIZE);
    /*
     * // Read data from the UART
        int len = uart_read_bytes(UART_NUM_0, data, BUF_SIZE, 20 / portTICK_RATE_MS);
        // Write data back to the UART
        uart_write_bytes(UART_NUM_0, (const char*)data , len);
    */
    
}