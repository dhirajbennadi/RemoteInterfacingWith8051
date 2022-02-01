*
* EMILY program: Logic block for interfacing external memory
* This program divides X*8 by Z
* Result is stored as below 
* Memory location	Result parameter
* 0x20				X
* 0x21				X*8
* 0x22				Y
* 0x23				Z (Quotient)
* 0x24				remainder
* 0x30				error code				
*

	ORG $0000
	;MOV A,#8	;used to feed in values 
	;MOV B,#7
	MOV R3,B	
	;Error handling for 0 denominator (Y)
	CJNE R3,#00h,DEN_NOT_ZERO
	MOV 30h,#01h
	MOV 20h,#00h
	MOV 21h,#00h
	MOV 22h,#00h
	MOV 23h,#00h
	MOV 24h,#00h
	SJMP	ENDLOOP
DEN_NOT_ZERO	MOV 20h,A	;copying value in Acc (X) to memory 0x20



	;multiplying X by 8
	MOV R2,#00h
	RLC A
	JNC LEFT_SHIFT2
	MOV R2,#01h
	
LEFT_SHIFT2	RLC A
	JNC LEFT_SHIFT3
	MOV R2,#01h
	
LEFT_SHIFT3	RLC A
	JNC SHIFTING_DONE
	MOV R2,#01h
	
SHIFTING_DONE	ANL A,#0F8h 	;masking first 3 bits #f8h
	CJNE R2,#01,NO_MULT_O_ERROR
	MOV 30h,#02h	;Error code 2 as Mult > 255
	SJMP	MULT_O_ERROR	;multiplication overflow error
NO_MULT_O_ERROR	MOV 30h,#00h
MULT_O_ERROR	MOV 21h,A	;copying value X*8 to 0x21
	MOV 22h,B	;copying value in B (Y) to 0x22
	MOV R1,#00h	;initializing quotient value
	MOV R1,#00h	;initializing quotient value
	CLR C
	
	
	;division routine
SUB_UNTIL_NONZERO	SUBB A,B
	INC R1
	JNC	SUB_UNTIL_NONZERO	
	;At this point accumulaotor is negative as carry is set and quotient is over-incremented by 1. 
	DEC R1	;Decrementing quotient which was increamened after above condition
	MOV 23h,R1	;copying Quotient to 0x23
	ADD A,B	;re-adding value which caused acc to go negative
	MOV 24h,A	;copying remainder to 0x24
ENDLOOP	SJMP	ENDLOOP