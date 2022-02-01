
/*************************************************
 * @filename : supportFunctions.h
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */

// Note: Header guards prevent multiple inclusions and should always be used
#ifndef SUPPORT_FUNCTIONS_H
#define SUPPORT_FUNCTIONS_H
/* -------------------------------------------------- */
//          INCLUDES & DEFINES
/* -------------------------------------------------- */
// For a good explanation on what to include in your .c vs .h files, see here:
// https://stackoverflow.com/questions/1804486/should-i-use-include-in-headers


/* -------------------------------------------------- */
//          EXTERN VARIABLES
/* -------------------------------------------------- */
// Extern variables are generally shared between this file and other files (globals)
// Globals are not considered best practice and should be avoided if possible

// Note: Since these variables are defined in _heap.c, you'd have to extern them
//       if you want to access them directly. Heap size might be useful to know,
//       but generally you'd want to avoid directly messing with the heap.
//       Use malloc to get heap space and use it.
extern char __sdcc_heap[];
extern const unsigned int __sdcc_heap_size;

/* -------------------------------------------------- */
//          FUNCTION DECLARATIONS
/* -------------------------------------------------- */

// putchar takes a char and TX's it. Blocking. No return value.
int putchar (int c);

// getchar gets a char from RX. Blocking. Returns char.
int getchar (void);

// putstr takes a string (char array) and prints till it finds a NULL.
// Returns length of printed string with null char
int putstr (char *s);

int getstr(char *a);

#endif // #ifndef SUPPORT_FUNCTIONS_H
