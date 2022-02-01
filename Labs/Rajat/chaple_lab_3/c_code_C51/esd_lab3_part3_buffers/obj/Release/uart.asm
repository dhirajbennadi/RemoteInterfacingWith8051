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
	.globl _free
	.globl _malloc
	.globl _atoi
	.globl _main
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
	.globl _total_malloced_data
	.globl _buf_number
	.globl _uint_to_hexstr_PARM_4
	.globl _uint_to_hexstr_PARM_3
	.globl _uint_to_hexstr_PARM_2
	.globl _hexdump_PARM_2
	.globl _command_PARM_2
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
_command_sloc0_1_0:
	.ds 3
_command_sloc1_1_0:
	.ds 3
_command_sloc2_1_0:
	.ds 2
_command_sloc3_1_0:
	.ds 2
_command_sloc4_1_0:
	.ds 3
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
_command_PARM_2:
	.ds 3
_command_received_char_65536_77:
	.ds 1
_command_new_buff_id_65536_78:
	.ds 2
_putchar_c_65536_105:
	.ds 2
_putstr_str_65536_108:
	.ds 3
_accept_number_from_user_received_char_65536_111:
	.ds 1
_accept_number_from_user_number_in_char_65536_111:
	.ds 25
_accept_number_from_user_valid_number_status_65536_111:
	.ds 1
_accept_number_from_user_number_65536_111:
	.ds 2
_accept_number_from_user_i_65536_111:
	.ds 2
_print_buffers_buffers_65536_116:
	.ds 3
_hexdump_PARM_2:
	.ds 4
_hexdump_loc_65536_120:
	.ds 3
_hexdump_hex_byte_65536_121:
	.ds 5
_hexdump_address_bytes_65536_121:
	.ds 7
_uint_to_hexstr_PARM_2:
	.ds 4
_uint_to_hexstr_PARM_3:
	.ds 2
_uint_to_hexstr_PARM_4:
	.ds 1
_uint_to_hexstr_str_65536_128:
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
;sloc0                     Allocated with name '_command_sloc0_1_0'
;sloc1                     Allocated with name '_command_sloc1_1_0'
;sloc2                     Allocated with name '_command_sloc2_1_0'
;sloc3                     Allocated with name '_command_sloc3_1_0'
;sloc4                     Allocated with name '_command_sloc4_1_0'
;buffers                   Allocated with name '_command_PARM_2'
;received_char             Allocated with name '_command_received_char_65536_77'
;new_buff_size             Allocated with name '_command_new_buff_size_65536_78'
;buffer_to_be_deleted      Allocated with name '_command_buffer_to_be_deleted_65536_78'
;new_buff_id               Allocated with name '_command_new_buff_id_65536_78'
;iBuffer                   Allocated with name '_command_iBuffer_196608_80'
;i                         Allocated with name '_command_i_262144_85'
;i                         Allocated with name '_command_i_327680_92'
;i                         Allocated with name '_command_i_196608_95'
;i                         Allocated with name '_command_i_196608_98'
;iBuffer0                  Allocated with name '_command_iBuffer0_196608_101'
;iBuffer                   Allocated with name '_command_iBuffer_196608_103'
;------------------------------------------------------------
;	uart.c:94: void command(char received_char, buffer_t *buffers)
;	-----------------------------------------
;	 function command
;	-----------------------------------------
_command:
	mov	a,dpl
	mov	dptr,#_command_received_char_65536_77
	movx	@dptr,a
;	uart.c:98: uint16_t new_buff_id = 0;
	mov	dptr,#_command_new_buff_id_65536_78
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	uart.c:100: if ((received_char >= 'a') && (received_char <= 'z')) // since small letter characters are storage characters and not command characters
	mov	dptr,#_command_received_char_65536_77
	movx	a,@dptr
	mov	r7,a
	cjne	r7,#0x61,00313$
00313$:
	jc	00102$
	mov	a,r7
	add	a,#0xff - 0x7a
	jc	00102$
;	uart.c:101: return;
	ret
00102$:
;	uart.c:103: switch (received_char)
	mov	dptr,#_command_received_char_65536_77
	movx	a,@dptr
	mov	r7,a
	cjne	r7,#0x2b,00316$
	sjmp	00104$
00316$:
	cjne	r7,#0x2d,00317$
	ljmp	00128$
00317$:
	cjne	r7,#0x3d,00318$
	ljmp	00141$
00318$:
	cjne	r7,#0x3f,00319$
	ljmp	00132$
00319$:
	cjne	r7,#0x40,00320$
	ljmp	00142$
00320$:
	ljmp	00146$
;	uart.c:107: case '+':
00104$:
;	uart.c:108: total_malloced_data = 0;
	mov	dptr,#_total_malloced_data
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	uart.c:109: for(int iBuffer = 0; iBuffer < MAX_NUM_OF_BUFFERS; iBuffer++)
	mov	dptr,#_command_PARM_2
	movx	a,@dptr
	mov	_command_sloc0_1_0,a
	inc	dptr
	movx	a,@dptr
	mov	(_command_sloc0_1_0 + 1),a
	inc	dptr
	movx	a,@dptr
	mov	(_command_sloc0_1_0 + 2),a
	mov	r2,#0x00
	mov	r3,#0x00
00149$:
	clr	c
	mov	a,r2
	subb	a,#0xd2
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00105$
;	uart.c:111: total_malloced_data += buffers[iBuffer].buf_size;
	mov	dptr,#__mulint_PARM_2
	mov	a,r2
	movx	@dptr,a
	mov	a,r3
	inc	dptr
	movx	@dptr,a
	mov	dptr,#0x0009
	push	ar3
	push	ar2
	lcall	__mulint
	mov	r0,dpl
	mov	r1,dph
	pop	ar2
	pop	ar3
	mov	a,r0
	add	a,_command_sloc0_1_0
	mov	r0,a
	mov	a,r1
	addc	a,(_command_sloc0_1_0 + 1)
	mov	r1,a
	mov	r6,(_command_sloc0_1_0 + 2)
	mov	a,#0x07
	add	a,r0
	mov	r0,a
	clr	a
	addc	a,r1
	mov	r1,a
	mov	dpl,r0
	mov	dph,r1
	mov	b,r6
	lcall	__gptrget
	mov	r0,a
	inc	dptr
	lcall	__gptrget
	mov	r1,a
	mov	dptr,#_total_malloced_data
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	mov	dptr,#_total_malloced_data
	mov	a,r0
	add	a,r5
	movx	@dptr,a
	mov	a,r1
	addc	a,r6
	inc	dptr
	movx	@dptr,a
;	uart.c:109: for(int iBuffer = 0; iBuffer < MAX_NUM_OF_BUFFERS; iBuffer++)
	inc	r2
	cjne	r2,#0x00,00149$
	inc	r3
	sjmp	00149$
00105$:
;	uart.c:113: putstr("\r\n\r\n\t *** Command for adding a buffer ***\r\n");
	mov	dptr,#___str_0
	mov	b,#0x80
	lcall	_putstr
;	uart.c:114: putstr("\r\n\t\b> Specify buffer size to be allocated (30 bytes to 300 bytes): ");
	mov	dptr,#___str_1
	mov	b,#0x80
	lcall	_putstr
;	uart.c:115: new_buff_size = accept_number_from_user();
	lcall	_accept_number_from_user
	mov	_command_sloc3_1_0,dpl
	mov	(_command_sloc3_1_0 + 1),dph
;	uart.c:116: total_malloced_data += new_buff_size;
	mov	dptr,#_total_malloced_data
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#_total_malloced_data
	mov	a,_command_sloc3_1_0
	add	a,r3
	movx	@dptr,a
	mov	a,(_command_sloc3_1_0 + 1)
	addc	a,r4
	inc	dptr
	movx	@dptr,a
;	uart.c:121: if ((new_buff_size < 30) || (new_buff_size > 300))
	mov	r3,_command_sloc3_1_0
	mov	r4,(_command_sloc3_1_0 + 1)
	clr	c
	mov	a,r3
	subb	a,#0x1e
	mov	a,r4
	subb	a,#0x00
	jc	00124$
	mov	r3,_command_sloc3_1_0
	mov	r4,(_command_sloc3_1_0 + 1)
	clr	c
	mov	a,#0x2c
	subb	a,r3
	mov	a,#0x01
	subb	a,r4
	jnc	00125$
