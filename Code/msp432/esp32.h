/*****************************************************************************************
 * @file esp32.h :
 * @brief : This file contains defines, includes, and function prototypes for esp32.c
 *
 * @date : Oct 22 2021
 * @author: Rajat Chaple
 ******************************************************************************************/

#ifndef ESP32_H_
#define ESP32_H_

#include <stdint.h>

typedef struct esp32_commands_s{
    int current_state;
    char* command;
    char* ok_response_msg_str;
    char* error_response_msg_str;
}esp32_commands_t;


extern esp32_commands_t wifi_connect[];
extern esp32_commands_t start_server[];

/** ------------------------------------------------------------------------------
 *  @brief    This function executes commands from esp32_commands

 * @param buf :  none
 *
 * @return none
 ---------------------------------------------------------------------------------**/
void esp_32_command(esp32_commands_t*);


#endif /* ESP32_H_ */
