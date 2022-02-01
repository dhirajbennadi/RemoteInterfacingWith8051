;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.9.0 #11195 (MINGW64)
;--------------------------------------------------------
	.module uart
	.optsdcc -mmcs51 --model-large
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _printf_tiny
	.globl _printf
	.globl _memset
	.globl _strncat
	.globl _strcat
	.globl _atoi
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
	.globl _total_malloced_data
	.globl _buf_number
	.globl _uint_to_hexstr_PARM_4
	.globl _uint_to_hexstr_PARM_3
	.globl _uint_to_hexstr_PARM_2
	.globl _hexdump_PARM_2
	.globl _uart_init
	.globl _echo
	.globl _command
	.globl _putchar
	.globl _getchar
	.globl _putstr
	.globl _accept_number_from_user
	.globl _print_buffers
	.globl _hexdump
	.globl _uint_to_hexstr
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
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
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
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
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_print_buffers_sloc0_1_0:
	.ds 3
_hexdump_sloc0_1_0:
	.ds 2
_hexdump_sloc1_1_0:
	.ds 2
_uint_to_hexstr_sloc0_1_0:
	.ds 4
_uint_to_hexstr_sloc1_1_0:
	.ds 2
_uint_to_hexstr_sloc2_1_0:
	.ds 3
_uint_to_hexstr_sloc3_1_0:
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
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
_echo_c_65536_74:
	.ds 1
_command_received_char_65536_77:
	.ds 1
_putchar_c_65536_80:
	.ds 2
_putstr_str_65536_83:
	.ds 3
_accept_number_from_user_received_char_65536_86:
	.ds 1
_accept_number_from_user_number_in_char_65536_86:
	.ds 25
_accept_number_from_user_valid_number_status_65536_86:
	.ds 1
_accept_number_from_user_number_65536_86:
	.ds 2
_accept_number_from_user_i_65536_86:
	.ds 2
_print_buffers_buffers_65536_91:
	.ds 3
_hexdump_PARM_2:
	.ds 4
_hexdump_loc_65536_95:
	.ds 3
_hexdump_hex_byte_65536_96:
	.ds 5
_hexdump_address_bytes_65536_96:
	.ds 7
_uint_to_hexstr_PARM_2:
	.ds 4
_uint_to_hexstr_PARM_3:
	.ds 2
_uint_to_hexstr_PARM_4:
	.ds 1
_uint_to_hexstr_str_65536_103:
	.ds 3
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
_buf_number::
	.ds 2
_total_malloced_data::
	.ds 2
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
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'uart_init'
;------------------------------------------------------------
;	uart.c:48: void uart_init()
;	-----------------------------------------
;	 function uart_init
;	-----------------------------------------
_uart_init:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	uart.c:50: SCON = 0x50; // setting up serial configuration 8bit uart, Receive enabled
	mov	_SCON,#0x50
;	uart.c:51: TMOD = 0x20; // timer1 in mode2, auto-reload
	mov	_TMOD,#0x20
;	uart.c:56: TI = 1;
;	assignBit
	setb	_TI
;	uart.c:57: P1_1 = false;
;	assignBit
	clr	_P1_1
;	uart.c:58: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'echo'
;------------------------------------------------------------
;c                         Allocated with name '_echo_c_65536_74'
;------------------------------------------------------------
;	uart.c:64: void echo(char c)
;	-----------------------------------------
;	 function echo
;	-----------------------------------------
_echo:
	mov	a,dpl
	mov	dptr,#_echo_c_65536_74
	movx	@dptr,a
;	uart.c:68: switch ((int8_t)c)
	movx	a,@dptr
	mov	r7,a
	mov	r6,a
	cjne	r6,#0xff,00120$
	ret
00120$:
	cjne	r6,#0x08,00121$
	sjmp	00102$
00121$:
;	uart.c:73: case BACKSPACE: // user presses backspace
	cjne	r6,#0x0d,00104$
	sjmp	00103$
00102$:
;	uart.c:74: putchar(BACKSPACE);
	mov	dptr,#0x0008
	lcall	_putchar
;	uart.c:75: putchar(' ');
	mov	dptr,#0x0020
	lcall	_putchar
;	uart.c:76: putchar(BACKSPACE);
	mov	dptr,#0x0008
;	uart.c:77: break;
;	uart.c:79: case '\r': // user presses enter
	ljmp	_putchar
00103$:
;	uart.c:80: putchar('\r');
	mov	dptr,#0x000d
	lcall	_putchar
;	uart.c:81: putchar('\n');
	mov	dptr,#0x000a
;	uart.c:82: break;
;	uart.c:84: default:
	ljmp	_putchar
00104$:
;	uart.c:85: putchar(c); // echoing received chars
	mov	r6,#0x00
	mov	dpl,r7
	mov	dph,r6
;	uart.c:87: }
;	uart.c:88: }
	ljmp	_putchar
;------------------------------------------------------------
;Allocation info for local variables in function 'command'
;------------------------------------------------------------
;received_char             Allocated with name '_command_received_char_65536_77'
;------------------------------------------------------------
;	uart.c:94: void command(char received_char)
;	-----------------------------------------
;	 function command
;	-----------------------------------------
_command:
	mov	a,dpl
	mov	dptr,#_command_received_char_65536_77
	movx	@dptr,a
;	uart.c:97: switch (received_char)
	movx	a,@dptr
	mov	r7,a
	cjne	r7,#0x31,00135$
	sjmp	00101$
00135$:
	cjne	r7,#0x32,00136$
	sjmp	00102$
00136$:
	cjne	r7,#0x33,00137$
	sjmp	00103$