00124$:
;	uart.c:123: putstr("\t Error: Invalid size");
	mov	dptr,#___str_2
	mov	b,#0x80
	lcall	_putstr
;	uart.c:124: putstr("\r\n\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	mov	dptr,#___str_3
	mov	b,#0x80
	lcall	_putstr
;	uart.c:125: command('+', buffers); // accepting size again
	mov	dptr,#_command_PARM_2
	mov	a,_command_sloc0_1_0
	movx	@dptr,a
	mov	a,(_command_sloc0_1_0 + 1)
	inc	dptr
	movx	@dptr,a
	mov	a,(_command_sloc0_1_0 + 2)
	inc	dptr
	movx	@dptr,a
	mov	dpl,#0x2b
	lcall	_command
	ljmp	00147$
00125$:
;	uart.c:127: else if(total_malloced_data > __sdcc_heap_size)
	mov	dptr,#_total_malloced_data
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	dptr,#___sdcc_heap_size
	clr	a
	movc	a,@a+dptr
	mov	r1,a
	mov	a,#0x01
	movc	a,@a+dptr
	mov	r2,a
	clr	c
	mov	a,r1
	subb	a,r3
	mov	a,r2
	subb	a,r4
	jnc	00185$
;	uart.c:129: putstr("\t Error: Out of memory, free some buffers to continue");
	mov	dptr,#___str_4
	mov	b,#0x80
	lcall	_putstr
;	uart.c:130: break;
	ljmp	00147$
;	uart.c:135: for (int i = 2; i < MAX_NUM_OF_BUFFERS; i++)
00185$:
	mov	_command_sloc1_1_0,_command_sloc0_1_0
	mov	(_command_sloc1_1_0 + 1),(_command_sloc0_1_0 + 1)
	mov	(_command_sloc1_1_0 + 2),(_command_sloc0_1_0 + 2)
	mov	r0,#0x02
	mov	r1,#0x00
00152$:
	clr	c
	mov	a,r0
	subb	a,#0xd2
	mov	a,r1
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00110$
;	uart.c:137: if (buffers[i].buffer_pointer == 0)
	mov	dptr,#__mulint_PARM_2
	mov	a,r0
	movx	@dptr,a
	mov	a,r1
	inc	dptr
	movx	@dptr,a
	mov	dptr,#0x0009
	push	ar1
	push	ar0
	lcall	__mulint
	mov	r5,dpl
	mov	r6,dph
	pop	ar0
	pop	ar1
	mov	a,r5
	add	a,_command_sloc1_1_0
	mov	r5,a
	mov	a,r6
	addc	a,(_command_sloc1_1_0 + 1)
	mov	r4,a
	mov	r6,(_command_sloc1_1_0 + 2)
	mov	dpl,r5
	mov	dph,r4
	mov	b,r6
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	a,r5
	orl	a,r4
	jnz	00107$
;	uart.c:139: new_buff_id = i;
	mov	dptr,#_command_new_buff_id_65536_78
	mov	a,r0
	movx	@dptr,a
	mov	a,r1
	inc	dptr
	movx	@dptr,a
;	uart.c:140: break;
	sjmp	00110$
00107$:
;	uart.c:142: if (i == MAX_NUM_OF_BUFFERS - 1)
	cjne	r0,#0xd1,00153$
	cjne	r1,#0x00,00153$
;	uart.c:144: putstr("\tError: buffer could not be added\r\n");
	mov	dptr,#___str_5
	mov	b,#0x80
	lcall	_putstr
;	uart.c:145: break;
	sjmp	00110$
00153$:
;	uart.c:135: for (int i = 2; i < MAX_NUM_OF_BUFFERS; i++)
	inc	r0
	cjne	r0,#0x00,00152$
	inc	r1
	sjmp	00152$
00110$:
;	uart.c:149: buffers[new_buff_id].buffer_pointer = (char *)malloc(sizeof(char) * new_buff_size);
	mov	r2,_command_sloc0_1_0
	mov	r3,(_command_sloc0_1_0 + 1)
	mov	r4,(_command_sloc0_1_0 + 2)
	mov	dptr,#_command_new_buff_id_65536_78
	movx	a,@dptr
	mov	_command_sloc2_1_0,a
	inc	dptr
	movx	a,@dptr
	mov	(_command_sloc2_1_0 + 1),a
	mov	dptr,#__mulint_PARM_2
	mov	a,_command_sloc2_1_0
	movx	@dptr,a
	mov	a,(_command_sloc2_1_0 + 1)
	inc	dptr
	movx	@dptr,a
	mov	dptr,#0x0009
	push	ar4
	push	ar3
	push	ar2
	lcall	__mulint
	mov	_command_sloc1_1_0,dpl
	mov	(_command_sloc1_1_0 + 1),dph
	mov	a,_command_sloc1_1_0
	add	a,_command_sloc0_1_0
	mov	_command_sloc4_1_0,a
	mov	a,(_command_sloc1_1_0 + 1)
	addc	a,(_command_sloc0_1_0 + 1)
	mov	(_command_sloc4_1_0 + 1),a
	mov	(_command_sloc4_1_0 + 2),(_command_sloc0_1_0 + 2)
	mov	dpl,_command_sloc3_1_0
	mov	dph,(_command_sloc3_1_0 + 1)
	lcall	_malloc
	mov	r5,dpl
	mov	r6,dph
	pop	ar2
	pop	ar3
	pop	ar4
	mov	ar1,r6
	mov	r6,#0x00
	mov	dpl,_command_sloc4_1_0
	mov	dph,(_command_sloc4_1_0 + 1)
	mov	b,(_command_sloc4_1_0 + 2)
	mov	a,r5
	lcall	__gptrput
	inc	dptr
	mov	a,r1
	lcall	__gptrput
	inc	dptr
	mov	a,r6
	lcall	__gptrput
;	uart.c:150: if (buffers[new_buff_id].buffer_pointer == NULL)
	mov	a,r5
	orl	a,r1
	jnz	00112$
;	uart.c:152: putstr("\tError: Failed allocating memory\r\n");
	mov	dptr,#___str_6
	mov	b,#0x80
	lcall	_putstr
;	uart.c:153: break;
	ljmp	00147$
00112$:
;	uart.c:157: putstr("\tNew buffer has been created\r\n");
	push	ar2
	push	ar3
	push	ar4
	mov	dptr,#___str_7
	mov	b,#0x80
	push	ar4
	push	ar3
	push	ar2
	lcall	_putstr
	pop	ar2
	pop	ar3
	pop	ar4
;	uart.c:160: buffers[new_buff_id].buf_id = new_buff_id;
	mov	a,_command_sloc1_1_0
	add	a,_command_sloc0_1_0
	mov	r1,a
	mov	a,(_command_sloc1_1_0 + 1)
	addc	a,(_command_sloc0_1_0 + 1)
	mov	r5,a
	mov	r6,(_command_sloc0_1_0 + 2)
	mov	a,#0x05
	add	a,r1
	mov	r0,a
	clr	a
	addc	a,r5
	mov	r3,a
	mov	ar4,r6
	mov	dpl,r0
	mov	dph,r3
	mov	b,r4
	mov	a,_command_sloc2_1_0
	lcall	__gptrput
	inc	dptr
	mov	a,(_command_sloc2_1_0 + 1)
	lcall	__gptrput
;	uart.c:161: buffers[new_buff_id].buf_size = new_buff_size;
	mov	a,#0x07
	add	a,r1
	mov	r2,a
	clr	a
	addc	a,r5
	mov	r3,a
	mov	ar4,r6
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_command_sloc3_1_0
	lcall	__gptrput
	inc	dptr
	mov	a,(_command_sloc3_1_0 + 1)
	lcall	__gptrput
;	uart.c:162: buffers[new_buff_id].buf_index = 0;
	mov	a,#0x03
	add	a,r1
	mov	r1,a
	clr	a
	addc	a,r5
	mov	r5,a
	mov	dpl,r1
	mov	dph,r5
	mov	b,r6
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	uart.c:166: printf_tiny("\r\n\r\n\t\t-------------------------");
	push	ar4
	push	ar3
	push	ar2
	mov	a,#___str_8
	push	acc
	mov	a,#(___str_8 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:167: printf_tiny("\r\n\t\t|buffer id|\tsize\t|");
	mov	a,#___str_9
	push	acc
	mov	a,#(___str_9 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:168: printf_tiny("\r\n\t\t-------------------------");
	mov	a,#___str_10
	push	acc
	mov	a,#(___str_10 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
	pop	ar2
	pop	ar3
	pop	ar4
;	uart.c:169: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
	mov	_command_sloc4_1_0,_command_sloc2_1_0
	mov	(_command_sloc4_1_0 + 1),(_command_sloc2_1_0 + 1)
	clr	a
	mov	_command_sloc3_1_0,a
	mov	(_command_sloc3_1_0 + 1),a
;	uart.c:265: putstr("Enter command (+, -, ?, =, @) or input: ");
	pop	ar4
	pop	ar3
	pop	ar2
;	uart.c:169: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
00155$:
	clr	c
	mov	a,_command_sloc3_1_0
	subb	a,#0xd2
	mov	a,(_command_sloc3_1_0 + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jc	00332$
	ljmp	00120$
00332$:
;	uart.c:171: if ((buffers[i].buffer_pointer != 0) || (i == 0) || (i == 1))
	mov	dptr,#__mulint_PARM_2
	mov	a,_command_sloc3_1_0
	movx	@dptr,a
	mov	a,(_command_sloc3_1_0 + 1)
	inc	dptr
	movx	@dptr,a
	mov	dptr,#0x0009
	push	ar4
	push	ar3
	push	ar2
	lcall	__mulint
	mov	r5,dpl
	mov	r6,dph
	pop	ar2
	pop	ar3
	pop	ar4
	mov	a,r5
	add	a,r2
	mov	r5,a
	mov	a,r6
	addc	a,r3
	mov	r1,a
	mov	ar6,r4
	mov	dpl,r5
	mov	dph,r1
	mov	b,r6
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r1,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	a,r5
	orl	a,r1
	jnz	00116$
	mov	a,_command_sloc3_1_0
	orl	a,(_command_sloc3_1_0 + 1)
	jz	00116$
	mov	a,#0x01
	cjne	a,_command_sloc3_1_0,00335$
	dec	a
	cjne	a,(_command_sloc3_1_0 + 1),00335$
	sjmp	00336$
00335$:
	ljmp	00156$
00336$:
00116$:
;	uart.c:173: printf_tiny("\r\n\t\t|    %d    |\t%d\t|", buffers[i].buf_id, buffers[i].buf_size);
	mov	dptr,#__mulint_PARM_2
	mov	a,_command_sloc3_1_0
	movx	@dptr,a
	mov	a,(_command_sloc3_1_0 + 1)
	inc	dptr
	movx	@dptr,a
	mov	dptr,#0x0009
	push	ar4
	push	ar3
	push	ar2
	lcall	__mulint
	mov	r5,dpl
	mov	r6,dph
	pop	ar2
	pop	ar3
	pop	ar4
	mov	a,r5
	add	a,r2
	mov	r5,a
	mov	a,r6
	addc	a,r3
	mov	r1,a
	mov	ar6,r4
	push	ar2
	push	ar3
	push	ar4
	mov	a,#0x07
	add	a,r5
	mov	r0,a
	clr	a
	addc	a,r1
	mov	r3,a
	mov	ar4,r6
	mov	dpl,r0
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r0,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	mov	a,#0x05
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r1
	mov	r1,a
	mov	dpl,r5
	mov	dph,r1
	mov	b,r6
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	push	ar0
	push	ar3
	push	ar2
	push	ar4
	mov	a,#___str_11
	push	acc
	mov	a,#(___str_11 >> 8)
	push	acc
	lcall	_printf_tiny
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
;	uart.c:174: if (buffers[i].buf_id == new_buff_id)
	mov	dpl,r5
	mov	dph,r1
	mov	b,r6
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r1,a
	mov	a,r5
	cjne	a,_command_sloc4_1_0,00337$
	mov	a,r1
	cjne	a,(_command_sloc4_1_0 + 1),00337$
	sjmp	00338$
00337$:
	pop	ar4
	pop	ar3
	pop	ar2
	sjmp	00156$
00338$:
	pop	ar4
	pop	ar3
	pop	ar2
;	uart.c:175: putstr(" <----- Newly added");
	mov	dptr,#___str_12
	mov	b,#0x80
	push	ar4
	push	ar3
	push	ar2
	lcall	_putstr
	pop	ar2
	pop	ar3
	pop	ar4
00156$:
;	uart.c:169: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
	inc	_command_sloc3_1_0
	clr	a
	cjne	a,_command_sloc3_1_0,00339$
	inc	(_command_sloc3_1_0 + 1)
00339$:
	ljmp	00155$
00120$:
;	uart.c:178: printf_tiny("\r\n\t\t-------------------------\r\n");
	mov	a,#___str_13
	push	acc
	mov	a,#(___str_13 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:182: break;
	ljmp	00147$
;	uart.c:185: case '-':
00128$:
;	uart.c:186: putstr("\r\n\r\n\t *** Command for removing a buffer ***\r\n");
	mov	dptr,#___str_14
	mov	b,#0x80
	lcall	_putstr
;	uart.c:187: print_buffers(buffers);
	mov	dptr,#_command_PARM_2
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
	lcall	_print_buffers
;	uart.c:188: putstr("\r\n\t\b> Specify buffer to be delated (select id from the list): ");
	mov	dptr,#___str_15
	mov	b,#0x80
	lcall	_putstr
;	uart.c:189: buffer_to_be_deleted = accept_number_from_user();
	lcall	_accept_number_from_user
	mov	_command_sloc4_1_0,dpl
	mov	(_command_sloc4_1_0 + 1),dph
;	uart.c:190: for (int i = 2; i < MAX_NUM_OF_BUFFERS; i++)
	mov	dptr,#_command_PARM_2
	movx	a,@dptr
	mov	r2,a
	inc	dptr
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	mov	r0,#0x02
	mov	r1,#0x00
00158$:
	clr	c
	mov	a,r0
	subb	a,#0xd2
	mov	a,r1
	xrl	a,#0x80
	subb	a,#0x80
	jc	00340$
	ljmp	00131$
00340$:
;	uart.c:192: if (buffer_to_be_deleted == buffers[i].buf_id)
	mov	dptr,#__mulint_PARM_2
	mov	a,r0
	movx	@dptr,a
	mov	a,r1
	inc	dptr
	movx	@dptr,a
	mov	dptr,#0x0009
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	push	ar0
	lcall	__mulint
	mov	r5,dpl
	mov	r6,dph
	pop	ar0
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	mov	a,r5
	add	a,r2
	mov	_command_sloc1_1_0,a
	mov	a,r6
	addc	a,r3
	mov	(_command_sloc1_1_0 + 1),a
	mov	(_command_sloc1_1_0 + 2),r4
	mov	a,#0x05
	add	a,_command_sloc1_1_0
	mov	_command_sloc0_1_0,a
	clr	a
	addc	a,(_command_sloc1_1_0 + 1)
	mov	(_command_sloc0_1_0 + 1),a
	mov	(_command_sloc0_1_0 + 2),(_command_sloc1_1_0 + 2)
	mov	dpl,_command_sloc0_1_0
	mov	dph,(_command_sloc0_1_0 + 1)
	mov	b,(_command_sloc0_1_0 + 2)
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	a,r5
	cjne	a,_command_sloc4_1_0,00341$
	mov	a,r6
	cjne	a,(_command_sloc4_1_0 + 1),00341$
	sjmp	00342$
00341$:
	ljmp	00159$
00342$:
;	uart.c:194: free(buffers[i].buffer_pointer);
	push	ar2
	push	ar3
	push	ar4
	mov	dpl,_command_sloc1_1_0
	mov	dph,(_command_sloc1_1_0 + 1)
	mov	b,(_command_sloc1_1_0 + 2)
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	push	ar0
	lcall	_free
	pop	ar0
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
;	uart.c:195: buffers[i].buffer_pointer = 0;
	mov	dpl,_command_sloc1_1_0
	mov	dph,(_command_sloc1_1_0 + 1)
	mov	b,(_command_sloc1_1_0 + 2)
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	uart.c:196: buffers[i].buf_id = -1;
	mov	dpl,_command_sloc0_1_0
	mov	dph,(_command_sloc0_1_0 + 1)
	mov	b,(_command_sloc0_1_0 + 2)
	dec	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	uart.c:197: buffers[i].buf_index = 0;
	mov	a,#0x03
	add	a,_command_sloc1_1_0
	mov	r4,a
	clr	a
	addc	a,(_command_sloc1_1_0 + 1)
	mov	r5,a
	mov	r6,(_command_sloc1_1_0 + 2)
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	uart.c:198: buffers[i].buf_size = 0;
	mov	a,#0x07
	add	a,_command_sloc1_1_0
	mov	r4,a
	clr	a
	addc	a,(_command_sloc1_1_0 + 1)
	mov	r5,a
	mov	r6,(_command_sloc1_1_0 + 2)
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	uart.c:265: putstr("Enter command (+, -, ?, =, @) or input: ");
	pop	ar4
	pop	ar3
	pop	ar2
;	uart.c:198: buffers[i].buf_size = 0;
00159$:
;	uart.c:190: for (int i = 2; i < MAX_NUM_OF_BUFFERS; i++)
	inc	r0
	cjne	r0,#0x00,00343$
	inc	r1
00343$:
	ljmp	00158$
00131$:
;	uart.c:201: print_buffers(buffers);
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	_print_buffers
;	uart.c:202: break;
	ljmp	00147$
;	uart.c:205: case '?':
00132$:
;	uart.c:206: putstr("\r\n\r\n\t *** Command for a query ***\r\n");
	mov	dptr,#___str_16
	mov	b,#0x80
	lcall	_putstr
;	uart.c:207: printf_tiny("\r\n\r\n\t\t-----------------------------------------------------------------");
	mov	a,#___str_17
	push	acc
	mov	a,#(___str_17 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:208: putstr("\r\n\t\t| Buffer id | start-addr | end-addr | nStorageChar | free-space |\t\r\n");
	mov	dptr,#___str_18
	mov	b,#0x80
	lcall	_putstr
;	uart.c:209: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
	mov	dptr,#_command_PARM_2
	movx	a,@dptr
	mov	_command_sloc4_1_0,a
	inc	dptr
	movx	a,@dptr
	mov	(_command_sloc4_1_0 + 1),a
	inc	dptr
	movx	a,@dptr
	mov	(_command_sloc4_1_0 + 2),a
	mov	r2,#0x00
	mov	r3,#0x00
00161$:
	clr	c
	mov	a,r2
	subb	a,#0xd2
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jc	00344$
	ljmp	00137$
00344$:
;	uart.c:214: if ((buffers[i].buffer_pointer != 0) || (i == 0) || (i == 1))
	mov	dptr,#__mulint_PARM_2
	mov	a,r2
	movx	@dptr,a
	mov	a,r3
	inc	dptr
	movx	@dptr,a
	mov	dptr,#0x0009
	push	ar3
	push	ar2
	lcall	__mulint
	mov	r0,dpl
	mov	r1,dph
	pop	ar2
	pop	ar3
	push	ar2
	push	ar3
	mov	a,r0
	add	a,_command_sloc4_1_0
	mov	r0,a
	mov	a,r1
	addc	a,(_command_sloc4_1_0 + 1)
	mov	r1,a
	mov	r3,(_command_sloc4_1_0 + 2)
	mov	dpl,r0
	mov	dph,r1
	mov	b,r3
	lcall	__gptrget
	mov	r0,a
	inc	dptr
	lcall	__gptrget
	mov	r1,a
	inc	dptr
	lcall	__gptrget
	mov	a,r0
	orl	a,r1
	pop	ar3
	pop	ar2
	jnz	00133$
	mov	a,r2
	orl	a,r3
	jz	00133$
	cjne	r2,#0x01,00347$
	cjne	r3,#0x00,00347$
	sjmp	00348$
00347$:
	ljmp	00162$
00348$:
00133$:
;	uart.c:216: printf_tiny("\r\n\t\t-----------------------------------------------------------------");
	push	ar3
	push	ar2
	mov	a,#___str_19
	push	acc
	mov	a,#(___str_19 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
	pop	ar2
	pop	ar3
;	uart.c:219: buffers[i].buf_index, (buffers[i].buf_size - buffers[i].buf_index));
	mov	dptr,#__mulint_PARM_2
	mov	a,r2
	movx	@dptr,a
	mov	a,r3
	inc	dptr
	movx	@dptr,a
	mov	dptr,#0x0009
	push	ar3
	push	ar2
	lcall	__mulint
	mov	r0,dpl
	mov	r1,dph
	pop	ar2
	pop	ar3
	push	ar2
	push	ar3
	mov	a,r0
	add	a,_command_sloc4_1_0
	mov	r0,a
	mov	a,r1
	addc	a,(_command_sloc4_1_0 + 1)
	mov	r1,a
	mov	r3,(_command_sloc4_1_0 + 2)
	mov	a,#0x07
	add	a,r0
	mov	r2,a
	clr	a
	addc	a,r1
	mov	r5,a
	mov	ar6,r3
	mov	dpl,r2
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	_command_sloc3_1_0,a
	inc	dptr
	lcall	__gptrget
	mov	(_command_sloc3_1_0 + 1),a
	mov	a,#0x03
	add	a,r0
	mov	r4,a
	clr	a
	addc	a,r1
	mov	r5,a
	mov	ar6,r3
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	_command_sloc1_1_0,a
	inc	dptr
	lcall	__gptrget
	mov	(_command_sloc1_1_0 + 1),a
	mov	a,_command_sloc3_1_0
	clr	c
	subb	a,_command_sloc1_1_0
	mov	_command_sloc2_1_0,a
	mov	a,(_command_sloc3_1_0 + 1)
	subb	a,(_command_sloc1_1_0 + 1)
	mov	(_command_sloc2_1_0 + 1),a
;	uart.c:218: buffers[i].buf_id, &(buffers[i].buffer_pointer[0]), &(buffers[i].buffer_pointer[buffers[i].buf_size - 1]),
	mov	dpl,r0
	mov	dph,r1
	mov	b,r3
	lcall	__gptrget
	mov	_command_sloc0_1_0,a
	inc	dptr
	lcall	__gptrget
	mov	(_command_sloc0_1_0 + 1),a
	inc	dptr
	lcall	__gptrget
	mov	(_command_sloc0_1_0 + 2),a
	mov	a,_command_sloc3_1_0
	add	a,#0xff
	mov	r4,a
	mov	a,(_command_sloc3_1_0 + 1)
	addc	a,#0xff
	mov	r6,a
	mov	a,r4
	add	a,_command_sloc0_1_0
	mov	r4,a
	mov	a,r6
	addc	a,(_command_sloc0_1_0 + 1)
	mov	r6,a
	mov	r5,(_command_sloc0_1_0 + 2)
	mov	a,#0x05
	add	a,r0
	mov	r0,a
	clr	a
	addc	a,r1
	mov	r1,a
	mov	dpl,r0
	mov	dph,r1
	mov	b,r3
	lcall	__gptrget
	mov	r0,a
	inc	dptr
	lcall	__gptrget
	mov	r1,a
;	uart.c:217: printf("\r\n\t\t|%10d |   %11p |%9p |%13d |%11d |",
	push	ar3
	push	ar2
	push	_command_sloc2_1_0
	push	(_command_sloc2_1_0 + 1)
	push	_command_sloc1_1_0
	push	(_command_sloc1_1_0 + 1)
	push	ar4
	push	ar6
	push	ar5
	push	_command_sloc0_1_0
	push	(_command_sloc0_1_0 + 1)
	push	(_command_sloc0_1_0 + 2)
	push	ar0
	push	ar1
	mov	a,#___str_20
	push	acc
	mov	a,#(___str_20 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf1
	mov	sp,a
	pop	ar2
	pop	ar3
;	uart.c:265: putstr("Enter command (+, -, ?, =, @) or input: ");
	pop	ar3
	pop	ar2
;	uart.c:217: printf("\r\n\t\t|%10d |   %11p |%9p |%13d |%11d |",
00162$:
;	uart.c:209: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
	inc	r2
	cjne	r2,#0x00,00349$
	inc	r3
00349$:
	ljmp	00161$
00137$:
;	uart.c:222: printf_tiny("\r\n\t\t-----------------------------------------------------------------\r\n");
	mov	a,#___str_21
	push	acc
	mov	a,#(___str_21 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:224: printf("\r\n\r\n\tBuffer 0 contents: \r\n\r\n");
	mov	a,#___str_22
	push	acc
	mov	a,#(___str_22 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
;	uart.c:225: for (int iBuffer0 = 0; iBuffer0 < buffers[0].buf_index; iBuffer0++)
	mov	r4,_command_sloc4_1_0
	mov	r5,(_command_sloc4_1_0 + 1)
	mov	r6,(_command_sloc4_1_0 + 2)
	mov	a,#0x03
	add	a,_command_sloc4_1_0
	mov	r1,a
	clr	a
	addc	a,(_command_sloc4_1_0 + 1)
	mov	r2,a
	mov	r3,(_command_sloc4_1_0 + 2)
	clr	a
	mov	_command_sloc4_1_0,a
	mov	(_command_sloc4_1_0 + 1),a
00164$:
	push	ar4
	push	ar5
	push	ar6
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r0,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	clr	c
	mov	a,_command_sloc4_1_0
	subb	a,r0
	mov	a,(_command_sloc4_1_0 + 1)
	xrl	a,#0x80
	mov	b,r6
	xrl	b,#0x80
	subb	a,b
	pop	ar6
	pop	ar5
	pop	ar4
	jc	00350$
	ljmp	00140$
00350$:
;	uart.c:227: if (iBuffer0 % 64 == 0)
	mov	dptr,#__modsint_PARM_2
	mov	a,#0x40
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dpl,_command_sloc4_1_0
	mov	dph,(_command_sloc4_1_0 + 1)
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
	orl	a,b
	jnz	00139$
;	uart.c:228: printf("\r\n\t\t");
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
00139$:
;	uart.c:229: printf("%c", buffers[0].buffer_pointer[iBuffer0]);
	push	ar1
	push	ar2
	push	ar3
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	r0,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	mov	a,_command_sloc4_1_0
	add	a,r0
	mov	r0,a
	mov	a,(_command_sloc4_1_0 + 1)
	addc	a,r2
	mov	r2,a
	mov	dpl,r0
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r0,a
	mov	r3,#0x00
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	push	ar0
	push	ar3
	mov	a,#___str_24
	push	acc
	mov	a,#(___str_24 >> 8)
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
;	uart.c:225: for (int iBuffer0 = 0; iBuffer0 < buffers[0].buf_index; iBuffer0++)
	inc	_command_sloc4_1_0
	clr	a
	cjne	a,_command_sloc4_1_0,00352$
	inc	(_command_sloc4_1_0 + 1)
00352$:
	pop	ar3
	pop	ar2
	pop	ar1
	ljmp	00164$
00140$:
;	uart.c:232: buffers[0].buffer_pointer[0] = '\0';
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	inc	dptr
	lcall	__gptrget
	mov	r6,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	clr	a
	lcall	__gptrput
;	uart.c:233: buffers[0].buf_index = 0;
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	uart.c:234: break;
	ljmp	00147$
;	uart.c:237: case '=':
00141$:
;	uart.c:238: putstr("\r\n\r\n\t *** Command for a hexdump ***\r\n");
	mov	dptr,#___str_25
	mov	b,#0x80
	lcall	_putstr
;	uart.c:239: hexdump(buffers[0].buffer_pointer, buffers[0].buf_index);
	mov	dptr,#_command_PARM_2
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
	lcall	__gptrget
	mov	r1,a
	inc	dptr
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	mov	a,#0x03
	add	a,r4
	mov	r4,a
	clr	a
	addc	a,r5
	mov	r5,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	r4,a
	inc	dptr
	lcall	__gptrget
	mov	r5,a
	mov	dptr,#_hexdump_PARM_2
	mov	a,r4
	movx	@dptr,a
	mov	a,r5
	inc	dptr
	movx	@dptr,a
	mov	a,r5
	rlc	a
	subb	a,acc
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	lcall	_hexdump
;	uart.c:240: break;
	ljmp	00147$
;	uart.c:242: case '@':
00142$:
;	uart.c:244: putstr("\r\n\r\n\t *** Command for freeing memory ***\r\n");
	mov	dptr,#___str_26
	mov	b,#0x80
	lcall	_putstr
;	uart.c:245: for (int iBuffer = 0; iBuffer < MAX_NUM_OF_BUFFERS; iBuffer++)
	mov	dptr,#_command_PARM_2
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	mov	r2,#0x00
	mov	r3,#0x00
00167$:
	clr	c
	mov	a,r2
	subb	a,#0xd2
	mov	a,r3
	xrl	a,#0x80
	subb	a,#0x80
	jc	00353$
	ljmp	00145$
00353$:
;	uart.c:247: if (buffers[iBuffer].buffer_pointer != 0)
	mov	dptr,#__mulint_PARM_2
	mov	a,r2
	movx	@dptr,a
	mov	a,r3
	inc	dptr
	movx	@dptr,a
	mov	dptr,#0x0009
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	lcall	__mulint
	mov	r0,dpl
	mov	r1,dph
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	push	ar2
	push	ar3
	mov	a,r0
	add	a,r4
	mov	r0,a
	mov	a,r1
	addc	a,r5
	mov	r1,a
	mov	ar3,r6
	mov	dpl,r0
	mov	dph,r1
	mov	b,r3
	lcall	__gptrget
	mov	_command_sloc4_1_0,a
	inc	dptr
	lcall	__gptrget
	mov	(_command_sloc4_1_0 + 1),a
	inc	dptr
	lcall	__gptrget
	mov	(_command_sloc4_1_0 + 2),a
	pop	ar3
	pop	ar2
	mov	a,_command_sloc4_1_0
	orl	a,(_command_sloc4_1_0 + 1)
	jz	00168$
;	uart.c:248: free(buffers[iBuffer].buffer_pointer);
	push	ar4
	push	ar5
	push	ar6
	mov	r0,_command_sloc4_1_0
	mov	r1,(_command_sloc4_1_0 + 1)
	mov	r6,(_command_sloc4_1_0 + 2)
	mov	dpl,r0
	mov	dph,r1
	mov	b,r6
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	lcall	_free
	pop	ar2
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
;	uart.c:265: putstr("Enter command (+, -, ?, =, @) or input: ");
	pop	ar6
	pop	ar5
	pop	ar4
;	uart.c:248: free(buffers[iBuffer].buffer_pointer);
00168$:
;	uart.c:245: for (int iBuffer = 0; iBuffer < MAX_NUM_OF_BUFFERS; iBuffer++)
	inc	r2
	cjne	r2,#0x00,00355$
	inc	r3
00355$:
	ljmp	00167$
00145$:
;	uart.c:250: printf("\r\n\r\n\t\tMemory has been freed\r\n\r\n");
	mov	a,#___str_27
	push	acc
	mov	a,#(___str_27 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
;	uart.c:251: putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
	mov	dptr,#___str_28
	mov	b,#0x80
	lcall	_putstr
;	uart.c:252: putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
	mov	dptr,#___str_28
	mov	b,#0x80
	lcall	_putstr
;	uart.c:253: main();
	lcall	_main
;	uart.c:254: break;
;	uart.c:257: default:
	sjmp	00147$
00146$:
;	uart.c:258: printf("\r\n\r\n\t Error: Received invalid command '%c'\r\n", received_char);
	mov	r6,#0x00
	push	ar7
	push	ar6
	mov	a,#___str_29
	push	acc
	mov	a,#(___str_29 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
;	uart.c:262: }
00147$:
;	uart.c:264: putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
	mov	dptr,#___str_28
	mov	b,#0x80
	lcall	_putstr
;	uart.c:265: putstr("Enter command (+, -, ?, =, @) or input: ");
	mov	dptr,#___str_30
	mov	b,#0x80
;	uart.c:267: }
	ljmp	_putstr
;------------------------------------------------------------
;Allocation info for local variables in function 'putchar'
;------------------------------------------------------------
;c                         Allocated with name '_putchar_c_65536_105'
;------------------------------------------------------------
;	uart.c:272: int putchar(int c)
;	-----------------------------------------
;	 function putchar
;	-----------------------------------------
_putchar:
	mov	r7,dph
	mov	a,dpl
	mov	dptr,#_putchar_c_65536_105
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:274: while (!TI)
00101$:
;	uart.c:276: TI = 0;
;	assignBit
	jbc	_TI,00114$
	sjmp	00101$
00114$:
;	uart.c:277: SBUF = c; // adding character to Serial buffer
	mov	dptr,#_putchar_c_65536_105
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	mov	_SBUF,r6
;	uart.c:278: return c;
	mov	dpl,r6
	mov	dph,r7
;	uart.c:279: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'getchar'
;------------------------------------------------------------
;	uart.c:288: int getchar() // Function to receive serial data
;	-----------------------------------------
;	 function getchar
;	-----------------------------------------
_getchar:
;	uart.c:290: P1_1 = false;
;	assignBit
	clr	_P1_1
;	uart.c:291: while (!RI)
00101$:
;	uart.c:294: RI = 0;
;	assignBit
	jbc	_RI,00114$
	sjmp	00101$
00114$:
;	uart.c:296: P1_1 = true;
;	assignBit
	setb	_P1_1
;	uart.c:297: return SBUF;
	mov	r6,_SBUF
	mov	r7,#0x00
	mov	dpl,r6
	mov	dph,r7
;	uart.c:298: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'putstr'
;------------------------------------------------------------
;str                       Allocated with name '_putstr_str_65536_108'
;index                     Allocated with name '_putstr_index_65536_109'
;------------------------------------------------------------
;	uart.c:304: int putstr(char *str)
;	-----------------------------------------
;	 function putstr
;	-----------------------------------------
_putstr:
	mov	r7,b
	mov	r6,dph
	mov	a,dpl
	mov	dptr,#_putstr_str_65536_108
	movx	@dptr,a
	mov	a,r6
	inc	dptr
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:307: while (*str)
	mov	dptr,#_putstr_str_65536_108
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
;	uart.c:309: putchar(*str++);
	inc	r5
	cjne	r5,#0x00,00116$
	inc	r6
00116$:
	mov	dptr,#_putstr_str_65536_108
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
;	uart.c:310: index++;
	inc	r3
	cjne	r3,#0x00,00101$
	inc	r4
	sjmp	00101$
00108$:
	mov	dptr,#_putstr_str_65536_108
	mov	a,r5
	movx	@dptr,a
	mov	a,r6
	inc	dptr
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:312: return index + 1;
	inc	r3
	cjne	r3,#0x00,00118$
	inc	r4
00118$:
	mov	dpl,r3
	mov	dph,r4
;	uart.c:313: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'accept_number_from_user'
;------------------------------------------------------------
;received_char             Allocated with name '_accept_number_from_user_received_char_65536_111'
;number_in_char            Allocated with name '_accept_number_from_user_number_in_char_65536_111'
;valid_number_status       Allocated with name '_accept_number_from_user_valid_number_status_65536_111'
;number                    Allocated with name '_accept_number_from_user_number_65536_111'
;i                         Allocated with name '_accept_number_from_user_i_65536_111'
;------------------------------------------------------------
;	uart.c:319: int accept_number_from_user()
;	-----------------------------------------
;	 function accept_number_from_user
;	-----------------------------------------
_accept_number_from_user:
;	uart.c:321: char received_char = '`';
	mov	dptr,#_accept_number_from_user_received_char_65536_111
	mov	a,#0x60
	movx	@dptr,a
;	uart.c:322: char number_in_char[25] = "\0";
	mov	dptr,#_accept_number_from_user_number_in_char_65536_111
	clr	a
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0001)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0002)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0003)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0004)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0005)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0006)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0007)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0008)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0009)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x000a)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x000b)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x000c)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x000d)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x000e)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x000f)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0010)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0011)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0012)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0013)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0014)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0015)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0016)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0017)
	movx	@dptr,a
	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0018)
	movx	@dptr,a
