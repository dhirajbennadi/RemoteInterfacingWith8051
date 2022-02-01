
/*************************************************
 * @filename : supportFunctions.c
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */


/* -------------------------------------------------- */
//          INCLUDES & DEFINES
/* -------------------------------------------------- */
// For a good explanation on what to include in your .c vs .h files, see here:
// https://stackoverflow.com/questions/1804486/should-i-use-include-in-headers
#include <at89c51ed2.h>       //also includes 8052.h and 8051.h
#include <mcs51reg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


/* -------------------------------------------------- */
//          GLOBALS
/* -------------------------------------------------- */
// Note: A global variable like this is accessible anywhere in this file
//       What does volatile mean to the compiler?
volatile int8_t gg = 0;


/* -------------------------------------------------- */
//          FUNCTION DEFINITIONS
/* -------------------------------------------------- */
// Note: Generally functions should be declared and defined in files outside of main
//       e.g. in strfuncs.c and strfuncs.h . Here they are included in a single file
//       to make compilation of this example easier

_sdcc_external_startup()
{
    // Note: Here is where you would put code to enable your internal RAM
    //       This code runs early in uC initialization and should be kept
    //       as small as possible. See section 4.1.4 of SDCC 3.9.0 Manual
    return 0;
}

// Note: In a function file, each function should have a small explanation of its args and returns

// putchar takes a char and TX's it. Blocking. No return value.
int putchar (int c)
{
    // Note: Compare the asm generated for the next three lines
    //       They all accomplish the same thing, but is the asm the same?
    while (!TI);
    while (TI == 0);
    while ((SCON & 0x02) == 0);

    SBUF = c;           // load serial port with transmit value
    TI = 0;             // clear TI flag

    return c;
}

// getchar gets a char from RX. Blocking. Returns char.
int getchar (void)
{
    // Note: Compare the asm generated for the next three lines
    //       They all accomplish the same thing, but is the asm the same?
    while (!RI);
    while ((SCON & 0x01) == 0);
    while (RI == 0);

    RI = 0;                         // clear RI flag
    return SBUF;                    // return character from SBUF
}

// putstr takes a string (char array) and prints till it finds a NULL.
// Returns length of printed string with null char
int putstr (char *s)
{
    int i = 0;
    while (*s){            // output characters until NULL found
        putchar(*s++);
        i++;
    }
    return i+1;
}

int getstr(char *a)
{

    int i = 0;
    do{
        *a = getchar();
        putchar(*a);
        i++;
    }while(*a++ != '\r');

    *a = '\0';
    return i+1;
}
