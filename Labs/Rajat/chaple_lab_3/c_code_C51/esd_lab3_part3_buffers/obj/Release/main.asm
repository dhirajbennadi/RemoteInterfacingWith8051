;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.9.0 #11195 (MINGW64)
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-large
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl __sdcc_external_startup
	.globl _dataout
	.globl _free
	.globl _malloc
	.globl _memset
	.globl _getchar
	.globl _printf
	.globl _accept_number_from_user
	.globl _command
	.globl _putstr
	.globl _echo
	.globl _uart_init
	.globl _P5_7
	.globl _P5_6
	.globl _P5_5
	.globl _P5_4
	.globl _P5_3
	.globl _P5_2
	.globl _P5_1
	.globl _P5_0
	.globl _P4_7
	.globl _P4_6
	.globl _P4_5
	.globl _P4_4
	.globl _P4_3
	.globl _P4_2
	.globl _P4_1
	.globl _P4_0
	.globl _PX0L
	.globl _PT0L
	.globl _PX1L
	.globl _PT1L
	.globl _PSL
	.globl _PT2L
	.globl _PPCL
	.globl _EC
	.globl _CCF0
	.globl _CCF1
	.globl _CCF2
	.globl _CCF3
	.globl _CCF4
	.globl _CR
	.globl _CF
	.globl _TF2
	.globl _EXF2
	.globl _RCLK
	.globl _TCLK
	.globl _EXEN2
	.globl _TR2
	.globl _C_T2
	.globl _CP_RL2
	.globl _T2CON_7
	.globl _T2CON_6
	.globl _T2CON_5
	.globl _T2CON_4
	.globl _T2CON_3
	.globl _T2CON_2
	.globl _T2CON_1
	.globl _T2CON_0
	.globl _PT2
	.globl _ET2
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _EECON
	.globl _KBF
	.globl _KBE
	.globl _KBLS
	.globl _BRL
	.globl _BDRCON
	.globl _T2MOD
	.globl _SPDAT
	.globl _SPSTA
	.globl _SPCON
	.globl _SADEN
	.globl _SADDR
	.globl _WDTPRG
	.globl _WDTRST
	.globl _P5
	.globl _P4
	.globl _IPH1
	.globl _IPL1
	.globl _IPH0
	.globl _IPL0
	.globl _IEN1
	.globl _IEN0
	.globl _CMOD
	.globl _CL
	.globl _CH
	.globl _CCON
	.globl _CCAPM4
	.globl _CCAPM3
	.globl _CCAPM2
	.globl _CCAPM1
	.globl _CCAPM0
	.globl _CCAP4L
	.globl _CCAP3L
	.globl _CCAP2L
	.globl _CCAP1L
	.globl _CCAP0L
	.globl _CCAP4H
	.globl _CCAP3H
	.globl _CCAP2H
	.globl _CCAP1H
	.globl _CCAP0H
	.globl _CKCON1
	.globl _CKCON0
	.globl _CKRL
	.globl _AUXR1
	.globl _AUXR
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2CON
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _main
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
_T2CON	=	0x00c8
_RCAP2L	=	0x00ca
_RCAP2H	=	0x00cb
_TL2	=	0x00cc
_TH2	=	0x00cd
_AUXR	=	0x008e
_AUXR1	=	0x00a2
_CKRL	=	0x0097
_CKCON0	=	0x008f
_CKCON1	=	0x00af
_CCAP0H	=	0x00fa
_CCAP1H	=	0x00fb
_CCAP2H	=	0x00fc
_CCAP3H	=	0x00fd
_CCAP4H	=	0x00fe
_CCAP0L	=	0x00ea
_CCAP1L	=	0x00eb
_CCAP2L	=	0x00ec
_CCAP3L	=	0x00ed
_CCAP4L	=	0x00ee
_CCAPM0	=	0x00da
_CCAPM1	=	0x00db
_CCAPM2	=	0x00dc
_CCAPM3	=	0x00dd
_CCAPM4	=	0x00de
_CCON	=	0x00d8
_CH	=	0x00f9
_CL	=	0x00e9
_CMOD	=	0x00d9
_IEN0	=	0x00a8
_IEN1	=	0x00b1
_IPL0	=	0x00b8
_IPH0	=	0x00b7
_IPL1	=	0x00b2
_IPH1	=	0x00b3
_P4	=	0x00c0
_P5	=	0x00e8
_WDTRST	=	0x00a6
_WDTPRG	=	0x00a7
_SADDR	=	0x00a9
_SADEN	=	0x00b9
_SPCON	=	0x00c3
_SPSTA	=	0x00c4
_SPDAT	=	0x00c5
_T2MOD	=	0x00c9
_BDRCON	=	0x009b
_BRL	=	0x009a
_KBLS	=	0x009c
_KBE	=	0x009d
_KBF	=	0x009e
_EECON	=	0x00d2
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
_ET2	=	0x00ad
_PT2	=	0x00bd
_T2CON_0	=	0x00c8
_T2CON_1	=	0x00c9
_T2CON_2	=	0x00ca
_T2CON_3	=	0x00cb
_T2CON_4	=	0x00cc
_T2CON_5	=	0x00cd
_T2CON_6	=	0x00ce
_T2CON_7	=	0x00cf
_CP_RL2	=	0x00c8
_C_T2	=	0x00c9
_TR2	=	0x00ca
_EXEN2	=	0x00cb
_TCLK	=	0x00cc
_RCLK	=	0x00cd
_EXF2	=	0x00ce
_TF2	=	0x00cf
_CF	=	0x00df
_CR	=	0x00de
_CCF4	=	0x00dc
_CCF3	=	0x00db
_CCF2	=	0x00da
_CCF1	=	0x00d9
_CCF0	=	0x00d8
_EC	=	0x00ae
_PPCL	=	0x00be
_PT2L	=	0x00bd
_PSL	=	0x00bc
_PT1L	=	0x00bb
_PX1L	=	0x00ba
_PT0L	=	0x00b9
_PX0L	=	0x00b8
_P4_0	=	0x00c0
_P4_1	=	0x00c1
_P4_2	=	0x00c2
_P4_3	=	0x00c3
_P4_4	=	0x00c4
_P4_5	=	0x00c5
_P4_6	=	0x00c6
_P4_7	=	0x00c7
_P5_0	=	0x00e8
_P5_1	=	0x00e9
_P5_2	=	0x00ea
_P5_3	=	0x00eb
_P5_4	=	0x00ec
_P5_5	=	0x00ed
_P5_6	=	0x00ee
_P5_7	=	0x00ef
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
_main_i_65536_77:
	.ds 2