;	uart.c:323: bool valid_number_status = false;
	mov	dptr,#_accept_number_from_user_valid_number_status_65536_111
	movx	@dptr,a
;	uart.c:324: int number = 0;
	mov	dptr,#_accept_number_from_user_number_65536_111
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	uart.c:325: int i = 0;
	mov	dptr,#_accept_number_from_user_i_65536_111
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
;	uart.c:326: while (valid_number_status == false)
00110$:
	mov	dptr,#_accept_number_from_user_valid_number_status_65536_111
	movx	a,@dptr
	jz	00139$
	ljmp	00112$
00139$:
;	uart.c:328: received_char = getchar();
	lcall	_getchar
	mov	r6,dpl
	mov	dptr,#_accept_number_from_user_received_char_65536_111
	mov	a,r6
	movx	@dptr,a
;	uart.c:329: i++;
	mov	dptr,#_accept_number_from_user_i_65536_111
	movx	a,@dptr
	add	a,#0x01
	movx	@dptr,a
	inc	dptr
	movx	a,@dptr
	addc	a,#0x00
	movx	@dptr,a
;	uart.c:330: echo(received_char);
	mov	dpl,r6
	lcall	_echo
;	uart.c:332: if (!(received_char >= '0' && received_char <= '9') && (received_char != '\r'))
	mov	dptr,#_accept_number_from_user_received_char_65536_111
	movx	a,@dptr
	mov	r7,a
	cjne	r7,#0x30,00140$
