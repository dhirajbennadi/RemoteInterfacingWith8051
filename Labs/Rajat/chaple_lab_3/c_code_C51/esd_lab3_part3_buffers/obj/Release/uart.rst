                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.9.0 #11195 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module uart
                                      6 	.optsdcc -mmcs51 --model-large
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _printf_tiny
                                     12 	.globl _printf
                                     13 	.globl _memset
                                     14 	.globl _strncat
                                     15 	.globl _strcat
                                     16 	.globl _free
                                     17 	.globl _malloc
                                     18 	.globl _atoi
                                     19 	.globl _main
                                     20 	.globl _CY
                                     21 	.globl _AC
                                     22 	.globl _F0
                                     23 	.globl _RS1
                                     24 	.globl _RS0
                                     25 	.globl _OV
                                     26 	.globl _F1
                                     27 	.globl _P
                                     28 	.globl _PS
                                     29 	.globl _PT1
                                     30 	.globl _PX1
                                     31 	.globl _PT0
                                     32 	.globl _PX0
                                     33 	.globl _RD
                                     34 	.globl _WR
                                     35 	.globl _T1
                                     36 	.globl _T0
                                     37 	.globl _INT1
                                     38 	.globl _INT0
                                     39 	.globl _TXD
                                     40 	.globl _RXD
                                     41 	.globl _P3_7
                                     42 	.globl _P3_6
                                     43 	.globl _P3_5
                                     44 	.globl _P3_4
                                     45 	.globl _P3_3
                                     46 	.globl _P3_2
                                     47 	.globl _P3_1
                                     48 	.globl _P3_0
                                     49 	.globl _EA
                                     50 	.globl _ES
                                     51 	.globl _ET1
                                     52 	.globl _EX1
                                     53 	.globl _ET0
                                     54 	.globl _EX0
                                     55 	.globl _P2_7
                                     56 	.globl _P2_6
                                     57 	.globl _P2_5
                                     58 	.globl _P2_4
                                     59 	.globl _P2_3
                                     60 	.globl _P2_2
                                     61 	.globl _P2_1
                                     62 	.globl _P2_0
                                     63 	.globl _SM0
                                     64 	.globl _SM1
                                     65 	.globl _SM2
                                     66 	.globl _REN
                                     67 	.globl _TB8
                                     68 	.globl _RB8
                                     69 	.globl _TI
                                     70 	.globl _RI
                                     71 	.globl _P1_7
                                     72 	.globl _P1_6
                                     73 	.globl _P1_5
                                     74 	.globl _P1_4
                                     75 	.globl _P1_3
                                     76 	.globl _P1_2
                                     77 	.globl _P1_1
                                     78 	.globl _P1_0
                                     79 	.globl _TF1
                                     80 	.globl _TR1
                                     81 	.globl _TF0
                                     82 	.globl _TR0
                                     83 	.globl _IE1
                                     84 	.globl _IT1
                                     85 	.globl _IE0
                                     86 	.globl _IT0
                                     87 	.globl _P0_7
                                     88 	.globl _P0_6
                                     89 	.globl _P0_5
                                     90 	.globl _P0_4
                                     91 	.globl _P0_3
                                     92 	.globl _P0_2
                                     93 	.globl _P0_1
                                     94 	.globl _P0_0
                                     95 	.globl _B
                                     96 	.globl _ACC
                                     97 	.globl _PSW
                                     98 	.globl _IP
                                     99 	.globl _P3
                                    100 	.globl _IE
                                    101 	.globl _P2
                                    102 	.globl _SBUF
                                    103 	.globl _SCON
                                    104 	.globl _P1
                                    105 	.globl _TH1
                                    106 	.globl _TH0
                                    107 	.globl _TL1
                                    108 	.globl _TL0
                                    109 	.globl _TMOD
                                    110 	.globl _TCON
                                    111 	.globl _PCON
                                    112 	.globl _DPH
                                    113 	.globl _DPL
                                    114 	.globl _SP
                                    115 	.globl _P0
                                    116 	.globl _total_malloced_data
                                    117 	.globl _buf_number
                                    118 	.globl _uint_to_hexstr_PARM_4
                                    119 	.globl _uint_to_hexstr_PARM_3
                                    120 	.globl _uint_to_hexstr_PARM_2
                                    121 	.globl _hexdump_PARM_2
                                    122 	.globl _command_PARM_2
                                    123 	.globl _uart_init
                                    124 	.globl _echo
                                    125 	.globl _command
                                    126 	.globl _putchar
                                    127 	.globl _getchar
                                    128 	.globl _putstr
                                    129 	.globl _accept_number_from_user
                                    130 	.globl _print_buffers
                                    131 	.globl _hexdump
                                    132 	.globl _uint_to_hexstr
                                    133 ;--------------------------------------------------------
                                    134 ; special function registers
                                    135 ;--------------------------------------------------------
                                    136 	.area RSEG    (ABS,DATA)
      000000                        137 	.org 0x0000
                           000080   138 _P0	=	0x0080
                           000081   139 _SP	=	0x0081
                           000082   140 _DPL	=	0x0082
                           000083   141 _DPH	=	0x0083
                           000087   142 _PCON	=	0x0087
                           000088   143 _TCON	=	0x0088
                           000089   144 _TMOD	=	0x0089
                           00008A   145 _TL0	=	0x008a
                           00008B   146 _TL1	=	0x008b
                           00008C   147 _TH0	=	0x008c
                           00008D   148 _TH1	=	0x008d
                           000090   149 _P1	=	0x0090
                           000098   150 _SCON	=	0x0098
                           000099   151 _SBUF	=	0x0099
                           0000A0   152 _P2	=	0x00a0
                           0000A8   153 _IE	=	0x00a8
                           0000B0   154 _P3	=	0x00b0
                           0000B8   155 _IP	=	0x00b8
                           0000D0   156 _PSW	=	0x00d0
                           0000E0   157 _ACC	=	0x00e0
                           0000F0   158 _B	=	0x00f0
                                    159 ;--------------------------------------------------------
                                    160 ; special function bits
                                    161 ;--------------------------------------------------------
                                    162 	.area RSEG    (ABS,DATA)
      000000                        163 	.org 0x0000
                           000080   164 _P0_0	=	0x0080
                           000081   165 _P0_1	=	0x0081
                           000082   166 _P0_2	=	0x0082
                           000083   167 _P0_3	=	0x0083
                           000084   168 _P0_4	=	0x0084
                           000085   169 _P0_5	=	0x0085
                           000086   170 _P0_6	=	0x0086
                           000087   171 _P0_7	=	0x0087
                           000088   172 _IT0	=	0x0088
                           000089   173 _IE0	=	0x0089
                           00008A   174 _IT1	=	0x008a
                           00008B   175 _IE1	=	0x008b
                           00008C   176 _TR0	=	0x008c
                           00008D   177 _TF0	=	0x008d
                           00008E   178 _TR1	=	0x008e
                           00008F   179 _TF1	=	0x008f
                           000090   180 _P1_0	=	0x0090
                           000091   181 _P1_1	=	0x0091
                           000092   182 _P1_2	=	0x0092
                           000093   183 _P1_3	=	0x0093
                           000094   184 _P1_4	=	0x0094
                           000095   185 _P1_5	=	0x0095
                           000096   186 _P1_6	=	0x0096
                           000097   187 _P1_7	=	0x0097
                           000098   188 _RI	=	0x0098
                           000099   189 _TI	=	0x0099
                           00009A   190 _RB8	=	0x009a
                           00009B   191 _TB8	=	0x009b
                           00009C   192 _REN	=	0x009c
                           00009D   193 _SM2	=	0x009d
                           00009E   194 _SM1	=	0x009e
                           00009F   195 _SM0	=	0x009f
                           0000A0   196 _P2_0	=	0x00a0
                           0000A1   197 _P2_1	=	0x00a1
                           0000A2   198 _P2_2	=	0x00a2
                           0000A3   199 _P2_3	=	0x00a3
                           0000A4   200 _P2_4	=	0x00a4
                           0000A5   201 _P2_5	=	0x00a5
                           0000A6   202 _P2_6	=	0x00a6
                           0000A7   203 _P2_7	=	0x00a7
                           0000A8   204 _EX0	=	0x00a8
                           0000A9   205 _ET0	=	0x00a9
                           0000AA   206 _EX1	=	0x00aa
                           0000AB   207 _ET1	=	0x00ab
                           0000AC   208 _ES	=	0x00ac
                           0000AF   209 _EA	=	0x00af
                           0000B0   210 _P3_0	=	0x00b0
                           0000B1   211 _P3_1	=	0x00b1
                           0000B2   212 _P3_2	=	0x00b2
                           0000B3   213 _P3_3	=	0x00b3
                           0000B4   214 _P3_4	=	0x00b4
                           0000B5   215 _P3_5	=	0x00b5
                           0000B6   216 _P3_6	=	0x00b6
                           0000B7   217 _P3_7	=	0x00b7
                           0000B0   218 _RXD	=	0x00b0
                           0000B1   219 _TXD	=	0x00b1
                           0000B2   220 _INT0	=	0x00b2
                           0000B3   221 _INT1	=	0x00b3
                           0000B4   222 _T0	=	0x00b4
                           0000B5   223 _T1	=	0x00b5
                           0000B6   224 _WR	=	0x00b6
                           0000B7   225 _RD	=	0x00b7
                           0000B8   226 _PX0	=	0x00b8
                           0000B9   227 _PT0	=	0x00b9
                           0000BA   228 _PX1	=	0x00ba
                           0000BB   229 _PT1	=	0x00bb
                           0000BC   230 _PS	=	0x00bc
                           0000D0   231 _P	=	0x00d0
                           0000D1   232 _F1	=	0x00d1
                           0000D2   233 _OV	=	0x00d2
                           0000D3   234 _RS0	=	0x00d3
                           0000D4   235 _RS1	=	0x00d4
                           0000D5   236 _F0	=	0x00d5
                           0000D6   237 _AC	=	0x00d6
                           0000D7   238 _CY	=	0x00d7
                                    239 ;--------------------------------------------------------
                                    240 ; overlayable register banks
                                    241 ;--------------------------------------------------------
                                    242 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        243 	.ds 8
                                    244 ;--------------------------------------------------------
                                    245 ; internal ram data
                                    246 ;--------------------------------------------------------
                                    247 	.area DSEG    (DATA)
      000008                        248 _command_sloc0_1_0:
      000008                        249 	.ds 3
      00000B                        250 _command_sloc1_1_0:
      00000B                        251 	.ds 3
      00000E                        252 _command_sloc2_1_0:
      00000E                        253 	.ds 2
      000010                        254 _command_sloc3_1_0:
      000010                        255 	.ds 2
      000012                        256 _command_sloc4_1_0:
      000012                        257 	.ds 3
      000015                        258 _print_buffers_sloc0_1_0:
      000015                        259 	.ds 3
      000018                        260 _hexdump_sloc0_1_0:
      000018                        261 	.ds 2
      00001A                        262 _hexdump_sloc1_1_0:
      00001A                        263 	.ds 2
      00001C                        264 _uint_to_hexstr_sloc0_1_0:
      00001C                        265 	.ds 4
      000020                        266 _uint_to_hexstr_sloc1_1_0:
      000020                        267 	.ds 2
      000022                        268 _uint_to_hexstr_sloc2_1_0:
      000022                        269 	.ds 3
      000025                        270 _uint_to_hexstr_sloc3_1_0:
      000025                        271 	.ds 2
                                    272 ;--------------------------------------------------------
                                    273 ; overlayable items in internal ram 
                                    274 ;--------------------------------------------------------
                                    275 ;--------------------------------------------------------
                                    276 ; indirectly addressable internal ram data
                                    277 ;--------------------------------------------------------
                                    278 	.area ISEG    (DATA)
                                    279 ;--------------------------------------------------------
                                    280 ; absolute internal ram data
                                    281 ;--------------------------------------------------------
                                    282 	.area IABS    (ABS,DATA)
                                    283 	.area IABS    (ABS,DATA)
                                    284 ;--------------------------------------------------------
                                    285 ; bit data
                                    286 ;--------------------------------------------------------
                                    287 	.area BSEG    (BIT)
                                    288 ;--------------------------------------------------------
                                    289 ; paged external ram data
                                    290 ;--------------------------------------------------------
                                    291 	.area PSEG    (PAG,XDATA)
                                    292 ;--------------------------------------------------------
                                    293 ; external ram data
                                    294 ;--------------------------------------------------------
                                    295 	.area XSEG    (XDATA)
      001AF6                        296 _echo_c_65536_74:
      001AF6                        297 	.ds 1
      001AF7                        298 _command_PARM_2:
      001AF7                        299 	.ds 3
      001AFA                        300 _command_received_char_65536_77:
      001AFA                        301 	.ds 1
      001AFB                        302 _command_new_buff_id_65536_78:
      001AFB                        303 	.ds 2
      001AFD                        304 _putchar_c_65536_105:
      001AFD                        305 	.ds 2
      001AFF                        306 _putstr_str_65536_108:
      001AFF                        307 	.ds 3
      001B02                        308 _accept_number_from_user_received_char_65536_111:
      001B02                        309 	.ds 1
      001B03                        310 _accept_number_from_user_number_in_char_65536_111:
      001B03                        311 	.ds 25
      001B1C                        312 _accept_number_from_user_valid_number_status_65536_111:
      001B1C                        313 	.ds 1
      001B1D                        314 _accept_number_from_user_number_65536_111:
      001B1D                        315 	.ds 2
      001B1F                        316 _accept_number_from_user_i_65536_111:
      001B1F                        317 	.ds 2
      001B21                        318 _print_buffers_buffers_65536_116:
      001B21                        319 	.ds 3
      001B24                        320 _hexdump_PARM_2:
      001B24                        321 	.ds 4
      001B28                        322 _hexdump_loc_65536_120:
      001B28                        323 	.ds 3
      001B2B                        324 _hexdump_hex_byte_65536_121:
      001B2B                        325 	.ds 5
      001B30                        326 _hexdump_address_bytes_65536_121:
      001B30                        327 	.ds 7
      001B37                        328 _uint_to_hexstr_PARM_2:
      001B37                        329 	.ds 4
      001B3B                        330 _uint_to_hexstr_PARM_3:
      001B3B                        331 	.ds 2
      001B3D                        332 _uint_to_hexstr_PARM_4:
      001B3D                        333 	.ds 1
      001B3E                        334 _uint_to_hexstr_str_65536_128:
      001B3E                        335 	.ds 3
                                    336 ;--------------------------------------------------------
                                    337 ; absolute external ram data
                                    338 ;--------------------------------------------------------
                                    339 	.area XABS    (ABS,XDATA)
                                    340 ;--------------------------------------------------------
                                    341 ; external initialized ram data
                                    342 ;--------------------------------------------------------
                                    343 	.area XISEG   (XDATA)
      001BBA                        344 _buf_number::
      001BBA                        345 	.ds 2
      001BBC                        346 _total_malloced_data::
      001BBC                        347 	.ds 2
                                    348 	.area HOME    (CODE)
                                    349 	.area GSINIT0 (CODE)
                                    350 	.area GSINIT1 (CODE)
                                    351 	.area GSINIT2 (CODE)
                                    352 	.area GSINIT3 (CODE)
                                    353 	.area GSINIT4 (CODE)
                                    354 	.area GSINIT5 (CODE)
                                    355 	.area GSINIT  (CODE)
                                    356 	.area GSFINAL (CODE)
                                    357 	.area CSEG    (CODE)
                                    358 ;--------------------------------------------------------
                                    359 ; global & static initialisations
                                    360 ;--------------------------------------------------------
                                    361 	.area HOME    (CODE)
                                    362 	.area GSINIT  (CODE)
                                    363 	.area GSFINAL (CODE)
                                    364 	.area GSINIT  (CODE)
                                    365 ;--------------------------------------------------------
                                    366 ; Home
                                    367 ;--------------------------------------------------------
                                    368 	.area HOME    (CODE)
                                    369 	.area HOME    (CODE)
                                    370 ;--------------------------------------------------------
                                    371 ; code
                                    372 ;--------------------------------------------------------
                                    373 	.area CSEG    (CODE)
                                    374 ;------------------------------------------------------------
                                    375 ;Allocation info for local variables in function 'uart_init'
                                    376 ;------------------------------------------------------------
                                    377 ;	uart.c:48: void uart_init()
                                    378 ;	-----------------------------------------
                                    379 ;	 function uart_init
                                    380 ;	-----------------------------------------
      0023CC                        381 _uart_init:
                           000007   382 	ar7 = 0x07
                           000006   383 	ar6 = 0x06
                           000005   384 	ar5 = 0x05
                           000004   385 	ar4 = 0x04
                           000003   386 	ar3 = 0x03
                           000002   387 	ar2 = 0x02
                           000001   388 	ar1 = 0x01
                           000000   389 	ar0 = 0x00
                                    390 ;	uart.c:50: SCON = 0x50; // setting up serial configuration 8bit uart, Receive enabled
      0023CC 75 98 50         [24]  391 	mov	_SCON,#0x50
                                    392 ;	uart.c:51: TMOD = 0x20; // timer1 in mode2, auto-reload
      0023CF 75 89 20         [24]  393 	mov	_TMOD,#0x20
                                    394 ;	uart.c:56: TI = 1;
                                    395 ;	assignBit
      0023D2 D2 99            [12]  396 	setb	_TI
                                    397 ;	uart.c:57: P1_1 = false;
                                    398 ;	assignBit
      0023D4 C2 91            [12]  399 	clr	_P1_1
                                    400 ;	uart.c:58: }
      0023D6 22               [24]  401 	ret
                                    402 ;------------------------------------------------------------
                                    403 ;Allocation info for local variables in function 'echo'
                                    404 ;------------------------------------------------------------
                                    405 ;c                         Allocated with name '_echo_c_65536_74'
                                    406 ;------------------------------------------------------------
                                    407 ;	uart.c:64: void echo(char c)
                                    408 ;	-----------------------------------------
                                    409 ;	 function echo
                                    410 ;	-----------------------------------------
      0023D7                        411 _echo:
      0023D7 E5 82            [12]  412 	mov	a,dpl
      0023D9 90 1A F6         [24]  413 	mov	dptr,#_echo_c_65536_74
      0023DC F0               [24]  414 	movx	@dptr,a
                                    415 ;	uart.c:68: switch ((int8_t)c)
      0023DD E0               [24]  416 	movx	a,@dptr
      0023DE FF               [12]  417 	mov	r7,a
      0023DF FE               [12]  418 	mov	r6,a
      0023E0 BE FF 01         [24]  419 	cjne	r6,#0xff,00120$
      0023E3 22               [24]  420 	ret
      0023E4                        421 00120$:
      0023E4 BE 08 02         [24]  422 	cjne	r6,#0x08,00121$
      0023E7 80 05            [24]  423 	sjmp	00102$
      0023E9                        424 00121$:
                                    425 ;	uart.c:73: case BACKSPACE: // user presses backspace
      0023E9 BE 0D 20         [24]  426 	cjne	r6,#0x0d,00104$
      0023EC 80 12            [24]  427 	sjmp	00103$
      0023EE                        428 00102$:
                                    429 ;	uart.c:74: putchar(BACKSPACE);
      0023EE 90 00 08         [24]  430 	mov	dptr,#0x0008
      0023F1 12 2E 0C         [24]  431 	lcall	_putchar
                                    432 ;	uart.c:75: putchar(' ');
      0023F4 90 00 20         [24]  433 	mov	dptr,#0x0020
      0023F7 12 2E 0C         [24]  434 	lcall	_putchar
                                    435 ;	uart.c:76: putchar(BACKSPACE);
      0023FA 90 00 08         [24]  436 	mov	dptr,#0x0008
                                    437 ;	uart.c:77: break;
                                    438 ;	uart.c:79: case '\r': // user presses enter
      0023FD 02 2E 0C         [24]  439 	ljmp	_putchar
      002400                        440 00103$:
                                    441 ;	uart.c:80: putchar('\r');
      002400 90 00 0D         [24]  442 	mov	dptr,#0x000d
      002403 12 2E 0C         [24]  443 	lcall	_putchar
                                    444 ;	uart.c:81: putchar('\n');
      002406 90 00 0A         [24]  445 	mov	dptr,#0x000a
                                    446 ;	uart.c:82: break;
                                    447 ;	uart.c:84: default:
      002409 02 2E 0C         [24]  448 	ljmp	_putchar
      00240C                        449 00104$:
                                    450 ;	uart.c:85: putchar(c); // echoing received chars
      00240C 7E 00            [12]  451 	mov	r6,#0x00
      00240E 8F 82            [24]  452 	mov	dpl,r7
      002410 8E 83            [24]  453 	mov	dph,r6
                                    454 ;	uart.c:87: }
                                    455 ;	uart.c:88: }
      002412 02 2E 0C         [24]  456 	ljmp	_putchar
                                    457 ;------------------------------------------------------------
                                    458 ;Allocation info for local variables in function 'command'
                                    459 ;------------------------------------------------------------
                                    460 ;sloc0                     Allocated with name '_command_sloc0_1_0'
                                    461 ;sloc1                     Allocated with name '_command_sloc1_1_0'
                                    462 ;sloc2                     Allocated with name '_command_sloc2_1_0'
                                    463 ;sloc3                     Allocated with name '_command_sloc3_1_0'
                                    464 ;sloc4                     Allocated with name '_command_sloc4_1_0'
                                    465 ;buffers                   Allocated with name '_command_PARM_2'
                                    466 ;received_char             Allocated with name '_command_received_char_65536_77'
                                    467 ;new_buff_size             Allocated with name '_command_new_buff_size_65536_78'
                                    468 ;buffer_to_be_deleted      Allocated with name '_command_buffer_to_be_deleted_65536_78'
                                    469 ;new_buff_id               Allocated with name '_command_new_buff_id_65536_78'
                                    470 ;iBuffer                   Allocated with name '_command_iBuffer_196608_80'
                                    471 ;i                         Allocated with name '_command_i_262144_85'
                                    472 ;i                         Allocated with name '_command_i_327680_92'
                                    473 ;i                         Allocated with name '_command_i_196608_95'
                                    474 ;i                         Allocated with name '_command_i_196608_98'
                                    475 ;iBuffer0                  Allocated with name '_command_iBuffer0_196608_101'
                                    476 ;iBuffer                   Allocated with name '_command_iBuffer_196608_103'
                                    477 ;------------------------------------------------------------
                                    478 ;	uart.c:94: void command(char received_char, buffer_t *buffers)
                                    479 ;	-----------------------------------------
                                    480 ;	 function command
                                    481 ;	-----------------------------------------
      002415                        482 _command:
      002415 E5 82            [12]  483 	mov	a,dpl
      002417 90 1A FA         [24]  484 	mov	dptr,#_command_received_char_65536_77
      00241A F0               [24]  485 	movx	@dptr,a
                                    486 ;	uart.c:98: uint16_t new_buff_id = 0;
      00241B 90 1A FB         [24]  487 	mov	dptr,#_command_new_buff_id_65536_78
      00241E E4               [12]  488 	clr	a
      00241F F0               [24]  489 	movx	@dptr,a
      002420 A3               [24]  490 	inc	dptr
      002421 F0               [24]  491 	movx	@dptr,a
                                    492 ;	uart.c:100: if ((received_char >= 'a') && (received_char <= 'z')) // since small letter characters are storage characters and not command characters
      002422 90 1A FA         [24]  493 	mov	dptr,#_command_received_char_65536_77
      002425 E0               [24]  494 	movx	a,@dptr
      002426 FF               [12]  495 	mov	r7,a
      002427 BF 61 00         [24]  496 	cjne	r7,#0x61,00313$
      00242A                        497 00313$:
      00242A 40 06            [24]  498 	jc	00102$
      00242C EF               [12]  499 	mov	a,r7
      00242D 24 85            [12]  500 	add	a,#0xff - 0x7a
      00242F 40 01            [24]  501 	jc	00102$
                                    502 ;	uart.c:101: return;
      002431 22               [24]  503 	ret
      002432                        504 00102$:
                                    505 ;	uart.c:103: switch (received_char)
      002432 90 1A FA         [24]  506 	mov	dptr,#_command_received_char_65536_77
      002435 E0               [24]  507 	movx	a,@dptr
      002436 FF               [12]  508 	mov	r7,a
      002437 BF 2B 02         [24]  509 	cjne	r7,#0x2b,00316$
      00243A 80 1B            [24]  510 	sjmp	00104$
      00243C                        511 00316$:
      00243C BF 2D 03         [24]  512 	cjne	r7,#0x2d,00317$
      00243F 02 28 58         [24]  513 	ljmp	00128$
      002442                        514 00317$:
      002442 BF 3D 03         [24]  515 	cjne	r7,#0x3d,00318$
      002445 02 2C A9         [24]  516 	ljmp	00141$
      002448                        517 00318$:
      002448 BF 3F 03         [24]  518 	cjne	r7,#0x3f,00319$
      00244B 02 29 AD         [24]  519 	ljmp	00132$
      00244E                        520 00319$:
      00244E BF 40 03         [24]  521 	cjne	r7,#0x40,00320$
      002451 02 2D 03         [24]  522 	ljmp	00142$
      002454                        523 00320$:
      002454 02 2D DF         [24]  524 	ljmp	00146$
                                    525 ;	uart.c:107: case '+':
      002457                        526 00104$:
                                    527 ;	uart.c:108: total_malloced_data = 0;
      002457 90 1B BC         [24]  528 	mov	dptr,#_total_malloced_data
      00245A E4               [12]  529 	clr	a
      00245B F0               [24]  530 	movx	@dptr,a
      00245C A3               [24]  531 	inc	dptr
      00245D F0               [24]  532 	movx	@dptr,a
                                    533 ;	uart.c:109: for(int iBuffer = 0; iBuffer < MAX_NUM_OF_BUFFERS; iBuffer++)
      00245E 90 1A F7         [24]  534 	mov	dptr,#_command_PARM_2
      002461 E0               [24]  535 	movx	a,@dptr
      002462 F5 08            [12]  536 	mov	_command_sloc0_1_0,a
      002464 A3               [24]  537 	inc	dptr
      002465 E0               [24]  538 	movx	a,@dptr
      002466 F5 09            [12]  539 	mov	(_command_sloc0_1_0 + 1),a
      002468 A3               [24]  540 	inc	dptr
      002469 E0               [24]  541 	movx	a,@dptr
      00246A F5 0A            [12]  542 	mov	(_command_sloc0_1_0 + 2),a
      00246C 7A 00            [12]  543 	mov	r2,#0x00
      00246E 7B 00            [12]  544 	mov	r3,#0x00
      002470                        545 00149$:
      002470 C3               [12]  546 	clr	c
      002471 EA               [12]  547 	mov	a,r2
      002472 94 D2            [12]  548 	subb	a,#0xd2
      002474 EB               [12]  549 	mov	a,r3
      002475 64 80            [12]  550 	xrl	a,#0x80
      002477 94 80            [12]  551 	subb	a,#0x80
      002479 50 53            [24]  552 	jnc	00105$
                                    553 ;	uart.c:111: total_malloced_data += buffers[iBuffer].buf_size;
      00247B 90 1B 5A         [24]  554 	mov	dptr,#__mulint_PARM_2
      00247E EA               [12]  555 	mov	a,r2
      00247F F0               [24]  556 	movx	@dptr,a
      002480 EB               [12]  557 	mov	a,r3
      002481 A3               [24]  558 	inc	dptr
      002482 F0               [24]  559 	movx	@dptr,a
      002483 90 00 09         [24]  560 	mov	dptr,#0x0009
      002486 C0 03            [24]  561 	push	ar3
      002488 C0 02            [24]  562 	push	ar2
      00248A 12 3A C5         [24]  563 	lcall	__mulint
      00248D A8 82            [24]  564 	mov	r0,dpl
      00248F A9 83            [24]  565 	mov	r1,dph
      002491 D0 02            [24]  566 	pop	ar2
      002493 D0 03            [24]  567 	pop	ar3
      002495 E8               [12]  568 	mov	a,r0
      002496 25 08            [12]  569 	add	a,_command_sloc0_1_0
      002498 F8               [12]  570 	mov	r0,a
      002499 E9               [12]  571 	mov	a,r1
      00249A 35 09            [12]  572 	addc	a,(_command_sloc0_1_0 + 1)
      00249C F9               [12]  573 	mov	r1,a
      00249D AE 0A            [24]  574 	mov	r6,(_command_sloc0_1_0 + 2)
      00249F 74 07            [12]  575 	mov	a,#0x07
      0024A1 28               [12]  576 	add	a,r0
      0024A2 F8               [12]  577 	mov	r0,a
      0024A3 E4               [12]  578 	clr	a
      0024A4 39               [12]  579 	addc	a,r1
      0024A5 F9               [12]  580 	mov	r1,a
      0024A6 88 82            [24]  581 	mov	dpl,r0
      0024A8 89 83            [24]  582 	mov	dph,r1
      0024AA 8E F0            [24]  583 	mov	b,r6
      0024AC 12 49 F6         [24]  584 	lcall	__gptrget
      0024AF F8               [12]  585 	mov	r0,a
      0024B0 A3               [24]  586 	inc	dptr
      0024B1 12 49 F6         [24]  587 	lcall	__gptrget
      0024B4 F9               [12]  588 	mov	r1,a
      0024B5 90 1B BC         [24]  589 	mov	dptr,#_total_malloced_data
      0024B8 E0               [24]  590 	movx	a,@dptr
      0024B9 FD               [12]  591 	mov	r5,a
      0024BA A3               [24]  592 	inc	dptr
      0024BB E0               [24]  593 	movx	a,@dptr
      0024BC FE               [12]  594 	mov	r6,a
      0024BD 90 1B BC         [24]  595 	mov	dptr,#_total_malloced_data
      0024C0 E8               [12]  596 	mov	a,r0
      0024C1 2D               [12]  597 	add	a,r5
      0024C2 F0               [24]  598 	movx	@dptr,a
      0024C3 E9               [12]  599 	mov	a,r1
      0024C4 3E               [12]  600 	addc	a,r6
      0024C5 A3               [24]  601 	inc	dptr
      0024C6 F0               [24]  602 	movx	@dptr,a
                                    603 ;	uart.c:109: for(int iBuffer = 0; iBuffer < MAX_NUM_OF_BUFFERS; iBuffer++)
      0024C7 0A               [12]  604 	inc	r2
      0024C8 BA 00 A5         [24]  605 	cjne	r2,#0x00,00149$
      0024CB 0B               [12]  606 	inc	r3
      0024CC 80 A2            [24]  607 	sjmp	00149$
      0024CE                        608 00105$:
                                    609 ;	uart.c:113: putstr("\r\n\r\n\t *** Command for adding a buffer ***\r\n");
      0024CE 90 4C 38         [24]  610 	mov	dptr,#___str_0
      0024D1 75 F0 80         [24]  611 	mov	b,#0x80
      0024D4 12 2E 3D         [24]  612 	lcall	_putstr
                                    613 ;	uart.c:114: putstr("\r\n\t\b> Specify buffer size to be allocated (30 bytes to 300 bytes): ");
      0024D7 90 4C 64         [24]  614 	mov	dptr,#___str_1
      0024DA 75 F0 80         [24]  615 	mov	b,#0x80
      0024DD 12 2E 3D         [24]  616 	lcall	_putstr
                                    617 ;	uart.c:115: new_buff_size = accept_number_from_user();
      0024E0 12 2E B3         [24]  618 	lcall	_accept_number_from_user
      0024E3 85 82 10         [24]  619 	mov	_command_sloc3_1_0,dpl
      0024E6 85 83 11         [24]  620 	mov	(_command_sloc3_1_0 + 1),dph
                                    621 ;	uart.c:116: total_malloced_data += new_buff_size;
      0024E9 90 1B BC         [24]  622 	mov	dptr,#_total_malloced_data
      0024EC E0               [24]  623 	movx	a,@dptr
      0024ED FB               [12]  624 	mov	r3,a
      0024EE A3               [24]  625 	inc	dptr
      0024EF E0               [24]  626 	movx	a,@dptr
      0024F0 FC               [12]  627 	mov	r4,a
      0024F1 90 1B BC         [24]  628 	mov	dptr,#_total_malloced_data
      0024F4 E5 10            [12]  629 	mov	a,_command_sloc3_1_0
      0024F6 2B               [12]  630 	add	a,r3
      0024F7 F0               [24]  631 	movx	@dptr,a
      0024F8 E5 11            [12]  632 	mov	a,(_command_sloc3_1_0 + 1)
      0024FA 3C               [12]  633 	addc	a,r4
      0024FB A3               [24]  634 	inc	dptr
      0024FC F0               [24]  635 	movx	@dptr,a
                                    636 ;	uart.c:121: if ((new_buff_size < 30) || (new_buff_size > 300))
      0024FD AB 10            [24]  637 	mov	r3,_command_sloc3_1_0
      0024FF AC 11            [24]  638 	mov	r4,(_command_sloc3_1_0 + 1)
      002501 C3               [12]  639 	clr	c
      002502 EB               [12]  640 	mov	a,r3
      002503 94 1E            [12]  641 	subb	a,#0x1e
      002505 EC               [12]  642 	mov	a,r4
      002506 94 00            [12]  643 	subb	a,#0x00
      002508 40 0D            [24]  644 	jc	00124$
      00250A AB 10            [24]  645 	mov	r3,_command_sloc3_1_0
      00250C AC 11            [24]  646 	mov	r4,(_command_sloc3_1_0 + 1)
      00250E C3               [12]  647 	clr	c
      00250F 74 2C            [12]  648 	mov	a,#0x2c
      002511 9B               [12]  649 	subb	a,r3
      002512 74 01            [12]  650 	mov	a,#0x01
      002514 9C               [12]  651 	subb	a,r4
      002515 50 29            [24]  652 	jnc	00125$
      002517                        653 00124$:
                                    654 ;	uart.c:123: putstr("\t Error: Invalid size");
      002517 90 4C A8         [24]  655 	mov	dptr,#___str_2
      00251A 75 F0 80         [24]  656 	mov	b,#0x80
      00251D 12 2E 3D         [24]  657 	lcall	_putstr
                                    658 ;	uart.c:124: putstr("\r\n\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
      002520 90 4C BE         [24]  659 	mov	dptr,#___str_3
      002523 75 F0 80         [24]  660 	mov	b,#0x80
      002526 12 2E 3D         [24]  661 	lcall	_putstr
                                    662 ;	uart.c:125: command('+', buffers); // accepting size again
      002529 90 1A F7         [24]  663 	mov	dptr,#_command_PARM_2
      00252C E5 08            [12]  664 	mov	a,_command_sloc0_1_0
      00252E F0               [24]  665 	movx	@dptr,a
      00252F E5 09            [12]  666 	mov	a,(_command_sloc0_1_0 + 1)
      002531 A3               [24]  667 	inc	dptr
      002532 F0               [24]  668 	movx	@dptr,a
      002533 E5 0A            [12]  669 	mov	a,(_command_sloc0_1_0 + 2)
      002535 A3               [24]  670 	inc	dptr
      002536 F0               [24]  671 	movx	@dptr,a
      002537 75 82 2B         [24]  672 	mov	dpl,#0x2b
      00253A 12 24 15         [24]  673 	lcall	_command
      00253D 02 2D FA         [24]  674 	ljmp	00147$
      002540                        675 00125$:
                                    676 ;	uart.c:127: else if(total_malloced_data > __sdcc_heap_size)
      002540 90 1B BC         [24]  677 	mov	dptr,#_total_malloced_data
      002543 E0               [24]  678 	movx	a,@dptr
      002544 FB               [12]  679 	mov	r3,a
      002545 A3               [24]  680 	inc	dptr
      002546 E0               [24]  681 	movx	a,@dptr
      002547 FC               [12]  682 	mov	r4,a
      002548 90 4A 12         [24]  683 	mov	dptr,#___sdcc_heap_size
      00254B E4               [12]  684 	clr	a
      00254C 93               [24]  685 	movc	a,@a+dptr
      00254D F9               [12]  686 	mov	r1,a
      00254E 74 01            [12]  687 	mov	a,#0x01
      002550 93               [24]  688 	movc	a,@a+dptr
      002551 FA               [12]  689 	mov	r2,a
      002552 C3               [12]  690 	clr	c
      002553 E9               [12]  691 	mov	a,r1
      002554 9B               [12]  692 	subb	a,r3
      002555 EA               [12]  693 	mov	a,r2
      002556 9C               [12]  694 	subb	a,r4
      002557 50 0C            [24]  695 	jnc	00185$
                                    696 ;	uart.c:129: putstr("\t Error: Out of memory, free some buffers to continue");
      002559 90 4D 00         [24]  697 	mov	dptr,#___str_4
      00255C 75 F0 80         [24]  698 	mov	b,#0x80
      00255F 12 2E 3D         [24]  699 	lcall	_putstr
                                    700 ;	uart.c:130: break;
      002562 02 2D FA         [24]  701 	ljmp	00147$
                                    702 ;	uart.c:135: for (int i = 2; i < MAX_NUM_OF_BUFFERS; i++)
      002565                        703 00185$:
      002565 85 08 0B         [24]  704 	mov	_command_sloc1_1_0,_command_sloc0_1_0
      002568 85 09 0C         [24]  705 	mov	(_command_sloc1_1_0 + 1),(_command_sloc0_1_0 + 1)
      00256B 85 0A 0D         [24]  706 	mov	(_command_sloc1_1_0 + 2),(_command_sloc0_1_0 + 2)
      00256E 78 02            [12]  707 	mov	r0,#0x02
      002570 79 00            [12]  708 	mov	r1,#0x00
      002572                        709 00152$:
      002572 C3               [12]  710 	clr	c
      002573 E8               [12]  711 	mov	a,r0
      002574 94 D2            [12]  712 	subb	a,#0xd2
      002576 E9               [12]  713 	mov	a,r1
      002577 64 80            [12]  714 	xrl	a,#0x80
      002579 94 80            [12]  715 	subb	a,#0x80
      00257B 50 5E            [24]  716 	jnc	00110$
                                    717 ;	uart.c:137: if (buffers[i].buffer_pointer == 0)
      00257D 90 1B 5A         [24]  718 	mov	dptr,#__mulint_PARM_2
      002580 E8               [12]  719 	mov	a,r0
      002581 F0               [24]  720 	movx	@dptr,a
      002582 E9               [12]  721 	mov	a,r1
      002583 A3               [24]  722 	inc	dptr
      002584 F0               [24]  723 	movx	@dptr,a
      002585 90 00 09         [24]  724 	mov	dptr,#0x0009
      002588 C0 01            [24]  725 	push	ar1
      00258A C0 00            [24]  726 	push	ar0
      00258C 12 3A C5         [24]  727 	lcall	__mulint
      00258F AD 82            [24]  728 	mov	r5,dpl
      002591 AE 83            [24]  729 	mov	r6,dph
      002593 D0 00            [24]  730 	pop	ar0
      002595 D0 01            [24]  731 	pop	ar1
      002597 ED               [12]  732 	mov	a,r5
      002598 25 0B            [12]  733 	add	a,_command_sloc1_1_0
      00259A FD               [12]  734 	mov	r5,a
      00259B EE               [12]  735 	mov	a,r6
      00259C 35 0C            [12]  736 	addc	a,(_command_sloc1_1_0 + 1)
      00259E FC               [12]  737 	mov	r4,a
      00259F AE 0D            [24]  738 	mov	r6,(_command_sloc1_1_0 + 2)
      0025A1 8D 82            [24]  739 	mov	dpl,r5
      0025A3 8C 83            [24]  740 	mov	dph,r4
      0025A5 8E F0            [24]  741 	mov	b,r6
      0025A7 12 49 F6         [24]  742 	lcall	__gptrget
      0025AA FD               [12]  743 	mov	r5,a
      0025AB A3               [24]  744 	inc	dptr
      0025AC 12 49 F6         [24]  745 	lcall	__gptrget
      0025AF FC               [12]  746 	mov	r4,a
      0025B0 A3               [24]  747 	inc	dptr
      0025B1 12 49 F6         [24]  748 	lcall	__gptrget
      0025B4 FE               [12]  749 	mov	r6,a
      0025B5 ED               [12]  750 	mov	a,r5
      0025B6 4C               [12]  751 	orl	a,r4
      0025B7 70 0A            [24]  752 	jnz	00107$
                                    753 ;	uart.c:139: new_buff_id = i;
      0025B9 90 1A FB         [24]  754 	mov	dptr,#_command_new_buff_id_65536_78
      0025BC E8               [12]  755 	mov	a,r0
      0025BD F0               [24]  756 	movx	@dptr,a
      0025BE E9               [12]  757 	mov	a,r1
      0025BF A3               [24]  758 	inc	dptr
      0025C0 F0               [24]  759 	movx	@dptr,a
                                    760 ;	uart.c:140: break;
      0025C1 80 18            [24]  761 	sjmp	00110$
      0025C3                        762 00107$:
                                    763 ;	uart.c:142: if (i == MAX_NUM_OF_BUFFERS - 1)
      0025C3 B8 D1 0E         [24]  764 	cjne	r0,#0xd1,00153$
      0025C6 B9 00 0B         [24]  765 	cjne	r1,#0x00,00153$
                                    766 ;	uart.c:144: putstr("\tError: buffer could not be added\r\n");
      0025C9 90 4D 36         [24]  767 	mov	dptr,#___str_5
      0025CC 75 F0 80         [24]  768 	mov	b,#0x80
      0025CF 12 2E 3D         [24]  769 	lcall	_putstr
                                    770 ;	uart.c:145: break;
      0025D2 80 07            [24]  771 	sjmp	00110$
      0025D4                        772 00153$:
                                    773 ;	uart.c:135: for (int i = 2; i < MAX_NUM_OF_BUFFERS; i++)
      0025D4 08               [12]  774 	inc	r0
      0025D5 B8 00 9A         [24]  775 	cjne	r0,#0x00,00152$
      0025D8 09               [12]  776 	inc	r1
      0025D9 80 97            [24]  777 	sjmp	00152$
      0025DB                        778 00110$:
                                    779 ;	uart.c:149: buffers[new_buff_id].buffer_pointer = (char *)malloc(sizeof(char) * new_buff_size);
      0025DB AA 08            [24]  780 	mov	r2,_command_sloc0_1_0
      0025DD AB 09            [24]  781 	mov	r3,(_command_sloc0_1_0 + 1)
      0025DF AC 0A            [24]  782 	mov	r4,(_command_sloc0_1_0 + 2)
      0025E1 90 1A FB         [24]  783 	mov	dptr,#_command_new_buff_id_65536_78
      0025E4 E0               [24]  784 	movx	a,@dptr
      0025E5 F5 0E            [12]  785 	mov	_command_sloc2_1_0,a
      0025E7 A3               [24]  786 	inc	dptr
      0025E8 E0               [24]  787 	movx	a,@dptr
      0025E9 F5 0F            [12]  788 	mov	(_command_sloc2_1_0 + 1),a
      0025EB 90 1B 5A         [24]  789 	mov	dptr,#__mulint_PARM_2
      0025EE E5 0E            [12]  790 	mov	a,_command_sloc2_1_0
      0025F0 F0               [24]  791 	movx	@dptr,a
      0025F1 E5 0F            [12]  792 	mov	a,(_command_sloc2_1_0 + 1)
      0025F3 A3               [24]  793 	inc	dptr
      0025F4 F0               [24]  794 	movx	@dptr,a
      0025F5 90 00 09         [24]  795 	mov	dptr,#0x0009
      0025F8 C0 04            [24]  796 	push	ar4
      0025FA C0 03            [24]  797 	push	ar3
      0025FC C0 02            [24]  798 	push	ar2
      0025FE 12 3A C5         [24]  799 	lcall	__mulint
      002601 85 82 0B         [24]  800 	mov	_command_sloc1_1_0,dpl
      002604 85 83 0C         [24]  801 	mov	(_command_sloc1_1_0 + 1),dph
      002607 E5 0B            [12]  802 	mov	a,_command_sloc1_1_0
      002609 25 08            [12]  803 	add	a,_command_sloc0_1_0
      00260B F5 12            [12]  804 	mov	_command_sloc4_1_0,a
      00260D E5 0C            [12]  805 	mov	a,(_command_sloc1_1_0 + 1)
      00260F 35 09            [12]  806 	addc	a,(_command_sloc0_1_0 + 1)
      002611 F5 13            [12]  807 	mov	(_command_sloc4_1_0 + 1),a
      002613 85 0A 14         [24]  808 	mov	(_command_sloc4_1_0 + 2),(_command_sloc0_1_0 + 2)
      002616 85 10 82         [24]  809 	mov	dpl,_command_sloc3_1_0
      002619 85 11 83         [24]  810 	mov	dph,(_command_sloc3_1_0 + 1)
      00261C 12 3B 21         [24]  811 	lcall	_malloc
      00261F AD 82            [24]  812 	mov	r5,dpl
      002621 AE 83            [24]  813 	mov	r6,dph
      002623 D0 02            [24]  814 	pop	ar2
      002625 D0 03            [24]  815 	pop	ar3
      002627 D0 04            [24]  816 	pop	ar4
      002629 8E 01            [24]  817 	mov	ar1,r6
      00262B 7E 00            [12]  818 	mov	r6,#0x00
      00262D 85 12 82         [24]  819 	mov	dpl,_command_sloc4_1_0
      002630 85 13 83         [24]  820 	mov	dph,(_command_sloc4_1_0 + 1)
      002633 85 14 F0         [24]  821 	mov	b,(_command_sloc4_1_0 + 2)
      002636 ED               [12]  822 	mov	a,r5
      002637 12 39 A1         [24]  823 	lcall	__gptrput
      00263A A3               [24]  824 	inc	dptr
      00263B E9               [12]  825 	mov	a,r1
      00263C 12 39 A1         [24]  826 	lcall	__gptrput
      00263F A3               [24]  827 	inc	dptr
      002640 EE               [12]  828 	mov	a,r6
      002641 12 39 A1         [24]  829 	lcall	__gptrput
                                    830 ;	uart.c:150: if (buffers[new_buff_id].buffer_pointer == NULL)
      002644 ED               [12]  831 	mov	a,r5
      002645 49               [12]  832 	orl	a,r1
      002646 70 0C            [24]  833 	jnz	00112$
                                    834 ;	uart.c:152: putstr("\tError: Failed allocating memory\r\n");
      002648 90 4D 5A         [24]  835 	mov	dptr,#___str_6
      00264B 75 F0 80         [24]  836 	mov	b,#0x80
      00264E 12 2E 3D         [24]  837 	lcall	_putstr
                                    838 ;	uart.c:153: break;
      002651 02 2D FA         [24]  839 	ljmp	00147$
      002654                        840 00112$:
                                    841 ;	uart.c:157: putstr("\tNew buffer has been created\r\n");
      002654 C0 02            [24]  842 	push	ar2
      002656 C0 03            [24]  843 	push	ar3
      002658 C0 04            [24]  844 	push	ar4
      00265A 90 4D 7D         [24]  845 	mov	dptr,#___str_7
      00265D 75 F0 80         [24]  846 	mov	b,#0x80
      002660 C0 04            [24]  847 	push	ar4
      002662 C0 03            [24]  848 	push	ar3
      002664 C0 02            [24]  849 	push	ar2
      002666 12 2E 3D         [24]  850 	lcall	_putstr
      002669 D0 02            [24]  851 	pop	ar2
      00266B D0 03            [24]  852 	pop	ar3
      00266D D0 04            [24]  853 	pop	ar4
                                    854 ;	uart.c:160: buffers[new_buff_id].buf_id = new_buff_id;
      00266F E5 0B            [12]  855 	mov	a,_command_sloc1_1_0
      002671 25 08            [12]  856 	add	a,_command_sloc0_1_0
      002673 F9               [12]  857 	mov	r1,a
      002674 E5 0C            [12]  858 	mov	a,(_command_sloc1_1_0 + 1)
      002676 35 09            [12]  859 	addc	a,(_command_sloc0_1_0 + 1)
      002678 FD               [12]  860 	mov	r5,a
      002679 AE 0A            [24]  861 	mov	r6,(_command_sloc0_1_0 + 2)
      00267B 74 05            [12]  862 	mov	a,#0x05
      00267D 29               [12]  863 	add	a,r1
      00267E F8               [12]  864 	mov	r0,a
      00267F E4               [12]  865 	clr	a
      002680 3D               [12]  866 	addc	a,r5
      002681 FB               [12]  867 	mov	r3,a
      002682 8E 04            [24]  868 	mov	ar4,r6
      002684 88 82            [24]  869 	mov	dpl,r0
      002686 8B 83            [24]  870 	mov	dph,r3
      002688 8C F0            [24]  871 	mov	b,r4
      00268A E5 0E            [12]  872 	mov	a,_command_sloc2_1_0
      00268C 12 39 A1         [24]  873 	lcall	__gptrput
      00268F A3               [24]  874 	inc	dptr
      002690 E5 0F            [12]  875 	mov	a,(_command_sloc2_1_0 + 1)
      002692 12 39 A1         [24]  876 	lcall	__gptrput
                                    877 ;	uart.c:161: buffers[new_buff_id].buf_size = new_buff_size;
      002695 74 07            [12]  878 	mov	a,#0x07
      002697 29               [12]  879 	add	a,r1
      002698 FA               [12]  880 	mov	r2,a
      002699 E4               [12]  881 	clr	a
      00269A 3D               [12]  882 	addc	a,r5
      00269B FB               [12]  883 	mov	r3,a
      00269C 8E 04            [24]  884 	mov	ar4,r6
      00269E 8A 82            [24]  885 	mov	dpl,r2
      0026A0 8B 83            [24]  886 	mov	dph,r3
      0026A2 8C F0            [24]  887 	mov	b,r4
      0026A4 E5 10            [12]  888 	mov	a,_command_sloc3_1_0
      0026A6 12 39 A1         [24]  889 	lcall	__gptrput
      0026A9 A3               [24]  890 	inc	dptr
      0026AA E5 11            [12]  891 	mov	a,(_command_sloc3_1_0 + 1)
      0026AC 12 39 A1         [24]  892 	lcall	__gptrput
                                    893 ;	uart.c:162: buffers[new_buff_id].buf_index = 0;
      0026AF 74 03            [12]  894 	mov	a,#0x03
      0026B1 29               [12]  895 	add	a,r1
      0026B2 F9               [12]  896 	mov	r1,a
      0026B3 E4               [12]  897 	clr	a
      0026B4 3D               [12]  898 	addc	a,r5
      0026B5 FD               [12]  899 	mov	r5,a
      0026B6 89 82            [24]  900 	mov	dpl,r1
      0026B8 8D 83            [24]  901 	mov	dph,r5
      0026BA 8E F0            [24]  902 	mov	b,r6
      0026BC E4               [12]  903 	clr	a
      0026BD 12 39 A1         [24]  904 	lcall	__gptrput
      0026C0 A3               [24]  905 	inc	dptr
      0026C1 12 39 A1         [24]  906 	lcall	__gptrput
                                    907 ;	uart.c:166: printf_tiny("\r\n\r\n\t\t-------------------------");
      0026C4 C0 04            [24]  908 	push	ar4
      0026C6 C0 03            [24]  909 	push	ar3
      0026C8 C0 02            [24]  910 	push	ar2
      0026CA 74 9C            [12]  911 	mov	a,#___str_8
      0026CC C0 E0            [24]  912 	push	acc
      0026CE 74 4D            [12]  913 	mov	a,#(___str_8 >> 8)
      0026D0 C0 E0            [24]  914 	push	acc
      0026D2 12 39 BC         [24]  915 	lcall	_printf_tiny
      0026D5 15 81            [12]  916 	dec	sp
      0026D7 15 81            [12]  917 	dec	sp
                                    918 ;	uart.c:167: printf_tiny("\r\n\t\t|buffer id|\tsize\t|");
      0026D9 74 BC            [12]  919 	mov	a,#___str_9
      0026DB C0 E0            [24]  920 	push	acc
      0026DD 74 4D            [12]  921 	mov	a,#(___str_9 >> 8)
      0026DF C0 E0            [24]  922 	push	acc
      0026E1 12 39 BC         [24]  923 	lcall	_printf_tiny
      0026E4 15 81            [12]  924 	dec	sp
      0026E6 15 81            [12]  925 	dec	sp
                                    926 ;	uart.c:168: printf_tiny("\r\n\t\t-------------------------");
      0026E8 74 D3            [12]  927 	mov	a,#___str_10
      0026EA C0 E0            [24]  928 	push	acc
      0026EC 74 4D            [12]  929 	mov	a,#(___str_10 >> 8)
      0026EE C0 E0            [24]  930 	push	acc
      0026F0 12 39 BC         [24]  931 	lcall	_printf_tiny
      0026F3 15 81            [12]  932 	dec	sp
      0026F5 15 81            [12]  933 	dec	sp
      0026F7 D0 02            [24]  934 	pop	ar2
      0026F9 D0 03            [24]  935 	pop	ar3
      0026FB D0 04            [24]  936 	pop	ar4
                                    937 ;	uart.c:169: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
      0026FD 85 0E 12         [24]  938 	mov	_command_sloc4_1_0,_command_sloc2_1_0
      002700 85 0F 13         [24]  939 	mov	(_command_sloc4_1_0 + 1),(_command_sloc2_1_0 + 1)
      002703 E4               [12]  940 	clr	a
      002704 F5 10            [12]  941 	mov	_command_sloc3_1_0,a
      002706 F5 11            [12]  942 	mov	(_command_sloc3_1_0 + 1),a
                                    943 ;	uart.c:265: putstr("Enter command (+, -, ?, =, @) or input: ");
      002708 D0 04            [24]  944 	pop	ar4
      00270A D0 03            [24]  945 	pop	ar3
      00270C D0 02            [24]  946 	pop	ar2
                                    947 ;	uart.c:169: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
      00270E                        948 00155$:
      00270E C3               [12]  949 	clr	c
      00270F E5 10            [12]  950 	mov	a,_command_sloc3_1_0
      002711 94 D2            [12]  951 	subb	a,#0xd2
      002713 E5 11            [12]  952 	mov	a,(_command_sloc3_1_0 + 1)
      002715 64 80            [12]  953 	xrl	a,#0x80
      002717 94 80            [12]  954 	subb	a,#0x80
      002719 40 03            [24]  955 	jc	00332$
      00271B 02 28 46         [24]  956 	ljmp	00120$
      00271E                        957 00332$:
                                    958 ;	uart.c:171: if ((buffers[i].buffer_pointer != 0) || (i == 0) || (i == 1))
      00271E 90 1B 5A         [24]  959 	mov	dptr,#__mulint_PARM_2
      002721 E5 10            [12]  960 	mov	a,_command_sloc3_1_0
      002723 F0               [24]  961 	movx	@dptr,a
      002724 E5 11            [12]  962 	mov	a,(_command_sloc3_1_0 + 1)
      002726 A3               [24]  963 	inc	dptr
      002727 F0               [24]  964 	movx	@dptr,a
      002728 90 00 09         [24]  965 	mov	dptr,#0x0009
      00272B C0 04            [24]  966 	push	ar4
      00272D C0 03            [24]  967 	push	ar3
      00272F C0 02            [24]  968 	push	ar2
      002731 12 3A C5         [24]  969 	lcall	__mulint
      002734 AD 82            [24]  970 	mov	r5,dpl
      002736 AE 83            [24]  971 	mov	r6,dph
      002738 D0 02            [24]  972 	pop	ar2
      00273A D0 03            [24]  973 	pop	ar3
      00273C D0 04            [24]  974 	pop	ar4
      00273E ED               [12]  975 	mov	a,r5
      00273F 2A               [12]  976 	add	a,r2
      002740 FD               [12]  977 	mov	r5,a
      002741 EE               [12]  978 	mov	a,r6
      002742 3B               [12]  979 	addc	a,r3
      002743 F9               [12]  980 	mov	r1,a
      002744 8C 06            [24]  981 	mov	ar6,r4
      002746 8D 82            [24]  982 	mov	dpl,r5
      002748 89 83            [24]  983 	mov	dph,r1
      00274A 8E F0            [24]  984 	mov	b,r6
      00274C 12 49 F6         [24]  985 	lcall	__gptrget
      00274F FD               [12]  986 	mov	r5,a
      002750 A3               [24]  987 	inc	dptr
      002751 12 49 F6         [24]  988 	lcall	__gptrget
      002754 F9               [12]  989 	mov	r1,a
      002755 A3               [24]  990 	inc	dptr
      002756 12 49 F6         [24]  991 	lcall	__gptrget
      002759 FE               [12]  992 	mov	r6,a
      00275A ED               [12]  993 	mov	a,r5
      00275B 49               [12]  994 	orl	a,r1
      00275C 70 14            [24]  995 	jnz	00116$
      00275E E5 10            [12]  996 	mov	a,_command_sloc3_1_0
      002760 45 11            [12]  997 	orl	a,(_command_sloc3_1_0 + 1)
      002762 60 0E            [24]  998 	jz	00116$
      002764 74 01            [12]  999 	mov	a,#0x01
      002766 B5 10 06         [24] 1000 	cjne	a,_command_sloc3_1_0,00335$
      002769 14               [12] 1001 	dec	a
      00276A B5 11 02         [24] 1002 	cjne	a,(_command_sloc3_1_0 + 1),00335$
      00276D 80 03            [24] 1003 	sjmp	00336$
      00276F                       1004 00335$:
      00276F 02 28 3B         [24] 1005 	ljmp	00156$
      002772                       1006 00336$:
      002772                       1007 00116$:
                                   1008 ;	uart.c:173: printf_tiny("\r\n\t\t|    %d    |\t%d\t|", buffers[i].buf_id, buffers[i].buf_size);
      002772 90 1B 5A         [24] 1009 	mov	dptr,#__mulint_PARM_2
      002775 E5 10            [12] 1010 	mov	a,_command_sloc3_1_0
      002777 F0               [24] 1011 	movx	@dptr,a
      002778 E5 11            [12] 1012 	mov	a,(_command_sloc3_1_0 + 1)
      00277A A3               [24] 1013 	inc	dptr
      00277B F0               [24] 1014 	movx	@dptr,a
      00277C 90 00 09         [24] 1015 	mov	dptr,#0x0009
      00277F C0 04            [24] 1016 	push	ar4
      002781 C0 03            [24] 1017 	push	ar3
      002783 C0 02            [24] 1018 	push	ar2
      002785 12 3A C5         [24] 1019 	lcall	__mulint
      002788 AD 82            [24] 1020 	mov	r5,dpl
      00278A AE 83            [24] 1021 	mov	r6,dph
      00278C D0 02            [24] 1022 	pop	ar2
      00278E D0 03            [24] 1023 	pop	ar3
      002790 D0 04            [24] 1024 	pop	ar4
      002792 ED               [12] 1025 	mov	a,r5
      002793 2A               [12] 1026 	add	a,r2
      002794 FD               [12] 1027 	mov	r5,a
      002795 EE               [12] 1028 	mov	a,r6
      002796 3B               [12] 1029 	addc	a,r3
      002797 F9               [12] 1030 	mov	r1,a
      002798 8C 06            [24] 1031 	mov	ar6,r4
      00279A C0 02            [24] 1032 	push	ar2
      00279C C0 03            [24] 1033 	push	ar3
      00279E C0 04            [24] 1034 	push	ar4
      0027A0 74 07            [12] 1035 	mov	a,#0x07
      0027A2 2D               [12] 1036 	add	a,r5
      0027A3 F8               [12] 1037 	mov	r0,a
      0027A4 E4               [12] 1038 	clr	a
      0027A5 39               [12] 1039 	addc	a,r1
      0027A6 FB               [12] 1040 	mov	r3,a
      0027A7 8E 04            [24] 1041 	mov	ar4,r6
      0027A9 88 82            [24] 1042 	mov	dpl,r0
      0027AB 8B 83            [24] 1043 	mov	dph,r3
      0027AD 8C F0            [24] 1044 	mov	b,r4
      0027AF 12 49 F6         [24] 1045 	lcall	__gptrget
      0027B2 F8               [12] 1046 	mov	r0,a
      0027B3 A3               [24] 1047 	inc	dptr
      0027B4 12 49 F6         [24] 1048 	lcall	__gptrget
      0027B7 FB               [12] 1049 	mov	r3,a
      0027B8 74 05            [12] 1050 	mov	a,#0x05
      0027BA 2D               [12] 1051 	add	a,r5
      0027BB FD               [12] 1052 	mov	r5,a
      0027BC E4               [12] 1053 	clr	a
      0027BD 39               [12] 1054 	addc	a,r1
      0027BE F9               [12] 1055 	mov	r1,a
      0027BF 8D 82            [24] 1056 	mov	dpl,r5
      0027C1 89 83            [24] 1057 	mov	dph,r1
      0027C3 8E F0            [24] 1058 	mov	b,r6
      0027C5 12 49 F6         [24] 1059 	lcall	__gptrget
      0027C8 FA               [12] 1060 	mov	r2,a
      0027C9 A3               [24] 1061 	inc	dptr
      0027CA 12 49 F6         [24] 1062 	lcall	__gptrget
      0027CD FC               [12] 1063 	mov	r4,a
      0027CE C0 06            [24] 1064 	push	ar6
      0027D0 C0 05            [24] 1065 	push	ar5
      0027D2 C0 04            [24] 1066 	push	ar4
      0027D4 C0 03            [24] 1067 	push	ar3
      0027D6 C0 02            [24] 1068 	push	ar2
      0027D8 C0 01            [24] 1069 	push	ar1
      0027DA C0 00            [24] 1070 	push	ar0
      0027DC C0 03            [24] 1071 	push	ar3
      0027DE C0 02            [24] 1072 	push	ar2
      0027E0 C0 04            [24] 1073 	push	ar4
      0027E2 74 F1            [12] 1074 	mov	a,#___str_11
      0027E4 C0 E0            [24] 1075 	push	acc
      0027E6 74 4D            [12] 1076 	mov	a,#(___str_11 >> 8)
      0027E8 C0 E0            [24] 1077 	push	acc
      0027EA 12 39 BC         [24] 1078 	lcall	_printf_tiny
      0027ED E5 81            [12] 1079 	mov	a,sp
      0027EF 24 FA            [12] 1080 	add	a,#0xfa
      0027F1 F5 81            [12] 1081 	mov	sp,a
      0027F3 D0 01            [24] 1082 	pop	ar1
      0027F5 D0 02            [24] 1083 	pop	ar2
      0027F7 D0 03            [24] 1084 	pop	ar3
      0027F9 D0 04            [24] 1085 	pop	ar4
      0027FB D0 05            [24] 1086 	pop	ar5
      0027FD D0 06            [24] 1087 	pop	ar6
                                   1088 ;	uart.c:174: if (buffers[i].buf_id == new_buff_id)
      0027FF 8D 82            [24] 1089 	mov	dpl,r5
      002801 89 83            [24] 1090 	mov	dph,r1
      002803 8E F0            [24] 1091 	mov	b,r6
      002805 12 49 F6         [24] 1092 	lcall	__gptrget
      002808 FD               [12] 1093 	mov	r5,a
      002809 A3               [24] 1094 	inc	dptr
      00280A 12 49 F6         [24] 1095 	lcall	__gptrget
      00280D F9               [12] 1096 	mov	r1,a
      00280E ED               [12] 1097 	mov	a,r5
      00280F B5 12 06         [24] 1098 	cjne	a,_command_sloc4_1_0,00337$
      002812 E9               [12] 1099 	mov	a,r1
      002813 B5 13 02         [24] 1100 	cjne	a,(_command_sloc4_1_0 + 1),00337$
      002816 80 08            [24] 1101 	sjmp	00338$
      002818                       1102 00337$:
      002818 D0 04            [24] 1103 	pop	ar4
      00281A D0 03            [24] 1104 	pop	ar3
      00281C D0 02            [24] 1105 	pop	ar2
      00281E 80 1B            [24] 1106 	sjmp	00156$
      002820                       1107 00338$:
      002820 D0 04            [24] 1108 	pop	ar4
      002822 D0 03            [24] 1109 	pop	ar3
      002824 D0 02            [24] 1110 	pop	ar2
                                   1111 ;	uart.c:175: putstr(" <----- Newly added");
      002826 90 4E 07         [24] 1112 	mov	dptr,#___str_12
      002829 75 F0 80         [24] 1113 	mov	b,#0x80
      00282C C0 04            [24] 1114 	push	ar4
      00282E C0 03            [24] 1115 	push	ar3
      002830 C0 02            [24] 1116 	push	ar2
      002832 12 2E 3D         [24] 1117 	lcall	_putstr
      002835 D0 02            [24] 1118 	pop	ar2
      002837 D0 03            [24] 1119 	pop	ar3
      002839 D0 04            [24] 1120 	pop	ar4
      00283B                       1121 00156$:
                                   1122 ;	uart.c:169: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
      00283B 05 10            [12] 1123 	inc	_command_sloc3_1_0
      00283D E4               [12] 1124 	clr	a
      00283E B5 10 02         [24] 1125 	cjne	a,_command_sloc3_1_0,00339$
      002841 05 11            [12] 1126 	inc	(_command_sloc3_1_0 + 1)
      002843                       1127 00339$:
      002843 02 27 0E         [24] 1128 	ljmp	00155$
      002846                       1129 00120$:
                                   1130 ;	uart.c:178: printf_tiny("\r\n\t\t-------------------------\r\n");
      002846 74 1B            [12] 1131 	mov	a,#___str_13
      002848 C0 E0            [24] 1132 	push	acc
      00284A 74 4E            [12] 1133 	mov	a,#(___str_13 >> 8)
      00284C C0 E0            [24] 1134 	push	acc
      00284E 12 39 BC         [24] 1135 	lcall	_printf_tiny
      002851 15 81            [12] 1136 	dec	sp
      002853 15 81            [12] 1137 	dec	sp
                                   1138 ;	uart.c:182: break;
      002855 02 2D FA         [24] 1139 	ljmp	00147$
                                   1140 ;	uart.c:185: case '-':
      002858                       1141 00128$:
                                   1142 ;	uart.c:186: putstr("\r\n\r\n\t *** Command for removing a buffer ***\r\n");
      002858 90 4E 3B         [24] 1143 	mov	dptr,#___str_14
      00285B 75 F0 80         [24] 1144 	mov	b,#0x80
      00285E 12 2E 3D         [24] 1145 	lcall	_putstr
                                   1146 ;	uart.c:187: print_buffers(buffers);
      002861 90 1A F7         [24] 1147 	mov	dptr,#_command_PARM_2
      002864 E0               [24] 1148 	movx	a,@dptr
      002865 FC               [12] 1149 	mov	r4,a
      002866 A3               [24] 1150 	inc	dptr
      002867 E0               [24] 1151 	movx	a,@dptr
      002868 FD               [12] 1152 	mov	r5,a
      002869 A3               [24] 1153 	inc	dptr
      00286A E0               [24] 1154 	movx	a,@dptr
      00286B FE               [12] 1155 	mov	r6,a
      00286C 8C 82            [24] 1156 	mov	dpl,r4
      00286E 8D 83            [24] 1157 	mov	dph,r5
      002870 8E F0            [24] 1158 	mov	b,r6
      002872 12 30 3D         [24] 1159 	lcall	_print_buffers
                                   1160 ;	uart.c:188: putstr("\r\n\t\b> Specify buffer to be delated (select id from the list): ");
      002875 90 4E 69         [24] 1161 	mov	dptr,#___str_15
      002878 75 F0 80         [24] 1162 	mov	b,#0x80
      00287B 12 2E 3D         [24] 1163 	lcall	_putstr
                                   1164 ;	uart.c:189: buffer_to_be_deleted = accept_number_from_user();
      00287E 12 2E B3         [24] 1165 	lcall	_accept_number_from_user
      002881 85 82 12         [24] 1166 	mov	_command_sloc4_1_0,dpl
      002884 85 83 13         [24] 1167 	mov	(_command_sloc4_1_0 + 1),dph
                                   1168 ;	uart.c:190: for (int i = 2; i < MAX_NUM_OF_BUFFERS; i++)
      002887 90 1A F7         [24] 1169 	mov	dptr,#_command_PARM_2
      00288A E0               [24] 1170 	movx	a,@dptr
      00288B FA               [12] 1171 	mov	r2,a
      00288C A3               [24] 1172 	inc	dptr
      00288D E0               [24] 1173 	movx	a,@dptr
      00288E FB               [12] 1174 	mov	r3,a
      00288F A3               [24] 1175 	inc	dptr
      002890 E0               [24] 1176 	movx	a,@dptr
      002891 FC               [12] 1177 	mov	r4,a
      002892 78 02            [12] 1178 	mov	r0,#0x02
      002894 79 00            [12] 1179 	mov	r1,#0x00
      002896                       1180 00158$:
      002896 C3               [12] 1181 	clr	c
      002897 E8               [12] 1182 	mov	a,r0
      002898 94 D2            [12] 1183 	subb	a,#0xd2
      00289A E9               [12] 1184 	mov	a,r1
      00289B 64 80            [12] 1185 	xrl	a,#0x80
      00289D 94 80            [12] 1186 	subb	a,#0x80
      00289F 40 03            [24] 1187 	jc	00340$
      0028A1 02 29 A1         [24] 1188 	ljmp	00131$
      0028A4                       1189 00340$:
                                   1190 ;	uart.c:192: if (buffer_to_be_deleted == buffers[i].buf_id)
      0028A4 90 1B 5A         [24] 1191 	mov	dptr,#__mulint_PARM_2
      0028A7 E8               [12] 1192 	mov	a,r0
      0028A8 F0               [24] 1193 	movx	@dptr,a
      0028A9 E9               [12] 1194 	mov	a,r1
      0028AA A3               [24] 1195 	inc	dptr
      0028AB F0               [24] 1196 	movx	@dptr,a
      0028AC 90 00 09         [24] 1197 	mov	dptr,#0x0009
      0028AF C0 04            [24] 1198 	push	ar4
      0028B1 C0 03            [24] 1199 	push	ar3
      0028B3 C0 02            [24] 1200 	push	ar2
      0028B5 C0 01            [24] 1201 	push	ar1
      0028B7 C0 00            [24] 1202 	push	ar0
      0028B9 12 3A C5         [24] 1203 	lcall	__mulint
      0028BC AD 82            [24] 1204 	mov	r5,dpl
      0028BE AE 83            [24] 1205 	mov	r6,dph
      0028C0 D0 00            [24] 1206 	pop	ar0
      0028C2 D0 01            [24] 1207 	pop	ar1
      0028C4 D0 02            [24] 1208 	pop	ar2
      0028C6 D0 03            [24] 1209 	pop	ar3
      0028C8 D0 04            [24] 1210 	pop	ar4
      0028CA ED               [12] 1211 	mov	a,r5
      0028CB 2A               [12] 1212 	add	a,r2
      0028CC F5 0B            [12] 1213 	mov	_command_sloc1_1_0,a
      0028CE EE               [12] 1214 	mov	a,r6
      0028CF 3B               [12] 1215 	addc	a,r3
      0028D0 F5 0C            [12] 1216 	mov	(_command_sloc1_1_0 + 1),a
      0028D2 8C 0D            [24] 1217 	mov	(_command_sloc1_1_0 + 2),r4
      0028D4 74 05            [12] 1218 	mov	a,#0x05
      0028D6 25 0B            [12] 1219 	add	a,_command_sloc1_1_0
      0028D8 F5 08            [12] 1220 	mov	_command_sloc0_1_0,a
      0028DA E4               [12] 1221 	clr	a
      0028DB 35 0C            [12] 1222 	addc	a,(_command_sloc1_1_0 + 1)
      0028DD F5 09            [12] 1223 	mov	(_command_sloc0_1_0 + 1),a
      0028DF 85 0D 0A         [24] 1224 	mov	(_command_sloc0_1_0 + 2),(_command_sloc1_1_0 + 2)
      0028E2 85 08 82         [24] 1225 	mov	dpl,_command_sloc0_1_0
      0028E5 85 09 83         [24] 1226 	mov	dph,(_command_sloc0_1_0 + 1)
      0028E8 85 0A F0         [24] 1227 	mov	b,(_command_sloc0_1_0 + 2)
      0028EB 12 49 F6         [24] 1228 	lcall	__gptrget
      0028EE FD               [12] 1229 	mov	r5,a
      0028EF A3               [24] 1230 	inc	dptr
      0028F0 12 49 F6         [24] 1231 	lcall	__gptrget
      0028F3 FE               [12] 1232 	mov	r6,a
      0028F4 ED               [12] 1233 	mov	a,r5
      0028F5 B5 12 06         [24] 1234 	cjne	a,_command_sloc4_1_0,00341$
      0028F8 EE               [12] 1235 	mov	a,r6
      0028F9 B5 13 02         [24] 1236 	cjne	a,(_command_sloc4_1_0 + 1),00341$
      0028FC 80 03            [24] 1237 	sjmp	00342$
      0028FE                       1238 00341$:
      0028FE 02 29 99         [24] 1239 	ljmp	00159$
      002901                       1240 00342$:
                                   1241 ;	uart.c:194: free(buffers[i].buffer_pointer);
      002901 C0 02            [24] 1242 	push	ar2
      002903 C0 03            [24] 1243 	push	ar3
      002905 C0 04            [24] 1244 	push	ar4
      002907 85 0B 82         [24] 1245 	mov	dpl,_command_sloc1_1_0
      00290A 85 0C 83         [24] 1246 	mov	dph,(_command_sloc1_1_0 + 1)
      00290D 85 0D F0         [24] 1247 	mov	b,(_command_sloc1_1_0 + 2)
      002910 12 49 F6         [24] 1248 	lcall	__gptrget
      002913 FC               [12] 1249 	mov	r4,a
      002914 A3               [24] 1250 	inc	dptr
      002915 12 49 F6         [24] 1251 	lcall	__gptrget
      002918 FD               [12] 1252 	mov	r5,a
      002919 A3               [24] 1253 	inc	dptr
      00291A 12 49 F6         [24] 1254 	lcall	__gptrget
      00291D FE               [12] 1255 	mov	r6,a
      00291E 8C 82            [24] 1256 	mov	dpl,r4
      002920 8D 83            [24] 1257 	mov	dph,r5
      002922 8E F0            [24] 1258 	mov	b,r6
      002924 C0 04            [24] 1259 	push	ar4
      002926 C0 03            [24] 1260 	push	ar3
      002928 C0 02            [24] 1261 	push	ar2
      00292A C0 01            [24] 1262 	push	ar1
      00292C C0 00            [24] 1263 	push	ar0
      00292E 12 36 94         [24] 1264 	lcall	_free
      002931 D0 00            [24] 1265 	pop	ar0
      002933 D0 01            [24] 1266 	pop	ar1
      002935 D0 02            [24] 1267 	pop	ar2
      002937 D0 03            [24] 1268 	pop	ar3
      002939 D0 04            [24] 1269 	pop	ar4
                                   1270 ;	uart.c:195: buffers[i].buffer_pointer = 0;
      00293B 85 0B 82         [24] 1271 	mov	dpl,_command_sloc1_1_0
      00293E 85 0C 83         [24] 1272 	mov	dph,(_command_sloc1_1_0 + 1)
      002941 85 0D F0         [24] 1273 	mov	b,(_command_sloc1_1_0 + 2)
      002944 E4               [12] 1274 	clr	a
      002945 12 39 A1         [24] 1275 	lcall	__gptrput
      002948 A3               [24] 1276 	inc	dptr
      002949 12 39 A1         [24] 1277 	lcall	__gptrput
      00294C A3               [24] 1278 	inc	dptr
      00294D 12 39 A1         [24] 1279 	lcall	__gptrput
                                   1280 ;	uart.c:196: buffers[i].buf_id = -1;
      002950 85 08 82         [24] 1281 	mov	dpl,_command_sloc0_1_0
      002953 85 09 83         [24] 1282 	mov	dph,(_command_sloc0_1_0 + 1)
      002956 85 0A F0         [24] 1283 	mov	b,(_command_sloc0_1_0 + 2)
      002959 14               [12] 1284 	dec	a
      00295A 12 39 A1         [24] 1285 	lcall	__gptrput
      00295D A3               [24] 1286 	inc	dptr
      00295E 12 39 A1         [24] 1287 	lcall	__gptrput
                                   1288 ;	uart.c:197: buffers[i].buf_index = 0;
      002961 74 03            [12] 1289 	mov	a,#0x03
      002963 25 0B            [12] 1290 	add	a,_command_sloc1_1_0
      002965 FC               [12] 1291 	mov	r4,a
      002966 E4               [12] 1292 	clr	a
      002967 35 0C            [12] 1293 	addc	a,(_command_sloc1_1_0 + 1)
      002969 FD               [12] 1294 	mov	r5,a
      00296A AE 0D            [24] 1295 	mov	r6,(_command_sloc1_1_0 + 2)
      00296C 8C 82            [24] 1296 	mov	dpl,r4
      00296E 8D 83            [24] 1297 	mov	dph,r5
      002970 8E F0            [24] 1298 	mov	b,r6
      002972 E4               [12] 1299 	clr	a
      002973 12 39 A1         [24] 1300 	lcall	__gptrput
      002976 A3               [24] 1301 	inc	dptr
      002977 12 39 A1         [24] 1302 	lcall	__gptrput
                                   1303 ;	uart.c:198: buffers[i].buf_size = 0;
      00297A 74 07            [12] 1304 	mov	a,#0x07
      00297C 25 0B            [12] 1305 	add	a,_command_sloc1_1_0
      00297E FC               [12] 1306 	mov	r4,a
      00297F E4               [12] 1307 	clr	a
      002980 35 0C            [12] 1308 	addc	a,(_command_sloc1_1_0 + 1)
      002982 FD               [12] 1309 	mov	r5,a
      002983 AE 0D            [24] 1310 	mov	r6,(_command_sloc1_1_0 + 2)
      002985 8C 82            [24] 1311 	mov	dpl,r4
      002987 8D 83            [24] 1312 	mov	dph,r5
      002989 8E F0            [24] 1313 	mov	b,r6
      00298B E4               [12] 1314 	clr	a
      00298C 12 39 A1         [24] 1315 	lcall	__gptrput
      00298F A3               [24] 1316 	inc	dptr
      002990 12 39 A1         [24] 1317 	lcall	__gptrput
                                   1318 ;	uart.c:265: putstr("Enter command (+, -, ?, =, @) or input: ");
      002993 D0 04            [24] 1319 	pop	ar4
      002995 D0 03            [24] 1320 	pop	ar3
      002997 D0 02            [24] 1321 	pop	ar2
                                   1322 ;	uart.c:198: buffers[i].buf_size = 0;
      002999                       1323 00159$:
                                   1324 ;	uart.c:190: for (int i = 2; i < MAX_NUM_OF_BUFFERS; i++)
      002999 08               [12] 1325 	inc	r0
      00299A B8 00 01         [24] 1326 	cjne	r0,#0x00,00343$
      00299D 09               [12] 1327 	inc	r1
      00299E                       1328 00343$:
      00299E 02 28 96         [24] 1329 	ljmp	00158$
      0029A1                       1330 00131$:
                                   1331 ;	uart.c:201: print_buffers(buffers);
      0029A1 8A 82            [24] 1332 	mov	dpl,r2
      0029A3 8B 83            [24] 1333 	mov	dph,r3
      0029A5 8C F0            [24] 1334 	mov	b,r4
      0029A7 12 30 3D         [24] 1335 	lcall	_print_buffers
                                   1336 ;	uart.c:202: break;
      0029AA 02 2D FA         [24] 1337 	ljmp	00147$
                                   1338 ;	uart.c:205: case '?':
      0029AD                       1339 00132$:
                                   1340 ;	uart.c:206: putstr("\r\n\r\n\t *** Command for a query ***\r\n");
      0029AD 90 4E A8         [24] 1341 	mov	dptr,#___str_16
      0029B0 75 F0 80         [24] 1342 	mov	b,#0x80
      0029B3 12 2E 3D         [24] 1343 	lcall	_putstr
                                   1344 ;	uart.c:207: printf_tiny("\r\n\r\n\t\t-----------------------------------------------------------------");
      0029B6 74 CC            [12] 1345 	mov	a,#___str_17
      0029B8 C0 E0            [24] 1346 	push	acc
      0029BA 74 4E            [12] 1347 	mov	a,#(___str_17 >> 8)
      0029BC C0 E0            [24] 1348 	push	acc
      0029BE 12 39 BC         [24] 1349 	lcall	_printf_tiny
      0029C1 15 81            [12] 1350 	dec	sp
      0029C3 15 81            [12] 1351 	dec	sp
                                   1352 ;	uart.c:208: putstr("\r\n\t\t| Buffer id | start-addr | end-addr | nStorageChar | free-space |\t\r\n");
      0029C5 90 4F 14         [24] 1353 	mov	dptr,#___str_18
      0029C8 75 F0 80         [24] 1354 	mov	b,#0x80
      0029CB 12 2E 3D         [24] 1355 	lcall	_putstr
                                   1356 ;	uart.c:209: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
      0029CE 90 1A F7         [24] 1357 	mov	dptr,#_command_PARM_2
      0029D1 E0               [24] 1358 	movx	a,@dptr
      0029D2 F5 12            [12] 1359 	mov	_command_sloc4_1_0,a
      0029D4 A3               [24] 1360 	inc	dptr
      0029D5 E0               [24] 1361 	movx	a,@dptr
      0029D6 F5 13            [12] 1362 	mov	(_command_sloc4_1_0 + 1),a
      0029D8 A3               [24] 1363 	inc	dptr
      0029D9 E0               [24] 1364 	movx	a,@dptr
      0029DA F5 14            [12] 1365 	mov	(_command_sloc4_1_0 + 2),a
      0029DC 7A 00            [12] 1366 	mov	r2,#0x00
      0029DE 7B 00            [12] 1367 	mov	r3,#0x00
      0029E0                       1368 00161$:
      0029E0 C3               [12] 1369 	clr	c
      0029E1 EA               [12] 1370 	mov	a,r2
      0029E2 94 D2            [12] 1371 	subb	a,#0xd2
      0029E4 EB               [12] 1372 	mov	a,r3
      0029E5 64 80            [12] 1373 	xrl	a,#0x80
      0029E7 94 80            [12] 1374 	subb	a,#0x80
      0029E9 40 03            [24] 1375 	jc	00344$
      0029EB 02 2B 42         [24] 1376 	ljmp	00137$
      0029EE                       1377 00344$:
                                   1378 ;	uart.c:214: if ((buffers[i].buffer_pointer != 0) || (i == 0) || (i == 1))
      0029EE 90 1B 5A         [24] 1379 	mov	dptr,#__mulint_PARM_2
      0029F1 EA               [12] 1380 	mov	a,r2
      0029F2 F0               [24] 1381 	movx	@dptr,a
      0029F3 EB               [12] 1382 	mov	a,r3
      0029F4 A3               [24] 1383 	inc	dptr
      0029F5 F0               [24] 1384 	movx	@dptr,a
      0029F6 90 00 09         [24] 1385 	mov	dptr,#0x0009
      0029F9 C0 03            [24] 1386 	push	ar3
      0029FB C0 02            [24] 1387 	push	ar2
      0029FD 12 3A C5         [24] 1388 	lcall	__mulint
      002A00 A8 82            [24] 1389 	mov	r0,dpl
      002A02 A9 83            [24] 1390 	mov	r1,dph
      002A04 D0 02            [24] 1391 	pop	ar2
      002A06 D0 03            [24] 1392 	pop	ar3
      002A08 C0 02            [24] 1393 	push	ar2
      002A0A C0 03            [24] 1394 	push	ar3
      002A0C E8               [12] 1395 	mov	a,r0
      002A0D 25 12            [12] 1396 	add	a,_command_sloc4_1_0
      002A0F F8               [12] 1397 	mov	r0,a
      002A10 E9               [12] 1398 	mov	a,r1
      002A11 35 13            [12] 1399 	addc	a,(_command_sloc4_1_0 + 1)
      002A13 F9               [12] 1400 	mov	r1,a
      002A14 AB 14            [24] 1401 	mov	r3,(_command_sloc4_1_0 + 2)
      002A16 88 82            [24] 1402 	mov	dpl,r0
      002A18 89 83            [24] 1403 	mov	dph,r1
      002A1A 8B F0            [24] 1404 	mov	b,r3
      002A1C 12 49 F6         [24] 1405 	lcall	__gptrget
      002A1F F8               [12] 1406 	mov	r0,a
      002A20 A3               [24] 1407 	inc	dptr
      002A21 12 49 F6         [24] 1408 	lcall	__gptrget
      002A24 F9               [12] 1409 	mov	r1,a
      002A25 A3               [24] 1410 	inc	dptr
      002A26 12 49 F6         [24] 1411 	lcall	__gptrget
      002A29 E8               [12] 1412 	mov	a,r0
      002A2A 49               [12] 1413 	orl	a,r1
      002A2B D0 03            [24] 1414 	pop	ar3
      002A2D D0 02            [24] 1415 	pop	ar2
      002A2F 70 0F            [24] 1416 	jnz	00133$
      002A31 EA               [12] 1417 	mov	a,r2
      002A32 4B               [12] 1418 	orl	a,r3
      002A33 60 0B            [24] 1419 	jz	00133$
      002A35 BA 01 05         [24] 1420 	cjne	r2,#0x01,00347$
      002A38 BB 00 02         [24] 1421 	cjne	r3,#0x00,00347$
      002A3B 80 03            [24] 1422 	sjmp	00348$
      002A3D                       1423 00347$:
      002A3D 02 2B 3A         [24] 1424 	ljmp	00162$
      002A40                       1425 00348$:
      002A40                       1426 00133$:
                                   1427 ;	uart.c:216: printf_tiny("\r\n\t\t-----------------------------------------------------------------");
      002A40 C0 03            [24] 1428 	push	ar3
      002A42 C0 02            [24] 1429 	push	ar2
      002A44 74 5D            [12] 1430 	mov	a,#___str_19
      002A46 C0 E0            [24] 1431 	push	acc
      002A48 74 4F            [12] 1432 	mov	a,#(___str_19 >> 8)
      002A4A C0 E0            [24] 1433 	push	acc
      002A4C 12 39 BC         [24] 1434 	lcall	_printf_tiny
      002A4F 15 81            [12] 1435 	dec	sp
      002A51 15 81            [12] 1436 	dec	sp
      002A53 D0 02            [24] 1437 	pop	ar2
      002A55 D0 03            [24] 1438 	pop	ar3
                                   1439 ;	uart.c:219: buffers[i].buf_index, (buffers[i].buf_size - buffers[i].buf_index));
      002A57 90 1B 5A         [24] 1440 	mov	dptr,#__mulint_PARM_2
      002A5A EA               [12] 1441 	mov	a,r2
      002A5B F0               [24] 1442 	movx	@dptr,a
      002A5C EB               [12] 1443 	mov	a,r3
      002A5D A3               [24] 1444 	inc	dptr
      002A5E F0               [24] 1445 	movx	@dptr,a
      002A5F 90 00 09         [24] 1446 	mov	dptr,#0x0009
      002A62 C0 03            [24] 1447 	push	ar3
      002A64 C0 02            [24] 1448 	push	ar2
      002A66 12 3A C5         [24] 1449 	lcall	__mulint
      002A69 A8 82            [24] 1450 	mov	r0,dpl
      002A6B A9 83            [24] 1451 	mov	r1,dph
      002A6D D0 02            [24] 1452 	pop	ar2
      002A6F D0 03            [24] 1453 	pop	ar3
      002A71 C0 02            [24] 1454 	push	ar2
      002A73 C0 03            [24] 1455 	push	ar3
      002A75 E8               [12] 1456 	mov	a,r0
      002A76 25 12            [12] 1457 	add	a,_command_sloc4_1_0
      002A78 F8               [12] 1458 	mov	r0,a
      002A79 E9               [12] 1459 	mov	a,r1
      002A7A 35 13            [12] 1460 	addc	a,(_command_sloc4_1_0 + 1)
      002A7C F9               [12] 1461 	mov	r1,a
      002A7D AB 14            [24] 1462 	mov	r3,(_command_sloc4_1_0 + 2)
      002A7F 74 07            [12] 1463 	mov	a,#0x07
      002A81 28               [12] 1464 	add	a,r0
      002A82 FA               [12] 1465 	mov	r2,a
      002A83 E4               [12] 1466 	clr	a
      002A84 39               [12] 1467 	addc	a,r1
      002A85 FD               [12] 1468 	mov	r5,a
      002A86 8B 06            [24] 1469 	mov	ar6,r3
      002A88 8A 82            [24] 1470 	mov	dpl,r2
      002A8A 8D 83            [24] 1471 	mov	dph,r5
      002A8C 8E F0            [24] 1472 	mov	b,r6
      002A8E 12 49 F6         [24] 1473 	lcall	__gptrget
      002A91 F5 10            [12] 1474 	mov	_command_sloc3_1_0,a
      002A93 A3               [24] 1475 	inc	dptr
      002A94 12 49 F6         [24] 1476 	lcall	__gptrget
      002A97 F5 11            [12] 1477 	mov	(_command_sloc3_1_0 + 1),a
      002A99 74 03            [12] 1478 	mov	a,#0x03
      002A9B 28               [12] 1479 	add	a,r0
      002A9C FC               [12] 1480 	mov	r4,a
      002A9D E4               [12] 1481 	clr	a
      002A9E 39               [12] 1482 	addc	a,r1
      002A9F FD               [12] 1483 	mov	r5,a
      002AA0 8B 06            [24] 1484 	mov	ar6,r3
      002AA2 8C 82            [24] 1485 	mov	dpl,r4
      002AA4 8D 83            [24] 1486 	mov	dph,r5
      002AA6 8E F0            [24] 1487 	mov	b,r6
      002AA8 12 49 F6         [24] 1488 	lcall	__gptrget
      002AAB F5 0B            [12] 1489 	mov	_command_sloc1_1_0,a
      002AAD A3               [24] 1490 	inc	dptr
      002AAE 12 49 F6         [24] 1491 	lcall	__gptrget
      002AB1 F5 0C            [12] 1492 	mov	(_command_sloc1_1_0 + 1),a
      002AB3 E5 10            [12] 1493 	mov	a,_command_sloc3_1_0
      002AB5 C3               [12] 1494 	clr	c
      002AB6 95 0B            [12] 1495 	subb	a,_command_sloc1_1_0
      002AB8 F5 0E            [12] 1496 	mov	_command_sloc2_1_0,a
      002ABA E5 11            [12] 1497 	mov	a,(_command_sloc3_1_0 + 1)
      002ABC 95 0C            [12] 1498 	subb	a,(_command_sloc1_1_0 + 1)
      002ABE F5 0F            [12] 1499 	mov	(_command_sloc2_1_0 + 1),a
                                   1500 ;	uart.c:218: buffers[i].buf_id, &(buffers[i].buffer_pointer[0]), &(buffers[i].buffer_pointer[buffers[i].buf_size - 1]),
      002AC0 88 82            [24] 1501 	mov	dpl,r0
      002AC2 89 83            [24] 1502 	mov	dph,r1
      002AC4 8B F0            [24] 1503 	mov	b,r3
      002AC6 12 49 F6         [24] 1504 	lcall	__gptrget
      002AC9 F5 08            [12] 1505 	mov	_command_sloc0_1_0,a
      002ACB A3               [24] 1506 	inc	dptr
      002ACC 12 49 F6         [24] 1507 	lcall	__gptrget
      002ACF F5 09            [12] 1508 	mov	(_command_sloc0_1_0 + 1),a
      002AD1 A3               [24] 1509 	inc	dptr
      002AD2 12 49 F6         [24] 1510 	lcall	__gptrget
      002AD5 F5 0A            [12] 1511 	mov	(_command_sloc0_1_0 + 2),a
      002AD7 E5 10            [12] 1512 	mov	a,_command_sloc3_1_0
      002AD9 24 FF            [12] 1513 	add	a,#0xff
      002ADB FC               [12] 1514 	mov	r4,a
      002ADC E5 11            [12] 1515 	mov	a,(_command_sloc3_1_0 + 1)
      002ADE 34 FF            [12] 1516 	addc	a,#0xff
      002AE0 FE               [12] 1517 	mov	r6,a
      002AE1 EC               [12] 1518 	mov	a,r4
      002AE2 25 08            [12] 1519 	add	a,_command_sloc0_1_0
      002AE4 FC               [12] 1520 	mov	r4,a
      002AE5 EE               [12] 1521 	mov	a,r6
      002AE6 35 09            [12] 1522 	addc	a,(_command_sloc0_1_0 + 1)
      002AE8 FE               [12] 1523 	mov	r6,a
      002AE9 AD 0A            [24] 1524 	mov	r5,(_command_sloc0_1_0 + 2)
      002AEB 74 05            [12] 1525 	mov	a,#0x05
      002AED 28               [12] 1526 	add	a,r0
      002AEE F8               [12] 1527 	mov	r0,a
      002AEF E4               [12] 1528 	clr	a
      002AF0 39               [12] 1529 	addc	a,r1
      002AF1 F9               [12] 1530 	mov	r1,a
      002AF2 88 82            [24] 1531 	mov	dpl,r0
      002AF4 89 83            [24] 1532 	mov	dph,r1
      002AF6 8B F0            [24] 1533 	mov	b,r3
      002AF8 12 49 F6         [24] 1534 	lcall	__gptrget
      002AFB F8               [12] 1535 	mov	r0,a
      002AFC A3               [24] 1536 	inc	dptr
      002AFD 12 49 F6         [24] 1537 	lcall	__gptrget
      002B00 F9               [12] 1538 	mov	r1,a
                                   1539 ;	uart.c:217: printf("\r\n\t\t|%10d |   %11p |%9p |%13d |%11d |",
      002B01 C0 03            [24] 1540 	push	ar3
      002B03 C0 02            [24] 1541 	push	ar2
      002B05 C0 0E            [24] 1542 	push	_command_sloc2_1_0
      002B07 C0 0F            [24] 1543 	push	(_command_sloc2_1_0 + 1)
      002B09 C0 0B            [24] 1544 	push	_command_sloc1_1_0
      002B0B C0 0C            [24] 1545 	push	(_command_sloc1_1_0 + 1)
      002B0D C0 04            [24] 1546 	push	ar4
      002B0F C0 06            [24] 1547 	push	ar6
      002B11 C0 05            [24] 1548 	push	ar5
      002B13 C0 08            [24] 1549 	push	_command_sloc0_1_0
      002B15 C0 09            [24] 1550 	push	(_command_sloc0_1_0 + 1)
      002B17 C0 0A            [24] 1551 	push	(_command_sloc0_1_0 + 2)
      002B19 C0 00            [24] 1552 	push	ar0
      002B1B C0 01            [24] 1553 	push	ar1
      002B1D 74 A3            [12] 1554 	mov	a,#___str_20
      002B1F C0 E0            [24] 1555 	push	acc
      002B21 74 4F            [12] 1556 	mov	a,#(___str_20 >> 8)
      002B23 C0 E0            [24] 1557 	push	acc
      002B25 74 80            [12] 1558 	mov	a,#0x80
      002B27 C0 E0            [24] 1559 	push	acc
      002B29 12 3F D4         [24] 1560 	lcall	_printf
      002B2C E5 81            [12] 1561 	mov	a,sp
      002B2E 24 F1            [12] 1562 	add	a,#0xf1
      002B30 F5 81            [12] 1563 	mov	sp,a
      002B32 D0 02            [24] 1564 	pop	ar2
      002B34 D0 03            [24] 1565 	pop	ar3
                                   1566 ;	uart.c:265: putstr("Enter command (+, -, ?, =, @) or input: ");
      002B36 D0 03            [24] 1567 	pop	ar3
      002B38 D0 02            [24] 1568 	pop	ar2
                                   1569 ;	uart.c:217: printf("\r\n\t\t|%10d |   %11p |%9p |%13d |%11d |",
      002B3A                       1570 00162$:
                                   1571 ;	uart.c:209: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
      002B3A 0A               [12] 1572 	inc	r2
      002B3B BA 00 01         [24] 1573 	cjne	r2,#0x00,00349$
      002B3E 0B               [12] 1574 	inc	r3
      002B3F                       1575 00349$:
      002B3F 02 29 E0         [24] 1576 	ljmp	00161$
      002B42                       1577 00137$:
                                   1578 ;	uart.c:222: printf_tiny("\r\n\t\t-----------------------------------------------------------------\r\n");
      002B42 74 C9            [12] 1579 	mov	a,#___str_21
      002B44 C0 E0            [24] 1580 	push	acc
      002B46 74 4F            [12] 1581 	mov	a,#(___str_21 >> 8)
      002B48 C0 E0            [24] 1582 	push	acc
      002B4A 12 39 BC         [24] 1583 	lcall	_printf_tiny
      002B4D 15 81            [12] 1584 	dec	sp
      002B4F 15 81            [12] 1585 	dec	sp
                                   1586 ;	uart.c:224: printf("\r\n\r\n\tBuffer 0 contents: \r\n\r\n");
      002B51 74 11            [12] 1587 	mov	a,#___str_22
      002B53 C0 E0            [24] 1588 	push	acc
      002B55 74 50            [12] 1589 	mov	a,#(___str_22 >> 8)
      002B57 C0 E0            [24] 1590 	push	acc
      002B59 74 80            [12] 1591 	mov	a,#0x80
      002B5B C0 E0            [24] 1592 	push	acc
      002B5D 12 3F D4         [24] 1593 	lcall	_printf
      002B60 15 81            [12] 1594 	dec	sp
      002B62 15 81            [12] 1595 	dec	sp
      002B64 15 81            [12] 1596 	dec	sp
                                   1597 ;	uart.c:225: for (int iBuffer0 = 0; iBuffer0 < buffers[0].buf_index; iBuffer0++)
      002B66 AC 12            [24] 1598 	mov	r4,_command_sloc4_1_0
      002B68 AD 13            [24] 1599 	mov	r5,(_command_sloc4_1_0 + 1)
      002B6A AE 14            [24] 1600 	mov	r6,(_command_sloc4_1_0 + 2)
      002B6C 74 03            [12] 1601 	mov	a,#0x03
      002B6E 25 12            [12] 1602 	add	a,_command_sloc4_1_0
      002B70 F9               [12] 1603 	mov	r1,a
      002B71 E4               [12] 1604 	clr	a
      002B72 35 13            [12] 1605 	addc	a,(_command_sloc4_1_0 + 1)
      002B74 FA               [12] 1606 	mov	r2,a
      002B75 AB 14            [24] 1607 	mov	r3,(_command_sloc4_1_0 + 2)
      002B77 E4               [12] 1608 	clr	a
      002B78 F5 12            [12] 1609 	mov	_command_sloc4_1_0,a
      002B7A F5 13            [12] 1610 	mov	(_command_sloc4_1_0 + 1),a
      002B7C                       1611 00164$:
      002B7C C0 04            [24] 1612 	push	ar4
      002B7E C0 05            [24] 1613 	push	ar5
      002B80 C0 06            [24] 1614 	push	ar6
      002B82 89 82            [24] 1615 	mov	dpl,r1
      002B84 8A 83            [24] 1616 	mov	dph,r2
      002B86 8B F0            [24] 1617 	mov	b,r3
      002B88 12 49 F6         [24] 1618 	lcall	__gptrget
      002B8B F8               [12] 1619 	mov	r0,a
      002B8C A3               [24] 1620 	inc	dptr
      002B8D 12 49 F6         [24] 1621 	lcall	__gptrget
      002B90 FE               [12] 1622 	mov	r6,a
      002B91 C3               [12] 1623 	clr	c
      002B92 E5 12            [12] 1624 	mov	a,_command_sloc4_1_0
      002B94 98               [12] 1625 	subb	a,r0
      002B95 E5 13            [12] 1626 	mov	a,(_command_sloc4_1_0 + 1)
      002B97 64 80            [12] 1627 	xrl	a,#0x80
      002B99 8E F0            [24] 1628 	mov	b,r6
      002B9B 63 F0 80         [24] 1629 	xrl	b,#0x80
      002B9E 95 F0            [12] 1630 	subb	a,b
      002BA0 D0 06            [24] 1631 	pop	ar6
      002BA2 D0 05            [24] 1632 	pop	ar5
      002BA4 D0 04            [24] 1633 	pop	ar4
      002BA6 40 03            [24] 1634 	jc	00350$
      002BA8 02 2C 7B         [24] 1635 	ljmp	00140$
      002BAB                       1636 00350$:
                                   1637 ;	uart.c:227: if (iBuffer0 % 64 == 0)
      002BAB 90 1B 64         [24] 1638 	mov	dptr,#__modsint_PARM_2
      002BAE 74 40            [12] 1639 	mov	a,#0x40
      002BB0 F0               [24] 1640 	movx	@dptr,a
      002BB1 E4               [12] 1641 	clr	a
      002BB2 A3               [24] 1642 	inc	dptr
      002BB3 F0               [24] 1643 	movx	@dptr,a
      002BB4 85 12 82         [24] 1644 	mov	dpl,_command_sloc4_1_0
      002BB7 85 13 83         [24] 1645 	mov	dph,(_command_sloc4_1_0 + 1)
      002BBA C0 06            [24] 1646 	push	ar6
      002BBC C0 05            [24] 1647 	push	ar5
      002BBE C0 04            [24] 1648 	push	ar4
      002BC0 C0 03            [24] 1649 	push	ar3
      002BC2 C0 02            [24] 1650 	push	ar2
      002BC4 C0 01            [24] 1651 	push	ar1
      002BC6 12 3C 8A         [24] 1652 	lcall	__modsint
      002BC9 E5 82            [12] 1653 	mov	a,dpl
      002BCB 85 83 F0         [24] 1654 	mov	b,dph
      002BCE D0 01            [24] 1655 	pop	ar1
      002BD0 D0 02            [24] 1656 	pop	ar2
      002BD2 D0 03            [24] 1657 	pop	ar3
      002BD4 D0 04            [24] 1658 	pop	ar4
      002BD6 D0 05            [24] 1659 	pop	ar5
      002BD8 D0 06            [24] 1660 	pop	ar6
      002BDA 45 F0            [12] 1661 	orl	a,b
      002BDC 70 2D            [24] 1662 	jnz	00139$
                                   1663 ;	uart.c:228: printf("\r\n\t\t");
      002BDE C0 06            [24] 1664 	push	ar6
      002BE0 C0 05            [24] 1665 	push	ar5
      002BE2 C0 04            [24] 1666 	push	ar4
      002BE4 C0 03            [24] 1667 	push	ar3
      002BE6 C0 02            [24] 1668 	push	ar2
      002BE8 C0 01            [24] 1669 	push	ar1
      002BEA 74 2E            [12] 1670 	mov	a,#___str_23
      002BEC C0 E0            [24] 1671 	push	acc
      002BEE 74 50            [12] 1672 	mov	a,#(___str_23 >> 8)
      002BF0 C0 E0            [24] 1673 	push	acc
      002BF2 74 80            [12] 1674 	mov	a,#0x80
      002BF4 C0 E0            [24] 1675 	push	acc
      002BF6 12 3F D4         [24] 1676 	lcall	_printf
      002BF9 15 81            [12] 1677 	dec	sp
      002BFB 15 81            [12] 1678 	dec	sp
      002BFD 15 81            [12] 1679 	dec	sp
      002BFF D0 01            [24] 1680 	pop	ar1
      002C01 D0 02            [24] 1681 	pop	ar2
      002C03 D0 03            [24] 1682 	pop	ar3
      002C05 D0 04            [24] 1683 	pop	ar4
      002C07 D0 05            [24] 1684 	pop	ar5
      002C09 D0 06            [24] 1685 	pop	ar6
      002C0B                       1686 00139$:
                                   1687 ;	uart.c:229: printf("%c", buffers[0].buffer_pointer[iBuffer0]);
      002C0B C0 01            [24] 1688 	push	ar1
      002C0D C0 02            [24] 1689 	push	ar2
      002C0F C0 03            [24] 1690 	push	ar3
      002C11 8C 82            [24] 1691 	mov	dpl,r4
      002C13 8D 83            [24] 1692 	mov	dph,r5
      002C15 8E F0            [24] 1693 	mov	b,r6
      002C17 12 49 F6         [24] 1694 	lcall	__gptrget
      002C1A F8               [12] 1695 	mov	r0,a
      002C1B A3               [24] 1696 	inc	dptr
      002C1C 12 49 F6         [24] 1697 	lcall	__gptrget
      002C1F FA               [12] 1698 	mov	r2,a
      002C20 A3               [24] 1699 	inc	dptr
      002C21 12 49 F6         [24] 1700 	lcall	__gptrget
      002C24 FB               [12] 1701 	mov	r3,a
      002C25 E5 12            [12] 1702 	mov	a,_command_sloc4_1_0
      002C27 28               [12] 1703 	add	a,r0
      002C28 F8               [12] 1704 	mov	r0,a
      002C29 E5 13            [12] 1705 	mov	a,(_command_sloc4_1_0 + 1)
      002C2B 3A               [12] 1706 	addc	a,r2
      002C2C FA               [12] 1707 	mov	r2,a
      002C2D 88 82            [24] 1708 	mov	dpl,r0
      002C2F 8A 83            [24] 1709 	mov	dph,r2
      002C31 8B F0            [24] 1710 	mov	b,r3
      002C33 12 49 F6         [24] 1711 	lcall	__gptrget
      002C36 F8               [12] 1712 	mov	r0,a
      002C37 7B 00            [12] 1713 	mov	r3,#0x00
      002C39 C0 06            [24] 1714 	push	ar6
      002C3B C0 05            [24] 1715 	push	ar5
      002C3D C0 04            [24] 1716 	push	ar4
      002C3F C0 03            [24] 1717 	push	ar3
      002C41 C0 02            [24] 1718 	push	ar2
      002C43 C0 01            [24] 1719 	push	ar1
      002C45 C0 00            [24] 1720 	push	ar0
      002C47 C0 03            [24] 1721 	push	ar3
      002C49 74 33            [12] 1722 	mov	a,#___str_24
      002C4B C0 E0            [24] 1723 	push	acc
      002C4D 74 50            [12] 1724 	mov	a,#(___str_24 >> 8)
      002C4F C0 E0            [24] 1725 	push	acc
      002C51 74 80            [12] 1726 	mov	a,#0x80
      002C53 C0 E0            [24] 1727 	push	acc
      002C55 12 3F D4         [24] 1728 	lcall	_printf
      002C58 E5 81            [12] 1729 	mov	a,sp
      002C5A 24 FB            [12] 1730 	add	a,#0xfb
      002C5C F5 81            [12] 1731 	mov	sp,a
      002C5E D0 01            [24] 1732 	pop	ar1
      002C60 D0 02            [24] 1733 	pop	ar2
      002C62 D0 03            [24] 1734 	pop	ar3
      002C64 D0 04            [24] 1735 	pop	ar4
      002C66 D0 05            [24] 1736 	pop	ar5
      002C68 D0 06            [24] 1737 	pop	ar6
                                   1738 ;	uart.c:225: for (int iBuffer0 = 0; iBuffer0 < buffers[0].buf_index; iBuffer0++)
      002C6A 05 12            [12] 1739 	inc	_command_sloc4_1_0
      002C6C E4               [12] 1740 	clr	a
      002C6D B5 12 02         [24] 1741 	cjne	a,_command_sloc4_1_0,00352$
      002C70 05 13            [12] 1742 	inc	(_command_sloc4_1_0 + 1)
      002C72                       1743 00352$:
      002C72 D0 03            [24] 1744 	pop	ar3
      002C74 D0 02            [24] 1745 	pop	ar2
      002C76 D0 01            [24] 1746 	pop	ar1
      002C78 02 2B 7C         [24] 1747 	ljmp	00164$
      002C7B                       1748 00140$:
                                   1749 ;	uart.c:232: buffers[0].buffer_pointer[0] = '\0';
      002C7B 8C 82            [24] 1750 	mov	dpl,r4
      002C7D 8D 83            [24] 1751 	mov	dph,r5
      002C7F 8E F0            [24] 1752 	mov	b,r6
      002C81 12 49 F6         [24] 1753 	lcall	__gptrget
      002C84 FC               [12] 1754 	mov	r4,a
      002C85 A3               [24] 1755 	inc	dptr
      002C86 12 49 F6         [24] 1756 	lcall	__gptrget
      002C89 FD               [12] 1757 	mov	r5,a
      002C8A A3               [24] 1758 	inc	dptr
      002C8B 12 49 F6         [24] 1759 	lcall	__gptrget
      002C8E FE               [12] 1760 	mov	r6,a
      002C8F 8C 82            [24] 1761 	mov	dpl,r4
      002C91 8D 83            [24] 1762 	mov	dph,r5
      002C93 8E F0            [24] 1763 	mov	b,r6
      002C95 E4               [12] 1764 	clr	a
      002C96 12 39 A1         [24] 1765 	lcall	__gptrput
                                   1766 ;	uart.c:233: buffers[0].buf_index = 0;
      002C99 89 82            [24] 1767 	mov	dpl,r1
      002C9B 8A 83            [24] 1768 	mov	dph,r2
      002C9D 8B F0            [24] 1769 	mov	b,r3
      002C9F 12 39 A1         [24] 1770 	lcall	__gptrput
      002CA2 A3               [24] 1771 	inc	dptr
      002CA3 12 39 A1         [24] 1772 	lcall	__gptrput
                                   1773 ;	uart.c:234: break;
      002CA6 02 2D FA         [24] 1774 	ljmp	00147$
                                   1775 ;	uart.c:237: case '=':
      002CA9                       1776 00141$:
                                   1777 ;	uart.c:238: putstr("\r\n\r\n\t *** Command for a hexdump ***\r\n");
      002CA9 90 50 36         [24] 1778 	mov	dptr,#___str_25
      002CAC 75 F0 80         [24] 1779 	mov	b,#0x80
      002CAF 12 2E 3D         [24] 1780 	lcall	_putstr
                                   1781 ;	uart.c:239: hexdump(buffers[0].buffer_pointer, buffers[0].buf_index);
      002CB2 90 1A F7         [24] 1782 	mov	dptr,#_command_PARM_2
      002CB5 E0               [24] 1783 	movx	a,@dptr
      002CB6 FC               [12] 1784 	mov	r4,a
      002CB7 A3               [24] 1785 	inc	dptr
      002CB8 E0               [24] 1786 	movx	a,@dptr
      002CB9 FD               [12] 1787 	mov	r5,a
      002CBA A3               [24] 1788 	inc	dptr
      002CBB E0               [24] 1789 	movx	a,@dptr
      002CBC FE               [12] 1790 	mov	r6,a
      002CBD 8C 82            [24] 1791 	mov	dpl,r4
      002CBF 8D 83            [24] 1792 	mov	dph,r5
      002CC1 8E F0            [24] 1793 	mov	b,r6
      002CC3 12 49 F6         [24] 1794 	lcall	__gptrget
      002CC6 F9               [12] 1795 	mov	r1,a
      002CC7 A3               [24] 1796 	inc	dptr
      002CC8 12 49 F6         [24] 1797 	lcall	__gptrget
      002CCB FA               [12] 1798 	mov	r2,a
      002CCC A3               [24] 1799 	inc	dptr
      002CCD 12 49 F6         [24] 1800 	lcall	__gptrget
      002CD0 FB               [12] 1801 	mov	r3,a
      002CD1 74 03            [12] 1802 	mov	a,#0x03
      002CD3 2C               [12] 1803 	add	a,r4
      002CD4 FC               [12] 1804 	mov	r4,a
      002CD5 E4               [12] 1805 	clr	a
      002CD6 3D               [12] 1806 	addc	a,r5
      002CD7 FD               [12] 1807 	mov	r5,a
      002CD8 8C 82            [24] 1808 	mov	dpl,r4
      002CDA 8D 83            [24] 1809 	mov	dph,r5
      002CDC 8E F0            [24] 1810 	mov	b,r6
      002CDE 12 49 F6         [24] 1811 	lcall	__gptrget
      002CE1 FC               [12] 1812 	mov	r4,a
      002CE2 A3               [24] 1813 	inc	dptr
      002CE3 12 49 F6         [24] 1814 	lcall	__gptrget
      002CE6 FD               [12] 1815 	mov	r5,a
      002CE7 90 1B 24         [24] 1816 	mov	dptr,#_hexdump_PARM_2
      002CEA EC               [12] 1817 	mov	a,r4
      002CEB F0               [24] 1818 	movx	@dptr,a
      002CEC ED               [12] 1819 	mov	a,r5
      002CED A3               [24] 1820 	inc	dptr
      002CEE F0               [24] 1821 	movx	@dptr,a
      002CEF ED               [12] 1822 	mov	a,r5
      002CF0 33               [12] 1823 	rlc	a
      002CF1 95 E0            [12] 1824 	subb	a,acc
      002CF3 A3               [24] 1825 	inc	dptr
      002CF4 F0               [24] 1826 	movx	@dptr,a
      002CF5 A3               [24] 1827 	inc	dptr
      002CF6 F0               [24] 1828 	movx	@dptr,a
      002CF7 89 82            [24] 1829 	mov	dpl,r1
      002CF9 8A 83            [24] 1830 	mov	dph,r2
      002CFB 8B F0            [24] 1831 	mov	b,r3
      002CFD 12 31 99         [24] 1832 	lcall	_hexdump
                                   1833 ;	uart.c:240: break;
      002D00 02 2D FA         [24] 1834 	ljmp	00147$
                                   1835 ;	uart.c:242: case '@':
      002D03                       1836 00142$:
                                   1837 ;	uart.c:244: putstr("\r\n\r\n\t *** Command for freeing memory ***\r\n");
      002D03 90 50 5C         [24] 1838 	mov	dptr,#___str_26
      002D06 75 F0 80         [24] 1839 	mov	b,#0x80
      002D09 12 2E 3D         [24] 1840 	lcall	_putstr
                                   1841 ;	uart.c:245: for (int iBuffer = 0; iBuffer < MAX_NUM_OF_BUFFERS; iBuffer++)
      002D0C 90 1A F7         [24] 1842 	mov	dptr,#_command_PARM_2
      002D0F E0               [24] 1843 	movx	a,@dptr
      002D10 FC               [12] 1844 	mov	r4,a
      002D11 A3               [24] 1845 	inc	dptr
      002D12 E0               [24] 1846 	movx	a,@dptr
      002D13 FD               [12] 1847 	mov	r5,a
      002D14 A3               [24] 1848 	inc	dptr
      002D15 E0               [24] 1849 	movx	a,@dptr
      002D16 FE               [12] 1850 	mov	r6,a
      002D17 7A 00            [12] 1851 	mov	r2,#0x00
      002D19 7B 00            [12] 1852 	mov	r3,#0x00
      002D1B                       1853 00167$:
      002D1B C3               [12] 1854 	clr	c
      002D1C EA               [12] 1855 	mov	a,r2
      002D1D 94 D2            [12] 1856 	subb	a,#0xd2
      002D1F EB               [12] 1857 	mov	a,r3
      002D20 64 80            [12] 1858 	xrl	a,#0x80
      002D22 94 80            [12] 1859 	subb	a,#0x80
      002D24 40 03            [24] 1860 	jc	00353$
      002D26 02 2D B3         [24] 1861 	ljmp	00145$
      002D29                       1862 00353$:
                                   1863 ;	uart.c:247: if (buffers[iBuffer].buffer_pointer != 0)
      002D29 90 1B 5A         [24] 1864 	mov	dptr,#__mulint_PARM_2
      002D2C EA               [12] 1865 	mov	a,r2
      002D2D F0               [24] 1866 	movx	@dptr,a
      002D2E EB               [12] 1867 	mov	a,r3
      002D2F A3               [24] 1868 	inc	dptr
      002D30 F0               [24] 1869 	movx	@dptr,a
      002D31 90 00 09         [24] 1870 	mov	dptr,#0x0009
      002D34 C0 06            [24] 1871 	push	ar6
      002D36 C0 05            [24] 1872 	push	ar5
      002D38 C0 04            [24] 1873 	push	ar4
      002D3A C0 03            [24] 1874 	push	ar3
      002D3C C0 02            [24] 1875 	push	ar2
      002D3E 12 3A C5         [24] 1876 	lcall	__mulint
      002D41 A8 82            [24] 1877 	mov	r0,dpl
      002D43 A9 83            [24] 1878 	mov	r1,dph
      002D45 D0 02            [24] 1879 	pop	ar2
      002D47 D0 03            [24] 1880 	pop	ar3
      002D49 D0 04            [24] 1881 	pop	ar4
      002D4B D0 05            [24] 1882 	pop	ar5
      002D4D D0 06            [24] 1883 	pop	ar6
      002D4F C0 02            [24] 1884 	push	ar2
      002D51 C0 03            [24] 1885 	push	ar3
      002D53 E8               [12] 1886 	mov	a,r0
      002D54 2C               [12] 1887 	add	a,r4
      002D55 F8               [12] 1888 	mov	r0,a
      002D56 E9               [12] 1889 	mov	a,r1
      002D57 3D               [12] 1890 	addc	a,r5
      002D58 F9               [12] 1891 	mov	r1,a
      002D59 8E 03            [24] 1892 	mov	ar3,r6
      002D5B 88 82            [24] 1893 	mov	dpl,r0
      002D5D 89 83            [24] 1894 	mov	dph,r1
      002D5F 8B F0            [24] 1895 	mov	b,r3
      002D61 12 49 F6         [24] 1896 	lcall	__gptrget
      002D64 F5 12            [12] 1897 	mov	_command_sloc4_1_0,a
      002D66 A3               [24] 1898 	inc	dptr
      002D67 12 49 F6         [24] 1899 	lcall	__gptrget
      002D6A F5 13            [12] 1900 	mov	(_command_sloc4_1_0 + 1),a
      002D6C A3               [24] 1901 	inc	dptr
      002D6D 12 49 F6         [24] 1902 	lcall	__gptrget
      002D70 F5 14            [12] 1903 	mov	(_command_sloc4_1_0 + 2),a
      002D72 D0 03            [24] 1904 	pop	ar3
      002D74 D0 02            [24] 1905 	pop	ar2
      002D76 E5 12            [12] 1906 	mov	a,_command_sloc4_1_0
      002D78 45 13            [12] 1907 	orl	a,(_command_sloc4_1_0 + 1)
      002D7A 60 2F            [24] 1908 	jz	00168$
                                   1909 ;	uart.c:248: free(buffers[iBuffer].buffer_pointer);
      002D7C C0 04            [24] 1910 	push	ar4
      002D7E C0 05            [24] 1911 	push	ar5
      002D80 C0 06            [24] 1912 	push	ar6
      002D82 A8 12            [24] 1913 	mov	r0,_command_sloc4_1_0
      002D84 A9 13            [24] 1914 	mov	r1,(_command_sloc4_1_0 + 1)
      002D86 AE 14            [24] 1915 	mov	r6,(_command_sloc4_1_0 + 2)
      002D88 88 82            [24] 1916 	mov	dpl,r0
      002D8A 89 83            [24] 1917 	mov	dph,r1
      002D8C 8E F0            [24] 1918 	mov	b,r6
      002D8E C0 06            [24] 1919 	push	ar6
      002D90 C0 05            [24] 1920 	push	ar5
      002D92 C0 04            [24] 1921 	push	ar4
      002D94 C0 03            [24] 1922 	push	ar3
      002D96 C0 02            [24] 1923 	push	ar2
      002D98 12 36 94         [24] 1924 	lcall	_free
      002D9B D0 02            [24] 1925 	pop	ar2
      002D9D D0 03            [24] 1926 	pop	ar3
      002D9F D0 04            [24] 1927 	pop	ar4
      002DA1 D0 05            [24] 1928 	pop	ar5
      002DA3 D0 06            [24] 1929 	pop	ar6
                                   1930 ;	uart.c:265: putstr("Enter command (+, -, ?, =, @) or input: ");
      002DA5 D0 06            [24] 1931 	pop	ar6
      002DA7 D0 05            [24] 1932 	pop	ar5
      002DA9 D0 04            [24] 1933 	pop	ar4
                                   1934 ;	uart.c:248: free(buffers[iBuffer].buffer_pointer);
      002DAB                       1935 00168$:
                                   1936 ;	uart.c:245: for (int iBuffer = 0; iBuffer < MAX_NUM_OF_BUFFERS; iBuffer++)
      002DAB 0A               [12] 1937 	inc	r2
      002DAC BA 00 01         [24] 1938 	cjne	r2,#0x00,00355$
      002DAF 0B               [12] 1939 	inc	r3
      002DB0                       1940 00355$:
      002DB0 02 2D 1B         [24] 1941 	ljmp	00167$
      002DB3                       1942 00145$:
                                   1943 ;	uart.c:250: printf("\r\n\r\n\t\tMemory has been freed\r\n\r\n");
      002DB3 74 87            [12] 1944 	mov	a,#___str_27
      002DB5 C0 E0            [24] 1945 	push	acc
      002DB7 74 50            [12] 1946 	mov	a,#(___str_27 >> 8)
      002DB9 C0 E0            [24] 1947 	push	acc
      002DBB 74 80            [12] 1948 	mov	a,#0x80
      002DBD C0 E0            [24] 1949 	push	acc
      002DBF 12 3F D4         [24] 1950 	lcall	_printf
      002DC2 15 81            [12] 1951 	dec	sp
      002DC4 15 81            [12] 1952 	dec	sp
      002DC6 15 81            [12] 1953 	dec	sp
                                   1954 ;	uart.c:251: putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
      002DC8 90 50 A7         [24] 1955 	mov	dptr,#___str_28
      002DCB 75 F0 80         [24] 1956 	mov	b,#0x80
      002DCE 12 2E 3D         [24] 1957 	lcall	_putstr
                                   1958 ;	uart.c:252: putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
      002DD1 90 50 A7         [24] 1959 	mov	dptr,#___str_28
      002DD4 75 F0 80         [24] 1960 	mov	b,#0x80
      002DD7 12 2E 3D         [24] 1961 	lcall	_putstr
                                   1962 ;	uart.c:253: main();
      002DDA 12 20 AF         [24] 1963 	lcall	_main
                                   1964 ;	uart.c:254: break;
                                   1965 ;	uart.c:257: default:
      002DDD 80 1B            [24] 1966 	sjmp	00147$
      002DDF                       1967 00146$:
                                   1968 ;	uart.c:258: printf("\r\n\r\n\t Error: Received invalid command '%c'\r\n", received_char);
      002DDF 7E 00            [12] 1969 	mov	r6,#0x00
      002DE1 C0 07            [24] 1970 	push	ar7
      002DE3 C0 06            [24] 1971 	push	ar6
      002DE5 74 F4            [12] 1972 	mov	a,#___str_29
      002DE7 C0 E0            [24] 1973 	push	acc
      002DE9 74 50            [12] 1974 	mov	a,#(___str_29 >> 8)
      002DEB C0 E0            [24] 1975 	push	acc
      002DED 74 80            [12] 1976 	mov	a,#0x80
      002DEF C0 E0            [24] 1977 	push	acc
      002DF1 12 3F D4         [24] 1978 	lcall	_printf
      002DF4 E5 81            [12] 1979 	mov	a,sp
      002DF6 24 FB            [12] 1980 	add	a,#0xfb
      002DF8 F5 81            [12] 1981 	mov	sp,a
                                   1982 ;	uart.c:262: }
      002DFA                       1983 00147$:
                                   1984 ;	uart.c:264: putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
      002DFA 90 50 A7         [24] 1985 	mov	dptr,#___str_28
      002DFD 75 F0 80         [24] 1986 	mov	b,#0x80
      002E00 12 2E 3D         [24] 1987 	lcall	_putstr
                                   1988 ;	uart.c:265: putstr("Enter command (+, -, ?, =, @) or input: ");
      002E03 90 51 21         [24] 1989 	mov	dptr,#___str_30
      002E06 75 F0 80         [24] 1990 	mov	b,#0x80
                                   1991 ;	uart.c:267: }
      002E09 02 2E 3D         [24] 1992 	ljmp	_putstr
                                   1993 ;------------------------------------------------------------
                                   1994 ;Allocation info for local variables in function 'putchar'
                                   1995 ;------------------------------------------------------------
                                   1996 ;c                         Allocated with name '_putchar_c_65536_105'
                                   1997 ;------------------------------------------------------------
                                   1998 ;	uart.c:272: int putchar(int c)
                                   1999 ;	-----------------------------------------
                                   2000 ;	 function putchar
                                   2001 ;	-----------------------------------------
      002E0C                       2002 _putchar:
      002E0C AF 83            [24] 2003 	mov	r7,dph
      002E0E E5 82            [12] 2004 	mov	a,dpl
      002E10 90 1A FD         [24] 2005 	mov	dptr,#_putchar_c_65536_105
      002E13 F0               [24] 2006 	movx	@dptr,a
      002E14 EF               [12] 2007 	mov	a,r7
      002E15 A3               [24] 2008 	inc	dptr
      002E16 F0               [24] 2009 	movx	@dptr,a
                                   2010 ;	uart.c:274: while (!TI)
      002E17                       2011 00101$:
                                   2012 ;	uart.c:276: TI = 0;
                                   2013 ;	assignBit
      002E17 10 99 02         [24] 2014 	jbc	_TI,00114$
      002E1A 80 FB            [24] 2015 	sjmp	00101$
      002E1C                       2016 00114$:
                                   2017 ;	uart.c:277: SBUF = c; // adding character to Serial buffer
      002E1C 90 1A FD         [24] 2018 	mov	dptr,#_putchar_c_65536_105
      002E1F E0               [24] 2019 	movx	a,@dptr
      002E20 FE               [12] 2020 	mov	r6,a
      002E21 A3               [24] 2021 	inc	dptr
      002E22 E0               [24] 2022 	movx	a,@dptr
      002E23 FF               [12] 2023 	mov	r7,a
      002E24 8E 99            [24] 2024 	mov	_SBUF,r6
                                   2025 ;	uart.c:278: return c;
      002E26 8E 82            [24] 2026 	mov	dpl,r6
      002E28 8F 83            [24] 2027 	mov	dph,r7
                                   2028 ;	uart.c:279: }
      002E2A 22               [24] 2029 	ret
                                   2030 ;------------------------------------------------------------
                                   2031 ;Allocation info for local variables in function 'getchar'
                                   2032 ;------------------------------------------------------------
                                   2033 ;	uart.c:288: int getchar() // Function to receive serial data
                                   2034 ;	-----------------------------------------
                                   2035 ;	 function getchar
                                   2036 ;	-----------------------------------------
      002E2B                       2037 _getchar:
                                   2038 ;	uart.c:290: P1_1 = false;
                                   2039 ;	assignBit
      002E2B C2 91            [12] 2040 	clr	_P1_1
                                   2041 ;	uart.c:291: while (!RI)
      002E2D                       2042 00101$:
                                   2043 ;	uart.c:294: RI = 0;
                                   2044 ;	assignBit
      002E2D 10 98 02         [24] 2045 	jbc	_RI,00114$
      002E30 80 FB            [24] 2046 	sjmp	00101$
      002E32                       2047 00114$:
                                   2048 ;	uart.c:296: P1_1 = true;
                                   2049 ;	assignBit
      002E32 D2 91            [12] 2050 	setb	_P1_1
                                   2051 ;	uart.c:297: return SBUF;
      002E34 AE 99            [24] 2052 	mov	r6,_SBUF
      002E36 7F 00            [12] 2053 	mov	r7,#0x00
      002E38 8E 82            [24] 2054 	mov	dpl,r6
      002E3A 8F 83            [24] 2055 	mov	dph,r7
                                   2056 ;	uart.c:298: }
      002E3C 22               [24] 2057 	ret
                                   2058 ;------------------------------------------------------------
                                   2059 ;Allocation info for local variables in function 'putstr'
                                   2060 ;------------------------------------------------------------
                                   2061 ;str                       Allocated with name '_putstr_str_65536_108'
                                   2062 ;index                     Allocated with name '_putstr_index_65536_109'
                                   2063 ;------------------------------------------------------------
                                   2064 ;	uart.c:304: int putstr(char *str)
                                   2065 ;	-----------------------------------------
                                   2066 ;	 function putstr
                                   2067 ;	-----------------------------------------
      002E3D                       2068 _putstr:
      002E3D AF F0            [24] 2069 	mov	r7,b
      002E3F AE 83            [24] 2070 	mov	r6,dph
      002E41 E5 82            [12] 2071 	mov	a,dpl
      002E43 90 1A FF         [24] 2072 	mov	dptr,#_putstr_str_65536_108
      002E46 F0               [24] 2073 	movx	@dptr,a
      002E47 EE               [12] 2074 	mov	a,r6
      002E48 A3               [24] 2075 	inc	dptr
      002E49 F0               [24] 2076 	movx	@dptr,a
      002E4A EF               [12] 2077 	mov	a,r7
      002E4B A3               [24] 2078 	inc	dptr
      002E4C F0               [24] 2079 	movx	@dptr,a
                                   2080 ;	uart.c:307: while (*str)
      002E4D 90 1A FF         [24] 2081 	mov	dptr,#_putstr_str_65536_108
      002E50 E0               [24] 2082 	movx	a,@dptr
      002E51 FD               [12] 2083 	mov	r5,a
      002E52 A3               [24] 2084 	inc	dptr
      002E53 E0               [24] 2085 	movx	a,@dptr
      002E54 FE               [12] 2086 	mov	r6,a
      002E55 A3               [24] 2087 	inc	dptr
      002E56 E0               [24] 2088 	movx	a,@dptr
      002E57 FF               [12] 2089 	mov	r7,a
      002E58 7B 00            [12] 2090 	mov	r3,#0x00
      002E5A 7C 00            [12] 2091 	mov	r4,#0x00
      002E5C                       2092 00101$:
      002E5C 8D 82            [24] 2093 	mov	dpl,r5
      002E5E 8E 83            [24] 2094 	mov	dph,r6
      002E60 8F F0            [24] 2095 	mov	b,r7
      002E62 12 49 F6         [24] 2096 	lcall	__gptrget
      002E65 FA               [12] 2097 	mov	r2,a
      002E66 60 36            [24] 2098 	jz	00108$
                                   2099 ;	uart.c:309: putchar(*str++);
      002E68 0D               [12] 2100 	inc	r5
      002E69 BD 00 01         [24] 2101 	cjne	r5,#0x00,00116$
      002E6C 0E               [12] 2102 	inc	r6
      002E6D                       2103 00116$:
      002E6D 90 1A FF         [24] 2104 	mov	dptr,#_putstr_str_65536_108
      002E70 ED               [12] 2105 	mov	a,r5
      002E71 F0               [24] 2106 	movx	@dptr,a
      002E72 EE               [12] 2107 	mov	a,r6
      002E73 A3               [24] 2108 	inc	dptr
      002E74 F0               [24] 2109 	movx	@dptr,a
      002E75 EF               [12] 2110 	mov	a,r7
      002E76 A3               [24] 2111 	inc	dptr
      002E77 F0               [24] 2112 	movx	@dptr,a
      002E78 8A 01            [24] 2113 	mov	ar1,r2
      002E7A 7A 00            [12] 2114 	mov	r2,#0x00
      002E7C 89 82            [24] 2115 	mov	dpl,r1
      002E7E 8A 83            [24] 2116 	mov	dph,r2
      002E80 C0 07            [24] 2117 	push	ar7
      002E82 C0 06            [24] 2118 	push	ar6
      002E84 C0 05            [24] 2119 	push	ar5
      002E86 C0 04            [24] 2120 	push	ar4
      002E88 C0 03            [24] 2121 	push	ar3
      002E8A 12 2E 0C         [24] 2122 	lcall	_putchar
      002E8D D0 03            [24] 2123 	pop	ar3
      002E8F D0 04            [24] 2124 	pop	ar4
      002E91 D0 05            [24] 2125 	pop	ar5
      002E93 D0 06            [24] 2126 	pop	ar6
      002E95 D0 07            [24] 2127 	pop	ar7
                                   2128 ;	uart.c:310: index++;
      002E97 0B               [12] 2129 	inc	r3
      002E98 BB 00 C1         [24] 2130 	cjne	r3,#0x00,00101$
      002E9B 0C               [12] 2131 	inc	r4
      002E9C 80 BE            [24] 2132 	sjmp	00101$
      002E9E                       2133 00108$:
      002E9E 90 1A FF         [24] 2134 	mov	dptr,#_putstr_str_65536_108
      002EA1 ED               [12] 2135 	mov	a,r5
      002EA2 F0               [24] 2136 	movx	@dptr,a
      002EA3 EE               [12] 2137 	mov	a,r6
      002EA4 A3               [24] 2138 	inc	dptr
      002EA5 F0               [24] 2139 	movx	@dptr,a
      002EA6 EF               [12] 2140 	mov	a,r7
      002EA7 A3               [24] 2141 	inc	dptr
      002EA8 F0               [24] 2142 	movx	@dptr,a
                                   2143 ;	uart.c:312: return index + 1;
      002EA9 0B               [12] 2144 	inc	r3
      002EAA BB 00 01         [24] 2145 	cjne	r3,#0x00,00118$
      002EAD 0C               [12] 2146 	inc	r4
      002EAE                       2147 00118$:
      002EAE 8B 82            [24] 2148 	mov	dpl,r3
      002EB0 8C 83            [24] 2149 	mov	dph,r4
                                   2150 ;	uart.c:313: }
      002EB2 22               [24] 2151 	ret
                                   2152 ;------------------------------------------------------------
                                   2153 ;Allocation info for local variables in function 'accept_number_from_user'
                                   2154 ;------------------------------------------------------------
                                   2155 ;received_char             Allocated with name '_accept_number_from_user_received_char_65536_111'
                                   2156 ;number_in_char            Allocated with name '_accept_number_from_user_number_in_char_65536_111'
                                   2157 ;valid_number_status       Allocated with name '_accept_number_from_user_valid_number_status_65536_111'
                                   2158 ;number                    Allocated with name '_accept_number_from_user_number_65536_111'
                                   2159 ;i                         Allocated with name '_accept_number_from_user_i_65536_111'
                                   2160 ;------------------------------------------------------------
                                   2161 ;	uart.c:319: int accept_number_from_user()
                                   2162 ;	-----------------------------------------
                                   2163 ;	 function accept_number_from_user
                                   2164 ;	-----------------------------------------
      002EB3                       2165 _accept_number_from_user:
                                   2166 ;	uart.c:321: char received_char = '`';
      002EB3 90 1B 02         [24] 2167 	mov	dptr,#_accept_number_from_user_received_char_65536_111
      002EB6 74 60            [12] 2168 	mov	a,#0x60
      002EB8 F0               [24] 2169 	movx	@dptr,a
                                   2170 ;	uart.c:322: char number_in_char[25] = "\0";
      002EB9 90 1B 03         [24] 2171 	mov	dptr,#_accept_number_from_user_number_in_char_65536_111
      002EBC E4               [12] 2172 	clr	a
      002EBD F0               [24] 2173 	movx	@dptr,a
      002EBE 90 1B 04         [24] 2174 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0001)
      002EC1 F0               [24] 2175 	movx	@dptr,a
      002EC2 90 1B 05         [24] 2176 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0002)
      002EC5 F0               [24] 2177 	movx	@dptr,a
      002EC6 90 1B 06         [24] 2178 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0003)
      002EC9 F0               [24] 2179 	movx	@dptr,a
      002ECA 90 1B 07         [24] 2180 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0004)
      002ECD F0               [24] 2181 	movx	@dptr,a
      002ECE 90 1B 08         [24] 2182 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0005)
      002ED1 F0               [24] 2183 	movx	@dptr,a
      002ED2 90 1B 09         [24] 2184 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0006)
      002ED5 F0               [24] 2185 	movx	@dptr,a
      002ED6 90 1B 0A         [24] 2186 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0007)
      002ED9 F0               [24] 2187 	movx	@dptr,a
      002EDA 90 1B 0B         [24] 2188 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0008)
      002EDD F0               [24] 2189 	movx	@dptr,a
      002EDE 90 1B 0C         [24] 2190 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0009)
      002EE1 F0               [24] 2191 	movx	@dptr,a
      002EE2 90 1B 0D         [24] 2192 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x000a)
      002EE5 F0               [24] 2193 	movx	@dptr,a
      002EE6 90 1B 0E         [24] 2194 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x000b)
      002EE9 F0               [24] 2195 	movx	@dptr,a
      002EEA 90 1B 0F         [24] 2196 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x000c)
      002EED F0               [24] 2197 	movx	@dptr,a
      002EEE 90 1B 10         [24] 2198 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x000d)
      002EF1 F0               [24] 2199 	movx	@dptr,a
      002EF2 90 1B 11         [24] 2200 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x000e)
      002EF5 F0               [24] 2201 	movx	@dptr,a
      002EF6 90 1B 12         [24] 2202 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x000f)
      002EF9 F0               [24] 2203 	movx	@dptr,a
      002EFA 90 1B 13         [24] 2204 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0010)
      002EFD F0               [24] 2205 	movx	@dptr,a
      002EFE 90 1B 14         [24] 2206 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0011)
      002F01 F0               [24] 2207 	movx	@dptr,a
      002F02 90 1B 15         [24] 2208 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0012)
      002F05 F0               [24] 2209 	movx	@dptr,a
      002F06 90 1B 16         [24] 2210 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0013)
      002F09 F0               [24] 2211 	movx	@dptr,a
      002F0A 90 1B 17         [24] 2212 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0014)
      002F0D F0               [24] 2213 	movx	@dptr,a
      002F0E 90 1B 18         [24] 2214 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0015)
      002F11 F0               [24] 2215 	movx	@dptr,a
      002F12 90 1B 19         [24] 2216 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0016)
      002F15 F0               [24] 2217 	movx	@dptr,a
      002F16 90 1B 1A         [24] 2218 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0017)
      002F19 F0               [24] 2219 	movx	@dptr,a
      002F1A 90 1B 1B         [24] 2220 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_111 + 0x0018)
      002F1D F0               [24] 2221 	movx	@dptr,a
                                   2222 ;	uart.c:323: bool valid_number_status = false;
      002F1E 90 1B 1C         [24] 2223 	mov	dptr,#_accept_number_from_user_valid_number_status_65536_111
      002F21 F0               [24] 2224 	movx	@dptr,a
                                   2225 ;	uart.c:324: int number = 0;
      002F22 90 1B 1D         [24] 2226 	mov	dptr,#_accept_number_from_user_number_65536_111
      002F25 F0               [24] 2227 	movx	@dptr,a
      002F26 A3               [24] 2228 	inc	dptr
      002F27 F0               [24] 2229 	movx	@dptr,a
                                   2230 ;	uart.c:325: int i = 0;
      002F28 90 1B 1F         [24] 2231 	mov	dptr,#_accept_number_from_user_i_65536_111
      002F2B F0               [24] 2232 	movx	@dptr,a
      002F2C A3               [24] 2233 	inc	dptr
      002F2D F0               [24] 2234 	movx	@dptr,a
                                   2235 ;	uart.c:326: while (valid_number_status == false)
      002F2E                       2236 00110$:
      002F2E 90 1B 1C         [24] 2237 	mov	dptr,#_accept_number_from_user_valid_number_status_65536_111
      002F31 E0               [24] 2238 	movx	a,@dptr
      002F32 60 03            [24] 2239 	jz	00139$
      002F34 02 30 31         [24] 2240 	ljmp	00112$
      002F37                       2241 00139$:
                                   2242 ;	uart.c:328: received_char = getchar();
      002F37 12 2E 2B         [24] 2243 	lcall	_getchar
      002F3A AE 82            [24] 2244 	mov	r6,dpl
      002F3C 90 1B 02         [24] 2245 	mov	dptr,#_accept_number_from_user_received_char_65536_111
      002F3F EE               [12] 2246 	mov	a,r6
      002F40 F0               [24] 2247 	movx	@dptr,a
                                   2248 ;	uart.c:329: i++;
      002F41 90 1B 1F         [24] 2249 	mov	dptr,#_accept_number_from_user_i_65536_111
      002F44 E0               [24] 2250 	movx	a,@dptr
      002F45 24 01            [12] 2251 	add	a,#0x01
      002F47 F0               [24] 2252 	movx	@dptr,a
      002F48 A3               [24] 2253 	inc	dptr
      002F49 E0               [24] 2254 	movx	a,@dptr
      002F4A 34 00            [12] 2255 	addc	a,#0x00
      002F4C F0               [24] 2256 	movx	@dptr,a
                                   2257 ;	uart.c:330: echo(received_char);
      002F4D 8E 82            [24] 2258 	mov	dpl,r6
      002F4F 12 23 D7         [24] 2259 	lcall	_echo
                                   2260 ;	uart.c:332: if (!(received_char >= '0' && received_char <= '9') && (received_char != '\r'))
      002F52 90 1B 02         [24] 2261 	mov	dptr,#_accept_number_from_user_received_char_65536_111
      002F55 E0               [24] 2262 	movx	a,@dptr
      002F56 FF               [12] 2263 	mov	r7,a
      002F57 BF 30 00         [24] 2264 	cjne	r7,#0x30,00140$
      002F5A                       2265 00140$:
      002F5A 40 05            [24] 2266 	jc	00107$
      002F5C EF               [12] 2267 	mov	a,r7
      002F5D 24 C6            [12] 2268 	add	a,#0xff - 0x39
      002F5F 50 33            [24] 2269 	jnc	00104$
      002F61                       2270 00107$:
      002F61 90 1B 02         [24] 2271 	mov	dptr,#_accept_number_from_user_received_char_65536_111
      002F64 E0               [24] 2272 	movx	a,@dptr
      002F65 FF               [12] 2273 	mov	r7,a
      002F66 BF 0D 02         [24] 2274 	cjne	r7,#0x0d,00143$
      002F69 80 29            [24] 2275 	sjmp	00104$
      002F6B                       2276 00143$:
                                   2277 ;	uart.c:335: memset(number_in_char, 0, sizeof(number_in_char));
      002F6B 90 1B 4A         [24] 2278 	mov	dptr,#_memset_PARM_2
      002F6E E4               [12] 2279 	clr	a
      002F6F F0               [24] 2280 	movx	@dptr,a
      002F70 90 1B 4B         [24] 2281 	mov	dptr,#_memset_PARM_3
      002F73 74 19            [12] 2282 	mov	a,#0x19
      002F75 F0               [24] 2283 	movx	@dptr,a
      002F76 E4               [12] 2284 	clr	a
      002F77 A3               [24] 2285 	inc	dptr
      002F78 F0               [24] 2286 	movx	@dptr,a
      002F79 90 1B 03         [24] 2287 	mov	dptr,#_accept_number_from_user_number_in_char_65536_111
      002F7C 75 F0 00         [24] 2288 	mov	b,#0x00
      002F7F 12 37 EB         [24] 2289 	lcall	_memset
                                   2290 ;	uart.c:336: putstr("\r\n\t\t Error: Re-enter the number: ");
      002F82 90 51 4A         [24] 2291 	mov	dptr,#___str_32
      002F85 75 F0 80         [24] 2292 	mov	b,#0x80
      002F88 12 2E 3D         [24] 2293 	lcall	_putstr
                                   2294 ;	uart.c:337: i = 0;
      002F8B 90 1B 1F         [24] 2295 	mov	dptr,#_accept_number_from_user_i_65536_111
      002F8E E4               [12] 2296 	clr	a
      002F8F F0               [24] 2297 	movx	@dptr,a
      002F90 A3               [24] 2298 	inc	dptr
      002F91 F0               [24] 2299 	movx	@dptr,a
      002F92 80 36            [24] 2300 	sjmp	00105$
      002F94                       2301 00104$:
                                   2302 ;	uart.c:341: else if (received_char == '\r')
      002F94 90 1B 02         [24] 2303 	mov	dptr,#_accept_number_from_user_received_char_65536_111
      002F97 E0               [24] 2304 	movx	a,@dptr
      002F98 FF               [12] 2305 	mov	r7,a
      002F99 BF 0D 2E         [24] 2306 	cjne	r7,#0x0d,00105$
                                   2307 ;	uart.c:343: strcat(number_in_char, '\0');
      002F9C 90 1B 53         [24] 2308 	mov	dptr,#_strcat_PARM_2
      002F9F E4               [12] 2309 	clr	a
      002FA0 F0               [24] 2310 	movx	@dptr,a
      002FA1 A3               [24] 2311 	inc	dptr
      002FA2 F0               [24] 2312 	movx	@dptr,a
      002FA3 A3               [24] 2313 	inc	dptr
      002FA4 F0               [24] 2314 	movx	@dptr,a
      002FA5 90 1B 03         [24] 2315 	mov	dptr,#_accept_number_from_user_number_in_char_65536_111
      002FA8 75 F0 00         [24] 2316 	mov	b,#0x00
      002FAB 12 39 33         [24] 2317 	lcall	_strcat
                                   2318 ;	uart.c:344: number = atoi(number_in_char);
      002FAE 90 1B 03         [24] 2319 	mov	dptr,#_accept_number_from_user_number_in_char_65536_111
      002FB1 75 F0 00         [24] 2320 	mov	b,#0x00
      002FB4 12 38 13         [24] 2321 	lcall	_atoi
      002FB7 E5 82            [12] 2322 	mov	a,dpl
      002FB9 85 83 F0         [24] 2323 	mov	b,dph
      002FBC 90 1B 1D         [24] 2324 	mov	dptr,#_accept_number_from_user_number_65536_111
      002FBF F0               [24] 2325 	movx	@dptr,a
      002FC0 E5 F0            [12] 2326 	mov	a,b
      002FC2 A3               [24] 2327 	inc	dptr
      002FC3 F0               [24] 2328 	movx	@dptr,a
                                   2329 ;	uart.c:345: valid_number_status = true;
      002FC4 90 1B 1C         [24] 2330 	mov	dptr,#_accept_number_from_user_valid_number_status_65536_111
      002FC7 74 01            [12] 2331 	mov	a,#0x01
      002FC9 F0               [24] 2332 	movx	@dptr,a
      002FCA                       2333 00105$:
                                   2334 ;	uart.c:348: strncat(number_in_char, &received_char, 1);
      002FCA 90 1B 6D         [24] 2335 	mov	dptr,#_strncat_PARM_2
      002FCD 74 02            [12] 2336 	mov	a,#_accept_number_from_user_received_char_65536_111
      002FCF F0               [24] 2337 	movx	@dptr,a
      002FD0 74 1B            [12] 2338 	mov	a,#(_accept_number_from_user_received_char_65536_111 >> 8)
      002FD2 A3               [24] 2339 	inc	dptr
      002FD3 F0               [24] 2340 	movx	@dptr,a
      002FD4 E4               [12] 2341 	clr	a
      002FD5 A3               [24] 2342 	inc	dptr
      002FD6 F0               [24] 2343 	movx	@dptr,a
      002FD7 90 1B 70         [24] 2344 	mov	dptr,#_strncat_PARM_3
      002FDA 04               [12] 2345 	inc	a
      002FDB F0               [24] 2346 	movx	@dptr,a
      002FDC E4               [12] 2347 	clr	a
      002FDD A3               [24] 2348 	inc	dptr
      002FDE F0               [24] 2349 	movx	@dptr,a
      002FDF 90 1B 03         [24] 2350 	mov	dptr,#_accept_number_from_user_number_in_char_65536_111
      002FE2 75 F0 00         [24] 2351 	mov	b,#0x00
      002FE5 12 3D 9E         [24] 2352 	lcall	_strncat
                                   2353 ;	uart.c:350: if (i >= 24)
      002FE8 90 1B 1F         [24] 2354 	mov	dptr,#_accept_number_from_user_i_65536_111
      002FEB E0               [24] 2355 	movx	a,@dptr
      002FEC FE               [12] 2356 	mov	r6,a
      002FED A3               [24] 2357 	inc	dptr
      002FEE E0               [24] 2358 	movx	a,@dptr
      002FEF FF               [12] 2359 	mov	r7,a
      002FF0 C3               [12] 2360 	clr	c
      002FF1 EE               [12] 2361 	mov	a,r6
      002FF2 94 18            [12] 2362 	subb	a,#0x18
      002FF4 EF               [12] 2363 	mov	a,r7
      002FF5 64 80            [12] 2364 	xrl	a,#0x80
      002FF7 94 80            [12] 2365 	subb	a,#0x80
      002FF9 50 03            [24] 2366 	jnc	00146$
      002FFB 02 2F 2E         [24] 2367 	ljmp	00110$
      002FFE                       2368 00146$:
                                   2369 ;	uart.c:352: putstr("\r\n\t\t Error: Reading a number failed, Reached maximum length supported");
      002FFE 90 51 6C         [24] 2370 	mov	dptr,#___str_33
      003001 75 F0 80         [24] 2371 	mov	b,#0x80
      003004 12 2E 3D         [24] 2372 	lcall	_putstr
                                   2373 ;	uart.c:353: putstr("\r\n\t\t Error: Re-enter the number: ");
      003007 90 51 4A         [24] 2374 	mov	dptr,#___str_32
      00300A 75 F0 80         [24] 2375 	mov	b,#0x80
      00300D 12 2E 3D         [24] 2376 	lcall	_putstr
                                   2377 ;	uart.c:355: memset(number_in_char, 0, sizeof(number_in_char));
      003010 90 1B 4A         [24] 2378 	mov	dptr,#_memset_PARM_2
      003013 E4               [12] 2379 	clr	a
      003014 F0               [24] 2380 	movx	@dptr,a
      003015 90 1B 4B         [24] 2381 	mov	dptr,#_memset_PARM_3
      003018 74 19            [12] 2382 	mov	a,#0x19
      00301A F0               [24] 2383 	movx	@dptr,a
      00301B E4               [12] 2384 	clr	a
      00301C A3               [24] 2385 	inc	dptr
      00301D F0               [24] 2386 	movx	@dptr,a
      00301E 90 1B 03         [24] 2387 	mov	dptr,#_accept_number_from_user_number_in_char_65536_111
      003021 75 F0 00         [24] 2388 	mov	b,#0x00
      003024 12 37 EB         [24] 2389 	lcall	_memset
                                   2390 ;	uart.c:356: i = 0;
      003027 90 1B 1F         [24] 2391 	mov	dptr,#_accept_number_from_user_i_65536_111
      00302A E4               [12] 2392 	clr	a
      00302B F0               [24] 2393 	movx	@dptr,a
      00302C A3               [24] 2394 	inc	dptr
      00302D F0               [24] 2395 	movx	@dptr,a
      00302E 02 2F 2E         [24] 2396 	ljmp	00110$
      003031                       2397 00112$:
                                   2398 ;	uart.c:359: return number;
      003031 90 1B 1D         [24] 2399 	mov	dptr,#_accept_number_from_user_number_65536_111
      003034 E0               [24] 2400 	movx	a,@dptr
      003035 FE               [12] 2401 	mov	r6,a
      003036 A3               [24] 2402 	inc	dptr
      003037 E0               [24] 2403 	movx	a,@dptr
                                   2404 ;	uart.c:360: }
      003038 8E 82            [24] 2405 	mov	dpl,r6
      00303A F5 83            [12] 2406 	mov	dph,a
      00303C 22               [24] 2407 	ret
                                   2408 ;------------------------------------------------------------
                                   2409 ;Allocation info for local variables in function 'print_buffers'
                                   2410 ;------------------------------------------------------------
                                   2411 ;sloc0                     Allocated with name '_print_buffers_sloc0_1_0'
                                   2412 ;buffers                   Allocated with name '_print_buffers_buffers_65536_116'
                                   2413 ;i                         Allocated with name '_print_buffers_i_131072_118'
                                   2414 ;------------------------------------------------------------
                                   2415 ;	uart.c:365: void print_buffers(buffer_t *buffers)
                                   2416 ;	-----------------------------------------
                                   2417 ;	 function print_buffers
                                   2418 ;	-----------------------------------------
      00303D                       2419 _print_buffers:
      00303D AF F0            [24] 2420 	mov	r7,b
      00303F AE 83            [24] 2421 	mov	r6,dph
      003041 E5 82            [12] 2422 	mov	a,dpl
      003043 90 1B 21         [24] 2423 	mov	dptr,#_print_buffers_buffers_65536_116
      003046 F0               [24] 2424 	movx	@dptr,a
      003047 EE               [12] 2425 	mov	a,r6
      003048 A3               [24] 2426 	inc	dptr
      003049 F0               [24] 2427 	movx	@dptr,a
      00304A EF               [12] 2428 	mov	a,r7
      00304B A3               [24] 2429 	inc	dptr
      00304C F0               [24] 2430 	movx	@dptr,a
                                   2431 ;	uart.c:367: printf_tiny("\r\n\r\n\t\t-------------------------");
      00304D 74 9C            [12] 2432 	mov	a,#___str_8
      00304F C0 E0            [24] 2433 	push	acc
      003051 74 4D            [12] 2434 	mov	a,#(___str_8 >> 8)
      003053 C0 E0            [24] 2435 	push	acc
      003055 12 39 BC         [24] 2436 	lcall	_printf_tiny
      003058 15 81            [12] 2437 	dec	sp
      00305A 15 81            [12] 2438 	dec	sp
                                   2439 ;	uart.c:368: printf_tiny("\r\n\t\t| buffer id |\tsize\t|");
      00305C 74 B2            [12] 2440 	mov	a,#___str_34
      00305E C0 E0            [24] 2441 	push	acc
      003060 74 51            [12] 2442 	mov	a,#(___str_34 >> 8)
      003062 C0 E0            [24] 2443 	push	acc
      003064 12 39 BC         [24] 2444 	lcall	_printf_tiny
      003067 15 81            [12] 2445 	dec	sp
      003069 15 81            [12] 2446 	dec	sp
                                   2447 ;	uart.c:369: printf_tiny("\r\n\t\t-------------------------");
      00306B 74 D3            [12] 2448 	mov	a,#___str_10
      00306D C0 E0            [24] 2449 	push	acc
      00306F 74 4D            [12] 2450 	mov	a,#(___str_10 >> 8)
      003071 C0 E0            [24] 2451 	push	acc
      003073 12 39 BC         [24] 2452 	lcall	_printf_tiny
      003076 15 81            [12] 2453 	dec	sp
      003078 15 81            [12] 2454 	dec	sp
                                   2455 ;	uart.c:370: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
      00307A 90 1B 21         [24] 2456 	mov	dptr,#_print_buffers_buffers_65536_116
      00307D E0               [24] 2457 	movx	a,@dptr
      00307E FD               [12] 2458 	mov	r5,a
      00307F A3               [24] 2459 	inc	dptr
      003080 E0               [24] 2460 	movx	a,@dptr
      003081 FE               [12] 2461 	mov	r6,a
      003082 A3               [24] 2462 	inc	dptr
      003083 E0               [24] 2463 	movx	a,@dptr
      003084 FF               [12] 2464 	mov	r7,a
      003085 8D 15            [24] 2465 	mov	_print_buffers_sloc0_1_0,r5
      003087 8E 16            [24] 2466 	mov	(_print_buffers_sloc0_1_0 + 1),r6
      003089 8F 17            [24] 2467 	mov	(_print_buffers_sloc0_1_0 + 2),r7
      00308B 78 00            [12] 2468 	mov	r0,#0x00
      00308D 79 00            [12] 2469 	mov	r1,#0x00
      00308F                       2470 00107$:
      00308F C3               [12] 2471 	clr	c
      003090 E8               [12] 2472 	mov	a,r0
      003091 94 D2            [12] 2473 	subb	a,#0xd2
      003093 E9               [12] 2474 	mov	a,r1
      003094 64 80            [12] 2475 	xrl	a,#0x80
      003096 94 80            [12] 2476 	subb	a,#0x80
      003098 40 03            [24] 2477 	jc	00128$
      00309A 02 31 89         [24] 2478 	ljmp	00105$
      00309D                       2479 00128$:
                                   2480 ;	uart.c:372: if ((buffers[i].buffer_pointer != 0) || (i == 0) || (i == 1))
      00309D 90 1B 5A         [24] 2481 	mov	dptr,#__mulint_PARM_2
      0030A0 E8               [12] 2482 	mov	a,r0
      0030A1 F0               [24] 2483 	movx	@dptr,a
      0030A2 E9               [12] 2484 	mov	a,r1
      0030A3 A3               [24] 2485 	inc	dptr
      0030A4 F0               [24] 2486 	movx	@dptr,a
      0030A5 90 00 09         [24] 2487 	mov	dptr,#0x0009
      0030A8 C0 07            [24] 2488 	push	ar7
      0030AA C0 06            [24] 2489 	push	ar6
      0030AC C0 05            [24] 2490 	push	ar5
      0030AE C0 01            [24] 2491 	push	ar1
      0030B0 C0 00            [24] 2492 	push	ar0
      0030B2 12 3A C5         [24] 2493 	lcall	__mulint
      0030B5 AB 82            [24] 2494 	mov	r3,dpl
      0030B7 AC 83            [24] 2495 	mov	r4,dph
      0030B9 D0 00            [24] 2496 	pop	ar0
      0030BB D0 01            [24] 2497 	pop	ar1
      0030BD D0 05            [24] 2498 	pop	ar5
      0030BF D0 06            [24] 2499 	pop	ar6
      0030C1 D0 07            [24] 2500 	pop	ar7
      0030C3 EB               [12] 2501 	mov	a,r3
      0030C4 2D               [12] 2502 	add	a,r5
      0030C5 FB               [12] 2503 	mov	r3,a
      0030C6 EC               [12] 2504 	mov	a,r4
      0030C7 3E               [12] 2505 	addc	a,r6
      0030C8 FC               [12] 2506 	mov	r4,a
      0030C9 8F 02            [24] 2507 	mov	ar2,r7
      0030CB 8B 82            [24] 2508 	mov	dpl,r3
      0030CD 8C 83            [24] 2509 	mov	dph,r4
      0030CF 8A F0            [24] 2510 	mov	b,r2
      0030D1 12 49 F6         [24] 2511 	lcall	__gptrget
      0030D4 FB               [12] 2512 	mov	r3,a
      0030D5 A3               [24] 2513 	inc	dptr
      0030D6 12 49 F6         [24] 2514 	lcall	__gptrget
      0030D9 FC               [12] 2515 	mov	r4,a
      0030DA A3               [24] 2516 	inc	dptr
      0030DB 12 49 F6         [24] 2517 	lcall	__gptrget
      0030DE FA               [12] 2518 	mov	r2,a
      0030DF EB               [12] 2519 	mov	a,r3
      0030E0 4C               [12] 2520 	orl	a,r4
      0030E1 70 0F            [24] 2521 	jnz	00101$
      0030E3 E8               [12] 2522 	mov	a,r0
      0030E4 49               [12] 2523 	orl	a,r1
      0030E5 60 0B            [24] 2524 	jz	00101$
      0030E7 B8 01 05         [24] 2525 	cjne	r0,#0x01,00131$
      0030EA B9 00 02         [24] 2526 	cjne	r1,#0x00,00131$
      0030ED 80 03            [24] 2527 	sjmp	00132$
      0030EF                       2528 00131$:
      0030EF 02 31 81         [24] 2529 	ljmp	00108$
      0030F2                       2530 00132$:
      0030F2                       2531 00101$:
                                   2532 ;	uart.c:373: printf_tiny("\r\n\t\t|    %d    |\t%d\t|", buffers[i].buf_id, buffers[i].buf_size);
      0030F2 C0 05            [24] 2533 	push	ar5
      0030F4 C0 06            [24] 2534 	push	ar6
      0030F6 C0 07            [24] 2535 	push	ar7
      0030F8 90 1B 5A         [24] 2536 	mov	dptr,#__mulint_PARM_2
      0030FB E8               [12] 2537 	mov	a,r0
      0030FC F0               [24] 2538 	movx	@dptr,a
      0030FD E9               [12] 2539 	mov	a,r1
      0030FE A3               [24] 2540 	inc	dptr
      0030FF F0               [24] 2541 	movx	@dptr,a
      003100 90 00 09         [24] 2542 	mov	dptr,#0x0009
      003103 C0 05            [24] 2543 	push	ar5
      003105 C0 01            [24] 2544 	push	ar1
      003107 C0 00            [24] 2545 	push	ar0
      003109 12 3A C5         [24] 2546 	lcall	__mulint
      00310C AE 82            [24] 2547 	mov	r6,dpl
      00310E AF 83            [24] 2548 	mov	r7,dph
      003110 D0 00            [24] 2549 	pop	ar0
      003112 D0 01            [24] 2550 	pop	ar1
      003114 D0 05            [24] 2551 	pop	ar5
      003116 EE               [12] 2552 	mov	a,r6
      003117 25 15            [12] 2553 	add	a,_print_buffers_sloc0_1_0
      003119 FE               [12] 2554 	mov	r6,a
      00311A EF               [12] 2555 	mov	a,r7
      00311B 35 16            [12] 2556 	addc	a,(_print_buffers_sloc0_1_0 + 1)
      00311D FF               [12] 2557 	mov	r7,a
      00311E AD 17            [24] 2558 	mov	r5,(_print_buffers_sloc0_1_0 + 2)
      003120 74 07            [12] 2559 	mov	a,#0x07
      003122 2E               [12] 2560 	add	a,r6
      003123 FA               [12] 2561 	mov	r2,a
      003124 E4               [12] 2562 	clr	a
      003125 3F               [12] 2563 	addc	a,r7
      003126 FB               [12] 2564 	mov	r3,a
      003127 8D 04            [24] 2565 	mov	ar4,r5
      003129 8A 82            [24] 2566 	mov	dpl,r2
      00312B 8B 83            [24] 2567 	mov	dph,r3
      00312D 8C F0            [24] 2568 	mov	b,r4
      00312F 12 49 F6         [24] 2569 	lcall	__gptrget
      003132 FA               [12] 2570 	mov	r2,a
      003133 A3               [24] 2571 	inc	dptr
      003134 12 49 F6         [24] 2572 	lcall	__gptrget
      003137 FB               [12] 2573 	mov	r3,a
      003138 74 05            [12] 2574 	mov	a,#0x05
      00313A 2E               [12] 2575 	add	a,r6
      00313B FE               [12] 2576 	mov	r6,a
      00313C E4               [12] 2577 	clr	a
      00313D 3F               [12] 2578 	addc	a,r7
      00313E FF               [12] 2579 	mov	r7,a
      00313F 8E 82            [24] 2580 	mov	dpl,r6
      003141 8F 83            [24] 2581 	mov	dph,r7
      003143 8D F0            [24] 2582 	mov	b,r5
      003145 12 49 F6         [24] 2583 	lcall	__gptrget
      003148 FE               [12] 2584 	mov	r6,a
      003149 A3               [24] 2585 	inc	dptr
      00314A 12 49 F6         [24] 2586 	lcall	__gptrget
      00314D FF               [12] 2587 	mov	r7,a
      00314E C0 07            [24] 2588 	push	ar7
      003150 C0 06            [24] 2589 	push	ar6
      003152 C0 05            [24] 2590 	push	ar5
      003154 C0 01            [24] 2591 	push	ar1
      003156 C0 00            [24] 2592 	push	ar0
      003158 C0 02            [24] 2593 	push	ar2
      00315A C0 03            [24] 2594 	push	ar3
      00315C C0 06            [24] 2595 	push	ar6
      00315E C0 07            [24] 2596 	push	ar7
      003160 74 F1            [12] 2597 	mov	a,#___str_11
      003162 C0 E0            [24] 2598 	push	acc
      003164 74 4D            [12] 2599 	mov	a,#(___str_11 >> 8)
      003166 C0 E0            [24] 2600 	push	acc
      003168 12 39 BC         [24] 2601 	lcall	_printf_tiny
      00316B E5 81            [12] 2602 	mov	a,sp
      00316D 24 FA            [12] 2603 	add	a,#0xfa
      00316F F5 81            [12] 2604 	mov	sp,a
      003171 D0 00            [24] 2605 	pop	ar0
      003173 D0 01            [24] 2606 	pop	ar1
      003175 D0 05            [24] 2607 	pop	ar5
      003177 D0 06            [24] 2608 	pop	ar6
      003179 D0 07            [24] 2609 	pop	ar7
                                   2610 ;	uart.c:375: printf_tiny("\r\n\t\t-------------------------\r\n");
      00317B D0 07            [24] 2611 	pop	ar7
      00317D D0 06            [24] 2612 	pop	ar6
      00317F D0 05            [24] 2613 	pop	ar5
                                   2614 ;	uart.c:373: printf_tiny("\r\n\t\t|    %d    |\t%d\t|", buffers[i].buf_id, buffers[i].buf_size);
      003181                       2615 00108$:
                                   2616 ;	uart.c:370: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
      003181 08               [12] 2617 	inc	r0
      003182 B8 00 01         [24] 2618 	cjne	r0,#0x00,00133$
      003185 09               [12] 2619 	inc	r1
      003186                       2620 00133$:
      003186 02 30 8F         [24] 2621 	ljmp	00107$
      003189                       2622 00105$:
                                   2623 ;	uart.c:375: printf_tiny("\r\n\t\t-------------------------\r\n");
      003189 74 1B            [12] 2624 	mov	a,#___str_13
      00318B C0 E0            [24] 2625 	push	acc
      00318D 74 4E            [12] 2626 	mov	a,#(___str_13 >> 8)
      00318F C0 E0            [24] 2627 	push	acc
      003191 12 39 BC         [24] 2628 	lcall	_printf_tiny
      003194 15 81            [12] 2629 	dec	sp
      003196 15 81            [12] 2630 	dec	sp
                                   2631 ;	uart.c:376: }
      003198 22               [24] 2632 	ret
                                   2633 ;------------------------------------------------------------
                                   2634 ;Allocation info for local variables in function 'hexdump'
                                   2635 ;------------------------------------------------------------
                                   2636 ;sloc0                     Allocated with name '_hexdump_sloc0_1_0'
                                   2637 ;sloc1                     Allocated with name '_hexdump_sloc1_1_0'
                                   2638 ;nbytes                    Allocated with name '_hexdump_PARM_2'
                                   2639 ;loc                       Allocated with name '_hexdump_loc_65536_120'
                                   2640 ;loc_pointer               Allocated with name '_hexdump_loc_pointer_65536_121'
                                   2641 ;hex_byte                  Allocated with name '_hexdump_hex_byte_65536_121'
                                   2642 ;address_bytes             Allocated with name '_hexdump_address_bytes_65536_121'
                                   2643 ;num                       Allocated with name '_hexdump_num_65536_121'
                                   2644 ;total_chars_in_output_string Allocated with name '_hexdump_total_chars_in_output_string_65536_121'
                                   2645 ;i                         Allocated with name '_hexdump_i_131072_123'
                                   2646 ;j                         Allocated with name '_hexdump_j_327680_126'
                                   2647 ;------------------------------------------------------------
                                   2648 ;	uart.c:381: void hexdump(const void *loc, long nbytes)
                                   2649 ;	-----------------------------------------
                                   2650 ;	 function hexdump
                                   2651 ;	-----------------------------------------
      003199                       2652 _hexdump:
      003199 AF F0            [24] 2653 	mov	r7,b
      00319B AE 83            [24] 2654 	mov	r6,dph
      00319D E5 82            [12] 2655 	mov	a,dpl
      00319F 90 1B 28         [24] 2656 	mov	dptr,#_hexdump_loc_65536_120
      0031A2 F0               [24] 2657 	movx	@dptr,a
      0031A3 EE               [12] 2658 	mov	a,r6
      0031A4 A3               [24] 2659 	inc	dptr
      0031A5 F0               [24] 2660 	movx	@dptr,a
      0031A6 EF               [12] 2661 	mov	a,r7
      0031A7 A3               [24] 2662 	inc	dptr
      0031A8 F0               [24] 2663 	movx	@dptr,a
                                   2664 ;	uart.c:383: const char *loc_pointer = loc;
      0031A9 90 1B 28         [24] 2665 	mov	dptr,#_hexdump_loc_65536_120
      0031AC E0               [24] 2666 	movx	a,@dptr
      0031AD FD               [12] 2667 	mov	r5,a
      0031AE A3               [24] 2668 	inc	dptr
      0031AF E0               [24] 2669 	movx	a,@dptr
      0031B0 FE               [12] 2670 	mov	r6,a
      0031B1 A3               [24] 2671 	inc	dptr
      0031B2 E0               [24] 2672 	movx	a,@dptr
      0031B3 FF               [12] 2673 	mov	r7,a
                                   2674 ;	uart.c:384: char hex_byte[5] = "FF";
      0031B4 90 1B 2B         [24] 2675 	mov	dptr,#_hexdump_hex_byte_65536_121
      0031B7 74 46            [12] 2676 	mov	a,#0x46
      0031B9 F0               [24] 2677 	movx	@dptr,a
      0031BA 90 1B 2C         [24] 2678 	mov	dptr,#(_hexdump_hex_byte_65536_121 + 0x0001)
      0031BD F0               [24] 2679 	movx	@dptr,a
      0031BE 90 1B 2D         [24] 2680 	mov	dptr,#(_hexdump_hex_byte_65536_121 + 0x0002)
      0031C1 E4               [12] 2681 	clr	a
      0031C2 F0               [24] 2682 	movx	@dptr,a
      0031C3 90 1B 2E         [24] 2683 	mov	dptr,#(_hexdump_hex_byte_65536_121 + 0x0003)
      0031C6 F0               [24] 2684 	movx	@dptr,a
      0031C7 90 1B 2F         [24] 2685 	mov	dptr,#(_hexdump_hex_byte_65536_121 + 0x0004)
      0031CA F0               [24] 2686 	movx	@dptr,a
                                   2687 ;	uart.c:385: char address_bytes[7] = "0x0000";
      0031CB 90 1B 30         [24] 2688 	mov	dptr,#_hexdump_address_bytes_65536_121
      0031CE 74 30            [12] 2689 	mov	a,#0x30
      0031D0 F0               [24] 2690 	movx	@dptr,a
      0031D1 90 1B 31         [24] 2691 	mov	dptr,#(_hexdump_address_bytes_65536_121 + 0x0001)
      0031D4 74 78            [12] 2692 	mov	a,#0x78
      0031D6 F0               [24] 2693 	movx	@dptr,a
      0031D7 90 1B 32         [24] 2694 	mov	dptr,#(_hexdump_address_bytes_65536_121 + 0x0002)
      0031DA 74 30            [12] 2695 	mov	a,#0x30
      0031DC F0               [24] 2696 	movx	@dptr,a
      0031DD 90 1B 33         [24] 2697 	mov	dptr,#(_hexdump_address_bytes_65536_121 + 0x0003)
      0031E0 F0               [24] 2698 	movx	@dptr,a
      0031E1 90 1B 34         [24] 2699 	mov	dptr,#(_hexdump_address_bytes_65536_121 + 0x0004)
      0031E4 F0               [24] 2700 	movx	@dptr,a
      0031E5 90 1B 35         [24] 2701 	mov	dptr,#(_hexdump_address_bytes_65536_121 + 0x0005)
      0031E8 F0               [24] 2702 	movx	@dptr,a
      0031E9 90 1B 36         [24] 2703 	mov	dptr,#(_hexdump_address_bytes_65536_121 + 0x0006)
      0031EC E4               [12] 2704 	clr	a
      0031ED F0               [24] 2705 	movx	@dptr,a
                                   2706 ;	uart.c:392: if (nbytes == 0)
      0031EE 90 1B 24         [24] 2707 	mov	dptr,#_hexdump_PARM_2
      0031F1 E0               [24] 2708 	movx	a,@dptr
      0031F2 F9               [12] 2709 	mov	r1,a
      0031F3 A3               [24] 2710 	inc	dptr
      0031F4 E0               [24] 2711 	movx	a,@dptr
      0031F5 FA               [12] 2712 	mov	r2,a
      0031F6 A3               [24] 2713 	inc	dptr
      0031F7 E0               [24] 2714 	movx	a,@dptr
      0031F8 FB               [12] 2715 	mov	r3,a
      0031F9 A3               [24] 2716 	inc	dptr
      0031FA E0               [24] 2717 	movx	a,@dptr
      0031FB FC               [12] 2718 	mov	r4,a
      0031FC 90 1B 24         [24] 2719 	mov	dptr,#_hexdump_PARM_2
      0031FF E0               [24] 2720 	movx	a,@dptr
      003200 F5 F0            [12] 2721 	mov	b,a
      003202 A3               [24] 2722 	inc	dptr
      003203 E0               [24] 2723 	movx	a,@dptr
      003204 42 F0            [12] 2724 	orl	b,a
      003206 A3               [24] 2725 	inc	dptr
      003207 E0               [24] 2726 	movx	a,@dptr
      003208 42 F0            [12] 2727 	orl	b,a
      00320A A3               [24] 2728 	inc	dptr
      00320B E0               [24] 2729 	movx	a,@dptr
      00320C 45 F0            [12] 2730 	orl	a,b
      00320E 70 16            [24] 2731 	jnz	00102$
                                   2732 ;	uart.c:394: printf("\r\n\r\n\t\tNo stored characters in the buffer\r\n");
      003210 74 CB            [12] 2733 	mov	a,#___str_37
      003212 C0 E0            [24] 2734 	push	acc
      003214 74 51            [12] 2735 	mov	a,#(___str_37 >> 8)
      003216 C0 E0            [24] 2736 	push	acc
      003218 74 80            [12] 2737 	mov	a,#0x80
      00321A C0 E0            [24] 2738 	push	acc
      00321C 12 3F D4         [24] 2739 	lcall	_printf
      00321F 15 81            [12] 2740 	dec	sp
      003221 15 81            [12] 2741 	dec	sp
      003223 15 81            [12] 2742 	dec	sp
                                   2743 ;	uart.c:395: return;
      003225 22               [24] 2744 	ret
      003226                       2745 00102$:
                                   2746 ;	uart.c:397: printf_tiny("\r\n\r\n\t\t|=======================================================");
      003226 C0 07            [24] 2747 	push	ar7
      003228 C0 06            [24] 2748 	push	ar6
      00322A C0 05            [24] 2749 	push	ar5
      00322C C0 04            [24] 2750 	push	ar4
      00322E C0 03            [24] 2751 	push	ar3
      003230 C0 02            [24] 2752 	push	ar2
      003232 C0 01            [24] 2753 	push	ar1
      003234 74 F6            [12] 2754 	mov	a,#___str_38
      003236 C0 E0            [24] 2755 	push	acc
      003238 74 51            [12] 2756 	mov	a,#(___str_38 >> 8)
      00323A C0 E0            [24] 2757 	push	acc
      00323C 12 39 BC         [24] 2758 	lcall	_printf_tiny
      00323F 15 81            [12] 2759 	dec	sp
      003241 15 81            [12] 2760 	dec	sp
      003243 D0 01            [24] 2761 	pop	ar1
      003245 D0 02            [24] 2762 	pop	ar2
      003247 D0 03            [24] 2763 	pop	ar3
      003249 D0 04            [24] 2764 	pop	ar4
      00324B D0 05            [24] 2765 	pop	ar5
      00324D D0 06            [24] 2766 	pop	ar6
      00324F D0 07            [24] 2767 	pop	ar7
                                   2768 ;	uart.c:399: for (int i = 0; i < nbytes; i++)
      003251 E4               [12] 2769 	clr	a
      003252 F5 18            [12] 2770 	mov	_hexdump_sloc0_1_0,a
      003254 F5 19            [12] 2771 	mov	(_hexdump_sloc0_1_0 + 1),a
      003256                       2772 00111$:
      003256 C0 05            [24] 2773 	push	ar5
      003258 C0 06            [24] 2774 	push	ar6
      00325A C0 07            [24] 2775 	push	ar7
      00325C A8 18            [24] 2776 	mov	r0,_hexdump_sloc0_1_0
      00325E E5 19            [12] 2777 	mov	a,(_hexdump_sloc0_1_0 + 1)
      003260 FD               [12] 2778 	mov	r5,a
      003261 33               [12] 2779 	rlc	a
      003262 95 E0            [12] 2780 	subb	a,acc
      003264 FE               [12] 2781 	mov	r6,a
      003265 FF               [12] 2782 	mov	r7,a
      003266 C3               [12] 2783 	clr	c
      003267 E8               [12] 2784 	mov	a,r0
      003268 99               [12] 2785 	subb	a,r1
      003269 ED               [12] 2786 	mov	a,r5
      00326A 9A               [12] 2787 	subb	a,r2
      00326B EE               [12] 2788 	mov	a,r6
      00326C 9B               [12] 2789 	subb	a,r3
      00326D EF               [12] 2790 	mov	a,r7
      00326E 64 80            [12] 2791 	xrl	a,#0x80
      003270 8C F0            [24] 2792 	mov	b,r4
      003272 63 F0 80         [24] 2793 	xrl	b,#0x80
      003275 95 F0            [12] 2794 	subb	a,b
      003277 D0 07            [24] 2795 	pop	ar7
      003279 D0 06            [24] 2796 	pop	ar6
      00327B D0 05            [24] 2797 	pop	ar5
      00327D 40 03            [24] 2798 	jc	00142$
      00327F 02 34 B5         [24] 2799 	ljmp	00106$
      003282                       2800 00142$:
                                   2801 ;	uart.c:401: if (i % 16 == 0) // 16 bytes per line
      003282 90 1B 64         [24] 2802 	mov	dptr,#__modsint_PARM_2
      003285 74 10            [12] 2803 	mov	a,#0x10
      003287 F0               [24] 2804 	movx	@dptr,a
      003288 E4               [12] 2805 	clr	a
      003289 A3               [24] 2806 	inc	dptr
      00328A F0               [24] 2807 	movx	@dptr,a
      00328B 85 18 82         [24] 2808 	mov	dpl,_hexdump_sloc0_1_0
      00328E 85 19 83         [24] 2809 	mov	dph,(_hexdump_sloc0_1_0 + 1)
      003291 C0 07            [24] 2810 	push	ar7
      003293 C0 06            [24] 2811 	push	ar6
      003295 C0 05            [24] 2812 	push	ar5
      003297 C0 04            [24] 2813 	push	ar4
      003299 C0 03            [24] 2814 	push	ar3
      00329B C0 02            [24] 2815 	push	ar2
      00329D C0 01            [24] 2816 	push	ar1
      00329F 12 3C 8A         [24] 2817 	lcall	__modsint
      0032A2 E5 82            [12] 2818 	mov	a,dpl
      0032A4 85 83 F0         [24] 2819 	mov	b,dph
      0032A7 D0 01            [24] 2820 	pop	ar1
      0032A9 D0 02            [24] 2821 	pop	ar2
      0032AB D0 03            [24] 2822 	pop	ar3
      0032AD D0 04            [24] 2823 	pop	ar4
      0032AF D0 05            [24] 2824 	pop	ar5
      0032B1 D0 06            [24] 2825 	pop	ar6
      0032B3 D0 07            [24] 2826 	pop	ar7
      0032B5 45 F0            [12] 2827 	orl	a,b
      0032B7 60 03            [24] 2828 	jz	00143$
      0032B9 02 33 D4         [24] 2829 	ljmp	00105$
      0032BC                       2830 00143$:
                                   2831 ;	uart.c:404: uint_to_hexstr(address_bytes, sizeof(address_bytes), (uint16_t)loc_pointer + i, 16); // Converting offset address to hec string
      0032BC C0 01            [24] 2832 	push	ar1
      0032BE C0 02            [24] 2833 	push	ar2
      0032C0 C0 03            [24] 2834 	push	ar3
      0032C2 C0 04            [24] 2835 	push	ar4
      0032C4 8D 00            [24] 2836 	mov	ar0,r5
      0032C6 8E 03            [24] 2837 	mov	ar3,r6
      0032C8 8F 04            [24] 2838 	mov	ar4,r7
      0032CA AA 18            [24] 2839 	mov	r2,_hexdump_sloc0_1_0
      0032CC AC 19            [24] 2840 	mov	r4,(_hexdump_sloc0_1_0 + 1)
      0032CE EA               [12] 2841 	mov	a,r2
      0032CF 28               [12] 2842 	add	a,r0
      0032D0 F8               [12] 2843 	mov	r0,a
      0032D1 EC               [12] 2844 	mov	a,r4
      0032D2 3B               [12] 2845 	addc	a,r3
      0032D3 FB               [12] 2846 	mov	r3,a
      0032D4 90 1B 37         [24] 2847 	mov	dptr,#_uint_to_hexstr_PARM_2
      0032D7 74 07            [12] 2848 	mov	a,#0x07
      0032D9 F0               [24] 2849 	movx	@dptr,a
      0032DA E4               [12] 2850 	clr	a
      0032DB A3               [24] 2851 	inc	dptr
      0032DC F0               [24] 2852 	movx	@dptr,a
      0032DD A3               [24] 2853 	inc	dptr
      0032DE F0               [24] 2854 	movx	@dptr,a
      0032DF A3               [24] 2855 	inc	dptr
      0032E0 F0               [24] 2856 	movx	@dptr,a
      0032E1 90 1B 3B         [24] 2857 	mov	dptr,#_uint_to_hexstr_PARM_3
      0032E4 E8               [12] 2858 	mov	a,r0
      0032E5 F0               [24] 2859 	movx	@dptr,a
      0032E6 EB               [12] 2860 	mov	a,r3
      0032E7 A3               [24] 2861 	inc	dptr
      0032E8 F0               [24] 2862 	movx	@dptr,a
      0032E9 90 1B 3D         [24] 2863 	mov	dptr,#_uint_to_hexstr_PARM_4
      0032EC 74 10            [12] 2864 	mov	a,#0x10
      0032EE F0               [24] 2865 	movx	@dptr,a
      0032EF 90 1B 30         [24] 2866 	mov	dptr,#_hexdump_address_bytes_65536_121
      0032F2 75 F0 00         [24] 2867 	mov	b,#0x00
      0032F5 C0 07            [24] 2868 	push	ar7
      0032F7 C0 06            [24] 2869 	push	ar6
      0032F9 C0 05            [24] 2870 	push	ar5
      0032FB C0 04            [24] 2871 	push	ar4
      0032FD C0 03            [24] 2872 	push	ar3
      0032FF C0 02            [24] 2873 	push	ar2
      003301 C0 01            [24] 2874 	push	ar1
      003303 12 34 C5         [24] 2875 	lcall	_uint_to_hexstr
                                   2876 ;	uart.c:405: printf("|\r\n\t\t| ");
      003306 74 35            [12] 2877 	mov	a,#___str_39
      003308 C0 E0            [24] 2878 	push	acc
      00330A 74 52            [12] 2879 	mov	a,#(___str_39 >> 8)
      00330C C0 E0            [24] 2880 	push	acc
      00330E 74 80            [12] 2881 	mov	a,#0x80
      003310 C0 E0            [24] 2882 	push	acc
      003312 12 3F D4         [24] 2883 	lcall	_printf
      003315 15 81            [12] 2884 	dec	sp
      003317 15 81            [12] 2885 	dec	sp
      003319 15 81            [12] 2886 	dec	sp
      00331B D0 01            [24] 2887 	pop	ar1
      00331D D0 02            [24] 2888 	pop	ar2
      00331F D0 03            [24] 2889 	pop	ar3
      003321 D0 04            [24] 2890 	pop	ar4
      003323 D0 05            [24] 2891 	pop	ar5
      003325 D0 06            [24] 2892 	pop	ar6
      003327 D0 07            [24] 2893 	pop	ar7
                                   2894 ;	uart.c:407: for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
      003329 75 1A 02         [24] 2895 	mov	_hexdump_sloc1_1_0,#0x02
      00332C 75 1B 00         [24] 2896 	mov	(_hexdump_sloc1_1_0 + 1),#0x00
                                   2897 ;	uart.c:421: printf_tiny("\r\n\t\t|=======================================================|\r\n");
      00332F D0 04            [24] 2898 	pop	ar4
      003331 D0 03            [24] 2899 	pop	ar3
      003333 D0 02            [24] 2900 	pop	ar2
      003335 D0 01            [24] 2901 	pop	ar1
                                   2902 ;	uart.c:407: for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
      003337                       2903 00108$:
      003337 C3               [12] 2904 	clr	c
      003338 E5 1A            [12] 2905 	mov	a,_hexdump_sloc1_1_0
      00333A 94 06            [12] 2906 	subb	a,#0x06
      00333C E5 1B            [12] 2907 	mov	a,(_hexdump_sloc1_1_0 + 1)
      00333E 64 80            [12] 2908 	xrl	a,#0x80
      003340 94 80            [12] 2909 	subb	a,#0x80
      003342 50 5F            [24] 2910 	jnc	00103$
                                   2911 ;	uart.c:409: printf("%c", address_bytes[j]);
      003344 C0 01            [24] 2912 	push	ar1
      003346 C0 02            [24] 2913 	push	ar2
      003348 C0 03            [24] 2914 	push	ar3
      00334A C0 04            [24] 2915 	push	ar4
      00334C E5 1A            [12] 2916 	mov	a,_hexdump_sloc1_1_0
      00334E 24 30            [12] 2917 	add	a,#_hexdump_address_bytes_65536_121
      003350 F5 82            [12] 2918 	mov	dpl,a
      003352 E5 1B            [12] 2919 	mov	a,(_hexdump_sloc1_1_0 + 1)
      003354 34 1B            [12] 2920 	addc	a,#(_hexdump_address_bytes_65536_121 >> 8)
      003356 F5 83            [12] 2921 	mov	dph,a
      003358 E0               [24] 2922 	movx	a,@dptr
      003359 F8               [12] 2923 	mov	r0,a
      00335A 7C 00            [12] 2924 	mov	r4,#0x00
      00335C C0 07            [24] 2925 	push	ar7
      00335E C0 06            [24] 2926 	push	ar6
      003360 C0 05            [24] 2927 	push	ar5
      003362 C0 04            [24] 2928 	push	ar4
      003364 C0 03            [24] 2929 	push	ar3
      003366 C0 02            [24] 2930 	push	ar2
      003368 C0 01            [24] 2931 	push	ar1
      00336A C0 00            [24] 2932 	push	ar0
      00336C C0 04            [24] 2933 	push	ar4
      00336E 74 33            [12] 2934 	mov	a,#___str_24
      003370 C0 E0            [24] 2935 	push	acc
      003372 74 50            [12] 2936 	mov	a,#(___str_24 >> 8)
      003374 C0 E0            [24] 2937 	push	acc
      003376 74 80            [12] 2938 	mov	a,#0x80
      003378 C0 E0            [24] 2939 	push	acc
      00337A 12 3F D4         [24] 2940 	lcall	_printf
      00337D E5 81            [12] 2941 	mov	a,sp
      00337F 24 FB            [12] 2942 	add	a,#0xfb
      003381 F5 81            [12] 2943 	mov	sp,a
      003383 D0 01            [24] 2944 	pop	ar1
      003385 D0 02            [24] 2945 	pop	ar2
      003387 D0 03            [24] 2946 	pop	ar3
      003389 D0 04            [24] 2947 	pop	ar4
      00338B D0 05            [24] 2948 	pop	ar5
      00338D D0 06            [24] 2949 	pop	ar6
      00338F D0 07            [24] 2950 	pop	ar7
                                   2951 ;	uart.c:407: for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
      003391 05 1A            [12] 2952 	inc	_hexdump_sloc1_1_0
      003393 E4               [12] 2953 	clr	a
      003394 B5 1A 02         [24] 2954 	cjne	a,_hexdump_sloc1_1_0,00145$
      003397 05 1B            [12] 2955 	inc	(_hexdump_sloc1_1_0 + 1)
      003399                       2956 00145$:
      003399 D0 04            [24] 2957 	pop	ar4
      00339B D0 03            [24] 2958 	pop	ar3
      00339D D0 02            [24] 2959 	pop	ar2
      00339F D0 01            [24] 2960 	pop	ar1
      0033A1 80 94            [24] 2961 	sjmp	00108$
      0033A3                       2962 00103$:
                                   2963 ;	uart.c:412: printf(": ");
      0033A3 C0 07            [24] 2964 	push	ar7
      0033A5 C0 06            [24] 2965 	push	ar6
      0033A7 C0 05            [24] 2966 	push	ar5
      0033A9 C0 04            [24] 2967 	push	ar4
      0033AB C0 03            [24] 2968 	push	ar3
      0033AD C0 02            [24] 2969 	push	ar2
      0033AF C0 01            [24] 2970 	push	ar1
      0033B1 74 3D            [12] 2971 	mov	a,#___str_40
      0033B3 C0 E0            [24] 2972 	push	acc
      0033B5 74 52            [12] 2973 	mov	a,#(___str_40 >> 8)
      0033B7 C0 E0            [24] 2974 	push	acc
      0033B9 74 80            [12] 2975 	mov	a,#0x80
      0033BB C0 E0            [24] 2976 	push	acc
      0033BD 12 3F D4         [24] 2977 	lcall	_printf
      0033C0 15 81            [12] 2978 	dec	sp
      0033C2 15 81            [12] 2979 	dec	sp
      0033C4 15 81            [12] 2980 	dec	sp
      0033C6 D0 01            [24] 2981 	pop	ar1
      0033C8 D0 02            [24] 2982 	pop	ar2
      0033CA D0 03            [24] 2983 	pop	ar3
      0033CC D0 04            [24] 2984 	pop	ar4
      0033CE D0 05            [24] 2985 	pop	ar5
      0033D0 D0 06            [24] 2986 	pop	ar6
      0033D2 D0 07            [24] 2987 	pop	ar7
      0033D4                       2988 00105$:
                                   2989 ;	uart.c:414: num = *loc_pointer;
      0033D4 C0 01            [24] 2990 	push	ar1
      0033D6 C0 02            [24] 2991 	push	ar2
      0033D8 C0 03            [24] 2992 	push	ar3
      0033DA C0 04            [24] 2993 	push	ar4
      0033DC 8D 82            [24] 2994 	mov	dpl,r5
      0033DE 8E 83            [24] 2995 	mov	dph,r6
      0033E0 8F F0            [24] 2996 	mov	b,r7
      0033E2 12 49 F6         [24] 2997 	lcall	__gptrget
      0033E5 F8               [12] 2998 	mov	r0,a
      0033E6 A3               [24] 2999 	inc	dptr
      0033E7 AD 82            [24] 3000 	mov	r5,dpl
      0033E9 AE 83            [24] 3001 	mov	r6,dph
      0033EB 7C 00            [12] 3002 	mov	r4,#0x00
                                   3003 ;	uart.c:415: uint_to_hexstr(hex_byte, sizeof(hex_byte), num, 8); // conveting each character to hex string
      0033ED 90 1B 37         [24] 3004 	mov	dptr,#_uint_to_hexstr_PARM_2
      0033F0 74 05            [12] 3005 	mov	a,#0x05
      0033F2 F0               [24] 3006 	movx	@dptr,a
      0033F3 E4               [12] 3007 	clr	a
      0033F4 A3               [24] 3008 	inc	dptr
      0033F5 F0               [24] 3009 	movx	@dptr,a
      0033F6 A3               [24] 3010 	inc	dptr
      0033F7 F0               [24] 3011 	movx	@dptr,a
      0033F8 A3               [24] 3012 	inc	dptr
      0033F9 F0               [24] 3013 	movx	@dptr,a
      0033FA 90 1B 3B         [24] 3014 	mov	dptr,#_uint_to_hexstr_PARM_3
      0033FD E8               [12] 3015 	mov	a,r0
      0033FE F0               [24] 3016 	movx	@dptr,a
      0033FF EC               [12] 3017 	mov	a,r4
      003400 A3               [24] 3018 	inc	dptr
      003401 F0               [24] 3019 	movx	@dptr,a
      003402 90 1B 3D         [24] 3020 	mov	dptr,#_uint_to_hexstr_PARM_4
      003405 74 08            [12] 3021 	mov	a,#0x08
      003407 F0               [24] 3022 	movx	@dptr,a
      003408 90 1B 2B         [24] 3023 	mov	dptr,#_hexdump_hex_byte_65536_121
      00340B 75 F0 00         [24] 3024 	mov	b,#0x00
      00340E C0 07            [24] 3025 	push	ar7
      003410 C0 06            [24] 3026 	push	ar6
      003412 C0 05            [24] 3027 	push	ar5
      003414 C0 04            [24] 3028 	push	ar4
      003416 C0 03            [24] 3029 	push	ar3
      003418 C0 02            [24] 3030 	push	ar2
      00341A C0 01            [24] 3031 	push	ar1
      00341C 12 34 C5         [24] 3032 	lcall	_uint_to_hexstr
      00341F D0 01            [24] 3033 	pop	ar1
      003421 D0 02            [24] 3034 	pop	ar2
      003423 D0 03            [24] 3035 	pop	ar3
      003425 D0 04            [24] 3036 	pop	ar4
                                   3037 ;	uart.c:416: printf("%c", hex_byte[2]);
      003427 90 1B 2D         [24] 3038 	mov	dptr,#(_hexdump_hex_byte_65536_121 + 0x0002)
      00342A E0               [24] 3039 	movx	a,@dptr
      00342B FC               [12] 3040 	mov	r4,a
      00342C 7B 00            [12] 3041 	mov	r3,#0x00
      00342E C0 04            [24] 3042 	push	ar4
      003430 C0 03            [24] 3043 	push	ar3
      003432 C0 02            [24] 3044 	push	ar2
      003434 C0 01            [24] 3045 	push	ar1
      003436 C0 04            [24] 3046 	push	ar4
      003438 C0 03            [24] 3047 	push	ar3
      00343A 74 33            [12] 3048 	mov	a,#___str_24
      00343C C0 E0            [24] 3049 	push	acc
      00343E 74 50            [12] 3050 	mov	a,#(___str_24 >> 8)
      003440 C0 E0            [24] 3051 	push	acc
      003442 74 80            [12] 3052 	mov	a,#0x80
      003444 C0 E0            [24] 3053 	push	acc
      003446 12 3F D4         [24] 3054 	lcall	_printf
      003449 E5 81            [12] 3055 	mov	a,sp
      00344B 24 FB            [12] 3056 	add	a,#0xfb
      00344D F5 81            [12] 3057 	mov	sp,a
      00344F D0 01            [24] 3058 	pop	ar1
      003451 D0 02            [24] 3059 	pop	ar2
      003453 D0 03            [24] 3060 	pop	ar3
      003455 D0 04            [24] 3061 	pop	ar4
                                   3062 ;	uart.c:417: printf("%c", hex_byte[3]);
      003457 90 1B 2E         [24] 3063 	mov	dptr,#(_hexdump_hex_byte_65536_121 + 0x0003)
      00345A E0               [24] 3064 	movx	a,@dptr
      00345B FC               [12] 3065 	mov	r4,a
      00345C 7B 00            [12] 3066 	mov	r3,#0x00
      00345E C0 04            [24] 3067 	push	ar4
      003460 C0 03            [24] 3068 	push	ar3
      003462 C0 02            [24] 3069 	push	ar2
      003464 C0 01            [24] 3070 	push	ar1
      003466 C0 04            [24] 3071 	push	ar4
      003468 C0 03            [24] 3072 	push	ar3
      00346A 74 33            [12] 3073 	mov	a,#___str_24
      00346C C0 E0            [24] 3074 	push	acc
      00346E 74 50            [12] 3075 	mov	a,#(___str_24 >> 8)
      003470 C0 E0            [24] 3076 	push	acc
      003472 74 80            [12] 3077 	mov	a,#0x80
      003474 C0 E0            [24] 3078 	push	acc
      003476 12 3F D4         [24] 3079 	lcall	_printf
      003479 E5 81            [12] 3080 	mov	a,sp
      00347B 24 FB            [12] 3081 	add	a,#0xfb
      00347D F5 81            [12] 3082 	mov	sp,a
                                   3083 ;	uart.c:418: printf(" ");
      00347F 74 40            [12] 3084 	mov	a,#___str_41
      003481 C0 E0            [24] 3085 	push	acc
      003483 74 52            [12] 3086 	mov	a,#(___str_41 >> 8)
      003485 C0 E0            [24] 3087 	push	acc
      003487 74 80            [12] 3088 	mov	a,#0x80
      003489 C0 E0            [24] 3089 	push	acc
      00348B 12 3F D4         [24] 3090 	lcall	_printf
      00348E 15 81            [12] 3091 	dec	sp
      003490 15 81            [12] 3092 	dec	sp
      003492 15 81            [12] 3093 	dec	sp
      003494 D0 01            [24] 3094 	pop	ar1
      003496 D0 02            [24] 3095 	pop	ar2
      003498 D0 03            [24] 3096 	pop	ar3
      00349A D0 04            [24] 3097 	pop	ar4
      00349C D0 05            [24] 3098 	pop	ar5
      00349E D0 06            [24] 3099 	pop	ar6
      0034A0 D0 07            [24] 3100 	pop	ar7
                                   3101 ;	uart.c:419: loc_pointer++;
                                   3102 ;	uart.c:399: for (int i = 0; i < nbytes; i++)
      0034A2 05 18            [12] 3103 	inc	_hexdump_sloc0_1_0
      0034A4 E4               [12] 3104 	clr	a
      0034A5 B5 18 02         [24] 3105 	cjne	a,_hexdump_sloc0_1_0,00146$
      0034A8 05 19            [12] 3106 	inc	(_hexdump_sloc0_1_0 + 1)
      0034AA                       3107 00146$:
      0034AA D0 04            [24] 3108 	pop	ar4
      0034AC D0 03            [24] 3109 	pop	ar3
      0034AE D0 02            [24] 3110 	pop	ar2
      0034B0 D0 01            [24] 3111 	pop	ar1
      0034B2 02 32 56         [24] 3112 	ljmp	00111$
      0034B5                       3113 00106$:
                                   3114 ;	uart.c:421: printf_tiny("\r\n\t\t|=======================================================|\r\n");
      0034B5 74 42            [12] 3115 	mov	a,#___str_42
      0034B7 C0 E0            [24] 3116 	push	acc
      0034B9 74 52            [12] 3117 	mov	a,#(___str_42 >> 8)
      0034BB C0 E0            [24] 3118 	push	acc
      0034BD 12 39 BC         [24] 3119 	lcall	_printf_tiny
      0034C0 15 81            [12] 3120 	dec	sp
      0034C2 15 81            [12] 3121 	dec	sp
                                   3122 ;	uart.c:422: }
      0034C4 22               [24] 3123 	ret
                                   3124 ;------------------------------------------------------------
                                   3125 ;Allocation info for local variables in function 'uint_to_hexstr'
                                   3126 ;------------------------------------------------------------
                                   3127 ;sloc0                     Allocated with name '_uint_to_hexstr_sloc0_1_0'
                                   3128 ;sloc1                     Allocated with name '_uint_to_hexstr_sloc1_1_0'
                                   3129 ;sloc2                     Allocated with name '_uint_to_hexstr_sloc2_1_0'
                                   3130 ;sloc3                     Allocated with name '_uint_to_hexstr_sloc3_1_0'
                                   3131 ;size                      Allocated with name '_uint_to_hexstr_PARM_2'
                                   3132 ;num                       Allocated with name '_uint_to_hexstr_PARM_3'
                                   3133 ;nbits                     Allocated with name '_uint_to_hexstr_PARM_4'
                                   3134 ;str                       Allocated with name '_uint_to_hexstr_str_65536_128'
                                   3135 ;rem                       Allocated with name '_uint_to_hexstr_rem_65536_129'
                                   3136 ;total_chars               Allocated with name '_uint_to_hexstr_total_chars_65536_129'
                                   3137 ;i                         Allocated with name '_uint_to_hexstr_i_131072_132'
                                   3138 ;------------------------------------------------------------
                                   3139 ;	uart.c:427: int uint_to_hexstr(char *str, long size, uint16_t num, uint8_t nbits)
                                   3140 ;	-----------------------------------------
                                   3141 ;	 function uint_to_hexstr
                                   3142 ;	-----------------------------------------
      0034C5                       3143 _uint_to_hexstr:
      0034C5 AF F0            [24] 3144 	mov	r7,b
      0034C7 AE 83            [24] 3145 	mov	r6,dph
      0034C9 E5 82            [12] 3146 	mov	a,dpl
      0034CB 90 1B 3E         [24] 3147 	mov	dptr,#_uint_to_hexstr_str_65536_128
      0034CE F0               [24] 3148 	movx	@dptr,a
      0034CF EE               [12] 3149 	mov	a,r6
      0034D0 A3               [24] 3150 	inc	dptr
      0034D1 F0               [24] 3151 	movx	@dptr,a
      0034D2 EF               [12] 3152 	mov	a,r7
      0034D3 A3               [24] 3153 	inc	dptr
      0034D4 F0               [24] 3154 	movx	@dptr,a
                                   3155 ;	uart.c:433: if ((nbits != 4) && (nbits != 8) && (nbits != 16) && (nbits != 32))
      0034D5 90 1B 3D         [24] 3156 	mov	dptr,#_uint_to_hexstr_PARM_4
      0034D8 E0               [24] 3157 	movx	a,@dptr
      0034D9 FF               [12] 3158 	mov	r7,a
      0034DA BF 04 02         [24] 3159 	cjne	r7,#0x04,00150$
      0034DD 80 28            [24] 3160 	sjmp	00102$
      0034DF                       3161 00150$:
      0034DF BF 08 02         [24] 3162 	cjne	r7,#0x08,00151$
      0034E2 80 23            [24] 3163 	sjmp	00102$
      0034E4                       3164 00151$:
      0034E4 BF 10 02         [24] 3165 	cjne	r7,#0x10,00152$
      0034E7 80 1E            [24] 3166 	sjmp	00102$
      0034E9                       3167 00152$:
      0034E9 BF 20 02         [24] 3168 	cjne	r7,#0x20,00153$
      0034EC 80 19            [24] 3169 	sjmp	00102$
      0034EE                       3170 00153$:
                                   3171 ;	uart.c:435: str[0] = '\0';
      0034EE 90 1B 3E         [24] 3172 	mov	dptr,#_uint_to_hexstr_str_65536_128
      0034F1 E0               [24] 3173 	movx	a,@dptr
      0034F2 FC               [12] 3174 	mov	r4,a
      0034F3 A3               [24] 3175 	inc	dptr
      0034F4 E0               [24] 3176 	movx	a,@dptr
      0034F5 FD               [12] 3177 	mov	r5,a
      0034F6 A3               [24] 3178 	inc	dptr
      0034F7 E0               [24] 3179 	movx	a,@dptr
      0034F8 FE               [12] 3180 	mov	r6,a
      0034F9 8C 82            [24] 3181 	mov	dpl,r4
      0034FB 8D 83            [24] 3182 	mov	dph,r5
      0034FD 8E F0            [24] 3183 	mov	b,r6
      0034FF E4               [12] 3184 	clr	a
      003500 12 39 A1         [24] 3185 	lcall	__gptrput
                                   3186 ;	uart.c:436: return -1;
      003503 90 FF FF         [24] 3187 	mov	dptr,#0xffff
      003506 22               [24] 3188 	ret
      003507                       3189 00102$:
                                   3190 ;	uart.c:439: total_chars = nbits / 4 + 3; // Every nibble requires 4 chars for representation AND +2 for 0x and +1 for \0
      003507 7E 00            [12] 3191 	mov	r6,#0x00
      003509 90 1B 78         [24] 3192 	mov	dptr,#__divsint_PARM_2
      00350C 74 04            [12] 3193 	mov	a,#0x04
      00350E F0               [24] 3194 	movx	@dptr,a
      00350F E4               [12] 3195 	clr	a
      003510 A3               [24] 3196 	inc	dptr
      003511 F0               [24] 3197 	movx	@dptr,a
      003512 8F 82            [24] 3198 	mov	dpl,r7
      003514 8E 83            [24] 3199 	mov	dph,r6
      003516 12 3E 87         [24] 3200 	lcall	__divsint
      003519 85 82 25         [24] 3201 	mov	_uint_to_hexstr_sloc3_1_0,dpl
      00351C 85 83 26         [24] 3202 	mov	(_uint_to_hexstr_sloc3_1_0 + 1),dph
      00351F 74 03            [12] 3203 	mov	a,#0x03
      003521 25 25            [12] 3204 	add	a,_uint_to_hexstr_sloc3_1_0
      003523 F5 20            [12] 3205 	mov	_uint_to_hexstr_sloc1_1_0,a
      003525 E4               [12] 3206 	clr	a
      003526 35 26            [12] 3207 	addc	a,(_uint_to_hexstr_sloc3_1_0 + 1)
      003528 F5 21            [12] 3208 	mov	(_uint_to_hexstr_sloc1_1_0 + 1),a
                                   3209 ;	uart.c:442: if (total_chars > size)
      00352A 90 1B 37         [24] 3210 	mov	dptr,#_uint_to_hexstr_PARM_2
      00352D E0               [24] 3211 	movx	a,@dptr
      00352E F5 1C            [12] 3212 	mov	_uint_to_hexstr_sloc0_1_0,a
      003530 A3               [24] 3213 	inc	dptr
      003531 E0               [24] 3214 	movx	a,@dptr
      003532 F5 1D            [12] 3215 	mov	(_uint_to_hexstr_sloc0_1_0 + 1),a
      003534 A3               [24] 3216 	inc	dptr
      003535 E0               [24] 3217 	movx	a,@dptr
      003536 F5 1E            [12] 3218 	mov	(_uint_to_hexstr_sloc0_1_0 + 2),a
      003538 A3               [24] 3219 	inc	dptr
      003539 E0               [24] 3220 	movx	a,@dptr
      00353A F5 1F            [12] 3221 	mov	(_uint_to_hexstr_sloc0_1_0 + 3),a
      00353C A8 20            [24] 3222 	mov	r0,_uint_to_hexstr_sloc1_1_0
      00353E E5 21            [12] 3223 	mov	a,(_uint_to_hexstr_sloc1_1_0 + 1)
      003540 F9               [12] 3224 	mov	r1,a
      003541 33               [12] 3225 	rlc	a
      003542 95 E0            [12] 3226 	subb	a,acc
      003544 FA               [12] 3227 	mov	r2,a
      003545 FB               [12] 3228 	mov	r3,a
      003546 C3               [12] 3229 	clr	c
      003547 E5 1C            [12] 3230 	mov	a,_uint_to_hexstr_sloc0_1_0
      003549 98               [12] 3231 	subb	a,r0
      00354A E5 1D            [12] 3232 	mov	a,(_uint_to_hexstr_sloc0_1_0 + 1)
      00354C 99               [12] 3233 	subb	a,r1
      00354D E5 1E            [12] 3234 	mov	a,(_uint_to_hexstr_sloc0_1_0 + 2)
      00354F 9A               [12] 3235 	subb	a,r2
      003550 E5 1F            [12] 3236 	mov	a,(_uint_to_hexstr_sloc0_1_0 + 3)
      003552 64 80            [12] 3237 	xrl	a,#0x80
      003554 8B F0            [24] 3238 	mov	b,r3
      003556 63 F0 80         [24] 3239 	xrl	b,#0x80
      003559 95 F0            [12] 3240 	subb	a,b
      00355B 50 19            [24] 3241 	jnc	00107$
                                   3242 ;	uart.c:444: str[0] = '\0';
      00355D 90 1B 3E         [24] 3243 	mov	dptr,#_uint_to_hexstr_str_65536_128
      003560 E0               [24] 3244 	movx	a,@dptr
      003561 F9               [12] 3245 	mov	r1,a
      003562 A3               [24] 3246 	inc	dptr
      003563 E0               [24] 3247 	movx	a,@dptr
      003564 FA               [12] 3248 	mov	r2,a
      003565 A3               [24] 3249 	inc	dptr
      003566 E0               [24] 3250 	movx	a,@dptr
      003567 FB               [12] 3251 	mov	r3,a
      003568 89 82            [24] 3252 	mov	dpl,r1
      00356A 8A 83            [24] 3253 	mov	dph,r2
      00356C 8B F0            [24] 3254 	mov	b,r3
      00356E E4               [12] 3255 	clr	a
      00356F 12 39 A1         [24] 3256 	lcall	__gptrput
                                   3257 ;	uart.c:445: return -1;
      003572 90 FF FF         [24] 3258 	mov	dptr,#0xffff
      003575 22               [24] 3259 	ret
      003576                       3260 00107$:
                                   3261 ;	uart.c:448: str[0] = '0';
      003576 90 1B 3E         [24] 3262 	mov	dptr,#_uint_to_hexstr_str_65536_128
      003579 E0               [24] 3263 	movx	a,@dptr
      00357A F9               [12] 3264 	mov	r1,a
      00357B A3               [24] 3265 	inc	dptr
      00357C E0               [24] 3266 	movx	a,@dptr
      00357D FA               [12] 3267 	mov	r2,a
      00357E A3               [24] 3268 	inc	dptr
      00357F E0               [24] 3269 	movx	a,@dptr
      003580 FB               [12] 3270 	mov	r3,a
      003581 89 82            [24] 3271 	mov	dpl,r1
      003583 8A 83            [24] 3272 	mov	dph,r2
      003585 8B F0            [24] 3273 	mov	b,r3
      003587 74 30            [12] 3274 	mov	a,#0x30
      003589 12 39 A1         [24] 3275 	lcall	__gptrput
                                   3276 ;	uart.c:449: str[1] = 'x';
      00358C 74 01            [12] 3277 	mov	a,#0x01
      00358E 29               [12] 3278 	add	a,r1
      00358F F8               [12] 3279 	mov	r0,a
      003590 E4               [12] 3280 	clr	a
      003591 3A               [12] 3281 	addc	a,r2
      003592 FC               [12] 3282 	mov	r4,a
      003593 8B 05            [24] 3283 	mov	ar5,r3
      003595 88 82            [24] 3284 	mov	dpl,r0
      003597 8C 83            [24] 3285 	mov	dph,r4
      003599 8D F0            [24] 3286 	mov	b,r5
      00359B 74 78            [12] 3287 	mov	a,#0x78
      00359D 12 39 A1         [24] 3288 	lcall	__gptrput
                                   3289 ;	uart.c:450: str[total_chars] = '\0';
      0035A0 E5 20            [12] 3290 	mov	a,_uint_to_hexstr_sloc1_1_0
      0035A2 29               [12] 3291 	add	a,r1
      0035A3 F8               [12] 3292 	mov	r0,a
      0035A4 E5 21            [12] 3293 	mov	a,(_uint_to_hexstr_sloc1_1_0 + 1)
      0035A6 3A               [12] 3294 	addc	a,r2
      0035A7 FC               [12] 3295 	mov	r4,a
      0035A8 8B 05            [24] 3296 	mov	ar5,r3
      0035AA 88 82            [24] 3297 	mov	dpl,r0
      0035AC 8C 83            [24] 3298 	mov	dph,r4
      0035AE 8D F0            [24] 3299 	mov	b,r5
      0035B0 E4               [12] 3300 	clr	a
      0035B1 12 39 A1         [24] 3301 	lcall	__gptrput
                                   3302 ;	uart.c:453: for (int i = total_chars - 2; i > 1; i--)
      0035B4 E5 25            [12] 3303 	mov	a,_uint_to_hexstr_sloc3_1_0
      0035B6 24 01            [12] 3304 	add	a,#0x01
      0035B8 FC               [12] 3305 	mov	r4,a
      0035B9 E4               [12] 3306 	clr	a
      0035BA 35 26            [12] 3307 	addc	a,(_uint_to_hexstr_sloc3_1_0 + 1)
      0035BC FD               [12] 3308 	mov	r5,a
      0035BD 89 1C            [24] 3309 	mov	_uint_to_hexstr_sloc0_1_0,r1
      0035BF 8A 1D            [24] 3310 	mov	(_uint_to_hexstr_sloc0_1_0 + 1),r2
      0035C1 8B 1E            [24] 3311 	mov	(_uint_to_hexstr_sloc0_1_0 + 2),r3
      0035C3                       3312 00113$:
      0035C3 C3               [12] 3313 	clr	c
      0035C4 74 01            [12] 3314 	mov	a,#0x01
      0035C6 9C               [12] 3315 	subb	a,r4
      0035C7 74 80            [12] 3316 	mov	a,#(0x00 ^ 0x80)
      0035C9 8D F0            [24] 3317 	mov	b,r5
      0035CB 63 F0 80         [24] 3318 	xrl	b,#0x80
      0035CE 95 F0            [12] 3319 	subb	a,b
      0035D0 40 03            [24] 3320 	jc	00155$
      0035D2 02 36 87         [24] 3321 	ljmp	00111$
      0035D5                       3322 00155$:
                                   3323 ;	uart.c:455: rem = num % 16;
      0035D5 90 1B 3B         [24] 3324 	mov	dptr,#_uint_to_hexstr_PARM_3
      0035D8 E0               [24] 3325 	movx	a,@dptr
      0035D9 F8               [12] 3326 	mov	r0,a
      0035DA A3               [24] 3327 	inc	dptr
      0035DB E0               [24] 3328 	movx	a,@dptr
      0035DC 74 0F            [12] 3329 	mov	a,#0x0f
      0035DE 58               [12] 3330 	anl	a,r0
      0035DF F5 20            [12] 3331 	mov	_uint_to_hexstr_sloc1_1_0,a
      0035E1 75 21 00         [24] 3332 	mov	(_uint_to_hexstr_sloc1_1_0 + 1),#0x00
                                   3333 ;	uart.c:456: if (rem < 10)
      0035E4 AE 20            [24] 3334 	mov	r6,_uint_to_hexstr_sloc1_1_0
      0035E6 AF 21            [24] 3335 	mov	r7,(_uint_to_hexstr_sloc1_1_0 + 1)
      0035E8 C3               [12] 3336 	clr	c
      0035E9 EE               [12] 3337 	mov	a,r6
      0035EA 94 0A            [12] 3338 	subb	a,#0x0a
      0035EC EF               [12] 3339 	mov	a,r7
      0035ED 64 80            [12] 3340 	xrl	a,#0x80
      0035EF 94 80            [12] 3341 	subb	a,#0x80
      0035F1 50 20            [24] 3342 	jnc	00109$
                                   3343 ;	uart.c:458: str[i] = '0' + rem;
      0035F3 EC               [12] 3344 	mov	a,r4
      0035F4 29               [12] 3345 	add	a,r1
      0035F5 F5 22            [12] 3346 	mov	_uint_to_hexstr_sloc2_1_0,a
      0035F7 ED               [12] 3347 	mov	a,r5
      0035F8 3A               [12] 3348 	addc	a,r2
      0035F9 F5 23            [12] 3349 	mov	(_uint_to_hexstr_sloc2_1_0 + 1),a
      0035FB 8B 24            [24] 3350 	mov	(_uint_to_hexstr_sloc2_1_0 + 2),r3
      0035FD AE 20            [24] 3351 	mov	r6,_uint_to_hexstr_sloc1_1_0
      0035FF AF 21            [24] 3352 	mov	r7,(_uint_to_hexstr_sloc1_1_0 + 1)
      003601 74 30            [12] 3353 	mov	a,#0x30
      003603 2E               [12] 3354 	add	a,r6
      003604 FE               [12] 3355 	mov	r6,a
      003605 85 22 82         [24] 3356 	mov	dpl,_uint_to_hexstr_sloc2_1_0
      003608 85 23 83         [24] 3357 	mov	dph,(_uint_to_hexstr_sloc2_1_0 + 1)
      00360B 85 24 F0         [24] 3358 	mov	b,(_uint_to_hexstr_sloc2_1_0 + 2)
      00360E 12 39 A1         [24] 3359 	lcall	__gptrput
      003611 80 50            [24] 3360 	sjmp	00110$
      003613                       3361 00109$:
                                   3362 ;	uart.c:462: str[i] = 'A' + (rem % 10);
      003613 C0 01            [24] 3363 	push	ar1
      003615 C0 02            [24] 3364 	push	ar2
      003617 C0 03            [24] 3365 	push	ar3
      003619 EC               [12] 3366 	mov	a,r4
      00361A 25 1C            [12] 3367 	add	a,_uint_to_hexstr_sloc0_1_0
      00361C F8               [12] 3368 	mov	r0,a
      00361D ED               [12] 3369 	mov	a,r5
      00361E 35 1D            [12] 3370 	addc	a,(_uint_to_hexstr_sloc0_1_0 + 1)
      003620 FE               [12] 3371 	mov	r6,a
      003621 AF 1E            [24] 3372 	mov	r7,(_uint_to_hexstr_sloc0_1_0 + 2)
      003623 AA 20            [24] 3373 	mov	r2,_uint_to_hexstr_sloc1_1_0
      003625 AB 21            [24] 3374 	mov	r3,(_uint_to_hexstr_sloc1_1_0 + 1)
      003627 90 1B 64         [24] 3375 	mov	dptr,#__modsint_PARM_2
      00362A 74 0A            [12] 3376 	mov	a,#0x0a
      00362C F0               [24] 3377 	movx	@dptr,a
      00362D E4               [12] 3378 	clr	a
      00362E A3               [24] 3379 	inc	dptr
      00362F F0               [24] 3380 	movx	@dptr,a
      003630 8A 82            [24] 3381 	mov	dpl,r2
      003632 8B 83            [24] 3382 	mov	dph,r3
      003634 C0 07            [24] 3383 	push	ar7
      003636 C0 06            [24] 3384 	push	ar6
      003638 C0 05            [24] 3385 	push	ar5
      00363A C0 04            [24] 3386 	push	ar4
      00363C C0 01            [24] 3387 	push	ar1
      00363E C0 00            [24] 3388 	push	ar0
      003640 12 3C 8A         [24] 3389 	lcall	__modsint
      003643 AA 82            [24] 3390 	mov	r2,dpl
      003645 D0 00            [24] 3391 	pop	ar0
      003647 D0 01            [24] 3392 	pop	ar1
      003649 D0 04            [24] 3393 	pop	ar4
      00364B D0 05            [24] 3394 	pop	ar5
      00364D D0 06            [24] 3395 	pop	ar6
      00364F D0 07            [24] 3396 	pop	ar7
      003651 74 41            [12] 3397 	mov	a,#0x41
      003653 2A               [12] 3398 	add	a,r2
      003654 88 82            [24] 3399 	mov	dpl,r0
      003656 8E 83            [24] 3400 	mov	dph,r6
      003658 8F F0            [24] 3401 	mov	b,r7
      00365A 12 39 A1         [24] 3402 	lcall	__gptrput
                                   3403 ;	uart.c:467: return total_chars - 1;
      00365D D0 03            [24] 3404 	pop	ar3
      00365F D0 02            [24] 3405 	pop	ar2
      003661 D0 01            [24] 3406 	pop	ar1
                                   3407 ;	uart.c:462: str[i] = 'A' + (rem % 10);
      003663                       3408 00110$:
                                   3409 ;	uart.c:464: num = num / 16;
      003663 90 1B 3B         [24] 3410 	mov	dptr,#_uint_to_hexstr_PARM_3
      003666 E0               [24] 3411 	movx	a,@dptr
      003667 FE               [12] 3412 	mov	r6,a
      003668 A3               [24] 3413 	inc	dptr
      003669 E0               [24] 3414 	movx	a,@dptr
      00366A C4               [12] 3415 	swap	a
      00366B CE               [12] 3416 	xch	a,r6
      00366C C4               [12] 3417 	swap	a
      00366D 54 0F            [12] 3418 	anl	a,#0x0f
      00366F 6E               [12] 3419 	xrl	a,r6
      003670 CE               [12] 3420 	xch	a,r6
      003671 54 0F            [12] 3421 	anl	a,#0x0f
      003673 CE               [12] 3422 	xch	a,r6
      003674 6E               [12] 3423 	xrl	a,r6
      003675 CE               [12] 3424 	xch	a,r6
      003676 FF               [12] 3425 	mov	r7,a
      003677 90 1B 3B         [24] 3426 	mov	dptr,#_uint_to_hexstr_PARM_3
      00367A EE               [12] 3427 	mov	a,r6
      00367B F0               [24] 3428 	movx	@dptr,a
      00367C EF               [12] 3429 	mov	a,r7
      00367D A3               [24] 3430 	inc	dptr
      00367E F0               [24] 3431 	movx	@dptr,a
                                   3432 ;	uart.c:453: for (int i = total_chars - 2; i > 1; i--)
      00367F 1C               [12] 3433 	dec	r4
      003680 BC FF 01         [24] 3434 	cjne	r4,#0xff,00157$
      003683 1D               [12] 3435 	dec	r5
      003684                       3436 00157$:
      003684 02 35 C3         [24] 3437 	ljmp	00113$
      003687                       3438 00111$:
                                   3439 ;	uart.c:467: return total_chars - 1;
      003687 E5 25            [12] 3440 	mov	a,_uint_to_hexstr_sloc3_1_0
      003689 24 02            [12] 3441 	add	a,#0x02
      00368B FE               [12] 3442 	mov	r6,a
      00368C E4               [12] 3443 	clr	a
      00368D 35 26            [12] 3444 	addc	a,(_uint_to_hexstr_sloc3_1_0 + 1)
                                   3445 ;	uart.c:468: }
      00368F 8E 82            [24] 3446 	mov	dpl,r6
      003691 F5 83            [12] 3447 	mov	dph,a
      003693 22               [24] 3448 	ret
                                   3449 	.area CSEG    (CODE)
                                   3450 	.area CONST   (CODE)
                                   3451 	.area CONST   (CODE)
      004C38                       3452 ___str_0:
      004C38 0D                    3453 	.db 0x0d
      004C39 0A                    3454 	.db 0x0a
      004C3A 0D                    3455 	.db 0x0d
      004C3B 0A                    3456 	.db 0x0a
      004C3C 09                    3457 	.db 0x09
      004C3D 20 2A 2A 2A 20 43 6F  3458 	.ascii " *** Command for adding a buffer ***"
             6D 6D 61 6E 64 20 66
             6F 72 20 61 64 64 69
             6E 67 20 61 20 62 75
             66 66 65 72 20 2A 2A
             2A
      004C61 0D                    3459 	.db 0x0d
      004C62 0A                    3460 	.db 0x0a
      004C63 00                    3461 	.db 0x00
                                   3462 	.area CSEG    (CODE)
                                   3463 	.area CONST   (CODE)
      004C64                       3464 ___str_1:
      004C64 0D                    3465 	.db 0x0d
      004C65 0A                    3466 	.db 0x0a
      004C66 09                    3467 	.db 0x09
      004C67 08                    3468 	.db 0x08
      004C68 3E 20 53 70 65 63 69  3469 	.ascii "> Specify buffer size to be allocated (30 bytes to 300 bytes"
             66 79 20 62 75 66 66
             65 72 20 73 69 7A 65
             20 74 6F 20 62 65 20
             61 6C 6C 6F 63 61 74
             65 64 20 28 33 30 20
             62 79 74 65 73 20 74
             6F 20 33 30 30 20 62
             79 74 65 73
      004CA4 29 3A 20              3470 	.ascii "): "
      004CA7 00                    3471 	.db 0x00
                                   3472 	.area CSEG    (CODE)
                                   3473 	.area CONST   (CODE)
      004CA8                       3474 ___str_2:
      004CA8 09                    3475 	.db 0x09
      004CA9 20 45 72 72 6F 72 3A  3476 	.ascii " Error: Invalid size"
             20 49 6E 76 61 6C 69
             64 20 73 69 7A 65
      004CBD 00                    3477 	.db 0x00
                                   3478 	.area CSEG    (CODE)
                                   3479 	.area CONST   (CODE)
      004CBE                       3480 ___str_3:
      004CBE 0D                    3481 	.db 0x0d
      004CBF 0A                    3482 	.db 0x0a
      004CC0 09                    3483 	.db 0x09
      004CC1 20 2D 20 2D 20 2D 20  3484 	.ascii " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
             2D 20 2D 20 2D 20 2D
             20 2D 20 2D 20 2D 20
             2D 20 2D 20 2D 20 2D
             20 2D 20 2D 20 2D 20
             2D 20 2D 20 2D 20 2D
             20 2D 20 2D 20 2D 20
             2D 20 2D 20 2D 20 2D
             20 2D 20 2D
      004CFD 20 2D                 3485 	.ascii " -"
      004CFF 00                    3486 	.db 0x00
                                   3487 	.area CSEG    (CODE)
                                   3488 	.area CONST   (CODE)
      004D00                       3489 ___str_4:
      004D00 09                    3490 	.db 0x09
      004D01 20 45 72 72 6F 72 3A  3491 	.ascii " Error: Out of memory, free some buffers to continue"
             20 4F 75 74 20 6F 66
             20 6D 65 6D 6F 72 79
             2C 20 66 72 65 65 20
             73 6F 6D 65 20 62 75
             66 66 65 72 73 20 74
             6F 20 63 6F 6E 74 69
             6E 75 65
      004D35 00                    3492 	.db 0x00
                                   3493 	.area CSEG    (CODE)
                                   3494 	.area CONST   (CODE)
      004D36                       3495 ___str_5:
      004D36 09                    3496 	.db 0x09
      004D37 45 72 72 6F 72 3A 20  3497 	.ascii "Error: buffer could not be added"
             62 75 66 66 65 72 20
             63 6F 75 6C 64 20 6E
             6F 74 20 62 65 20 61
             64 64 65 64
      004D57 0D                    3498 	.db 0x0d
      004D58 0A                    3499 	.db 0x0a
      004D59 00                    3500 	.db 0x00
                                   3501 	.area CSEG    (CODE)
                                   3502 	.area CONST   (CODE)
      004D5A                       3503 ___str_6:
      004D5A 09                    3504 	.db 0x09
      004D5B 45 72 72 6F 72 3A 20  3505 	.ascii "Error: Failed allocating memory"
             46 61 69 6C 65 64 20
             61 6C 6C 6F 63 61 74
             69 6E 67 20 6D 65 6D
             6F 72 79
      004D7A 0D                    3506 	.db 0x0d
      004D7B 0A                    3507 	.db 0x0a
      004D7C 00                    3508 	.db 0x00
                                   3509 	.area CSEG    (CODE)
                                   3510 	.area CONST   (CODE)
      004D7D                       3511 ___str_7:
      004D7D 09                    3512 	.db 0x09
      004D7E 4E 65 77 20 62 75 66  3513 	.ascii "New buffer has been created"
             66 65 72 20 68 61 73
             20 62 65 65 6E 20 63
             72 65 61 74 65 64
      004D99 0D                    3514 	.db 0x0d
      004D9A 0A                    3515 	.db 0x0a
      004D9B 00                    3516 	.db 0x00
                                   3517 	.area CSEG    (CODE)
                                   3518 	.area CONST   (CODE)
      004D9C                       3519 ___str_8:
      004D9C 0D                    3520 	.db 0x0d
      004D9D 0A                    3521 	.db 0x0a
      004D9E 0D                    3522 	.db 0x0d
      004D9F 0A                    3523 	.db 0x0a
      004DA0 09                    3524 	.db 0x09
      004DA1 09                    3525 	.db 0x09
      004DA2 2D 2D 2D 2D 2D 2D 2D  3526 	.ascii "-------------------------"
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D
      004DBB 00                    3527 	.db 0x00
                                   3528 	.area CSEG    (CODE)
                                   3529 	.area CONST   (CODE)
      004DBC                       3530 ___str_9:
      004DBC 0D                    3531 	.db 0x0d
      004DBD 0A                    3532 	.db 0x0a
      004DBE 09                    3533 	.db 0x09
      004DBF 09                    3534 	.db 0x09
      004DC0 7C 62 75 66 66 65 72  3535 	.ascii "|buffer id|"
             20 69 64 7C
      004DCB 09                    3536 	.db 0x09
      004DCC 73 69 7A 65           3537 	.ascii "size"
      004DD0 09                    3538 	.db 0x09
      004DD1 7C                    3539 	.ascii "|"
      004DD2 00                    3540 	.db 0x00
                                   3541 	.area CSEG    (CODE)
                                   3542 	.area CONST   (CODE)
      004DD3                       3543 ___str_10:
      004DD3 0D                    3544 	.db 0x0d
      004DD4 0A                    3545 	.db 0x0a
      004DD5 09                    3546 	.db 0x09
      004DD6 09                    3547 	.db 0x09
      004DD7 2D 2D 2D 2D 2D 2D 2D  3548 	.ascii "-------------------------"
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D
      004DF0 00                    3549 	.db 0x00
                                   3550 	.area CSEG    (CODE)
                                   3551 	.area CONST   (CODE)
      004DF1                       3552 ___str_11:
      004DF1 0D                    3553 	.db 0x0d
      004DF2 0A                    3554 	.db 0x0a
      004DF3 09                    3555 	.db 0x09
      004DF4 09                    3556 	.db 0x09
      004DF5 7C 20 20 20 20 25 64  3557 	.ascii "|    %d    |"
             20 20 20 20 7C
      004E01 09                    3558 	.db 0x09
      004E02 25 64                 3559 	.ascii "%d"
      004E04 09                    3560 	.db 0x09
      004E05 7C                    3561 	.ascii "|"
      004E06 00                    3562 	.db 0x00
                                   3563 	.area CSEG    (CODE)
                                   3564 	.area CONST   (CODE)
      004E07                       3565 ___str_12:
      004E07 20 3C 2D 2D 2D 2D 2D  3566 	.ascii " <----- Newly added"
             20 4E 65 77 6C 79 20
             61 64 64 65 64
      004E1A 00                    3567 	.db 0x00
                                   3568 	.area CSEG    (CODE)
                                   3569 	.area CONST   (CODE)
      004E1B                       3570 ___str_13:
      004E1B 0D                    3571 	.db 0x0d
      004E1C 0A                    3572 	.db 0x0a
      004E1D 09                    3573 	.db 0x09
      004E1E 09                    3574 	.db 0x09
      004E1F 2D 2D 2D 2D 2D 2D 2D  3575 	.ascii "-------------------------"
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D
      004E38 0D                    3576 	.db 0x0d
      004E39 0A                    3577 	.db 0x0a
      004E3A 00                    3578 	.db 0x00
                                   3579 	.area CSEG    (CODE)
                                   3580 	.area CONST   (CODE)
      004E3B                       3581 ___str_14:
      004E3B 0D                    3582 	.db 0x0d
      004E3C 0A                    3583 	.db 0x0a
      004E3D 0D                    3584 	.db 0x0d
      004E3E 0A                    3585 	.db 0x0a
      004E3F 09                    3586 	.db 0x09
      004E40 20 2A 2A 2A 20 43 6F  3587 	.ascii " *** Command for removing a buffer ***"
             6D 6D 61 6E 64 20 66
             6F 72 20 72 65 6D 6F
             76 69 6E 67 20 61 20
             62 75 66 66 65 72 20
             2A 2A 2A
      004E66 0D                    3588 	.db 0x0d
      004E67 0A                    3589 	.db 0x0a
      004E68 00                    3590 	.db 0x00
                                   3591 	.area CSEG    (CODE)
                                   3592 	.area CONST   (CODE)
      004E69                       3593 ___str_15:
      004E69 0D                    3594 	.db 0x0d
      004E6A 0A                    3595 	.db 0x0a
      004E6B 09                    3596 	.db 0x09
      004E6C 08                    3597 	.db 0x08
      004E6D 3E 20 53 70 65 63 69  3598 	.ascii "> Specify buffer to be delated (select id from the list): "
             66 79 20 62 75 66 66
             65 72 20 74 6F 20 62
             65 20 64 65 6C 61 74
             65 64 20 28 73 65 6C
             65 63 74 20 69 64 20
             66 72 6F 6D 20 74 68
             65 20 6C 69 73 74 29
             3A 20
      004EA7 00                    3599 	.db 0x00
                                   3600 	.area CSEG    (CODE)
                                   3601 	.area CONST   (CODE)
      004EA8                       3602 ___str_16:
      004EA8 0D                    3603 	.db 0x0d
      004EA9 0A                    3604 	.db 0x0a
      004EAA 0D                    3605 	.db 0x0d
      004EAB 0A                    3606 	.db 0x0a
      004EAC 09                    3607 	.db 0x09
      004EAD 20 2A 2A 2A 20 43 6F  3608 	.ascii " *** Command for a query ***"
             6D 6D 61 6E 64 20 66
             6F 72 20 61 20 71 75
             65 72 79 20 2A 2A 2A
      004EC9 0D                    3609 	.db 0x0d
      004ECA 0A                    3610 	.db 0x0a
      004ECB 00                    3611 	.db 0x00
                                   3612 	.area CSEG    (CODE)
                                   3613 	.area CONST   (CODE)
      004ECC                       3614 ___str_17:
      004ECC 0D                    3615 	.db 0x0d
      004ECD 0A                    3616 	.db 0x0a
      004ECE 0D                    3617 	.db 0x0d
      004ECF 0A                    3618 	.db 0x0a
      004ED0 09                    3619 	.db 0x09
      004ED1 09                    3620 	.db 0x09
      004ED2 2D 2D 2D 2D 2D 2D 2D  3621 	.ascii "------------------------------------------------------------"
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D
      004F0E 2D 2D 2D 2D 2D        3622 	.ascii "-----"
      004F13 00                    3623 	.db 0x00
                                   3624 	.area CSEG    (CODE)
                                   3625 	.area CONST   (CODE)
      004F14                       3626 ___str_18:
      004F14 0D                    3627 	.db 0x0d
      004F15 0A                    3628 	.db 0x0a
      004F16 09                    3629 	.db 0x09
      004F17 09                    3630 	.db 0x09
      004F18 7C 20 42 75 66 66 65  3631 	.ascii "| Buffer id | start-addr | end-addr | nStorageChar | free-sp"
             72 20 69 64 20 7C 20
             73 74 61 72 74 2D 61
             64 64 72 20 7C 20 65
             6E 64 2D 61 64 64 72
             20 7C 20 6E 53 74 6F
             72 61 67 65 43 68 61
             72 20 7C 20 66 72 65
             65 2D 73 70
      004F54 61 63 65 20 7C        3632 	.ascii "ace |"
      004F59 09                    3633 	.db 0x09
      004F5A 0D                    3634 	.db 0x0d
      004F5B 0A                    3635 	.db 0x0a
      004F5C 00                    3636 	.db 0x00
                                   3637 	.area CSEG    (CODE)
                                   3638 	.area CONST   (CODE)
      004F5D                       3639 ___str_19:
      004F5D 0D                    3640 	.db 0x0d
      004F5E 0A                    3641 	.db 0x0a
      004F5F 09                    3642 	.db 0x09
      004F60 09                    3643 	.db 0x09
      004F61 2D 2D 2D 2D 2D 2D 2D  3644 	.ascii "------------------------------------------------------------"
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D
      004F9D 2D 2D 2D 2D 2D        3645 	.ascii "-----"
      004FA2 00                    3646 	.db 0x00
                                   3647 	.area CSEG    (CODE)
                                   3648 	.area CONST   (CODE)
      004FA3                       3649 ___str_20:
      004FA3 0D                    3650 	.db 0x0d
      004FA4 0A                    3651 	.db 0x0a
      004FA5 09                    3652 	.db 0x09
      004FA6 09                    3653 	.db 0x09
      004FA7 7C 25 31 30 64 20 7C  3654 	.ascii "|%10d |   %11p |%9p |%13d |%11d |"
             20 20 20 25 31 31 70
             20 7C 25 39 70 20 7C
             25 31 33 64 20 7C 25
             31 31 64 20 7C
      004FC8 00                    3655 	.db 0x00
                                   3656 	.area CSEG    (CODE)
                                   3657 	.area CONST   (CODE)
      004FC9                       3658 ___str_21:
      004FC9 0D                    3659 	.db 0x0d
      004FCA 0A                    3660 	.db 0x0a
      004FCB 09                    3661 	.db 0x09
      004FCC 09                    3662 	.db 0x09
      004FCD 2D 2D 2D 2D 2D 2D 2D  3663 	.ascii "------------------------------------------------------------"
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D
      005009 2D 2D 2D 2D 2D        3664 	.ascii "-----"
      00500E 0D                    3665 	.db 0x0d
      00500F 0A                    3666 	.db 0x0a
      005010 00                    3667 	.db 0x00
                                   3668 	.area CSEG    (CODE)
                                   3669 	.area CONST   (CODE)
      005011                       3670 ___str_22:
      005011 0D                    3671 	.db 0x0d
      005012 0A                    3672 	.db 0x0a
      005013 0D                    3673 	.db 0x0d
      005014 0A                    3674 	.db 0x0a
      005015 09                    3675 	.db 0x09
      005016 42 75 66 66 65 72 20  3676 	.ascii "Buffer 0 contents: "
             30 20 63 6F 6E 74 65
             6E 74 73 3A 20
      005029 0D                    3677 	.db 0x0d
      00502A 0A                    3678 	.db 0x0a
      00502B 0D                    3679 	.db 0x0d
      00502C 0A                    3680 	.db 0x0a
      00502D 00                    3681 	.db 0x00
                                   3682 	.area CSEG    (CODE)
                                   3683 	.area CONST   (CODE)
      00502E                       3684 ___str_23:
      00502E 0D                    3685 	.db 0x0d
      00502F 0A                    3686 	.db 0x0a
      005030 09                    3687 	.db 0x09
      005031 09                    3688 	.db 0x09
      005032 00                    3689 	.db 0x00
                                   3690 	.area CSEG    (CODE)
                                   3691 	.area CONST   (CODE)
      005033                       3692 ___str_24:
      005033 25 63                 3693 	.ascii "%c"
      005035 00                    3694 	.db 0x00
                                   3695 	.area CSEG    (CODE)
                                   3696 	.area CONST   (CODE)
      005036                       3697 ___str_25:
      005036 0D                    3698 	.db 0x0d
      005037 0A                    3699 	.db 0x0a
      005038 0D                    3700 	.db 0x0d
      005039 0A                    3701 	.db 0x0a
      00503A 09                    3702 	.db 0x09
      00503B 20 2A 2A 2A 20 43 6F  3703 	.ascii " *** Command for a hexdump ***"
             6D 6D 61 6E 64 20 66
             6F 72 20 61 20 68 65
             78 64 75 6D 70 20 2A
             2A 2A
      005059 0D                    3704 	.db 0x0d
      00505A 0A                    3705 	.db 0x0a
      00505B 00                    3706 	.db 0x00
                                   3707 	.area CSEG    (CODE)
                                   3708 	.area CONST   (CODE)
      00505C                       3709 ___str_26:
      00505C 0D                    3710 	.db 0x0d
      00505D 0A                    3711 	.db 0x0a
      00505E 0D                    3712 	.db 0x0d
      00505F 0A                    3713 	.db 0x0a
      005060 09                    3714 	.db 0x09
      005061 20 2A 2A 2A 20 43 6F  3715 	.ascii " *** Command for freeing memory ***"
             6D 6D 61 6E 64 20 66
             6F 72 20 66 72 65 65
             69 6E 67 20 6D 65 6D
             6F 72 79 20 2A 2A 2A
      005084 0D                    3716 	.db 0x0d
      005085 0A                    3717 	.db 0x0a
      005086 00                    3718 	.db 0x00
                                   3719 	.area CSEG    (CODE)
                                   3720 	.area CONST   (CODE)
      005087                       3721 ___str_27:
      005087 0D                    3722 	.db 0x0d
      005088 0A                    3723 	.db 0x0a
      005089 0D                    3724 	.db 0x0d
      00508A 0A                    3725 	.db 0x0a
      00508B 09                    3726 	.db 0x09
      00508C 09                    3727 	.db 0x09
      00508D 4D 65 6D 6F 72 79 20  3728 	.ascii "Memory has been freed"
             68 61 73 20 62 65 65
             6E 20 66 72 65 65 64
      0050A2 0D                    3729 	.db 0x0d
      0050A3 0A                    3730 	.db 0x0a
      0050A4 0D                    3731 	.db 0x0d
      0050A5 0A                    3732 	.db 0x0a
      0050A6 00                    3733 	.db 0x00
                                   3734 	.area CSEG    (CODE)
                                   3735 	.area CONST   (CODE)
      0050A7                       3736 ___str_28:
      0050A7 0D                    3737 	.db 0x0d
      0050A8 0A                    3738 	.db 0x0a
      0050A9 2D 2D 2D 2D 2D 2D 2D  3739 	.ascii "------------------------------------------------------------"
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D
      0050E5 2D 2D 2D 2D 2D 2D 2D  3740 	.ascii "----------"
             2D 2D 2D
      0050EF 0D                    3741 	.db 0x0d
      0050F0 0A                    3742 	.db 0x0a
      0050F1 0D                    3743 	.db 0x0d
      0050F2 0A                    3744 	.db 0x0a
      0050F3 00                    3745 	.db 0x00
                                   3746 	.area CSEG    (CODE)
                                   3747 	.area CONST   (CODE)
      0050F4                       3748 ___str_29:
      0050F4 0D                    3749 	.db 0x0d
      0050F5 0A                    3750 	.db 0x0a
      0050F6 0D                    3751 	.db 0x0d
      0050F7 0A                    3752 	.db 0x0a
      0050F8 09                    3753 	.db 0x09
      0050F9 20 45 72 72 6F 72 3A  3754 	.ascii " Error: Received invalid command '%c'"
             20 52 65 63 65 69 76
             65 64 20 69 6E 76 61
             6C 69 64 20 63 6F 6D
             6D 61 6E 64 20 27 25
             63 27
      00511E 0D                    3755 	.db 0x0d
      00511F 0A                    3756 	.db 0x0a
      005120 00                    3757 	.db 0x00
                                   3758 	.area CSEG    (CODE)
                                   3759 	.area CONST   (CODE)
      005121                       3760 ___str_30:
      005121 45 6E 74 65 72 20 63  3761 	.ascii "Enter command (+, -, ?, =, @) or input: "
             6F 6D 6D 61 6E 64 20
             28 2B 2C 20 2D 2C 20
             3F 2C 20 3D 2C 20 40
             29 20 6F 72 20 69 6E
             70 75 74 3A 20
      005149 00                    3762 	.db 0x00
                                   3763 	.area CSEG    (CODE)
                                   3764 	.area CONST   (CODE)
      00514A                       3765 ___str_32:
      00514A 0D                    3766 	.db 0x0d
      00514B 0A                    3767 	.db 0x0a
      00514C 09                    3768 	.db 0x09
      00514D 09                    3769 	.db 0x09
      00514E 20 45 72 72 6F 72 3A  3770 	.ascii " Error: Re-enter the number: "
             20 52 65 2D 65 6E 74
             65 72 20 74 68 65 20
             6E 75 6D 62 65 72 3A
             20
      00516B 00                    3771 	.db 0x00
                                   3772 	.area CSEG    (CODE)
                                   3773 	.area CONST   (CODE)
      00516C                       3774 ___str_33:
      00516C 0D                    3775 	.db 0x0d
      00516D 0A                    3776 	.db 0x0a
      00516E 09                    3777 	.db 0x09
      00516F 09                    3778 	.db 0x09
      005170 20 45 72 72 6F 72 3A  3779 	.ascii " Error: Reading a number failed, Reached maximum length supp"
             20 52 65 61 64 69 6E
             67 20 61 20 6E 75 6D
             62 65 72 20 66 61 69
             6C 65 64 2C 20 52 65
             61 63 68 65 64 20 6D
             61 78 69 6D 75 6D 20
             6C 65 6E 67 74 68 20
             73 75 70 70
      0051AC 6F 72 74 65 64        3780 	.ascii "orted"
      0051B1 00                    3781 	.db 0x00
                                   3782 	.area CSEG    (CODE)
                                   3783 	.area CONST   (CODE)
      0051B2                       3784 ___str_34:
      0051B2 0D                    3785 	.db 0x0d
      0051B3 0A                    3786 	.db 0x0a
      0051B4 09                    3787 	.db 0x09
      0051B5 09                    3788 	.db 0x09
      0051B6 7C 20 62 75 66 66 65  3789 	.ascii "| buffer id |"
             72 20 69 64 20 7C
      0051C3 09                    3790 	.db 0x09
      0051C4 73 69 7A 65           3791 	.ascii "size"
      0051C8 09                    3792 	.db 0x09
      0051C9 7C                    3793 	.ascii "|"
      0051CA 00                    3794 	.db 0x00
                                   3795 	.area CSEG    (CODE)
                                   3796 	.area CONST   (CODE)
      0051CB                       3797 ___str_37:
      0051CB 0D                    3798 	.db 0x0d
      0051CC 0A                    3799 	.db 0x0a
      0051CD 0D                    3800 	.db 0x0d
      0051CE 0A                    3801 	.db 0x0a
      0051CF 09                    3802 	.db 0x09
      0051D0 09                    3803 	.db 0x09
      0051D1 4E 6F 20 73 74 6F 72  3804 	.ascii "No stored characters in the buffer"
             65 64 20 63 68 61 72
             61 63 74 65 72 73 20
             69 6E 20 74 68 65 20
             62 75 66 66 65 72
      0051F3 0D                    3805 	.db 0x0d
      0051F4 0A                    3806 	.db 0x0a
      0051F5 00                    3807 	.db 0x00
                                   3808 	.area CSEG    (CODE)
                                   3809 	.area CONST   (CODE)
      0051F6                       3810 ___str_38:
      0051F6 0D                    3811 	.db 0x0d
      0051F7 0A                    3812 	.db 0x0a
      0051F8 0D                    3813 	.db 0x0d
      0051F9 0A                    3814 	.db 0x0a
      0051FA 09                    3815 	.db 0x09
      0051FB 09                    3816 	.db 0x09
      0051FC 7C 3D 3D 3D 3D 3D 3D  3817 	.ascii "|======================================================="
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
      005234 00                    3818 	.db 0x00
                                   3819 	.area CSEG    (CODE)
                                   3820 	.area CONST   (CODE)
      005235                       3821 ___str_39:
      005235 7C                    3822 	.ascii "|"
      005236 0D                    3823 	.db 0x0d
      005237 0A                    3824 	.db 0x0a
      005238 09                    3825 	.db 0x09
      005239 09                    3826 	.db 0x09
      00523A 7C 20                 3827 	.ascii "| "
      00523C 00                    3828 	.db 0x00
                                   3829 	.area CSEG    (CODE)
                                   3830 	.area CONST   (CODE)
      00523D                       3831 ___str_40:
      00523D 3A 20                 3832 	.ascii ": "
      00523F 00                    3833 	.db 0x00
                                   3834 	.area CSEG    (CODE)
                                   3835 	.area CONST   (CODE)
      005240                       3836 ___str_41:
      005240 20                    3837 	.ascii " "
      005241 00                    3838 	.db 0x00
                                   3839 	.area CSEG    (CODE)
                                   3840 	.area CONST   (CODE)
      005242                       3841 ___str_42:
      005242 0D                    3842 	.db 0x0d
      005243 0A                    3843 	.db 0x0a
      005244 09                    3844 	.db 0x09
      005245 09                    3845 	.db 0x09
      005246 7C 3D 3D 3D 3D 3D 3D  3846 	.ascii "|=======================================================|"
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             7C
      00527F 0D                    3847 	.db 0x0d
      005280 0A                    3848 	.db 0x0a
      005281 00                    3849 	.db 0x00
                                   3850 	.area CSEG    (CODE)
                                   3851 	.area XINIT   (CODE)
      00528D                       3852 __xinit__buf_number:
      00528D 00 00                 3853 	.byte #0x00, #0x00	;  0
      00528F                       3854 __xinit__total_malloced_data:
      00528F 00 00                 3855 	.byte #0x00, #0x00	;  0
                                   3856 	.area CABS    (ABS,CODE)