00137$:
	cjne	r7,#0x34,00138$
	sjmp	00104$
00138$:
	cjne	r7,#0x35,00139$
	sjmp	00105$
00139$:
;	uart.c:101: case '1':
	cjne	r7,#0x36,00107$
	sjmp	00106$
00101$:
;	uart.c:102: putstr("\r\n\t\t ** Turning PWM on ** \r\n");
	mov	dptr,#___str_0
	mov	b,#0x80
	lcall	_putstr
;	uart.c:103: CR = 1;
;	assignBit
	setb	_CR
;	uart.c:104: break;
;	uart.c:106: case '2':
	sjmp	00108$
00102$:
;	uart.c:107: putstr("\r\n\t\t ** Turning PWM off ** \r\n");
	mov	dptr,#___str_1
	mov	b,#0x80
	lcall	_putstr
;	uart.c:108: CR = 0;
;	assignBit
	clr	_CR
;	uart.c:109: uart_init();
	lcall	_uart_init
;	uart.c:110: break;
;	uart.c:112: case '3':
	sjmp	00108$
00103$:
;	uart.c:113: putstr("\r\n\t\t ** Setting up minimum frequency ** \r\n");
	mov	dptr,#___str_2
	mov	b,#0x80
	lcall	_putstr
;	uart.c:114: CKRL = 0;   //0 for minimum frequency
	mov	_CKRL,#0x00
;	uart.c:115: break;
;	uart.c:117: case '4':
	sjmp	00108$
00104$:
;	uart.c:118: putstr("\r\n\t\t ** Setting up maximum frequency ** \r\n");
	mov	dptr,#___str_3
	mov	b,#0x80
	lcall	_putstr
;	uart.c:119: CKRL = 0xFF;   //0xFF for maximum frequency
	mov	_CKRL,#0xff
;	uart.c:120: break;
;	uart.c:122: case '5':
	sjmp	00108$
00105$:
;	uart.c:123: putstr("\r\n\t\t ** Entering IDLE mode ** \r\n");
	mov	dptr,#___str_4
	mov	b,#0x80
	lcall	_putstr
;	uart.c:124: PCON |= 0x01;   //Setting up IDLE bit in PCON
	orl	_PCON,#0x01
;	uart.c:125: break;
;	uart.c:127: case '6':
	sjmp	00108$
00106$:
;	uart.c:128: putstr("\r\n\t\t ** Entering Power-down mode ** \r\n");
	mov	dptr,#___str_5
	mov	b,#0x80
	lcall	_putstr
;	uart.c:129: PCON |= 0x02;   //setting up PDL bit in PCON
	orl	_PCON,#0x02
;	uart.c:130: break;
;	uart.c:133: default:
	sjmp	00108$
00107$:
;	uart.c:134: printf("\r\n\r\n\t Error: Received invalid command '%c'\r\n", received_char);
	mov	r6,#0x00
	push	ar7
	push	ar6
	mov	a,#___str_6
	push	acc
	mov	a,#(___str_6 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
;	uart.c:138: }
00108$:
;	uart.c:140: putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
	mov	dptr,#___str_7
	mov	b,#0x80
	lcall	_putstr
;	uart.c:141: putstr("Enter command: ");
	mov	dptr,#___str_8
	mov	b,#0x80
;	uart.c:143: }
	ljmp	_putstr
;------------------------------------------------------------
;Allocation info for local variables in function 'putchar'
;------------------------------------------------------------
;c                         Allocated with name '_putchar_c_65536_80'
;------------------------------------------------------------
;	uart.c:148: int putchar(int c)
;	-----------------------------------------
;	 function putchar
;	-----------------------------------------
_putchar:
	mov	r7,dph
	mov	a,dpl
	mov	dptr,#_putchar_c_65536_80
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:150: while (!TI)
00101$:
;	uart.c:152: TI = 0;
;	assignBit
	jbc	_TI,00114$
	sjmp	00101$
00114$:
;	uart.c:153: SBUF = c; // adding character to Serial buffer
	mov	dptr,#_putchar_c_65536_80
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	_SBUF,r6
;	uart.c:154: return c;
	mov	dpl,r6
	mov	dph,r7
;	uart.c:155: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'getchar'
;------------------------------------------------------------
;	uart.c:164: int getchar() // Function to receive serial data
;	-----------------------------------------
;	 function getchar
;	-----------------------------------------
_getchar:
;	uart.c:166: P1_1 = false;
;	assignBit
	clr	_P1_1
;	uart.c:167: while (!RI)
00101$:
;	uart.c:170: RI = 0;
;	assignBit
	jbc	_RI,00114$
	sjmp	00101$
00114$:
;	uart.c:172: P1_1 = true;
;	assignBit
	setb	_P1_1
;	uart.c:173: return SBUF;
	mov	r6,_SBUF
	mov	r7,#0x00
	mov	dpl,r6
	mov	dph,r7
;	uart.c:174: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'putstr'
;------------------------------------------------------------
;str                       Allocated with name '_putstr_str_65536_83'
;index                     Allocated with name '_putstr_index_65536_84'
;------------------------------------------------------------
;	uart.c:180: int putstr(char *str)
;	-----------------------------------------
;	 function putstr
;	-----------------------------------------
_putstr:
	mov	r7,b
	mov	r6,dph
	mov	a,dpl
	mov	dptr,#_putstr_str_65536_83
	movx	@dptr,a
	mov	a,r6
	inc	dptr
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:183: while (*str)
	mov	dptr,#_putstr_str_65536_83
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	r3,#0x00
	mov	r4,#0x00
00101$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	jz	00108$
;	uart.c:185: putchar(*str++);
	inc	r5
	cjne	r5,#0x00,00116$
	inc	r6