00140$:
	jc	00107$
	mov	a,r7
	add	a,#0xff - 0x39
	jnc	00104$
00107$:
	mov	dptr,#_accept_number_from_user_received_char_65536_111
	movx	a,@dptr
	mov	r7,a
	cjne	r7,#0x0d,00143$
	sjmp	00104$
00143$:
;	uart.c:335: memset(number_in_char, 0, sizeof(number_in_char));
	mov	dptr,#_memset_PARM_2
	clr	a
	movx	@dptr,a
	mov	dptr,#_memset_PARM_3
	mov	a,#0x19
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_accept_number_from_user_number_in_char_65536_111
	mov	b,#0x00
	lcall	_memset
;	uart.c:336: putstr("\r\n\t\t Error: Re-enter the number: ");
	mov	dptr,#___str_32
	mov	b,#0x80
	lcall	_putstr
;	uart.c:337: i = 0;
	mov	dptr,#_accept_number_from_user_i_65536_111
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	sjmp	00105$
00104$:
;	uart.c:341: else if (received_char == '\r')
	mov	dptr,#_accept_number_from_user_received_char_65536_111
	movx	a,@dptr
	mov	r7,a
	cjne	r7,#0x0d,00105$
;	uart.c:343: strcat(number_in_char, '\0');
	mov	dptr,#_strcat_PARM_2
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_accept_number_from_user_number_in_char_65536_111
	mov	b,#0x00
	lcall	_strcat
