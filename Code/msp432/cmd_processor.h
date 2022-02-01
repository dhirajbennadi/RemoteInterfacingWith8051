/*******************************************************************************************
 * @file cmd_processor.h :
 * @brief : This file contains includes, defines and function prototypes for cmd_processor.c
 *
 * @date : Nov 29, 2021
 * @author: Rajat Chaple
 ********************************************************************************************/

#ifndef CMD_PROCESSOR_H_
#define CMD_PROCESSOR_H_

/** ------------------------------------------------------------------------------
 * @brief This function receives hex file over uart from esp32
 *
 * @param a character over uart
 *
 * @return None
 ---------------------------------------------------------------------------------**/
bool receive_hex_file(int c);

/** ------------------------------------------------------------------------------
 * @brief This function sends hex file to 8051 ocer UART3
 *
 * @return None
 ---------------------------------------------------------------------------------**/
void send_hex_file_to_8051(void);

#endif /* CMD_PROCESSOR_H_ */