00116$:
	mov	dptr,#_putstr_str_65536_83
	mov	a,r5
	movx	@dptr,a
	mov	a,r6
	inc	dptr
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
	mov	ar1,r2
	mov	r2,#0x00
	mov	dpl,r1
	mov	dph,r2
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	lcall	_putchar
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	uart.c:186: index++;
	inc	r3
	cjne	r3,#0x00,00101$
	inc	r4
	sjmp	00101$
00108$:
	mov	dptr,#_putstr_str_65536_83
	mov	a,r5
	movx	@dptr,a
	mov	a,r6
	inc	dptr
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:188: return index + 1;
	inc	r3
	cjne	r3,#0x00,00118$
	inc	r4
00118$:
	mov	dpl,r3
	mov	dph,r4
;	uart.c:189: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'accept_number_from_user'
;------------------------------------------------------------
;received_char             Allocated with name '_accept_number_from_user_received_char_65536_86'
;number_in_char            Allocated with name '_accept_number_from_user_number_in_char_65536_86'
;valid_number_status       Allocated with name '_accept_number_from_user_valid_number_status_65536_86'
;number                    Allocated with name '_accept_number_from_user_number_65536_86'
;i                         Allocated with name '_accept_number_from_user_i_65536_86'
;------------------------------------------------------------
;	uart.c:195: int accept_number_from_user()
;	-----------------------------------------
;	 function accept_number_from_user
;	-----------------------------------------
_accept_number_from_user:
;	uart.c:197: char received_char = '`';
	mov	dptr,#_accept_number_from_user_received_char_65536_86
	mov	a,#0x60
	movx	@dptr,a
;	uart.c:198: char number_in_char[25] = "\0";
	mov	dptr,#_accept_number_from_user_number_in_char_65536_86
	clr	a
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0001)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0002)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0003)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0004)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0005)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0006)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0007)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0008)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0009)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x000a)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x000b)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x000c)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x000d)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x000e)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x000f)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0010)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0011)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0012)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0013)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0014)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0015)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0016)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0017)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0018)
	movx	@dptr,a
;	uart.c:199: bool valid_number_status = false;
	mov	dptr,#_accept_number_from_user_valid_number_status_65536_86
	movx	@dptr,a
;	uart.c:200: int number = 0;
	mov	dptr,#_accept_number_from_user_number_65536_86
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	uart.c:201: int i = 0;
	mov	dptr,#_accept_number_from_user_i_65536_86
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	uart.c:202: while (valid_number_status == false)
00110$:
	mov	dptr,#_accept_number_from_user_valid_number_status_65536_86
	movx	a,@dptr
	jz	00139$
	ljmp	00112$
00139$:
;	uart.c:204: received_char = getchar();
	lcall	_getchar
	mov	r6,dpl
	mov	dptr,#_accept_number_from_user_received_char_65536_86
	mov	a,r6
	movx	@dptr,a
;	uart.c:205: i++;
	mov	dptr,#_accept_number_from_user_i_65536_86
	movx	a,@dptr
	add	a,#0x01
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0x00
	movx	@dptr,a
;	uart.c:206: echo(received_char);
	mov	dpl,r6
	lcall	_echo
;	uart.c:208: if (!(received_char >= '0' && received_char <= '9') && (received_char != '\r'))
	mov	dptr,#_accept_number_from_user_received_char_65536_86
	movx	a,@dptr
	mov	r7,a
	cjne	r7,#0x30,00140$
00140$:
	jc	00107$
	mov	a,r7
	add	a,#0xff - 0x39
	jnc	00104$
00107$:
	mov	dptr,#_accept_number_from_user_received_char_65536_86
	movx	a,@dptr
	mov	r7,a
	cjne	r7,#0x0d,00143$
	sjmp	00104$
00143$:
;	uart.c:211: memset(number_in_char, 0, sizeof(number_in_char));
	mov	dptr,#_memset_PARM_2
	clr	a
	movx	@dptr,a
	mov	dptr,#_memset_PARM_3
	mov	a,#0x19
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_accept_number_from_user_number_in_char_65536_86
	mov	b,#0x00
	lcall	_memset
;	uart.c:212: putstr("\r\n\t\t Error: Re-enter the number: ");
	mov	dptr,#___str_10
	mov	b,#0x80
	lcall	_putstr
;	uart.c:213: i = 0;
	mov	dptr,#_accept_number_from_user_i_65536_86
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	sjmp	00105$
00104$:
;	uart.c:217: else if (received_char == '\r')
	mov	dptr,#_accept_number_from_user_received_char_65536_86
	movx	a,@dptr
	mov	r7,a
	cjne	r7,#0x0d,00105$
;	uart.c:219: strcat(number_in_char, '\0');
	mov	dptr,#_strcat_PARM_2
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_accept_number_from_user_number_in_char_65536_86
	mov	b,#0x00
	lcall	_strcat
;	uart.c:220: number = atoi(number_in_char);
	mov	dptr,#_accept_number_from_user_number_in_char_65536_86
	mov	b,#0x00
	lcall	_atoi
	mov	a,dpl
	mov	b,dph
	mov	dptr,#_accept_number_from_user_number_65536_86
	movx	@dptr,a
	mov	a,b
	inc	dptr
	movx	@dptr,a
;	uart.c:221: valid_number_status = true;
	mov	dptr,#_accept_number_from_user_valid_number_status_65536_86
	mov	a,#0x01
	movx	@dptr,a