;	uart.c:344: number = atoi(number_in_char);
	mov	dptr,#_accept_number_from_user_number_in_char_65536_111
	mov	b,#0x00
	lcall	_atoi
	mov	a,dpl
	mov	b,dph
	mov	dptr,#_accept_number_from_user_number_65536_111
	movx	@dptr,a
	mov	a,b
	inc	dptr
	movx	@dptr,a
;	uart.c:345: valid_number_status = true;
	mov	dptr,#_accept_number_from_user_valid_number_status_65536_111
	mov	a,#0x01
	movx	@dptr,a
00105$:
;	uart.c:348: strncat(number_in_char, &received_char, 1);
	mov	dptr,#_strncat_PARM_2
	mov	a,#_accept_number_from_user_received_char_65536_111
	movx	@dptr,a
	mov	a,#(_accept_number_from_user_received_char_65536_111 >> 8)
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
	mov	dptr,#_accept_number_from_user_number_in_char_65536_111
	mov	b,#0x00
	lcall	_strncat
;	uart.c:350: if (i >= 24)
	mov	dptr,#_accept_number_from_user_i_65536_111
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
;	uart.c:352: putstr("\r\n\t\t Error: Reading a number failed, Reached maximum length supported");
	mov	dptr,#___str_33
	mov	b,#0x80
	lcall	_putstr
