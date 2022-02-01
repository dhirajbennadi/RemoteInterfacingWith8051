/*************************************************
 * @filename : i2c.h
 * @author   : Dhiraj Bennadi
 * @compiler : arm
 * @IDE      : Code Blocks
 *
 * Identification of any leveraged code : Code Referenced
 * from the example given by Prof. Linden Mcclure
 * Applicable Links: None
 */

/*=========================================
   Prototypes for I2c functions
 ==========================================*/

#define FULL_CYCLE_DELAY    500

#define CTRL_WRITE_BYTE 0xA0
#define CTRL_READ_BYTE  0xA1

#define ACK_BIT    0
#define SERIAL_DATA P1_4
#define SERIAL_CLK  P1_5

void InitI2c(void);
void StartI2c(void);
void RepeatedStartI2c(void);
void StopI2c(void);
void SendAckBit(void);
void SendNackBit(void);
void delay(unsigned int);
__bit write_i2c(unsigned char);
unsigned char read_i2c(void);
void write_byte_to_eeprom(unsigned int addr,unsigned char byte, unsigned char blockValue);
unsigned char read_byte_from_eeprom(unsigned int addr, unsigned char blockValue);
void NACK();