00105$:
;	uart.c:224: strncat(number_in_char, &received_char, 1);
	mov	dptr,#_strncat_PARM_2
	mov	a,#_accept_number_from_user_received_char_65536_86
	movx	@dptr,a
	mov	a,#(_accept_number_from_user_received_char_65536_86 >> 8)
	inc	dptr
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_strncat_PARM_3
	inc	a
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_accept_number_from_user_number_in_char_65536_86
	mov	b,#0x00
	lcall	_strncat
;	uart.c:226: if (i >= 24)
	mov	dptr,#_accept_number_from_user_i_65536_86
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	clr	c
	mov	a,r6
	subb	a,#0x18
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00146$
	ljmp	00110$
00146$:
;	uart.c:228: putstr("\r\n\t\t Error: Reading a number failed, Reached maximum length supported");
	mov	dptr,#___str_11
	mov	b,#0x80
	lcall	_putstr
;	uart.c:229: putstr("\r\n\t\t Error: Re-enter the number: ");
	mov	dptr,#___str_10
	mov	b,#0x80
	lcall	_putstr
;	uart.c:231: memset(number_in_char, 0, sizeof(number_in_char));
	mov	dptr,#_memset_PARM_2
	clr	a
	movx	@dptr,a
	mov	dptr,#_memset_PARM_3
	mov	a,#0x19
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_accept_number_from_user_number_in_char_65536_86
	mov	b,#0x00
	lcall	_memset
;	uart.c:232: i = 0;
	mov	dptr,#_accept_number_from_user_i_65536_86
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	ljmp	00110$
00112$:
;	uart.c:235: return number;
	mov	dptr,#_accept_number_from_user_number_65536_86
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
;	uart.c:236: }
	mov	dpl,r6
	mov	dph,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'print_buffers'
;------------------------------------------------------------
;sloc0                     Allocated with name '_print_buffers_sloc0_1_0'
;buffers                   Allocated with name '_print_buffers_buffers_65536_91'
;i                         Allocated with name '_print_buffers_i_131072_93'
;------------------------------------------------------------
;	uart.c:241: void print_buffers(buffer_t *buffers)
;	-----------------------------------------
;	 function print_buffers
;	-----------------------------------------
_print_buffers:
	mov	r7,b
	mov	r6,dph
	mov	a,dpl
	mov	dptr,#_print_buffers_buffers_65536_91
	movx	@dptr,a
	mov	a,r6
	inc	dptr
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:243: printf_tiny("\r\n\r\n\t\t-------------------------");
	mov	a,#___str_12
	push	acc
	mov	a,#(___str_12 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:244: printf_tiny("\r\n\t\t| buffer id |\tsize\t|");
	mov	a,#___str_13
	push	acc
	mov	a,#(___str_13 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:245: printf_tiny("\r\n\t\t-------------------------");
	mov	a,#___str_14
	push	acc
	mov	a,#(___str_14 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:246: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
	mov	dptr,#_print_buffers_buffers_65536_91
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	_print_buffers_sloc0_1_0,r5
	mov	(_print_buffers_sloc0_1_0 + 1),r6
	mov	(_print_buffers_sloc0_1_0 + 2),r7
	mov	r0,#0x00
	mov	r1,#0x00
00107$:
	clr	c
	mov	a,r0
	subb	a,#0xd2
	mov	a,r1
	xrl	a,#0x80
	subb	a,#0x80
	jc	00128$
	ljmp	00105$
00128$:
;	uart.c:248: if ((buffers[i].buffer_pointer != 0) || (i == 0) || (i == 1))
	mov	dptr,#__mulint_PARM_2
	mov	a,r0
	movx	@dptr,a
	mov	a,r1
	inc	dptr
	movx	@dptr,a
	mov	dptr,#0x0009
	push	ar7
	push	ar6
	push	ar5
	push	ar1
	push	ar0
	lcall	__mulint
	mov	r3,dpl
	mov	r4,dph
	pop	ar0
	pop	ar1
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,r3
	add	a,r5
	mov	r3,a
	mov	a,r4
	addc	a,r6
	mov	r4,a
	mov	ar2,r7
	mov	dpl,r3
	mov	dph,r4
	mov	b,r2
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	mov	a,r3
	orl	a,r4
	jnz	00101$
	mov	a,r0
	orl	a,r1
	jz	00101$
	cjne	r0,#0x01,00131$
	cjne	r1,#0x00,00131$
	sjmp	00132$
00131$:
	ljmp	00108$
00132$:
00101$:
;	uart.c:249: printf_tiny("\r\n\t\t|    %d    |\t%d\t|", buffers[i].buf_id, buffers[i].buf_size);
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#__mulint_PARM_2
	mov	a,r0
	movx	@dptr,a
	mov	a,r1
	inc	dptr
	movx	@dptr,a
	mov	dptr,#0x0009
	push	ar5
	push	ar1
	push	ar0
	lcall	__mulint
	mov	r6,dpl
	mov	r7,dph
	pop	ar0
	pop	ar1
	pop	ar5
	mov	a,r6
	add	a,_print_buffers_sloc0_1_0
	mov	r6,a
	mov	a,r7
	addc	a,(_print_buffers_sloc0_1_0 + 1)
	mov	r7,a
	mov	r5,(_print_buffers_sloc0_1_0 + 2)
	mov	a,#0x07
	add	a,r6
	mov	r2,a
	clr	a
	addc	a,r7
	mov	r3,a
	mov	ar4,r5
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	mov	a,#0x05
	add	a,r6
	mov	r6,a
	clr	a
	addc	a,r7
	mov	r7,a
	mov	dpl,r6
	mov	dph,r7
	mov	b,r5
	lcall	__gptrget
	mov	r6,a
	inc	dptr
	lcall	__gptrget
	mov	r7,a
	push	ar7
	push	ar6
	push	ar5
	push	ar1
	push	ar0
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	mov	a,#___str_15
	push	acc
	mov	a,#(___str_15 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
	pop	ar0
	pop	ar1
	pop	ar5
	pop	ar6
	pop	ar7