;	uart.c:353: putstr("\r\n\t\t Error: Re-enter the number: ");
	mov	dptr,#___str_32
	mov	b,#0x80
	lcall	_putstr
;	uart.c:355: memset(number_in_char, 0, sizeof(number_in_char));
	mov	dptr,#_memset_PARM_2
	clr	a
	movx	@dptr,a
	mov	dptr,#_memset_PARM_3
	mov	a,#0x19
	movx	@dptr,a
	clr	a
	inc	dptr
	movx	@dptr,a
	mov	dptr,#_accept_number_from_user_number_in_char_65536_111
	mov	b,#0x00
	lcall	_memset
;	uart.c:356: i = 0;
	mov	dptr,#_accept_number_from_user_i_65536_111
	clr	a
	movx	@dptr,a
	inc	dptr
	movx	@dptr,a
	ljmp	00110$
00112$:
;	uart.c:359: return number;
	mov	dptr,#_accept_number_from_user_number_65536_111
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
;	uart.c:360: }
	mov	dpl,r6
	mov	dph,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'print_buffers'
;------------------------------------------------------------
;sloc0                     Allocated with name '_print_buffers_sloc0_1_0'
;buffers                   Allocated with name '_print_buffers_buffers_65536_116'
;i                         Allocated with name '_print_buffers_i_131072_118'
;------------------------------------------------------------
;	uart.c:365: void print_buffers(buffer_t *buffers)
;	-----------------------------------------
;	 function print_buffers
;	-----------------------------------------
_print_buffers:
	mov	r7,b
	mov	r6,dph
	mov	a,dpl
	mov	dptr,#_print_buffers_buffers_65536_116
	movx	@dptr,a
	mov	a,r6
	inc	dptr
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:367: printf_tiny("\r\n\r\n\t\t-------------------------");
	mov	a,#___str_8
	push	acc
	mov	a,#(___str_8 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:368: printf_tiny("\r\n\t\t| buffer id |\tsize\t|");
	mov	a,#___str_34
	push	acc
	mov	a,#(___str_34 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:369: printf_tiny("\r\n\t\t-------------------------");
	mov	a,#___str_10
	push	acc
	mov	a,#(___str_10 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:370: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
	mov	dptr,#_print_buffers_buffers_65536_116
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
;	uart.c:372: if ((buffers[i].buffer_pointer != 0) || (i == 0) || (i == 1))
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
;	uart.c:373: printf_tiny("\r\n\t\t|    %d    |\t%d\t|", buffers[i].buf_id, buffers[i].buf_size);
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
	mov	a,#___str_11
	push	acc
	mov	a,#(___str_11 >> 8)
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
;	uart.c:375: printf_tiny("\r\n\t\t-------------------------\r\n");
	pop	ar7
	pop	ar6
	pop	ar5
