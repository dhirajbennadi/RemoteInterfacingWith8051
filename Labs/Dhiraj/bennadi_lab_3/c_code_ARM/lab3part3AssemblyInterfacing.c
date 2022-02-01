/*************************************************
 * @filename : main.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Composer Studio
 *
 * Identification of any leveraged code : None
 * Applicable Links: None
 */

#include "msp.h"

extern int globalVariable = 1;
extern int return_one(int param1, int param2, int param3);

extern int foo(int param1);



int main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	int a, b;

	a = return_one(10,5,19);

	b = foo(1);

	while(1)
	{
	    ;
	}
}
