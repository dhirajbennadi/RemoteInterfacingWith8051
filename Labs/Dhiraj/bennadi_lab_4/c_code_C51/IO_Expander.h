/*************************************************
 * @filename : IO_Expander.h
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */

/*IO Expander Pin configuration*/
#define P0_IOEXP 0b00000001
#define P1_IOEXP 0b00000010
#define P2_IOEXP 0b00000100
#define P3_IOEXP 0b00001000
#define P4_IOEXP 0b00010000
#define P5_IOEXP 0b00100000
#define P6_IOEXP 0b01000000
#define P7_IOEXP 0b10000000

#define IO_EXP_DEVICE_ADDR 0x70

void IO_Exp_Write(unsigned char a);
unsigned char IO_Exp_Read();