;	uart.c:373: printf_tiny("\r\n\t\t|    %d    |\t%d\t|", buffers[i].buf_id, buffers[i].buf_size);
00108$:
;	uart.c:370: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
	inc	r0
	cjne	r0,#0x00,00133$
	inc	r1
00133$:
	ljmp	00107$
00105$:
;	uart.c:375: printf_tiny("\r\n\t\t-------------------------\r\n");
	mov	a,#___str_13
	push	acc
	mov	a,#(___str_13 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:376: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'hexdump'
;------------------------------------------------------------
;sloc0                     Allocated with name '_hexdump_sloc0_1_0'
;sloc1                     Allocated with name '_hexdump_sloc1_1_0'
;nbytes                    Allocated with name '_hexdump_PARM_2'
;loc                       Allocated with name '_hexdump_loc_65536_120'
;loc_pointer               Allocated with name '_hexdump_loc_pointer_65536_121'
;hex_byte                  Allocated with name '_hexdump_hex_byte_65536_121'
;address_bytes             Allocated with name '_hexdump_address_bytes_65536_121'
;num                       Allocated with name '_hexdump_num_65536_121'
;total_chars_in_output_string Allocated with name '_hexdump_total_chars_in_output_string_65536_121'
;i                         Allocated with name '_hexdump_i_131072_123'
;j                         Allocated with name '_hexdump_j_327680_126'
;------------------------------------------------------------
;	uart.c:381: void hexdump(const void *loc, long nbytes)
;	-----------------------------------------
;	 function hexdump
;	-----------------------------------------
_hexdump:
	mov	r7,b
	mov	r6,dph
	mov	a,dpl
	mov	dptr,#_hexdump_loc_65536_120
	movx	@dptr,a
	mov	a,r6
	inc	dptr
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:383: const char *loc_pointer = loc;
	mov	dptr,#_hexdump_loc_65536_120
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
;	uart.c:384: char hex_byte[5] = "FF";
	mov	dptr,#_hexdump_hex_byte_65536_121
	mov	a,#0x46
	movx	@dptr,a
	mov	dptr,#(_hexdump_hex_byte_65536_121 + 0x0001)
	movx	@dptr,a
	mov	dptr,#(_hexdump_hex_byte_65536_121 + 0x0002)
	clr	a
	movx	@dptr,a
	mov	dptr,#(_hexdump_hex_byte_65536_121 + 0x0003)
	movx	@dptr,a
	mov	dptr,#(_hexdump_hex_byte_65536_121 + 0x0004)
	movx	@dptr,a
;	uart.c:385: char address_bytes[7] = "0x0000";
	mov	dptr,#_hexdump_address_bytes_65536_121
	mov	a,#0x30
	movx	@dptr,a
	mov	dptr,#(_hexdump_address_bytes_65536_121 + 0x0001)
	mov	a,#0x78
	movx	@dptr,a
	mov	dptr,#(_hexdump_address_bytes_65536_121 + 0x0002)
	mov	a,#0x30
	movx	@dptr,a
	mov	dptr,#(_hexdump_address_bytes_65536_121 + 0x0003)
	movx	@dptr,a
	mov	dptr,#(_hexdump_address_bytes_65536_121 + 0x0004)
	movx	@dptr,a
	mov	dptr,#(_hexdump_address_bytes_65536_121 + 0x0005)
	movx	@dptr,a
	mov	dptr,#(_hexdump_address_bytes_65536_121 + 0x0006)
	clr	a
	movx	@dptr,a
;	uart.c:392: if (nbytes == 0)
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
;	uart.c:394: printf("\r\n\r\n\t\tNo stored characters in the buffer\r\n");
	mov	a,#___str_37
	push	acc
	mov	a,#(___str_37 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	dec	sp
	dec	sp
	dec	sp
;	uart.c:395: return;
	ret
00102$:
;	uart.c:397: printf_tiny("\r\n\r\n\t\t|=======================================================");
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	mov	a,#___str_38
	push	acc
	mov	a,#(___str_38 >> 8)
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
;	uart.c:399: for (int i = 0; i < nbytes; i++)
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
;	uart.c:401: if (i % 16 == 0) // 16 bytes per line
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
;	uart.c:404: uint_to_hexstr(address_bytes, sizeof(address_bytes), (uint16_t)loc_pointer + i, 16); // Converting offset address to hec string
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
	mov	dptr,#_hexdump_address_bytes_65536_121
	mov	b,#0x00
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	lcall	_uint_to_hexstr
;	uart.c:405: printf("|\r\n\t\t| ");
	mov	a,#___str_39
	push	acc
	mov	a,#(___str_39 >> 8)
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
;	uart.c:407: for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
	mov	_hexdump_sloc1_1_0,#0x02
	mov	(_hexdump_sloc1_1_0 + 1),#0x00
;	uart.c:421: printf_tiny("\r\n\t\t|=======================================================|\r\n");
	pop	ar4
	pop	ar3
	pop	ar2
	pop	ar1
