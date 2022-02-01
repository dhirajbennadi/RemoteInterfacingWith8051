;*************************************************
;* @filename : lab3assembly.asm
;* @author   : Dhiraj Bennadi
;* @compiler : arm
;* @IDE      : Code Composer Studio
;*
;* Identification of any leveraged code : None
;* Applicable Links: None
;*/

	.global return_one
	.global foo

foo:
	mov r1,r0
	add r1,#10
	mov r0,r1
	b ret_foo
ret_foo:
	mov pc,lr

return_one:
	push {r3-r6 , lr}
	mov r3,r0
	mov r4,r1
	mov r5,r2
	mov r6,#0
	b division

division:
	subs r5,r5,r4
	bmi stop_division
	add r6,#1
	b division

stop_division:
   add r5,r4
   mul r5,r0
   b ret1


ret1:
	mov r0,r5
	b ret

ret:
	pop {r3-r6,pc}
