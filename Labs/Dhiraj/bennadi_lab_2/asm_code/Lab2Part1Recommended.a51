;Embedded System Design ECEN 5613
;Submitted by: Dhiraj Bennadi

;Program to Read the Status of the Pin and Change the rate of 
;LED blinking

;Start of Program
ORG 0000H
LJMP main

;Timer 0 ISR Routine IVT Address
ORG 000BH
LJMP Timer0Isr

;Initialization of Timer Registers
ORG 0030H
main: MOV TMOD,#01H         ;Timer 0 Mode 1 16 bit Timer
	  MOV IE,#82H           ;Enable Interrupt Bit , Enable Timer 0 Overflow Bit
	  CALL ReadPinVal       ;Jump to brnach ReadPinVal to read the status of P1.3
	  MOV TL0,#00H          ;Load Timer 0 Lower Byte Register with 0H
	  MOV TH0,#00H          ;Load Timer 0 Higher Byte Register with 0H
	  SETB TR0              ;Start Timer 0 bit
	  
;Infinite Loop
HERE:CALL ReadPinVal        ;Jump to brnach ReadPinVal to read the status of P1.3
     SJMP HERE


;Timer 0 ISR Routine
Timer0Isr:SETB P1.2                 ;Set P1.2 to measure the ISR Timing
          DJNZ R0,DELAY_COUNTER     ;Loop the counter as specified by the P1.3 status
	      CPL P1.1                  ;Toggle P1.1
		  CALL ReadPinVal           ;Jump to brnach ReadPinVal to read the status of P1.3
	      MOV TL0,#00H              ;Load Timer 0 Lower Byte Register with 0H
	      MOV TH0,#00H              ;Load Timer 0 Higher Byte Register with 0H
	      CLR P1.2                  ;Clear P1.2 to measure the ISR Timing
DELAY_COUNTER:RETI                  ;Return from ISR

;Branch to poll the Pin continuously
ReadPinVal:JB P1.3,BlinkRate        ;Jump to branch BlinkRate to change the delay value
           MOV R0,#03H              ;Load value for a delay of 0.5Hz
		   SJMP NEXT                ;Jump to Branch Next

;Determine the Blinkrate based on the Pin Reading
BlinkRate: MOV R0,#06H              ;Load value for a delay of 1.16Hz
NEXT:RET                            ;Return from Loop
;End of Program
END