_main_total_characters_received_since_last_query_65536_77:
	.ds 4
_main_buffers_65536_77:
	.ds 1890
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function '_sdcc_external_startup'
;------------------------------------------------------------
;	main.c:33: _sdcc_external_startup()
;	-----------------------------------------
;	 function _sdcc_external_startup
;	-----------------------------------------
__sdcc_external_startup:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	main.c:35: AUXR |= 0x0C; // 0000 1100
	orl	_AUXR,#0x0c
;	main.c:37: return 0;
	mov	dptr,#0x0000
;	main.c:38: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;received_char             Allocated with name '_main_received_char_65536_77'
;i                         Allocated with name '_main_i_65536_77'
;cmd                       Allocated with name '_main_cmd_65536_77'
;command_processed_status  Allocated with name '_main_command_processed_status_65536_77'
;total_characters_received Allocated with name '_main_total_characters_received_65536_77'
;total_characters_received_since_last_query Allocated with name '_main_total_characters_received_since_last_query_65536_77'
;buffers                   Allocated with name '_main_buffers_65536_77'
;------------------------------------------------------------
;	main.c:43: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	main.c:46: volatile int i = 0;
	mov	dptr,#_main_i_65536_77
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	main.c:50: long total_characters_received_since_last_query = 0;
	mov	dptr,#_main_total_characters_received_since_last_query_65536_77
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	main.c:59: uart_init();
	lcall	_uart_init
;	main.c:61: memset(buffers, 0, sizeof(buffers));
	mov	dptr,#_memset_PARM_2
	clr	a
	movx	@dptr,a
	mov	dptr,#_memset_PARM_3
	mov	a,#0x62
	movx	@dptr,a
	mov	a,#0x07
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_main_buffers_65536_77
	mov	b,#0x00
	lcall	_memset
;	main.c:63: putstr("Specify buffer size (48 bytes to 4800 bytes in multiples of 16): ");
	mov	dptr,#___str_0
	mov	b,#0x80
	lcall	_putstr
;	main.c:64: buffers[0].buf_size = accept_number_from_user();
	lcall	_accept_number_from_user
	mov	r6,dpl
	mov	r7,dph
	mov	dptr,#(_main_buffers_65536_77 + 0x0007)
	mov	a,r6
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	main.c:65: buffers[1].buf_size = buffers[0].buf_size;
	mov	dptr,#(_main_buffers_65536_77 + 0x0010)
	mov	a,r6
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	main.c:67: while ((buffers[0].buf_size % 16 != 0) || (buffers[0].buf_size < 48) || (buffers[0].buf_size > 4800))
00103$:
	mov	dptr,#(_main_buffers_65536_77 + 0x0007)
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dptr,#__modsint_PARM_2
	mov	a,#0x10
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r6
	mov	dph,r7
	lcall	__modsint
	mov	a,dpl
	mov	b,dph
	orl	a,b
	jnz	00104$
	mov	dptr,#(_main_buffers_65536_77 + 0x0007)
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	clr	c
	mov	a,r6
	subb	a,#0x30
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jc	00104$
	mov	dptr,#(_main_buffers_65536_77 + 0x0007)
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	clr	c
	mov	a,#0xc0
	subb	a,r6
	mov	a,#(0x12 ^ 0x80)
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jnc	00105$
00104$:
;	main.c:69: putstr("============================================================================\r\n");
	mov	dptr,#___str_1
	mov	b,#0x80
	lcall	_putstr
