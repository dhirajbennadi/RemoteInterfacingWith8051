;Assembly Program for the equation Z = (X * 8) / Y without using
;MUL and DIV instructions
;Start of Program
ORG 0000H
MOV A,#10H
MOV B,#0AH
MOV R0,A
MOV R1,B
MOV A,B
;Jump to Error 1 if the divisor is zero
JZ ERROR1
MOV A,R0
MOV R2,#03H
;Jump to branch Multiply if the divisor is not zero
SJMP MULTIPLY

;Branch for Division (Repeated Subtraction)
DIVISION:SUBB A,B
		 JC STOP_DIVISION
		 INC R3
		 SJMP DIVISION

;Branch to stop division if the dividend is less than divisor
STOP_DIVISION:ADD A,B
              SJMP STORE

;Branch for Multiplication using left shift operation
MULTIPLY:CLR C
		 RLC A
		 DJNZ R2,MULTIPLY
		 JC ERROR2
		 MOV R4,A
		 SJMP DIVISION

;Branch for Error Code 1 if the divisor is 0
ERROR1:MOV R0,#30H
       MOV A,#01H
	   MOV @R0,A
	   SJMP ENDLOOP

;Branch for Error Code 2 if the dividend increases by 0xFF
ERROR2:MOV 23H,A
       MOV 21H,A
	   MOV A,B
	   MOV 22H,A
	   MOV 20H,R0
	   MOV R0,#30H
	   MOV A,#02H
	   MOV @R0,A
	   SJMP ENDLOOP

;Branch to store result if the operation was successful
STORE:MOV 24H,A
	  MOV 23H,R3
	  MOV 20H,R0
	  MOV 21H,R4
	  MOV A,B
	  MOV 22H,A
	  SJMP NO_ERROR

;Branch to store the result code of the successful operation
NO_ERROR:MOV A,#00H
		 MOV 30H,A
		 SJMP ENDLOOP
	  

;Infinite Loop
ENDLOOP:SJMP ENDLOOP
;End of Program
END