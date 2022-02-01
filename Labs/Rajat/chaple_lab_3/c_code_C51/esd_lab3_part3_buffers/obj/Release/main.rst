                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.9.0 #11195 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-large
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl __sdcc_external_startup
                                     12 	.globl _dataout
                                     13 	.globl _free
                                     14 	.globl _malloc
                                     15 	.globl _memset
                                     16 	.globl _getchar
                                     17 	.globl _printf
                                     18 	.globl _accept_number_from_user
                                     19 	.globl _command
                                     20 	.globl _putstr
                                     21 	.globl _echo
                                     22 	.globl _uart_init
                                     23 	.globl _P5_7
                                     24 	.globl _P5_6
                                     25 	.globl _P5_5
                                     26 	.globl _P5_4
                                     27 	.globl _P5_3
                                     28 	.globl _P5_2
                                     29 	.globl _P5_1
                                     30 	.globl _P5_0
                                     31 	.globl _P4_7
                                     32 	.globl _P4_6
                                     33 	.globl _P4_5
                                     34 	.globl _P4_4
                                     35 	.globl _P4_3
                                     36 	.globl _P4_2
                                     37 	.globl _P4_1
                                     38 	.globl _P4_0
                                     39 	.globl _PX0L
                                     40 	.globl _PT0L
                                     41 	.globl _PX1L
                                     42 	.globl _PT1L
                                     43 	.globl _PSL
                                     44 	.globl _PT2L
                                     45 	.globl _PPCL
                                     46 	.globl _EC
                                     47 	.globl _CCF0
                                     48 	.globl _CCF1
                                     49 	.globl _CCF2
                                     50 	.globl _CCF3
                                     51 	.globl _CCF4
                                     52 	.globl _CR
                                     53 	.globl _CF
                                     54 	.globl _TF2
                                     55 	.globl _EXF2
                                     56 	.globl _RCLK
                                     57 	.globl _TCLK
                                     58 	.globl _EXEN2
                                     59 	.globl _TR2
                                     60 	.globl _C_T2
                                     61 	.globl _CP_RL2
                                     62 	.globl _T2CON_7
                                     63 	.globl _T2CON_6
                                     64 	.globl _T2CON_5
                                     65 	.globl _T2CON_4
                                     66 	.globl _T2CON_3
                                     67 	.globl _T2CON_2
                                     68 	.globl _T2CON_1
                                     69 	.globl _T2CON_0
                                     70 	.globl _PT2
                                     71 	.globl _ET2
                                     72 	.globl _CY
                                     73 	.globl _AC
                                     74 	.globl _F0
                                     75 	.globl _RS1
                                     76 	.globl _RS0
                                     77 	.globl _OV
                                     78 	.globl _F1
                                     79 	.globl _P
                                     80 	.globl _PS
                                     81 	.globl _PT1
                                     82 	.globl _PX1
                                     83 	.globl _PT0
                                     84 	.globl _PX0
                                     85 	.globl _RD
                                     86 	.globl _WR
                                     87 	.globl _T1
                                     88 	.globl _T0
                                     89 	.globl _INT1
                                     90 	.globl _INT0
                                     91 	.globl _TXD
                                     92 	.globl _RXD
                                     93 	.globl _P3_7
                                     94 	.globl _P3_6
                                     95 	.globl _P3_5
                                     96 	.globl _P3_4
                                     97 	.globl _P3_3
                                     98 	.globl _P3_2
                                     99 	.globl _P3_1
                                    100 	.globl _P3_0
                                    101 	.globl _EA
                                    102 	.globl _ES
                                    103 	.globl _ET1
                                    104 	.globl _EX1
                                    105 	.globl _ET0
                                    106 	.globl _EX0
                                    107 	.globl _P2_7
                                    108 	.globl _P2_6
                                    109 	.globl _P2_5
                                    110 	.globl _P2_4
                                    111 	.globl _P2_3
                                    112 	.globl _P2_2
                                    113 	.globl _P2_1
                                    114 	.globl _P2_0
                                    115 	.globl _SM0
                                    116 	.globl _SM1
                                    117 	.globl _SM2
                                    118 	.globl _REN
                                    119 	.globl _TB8
                                    120 	.globl _RB8
                                    121 	.globl _TI
                                    122 	.globl _RI
                                    123 	.globl _P1_7
                                    124 	.globl _P1_6
                                    125 	.globl _P1_5
                                    126 	.globl _P1_4
                                    127 	.globl _P1_3
                                    128 	.globl _P1_2
                                    129 	.globl _P1_1
                                    130 	.globl _P1_0
                                    131 	.globl _TF1
                                    132 	.globl _TR1
                                    133 	.globl _TF0
                                    134 	.globl _TR0
                                    135 	.globl _IE1
                                    136 	.globl _IT1
                                    137 	.globl _IE0
                                    138 	.globl _IT0
                                    139 	.globl _P0_7
                                    140 	.globl _P0_6
                                    141 	.globl _P0_5
                                    142 	.globl _P0_4
                                    143 	.globl _P0_3
                                    144 	.globl _P0_2
                                    145 	.globl _P0_1
                                    146 	.globl _P0_0
                                    147 	.globl _EECON
                                    148 	.globl _KBF
                                    149 	.globl _KBE
                                    150 	.globl _KBLS
                                    151 	.globl _BRL
                                    152 	.globl _BDRCON
                                    153 	.globl _T2MOD
                                    154 	.globl _SPDAT
                                    155 	.globl _SPSTA
                                    156 	.globl _SPCON
                                    157 	.globl _SADEN
                                    158 	.globl _SADDR
                                    159 	.globl _WDTPRG
                                    160 	.globl _WDTRST
                                    161 	.globl _P5
                                    162 	.globl _P4
                                    163 	.globl _IPH1
                                    164 	.globl _IPL1
                                    165 	.globl _IPH0
                                    166 	.globl _IPL0
                                    167 	.globl _IEN1
                                    168 	.globl _IEN0
                                    169 	.globl _CMOD
                                    170 	.globl _CL
                                    171 	.globl _CH
                                    172 	.globl _CCON
                                    173 	.globl _CCAPM4
                                    174 	.globl _CCAPM3
                                    175 	.globl _CCAPM2
                                    176 	.globl _CCAPM1
                                    177 	.globl _CCAPM0
                                    178 	.globl _CCAP4L
                                    179 	.globl _CCAP3L
                                    180 	.globl _CCAP2L
                                    181 	.globl _CCAP1L
                                    182 	.globl _CCAP0L
                                    183 	.globl _CCAP4H
                                    184 	.globl _CCAP3H
                                    185 	.globl _CCAP2H
                                    186 	.globl _CCAP1H
                                    187 	.globl _CCAP0H
                                    188 	.globl _CKCON1
                                    189 	.globl _CKCON0
                                    190 	.globl _CKRL
                                    191 	.globl _AUXR1
                                    192 	.globl _AUXR
                                    193 	.globl _TH2
                                    194 	.globl _TL2
                                    195 	.globl _RCAP2H
                                    196 	.globl _RCAP2L
                                    197 	.globl _T2CON
                                    198 	.globl _B
                                    199 	.globl _ACC
                                    200 	.globl _PSW
                                    201 	.globl _IP
                                    202 	.globl _P3
                                    203 	.globl _IE
                                    204 	.globl _P2
                                    205 	.globl _SBUF
                                    206 	.globl _SCON
                                    207 	.globl _P1
                                    208 	.globl _TH1
                                    209 	.globl _TH0
                                    210 	.globl _TL1
                                    211 	.globl _TL0
                                    212 	.globl _TMOD
                                    213 	.globl _TCON
                                    214 	.globl _PCON
                                    215 	.globl _DPH
                                    216 	.globl _DPL
                                    217 	.globl _SP
                                    218 	.globl _P0
                                    219 	.globl _main
                                    220 ;--------------------------------------------------------
                                    221 ; special function registers
                                    222 ;--------------------------------------------------------
                                    223 	.area RSEG    (ABS,DATA)
      000000                        224 	.org 0x0000
                           000080   225 _P0	=	0x0080
                           000081   226 _SP	=	0x0081
                           000082   227 _DPL	=	0x0082
                           000083   228 _DPH	=	0x0083
                           000087   229 _PCON	=	0x0087
                           000088   230 _TCON	=	0x0088
                           000089   231 _TMOD	=	0x0089
                           00008A   232 _TL0	=	0x008a
                           00008B   233 _TL1	=	0x008b
                           00008C   234 _TH0	=	0x008c
                           00008D   235 _TH1	=	0x008d
                           000090   236 _P1	=	0x0090
                           000098   237 _SCON	=	0x0098
                           000099   238 _SBUF	=	0x0099
                           0000A0   239 _P2	=	0x00a0
                           0000A8   240 _IE	=	0x00a8
                           0000B0   241 _P3	=	0x00b0
                           0000B8   242 _IP	=	0x00b8
                           0000D0   243 _PSW	=	0x00d0
                           0000E0   244 _ACC	=	0x00e0
                           0000F0   245 _B	=	0x00f0
                           0000C8   246 _T2CON	=	0x00c8
                           0000CA   247 _RCAP2L	=	0x00ca
                           0000CB   248 _RCAP2H	=	0x00cb
                           0000CC   249 _TL2	=	0x00cc
                           0000CD   250 _TH2	=	0x00cd
                           00008E   251 _AUXR	=	0x008e
                           0000A2   252 _AUXR1	=	0x00a2
                           000097   253 _CKRL	=	0x0097
                           00008F   254 _CKCON0	=	0x008f
                           0000AF   255 _CKCON1	=	0x00af
                           0000FA   256 _CCAP0H	=	0x00fa
                           0000FB   257 _CCAP1H	=	0x00fb
                           0000FC   258 _CCAP2H	=	0x00fc
                           0000FD   259 _CCAP3H	=	0x00fd
                           0000FE   260 _CCAP4H	=	0x00fe
                           0000EA   261 _CCAP0L	=	0x00ea
                           0000EB   262 _CCAP1L	=	0x00eb
                           0000EC   263 _CCAP2L	=	0x00ec
                           0000ED   264 _CCAP3L	=	0x00ed
                           0000EE   265 _CCAP4L	=	0x00ee
                           0000DA   266 _CCAPM0	=	0x00da
                           0000DB   267 _CCAPM1	=	0x00db
                           0000DC   268 _CCAPM2	=	0x00dc
                           0000DD   269 _CCAPM3	=	0x00dd
                           0000DE   270 _CCAPM4	=	0x00de
                           0000D8   271 _CCON	=	0x00d8
                           0000F9   272 _CH	=	0x00f9
                           0000E9   273 _CL	=	0x00e9
                           0000D9   274 _CMOD	=	0x00d9
                           0000A8   275 _IEN0	=	0x00a8
                           0000B1   276 _IEN1	=	0x00b1
                           0000B8   277 _IPL0	=	0x00b8
                           0000B7   278 _IPH0	=	0x00b7
                           0000B2   279 _IPL1	=	0x00b2
                           0000B3   280 _IPH1	=	0x00b3
                           0000C0   281 _P4	=	0x00c0
                           0000E8   282 _P5	=	0x00e8
                           0000A6   283 _WDTRST	=	0x00a6
                           0000A7   284 _WDTPRG	=	0x00a7
                           0000A9   285 _SADDR	=	0x00a9
                           0000B9   286 _SADEN	=	0x00b9
                           0000C3   287 _SPCON	=	0x00c3
                           0000C4   288 _SPSTA	=	0x00c4
                           0000C5   289 _SPDAT	=	0x00c5
                           0000C9   290 _T2MOD	=	0x00c9
                           00009B   291 _BDRCON	=	0x009b
                           00009A   292 _BRL	=	0x009a
                           00009C   293 _KBLS	=	0x009c
                           00009D   294 _KBE	=	0x009d
                           00009E   295 _KBF	=	0x009e
                           0000D2   296 _EECON	=	0x00d2
                                    297 ;--------------------------------------------------------
                                    298 ; special function bits
                                    299 ;--------------------------------------------------------
                                    300 	.area RSEG    (ABS,DATA)
      000000                        301 	.org 0x0000
                           000080   302 _P0_0	=	0x0080
                           000081   303 _P0_1	=	0x0081
                           000082   304 _P0_2	=	0x0082
                           000083   305 _P0_3	=	0x0083
                           000084   306 _P0_4	=	0x0084
                           000085   307 _P0_5	=	0x0085
                           000086   308 _P0_6	=	0x0086
                           000087   309 _P0_7	=	0x0087
                           000088   310 _IT0	=	0x0088
                           000089   311 _IE0	=	0x0089
                           00008A   312 _IT1	=	0x008a
                           00008B   313 _IE1	=	0x008b
                           00008C   314 _TR0	=	0x008c
                           00008D   315 _TF0	=	0x008d
                           00008E   316 _TR1	=	0x008e
                           00008F   317 _TF1	=	0x008f
                           000090   318 _P1_0	=	0x0090
                           000091   319 _P1_1	=	0x0091
                           000092   320 _P1_2	=	0x0092
                           000093   321 _P1_3	=	0x0093
                           000094   322 _P1_4	=	0x0094
                           000095   323 _P1_5	=	0x0095
                           000096   324 _P1_6	=	0x0096
                           000097   325 _P1_7	=	0x0097
                           000098   326 _RI	=	0x0098
                           000099   327 _TI	=	0x0099
                           00009A   328 _RB8	=	0x009a
                           00009B   329 _TB8	=	0x009b
                           00009C   330 _REN	=	0x009c
                           00009D   331 _SM2	=	0x009d
                           00009E   332 _SM1	=	0x009e
                           00009F   333 _SM0	=	0x009f
                           0000A0   334 _P2_0	=	0x00a0
                           0000A1   335 _P2_1	=	0x00a1
                           0000A2   336 _P2_2	=	0x00a2
                           0000A3   337 _P2_3	=	0x00a3
                           0000A4   338 _P2_4	=	0x00a4
                           0000A5   339 _P2_5	=	0x00a5
                           0000A6   340 _P2_6	=	0x00a6
                           0000A7   341 _P2_7	=	0x00a7
                           0000A8   342 _EX0	=	0x00a8
                           0000A9   343 _ET0	=	0x00a9
                           0000AA   344 _EX1	=	0x00aa
                           0000AB   345 _ET1	=	0x00ab
                           0000AC   346 _ES	=	0x00ac
                           0000AF   347 _EA	=	0x00af
                           0000B0   348 _P3_0	=	0x00b0
                           0000B1   349 _P3_1	=	0x00b1
                           0000B2   350 _P3_2	=	0x00b2
                           0000B3   351 _P3_3	=	0x00b3
                           0000B4   352 _P3_4	=	0x00b4
                           0000B5   353 _P3_5	=	0x00b5
                           0000B6   354 _P3_6	=	0x00b6
                           0000B7   355 _P3_7	=	0x00b7
                           0000B0   356 _RXD	=	0x00b0
                           0000B1   357 _TXD	=	0x00b1
                           0000B2   358 _INT0	=	0x00b2
                           0000B3   359 _INT1	=	0x00b3
                           0000B4   360 _T0	=	0x00b4
                           0000B5   361 _T1	=	0x00b5
                           0000B6   362 _WR	=	0x00b6
                           0000B7   363 _RD	=	0x00b7
                           0000B8   364 _PX0	=	0x00b8
                           0000B9   365 _PT0	=	0x00b9
                           0000BA   366 _PX1	=	0x00ba
                           0000BB   367 _PT1	=	0x00bb
                           0000BC   368 _PS	=	0x00bc
                           0000D0   369 _P	=	0x00d0
                           0000D1   370 _F1	=	0x00d1
                           0000D2   371 _OV	=	0x00d2
                           0000D3   372 _RS0	=	0x00d3
                           0000D4   373 _RS1	=	0x00d4
                           0000D5   374 _F0	=	0x00d5
                           0000D6   375 _AC	=	0x00d6
                           0000D7   376 _CY	=	0x00d7
                           0000AD   377 _ET2	=	0x00ad
                           0000BD   378 _PT2	=	0x00bd
                           0000C8   379 _T2CON_0	=	0x00c8
                           0000C9   380 _T2CON_1	=	0x00c9
                           0000CA   381 _T2CON_2	=	0x00ca
                           0000CB   382 _T2CON_3	=	0x00cb
                           0000CC   383 _T2CON_4	=	0x00cc
                           0000CD   384 _T2CON_5	=	0x00cd
                           0000CE   385 _T2CON_6	=	0x00ce
                           0000CF   386 _T2CON_7	=	0x00cf
                           0000C8   387 _CP_RL2	=	0x00c8
                           0000C9   388 _C_T2	=	0x00c9
                           0000CA   389 _TR2	=	0x00ca
                           0000CB   390 _EXEN2	=	0x00cb
                           0000CC   391 _TCLK	=	0x00cc
                           0000CD   392 _RCLK	=	0x00cd
                           0000CE   393 _EXF2	=	0x00ce
                           0000CF   394 _TF2	=	0x00cf
                           0000DF   395 _CF	=	0x00df
                           0000DE   396 _CR	=	0x00de
                           0000DC   397 _CCF4	=	0x00dc
                           0000DB   398 _CCF3	=	0x00db
                           0000DA   399 _CCF2	=	0x00da
                           0000D9   400 _CCF1	=	0x00d9
                           0000D8   401 _CCF0	=	0x00d8
                           0000AE   402 _EC	=	0x00ae
                           0000BE   403 _PPCL	=	0x00be
                           0000BD   404 _PT2L	=	0x00bd
                           0000BC   405 _PSL	=	0x00bc
                           0000BB   406 _PT1L	=	0x00bb
                           0000BA   407 _PX1L	=	0x00ba
                           0000B9   408 _PT0L	=	0x00b9
                           0000B8   409 _PX0L	=	0x00b8
                           0000C0   410 _P4_0	=	0x00c0
                           0000C1   411 _P4_1	=	0x00c1
                           0000C2   412 _P4_2	=	0x00c2
                           0000C3   413 _P4_3	=	0x00c3
                           0000C4   414 _P4_4	=	0x00c4
                           0000C5   415 _P4_5	=	0x00c5
                           0000C6   416 _P4_6	=	0x00c6
                           0000C7   417 _P4_7	=	0x00c7
                           0000E8   418 _P5_0	=	0x00e8
                           0000E9   419 _P5_1	=	0x00e9
                           0000EA   420 _P5_2	=	0x00ea
                           0000EB   421 _P5_3	=	0x00eb
                           0000EC   422 _P5_4	=	0x00ec
                           0000ED   423 _P5_5	=	0x00ed
                           0000EE   424 _P5_6	=	0x00ee
                           0000EF   425 _P5_7	=	0x00ef
                                    426 ;--------------------------------------------------------
                                    427 ; overlayable register banks
                                    428 ;--------------------------------------------------------
                                    429 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        430 	.ds 8
                                    431 ;--------------------------------------------------------
                                    432 ; internal ram data
                                    433 ;--------------------------------------------------------
                                    434 	.area DSEG    (DATA)
                                    435 ;--------------------------------------------------------
                                    436 ; overlayable items in internal ram 
                                    437 ;--------------------------------------------------------
                                    438 ;--------------------------------------------------------
                                    439 ; Stack segment in internal ram 
                                    440 ;--------------------------------------------------------
                                    441 	.area	SSEG
      000037                        442 __start__stack:
      000037                        443 	.ds	1
                                    444 
                                    445 ;--------------------------------------------------------
                                    446 ; indirectly addressable internal ram data
                                    447 ;--------------------------------------------------------
                                    448 	.area ISEG    (DATA)
                                    449 ;--------------------------------------------------------
                                    450 ; absolute internal ram data
                                    451 ;--------------------------------------------------------
                                    452 	.area IABS    (ABS,DATA)
                                    453 	.area IABS    (ABS,DATA)
                                    454 ;--------------------------------------------------------
                                    455 ; bit data
                                    456 ;--------------------------------------------------------
                                    457 	.area BSEG    (BIT)
                                    458 ;--------------------------------------------------------
                                    459 ; paged external ram data
                                    460 ;--------------------------------------------------------
                                    461 	.area PSEG    (PAG,XDATA)
                                    462 ;--------------------------------------------------------
                                    463 ; external ram data
                                    464 ;--------------------------------------------------------
                                    465 	.area XSEG    (XDATA)
      00138E                        466 _main_i_65536_77:
      00138E                        467 	.ds 2
      001390                        468 _main_total_characters_received_since_last_query_65536_77:
      001390                        469 	.ds 4
      001394                        470 _main_buffers_65536_77:
      001394                        471 	.ds 1890
                                    472 ;--------------------------------------------------------
                                    473 ; absolute external ram data
                                    474 ;--------------------------------------------------------
                                    475 	.area XABS    (ABS,XDATA)
                                    476 ;--------------------------------------------------------
                                    477 ; external initialized ram data
                                    478 ;--------------------------------------------------------
                                    479 	.area XISEG   (XDATA)
                                    480 	.area HOME    (CODE)
                                    481 	.area GSINIT0 (CODE)
                                    482 	.area GSINIT1 (CODE)
                                    483 	.area GSINIT2 (CODE)
                                    484 	.area GSINIT3 (CODE)
                                    485 	.area GSINIT4 (CODE)
                                    486 	.area GSINIT5 (CODE)
                                    487 	.area GSINIT  (CODE)
                                    488 	.area GSFINAL (CODE)
                                    489 	.area CSEG    (CODE)
                                    490 ;--------------------------------------------------------
                                    491 ; interrupt vector 
                                    492 ;--------------------------------------------------------
                                    493 	.area HOME    (CODE)
      002000                        494 __interrupt_vect:
      002000 02 20 06         [24]  495 	ljmp	__sdcc_gsinit_startup
                                    496 ;--------------------------------------------------------
                                    497 ; global & static initialisations
                                    498 ;--------------------------------------------------------
                                    499 	.area HOME    (CODE)
                                    500 	.area GSINIT  (CODE)
                                    501 	.area GSFINAL (CODE)
                                    502 	.area GSINIT  (CODE)
                                    503 	.globl __sdcc_gsinit_startup
                                    504 	.globl __sdcc_program_startup
                                    505 	.globl __start__stack
                                    506 	.globl __mcs51_genXINIT
                                    507 	.globl __mcs51_genXRAMCLEAR
                                    508 	.globl __mcs51_genRAMCLEAR
                                    509 	.area GSFINAL (CODE)
      00205F 02 20 03         [24]  510 	ljmp	__sdcc_program_startup
                                    511 ;--------------------------------------------------------
                                    512 ; Home
                                    513 ;--------------------------------------------------------
                                    514 	.area HOME    (CODE)
                                    515 	.area HOME    (CODE)
      002003                        516 __sdcc_program_startup:
      002003 02 20 AF         [24]  517 	ljmp	_main
                                    518 ;	return from main will return to caller
                                    519 ;--------------------------------------------------------
                                    520 ; code
                                    521 ;--------------------------------------------------------
                                    522 	.area CSEG    (CODE)
                                    523 ;------------------------------------------------------------
                                    524 ;Allocation info for local variables in function '_sdcc_external_startup'
                                    525 ;------------------------------------------------------------
                                    526 ;	main.c:33: _sdcc_external_startup()
                                    527 ;	-----------------------------------------
                                    528 ;	 function _sdcc_external_startup
                                    529 ;	-----------------------------------------
      0020A8                        530 __sdcc_external_startup:
                           000007   531 	ar7 = 0x07
                           000006   532 	ar6 = 0x06
                           000005   533 	ar5 = 0x05
                           000004   534 	ar4 = 0x04
                           000003   535 	ar3 = 0x03
                           000002   536 	ar2 = 0x02
                           000001   537 	ar1 = 0x01
                           000000   538 	ar0 = 0x00
                                    539 ;	main.c:35: AUXR |= 0x0C; // 0000 1100
      0020A8 43 8E 0C         [24]  540 	orl	_AUXR,#0x0c
                                    541 ;	main.c:37: return 0;
      0020AB 90 00 00         [24]  542 	mov	dptr,#0x0000
                                    543 ;	main.c:38: }
      0020AE 22               [24]  544 	ret
                                    545 ;------------------------------------------------------------
                                    546 ;Allocation info for local variables in function 'main'
                                    547 ;------------------------------------------------------------
                                    548 ;received_char             Allocated with name '_main_received_char_65536_77'
                                    549 ;i                         Allocated with name '_main_i_65536_77'
                                    550 ;cmd                       Allocated with name '_main_cmd_65536_77'
                                    551 ;command_processed_status  Allocated with name '_main_command_processed_status_65536_77'
                                    552 ;total_characters_received Allocated with name '_main_total_characters_received_65536_77'
                                    553 ;total_characters_received_since_last_query Allocated with name '_main_total_characters_received_since_last_query_65536_77'
                                    554 ;buffers                   Allocated with name '_main_buffers_65536_77'
                                    555 ;------------------------------------------------------------
                                    556 ;	main.c:43: void main(void)
                                    557 ;	-----------------------------------------
                                    558 ;	 function main
                                    559 ;	-----------------------------------------
      0020AF                        560 _main:
                                    561 ;	main.c:46: volatile int i = 0;
      0020AF 90 13 8E         [24]  562 	mov	dptr,#_main_i_65536_77
      0020B2 E4               [12]  563 	clr	a
      0020B3 F0               [24]  564 	movx	@dptr,a
      0020B4 A3               [24]  565 	inc	dptr
      0020B5 F0               [24]  566 	movx	@dptr,a
                                    567 ;	main.c:50: long total_characters_received_since_last_query = 0;
      0020B6 90 13 90         [24]  568 	mov	dptr,#_main_total_characters_received_since_last_query_65536_77
      0020B9 F0               [24]  569 	movx	@dptr,a
      0020BA A3               [24]  570 	inc	dptr
      0020BB F0               [24]  571 	movx	@dptr,a
      0020BC A3               [24]  572 	inc	dptr
      0020BD F0               [24]  573 	movx	@dptr,a
      0020BE A3               [24]  574 	inc	dptr
      0020BF F0               [24]  575 	movx	@dptr,a
                                    576 ;	main.c:59: uart_init();
      0020C0 12 23 CC         [24]  577 	lcall	_uart_init
                                    578 ;	main.c:61: memset(buffers, 0, sizeof(buffers));
      0020C3 90 1B 4A         [24]  579 	mov	dptr,#_memset_PARM_2
      0020C6 E4               [12]  580 	clr	a
      0020C7 F0               [24]  581 	movx	@dptr,a
      0020C8 90 1B 4B         [24]  582 	mov	dptr,#_memset_PARM_3
      0020CB 74 62            [12]  583 	mov	a,#0x62
      0020CD F0               [24]  584 	movx	@dptr,a
      0020CE 74 07            [12]  585 	mov	a,#0x07
      0020D0 A3               [24]  586 	inc	dptr
      0020D1 F0               [24]  587 	movx	@dptr,a
      0020D2 90 13 94         [24]  588 	mov	dptr,#_main_buffers_65536_77
      0020D5 75 F0 00         [24]  589 	mov	b,#0x00
      0020D8 12 37 EB         [24]  590 	lcall	_memset
                                    591 ;	main.c:63: putstr("Specify buffer size (48 bytes to 4800 bytes in multiples of 16): ");
      0020DB 90 4A 14         [24]  592 	mov	dptr,#___str_0
      0020DE 75 F0 80         [24]  593 	mov	b,#0x80
      0020E1 12 2E 3D         [24]  594 	lcall	_putstr
                                    595 ;	main.c:64: buffers[0].buf_size = accept_number_from_user();
      0020E4 12 2E B3         [24]  596 	lcall	_accept_number_from_user
      0020E7 AE 82            [24]  597 	mov	r6,dpl
      0020E9 AF 83            [24]  598 	mov	r7,dph
      0020EB 90 13 9B         [24]  599 	mov	dptr,#(_main_buffers_65536_77 + 0x0007)
      0020EE EE               [12]  600 	mov	a,r6
      0020EF F0               [24]  601 	movx	@dptr,a
      0020F0 EF               [12]  602 	mov	a,r7
      0020F1 A3               [24]  603 	inc	dptr
      0020F2 F0               [24]  604 	movx	@dptr,a
                                    605 ;	main.c:65: buffers[1].buf_size = buffers[0].buf_size;
      0020F3 90 13 A4         [24]  606 	mov	dptr,#(_main_buffers_65536_77 + 0x0010)
      0020F6 EE               [12]  607 	mov	a,r6
      0020F7 F0               [24]  608 	movx	@dptr,a
      0020F8 EF               [12]  609 	mov	a,r7
      0020F9 A3               [24]  610 	inc	dptr
      0020FA F0               [24]  611 	movx	@dptr,a
                                    612 ;	main.c:67: while ((buffers[0].buf_size % 16 != 0) || (buffers[0].buf_size < 48) || (buffers[0].buf_size > 4800))
      0020FB                        613 00103$:
      0020FB 90 13 9B         [24]  614 	mov	dptr,#(_main_buffers_65536_77 + 0x0007)
      0020FE E0               [24]  615 	movx	a,@dptr
      0020FF FE               [12]  616 	mov	r6,a
      002100 A3               [24]  617 	inc	dptr
      002101 E0               [24]  618 	movx	a,@dptr
      002102 FF               [12]  619 	mov	r7,a
      002103 90 1B 64         [24]  620 	mov	dptr,#__modsint_PARM_2
      002106 74 10            [12]  621 	mov	a,#0x10
      002108 F0               [24]  622 	movx	@dptr,a
      002109 E4               [12]  623 	clr	a
      00210A A3               [24]  624 	inc	dptr
      00210B F0               [24]  625 	movx	@dptr,a
      00210C 8E 82            [24]  626 	mov	dpl,r6
      00210E 8F 83            [24]  627 	mov	dph,r7
      002110 12 3C 8A         [24]  628 	lcall	__modsint
      002113 E5 82            [12]  629 	mov	a,dpl
      002115 85 83 F0         [24]  630 	mov	b,dph
      002118 45 F0            [12]  631 	orl	a,b
      00211A 70 2A            [24]  632 	jnz	00104$
      00211C 90 13 9B         [24]  633 	mov	dptr,#(_main_buffers_65536_77 + 0x0007)
      00211F E0               [24]  634 	movx	a,@dptr
      002120 FE               [12]  635 	mov	r6,a
      002121 A3               [24]  636 	inc	dptr
      002122 E0               [24]  637 	movx	a,@dptr
      002123 FF               [12]  638 	mov	r7,a
      002124 C3               [12]  639 	clr	c
      002125 EE               [12]  640 	mov	a,r6
      002126 94 30            [12]  641 	subb	a,#0x30
      002128 EF               [12]  642 	mov	a,r7
      002129 64 80            [12]  643 	xrl	a,#0x80
      00212B 94 80            [12]  644 	subb	a,#0x80
      00212D 40 17            [24]  645 	jc	00104$
      00212F 90 13 9B         [24]  646 	mov	dptr,#(_main_buffers_65536_77 + 0x0007)
      002132 E0               [24]  647 	movx	a,@dptr
      002133 FE               [12]  648 	mov	r6,a
      002134 A3               [24]  649 	inc	dptr
      002135 E0               [24]  650 	movx	a,@dptr
      002136 FF               [12]  651 	mov	r7,a
      002137 C3               [12]  652 	clr	c
      002138 74 C0            [12]  653 	mov	a,#0xc0
      00213A 9E               [12]  654 	subb	a,r6
      00213B 74 92            [12]  655 	mov	a,#(0x12 ^ 0x80)
      00213D 8F F0            [24]  656 	mov	b,r7
      00213F 63 F0 80         [24]  657 	xrl	b,#0x80
      002142 95 F0            [12]  658 	subb	a,b
      002144 50 35            [24]  659 	jnc	00105$
      002146                        660 00104$:
                                    661 ;	main.c:69: putstr("============================================================================\r\n");
      002146 90 4A 56         [24]  662 	mov	dptr,#___str_1
      002149 75 F0 80         [24]  663 	mov	b,#0x80
      00214C 12 2E 3D         [24]  664 	lcall	_putstr
                                    665 ;	main.c:70: putstr("Invalid size entered\r\n");
      00214F 90 4A A5         [24]  666 	mov	dptr,#___str_2
      002152 75 F0 80         [24]  667 	mov	b,#0x80
      002155 12 2E 3D         [24]  668 	lcall	_putstr
                                    669 ;	main.c:71: putstr("Specify buffer size (48 bytes to 4800 bytes in multiples of 16): ");
      002158 90 4A 14         [24]  670 	mov	dptr,#___str_0
      00215B 75 F0 80         [24]  671 	mov	b,#0x80
      00215E 12 2E 3D         [24]  672 	lcall	_putstr
                                    673 ;	main.c:72: buffers[0].buf_size = accept_number_from_user();
      002161 12 2E B3         [24]  674 	lcall	_accept_number_from_user
      002164 AE 82            [24]  675 	mov	r6,dpl
      002166 AF 83            [24]  676 	mov	r7,dph
      002168 90 13 9B         [24]  677 	mov	dptr,#(_main_buffers_65536_77 + 0x0007)
      00216B EE               [12]  678 	mov	a,r6
      00216C F0               [24]  679 	movx	@dptr,a
      00216D EF               [12]  680 	mov	a,r7
      00216E A3               [24]  681 	inc	dptr
      00216F F0               [24]  682 	movx	@dptr,a
                                    683 ;	main.c:73: buffers[1].buf_size = buffers[0].buf_size;
      002170 90 13 A4         [24]  684 	mov	dptr,#(_main_buffers_65536_77 + 0x0010)
      002173 EE               [12]  685 	mov	a,r6
      002174 F0               [24]  686 	movx	@dptr,a
      002175 EF               [12]  687 	mov	a,r7
      002176 A3               [24]  688 	inc	dptr
      002177 F0               [24]  689 	movx	@dptr,a
      002178 02 20 FB         [24]  690 	ljmp	00103$
      00217B                        691 00105$:
                                    692 ;	main.c:77: buffers[0].buffer_pointer = (uint8_t *)malloc(buffers[0].buf_size);
      00217B 90 13 9B         [24]  693 	mov	dptr,#(_main_buffers_65536_77 + 0x0007)
      00217E E0               [24]  694 	movx	a,@dptr
      00217F FE               [12]  695 	mov	r6,a
      002180 A3               [24]  696 	inc	dptr
      002181 E0               [24]  697 	movx	a,@dptr
      002182 FF               [12]  698 	mov	r7,a
      002183 8E 82            [24]  699 	mov	dpl,r6
      002185 8F 83            [24]  700 	mov	dph,r7
      002187 12 3B 21         [24]  701 	lcall	_malloc
      00218A AE 82            [24]  702 	mov	r6,dpl
      00218C AF 83            [24]  703 	mov	r7,dph
      00218E 7D 00            [12]  704 	mov	r5,#0x00
      002190 90 13 94         [24]  705 	mov	dptr,#_main_buffers_65536_77
      002193 EE               [12]  706 	mov	a,r6
      002194 F0               [24]  707 	movx	@dptr,a
      002195 EF               [12]  708 	mov	a,r7
      002196 A3               [24]  709 	inc	dptr
      002197 F0               [24]  710 	movx	@dptr,a
      002198 ED               [12]  711 	mov	a,r5
      002199 A3               [24]  712 	inc	dptr
      00219A F0               [24]  713 	movx	@dptr,a
                                    714 ;	main.c:78: if (buffers[0].buffer_pointer != NULL)
      00219B EE               [12]  715 	mov	a,r6
      00219C 4F               [12]  716 	orl	a,r7
      00219D 60 12            [24]  717 	jz	00107$
                                    718 ;	main.c:80: putstr("Success: malloc for buffer0 successful\r\n");
      00219F 90 4A BC         [24]  719 	mov	dptr,#___str_3
      0021A2 75 F0 80         [24]  720 	mov	b,#0x80
      0021A5 12 2E 3D         [24]  721 	lcall	_putstr
                                    722 ;	main.c:81: buffers[0].buf_id = 0;
      0021A8 90 13 99         [24]  723 	mov	dptr,#(_main_buffers_65536_77 + 0x0005)
      0021AB E4               [12]  724 	clr	a
      0021AC F0               [24]  725 	movx	@dptr,a
      0021AD A3               [24]  726 	inc	dptr
      0021AE F0               [24]  727 	movx	@dptr,a
      0021AF 80 09            [24]  728 	sjmp	00108$
      0021B1                        729 00107$:
                                    730 ;	main.c:85: putstr("Error: malloc for buffer0 failed\r\n");
      0021B1 90 4A E5         [24]  731 	mov	dptr,#___str_4
      0021B4 75 F0 80         [24]  732 	mov	b,#0x80
                                    733 ;	main.c:87: return;
      0021B7 02 2E 3D         [24]  734 	ljmp	_putstr
      0021BA                        735 00108$:
                                    736 ;	main.c:91: buffers[1].buffer_pointer = (uint8_t *)malloc(buffers[1].buf_size);
      0021BA 90 13 A4         [24]  737 	mov	dptr,#(_main_buffers_65536_77 + 0x0010)
      0021BD E0               [24]  738 	movx	a,@dptr
      0021BE FE               [12]  739 	mov	r6,a
      0021BF A3               [24]  740 	inc	dptr
      0021C0 E0               [24]  741 	movx	a,@dptr
      0021C1 FF               [12]  742 	mov	r7,a
      0021C2 8E 82            [24]  743 	mov	dpl,r6
      0021C4 8F 83            [24]  744 	mov	dph,r7
      0021C6 12 3B 21         [24]  745 	lcall	_malloc
      0021C9 AE 82            [24]  746 	mov	r6,dpl
      0021CB AF 83            [24]  747 	mov	r7,dph
      0021CD 7D 00            [12]  748 	mov	r5,#0x00
      0021CF 90 13 9D         [24]  749 	mov	dptr,#(_main_buffers_65536_77 + 0x0009)
      0021D2 EE               [12]  750 	mov	a,r6
      0021D3 F0               [24]  751 	movx	@dptr,a
      0021D4 EF               [12]  752 	mov	a,r7
      0021D5 A3               [24]  753 	inc	dptr
      0021D6 F0               [24]  754 	movx	@dptr,a
      0021D7 ED               [12]  755 	mov	a,r5
      0021D8 A3               [24]  756 	inc	dptr
      0021D9 F0               [24]  757 	movx	@dptr,a
                                    758 ;	main.c:92: if (buffers[1].buffer_pointer != NULL)
      0021DA EE               [12]  759 	mov	a,r6
      0021DB 4F               [12]  760 	orl	a,r7
      0021DC 60 14            [24]  761 	jz	00110$
                                    762 ;	main.c:94: putstr("Success: malloc for buffer1 successful\r\n");
      0021DE 90 4B 08         [24]  763 	mov	dptr,#___str_5
      0021E1 75 F0 80         [24]  764 	mov	b,#0x80
      0021E4 12 2E 3D         [24]  765 	lcall	_putstr
                                    766 ;	main.c:95: buffers[1].buf_id = 1;
      0021E7 90 13 A2         [24]  767 	mov	dptr,#(_main_buffers_65536_77 + 0x000e)
      0021EA 74 01            [12]  768 	mov	a,#0x01
      0021EC F0               [24]  769 	movx	@dptr,a
      0021ED E4               [12]  770 	clr	a
      0021EE A3               [24]  771 	inc	dptr
      0021EF F0               [24]  772 	movx	@dptr,a
      0021F0 80 1D            [24]  773 	sjmp	00111$
      0021F2                        774 00110$:
                                    775 ;	main.c:99: putstr("Error: malloc for buffer1 failed, clearing buffers\r\n");
      0021F2 90 4B 31         [24]  776 	mov	dptr,#___str_6
      0021F5 75 F0 80         [24]  777 	mov	b,#0x80
      0021F8 12 2E 3D         [24]  778 	lcall	_putstr
                                    779 ;	main.c:100: free(buffers[0].buffer_pointer);
      0021FB 90 13 94         [24]  780 	mov	dptr,#_main_buffers_65536_77
      0021FE E0               [24]  781 	movx	a,@dptr
      0021FF FD               [12]  782 	mov	r5,a
      002200 A3               [24]  783 	inc	dptr
      002201 E0               [24]  784 	movx	a,@dptr
      002202 FE               [12]  785 	mov	r6,a
      002203 A3               [24]  786 	inc	dptr
      002204 E0               [24]  787 	movx	a,@dptr
      002205 FF               [12]  788 	mov	r7,a
      002206 8D 82            [24]  789 	mov	dpl,r5
      002208 8E 83            [24]  790 	mov	dph,r6
      00220A 8F F0            [24]  791 	mov	b,r7
                                    792 ;	main.c:102: return;
      00220C 02 36 94         [24]  793 	ljmp	_free
      00220F                        794 00111$:
                                    795 ;	main.c:105: putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
      00220F 90 4B 66         [24]  796 	mov	dptr,#___str_7
      002212 75 F0 80         [24]  797 	mov	b,#0x80
      002215 12 2E 3D         [24]  798 	lcall	_putstr
                                    799 ;	main.c:106: putstr("Enter command (+, -, ?, =, @) or input: ");
      002218 90 4B B3         [24]  800 	mov	dptr,#___str_8
      00221B 75 F0 80         [24]  801 	mov	b,#0x80
      00221E 12 2E 3D         [24]  802 	lcall	_putstr
                                    803 ;	main.c:108: while (1)
      002221 7C 00            [12]  804 	mov	r4,#0x00
      002223 7D 00            [12]  805 	mov	r5,#0x00
      002225 7E 00            [12]  806 	mov	r6,#0x00
      002227 7F 00            [12]  807 	mov	r7,#0x00
      002229                        808 00123$:
                                    809 ;	main.c:111: received_char = getchar();
      002229 C0 07            [24]  810 	push	ar7
      00222B C0 06            [24]  811 	push	ar6
      00222D C0 05            [24]  812 	push	ar5
      00222F C0 04            [24]  813 	push	ar4
      002231 12 2E 2B         [24]  814 	lcall	_getchar
      002234 AA 82            [24]  815 	mov	r2,dpl
                                    816 ;	main.c:112: DEBUGPORT(received_char);
      002236 90 13 89         [24]  817 	mov	dptr,#_dataout_PARM_2
      002239 EA               [12]  818 	mov	a,r2
      00223A F0               [24]  819 	movx	@dptr,a
      00223B 90 FF FF         [24]  820 	mov	dptr,#0xffff
      00223E 75 F0 00         [24]  821 	mov	b,#0x00
      002241 C0 02            [24]  822 	push	ar2
      002243 12 20 62         [24]  823 	lcall	_dataout
      002246 D0 02            [24]  824 	pop	ar2
      002248 D0 04            [24]  825 	pop	ar4
      00224A D0 05            [24]  826 	pop	ar5
      00224C D0 06            [24]  827 	pop	ar6
      00224E D0 07            [24]  828 	pop	ar7
                                    829 ;	main.c:115: if (((received_char >= 'a') && (received_char <= 'z')))
      002250 BA 61 00         [24]  830 	cjne	r2,#0x61,00180$
      002253                        831 00180$:
      002253 E4               [12]  832 	clr	a
      002254 33               [12]  833 	rlc	a
      002255 FB               [12]  834 	mov	r3,a
      002256 70 5F            [24]  835 	jnz	00115$
      002258 EA               [12]  836 	mov	a,r2
      002259 24 85            [12]  837 	add	a,#0xff - 0x7a
      00225B 40 5A            [24]  838 	jc	00115$
                                    839 ;	main.c:117: if(buffers[0].buf_index % 40 == 0)
      00225D 90 13 97         [24]  840 	mov	dptr,#(_main_buffers_65536_77 + 0x0003)
      002260 E0               [24]  841 	movx	a,@dptr
      002261 F8               [12]  842 	mov	r0,a
      002262 A3               [24]  843 	inc	dptr
      002263 E0               [24]  844 	movx	a,@dptr
      002264 F9               [12]  845 	mov	r1,a
      002265 90 1B 64         [24]  846 	mov	dptr,#__modsint_PARM_2
      002268 74 28            [12]  847 	mov	a,#0x28
      00226A F0               [24]  848 	movx	@dptr,a
      00226B E4               [12]  849 	clr	a
      00226C A3               [24]  850 	inc	dptr
      00226D F0               [24]  851 	movx	@dptr,a
      00226E 88 82            [24]  852 	mov	dpl,r0
      002270 89 83            [24]  853 	mov	dph,r1
      002272 C0 07            [24]  854 	push	ar7
      002274 C0 06            [24]  855 	push	ar6
      002276 C0 05            [24]  856 	push	ar5
      002278 C0 04            [24]  857 	push	ar4
      00227A C0 03            [24]  858 	push	ar3
      00227C C0 02            [24]  859 	push	ar2
      00227E 12 3C 8A         [24]  860 	lcall	__modsint
      002281 E5 82            [12]  861 	mov	a,dpl
      002283 85 83 F0         [24]  862 	mov	b,dph
      002286 D0 02            [24]  863 	pop	ar2
      002288 D0 03            [24]  864 	pop	ar3
      00228A D0 04            [24]  865 	pop	ar4
      00228C D0 05            [24]  866 	pop	ar5
      00228E D0 06            [24]  867 	pop	ar6
      002290 D0 07            [24]  868 	pop	ar7
      002292 45 F0            [12]  869 	orl	a,b
      002294 70 21            [24]  870 	jnz	00115$
                                    871 ;	main.c:118: putstr("\r\n\t\t");
      002296 90 4B DC         [24]  872 	mov	dptr,#___str_9
      002299 75 F0 80         [24]  873 	mov	b,#0x80
      00229C C0 07            [24]  874 	push	ar7
      00229E C0 06            [24]  875 	push	ar6
      0022A0 C0 05            [24]  876 	push	ar5
      0022A2 C0 04            [24]  877 	push	ar4
      0022A4 C0 03            [24]  878 	push	ar3
      0022A6 C0 02            [24]  879 	push	ar2
      0022A8 12 2E 3D         [24]  880 	lcall	_putstr
      0022AB D0 02            [24]  881 	pop	ar2
      0022AD D0 03            [24]  882 	pop	ar3
      0022AF D0 04            [24]  883 	pop	ar4
      0022B1 D0 05            [24]  884 	pop	ar5
      0022B3 D0 06            [24]  885 	pop	ar6
      0022B5 D0 07            [24]  886 	pop	ar7
      0022B7                        887 00115$:
                                    888 ;	main.c:121: echo(received_char); // echoing characters back
      0022B7 8A 82            [24]  889 	mov	dpl,r2
      0022B9 C0 07            [24]  890 	push	ar7
      0022BB C0 06            [24]  891 	push	ar6
      0022BD C0 05            [24]  892 	push	ar5
      0022BF C0 04            [24]  893 	push	ar4
      0022C1 C0 03            [24]  894 	push	ar3
      0022C3 C0 02            [24]  895 	push	ar2
      0022C5 12 23 D7         [24]  896 	lcall	_echo
      0022C8 D0 02            [24]  897 	pop	ar2
      0022CA D0 03            [24]  898 	pop	ar3
      0022CC D0 04            [24]  899 	pop	ar4
      0022CE D0 05            [24]  900 	pop	ar5
      0022D0 D0 06            [24]  901 	pop	ar6
      0022D2 D0 07            [24]  902 	pop	ar7
                                    903 ;	main.c:122: total_characters_received++;
      0022D4 0C               [12]  904 	inc	r4
      0022D5 BC 00 09         [24]  905 	cjne	r4,#0x00,00184$
      0022D8 0D               [12]  906 	inc	r5
      0022D9 BD 00 05         [24]  907 	cjne	r5,#0x00,00184$
      0022DC 0E               [12]  908 	inc	r6
      0022DD BE 00 01         [24]  909 	cjne	r6,#0x00,00184$
      0022E0 0F               [12]  910 	inc	r7
      0022E1                        911 00184$:
                                    912 ;	main.c:123: total_characters_received_since_last_query++;
      0022E1 90 13 90         [24]  913 	mov	dptr,#_main_total_characters_received_since_last_query_65536_77
      0022E4 E0               [24]  914 	movx	a,@dptr
      0022E5 24 01            [12]  915 	add	a,#0x01
      0022E7 F0               [24]  916 	movx	@dptr,a
      0022E8 A3               [24]  917 	inc	dptr
      0022E9 E0               [24]  918 	movx	a,@dptr
      0022EA 34 00            [12]  919 	addc	a,#0x00
      0022EC F0               [24]  920 	movx	@dptr,a
      0022ED A3               [24]  921 	inc	dptr
      0022EE E0               [24]  922 	movx	a,@dptr
      0022EF 34 00            [12]  923 	addc	a,#0x00
      0022F1 F0               [24]  924 	movx	@dptr,a
      0022F2 A3               [24]  925 	inc	dptr
      0022F3 E0               [24]  926 	movx	a,@dptr
      0022F4 34 00            [12]  927 	addc	a,#0x00
      0022F6 F0               [24]  928 	movx	@dptr,a
                                    929 ;	main.c:125: if ((received_char >= 'a') && (received_char <= 'z'))
      0022F7 EB               [12]  930 	mov	a,r3
      0022F8 70 47            [24]  931 	jnz	00118$
      0022FA EA               [12]  932 	mov	a,r2
      0022FB 24 85            [12]  933 	add	a,#0xff - 0x7a
      0022FD 40 42            [24]  934 	jc	00118$
                                    935 ;	main.c:126: buffers[0].buffer_pointer[buffers[0].buf_index++] = received_char;
      0022FF C0 04            [24]  936 	push	ar4
      002301 C0 05            [24]  937 	push	ar5
      002303 C0 06            [24]  938 	push	ar6
      002305 C0 07            [24]  939 	push	ar7
      002307 90 13 94         [24]  940 	mov	dptr,#_main_buffers_65536_77
      00230A E0               [24]  941 	movx	a,@dptr
      00230B F8               [12]  942 	mov	r0,a
      00230C A3               [24]  943 	inc	dptr
      00230D E0               [24]  944 	movx	a,@dptr
      00230E F9               [12]  945 	mov	r1,a
      00230F A3               [24]  946 	inc	dptr
      002310 E0               [24]  947 	movx	a,@dptr
      002311 FB               [12]  948 	mov	r3,a
      002312 90 13 97         [24]  949 	mov	dptr,#(_main_buffers_65536_77 + 0x0003)
      002315 E0               [24]  950 	movx	a,@dptr
      002316 FE               [12]  951 	mov	r6,a
      002317 A3               [24]  952 	inc	dptr
      002318 E0               [24]  953 	movx	a,@dptr
      002319 FF               [12]  954 	mov	r7,a
      00231A 74 01            [12]  955 	mov	a,#0x01
      00231C 2E               [12]  956 	add	a,r6
      00231D FC               [12]  957 	mov	r4,a
      00231E E4               [12]  958 	clr	a
      00231F 3F               [12]  959 	addc	a,r7
      002320 FD               [12]  960 	mov	r5,a
      002321 90 13 97         [24]  961 	mov	dptr,#(_main_buffers_65536_77 + 0x0003)
      002324 EC               [12]  962 	mov	a,r4
      002325 F0               [24]  963 	movx	@dptr,a
      002326 ED               [12]  964 	mov	a,r5
      002327 A3               [24]  965 	inc	dptr
      002328 F0               [24]  966 	movx	@dptr,a
      002329 EE               [12]  967 	mov	a,r6
      00232A 28               [12]  968 	add	a,r0
      00232B F8               [12]  969 	mov	r0,a
      00232C EF               [12]  970 	mov	a,r7
      00232D 39               [12]  971 	addc	a,r1
      00232E F9               [12]  972 	mov	r1,a
      00232F 88 82            [24]  973 	mov	dpl,r0
      002331 89 83            [24]  974 	mov	dph,r1
      002333 8B F0            [24]  975 	mov	b,r3
      002335 EA               [12]  976 	mov	a,r2
      002336 12 39 A1         [24]  977 	lcall	__gptrput
                                    978 ;	main.c:135: command(received_char, buffers);
      002339 D0 07            [24]  979 	pop	ar7
      00233B D0 06            [24]  980 	pop	ar6
      00233D D0 05            [24]  981 	pop	ar5
      00233F D0 04            [24]  982 	pop	ar4
                                    983 ;	main.c:126: buffers[0].buffer_pointer[buffers[0].buf_index++] = received_char;
      002341                        984 00118$:
                                    985 ;	main.c:128: if (received_char == '?')
      002341 BA 3F 63         [24]  986 	cjne	r2,#0x3f,00121$
                                    987 ;	main.c:130: printf("\r\n\tTotal Characters received: %ld\r\n", total_characters_received);
      002344 C0 07            [24]  988 	push	ar7
      002346 C0 06            [24]  989 	push	ar6
      002348 C0 05            [24]  990 	push	ar5
      00234A C0 04            [24]  991 	push	ar4
      00234C C0 02            [24]  992 	push	ar2
      00234E C0 04            [24]  993 	push	ar4
      002350 C0 05            [24]  994 	push	ar5
      002352 C0 06            [24]  995 	push	ar6
      002354 C0 07            [24]  996 	push	ar7
      002356 74 E1            [12]  997 	mov	a,#___str_10
      002358 C0 E0            [24]  998 	push	acc
      00235A 74 4B            [12]  999 	mov	a,#(___str_10 >> 8)
      00235C C0 E0            [24] 1000 	push	acc
      00235E 74 80            [12] 1001 	mov	a,#0x80
      002360 C0 E0            [24] 1002 	push	acc
      002362 12 3F D4         [24] 1003 	lcall	_printf
      002365 E5 81            [12] 1004 	mov	a,sp
      002367 24 F9            [12] 1005 	add	a,#0xf9
      002369 F5 81            [12] 1006 	mov	sp,a
                                   1007 ;	main.c:131: printf("\tTotal Characters received since last query: %ld\r\n", total_characters_received_since_last_query);
      00236B 90 13 90         [24] 1008 	mov	dptr,#_main_total_characters_received_since_last_query_65536_77
      00236E E0               [24] 1009 	movx	a,@dptr
      00236F C0 E0            [24] 1010 	push	acc
      002371 A3               [24] 1011 	inc	dptr
      002372 E0               [24] 1012 	movx	a,@dptr
      002373 C0 E0            [24] 1013 	push	acc
      002375 A3               [24] 1014 	inc	dptr
      002376 E0               [24] 1015 	movx	a,@dptr
      002377 C0 E0            [24] 1016 	push	acc
      002379 A3               [24] 1017 	inc	dptr
      00237A E0               [24] 1018 	movx	a,@dptr
      00237B C0 E0            [24] 1019 	push	acc
      00237D 74 05            [12] 1020 	mov	a,#___str_11
      00237F C0 E0            [24] 1021 	push	acc
      002381 74 4C            [12] 1022 	mov	a,#(___str_11 >> 8)
      002383 C0 E0            [24] 1023 	push	acc
      002385 74 80            [12] 1024 	mov	a,#0x80
      002387 C0 E0            [24] 1025 	push	acc
      002389 12 3F D4         [24] 1026 	lcall	_printf
      00238C E5 81            [12] 1027 	mov	a,sp
      00238E 24 F9            [12] 1028 	add	a,#0xf9
      002390 F5 81            [12] 1029 	mov	sp,a
      002392 D0 02            [24] 1030 	pop	ar2
      002394 D0 04            [24] 1031 	pop	ar4
      002396 D0 05            [24] 1032 	pop	ar5
      002398 D0 06            [24] 1033 	pop	ar6
      00239A D0 07            [24] 1034 	pop	ar7
                                   1035 ;	main.c:132: total_characters_received_since_last_query = 0;
      00239C 90 13 90         [24] 1036 	mov	dptr,#_main_total_characters_received_since_last_query_65536_77
      00239F E4               [12] 1037 	clr	a
      0023A0 F0               [24] 1038 	movx	@dptr,a
      0023A1 A3               [24] 1039 	inc	dptr
      0023A2 F0               [24] 1040 	movx	@dptr,a
      0023A3 A3               [24] 1041 	inc	dptr
      0023A4 F0               [24] 1042 	movx	@dptr,a
      0023A5 A3               [24] 1043 	inc	dptr
      0023A6 F0               [24] 1044 	movx	@dptr,a
      0023A7                       1045 00121$:
                                   1046 ;	main.c:135: command(received_char, buffers);
      0023A7 90 1A F7         [24] 1047 	mov	dptr,#_command_PARM_2
      0023AA 74 94            [12] 1048 	mov	a,#_main_buffers_65536_77
      0023AC F0               [24] 1049 	movx	@dptr,a
      0023AD 74 13            [12] 1050 	mov	a,#(_main_buffers_65536_77 >> 8)
      0023AF A3               [24] 1051 	inc	dptr
      0023B0 F0               [24] 1052 	movx	@dptr,a
      0023B1 E4               [12] 1053 	clr	a
      0023B2 A3               [24] 1054 	inc	dptr
      0023B3 F0               [24] 1055 	movx	@dptr,a
      0023B4 8A 82            [24] 1056 	mov	dpl,r2
      0023B6 C0 07            [24] 1057 	push	ar7
      0023B8 C0 06            [24] 1058 	push	ar6
      0023BA C0 05            [24] 1059 	push	ar5
      0023BC C0 04            [24] 1060 	push	ar4
      0023BE 12 24 15         [24] 1061 	lcall	_command
      0023C1 D0 04            [24] 1062 	pop	ar4
      0023C3 D0 05            [24] 1063 	pop	ar5
      0023C5 D0 06            [24] 1064 	pop	ar6
      0023C7 D0 07            [24] 1065 	pop	ar7
                                   1066 ;	main.c:137: }
      0023C9 02 22 29         [24] 1067 	ljmp	00123$
                                   1068 	.area CSEG    (CODE)
                                   1069 	.area CONST   (CODE)
                                   1070 	.area CONST   (CODE)
      004A14                       1071 ___str_0:
      004A14 53 70 65 63 69 66 79  1072 	.ascii "Specify buffer size (48 bytes to 4800 bytes in multiples of "
             20 62 75 66 66 65 72
             20 73 69 7A 65 20 28
             34 38 20 62 79 74 65
             73 20 74 6F 20 34 38
             30 30 20 62 79 74 65
             73 20 69 6E 20 6D 75
             6C 74 69 70 6C 65 73
             20 6F 66 20
      004A50 31 36 29 3A 20        1073 	.ascii "16): "
      004A55 00                    1074 	.db 0x00
                                   1075 	.area CSEG    (CODE)
                                   1076 	.area CONST   (CODE)
      004A56                       1077 ___str_1:
      004A56 3D 3D 3D 3D 3D 3D 3D  1078 	.ascii "============================================================"
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D
      004A92 3D 3D 3D 3D 3D 3D 3D  1079 	.ascii "================"
             3D 3D 3D 3D 3D 3D 3D
             3D 3D
      004AA2 0D                    1080 	.db 0x0d
      004AA3 0A                    1081 	.db 0x0a
      004AA4 00                    1082 	.db 0x00
                                   1083 	.area CSEG    (CODE)
                                   1084 	.area CONST   (CODE)
      004AA5                       1085 ___str_2:
      004AA5 49 6E 76 61 6C 69 64  1086 	.ascii "Invalid size entered"
             20 73 69 7A 65 20 65
             6E 74 65 72 65 64
      004AB9 0D                    1087 	.db 0x0d
      004ABA 0A                    1088 	.db 0x0a
      004ABB 00                    1089 	.db 0x00
                                   1090 	.area CSEG    (CODE)
                                   1091 	.area CONST   (CODE)
      004ABC                       1092 ___str_3:
      004ABC 53 75 63 63 65 73 73  1093 	.ascii "Success: malloc for buffer0 successful"
             3A 20 6D 61 6C 6C 6F
             63 20 66 6F 72 20 62
             75 66 66 65 72 30 20
             73 75 63 63 65 73 73
             66 75 6C
      004AE2 0D                    1094 	.db 0x0d
      004AE3 0A                    1095 	.db 0x0a
      004AE4 00                    1096 	.db 0x00
                                   1097 	.area CSEG    (CODE)
                                   1098 	.area CONST   (CODE)
      004AE5                       1099 ___str_4:
      004AE5 45 72 72 6F 72 3A 20  1100 	.ascii "Error: malloc for buffer0 failed"
             6D 61 6C 6C 6F 63 20
             66 6F 72 20 62 75 66
             66 65 72 30 20 66 61
             69 6C 65 64
      004B05 0D                    1101 	.db 0x0d
      004B06 0A                    1102 	.db 0x0a
      004B07 00                    1103 	.db 0x00
                                   1104 	.area CSEG    (CODE)
                                   1105 	.area CONST   (CODE)
      004B08                       1106 ___str_5:
      004B08 53 75 63 63 65 73 73  1107 	.ascii "Success: malloc for buffer1 successful"
             3A 20 6D 61 6C 6C 6F
             63 20 66 6F 72 20 62
             75 66 66 65 72 31 20
             73 75 63 63 65 73 73
             66 75 6C
      004B2E 0D                    1108 	.db 0x0d
      004B2F 0A                    1109 	.db 0x0a
      004B30 00                    1110 	.db 0x00
                                   1111 	.area CSEG    (CODE)
                                   1112 	.area CONST   (CODE)
      004B31                       1113 ___str_6:
      004B31 45 72 72 6F 72 3A 20  1114 	.ascii "Error: malloc for buffer1 failed, clearing buffers"
             6D 61 6C 6C 6F 63 20
             66 6F 72 20 62 75 66
             66 65 72 31 20 66 61
             69 6C 65 64 2C 20 63
             6C 65 61 72 69 6E 67
             20 62 75 66 66 65 72
             73
      004B63 0D                    1115 	.db 0x0d
      004B64 0A                    1116 	.db 0x0a
      004B65 00                    1117 	.db 0x00
                                   1118 	.area CSEG    (CODE)
                                   1119 	.area CONST   (CODE)
      004B66                       1120 ___str_7:
      004B66 0D                    1121 	.db 0x0d
      004B67 0A                    1122 	.db 0x0a
      004B68 2D 2D 2D 2D 2D 2D 2D  1123 	.ascii "------------------------------------------------------------"
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D
      004BA4 2D 2D 2D 2D 2D 2D 2D  1124 	.ascii "----------"
             2D 2D 2D
      004BAE 0D                    1125 	.db 0x0d
      004BAF 0A                    1126 	.db 0x0a
      004BB0 0D                    1127 	.db 0x0d
      004BB1 0A                    1128 	.db 0x0a
      004BB2 00                    1129 	.db 0x00
                                   1130 	.area CSEG    (CODE)
                                   1131 	.area CONST   (CODE)
      004BB3                       1132 ___str_8:
      004BB3 45 6E 74 65 72 20 63  1133 	.ascii "Enter command (+, -, ?, =, @) or input: "
             6F 6D 6D 61 6E 64 20
             28 2B 2C 20 2D 2C 20
             3F 2C 20 3D 2C 20 40
             29 20 6F 72 20 69 6E
             70 75 74 3A 20
      004BDB 00                    1134 	.db 0x00
                                   1135 	.area CSEG    (CODE)
                                   1136 	.area CONST   (CODE)
      004BDC                       1137 ___str_9:
      004BDC 0D                    1138 	.db 0x0d
      004BDD 0A                    1139 	.db 0x0a
      004BDE 09                    1140 	.db 0x09
      004BDF 09                    1141 	.db 0x09
      004BE0 00                    1142 	.db 0x00
                                   1143 	.area CSEG    (CODE)
                                   1144 	.area CONST   (CODE)
      004BE1                       1145 ___str_10:
      004BE1 0D                    1146 	.db 0x0d
      004BE2 0A                    1147 	.db 0x0a
      004BE3 09                    1148 	.db 0x09
      004BE4 54 6F 74 61 6C 20 43  1149 	.ascii "Total Characters received: %ld"
             68 61 72 61 63 74 65
             72 73 20 72 65 63 65
             69 76 65 64 3A 20 25
             6C 64
      004C02 0D                    1150 	.db 0x0d
      004C03 0A                    1151 	.db 0x0a
      004C04 00                    1152 	.db 0x00
                                   1153 	.area CSEG    (CODE)
                                   1154 	.area CONST   (CODE)
      004C05                       1155 ___str_11:
      004C05 09                    1156 	.db 0x09
      004C06 54 6F 74 61 6C 20 43  1157 	.ascii "Total Characters received since last query: %ld"
             68 61 72 61 63 74 65
             72 73 20 72 65 63 65
             69 76 65 64 20 73 69
             6E 63 65 20 6C 61 73
             74 20 71 75 65 72 79
             3A 20 25 6C 64
      004C35 0D                    1158 	.db 0x0d
      004C36 0A                    1159 	.db 0x0a
      004C37 00                    1160 	.db 0x00
                                   1161 	.area CSEG    (CODE)
                                   1162 	.area XINIT   (CODE)
                                   1163 	.area CABS    (ABS,CODE)