;	main.c:70: putstr("Invalid size entered\r\n");
	mov	dptr,#___str_2
	mov	b,#0x80
	lcall	_putstr
;	main.c:71: putstr("Specify buffer size (48 bytes to 4800 bytes in multiples of 16): ");
	mov	dptr,#___str_0
	mov	b,#0x80
	lcall	_putstr
;	main.c:72: buffers[0].buf_size = accept_number_from_user();
	lcall	_accept_number_from_user
	mov	r6,dpl
	mov	r7,dph
	mov	dptr,#(_main_buffers_65536_77 + 0x0007)
	mov	a,r6
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	main.c:73: buffers[1].buf_size = buffers[0].buf_size;
	mov	dptr,#(_main_buffers_65536_77 + 0x0010)
	mov	a,r6
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
	ljmp	00103$
00105$:
;	main.c:77: buffers[0].buffer_pointer = (uint8_t *)malloc(buffers[0].buf_size);
	mov	dptr,#(_main_buffers_65536_77 + 0x0007)
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dpl,r6
	mov	dph,r7
	lcall	_malloc
	mov	r6,dpl
	mov	r7,dph
	mov	r5,#0x00
	mov	dptr,#_main_buffers_65536_77
	mov	a,r6
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
	mov	a,r5
	inc	dptr
	movx	@dptr,a
;	main.c:78: if (buffers[0].buffer_pointer != NULL)
	mov	a,r6
	orl	a,r7
	jz	00107$
;	main.c:80: putstr("Success: malloc for buffer0 successful\r\n");
	mov	dptr,#___str_3
	mov	b,#0x80
	lcall	_putstr
;	main.c:81: buffers[0].buf_id = 0;
	mov	dptr,#(_main_buffers_65536_77 + 0x0005)
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	sjmp	00108$
00107$:
;	main.c:85: putstr("Error: malloc for buffer0 failed\r\n");
	mov	dptr,#___str_4
	mov	b,#0x80
;	main.c:87: return;
	ljmp	_putstr
00108$:
;	main.c:91: buffers[1].buffer_pointer = (uint8_t *)malloc(buffers[1].buf_size);
	mov	dptr,#(_main_buffers_65536_77 + 0x0010)
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dpl,r6
	mov	dph,r7
	lcall	_malloc
	mov	r6,dpl
	mov	r7,dph
	mov	r5,#0x00
	mov	dptr,#(_main_buffers_65536_77 + 0x0009)
	mov	a,r6
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
	mov	a,r5
	inc	dptr
	movx	@dptr,a
;	main.c:92: if (buffers[1].buffer_pointer != NULL)
	mov	a,r6
	orl	a,r7
	jz	00110$
;	main.c:94: putstr("Success: malloc for buffer1 successful\r\n");
	mov	dptr,#___str_5
	mov	b,#0x80
	lcall	_putstr
;	main.c:95: buffers[1].buf_id = 1;
	mov	dptr,#(_main_buffers_65536_77 + 0x000e)
	mov	a,#0x01
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	sjmp	00111$
00110$:
;	main.c:99: putstr("Error: malloc for buffer1 failed, clearing buffers\r\n");
	mov	dptr,#___str_6
	mov	b,#0x80
	lcall	_putstr
;	main.c:100: free(buffers[0].buffer_pointer);
	mov	dptr,#_main_buffers_65536_77
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
;	main.c:102: return;
	ljmp	_free
00111$:
;	main.c:105: putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
	mov	dptr,#___str_7
	mov	b,#0x80
	lcall	_putstr
;	main.c:106: putstr("Enter command (+, -, ?, =, @) or input: ");
	mov	dptr,#___str_8
	mov	b,#0x80
	lcall	_putstr
;	main.c:108: while (1)
	mov	r4,#0x00
	mov	r5,#0x00
	mov	r6,#0x00
	mov	r7,#0x00
00123$:
;	main.c:111: received_char = getchar();
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_getchar
	mov	r2,dpl
;	main.c:112: DEBUGPORT(received_char);
	mov	dptr,#_dataout_PARM_2
	mov	a,r2
	movx	@dptr,a
	mov	dptr,#0xffff
	mov	b,#0x00
	push	ar2
	lcall	_dataout
	pop	ar2
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	main.c:115: if (((received_char >= 'a') && (received_char <= 'z')))
	cjne	r2,#0x61,00180$