;	uart.c:251: printf_tiny("\r\n\t\t-------------------------\r\n");
	pop	ar7
	pop	ar6
	pop	ar5
;	uart.c:249: printf_tiny("\r\n\t\t|    %d    |\t%d\t|", buffers[i].buf_id, buffers[i].buf_size);
00108$:
;	uart.c:246: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
	inc	r0
	cjne	r0,#0x00,00133$
	inc	r1
00133$:
	ljmp	00107$
00105$:
;	uart.c:251: printf_tiny("\r\n\t\t-------------------------\r\n");
	mov	a,#___str_16
	push	acc
	mov	a,#(___str_16 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:252: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'hexdump'
;------------------------------------------------------------
;sloc0                     Allocated with name '_hexdump_sloc0_1_0'
;sloc1                     Allocated with name '_hexdump_sloc1_1_0'
;nbytes                    Allocated with name '_hexdump_PARM_2'
;loc                       Allocated with name '_hexdump_loc_65536_95'
;loc_pointer               Allocated with name '_hexdump_loc_pointer_65536_96'
;hex_byte                  Allocated with name '_hexdump_hex_byte_65536_96'
;address_bytes             Allocated with name '_hexdump_address_bytes_65536_96'
;num                       Allocated with name '_hexdump_num_65536_96'
;total_chars_in_output_string Allocated with name '_hexdump_total_chars_in_output_string_65536_96'
;i                         Allocated with name '_hexdump_i_131072_98'
;j                         Allocated with name '_hexdump_j_327680_101'
;------------------------------------------------------------
;	uart.c:257: void hexdump(const void *loc, long nbytes)
;	-----------------------------------------
;	 function hexdump
;	-----------------------------------------
_hexdump:
	mov	r7,b
	mov	r6,dph
	mov	a,dpl
	mov	dptr,#_hexdump_loc_65536_95
	movx	@dptr,a
	mov	a,r6
	inc	dptr
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:259: const char *loc_pointer = loc;
	mov	dptr,#_hexdump_loc_65536_95
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
;	uart.c:260: char hex_byte[5] = "FF";
	mov	dptr,#_hexdump_hex_byte_65536_96
	mov	a,#0x46
	movx	@dptr,a
	mov	dptr,#(_hexdump_hex_byte_65536_96 + 0x0001)
	movx	@dptr,a
	mov	dptr,#(_hexdump_hex_byte_65536_96 + 0x0002)
	clr	a
	movx	@dptr,a
	mov	dptr,#(_hexdump_hex_byte_65536_96 + 0x0003)
	movx	@dptr,a
	mov	dptr,#(_hexdump_hex_byte_65536_96 + 0x0004)
	movx	@dptr,a
;	uart.c:261: char address_bytes[7] = "0x0000";
	mov	dptr,#_hexdump_address_bytes_65536_96
	mov	a,#0x30
	movx	@dptr,a
	mov	dptr,#(_hexdump_address_bytes_65536_96 + 0x0001)
	mov	a,#0x78
	movx	@dptr,a
	mov	dptr,#(_hexdump_address_bytes_65536_96 + 0x0002)
	mov	a,#0x30
	movx	@dptr,a
	mov	dptr,#(_hexdump_address_bytes_65536_96 + 0x0003)
	movx	@dptr,a
	mov	dptr,#(_hexdump_address_bytes_65536_96 + 0x0004)
	movx	@dptr,a
	mov	dptr,#(_hexdump_address_bytes_65536_96 + 0x0005)
	movx	@dptr,a
	mov	dptr,#(_hexdump_address_bytes_65536_96 + 0x0006)
	clr	a
	movx	@dptr,a
;	uart.c:268: if (nbytes == 0)
	mov	dptr,#_hexdump_PARM_2
	movx	a,@dptr
	mov	r1,a
	inc	dptr
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_hexdump_PARM_2
	movx	a,@dptr
	mov	b,a
	inc	dptr
	movx	a,@dptr
	orl	b,a
	inc	dptr
	movx	a,@dptr
	orl	b,a
	inc	dptr
	movx	a,@dptr
	orl	a,b
	jnz	00102$
;	uart.c:270: printf("\r\n\r\n\t\tNo stored characters in the buffer\r\n");
	mov	a,#___str_19
	push	acc
	mov	a,#(___str_19 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
;	uart.c:271: return;
	ret
00102$:
;	uart.c:273: printf_tiny("\r\n\r\n\t\t|=======================================================");
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	mov	a,#___str_20
	push	acc
	mov	a,#(___str_20 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	uart.c:275: for (int i = 0; i < nbytes; i++)
	clr	a
	mov	_hexdump_sloc0_1_0,a
	mov	(_hexdump_sloc0_1_0 + 1),a
00111$:
	push	ar5
	push	ar6
	push	ar7
	mov	r0,_hexdump_sloc0_1_0
	mov	a,(_hexdump_sloc0_1_0 + 1)
	mov	r5,a
	rlc	a
	subb	a,acc
	mov	r6,a
	mov	r7,a
	clr	c
	mov	a,r0
	subb	a,r1
	mov	a,r5
	subb	a,r2
	mov	a,r6
	subb	a,r3
	mov	a,r7
	xrl	a,#0x80
	mov	b,r4
	xrl	b,#0x80
	subb	a,b
	pop	ar7
	pop	ar6
	pop	ar5
	jc	00142$
	ljmp	00106$
