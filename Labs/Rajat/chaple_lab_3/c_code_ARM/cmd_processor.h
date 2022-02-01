/*******************************************************************************************
 * @file cmd_processor.h :
 * @brief : This file contains includes, defines and function prototypes for cmd_processor.c
 *
 * @author : Rajat Chaple (rajat.chaple@colorado.edu)
 * @date : Oct 22, 2021
 ********************************************************************************************/

#ifndef CMD_PROCESSOR_H_
#define CMD_PROCESSOR_H_

/** ------------------------------------------------------------------------------
 * @brief This function processes command char contained in input char c
 *        It performs lexical analysis to segregate command and arguments.
 *        This then invokes respective handlers for those commands.
 *
 * @param pointer to a character array
 *
 * @return None
 ---------------------------------------------------------------------------------**/
void process_char_command(char c);


#endif /* CMD_PROCESSOR_H_ */
