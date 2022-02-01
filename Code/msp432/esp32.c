/***************************************************************************************
 * @file esp32.c :
 * @brief : This file contains wifi configuration
 *
 * @date : Nov 29 2021
 * @author: Rajat Chaple
 ****************************************************************************************/

/*---Includes---*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "msp.h"
#include "uart.h"
#include "cbfifo.h"
#include "gpio.h"
#include "esp32.h"
#include "timers.h"
#include "lcd.h"

//states for wifi connections
typedef enum wifi_state_e{
STATE_AT_CHECK,
STATE_WIFI_MODE_3,
STATE_SET_SSID_PASSWORD,
STATE_WIFI_MODE_1,
STATE_CONNECT_TO_WIFI,
NO_COMMAND = 'z'
}wifi_state_t;

//states for starting wifi
typedef enum tcp_server_state_e{
STATE_MULTI_CONNECTIONS,
STATE_SET_STATION_IP,
STATE_DELETE_EXISTING_SERVER,
STATE_START_SERVER,
STATE_GET_SERVER_IP
}tcp_server_state_t;


//Connecting to Wi-Fi network command set
esp32_commands_t wifi_connect[] =
{
 {STATE_AT_CHECK,            "AT",                                          "SUCCESS: AT OK successful",    "ERROR: AT OK Failed"},
 {STATE_SET_STATION_IP,      "AT+CIPSTA=\"192.168.243.100\"",               "SUCCESS: station IP set",      "ERROR: station ip not set"},
 {STATE_WIFI_MODE_3,         "AT+CWMODE=3",                                 "SUCCESS: WIFI MODE SET to 3",  "ERROR: WIFI MODE NOT SET"},
 {STATE_SET_SSID_PASSWORD,   "AT+CWSAP=\"dhirajm512\",\"1234512345\",1,2",  "SUCCESS: ssid password set",   "ERROR: ssid password not set"},
 {STATE_WIFI_MODE_1,         "AT+CWMODE=1",                                 "SUCCESS: WIFI MODE SET to 1",  "ERROR: WIFI MODE NOT SET"},
 {STATE_CONNECT_TO_WIFI,     "AT+CWJAP=\"dhirajm512\",\"1234512345\"" ,     "SUCCESS: WIFI connected",      "ERROR: wifi connection failed"},
 {NULL,                      NULL,                                           NULL,                           NULL}
};




//Starting a server command set
esp32_commands_t start_server[] =
{
 {STATE_MULTI_CONNECTIONS,       "AT+CIPMUX=1",                      "SUCCESS: multiconnection set success",   "ERROR: multiconnection set failed"},
 {STATE_DELETE_EXISTING_SERVER,  "AT+CIPSERVER=0",                   "SUCCESS: existing server deleted",       "ERROR: existing server not deleted"},
 {STATE_START_SERVER,            "AT+CIPSERVER=1,80",                "SUCCESS: started server",                "ERROR: server start failed"},
 {STATE_GET_SERVER_IP,           "AT+CIFSR",                         "SUCCESS: retrieved server IP",           "ERROR: server IP not retrieved"},
 {NULL,                          NULL,                               NULL,                                     NULL}
};


/*---Variables---*/

char endline = 0x0D;
#define SEND_ENDLINE send_to_esp32(&endline)

bool is_wifi_connected = false;
bool is_server_started = false;

/** ------------------------------------------------------------------------------
 *  @brief     This function executes commands from esp32_commands

 * @param buf :  none
 *
 * @return none
 ---------------------------------------------------------------------------------**/
void esp_32_command(esp32_commands_t* command_set)
{
    char readline[100] = "";
    char c = 0x0D;  //<CR>
    char a = 0x0A;  //<LF>
    command_set->current_state = 0;

    while(1)
    {
        send_to_esp32(command_set[command_set->current_state].command); //sending command from a command table
        send_to_esp32(&c);
        send_to_esp32(&a);

        while(1)
        {
            memset(readline,0,sizeof(readline));

            get_esp32_response(readline);
            delay(50000);
            putstr(readline);
            putstr("\r\n");

            if(strstr(readline,"OK") != NULL)
                {   putstr(command_set[command_set->current_state].ok_response_msg_str);putstr("\r\n");
                    command_set->current_state++;
                    break;
                }
            else if(strstr(readline,"ERROR") != NULL)
                {
                    putstr(command_set[command_set->current_state].error_response_msg_str);putstr("\r\n");
                    break;
                }
            else if(strstr(readline,"CONNECT") != NULL) //displays over LCD that client is connected
            {
                lcd_print_str("Client", "Connected");
            }
        }

        if(command_set[command_set->current_state].command == NULL)
           break;

        delay(50000);
    }
}