00142$:
;	uart.c:277: if (i % 16 == 0) // 16 bytes per line
	mov	dptr,#__modsint_PARM_2
	mov	a,#0x10
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,_hexdump_sloc0_1_0
	mov	dph,(_hexdump_sloc0_1_0 + 1)
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	lcall	__modsint
	mov	a,dpl
	mov	b,dph
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	orl	a,b
	jz	00143$
	ljmp	00105$
00143$:
;	uart.c:280: uint_to_hexstr(address_bytes, sizeof(address_bytes), (uint16_t)loc_pointer + i, 16); // Converting offset address to hec string
	push	ar1
	push	ar2
	push	ar3
	push	ar4
	mov	ar0,r5
	mov	ar3,r6
	mov	ar4,r7
	mov	r2,_hexdump_sloc0_1_0
	mov	r4,(_hexdump_sloc0_1_0 + 1)
	mov	a,r2
	add	a,r0
	mov	r0,a
	mov	a,r4
	addc	a,r3
	mov	r3,a
	mov	dptr,#_uint_to_hexstr_PARM_2
	mov	a,#0x07
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_uint_to_hexstr_PARM_3
	mov	a,r0
	movx	@dptr,a
	mov	a,r3
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_uint_to_hexstr_PARM_4
	mov	a,#0x10
	movx	@dptr,a
	mov	dptr,#_hexdump_address_bytes_65536_96
	mov	b,#0x00
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	lcall	_uint_to_hexstr
;	uart.c:281: printf("|\r\n\t\t| ");
	mov	a,#___str_21
	push	acc
	mov	a,#(___str_21 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	uart.c:283: for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
	mov	_hexdump_sloc1_1_0,#0x02
	mov	(_hexdump_sloc1_1_0 + 1),#0x00
;	uart.c:297: printf_tiny("\r\n\t\t|=======================================================|\r\n");
	pop	ar4
	pop	ar3
	pop	ar2
	pop	ar1
