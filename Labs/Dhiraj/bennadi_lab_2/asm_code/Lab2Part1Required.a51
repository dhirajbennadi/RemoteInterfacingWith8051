;Embedded System Design ECEN 5613
;Submitted by: Dhiraj Bennadi

;Program to Toggle LED at 430ms using ISR of Timer 0

;Start of Program
ORG 0000H
LJMP main

;Timer 0 ISR Routine IVT Address
ORG 000BH
LJMP ISR_T0

;main
ORG 0030H
main: MOV TMOD,#01H                ;Timer 0 Mode 1 16 bit Timer
	  MOV IE,#82H                  ;Enable Interrupt Bit , Enable Timer 0 Overflow Bit
	  MOV R0,#06H                  ;To generate a delay of 430ms , Count of (0-FFFFH + 1) * 6
	  MOV TL0,#000H                ;Load Timer 0 Lower Byte Register with 0H
	  MOV TH0,#000H                ;Load Timer 0 Higher Byte Register with 0H
	  SETB TR0                     ;Start Timer 0 bit
	  
;Infinite Loop
HERE:SJMP HERE

;Timer 0 ISR Routine
ISR_T0:SETB P1.2                   ;Set P1.2 to measure the ISR Timing
       DJNZ R0,DELAY_COUNTER       ;Loop the counter 6 times
	   CPL P1.1                    ;Toggle P1.1
	   MOV R0,#06H                 ;Reinitialize the Counter to 6 for 430ms Delay
	   MOV TL0,#00H                ;Load Timer 0 Lower Byte Register with 0H          
	   MOV TH0,#00H                ;Load Timer 0 Higher Byte Register with 0H
	   CLR P1.2                    ;Clear P1.2 to measure the ISR Timing
DELAY_COUNTER:RETI
;End of Program
END