;	uart.c:407: for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
00108$:
	clr	c
	mov	a,_hexdump_sloc1_1_0
	subb	a,#0x06
	mov	a,(_hexdump_sloc1_1_0 + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00103$
;	uart.c:409: printf("%c", address_bytes[j]);
	push	ar1
	push	ar2
	push	ar3
	push	ar4
	mov	a,_hexdump_sloc1_1_0
	add	a,#_hexdump_address_bytes_65536_121
	mov	dpl,a
	mov	a,(_hexdump_sloc1_1_0 + 1)
	addc	a,#(_hexdump_address_bytes_65536_121 >> 8)
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
	mov	a,#___str_24
	push	acc
	mov	a,#(___str_24 >> 8)
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
;	uart.c:407: for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
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
;	uart.c:412: printf(": ");
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	mov	a,#___str_40
	push	acc
	mov	a,#(___str_40 >> 8)
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
;	uart.c:414: num = *loc_pointer;
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
;	uart.c:415: uint_to_hexstr(hex_byte, sizeof(hex_byte), num, 8); // conveting each character to hex string
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
	mov	dptr,#_hexdump_hex_byte_65536_121
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
;	uart.c:416: printf("%c", hex_byte[2]);
	mov	dptr,#(_hexdump_hex_byte_65536_121 + 0x0002)
	movx	a,@dptr
	mov	r4,a
	mov	r3,#0x00
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	push	ar4
	push	ar3
	mov	a,#___str_24
	push	acc
	mov	a,#(___str_24 >> 8)
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
;	uart.c:417: printf("%c", hex_byte[3]);
	mov	dptr,#(_hexdump_hex_byte_65536_121 + 0x0003)
	movx	a,@dptr
	mov	r4,a
	mov	r3,#0x00
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	push	ar4
	push	ar3
	mov	a,#___str_24
	push	acc
	mov	a,#(___str_24 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
;	uart.c:418: printf(" ");
	mov	a,#___str_41
	push	acc
	mov	a,#(___str_41 >> 8)
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
;	uart.c:419: loc_pointer++;
;	uart.c:399: for (int i = 0; i < nbytes; i++)
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
;	uart.c:421: printf_tiny("\r\n\t\t|=======================================================|\r\n");
	mov	a,#___str_42
	push	acc
	mov	a,#(___str_42 >> 8)
	push	acc
	lcall	_printf_tiny
	dec	sp
	dec	sp
;	uart.c:422: }
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
;str                       Allocated with name '_uint_to_hexstr_str_65536_128'
;rem                       Allocated with name '_uint_to_hexstr_rem_65536_129'
;total_chars               Allocated with name '_uint_to_hexstr_total_chars_65536_129'
;i                         Allocated with name '_uint_to_hexstr_i_131072_132'
;------------------------------------------------------------
;	uart.c:427: int uint_to_hexstr(char *str, long size, uint16_t num, uint8_t nbits)
;	-----------------------------------------
;	 function uint_to_hexstr
;	-----------------------------------------
_uint_to_hexstr:
	mov	r7,b
	mov	r6,dph
	mov	a,dpl
	mov	dptr,#_uint_to_hexstr_str_65536_128
	movx	@dptr,a
	mov	a,r6
	inc	dptr
	movx	@dptr,a
	mov	a,r7
	inc	dptr
	movx	@dptr,a
;	uart.c:433: if ((nbits != 4) && (nbits != 8) && (nbits != 16) && (nbits != 32))
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
;	uart.c:435: str[0] = '\0';
	mov	dptr,#_uint_to_hexstr_str_65536_128
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
;	uart.c:436: return -1;
	mov	dptr,#0xffff
	ret
00102$:
;	uart.c:439: total_chars = nbits / 4 + 3; // Every nibble requires 4 chars for representation AND +2 for 0x and +1 for \0
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
;	uart.c:442: if (total_chars > size)
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
;	uart.c:444: str[0] = '\0';
	mov	dptr,#_uint_to_hexstr_str_65536_128
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
;	uart.c:445: return -1;
	mov	dptr,#0xffff
	ret
00107$:
;	uart.c:448: str[0] = '0';
	mov	dptr,#_uint_to_hexstr_str_65536_128
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
;	uart.c:449: str[1] = 'x';
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
;	uart.c:450: str[total_chars] = '\0';
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
;	uart.c:453: for (int i = total_chars - 2; i > 1; i--)
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
;	uart.c:455: rem = num % 16;
	mov	dptr,#_uint_to_hexstr_PARM_3
	movx	a,@dptr
	mov	r0,a
	inc	dptr
	movx	a,@dptr
	mov	a,#0x0f
	anl	a,r0
	mov	_uint_to_hexstr_sloc1_1_0,a
	mov	(_uint_to_hexstr_sloc1_1_0 + 1),#0x00
;	uart.c:456: if (rem < 10)
	mov	r6,_uint_to_hexstr_sloc1_1_0
	mov	r7,(_uint_to_hexstr_sloc1_1_0 + 1)
	clr	c
	mov	a,r6
	subb	a,#0x0a
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00109$
;	uart.c:458: str[i] = '0' + rem;
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
;	uart.c:462: str[i] = 'A' + (rem % 10);
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
;	uart.c:467: return total_chars - 1;
	pop	ar3
	pop	ar2
	pop	ar1
;	uart.c:462: str[i] = 'A' + (rem % 10);
00110$:
;	uart.c:464: num = num / 16;
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
;	uart.c:453: for (int i = total_chars - 2; i > 1; i--)
	dec	r4
	cjne	r4,#0xff,00157$
	dec	r5
00157$:
	ljmp	00113$
00111$:
;	uart.c:467: return total_chars - 1;
	mov	a,_uint_to_hexstr_sloc3_1_0
	add	a,#0x02
	mov	r6,a
	clr	a
	addc	a,(_uint_to_hexstr_sloc3_1_0 + 1)
;	uart.c:468: }
	mov	dpl,r6
	mov	dph,a
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area CONST   (CODE)
___str_0:
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x09
	.ascii " *** Command for adding a buffer ***"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_1:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x08
	.ascii "> Specify buffer size to be allocated (30 bytes to 300 bytes"
	.ascii "): "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_2:
	.db 0x09
	.ascii " Error: Invalid size"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_3:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.ascii " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
	.ascii " -"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_4:
	.db 0x09
	.ascii " Error: Out of memory, free some buffers to continue"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_5:
	.db 0x09
	.ascii "Error: buffer could not be added"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_6:
	.db 0x09
	.ascii "Error: Failed allocating memory"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_7:
	.db 0x09
	.ascii "New buffer has been created"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_8:
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
___str_9:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "|buffer id|"
	.db 0x09
	.ascii "size"
	.db 0x09
	.ascii "|"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_10:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "-------------------------"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_11:
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
___str_12:
	.ascii " <----- Newly added"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_13:
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
___str_14:
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x09
	.ascii " *** Command for removing a buffer ***"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_15:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x08
	.ascii "> Specify buffer to be delated (select id from the list): "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_16:
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x09
	.ascii " *** Command for a query ***"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_17:
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "------------------------------------------------------------"
	.ascii "-----"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_18:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "| Buffer id | start-addr | end-addr | nStorageChar | free-sp"
	.ascii "ace |"
	.db 0x09
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_19:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "------------------------------------------------------------"
	.ascii "-----"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_20:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "|%10d |   %11p |%9p |%13d |%11d |"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_21:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "------------------------------------------------------------"
	.ascii "-----"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_22:
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x09
	.ascii "Buffer 0 contents: "
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_23:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_24:
	.ascii "%c"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_25:
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x09
	.ascii " *** Command for a hexdump ***"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_26:
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x09
	.ascii " *** Command for freeing memory ***"
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_27:
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "Memory has been freed"
	.db 0x0d
	.db 0x0a
	.db 0x0d
	.db 0x0a
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_28:
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
___str_29:
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
___str_30:
	.ascii "Enter command (+, -, ?, =, @) or input: "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_32:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii " Error: Re-enter the number: "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_33:
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii " Error: Reading a number failed, Reached maximum length supp"
	.ascii "orted"
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_34:
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
___str_37:
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
___str_38:
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
___str_39:
	.ascii "|"
	.db 0x0d
	.db 0x0a
	.db 0x09
	.db 0x09
	.ascii "| "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_40:
	.ascii ": "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_41:
	.ascii " "
	.db 0x00
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_42:
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