;	uart.c:283: for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
00108$:
	clr	c
	mov	a,_hexdump_sloc1_1_0
	subb	a,#0x06
	mov	a,(_hexdump_sloc1_1_0 + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00103$
;	uart.c:285: printf("%c", address_bytes[j]);
	push	ar1
	push	ar2
	push	ar3
	push	ar4
	mov	a,_hexdump_sloc1_1_0
	add	a,#_hexdump_address_bytes_65536_96
	mov	dpl,a
	mov	a,(_hexdump_sloc1_1_0 + 1)
	addc	a,#(_hexdump_address_bytes_65536_96 >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r0,a
	mov	r4,#0x00
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	push	ar0
	push	ar4
	mov	a,#___str_22
	push	acc
	mov	a,#(___str_22 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	uart.c:283: for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
	inc	_hexdump_sloc1_1_0
	clr	a
	cjne	a,_hexdump_sloc1_1_0,00145$
	inc	(_hexdump_sloc1_1_0 + 1)
00145$:
	pop	ar4
	pop	ar3
	pop	ar2
	pop	ar1
	sjmp	00108$
00103$:
;	uart.c:288: printf(": ");
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	mov	a,#___str_23
	push	acc
	mov	a,#(___str_23 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
00105$:
;	uart.c:290: num = *loc_pointer;
	push	ar1
	push	ar2
	push	ar3
	push	ar4
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r0,a
	inc	dptr
	mov	r5,dpl
	mov	r6,dph
	mov	r4,#0x00
;	uart.c:291: uint_to_hexstr(hex_byte, sizeof(hex_byte), num, 8); // conveting each character to hex string
	mov	dptr,#_uint_to_hexstr_PARM_2
	mov	a,#0x05
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_uint_to_hexstr_PARM_3
	mov	a,r0
	movx	@dptr,a
	mov	a,r4
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_uint_to_hexstr_PARM_4
	mov	a,#0x08
	movx	@dptr,a
	mov	dptr,#_hexdump_hex_byte_65536_96
	mov	b,#0x00
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	lcall	_uint_to_hexstr
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
;	uart.c:292: printf("%c", hex_byte[2]);
	mov	dptr,#(_hexdump_hex_byte_65536_96 + 0x0002)
	movx	a,@dptr
	mov	r4,a
	mov	r3,#0x00
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	push	ar4
	push	ar3
	mov	a,#___str_22
	push	acc
	mov	a,#(___str_22 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
;	uart.c:293: printf("%c", hex_byte[3]);
	mov	dptr,#(_hexdump_hex_byte_65536_96 + 0x0003)
	movx	a,@dptr
	mov	r4,a
	mov	r3,#0x00
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	push	ar4
	push	ar3
	mov	a,#___str_22
	push	acc
	mov	a,#(___str_22 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
;	uart.c:294: printf(" ");
	mov	a,#___str_24
	push	acc
	mov	a,#(___str_24 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	uart.c:295: loc_pointer++;
;	uart.c:275: for (int i = 0; i < nbytes; i++)
	inc	_hexdump_sloc0_1_0
	clr	a
	cjne	a,_hexdump_sloc0_1_0,00146$
	inc	(_hexdump_sloc0_1_0 + 1)
00146$:
	pop	ar4
	pop	ar3
	pop	ar2
	pop	ar1
	ljmp	00111$
00106$:
;	uart.c:297: printf_tiny("\r\n\t\t|=======================================================|\r\n");
	mov	a,#___str_25
	push	acc
	mov	a,#(___str_25 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:298: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uint_to_hexstr'
;------------------------------------------------------------
;sloc0                     Allocated with name '_uint_to_hexstr_sloc0_1_0'
;sloc1                     Allocated with name '_uint_to_hexstr_sloc1_1_0'
;sloc2                     Allocated with name '_uint_to_hexstr_sloc2_1_0'
;sloc3                     Allocated with name '_uint_to_hexstr_sloc3_1_0'
;size                      Allocated with name '_uint_to_hexstr_PARM_2'
;num                       Allocated with name '_uint_to_hexstr_PARM_3'
;nbits                     Allocated with name '_uint_to_hexstr_PARM_4'
;str                       Allocated with name '_uint_to_hexstr_str_65536_103'
;rem                       Allocated with name '_uint_to_hexstr_rem_65536_104'
;total_chars               Allocated with name '_uint_to_hexstr_total_chars_65536_104'
;i                         Allocated with name '_uint_to_hexstr_i_131072_107'
;------------------------------------------------------------
;	uart.c:303: int uint_to_hexstr(char *str, long size, uint16_t num, uint8_t nbits)
;	-----------------------------------------
;	 function uint_to_hexstr
;	-----------------------------------------
_uint_to_hexstr:
	mov	r7,b
	mov	r6,dph
	mov	a,dpl
	mov	dptr,#_uint_to_hexstr_str_65536_103
	movx	@dptr,a
	mov	a,r6
	inc	dptr
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:309: if ((nbits != 4) && (nbits != 8) && (nbits != 16) && (nbits != 32))
	mov	dptr,#_uint_to_hexstr_PARM_4
	movx	a,@dptr
	mov	r7,a
	cjne	r7,#0x04,00150$
	sjmp	00102$
00150$:
	cjne	r7,#0x08,00151$
	sjmp	00102$
00151$:
	cjne	r7,#0x10,00152$
	sjmp	00102$
00152$:
	cjne	r7,#0x20,00153$
	sjmp	00102$
00153$:
;	uart.c:311: str[0] = '\0';
	mov	dptr,#_uint_to_hexstr_str_65536_103
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	clr	a
	lcall	__gptrput
;	uart.c:312: return -1;
	mov	dptr,#0xffff
	ret
00102$:
;	uart.c:315: total_chars = nbits / 4 + 3; // Every nibble requires 4 chars for representation AND +2 for 0x and +1 for \0
	mov	r6,#0x00
	mov	dptr,#__divsint_PARM_2
	mov	a,#0x04
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r7
	mov	dph,r6
	lcall	__divsint
	mov	_uint_to_hexstr_sloc3_1_0,dpl
	mov	(_uint_to_hexstr_sloc3_1_0 + 1),dph
	mov	a,#0x03
	add	a,_uint_to_hexstr_sloc3_1_0
	mov	_uint_to_hexstr_sloc1_1_0,a
	clr	a
	addc	a,(_uint_to_hexstr_sloc3_1_0 + 1)
	mov	(_uint_to_hexstr_sloc1_1_0 + 1),a
;	uart.c:318: if (total_chars > size)
	mov	dptr,#_uint_to_hexstr_PARM_2
	movx	a,@dptr
	mov	_uint_to_hexstr_sloc0_1_0,a
	inc	dptr
	movx	a,@dptr
	mov	(_uint_to_hexstr_sloc0_1_0 + 1),a
	inc	dptr
	movx	a,@dptr
	mov	(_uint_to_hexstr_sloc0_1_0 + 2),a
	inc	dptr
	movx	a,@dptr
	mov	(_uint_to_hexstr_sloc0_1_0 + 3),a
	mov	r0,_uint_to_hexstr_sloc1_1_0
	mov	a,(_uint_to_hexstr_sloc1_1_0 + 1)
	mov	r1,a
	rlc	a
	subb	a,acc
	mov	r2,a
	mov	r3,a
	clr	c
	mov	a,_uint_to_hexstr_sloc0_1_0
	subb	a,r0
	mov	a,(_uint_to_hexstr_sloc0_1_0 + 1)
	subb	a,r1
	mov	a,(_uint_to_hexstr_sloc0_1_0 + 2)
	subb	a,r2
	mov	a,(_uint_to_hexstr_sloc0_1_0 + 3)
	xrl	a,#0x80
	mov	b,r3
	xrl	b,#0x80
	subb	a,b
	jnc	00107$
;	uart.c:320: str[0] = '\0';
	mov	dptr,#_uint_to_hexstr_str_65536_103
	movx	a,@dptr
	mov	r1,a
	inc	dptr
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	clr	a
	lcall	__gptrput
;	uart.c:321: return -1;
	mov	dptr,#0xffff
	ret
00107$:
;	uart.c:324: str[0] = '0';
	mov	dptr,#_uint_to_hexstr_str_65536_103
	movx	a,@dptr
	mov	r1,a
	inc	dptr
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	mov	a,#0x30
	lcall	__gptrput
;	uart.c:325: str[1] = 'x';
	mov	a,#0x01
	add	a,r1
	mov	r0,a
	clr	a
	addc	a,r2
	mov	r4,a
	mov	ar5,r3
	mov	dpl,r0
	mov	dph,r4
	mov	b,r5
	mov	a,#0x78
	lcall	__gptrput
;	uart.c:326: str[total_chars] = '\0';
	mov	a,_uint_to_hexstr_sloc1_1_0
	add	a,r1
	mov	r0,a
	mov	a,(_uint_to_hexstr_sloc1_1_0 + 1)
	addc	a,r2
	mov	r4,a
	mov	ar5,r3
	mov	dpl,r0
	mov	dph,r4
	mov	b,r5
	clr	a
	lcall	__gptrput
;	uart.c:329: for (int i = total_chars - 2; i > 1; i--)
	mov	a,_uint_to_hexstr_sloc3_1_0
	add	a,#0x01
	mov	r4,a
	clr	a
	addc	a,(_uint_to_hexstr_sloc3_1_0 + 1)
	mov	r5,a
	mov	_uint_to_hexstr_sloc0_1_0,r1
	mov	(_uint_to_hexstr_sloc0_1_0 + 1),r2
	mov	(_uint_to_hexstr_sloc0_1_0 + 2),r3
00113$:
	clr	c
	mov	a,#0x01
	subb	a,r4
	mov	a,#(0x00 ^ 0x80)
	mov	b,r5
	xrl	b,#0x80
	subb	a,b
	jc	00155$
	ljmp	00111$
00155$:
;	uart.c:331: rem = num % 16;
	mov	dptr,#_uint_to_hexstr_PARM_3
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	a,#0x0f
	anl	a,r0
	mov	_uint_to_hexstr_sloc1_1_0,a
	mov	(_uint_to_hexstr_sloc1_1_0 + 1),#0x00
;	uart.c:332: if (rem < 10)
	mov	r6,_uint_to_hexstr_sloc1_1_0
	mov	r7,(_uint_to_hexstr_sloc1_1_0 + 1)
	clr	c
	mov	a,r6
	subb	a,#0x0a
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00109$
;	uart.c:334: str[i] = '0' + rem;
	mov	a,r4
	add	a,r1
	mov	_uint_to_hexstr_sloc2_1_0,a
	mov	a,r5
	addc	a,r2
	mov	(_uint_to_hexstr_sloc2_1_0 + 1),a
	mov	(_uint_to_hexstr_sloc2_1_0 + 2),r3
	mov	r6,_uint_to_hexstr_sloc1_1_0
	mov	r7,(_uint_to_hexstr_sloc1_1_0 + 1)
	mov	a,#0x30
	add	a,r6
	mov	r6,a
	mov	dpl,_uint_to_hexstr_sloc2_1_0
	mov	dph,(_uint_to_hexstr_sloc2_1_0 + 1)
	mov	b,(_uint_to_hexstr_sloc2_1_0 + 2)
	lcall	__gptrput
	sjmp	00110$
00109$:
;	uart.c:338: str[i] = 'A' + (rem % 10);
	push	ar1
	push	ar2
	push	ar3
	mov	a,r4
	add	a,_uint_to_hexstr_sloc0_1_0
	mov	r0,a
	mov	a,r5
	addc	a,(_uint_to_hexstr_sloc0_1_0 + 1)
	mov	r6,a
	mov	r7,(_uint_to_hexstr_sloc0_1_0 + 2)
	mov	r2,_uint_to_hexstr_sloc1_1_0
	mov	r3,(_uint_to_hexstr_sloc1_1_0 + 1)
	mov	dptr,#__modsint_PARM_2
	mov	a,#0x0a
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r2
	mov	dph,r3
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar1
	push	ar0
	lcall	__modsint
	mov	r2,dpl
	pop	ar0
	pop	ar1
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,#0x41
	add	a,r2
	mov	dpl,r0
	mov	dph,r6
	mov	b,r7
	lcall	__gptrput
;	uart.c:343: return total_chars - 1;
	pop	ar3
	pop	ar2
	pop	ar1
;	uart.c:338: str[i] = 'A' + (rem % 10);
00110$:
;	uart.c:340: num = num / 16;
	mov	dptr,#_uint_to_hexstr_PARM_3
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	swap	a
	xch	a,r6
	swap	a
	anl	a,#0x0f
	xrl	a,r6
	xch	a,r6
	anl	a,#0x0f
	xch	a,r6
	xrl	a,r6
	xch	a,r6
	mov	r7,a
	mov	dptr,#_uint_to_hexstr_PARM_3
	mov	a,r6
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:329: for (int i = total_chars - 2; i > 1; i--)
	dec	r4
	cjne	r4,#0xff,00157$
	dec	r5
00157$:
	ljmp	00113$
00111$:
;	uart.c:343: return total_chars - 1;
	mov	a,_uint_to_hexstr_sloc3_1_0
	add	a,#0x02
	mov	r6,a
	clr	a
	addc	a,(_uint_to_hexstr_sloc3_1_0 + 1)
;	uart.c:344: }
	mov	dpl,r6
	mov	dph,a
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area CONST   (CODE)
___str_0:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii " ** Turning PWM on ** "
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_1:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii " ** Turning PWM off ** "
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_2:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii " ** Setting up minimum frequency ** "
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_3:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii " ** Setting up maximum frequency ** "
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_4:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii " ** Entering IDLE mode ** "
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_5:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii " ** Entering Power-down mode ** "
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_6:
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x09
	.ascii " Error: Received invalid command '%c'"
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
	.ascii "Enter command: "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_10:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii " Error: Re-enter the number: "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_11:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii " Error: Reading a number failed, Reached maximum length supp"
	.ascii "orted"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_12:
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "-------------------------"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_13:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "| buffer id |"
	.db 0x09
	.ascii "size"
	.db 0x09
	.ascii "|"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_14:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "-------------------------"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_15:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "|    %d    |"
	.db 0x09
	.ascii "%d"
	.db 0x09
	.ascii "|"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_16:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "-------------------------"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_19:
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "No stored characters in the buffer"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_20:
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "|======================================================="
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_21:
	.ascii "|"
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "| "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_22:
	.ascii "%c"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_23:
	.ascii ": "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_24:
	.ascii " "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_25:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "|=======================================================|"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area XINIT   (CODE)
__xinit__buf_number:
	.byte #0x00, #0x00	;  0
__xinit__total_malloced_data:
	.byte #0x00, #0x00	;  0
	.area CABS    (ABS,CODE)