00180$:
	clr	a
	rlc	a
	mov	r3,a
	jnz	00115$
	mov	a,r2
	add	a,#0xff - 0x7a
	jc	00115$
;	main.c:117: if(buffers[0].buf_index % 40 == 0)
	mov	dptr,#(_main_buffers_65536_77 + 0x0003)
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	r1,a
	mov	dptr,#__modsint_PARM_2
	mov	a,#0x28
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r0
	mov	dph,r1
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	lcall	__modsint
	mov	a,dpl
	mov	b,dph
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	orl	a,b
	jnz	00115$
;	main.c:118: putstr("\r\n\t\t");
	mov	dptr,#___str_9
	mov	b,#0x80
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	lcall	_putstr
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
00115$:
;	main.c:121: echo(received_char); // echoing characters back
	mov	dpl,r2
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	lcall	_echo
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	main.c:122: total_characters_received++;
	inc	r4
	cjne	r4,#0x00,00184$
	inc	r5
	cjne	r5,#0x00,00184$
	inc	r6
	cjne	r6,#0x00,00184$
	inc	r7
00184$:
;	main.c:123: total_characters_received_since_last_query++;
	mov	dptr,#_main_total_characters_received_since_last_query_65536_77
	movx	a,@dptr
	add	a,#0x01
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0x00
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0x00
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0x00
	movx	@dptr,a
;	main.c:125: if ((received_char >= 'a') && (received_char <= 'z'))
	mov	a,r3
	jnz	00118$
	mov	a,r2
	add	a,#0xff - 0x7a
	jc	00118$
;	main.c:126: buffers[0].buffer_pointer[buffers[0].buf_index++] = received_char;
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#_main_buffers_65536_77
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	r1,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dptr,#(_main_buffers_65536_77 + 0x0003)
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	a,#0x01
	add	a,r6
	mov	r4,a
	clr	a
	addc	a,r7
	mov	r5,a
	mov	dptr,#(_main_buffers_65536_77 + 0x0003)
	mov	a,r4
	movx	@dptr,a
	mov	a,r5
	inc	dptr
	movx	@dptr,a
	mov	a,r6
	add	a,r0
	mov	r0,a
	mov	a,r7
	addc	a,r1
	mov	r1,a
	mov	dpl,r0
	mov	dph,r1
	mov	b,r3
	mov	a,r2
	lcall	__gptrput
;	main.c:135: command(received_char, buffers);
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar4
;	main.c:126: buffers[0].buffer_pointer[buffers[0].buf_index++] = received_char;
00118$:
;	main.c:128: if (received_char == '?')
	cjne	r2,#0x3f,00121$
;	main.c:130: printf("\r\n\tTotal Characters received: %ld\r\n", total_characters_received);
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar2
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	a,#___str_10
	push	acc
	mov	a,#(___str_10 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
;	main.c:131: printf("\tTotal Characters received since last query: %ld\r\n", total_characters_received_since_last_query);
	mov	dptr,#_main_total_characters_received_since_last_query_65536_77
	movx	a,@dptr
	push	acc
	inc	dptr
	movx	a,@dptr
	push	acc
	inc	dptr
	movx	a,@dptr
	push	acc
	inc	dptr
	movx	a,@dptr
	push	acc
	mov	a,#___str_11
	push	acc
	mov	a,#(___str_11 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf9
	mov	sp,a
	pop	ar2
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	main.c:132: total_characters_received_since_last_query = 0;
	mov	dptr,#_main_total_characters_received_since_last_query_65536_77
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
00121$:
;	main.c:135: command(received_char, buffers);
	mov	dptr,#_command_PARM_2
	mov	a,#_main_buffers_65536_77
	movx	@dptr,a
	mov	a,#(_main_buffers_65536_77 >> 8)
	inc	dptr
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_command
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	main.c:137: }
	ljmp	00123$
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area CONST   (CODE)
___str_0:
	.ascii "Specify buffer size (48 bytes to 4800 bytes in multiples of "
	.ascii "16): "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_1:
	.ascii "============================================================"
	.ascii "================"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_2:
	.ascii "Invalid size entered"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_3:
	.ascii "Success: malloc for buffer0 successful"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_4:
	.ascii "Error: malloc for buffer0 failed"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_5:
	.ascii "Success: malloc for buffer1 successful"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_6:
	.ascii "Error: malloc for buffer1 failed, clearing buffers"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_7:
	.db 0x0d
	.db 0x0a
	.ascii "------------------------------------------------------------"
	.ascii "----------"
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_8:
	.ascii "Enter command (+, -, ?, =, @) or input: "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_9:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_10:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.ascii "Total Characters received: %ld"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_11:
	.db 0x09
	.ascii "Total Characters received since last query: %ld"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
