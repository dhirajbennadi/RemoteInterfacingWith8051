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
                                     16 	.globl _atoi
                                     17 	.globl _CY
                                     18 	.globl _AC
                                     19 	.globl _F0
                                     20 	.globl _RS1
                                     21 	.globl _RS0
                                     22 	.globl _OV
                                     23 	.globl _F1
                                     24 	.globl _P
                                     25 	.globl _PS
                                     26 	.globl _PT1
                                     27 	.globl _PX1
                                     28 	.globl _PT0
                                     29 	.globl _PX0
                                     30 	.globl _RD
                                     31 	.globl _WR
                                     32 	.globl _T1
                                     33 	.globl _T0
                                     34 	.globl _INT1
                                     35 	.globl _INT0
                                     36 	.globl _TXD
                                     37 	.globl _RXD
                                     38 	.globl _P3_7
                                     39 	.globl _P3_6
                                     40 	.globl _P3_5
                                     41 	.globl _P3_4
                                     42 	.globl _P3_3
                                     43 	.globl _P3_2
                                     44 	.globl _P3_1
                                     45 	.globl _P3_0
                                     46 	.globl _EA
                                     47 	.globl _ES
                                     48 	.globl _ET1
                                     49 	.globl _EX1
                                     50 	.globl _ET0
                                     51 	.globl _EX0
                                     52 	.globl _P2_7
                                     53 	.globl _P2_6
                                     54 	.globl _P2_5
                                     55 	.globl _P2_4
                                     56 	.globl _P2_3
                                     57 	.globl _P2_2
                                     58 	.globl _P2_1
                                     59 	.globl _P2_0
                                     60 	.globl _SM0
                                     61 	.globl _SM1
                                     62 	.globl _SM2
                                     63 	.globl _REN
                                     64 	.globl _TB8
                                     65 	.globl _RB8
                                     66 	.globl _TI
                                     67 	.globl _RI
                                     68 	.globl _P1_7
                                     69 	.globl _P1_6
                                     70 	.globl _P1_5
                                     71 	.globl _P1_4
                                     72 	.globl _P1_3
                                     73 	.globl _P1_2
                                     74 	.globl _P1_1
                                     75 	.globl _P1_0
                                     76 	.globl _TF1
                                     77 	.globl _TR1
                                     78 	.globl _TF0
                                     79 	.globl _TR0
                                     80 	.globl _IE1
                                     81 	.globl _IT1
                                     82 	.globl _IE0
                                     83 	.globl _IT0
                                     84 	.globl _P0_7
                                     85 	.globl _P0_6
                                     86 	.globl _P0_5
                                     87 	.globl _P0_4
                                     88 	.globl _P0_3
                                     89 	.globl _P0_2
                                     90 	.globl _P0_1
                                     91 	.globl _P0_0
                                     92 	.globl _P5_7
                                     93 	.globl _P5_6
                                     94 	.globl _P5_5
                                     95 	.globl _P5_4
                                     96 	.globl _P5_3
                                     97 	.globl _P5_2
                                     98 	.globl _P5_1
                                     99 	.globl _P5_0
                                    100 	.globl _P4_7
                                    101 	.globl _P4_6
                                    102 	.globl _P4_5
                                    103 	.globl _P4_4
                                    104 	.globl _P4_3
                                    105 	.globl _P4_2
                                    106 	.globl _P4_1
                                    107 	.globl _P4_0
                                    108 	.globl _PX0L
                                    109 	.globl _PT0L
                                    110 	.globl _PX1L
                                    111 	.globl _PT1L
                                    112 	.globl _PSL
                                    113 	.globl _PT2L
                                    114 	.globl _PPCL
                                    115 	.globl _EC
                                    116 	.globl _CCF0
                                    117 	.globl _CCF1
                                    118 	.globl _CCF2
                                    119 	.globl _CCF3
                                    120 	.globl _CCF4
                                    121 	.globl _CR
                                    122 	.globl _CF
                                    123 	.globl _TF2
                                    124 	.globl _EXF2
                                    125 	.globl _RCLK
                                    126 	.globl _TCLK
                                    127 	.globl _EXEN2
                                    128 	.globl _TR2
                                    129 	.globl _C_T2
                                    130 	.globl _CP_RL2
                                    131 	.globl _T2CON_7
                                    132 	.globl _T2CON_6
                                    133 	.globl _T2CON_5
                                    134 	.globl _T2CON_4
                                    135 	.globl _T2CON_3
                                    136 	.globl _T2CON_2
                                    137 	.globl _T2CON_1
                                    138 	.globl _T2CON_0
                                    139 	.globl _PT2
                                    140 	.globl _ET2
                                    141 	.globl _B
                                    142 	.globl _ACC
                                    143 	.globl _PSW
                                    144 	.globl _IP
                                    145 	.globl _P3
                                    146 	.globl _IE
                                    147 	.globl _P2
                                    148 	.globl _SBUF
                                    149 	.globl _SCON
                                    150 	.globl _P1
                                    151 	.globl _TH1
                                    152 	.globl _TH0
                                    153 	.globl _TL1
                                    154 	.globl _TL0
                                    155 	.globl _TMOD
                                    156 	.globl _TCON
                                    157 	.globl _PCON
                                    158 	.globl _DPH
                                    159 	.globl _DPL
                                    160 	.globl _SP
                                    161 	.globl _P0
                                    162 	.globl _EECON
                                    163 	.globl _KBF
                                    164 	.globl _KBE
                                    165 	.globl _KBLS
                                    166 	.globl _BRL
                                    167 	.globl _BDRCON
                                    168 	.globl _T2MOD
                                    169 	.globl _SPDAT
                                    170 	.globl _SPSTA
                                    171 	.globl _SPCON
                                    172 	.globl _SADEN
                                    173 	.globl _SADDR
                                    174 	.globl _WDTPRG
                                    175 	.globl _WDTRST
                                    176 	.globl _P5
                                    177 	.globl _P4
                                    178 	.globl _IPH1
                                    179 	.globl _IPL1
                                    180 	.globl _IPH0
                                    181 	.globl _IPL0
                                    182 	.globl _IEN1
                                    183 	.globl _IEN0
                                    184 	.globl _CMOD
                                    185 	.globl _CL
                                    186 	.globl _CH
                                    187 	.globl _CCON
                                    188 	.globl _CCAPM4
                                    189 	.globl _CCAPM3
                                    190 	.globl _CCAPM2
                                    191 	.globl _CCAPM1
                                    192 	.globl _CCAPM0
                                    193 	.globl _CCAP4L
                                    194 	.globl _CCAP3L
                                    195 	.globl _CCAP2L
                                    196 	.globl _CCAP1L
                                    197 	.globl _CCAP0L
                                    198 	.globl _CCAP4H
                                    199 	.globl _CCAP3H
                                    200 	.globl _CCAP2H
                                    201 	.globl _CCAP1H
                                    202 	.globl _CCAP0H
                                    203 	.globl _CKCON1
                                    204 	.globl _CKCON0
                                    205 	.globl _CKRL
                                    206 	.globl _AUXR1
                                    207 	.globl _AUXR
                                    208 	.globl _TH2
                                    209 	.globl _TL2
                                    210 	.globl _RCAP2H
                                    211 	.globl _RCAP2L
                                    212 	.globl _T2CON
                                    213 	.globl _total_malloced_data
                                    214 	.globl _buf_number
                                    215 	.globl _uint_to_hexstr_PARM_4
                                    216 	.globl _uint_to_hexstr_PARM_3
                                    217 	.globl _uint_to_hexstr_PARM_2
                                    218 	.globl _hexdump_PARM_2
                                    219 	.globl _uart_init
                                    220 	.globl _echo
                                    221 	.globl _command
                                    222 	.globl _putchar
                                    223 	.globl _getchar
                                    224 	.globl _putstr
                                    225 	.globl _accept_number_from_user
                                    226 	.globl _print_buffers
                                    227 	.globl _hexdump
                                    228 	.globl _uint_to_hexstr
                                    229 ;--------------------------------------------------------
                                    230 ; special function registers
                                    231 ;--------------------------------------------------------
                                    232 	.area RSEG    (ABS,DATA)
      000000                        233 	.org 0x0000
                           0000C8   234 _T2CON	=	0x00c8
                           0000CA   235 _RCAP2L	=	0x00ca
                           0000CB   236 _RCAP2H	=	0x00cb
                           0000CC   237 _TL2	=	0x00cc
                           0000CD   238 _TH2	=	0x00cd
                           00008E   239 _AUXR	=	0x008e
                           0000A2   240 _AUXR1	=	0x00a2
                           000097   241 _CKRL	=	0x0097
                           00008F   242 _CKCON0	=	0x008f
                           0000AF   243 _CKCON1	=	0x00af
                           0000FA   244 _CCAP0H	=	0x00fa
                           0000FB   245 _CCAP1H	=	0x00fb
                           0000FC   246 _CCAP2H	=	0x00fc
                           0000FD   247 _CCAP3H	=	0x00fd
                           0000FE   248 _CCAP4H	=	0x00fe
                           0000EA   249 _CCAP0L	=	0x00ea
                           0000EB   250 _CCAP1L	=	0x00eb
                           0000EC   251 _CCAP2L	=	0x00ec
                           0000ED   252 _CCAP3L	=	0x00ed
                           0000EE   253 _CCAP4L	=	0x00ee
                           0000DA   254 _CCAPM0	=	0x00da
                           0000DB   255 _CCAPM1	=	0x00db
                           0000DC   256 _CCAPM2	=	0x00dc
                           0000DD   257 _CCAPM3	=	0x00dd
                           0000DE   258 _CCAPM4	=	0x00de
                           0000D8   259 _CCON	=	0x00d8
                           0000F9   260 _CH	=	0x00f9
                           0000E9   261 _CL	=	0x00e9
                           0000D9   262 _CMOD	=	0x00d9
                           0000A8   263 _IEN0	=	0x00a8
                           0000B1   264 _IEN1	=	0x00b1
                           0000B8   265 _IPL0	=	0x00b8
                           0000B7   266 _IPH0	=	0x00b7
                           0000B2   267 _IPL1	=	0x00b2
                           0000B3   268 _IPH1	=	0x00b3
                           0000C0   269 _P4	=	0x00c0
                           0000E8   270 _P5	=	0x00e8
                           0000A6   271 _WDTRST	=	0x00a6
                           0000A7   272 _WDTPRG	=	0x00a7
                           0000A9   273 _SADDR	=	0x00a9
                           0000B9   274 _SADEN	=	0x00b9
                           0000C3   275 _SPCON	=	0x00c3
                           0000C4   276 _SPSTA	=	0x00c4
                           0000C5   277 _SPDAT	=	0x00c5
                           0000C9   278 _T2MOD	=	0x00c9
                           00009B   279 _BDRCON	=	0x009b
                           00009A   280 _BRL	=	0x009a
                           00009C   281 _KBLS	=	0x009c
                           00009D   282 _KBE	=	0x009d
                           00009E   283 _KBF	=	0x009e
                           0000D2   284 _EECON	=	0x00d2
                           000080   285 _P0	=	0x0080
                           000081   286 _SP	=	0x0081
                           000082   287 _DPL	=	0x0082
                           000083   288 _DPH	=	0x0083
                           000087   289 _PCON	=	0x0087
                           000088   290 _TCON	=	0x0088
                           000089   291 _TMOD	=	0x0089
                           00008A   292 _TL0	=	0x008a
                           00008B   293 _TL1	=	0x008b
                           00008C   294 _TH0	=	0x008c
                           00008D   295 _TH1	=	0x008d
                           000090   296 _P1	=	0x0090
                           000098   297 _SCON	=	0x0098
                           000099   298 _SBUF	=	0x0099
                           0000A0   299 _P2	=	0x00a0
                           0000A8   300 _IE	=	0x00a8
                           0000B0   301 _P3	=	0x00b0
                           0000B8   302 _IP	=	0x00b8
                           0000D0   303 _PSW	=	0x00d0
                           0000E0   304 _ACC	=	0x00e0
                           0000F0   305 _B	=	0x00f0
                                    306 ;--------------------------------------------------------
                                    307 ; special function bits
                                    308 ;--------------------------------------------------------
                                    309 	.area RSEG    (ABS,DATA)
      000000                        310 	.org 0x0000
                           0000AD   311 _ET2	=	0x00ad
                           0000BD   312 _PT2	=	0x00bd
                           0000C8   313 _T2CON_0	=	0x00c8
                           0000C9   314 _T2CON_1	=	0x00c9
                           0000CA   315 _T2CON_2	=	0x00ca
                           0000CB   316 _T2CON_3	=	0x00cb
                           0000CC   317 _T2CON_4	=	0x00cc
                           0000CD   318 _T2CON_5	=	0x00cd
                           0000CE   319 _T2CON_6	=	0x00ce
                           0000CF   320 _T2CON_7	=	0x00cf
                           0000C8   321 _CP_RL2	=	0x00c8
                           0000C9   322 _C_T2	=	0x00c9
                           0000CA   323 _TR2	=	0x00ca
                           0000CB   324 _EXEN2	=	0x00cb
                           0000CC   325 _TCLK	=	0x00cc
                           0000CD   326 _RCLK	=	0x00cd
                           0000CE   327 _EXF2	=	0x00ce
                           0000CF   328 _TF2	=	0x00cf
                           0000DF   329 _CF	=	0x00df
                           0000DE   330 _CR	=	0x00de
                           0000DC   331 _CCF4	=	0x00dc
                           0000DB   332 _CCF3	=	0x00db
                           0000DA   333 _CCF2	=	0x00da
                           0000D9   334 _CCF1	=	0x00d9
                           0000D8   335 _CCF0	=	0x00d8
                           0000AE   336 _EC	=	0x00ae
                           0000BE   337 _PPCL	=	0x00be
                           0000BD   338 _PT2L	=	0x00bd
                           0000BC   339 _PSL	=	0x00bc
                           0000BB   340 _PT1L	=	0x00bb
                           0000BA   341 _PX1L	=	0x00ba
                           0000B9   342 _PT0L	=	0x00b9
                           0000B8   343 _PX0L	=	0x00b8
                           0000C0   344 _P4_0	=	0x00c0
                           0000C1   345 _P4_1	=	0x00c1
                           0000C2   346 _P4_2	=	0x00c2
                           0000C3   347 _P4_3	=	0x00c3
                           0000C4   348 _P4_4	=	0x00c4
                           0000C5   349 _P4_5	=	0x00c5
                           0000C6   350 _P4_6	=	0x00c6
                           0000C7   351 _P4_7	=	0x00c7
                           0000E8   352 _P5_0	=	0x00e8
                           0000E9   353 _P5_1	=	0x00e9
                           0000EA   354 _P5_2	=	0x00ea
                           0000EB   355 _P5_3	=	0x00eb
                           0000EC   356 _P5_4	=	0x00ec
                           0000ED   357 _P5_5	=	0x00ed
                           0000EE   358 _P5_6	=	0x00ee
                           0000EF   359 _P5_7	=	0x00ef
                           000080   360 _P0_0	=	0x0080
                           000081   361 _P0_1	=	0x0081
                           000082   362 _P0_2	=	0x0082
                           000083   363 _P0_3	=	0x0083
                           000084   364 _P0_4	=	0x0084
                           000085   365 _P0_5	=	0x0085
                           000086   366 _P0_6	=	0x0086
                           000087   367 _P0_7	=	0x0087
                           000088   368 _IT0	=	0x0088
                           000089   369 _IE0	=	0x0089
                           00008A   370 _IT1	=	0x008a
                           00008B   371 _IE1	=	0x008b
                           00008C   372 _TR0	=	0x008c
                           00008D   373 _TF0	=	0x008d
                           00008E   374 _TR1	=	0x008e
                           00008F   375 _TF1	=	0x008f
                           000090   376 _P1_0	=	0x0090
                           000091   377 _P1_1	=	0x0091
                           000092   378 _P1_2	=	0x0092
                           000093   379 _P1_3	=	0x0093
                           000094   380 _P1_4	=	0x0094
                           000095   381 _P1_5	=	0x0095
                           000096   382 _P1_6	=	0x0096
                           000097   383 _P1_7	=	0x0097
                           000098   384 _RI	=	0x0098
                           000099   385 _TI	=	0x0099
                           00009A   386 _RB8	=	0x009a
                           00009B   387 _TB8	=	0x009b
                           00009C   388 _REN	=	0x009c
                           00009D   389 _SM2	=	0x009d
                           00009E   390 _SM1	=	0x009e
                           00009F   391 _SM0	=	0x009f
                           0000A0   392 _P2_0	=	0x00a0
                           0000A1   393 _P2_1	=	0x00a1
                           0000A2   394 _P2_2	=	0x00a2
                           0000A3   395 _P2_3	=	0x00a3
                           0000A4   396 _P2_4	=	0x00a4
                           0000A5   397 _P2_5	=	0x00a5
                           0000A6   398 _P2_6	=	0x00a6
                           0000A7   399 _P2_7	=	0x00a7
                           0000A8   400 _EX0	=	0x00a8
                           0000A9   401 _ET0	=	0x00a9
                           0000AA   402 _EX1	=	0x00aa
                           0000AB   403 _ET1	=	0x00ab
                           0000AC   404 _ES	=	0x00ac
                           0000AF   405 _EA	=	0x00af
                           0000B0   406 _P3_0	=	0x00b0
                           0000B1   407 _P3_1	=	0x00b1
                           0000B2   408 _P3_2	=	0x00b2
                           0000B3   409 _P3_3	=	0x00b3
                           0000B4   410 _P3_4	=	0x00b4
                           0000B5   411 _P3_5	=	0x00b5
                           0000B6   412 _P3_6	=	0x00b6
                           0000B7   413 _P3_7	=	0x00b7
                           0000B0   414 _RXD	=	0x00b0
                           0000B1   415 _TXD	=	0x00b1
                           0000B2   416 _INT0	=	0x00b2
                           0000B3   417 _INT1	=	0x00b3
                           0000B4   418 _T0	=	0x00b4
                           0000B5   419 _T1	=	0x00b5
                           0000B6   420 _WR	=	0x00b6
                           0000B7   421 _RD	=	0x00b7
                           0000B8   422 _PX0	=	0x00b8
                           0000B9   423 _PT0	=	0x00b9
                           0000BA   424 _PX1	=	0x00ba
                           0000BB   425 _PT1	=	0x00bb
                           0000BC   426 _PS	=	0x00bc
                           0000D0   427 _P	=	0x00d0
                           0000D1   428 _F1	=	0x00d1
                           0000D2   429 _OV	=	0x00d2
                           0000D3   430 _RS0	=	0x00d3
                           0000D4   431 _RS1	=	0x00d4
                           0000D5   432 _F0	=	0x00d5
                           0000D6   433 _AC	=	0x00d6
                           0000D7   434 _CY	=	0x00d7
                                    435 ;--------------------------------------------------------
                                    436 ; overlayable register banks
                                    437 ;--------------------------------------------------------
                                    438 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        439 	.ds 8
                                    440 ;--------------------------------------------------------
                                    441 ; internal ram data
                                    442 ;--------------------------------------------------------
                                    443 	.area DSEG    (DATA)
      000008                        444 _print_buffers_sloc0_1_0:
      000008                        445 	.ds 3
      00000B                        446 _hexdump_sloc0_1_0:
      00000B                        447 	.ds 2
      00000D                        448 _hexdump_sloc1_1_0:
      00000D                        449 	.ds 2
      00000F                        450 _uint_to_hexstr_sloc0_1_0:
      00000F                        451 	.ds 4
      000013                        452 _uint_to_hexstr_sloc1_1_0:
      000013                        453 	.ds 2
      000015                        454 _uint_to_hexstr_sloc2_1_0:
      000015                        455 	.ds 3
      000018                        456 _uint_to_hexstr_sloc3_1_0:
      000018                        457 	.ds 2
                                    458 ;--------------------------------------------------------
                                    459 ; overlayable items in internal ram 
                                    460 ;--------------------------------------------------------
                                    461 ;--------------------------------------------------------
                                    462 ; indirectly addressable internal ram data
                                    463 ;--------------------------------------------------------
                                    464 	.area ISEG    (DATA)
                                    465 ;--------------------------------------------------------
                                    466 ; absolute internal ram data
                                    467 ;--------------------------------------------------------
                                    468 	.area IABS    (ABS,DATA)
                                    469 	.area IABS    (ABS,DATA)
                                    470 ;--------------------------------------------------------
                                    471 ; bit data
                                    472 ;--------------------------------------------------------
                                    473 	.area BSEG    (BIT)
                                    474 ;--------------------------------------------------------
                                    475 ; paged external ram data
                                    476 ;--------------------------------------------------------
                                    477 	.area PSEG    (PAG,XDATA)
                                    478 ;--------------------------------------------------------
                                    479 ; external ram data
                                    480 ;--------------------------------------------------------
                                    481 	.area XSEG    (XDATA)
      00138F                        482 _echo_c_65536_74:
      00138F                        483 	.ds 1
      001390                        484 _command_received_char_65536_77:
      001390                        485 	.ds 1
      001391                        486 _putchar_c_65536_80:
      001391                        487 	.ds 2
      001393                        488 _putstr_str_65536_83:
      001393                        489 	.ds 3
      001396                        490 _accept_number_from_user_received_char_65536_86:
      001396                        491 	.ds 1
      001397                        492 _accept_number_from_user_number_in_char_65536_86:
      001397                        493 	.ds 25
      0013B0                        494 _accept_number_from_user_valid_number_status_65536_86:
      0013B0                        495 	.ds 1
      0013B1                        496 _accept_number_from_user_number_65536_86:
      0013B1                        497 	.ds 2
      0013B3                        498 _accept_number_from_user_i_65536_86:
      0013B3                        499 	.ds 2
      0013B5                        500 _print_buffers_buffers_65536_91:
      0013B5                        501 	.ds 3
      0013B8                        502 _hexdump_PARM_2:
      0013B8                        503 	.ds 4
      0013BC                        504 _hexdump_loc_65536_95:
      0013BC                        505 	.ds 3
      0013BF                        506 _hexdump_hex_byte_65536_96:
      0013BF                        507 	.ds 5
      0013C4                        508 _hexdump_address_bytes_65536_96:
      0013C4                        509 	.ds 7
      0013CB                        510 _uint_to_hexstr_PARM_2:
      0013CB                        511 	.ds 4
      0013CF                        512 _uint_to_hexstr_PARM_3:
      0013CF                        513 	.ds 2
      0013D1                        514 _uint_to_hexstr_PARM_4:
      0013D1                        515 	.ds 1
      0013D2                        516 _uint_to_hexstr_str_65536_103:
      0013D2                        517 	.ds 3
                                    518 ;--------------------------------------------------------
                                    519 ; absolute external ram data
                                    520 ;--------------------------------------------------------
                                    521 	.area XABS    (ABS,XDATA)
                                    522 ;--------------------------------------------------------
                                    523 ; external initialized ram data
                                    524 ;--------------------------------------------------------
                                    525 	.area XISEG   (XDATA)
      00143D                        526 _buf_number::
      00143D                        527 	.ds 2
      00143F                        528 _total_malloced_data::
      00143F                        529 	.ds 2
                                    530 	.area HOME    (CODE)
                                    531 	.area GSINIT0 (CODE)
                                    532 	.area GSINIT1 (CODE)
                                    533 	.area GSINIT2 (CODE)
                                    534 	.area GSINIT3 (CODE)
                                    535 	.area GSINIT4 (CODE)
                                    536 	.area GSINIT5 (CODE)
                                    537 	.area GSINIT  (CODE)
                                    538 	.area GSFINAL (CODE)
                                    539 	.area CSEG    (CODE)
                                    540 ;--------------------------------------------------------
                                    541 ; global & static initialisations
                                    542 ;--------------------------------------------------------
                                    543 	.area HOME    (CODE)
                                    544 	.area GSINIT  (CODE)
                                    545 	.area GSFINAL (CODE)
                                    546 	.area GSINIT  (CODE)
                                    547 ;--------------------------------------------------------
                                    548 ; Home
                                    549 ;--------------------------------------------------------
                                    550 	.area HOME    (CODE)
                                    551 	.area HOME    (CODE)
                                    552 ;--------------------------------------------------------
                                    553 ; code
                                    554 ;--------------------------------------------------------
                                    555 	.area CSEG    (CODE)
                                    556 ;------------------------------------------------------------
                                    557 ;Allocation info for local variables in function 'uart_init'
                                    558 ;------------------------------------------------------------
                                    559 ;	uart.c:48: void uart_init()
                                    560 ;	-----------------------------------------
                                    561 ;	 function uart_init
                                    562 ;	-----------------------------------------
      002108                        563 _uart_init:
                           000007   564 	ar7 = 0x07
                           000006   565 	ar6 = 0x06
                           000005   566 	ar5 = 0x05
                           000004   567 	ar4 = 0x04
                           000003   568 	ar3 = 0x03
                           000002   569 	ar2 = 0x02
                           000001   570 	ar1 = 0x01
                           000000   571 	ar0 = 0x00
                                    572 ;	uart.c:50: SCON = 0x50; // setting up serial configuration 8bit uart, Receive enabled
      002108 75 98 50         [24]  573 	mov	_SCON,#0x50
                                    574 ;	uart.c:51: TMOD = 0x20; // timer1 in mode2, auto-reload
      00210B 75 89 20         [24]  575 	mov	_TMOD,#0x20
                                    576 ;	uart.c:56: TI = 1;
                                    577 ;	assignBit
      00210E D2 99            [12]  578 	setb	_TI
                                    579 ;	uart.c:57: P1_1 = false;
                                    580 ;	assignBit
      002110 C2 91            [12]  581 	clr	_P1_1
                                    582 ;	uart.c:58: }
      002112 22               [24]  583 	ret
                                    584 ;------------------------------------------------------------
                                    585 ;Allocation info for local variables in function 'echo'
                                    586 ;------------------------------------------------------------
                                    587 ;c                         Allocated with name '_echo_c_65536_74'
                                    588 ;------------------------------------------------------------
                                    589 ;	uart.c:64: void echo(char c)
                                    590 ;	-----------------------------------------
                                    591 ;	 function echo
                                    592 ;	-----------------------------------------
      002113                        593 _echo:
      002113 E5 82            [12]  594 	mov	a,dpl
      002115 90 13 8F         [24]  595 	mov	dptr,#_echo_c_65536_74
      002118 F0               [24]  596 	movx	@dptr,a
                                    597 ;	uart.c:68: switch ((int8_t)c)
      002119 E0               [24]  598 	movx	a,@dptr
      00211A FF               [12]  599 	mov	r7,a
      00211B FE               [12]  600 	mov	r6,a
      00211C BE FF 01         [24]  601 	cjne	r6,#0xff,00120$
      00211F 22               [24]  602 	ret
      002120                        603 00120$:
      002120 BE 08 02         [24]  604 	cjne	r6,#0x08,00121$
      002123 80 05            [24]  605 	sjmp	00102$
      002125                        606 00121$:
                                    607 ;	uart.c:73: case BACKSPACE: // user presses backspace
      002125 BE 0D 20         [24]  608 	cjne	r6,#0x0d,00104$
      002128 80 12            [24]  609 	sjmp	00103$
      00212A                        610 00102$:
                                    611 ;	uart.c:74: putchar(BACKSPACE);
      00212A 90 00 08         [24]  612 	mov	dptr,#0x0008
      00212D 12 21 F9         [24]  613 	lcall	_putchar
                                    614 ;	uart.c:75: putchar(' ');
      002130 90 00 20         [24]  615 	mov	dptr,#0x0020
      002133 12 21 F9         [24]  616 	lcall	_putchar
                                    617 ;	uart.c:76: putchar(BACKSPACE);
      002136 90 00 08         [24]  618 	mov	dptr,#0x0008
                                    619 ;	uart.c:77: break;
                                    620 ;	uart.c:79: case '\r': // user presses enter
      002139 02 21 F9         [24]  621 	ljmp	_putchar
      00213C                        622 00103$:
                                    623 ;	uart.c:80: putchar('\r');
      00213C 90 00 0D         [24]  624 	mov	dptr,#0x000d
      00213F 12 21 F9         [24]  625 	lcall	_putchar
                                    626 ;	uart.c:81: putchar('\n');
      002142 90 00 0A         [24]  627 	mov	dptr,#0x000a
                                    628 ;	uart.c:82: break;
                                    629 ;	uart.c:84: default:
      002145 02 21 F9         [24]  630 	ljmp	_putchar
      002148                        631 00104$:
                                    632 ;	uart.c:85: putchar(c); // echoing received chars
      002148 7E 00            [12]  633 	mov	r6,#0x00
      00214A 8F 82            [24]  634 	mov	dpl,r7
      00214C 8E 83            [24]  635 	mov	dph,r6
                                    636 ;	uart.c:87: }
                                    637 ;	uart.c:88: }
      00214E 02 21 F9         [24]  638 	ljmp	_putchar
                                    639 ;------------------------------------------------------------
                                    640 ;Allocation info for local variables in function 'command'
                                    641 ;------------------------------------------------------------
                                    642 ;received_char             Allocated with name '_command_received_char_65536_77'
                                    643 ;------------------------------------------------------------
                                    644 ;	uart.c:94: void command(char received_char)
                                    645 ;	-----------------------------------------
                                    646 ;	 function command
                                    647 ;	-----------------------------------------
      002151                        648 _command:
      002151 E5 82            [12]  649 	mov	a,dpl
      002153 90 13 90         [24]  650 	mov	dptr,#_command_received_char_65536_77
      002156 F0               [24]  651 	movx	@dptr,a
                                    652 ;	uart.c:97: switch (received_char)
      002157 E0               [24]  653 	movx	a,@dptr
      002158 FF               [12]  654 	mov	r7,a
      002159 BF 31 02         [24]  655 	cjne	r7,#0x31,00135$
      00215C 80 19            [24]  656 	sjmp	00101$
      00215E                        657 00135$:
      00215E BF 32 02         [24]  658 	cjne	r7,#0x32,00136$
      002161 80 21            [24]  659 	sjmp	00102$
      002163                        660 00136$:
      002163 BF 33 02         [24]  661 	cjne	r7,#0x33,00137$
      002166 80 2C            [24]  662 	sjmp	00103$
      002168                        663 00137$:
      002168 BF 34 02         [24]  664 	cjne	r7,#0x34,00138$
      00216B 80 35            [24]  665 	sjmp	00104$
      00216D                        666 00138$:
      00216D BF 35 02         [24]  667 	cjne	r7,#0x35,00139$
      002170 80 3E            [24]  668 	sjmp	00105$
      002172                        669 00139$:
                                    670 ;	uart.c:101: case '1':
      002172 BF 36 57         [24]  671 	cjne	r7,#0x36,00107$
      002175 80 47            [24]  672 	sjmp	00106$
      002177                        673 00101$:
                                    674 ;	uart.c:102: putstr("\r\n\t\t ** Turning PWM on ** \r\n");
      002177 90 3C 08         [24]  675 	mov	dptr,#___str_0
      00217A 75 F0 80         [24]  676 	mov	b,#0x80
      00217D 12 22 2A         [24]  677 	lcall	_putstr
                                    678 ;	uart.c:103: CR = 1;
                                    679 ;	assignBit
      002180 D2 DE            [12]  680 	setb	_CR
                                    681 ;	uart.c:104: break;
                                    682 ;	uart.c:106: case '2':
      002182 80 63            [24]  683 	sjmp	00108$
      002184                        684 00102$:
                                    685 ;	uart.c:107: putstr("\r\n\t\t ** Turning PWM off ** \r\n");
      002184 90 3C 25         [24]  686 	mov	dptr,#___str_1
      002187 75 F0 80         [24]  687 	mov	b,#0x80
      00218A 12 22 2A         [24]  688 	lcall	_putstr
                                    689 ;	uart.c:108: CR = 0;
                                    690 ;	assignBit
      00218D C2 DE            [12]  691 	clr	_CR
                                    692 ;	uart.c:109: uart_init();
      00218F 12 21 08         [24]  693 	lcall	_uart_init
                                    694 ;	uart.c:110: break;
                                    695 ;	uart.c:112: case '3':
      002192 80 53            [24]  696 	sjmp	00108$
      002194                        697 00103$:
                                    698 ;	uart.c:113: putstr("\r\n\t\t ** Setting up minimum frequency ** \r\n");
      002194 90 3C 43         [24]  699 	mov	dptr,#___str_2
      002197 75 F0 80         [24]  700 	mov	b,#0x80
      00219A 12 22 2A         [24]  701 	lcall	_putstr
                                    702 ;	uart.c:114: CKRL = 0;   //0 for minimum frequency
      00219D 75 97 00         [24]  703 	mov	_CKRL,#0x00
                                    704 ;	uart.c:115: break;
                                    705 ;	uart.c:117: case '4':
      0021A0 80 45            [24]  706 	sjmp	00108$
      0021A2                        707 00104$:
                                    708 ;	uart.c:118: putstr("\r\n\t\t ** Setting up maximum frequency ** \r\n");
      0021A2 90 3C 6E         [24]  709 	mov	dptr,#___str_3
      0021A5 75 F0 80         [24]  710 	mov	b,#0x80
      0021A8 12 22 2A         [24]  711 	lcall	_putstr
                                    712 ;	uart.c:119: CKRL = 0xFF;   //0xFF for maximum frequency
      0021AB 75 97 FF         [24]  713 	mov	_CKRL,#0xff
                                    714 ;	uart.c:120: break;
                                    715 ;	uart.c:122: case '5':
      0021AE 80 37            [24]  716 	sjmp	00108$
      0021B0                        717 00105$:
                                    718 ;	uart.c:123: putstr("\r\n\t\t ** Entering IDLE mode ** \r\n");
      0021B0 90 3C 99         [24]  719 	mov	dptr,#___str_4
      0021B3 75 F0 80         [24]  720 	mov	b,#0x80
      0021B6 12 22 2A         [24]  721 	lcall	_putstr
                                    722 ;	uart.c:124: PCON |= 0x01;   //Setting up IDLE bit in PCON
      0021B9 43 87 01         [24]  723 	orl	_PCON,#0x01
                                    724 ;	uart.c:125: break;
                                    725 ;	uart.c:127: case '6':
      0021BC 80 29            [24]  726 	sjmp	00108$
      0021BE                        727 00106$:
                                    728 ;	uart.c:128: putstr("\r\n\t\t ** Entering Power-down mode ** \r\n");
      0021BE 90 3C BA         [24]  729 	mov	dptr,#___str_5
      0021C1 75 F0 80         [24]  730 	mov	b,#0x80
      0021C4 12 22 2A         [24]  731 	lcall	_putstr
                                    732 ;	uart.c:129: PCON |= 0x02;   //setting up PDL bit in PCON
      0021C7 43 87 02         [24]  733 	orl	_PCON,#0x02
                                    734 ;	uart.c:130: break;
                                    735 ;	uart.c:133: default:
      0021CA 80 1B            [24]  736 	sjmp	00108$
      0021CC                        737 00107$:
                                    738 ;	uart.c:134: printf("\r\n\r\n\t Error: Received invalid command '%c'\r\n", received_char);
      0021CC 7E 00            [12]  739 	mov	r6,#0x00
      0021CE C0 07            [24]  740 	push	ar7
      0021D0 C0 06            [24]  741 	push	ar6
      0021D2 74 E1            [12]  742 	mov	a,#___str_6
      0021D4 C0 E0            [24]  743 	push	acc
      0021D6 74 3C            [12]  744 	mov	a,#(___str_6 >> 8)
      0021D8 C0 E0            [24]  745 	push	acc
      0021DA 74 80            [12]  746 	mov	a,#0x80
      0021DC C0 E0            [24]  747 	push	acc
      0021DE 12 30 C5         [24]  748 	lcall	_printf
      0021E1 E5 81            [12]  749 	mov	a,sp
      0021E3 24 FB            [12]  750 	add	a,#0xfb
      0021E5 F5 81            [12]  751 	mov	sp,a
                                    752 ;	uart.c:138: }
      0021E7                        753 00108$:
                                    754 ;	uart.c:140: putstr("\r\n----------------------------------------------------------------------\r\n\r\n");
      0021E7 90 3D 0E         [24]  755 	mov	dptr,#___str_7
      0021EA 75 F0 80         [24]  756 	mov	b,#0x80
      0021ED 12 22 2A         [24]  757 	lcall	_putstr
                                    758 ;	uart.c:141: putstr("Enter command: ");
      0021F0 90 3D 5B         [24]  759 	mov	dptr,#___str_8
      0021F3 75 F0 80         [24]  760 	mov	b,#0x80
                                    761 ;	uart.c:143: }
      0021F6 02 22 2A         [24]  762 	ljmp	_putstr
                                    763 ;------------------------------------------------------------
                                    764 ;Allocation info for local variables in function 'putchar'
                                    765 ;------------------------------------------------------------
                                    766 ;c                         Allocated with name '_putchar_c_65536_80'
                                    767 ;------------------------------------------------------------
                                    768 ;	uart.c:148: int putchar(int c)
                                    769 ;	-----------------------------------------
                                    770 ;	 function putchar
                                    771 ;	-----------------------------------------
      0021F9                        772 _putchar:
      0021F9 AF 83            [24]  773 	mov	r7,dph
      0021FB E5 82            [12]  774 	mov	a,dpl
      0021FD 90 13 91         [24]  775 	mov	dptr,#_putchar_c_65536_80
      002200 F0               [24]  776 	movx	@dptr,a
      002201 EF               [12]  777 	mov	a,r7
      002202 A3               [24]  778 	inc	dptr
      002203 F0               [24]  779 	movx	@dptr,a
                                    780 ;	uart.c:150: while (!TI)
      002204                        781 00101$:
                                    782 ;	uart.c:152: TI = 0;
                                    783 ;	assignBit
      002204 10 99 02         [24]  784 	jbc	_TI,00114$
      002207 80 FB            [24]  785 	sjmp	00101$
      002209                        786 00114$:
                                    787 ;	uart.c:153: SBUF = c; // adding character to Serial buffer
      002209 90 13 91         [24]  788 	mov	dptr,#_putchar_c_65536_80
      00220C E0               [24]  789 	movx	a,@dptr
      00220D FE               [12]  790 	mov	r6,a
      00220E A3               [24]  791 	inc	dptr
      00220F E0               [24]  792 	movx	a,@dptr
      002210 FF               [12]  793 	mov	r7,a
      002211 8E 99            [24]  794 	mov	_SBUF,r6
                                    795 ;	uart.c:154: return c;
      002213 8E 82            [24]  796 	mov	dpl,r6
      002215 8F 83            [24]  797 	mov	dph,r7
                                    798 ;	uart.c:155: }
      002217 22               [24]  799 	ret
                                    800 ;------------------------------------------------------------
                                    801 ;Allocation info for local variables in function 'getchar'
                                    802 ;------------------------------------------------------------
                                    803 ;	uart.c:164: int getchar() // Function to receive serial data
                                    804 ;	-----------------------------------------
                                    805 ;	 function getchar
                                    806 ;	-----------------------------------------
      002218                        807 _getchar:
                                    808 ;	uart.c:166: P1_1 = false;
                                    809 ;	assignBit
      002218 C2 91            [12]  810 	clr	_P1_1
                                    811 ;	uart.c:167: while (!RI)
      00221A                        812 00101$:
                                    813 ;	uart.c:170: RI = 0;
                                    814 ;	assignBit
      00221A 10 98 02         [24]  815 	jbc	_RI,00114$
      00221D 80 FB            [24]  816 	sjmp	00101$
      00221F                        817 00114$:
                                    818 ;	uart.c:172: P1_1 = true;
                                    819 ;	assignBit
      00221F D2 91            [12]  820 	setb	_P1_1
                                    821 ;	uart.c:173: return SBUF;
      002221 AE 99            [24]  822 	mov	r6,_SBUF
      002223 7F 00            [12]  823 	mov	r7,#0x00
      002225 8E 82            [24]  824 	mov	dpl,r6
      002227 8F 83            [24]  825 	mov	dph,r7
                                    826 ;	uart.c:174: }
      002229 22               [24]  827 	ret
                                    828 ;------------------------------------------------------------
                                    829 ;Allocation info for local variables in function 'putstr'
                                    830 ;------------------------------------------------------------
                                    831 ;str                       Allocated with name '_putstr_str_65536_83'
                                    832 ;index                     Allocated with name '_putstr_index_65536_84'
                                    833 ;------------------------------------------------------------
                                    834 ;	uart.c:180: int putstr(char *str)
                                    835 ;	-----------------------------------------
                                    836 ;	 function putstr
                                    837 ;	-----------------------------------------
      00222A                        838 _putstr:
      00222A AF F0            [24]  839 	mov	r7,b
      00222C AE 83            [24]  840 	mov	r6,dph
      00222E E5 82            [12]  841 	mov	a,dpl
      002230 90 13 93         [24]  842 	mov	dptr,#_putstr_str_65536_83
      002233 F0               [24]  843 	movx	@dptr,a
      002234 EE               [12]  844 	mov	a,r6
      002235 A3               [24]  845 	inc	dptr
      002236 F0               [24]  846 	movx	@dptr,a
      002237 EF               [12]  847 	mov	a,r7
      002238 A3               [24]  848 	inc	dptr
      002239 F0               [24]  849 	movx	@dptr,a
                                    850 ;	uart.c:183: while (*str)
      00223A 90 13 93         [24]  851 	mov	dptr,#_putstr_str_65536_83
      00223D E0               [24]  852 	movx	a,@dptr
      00223E FD               [12]  853 	mov	r5,a
      00223F A3               [24]  854 	inc	dptr
      002240 E0               [24]  855 	movx	a,@dptr
      002241 FE               [12]  856 	mov	r6,a
      002242 A3               [24]  857 	inc	dptr
      002243 E0               [24]  858 	movx	a,@dptr
      002244 FF               [12]  859 	mov	r7,a
      002245 7B 00            [12]  860 	mov	r3,#0x00
      002247 7C 00            [12]  861 	mov	r4,#0x00
      002249                        862 00101$:
      002249 8D 82            [24]  863 	mov	dpl,r5
      00224B 8E 83            [24]  864 	mov	dph,r6
      00224D 8F F0            [24]  865 	mov	b,r7
      00224F 12 3A E7         [24]  866 	lcall	__gptrget
      002252 FA               [12]  867 	mov	r2,a
      002253 60 36            [24]  868 	jz	00108$
                                    869 ;	uart.c:185: putchar(*str++);
      002255 0D               [12]  870 	inc	r5
      002256 BD 00 01         [24]  871 	cjne	r5,#0x00,00116$
      002259 0E               [12]  872 	inc	r6
      00225A                        873 00116$:
      00225A 90 13 93         [24]  874 	mov	dptr,#_putstr_str_65536_83
      00225D ED               [12]  875 	mov	a,r5
      00225E F0               [24]  876 	movx	@dptr,a
      00225F EE               [12]  877 	mov	a,r6
      002260 A3               [24]  878 	inc	dptr
      002261 F0               [24]  879 	movx	@dptr,a
      002262 EF               [12]  880 	mov	a,r7
      002263 A3               [24]  881 	inc	dptr
      002264 F0               [24]  882 	movx	@dptr,a
      002265 8A 01            [24]  883 	mov	ar1,r2
      002267 7A 00            [12]  884 	mov	r2,#0x00
      002269 89 82            [24]  885 	mov	dpl,r1
      00226B 8A 83            [24]  886 	mov	dph,r2
      00226D C0 07            [24]  887 	push	ar7
      00226F C0 06            [24]  888 	push	ar6
      002271 C0 05            [24]  889 	push	ar5
      002273 C0 04            [24]  890 	push	ar4
      002275 C0 03            [24]  891 	push	ar3
      002277 12 21 F9         [24]  892 	lcall	_putchar
      00227A D0 03            [24]  893 	pop	ar3
      00227C D0 04            [24]  894 	pop	ar4
      00227E D0 05            [24]  895 	pop	ar5
      002280 D0 06            [24]  896 	pop	ar6
      002282 D0 07            [24]  897 	pop	ar7
                                    898 ;	uart.c:186: index++;
      002284 0B               [12]  899 	inc	r3
      002285 BB 00 C1         [24]  900 	cjne	r3,#0x00,00101$
      002288 0C               [12]  901 	inc	r4
      002289 80 BE            [24]  902 	sjmp	00101$
      00228B                        903 00108$:
      00228B 90 13 93         [24]  904 	mov	dptr,#_putstr_str_65536_83
      00228E ED               [12]  905 	mov	a,r5
      00228F F0               [24]  906 	movx	@dptr,a
      002290 EE               [12]  907 	mov	a,r6
      002291 A3               [24]  908 	inc	dptr
      002292 F0               [24]  909 	movx	@dptr,a
      002293 EF               [12]  910 	mov	a,r7
      002294 A3               [24]  911 	inc	dptr
      002295 F0               [24]  912 	movx	@dptr,a
                                    913 ;	uart.c:188: return index + 1;
      002296 0B               [12]  914 	inc	r3
      002297 BB 00 01         [24]  915 	cjne	r3,#0x00,00118$
      00229A 0C               [12]  916 	inc	r4
      00229B                        917 00118$:
      00229B 8B 82            [24]  918 	mov	dpl,r3
      00229D 8C 83            [24]  919 	mov	dph,r4
                                    920 ;	uart.c:189: }
      00229F 22               [24]  921 	ret
                                    922 ;------------------------------------------------------------
                                    923 ;Allocation info for local variables in function 'accept_number_from_user'
                                    924 ;------------------------------------------------------------
                                    925 ;received_char             Allocated with name '_accept_number_from_user_received_char_65536_86'
                                    926 ;number_in_char            Allocated with name '_accept_number_from_user_number_in_char_65536_86'
                                    927 ;valid_number_status       Allocated with name '_accept_number_from_user_valid_number_status_65536_86'
                                    928 ;number                    Allocated with name '_accept_number_from_user_number_65536_86'
                                    929 ;i                         Allocated with name '_accept_number_from_user_i_65536_86'
                                    930 ;------------------------------------------------------------
                                    931 ;	uart.c:195: int accept_number_from_user()
                                    932 ;	-----------------------------------------
                                    933 ;	 function accept_number_from_user
                                    934 ;	-----------------------------------------
      0022A0                        935 _accept_number_from_user:
                                    936 ;	uart.c:197: char received_char = '`';
      0022A0 90 13 96         [24]  937 	mov	dptr,#_accept_number_from_user_received_char_65536_86
      0022A3 74 60            [12]  938 	mov	a,#0x60
      0022A5 F0               [24]  939 	movx	@dptr,a
                                    940 ;	uart.c:198: char number_in_char[25] = "\0";
      0022A6 90 13 97         [24]  941 	mov	dptr,#_accept_number_from_user_number_in_char_65536_86
      0022A9 E4               [12]  942 	clr	a
      0022AA F0               [24]  943 	movx	@dptr,a
      0022AB 90 13 98         [24]  944 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0001)
      0022AE F0               [24]  945 	movx	@dptr,a
      0022AF 90 13 99         [24]  946 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0002)
      0022B2 F0               [24]  947 	movx	@dptr,a
      0022B3 90 13 9A         [24]  948 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0003)
      0022B6 F0               [24]  949 	movx	@dptr,a
      0022B7 90 13 9B         [24]  950 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0004)
      0022BA F0               [24]  951 	movx	@dptr,a
      0022BB 90 13 9C         [24]  952 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0005)
      0022BE F0               [24]  953 	movx	@dptr,a
      0022BF 90 13 9D         [24]  954 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0006)
      0022C2 F0               [24]  955 	movx	@dptr,a
      0022C3 90 13 9E         [24]  956 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0007)
      0022C6 F0               [24]  957 	movx	@dptr,a
      0022C7 90 13 9F         [24]  958 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0008)
      0022CA F0               [24]  959 	movx	@dptr,a
      0022CB 90 13 A0         [24]  960 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0009)
      0022CE F0               [24]  961 	movx	@dptr,a
      0022CF 90 13 A1         [24]  962 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x000a)
      0022D2 F0               [24]  963 	movx	@dptr,a
      0022D3 90 13 A2         [24]  964 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x000b)
      0022D6 F0               [24]  965 	movx	@dptr,a
      0022D7 90 13 A3         [24]  966 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x000c)
      0022DA F0               [24]  967 	movx	@dptr,a
      0022DB 90 13 A4         [24]  968 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x000d)
      0022DE F0               [24]  969 	movx	@dptr,a
      0022DF 90 13 A5         [24]  970 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x000e)
      0022E2 F0               [24]  971 	movx	@dptr,a
      0022E3 90 13 A6         [24]  972 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x000f)
      0022E6 F0               [24]  973 	movx	@dptr,a
      0022E7 90 13 A7         [24]  974 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0010)
      0022EA F0               [24]  975 	movx	@dptr,a
      0022EB 90 13 A8         [24]  976 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0011)
      0022EE F0               [24]  977 	movx	@dptr,a
      0022EF 90 13 A9         [24]  978 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0012)
      0022F2 F0               [24]  979 	movx	@dptr,a
      0022F3 90 13 AA         [24]  980 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0013)
      0022F6 F0               [24]  981 	movx	@dptr,a
      0022F7 90 13 AB         [24]  982 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0014)
      0022FA F0               [24]  983 	movx	@dptr,a
      0022FB 90 13 AC         [24]  984 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0015)
      0022FE F0               [24]  985 	movx	@dptr,a
      0022FF 90 13 AD         [24]  986 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0016)
      002302 F0               [24]  987 	movx	@dptr,a
      002303 90 13 AE         [24]  988 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0017)
      002306 F0               [24]  989 	movx	@dptr,a
      002307 90 13 AF         [24]  990 	mov	dptr,#(_accept_number_from_user_number_in_char_65536_86 + 0x0018)
      00230A F0               [24]  991 	movx	@dptr,a
                                    992 ;	uart.c:199: bool valid_number_status = false;
      00230B 90 13 B0         [24]  993 	mov	dptr,#_accept_number_from_user_valid_number_status_65536_86
      00230E F0               [24]  994 	movx	@dptr,a
                                    995 ;	uart.c:200: int number = 0;
      00230F 90 13 B1         [24]  996 	mov	dptr,#_accept_number_from_user_number_65536_86
      002312 F0               [24]  997 	movx	@dptr,a
      002313 A3               [24]  998 	inc	dptr
      002314 F0               [24]  999 	movx	@dptr,a
                                   1000 ;	uart.c:201: int i = 0;
      002315 90 13 B3         [24] 1001 	mov	dptr,#_accept_number_from_user_i_65536_86
      002318 F0               [24] 1002 	movx	@dptr,a
      002319 A3               [24] 1003 	inc	dptr
      00231A F0               [24] 1004 	movx	@dptr,a
                                   1005 ;	uart.c:202: while (valid_number_status == false)
      00231B                       1006 00110$:
      00231B 90 13 B0         [24] 1007 	mov	dptr,#_accept_number_from_user_valid_number_status_65536_86
      00231E E0               [24] 1008 	movx	a,@dptr
      00231F 60 03            [24] 1009 	jz	00139$
      002321 02 24 1E         [24] 1010 	ljmp	00112$
      002324                       1011 00139$:
                                   1012 ;	uart.c:204: received_char = getchar();
      002324 12 22 18         [24] 1013 	lcall	_getchar
      002327 AE 82            [24] 1014 	mov	r6,dpl
      002329 90 13 96         [24] 1015 	mov	dptr,#_accept_number_from_user_received_char_65536_86
      00232C EE               [12] 1016 	mov	a,r6
      00232D F0               [24] 1017 	movx	@dptr,a
                                   1018 ;	uart.c:205: i++;
      00232E 90 13 B3         [24] 1019 	mov	dptr,#_accept_number_from_user_i_65536_86
      002331 E0               [24] 1020 	movx	a,@dptr
      002332 24 01            [12] 1021 	add	a,#0x01
      002334 F0               [24] 1022 	movx	@dptr,a
      002335 A3               [24] 1023 	inc	dptr
      002336 E0               [24] 1024 	movx	a,@dptr
      002337 34 00            [12] 1025 	addc	a,#0x00
      002339 F0               [24] 1026 	movx	@dptr,a
                                   1027 ;	uart.c:206: echo(received_char);
      00233A 8E 82            [24] 1028 	mov	dpl,r6
      00233C 12 21 13         [24] 1029 	lcall	_echo
                                   1030 ;	uart.c:208: if (!(received_char >= '0' && received_char <= '9') && (received_char != '\r'))
      00233F 90 13 96         [24] 1031 	mov	dptr,#_accept_number_from_user_received_char_65536_86
      002342 E0               [24] 1032 	movx	a,@dptr
      002343 FF               [12] 1033 	mov	r7,a
      002344 BF 30 00         [24] 1034 	cjne	r7,#0x30,00140$
      002347                       1035 00140$:
      002347 40 05            [24] 1036 	jc	00107$
      002349 EF               [12] 1037 	mov	a,r7
      00234A 24 C6            [12] 1038 	add	a,#0xff - 0x39
      00234C 50 33            [24] 1039 	jnc	00104$
      00234E                       1040 00107$:
      00234E 90 13 96         [24] 1041 	mov	dptr,#_accept_number_from_user_received_char_65536_86
      002351 E0               [24] 1042 	movx	a,@dptr
      002352 FF               [12] 1043 	mov	r7,a
      002353 BF 0D 02         [24] 1044 	cjne	r7,#0x0d,00143$
      002356 80 29            [24] 1045 	sjmp	00104$
      002358                       1046 00143$:
                                   1047 ;	uart.c:211: memset(number_in_char, 0, sizeof(number_in_char));
      002358 90 13 D5         [24] 1048 	mov	dptr,#_memset_PARM_2
      00235B E4               [12] 1049 	clr	a
      00235C F0               [24] 1050 	movx	@dptr,a
      00235D 90 13 D6         [24] 1051 	mov	dptr,#_memset_PARM_3
      002360 74 19            [12] 1052 	mov	a,#0x19
      002362 F0               [24] 1053 	movx	@dptr,a
      002363 E4               [12] 1054 	clr	a
      002364 A3               [24] 1055 	inc	dptr
      002365 F0               [24] 1056 	movx	@dptr,a
      002366 90 13 97         [24] 1057 	mov	dptr,#_accept_number_from_user_number_in_char_65536_86
      002369 75 F0 00         [24] 1058 	mov	b,#0x00
      00236C 12 2A 81         [24] 1059 	lcall	_memset
                                   1060 ;	uart.c:212: putstr("\r\n\t\t Error: Re-enter the number: ");
      00236F 90 3D 6B         [24] 1061 	mov	dptr,#___str_10
      002372 75 F0 80         [24] 1062 	mov	b,#0x80
      002375 12 22 2A         [24] 1063 	lcall	_putstr
                                   1064 ;	uart.c:213: i = 0;
      002378 90 13 B3         [24] 1065 	mov	dptr,#_accept_number_from_user_i_65536_86
      00237B E4               [12] 1066 	clr	a
      00237C F0               [24] 1067 	movx	@dptr,a
      00237D A3               [24] 1068 	inc	dptr
      00237E F0               [24] 1069 	movx	@dptr,a
      00237F 80 36            [24] 1070 	sjmp	00105$
      002381                       1071 00104$:
                                   1072 ;	uart.c:217: else if (received_char == '\r')
      002381 90 13 96         [24] 1073 	mov	dptr,#_accept_number_from_user_received_char_65536_86
      002384 E0               [24] 1074 	movx	a,@dptr
      002385 FF               [12] 1075 	mov	r7,a
      002386 BF 0D 2E         [24] 1076 	cjne	r7,#0x0d,00105$
                                   1077 ;	uart.c:219: strcat(number_in_char, '\0');
      002389 90 13 DE         [24] 1078 	mov	dptr,#_strcat_PARM_2
      00238C E4               [12] 1079 	clr	a
      00238D F0               [24] 1080 	movx	@dptr,a
      00238E A3               [24] 1081 	inc	dptr
      00238F F0               [24] 1082 	movx	@dptr,a
      002390 A3               [24] 1083 	inc	dptr
      002391 F0               [24] 1084 	movx	@dptr,a
      002392 90 13 97         [24] 1085 	mov	dptr,#_accept_number_from_user_number_in_char_65536_86
      002395 75 F0 00         [24] 1086 	mov	b,#0x00
      002398 12 2B C9         [24] 1087 	lcall	_strcat
                                   1088 ;	uart.c:220: number = atoi(number_in_char);
      00239B 90 13 97         [24] 1089 	mov	dptr,#_accept_number_from_user_number_in_char_65536_86
      00239E 75 F0 00         [24] 1090 	mov	b,#0x00
      0023A1 12 2A A9         [24] 1091 	lcall	_atoi
      0023A4 E5 82            [12] 1092 	mov	a,dpl
      0023A6 85 83 F0         [24] 1093 	mov	b,dph
      0023A9 90 13 B1         [24] 1094 	mov	dptr,#_accept_number_from_user_number_65536_86
      0023AC F0               [24] 1095 	movx	@dptr,a
      0023AD E5 F0            [12] 1096 	mov	a,b
      0023AF A3               [24] 1097 	inc	dptr
      0023B0 F0               [24] 1098 	movx	@dptr,a
                                   1099 ;	uart.c:221: valid_number_status = true;
      0023B1 90 13 B0         [24] 1100 	mov	dptr,#_accept_number_from_user_valid_number_status_65536_86
      0023B4 74 01            [12] 1101 	mov	a,#0x01
      0023B6 F0               [24] 1102 	movx	@dptr,a
      0023B7                       1103 00105$:
                                   1104 ;	uart.c:224: strncat(number_in_char, &received_char, 1);
      0023B7 90 13 F0         [24] 1105 	mov	dptr,#_strncat_PARM_2
      0023BA 74 96            [12] 1106 	mov	a,#_accept_number_from_user_received_char_65536_86
      0023BC F0               [24] 1107 	movx	@dptr,a
      0023BD 74 13            [12] 1108 	mov	a,#(_accept_number_from_user_received_char_65536_86 >> 8)
      0023BF A3               [24] 1109 	inc	dptr
      0023C0 F0               [24] 1110 	movx	@dptr,a
      0023C1 E4               [12] 1111 	clr	a
      0023C2 A3               [24] 1112 	inc	dptr
      0023C3 F0               [24] 1113 	movx	@dptr,a
      0023C4 90 13 F3         [24] 1114 	mov	dptr,#_strncat_PARM_3
      0023C7 04               [12] 1115 	inc	a
      0023C8 F0               [24] 1116 	movx	@dptr,a
      0023C9 E4               [12] 1117 	clr	a
      0023CA A3               [24] 1118 	inc	dptr
      0023CB F0               [24] 1119 	movx	@dptr,a
      0023CC 90 13 97         [24] 1120 	mov	dptr,#_accept_number_from_user_number_in_char_65536_86
      0023CF 75 F0 00         [24] 1121 	mov	b,#0x00
      0023D2 12 2E 8F         [24] 1122 	lcall	_strncat
                                   1123 ;	uart.c:226: if (i >= 24)
      0023D5 90 13 B3         [24] 1124 	mov	dptr,#_accept_number_from_user_i_65536_86
      0023D8 E0               [24] 1125 	movx	a,@dptr
      0023D9 FE               [12] 1126 	mov	r6,a
      0023DA A3               [24] 1127 	inc	dptr
      0023DB E0               [24] 1128 	movx	a,@dptr
      0023DC FF               [12] 1129 	mov	r7,a
      0023DD C3               [12] 1130 	clr	c
      0023DE EE               [12] 1131 	mov	a,r6
      0023DF 94 18            [12] 1132 	subb	a,#0x18
      0023E1 EF               [12] 1133 	mov	a,r7
      0023E2 64 80            [12] 1134 	xrl	a,#0x80
      0023E4 94 80            [12] 1135 	subb	a,#0x80
      0023E6 50 03            [24] 1136 	jnc	00146$
      0023E8 02 23 1B         [24] 1137 	ljmp	00110$
      0023EB                       1138 00146$:
                                   1139 ;	uart.c:228: putstr("\r\n\t\t Error: Reading a number failed, Reached maximum length supported");
      0023EB 90 3D 8D         [24] 1140 	mov	dptr,#___str_11
      0023EE 75 F0 80         [24] 1141 	mov	b,#0x80
      0023F1 12 22 2A         [24] 1142 	lcall	_putstr
                                   1143 ;	uart.c:229: putstr("\r\n\t\t Error: Re-enter the number: ");
      0023F4 90 3D 6B         [24] 1144 	mov	dptr,#___str_10
      0023F7 75 F0 80         [24] 1145 	mov	b,#0x80
      0023FA 12 22 2A         [24] 1146 	lcall	_putstr
                                   1147 ;	uart.c:231: memset(number_in_char, 0, sizeof(number_in_char));
      0023FD 90 13 D5         [24] 1148 	mov	dptr,#_memset_PARM_2
      002400 E4               [12] 1149 	clr	a
      002401 F0               [24] 1150 	movx	@dptr,a
      002402 90 13 D6         [24] 1151 	mov	dptr,#_memset_PARM_3
      002405 74 19            [12] 1152 	mov	a,#0x19
      002407 F0               [24] 1153 	movx	@dptr,a
      002408 E4               [12] 1154 	clr	a
      002409 A3               [24] 1155 	inc	dptr
      00240A F0               [24] 1156 	movx	@dptr,a
      00240B 90 13 97         [24] 1157 	mov	dptr,#_accept_number_from_user_number_in_char_65536_86
      00240E 75 F0 00         [24] 1158 	mov	b,#0x00
      002411 12 2A 81         [24] 1159 	lcall	_memset
                                   1160 ;	uart.c:232: i = 0;
      002414 90 13 B3         [24] 1161 	mov	dptr,#_accept_number_from_user_i_65536_86
      002417 E4               [12] 1162 	clr	a
      002418 F0               [24] 1163 	movx	@dptr,a
      002419 A3               [24] 1164 	inc	dptr
      00241A F0               [24] 1165 	movx	@dptr,a
      00241B 02 23 1B         [24] 1166 	ljmp	00110$
      00241E                       1167 00112$:
                                   1168 ;	uart.c:235: return number;
      00241E 90 13 B1         [24] 1169 	mov	dptr,#_accept_number_from_user_number_65536_86
      002421 E0               [24] 1170 	movx	a,@dptr
      002422 FE               [12] 1171 	mov	r6,a
      002423 A3               [24] 1172 	inc	dptr
      002424 E0               [24] 1173 	movx	a,@dptr
                                   1174 ;	uart.c:236: }
      002425 8E 82            [24] 1175 	mov	dpl,r6
      002427 F5 83            [12] 1176 	mov	dph,a
      002429 22               [24] 1177 	ret
                                   1178 ;------------------------------------------------------------
                                   1179 ;Allocation info for local variables in function 'print_buffers'
                                   1180 ;------------------------------------------------------------
                                   1181 ;sloc0                     Allocated with name '_print_buffers_sloc0_1_0'
                                   1182 ;buffers                   Allocated with name '_print_buffers_buffers_65536_91'
                                   1183 ;i                         Allocated with name '_print_buffers_i_131072_93'
                                   1184 ;------------------------------------------------------------
                                   1185 ;	uart.c:241: void print_buffers(buffer_t *buffers)
                                   1186 ;	-----------------------------------------
                                   1187 ;	 function print_buffers
                                   1188 ;	-----------------------------------------
      00242A                       1189 _print_buffers:
      00242A AF F0            [24] 1190 	mov	r7,b
      00242C AE 83            [24] 1191 	mov	r6,dph
      00242E E5 82            [12] 1192 	mov	a,dpl
      002430 90 13 B5         [24] 1193 	mov	dptr,#_print_buffers_buffers_65536_91
      002433 F0               [24] 1194 	movx	@dptr,a
      002434 EE               [12] 1195 	mov	a,r6
      002435 A3               [24] 1196 	inc	dptr
      002436 F0               [24] 1197 	movx	@dptr,a
      002437 EF               [12] 1198 	mov	a,r7
      002438 A3               [24] 1199 	inc	dptr
      002439 F0               [24] 1200 	movx	@dptr,a
                                   1201 ;	uart.c:243: printf_tiny("\r\n\r\n\t\t-------------------------");
      00243A 74 D3            [12] 1202 	mov	a,#___str_12
      00243C C0 E0            [24] 1203 	push	acc
      00243E 74 3D            [12] 1204 	mov	a,#(___str_12 >> 8)
      002440 C0 E0            [24] 1205 	push	acc
      002442 12 2C 52         [24] 1206 	lcall	_printf_tiny
      002445 15 81            [12] 1207 	dec	sp
      002447 15 81            [12] 1208 	dec	sp
                                   1209 ;	uart.c:244: printf_tiny("\r\n\t\t| buffer id |\tsize\t|");
      002449 74 F3            [12] 1210 	mov	a,#___str_13
      00244B C0 E0            [24] 1211 	push	acc
      00244D 74 3D            [12] 1212 	mov	a,#(___str_13 >> 8)
      00244F C0 E0            [24] 1213 	push	acc
      002451 12 2C 52         [24] 1214 	lcall	_printf_tiny
      002454 15 81            [12] 1215 	dec	sp
      002456 15 81            [12] 1216 	dec	sp
                                   1217 ;	uart.c:245: printf_tiny("\r\n\t\t-------------------------");
      002458 74 0C            [12] 1218 	mov	a,#___str_14
      00245A C0 E0            [24] 1219 	push	acc
      00245C 74 3E            [12] 1220 	mov	a,#(___str_14 >> 8)
      00245E C0 E0            [24] 1221 	push	acc
      002460 12 2C 52         [24] 1222 	lcall	_printf_tiny
      002463 15 81            [12] 1223 	dec	sp
      002465 15 81            [12] 1224 	dec	sp
                                   1225 ;	uart.c:246: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
      002467 90 13 B5         [24] 1226 	mov	dptr,#_print_buffers_buffers_65536_91
      00246A E0               [24] 1227 	movx	a,@dptr
      00246B FD               [12] 1228 	mov	r5,a
      00246C A3               [24] 1229 	inc	dptr
      00246D E0               [24] 1230 	movx	a,@dptr
      00246E FE               [12] 1231 	mov	r6,a
      00246F A3               [24] 1232 	inc	dptr
      002470 E0               [24] 1233 	movx	a,@dptr
      002471 FF               [12] 1234 	mov	r7,a
      002472 8D 08            [24] 1235 	mov	_print_buffers_sloc0_1_0,r5
      002474 8E 09            [24] 1236 	mov	(_print_buffers_sloc0_1_0 + 1),r6
      002476 8F 0A            [24] 1237 	mov	(_print_buffers_sloc0_1_0 + 2),r7
      002478 78 00            [12] 1238 	mov	r0,#0x00
      00247A 79 00            [12] 1239 	mov	r1,#0x00
      00247C                       1240 00107$:
      00247C C3               [12] 1241 	clr	c
      00247D E8               [12] 1242 	mov	a,r0
      00247E 94 D2            [12] 1243 	subb	a,#0xd2
      002480 E9               [12] 1244 	mov	a,r1
      002481 64 80            [12] 1245 	xrl	a,#0x80
      002483 94 80            [12] 1246 	subb	a,#0x80
      002485 40 03            [24] 1247 	jc	00128$
      002487 02 25 76         [24] 1248 	ljmp	00105$
      00248A                       1249 00128$:
                                   1250 ;	uart.c:248: if ((buffers[i].buffer_pointer != 0) || (i == 0) || (i == 1))
      00248A 90 13 E5         [24] 1251 	mov	dptr,#__mulint_PARM_2
      00248D E8               [12] 1252 	mov	a,r0
      00248E F0               [24] 1253 	movx	@dptr,a
      00248F E9               [12] 1254 	mov	a,r1
      002490 A3               [24] 1255 	inc	dptr
      002491 F0               [24] 1256 	movx	@dptr,a
      002492 90 00 09         [24] 1257 	mov	dptr,#0x0009
      002495 C0 07            [24] 1258 	push	ar7
      002497 C0 06            [24] 1259 	push	ar6
      002499 C0 05            [24] 1260 	push	ar5
      00249B C0 01            [24] 1261 	push	ar1
      00249D C0 00            [24] 1262 	push	ar0
      00249F 12 2D 5B         [24] 1263 	lcall	__mulint
      0024A2 AB 82            [24] 1264 	mov	r3,dpl
      0024A4 AC 83            [24] 1265 	mov	r4,dph
      0024A6 D0 00            [24] 1266 	pop	ar0
      0024A8 D0 01            [24] 1267 	pop	ar1
      0024AA D0 05            [24] 1268 	pop	ar5
      0024AC D0 06            [24] 1269 	pop	ar6
      0024AE D0 07            [24] 1270 	pop	ar7
      0024B0 EB               [12] 1271 	mov	a,r3
      0024B1 2D               [12] 1272 	add	a,r5
      0024B2 FB               [12] 1273 	mov	r3,a
      0024B3 EC               [12] 1274 	mov	a,r4
      0024B4 3E               [12] 1275 	addc	a,r6
      0024B5 FC               [12] 1276 	mov	r4,a
      0024B6 8F 02            [24] 1277 	mov	ar2,r7
      0024B8 8B 82            [24] 1278 	mov	dpl,r3
      0024BA 8C 83            [24] 1279 	mov	dph,r4
      0024BC 8A F0            [24] 1280 	mov	b,r2
      0024BE 12 3A E7         [24] 1281 	lcall	__gptrget
      0024C1 FB               [12] 1282 	mov	r3,a
      0024C2 A3               [24] 1283 	inc	dptr
      0024C3 12 3A E7         [24] 1284 	lcall	__gptrget
      0024C6 FC               [12] 1285 	mov	r4,a
      0024C7 A3               [24] 1286 	inc	dptr
      0024C8 12 3A E7         [24] 1287 	lcall	__gptrget
      0024CB FA               [12] 1288 	mov	r2,a
      0024CC EB               [12] 1289 	mov	a,r3
      0024CD 4C               [12] 1290 	orl	a,r4
      0024CE 70 0F            [24] 1291 	jnz	00101$
      0024D0 E8               [12] 1292 	mov	a,r0
      0024D1 49               [12] 1293 	orl	a,r1
      0024D2 60 0B            [24] 1294 	jz	00101$
      0024D4 B8 01 05         [24] 1295 	cjne	r0,#0x01,00131$
      0024D7 B9 00 02         [24] 1296 	cjne	r1,#0x00,00131$
      0024DA 80 03            [24] 1297 	sjmp	00132$
      0024DC                       1298 00131$:
      0024DC 02 25 6E         [24] 1299 	ljmp	00108$
      0024DF                       1300 00132$:
      0024DF                       1301 00101$:
                                   1302 ;	uart.c:249: printf_tiny("\r\n\t\t|    %d    |\t%d\t|", buffers[i].buf_id, buffers[i].buf_size);
      0024DF C0 05            [24] 1303 	push	ar5
      0024E1 C0 06            [24] 1304 	push	ar6
      0024E3 C0 07            [24] 1305 	push	ar7
      0024E5 90 13 E5         [24] 1306 	mov	dptr,#__mulint_PARM_2
      0024E8 E8               [12] 1307 	mov	a,r0
      0024E9 F0               [24] 1308 	movx	@dptr,a
      0024EA E9               [12] 1309 	mov	a,r1
      0024EB A3               [24] 1310 	inc	dptr
      0024EC F0               [24] 1311 	movx	@dptr,a
      0024ED 90 00 09         [24] 1312 	mov	dptr,#0x0009
      0024F0 C0 05            [24] 1313 	push	ar5
      0024F2 C0 01            [24] 1314 	push	ar1
      0024F4 C0 00            [24] 1315 	push	ar0
      0024F6 12 2D 5B         [24] 1316 	lcall	__mulint
      0024F9 AE 82            [24] 1317 	mov	r6,dpl
      0024FB AF 83            [24] 1318 	mov	r7,dph
      0024FD D0 00            [24] 1319 	pop	ar0
      0024FF D0 01            [24] 1320 	pop	ar1
      002501 D0 05            [24] 1321 	pop	ar5
      002503 EE               [12] 1322 	mov	a,r6
      002504 25 08            [12] 1323 	add	a,_print_buffers_sloc0_1_0
      002506 FE               [12] 1324 	mov	r6,a
      002507 EF               [12] 1325 	mov	a,r7
      002508 35 09            [12] 1326 	addc	a,(_print_buffers_sloc0_1_0 + 1)
      00250A FF               [12] 1327 	mov	r7,a
      00250B AD 0A            [24] 1328 	mov	r5,(_print_buffers_sloc0_1_0 + 2)
      00250D 74 07            [12] 1329 	mov	a,#0x07
      00250F 2E               [12] 1330 	add	a,r6
      002510 FA               [12] 1331 	mov	r2,a
      002511 E4               [12] 1332 	clr	a
      002512 3F               [12] 1333 	addc	a,r7
      002513 FB               [12] 1334 	mov	r3,a
      002514 8D 04            [24] 1335 	mov	ar4,r5
      002516 8A 82            [24] 1336 	mov	dpl,r2
      002518 8B 83            [24] 1337 	mov	dph,r3
      00251A 8C F0            [24] 1338 	mov	b,r4
      00251C 12 3A E7         [24] 1339 	lcall	__gptrget
      00251F FA               [12] 1340 	mov	r2,a
      002520 A3               [24] 1341 	inc	dptr
      002521 12 3A E7         [24] 1342 	lcall	__gptrget
      002524 FB               [12] 1343 	mov	r3,a
      002525 74 05            [12] 1344 	mov	a,#0x05
      002527 2E               [12] 1345 	add	a,r6
      002528 FE               [12] 1346 	mov	r6,a
      002529 E4               [12] 1347 	clr	a
      00252A 3F               [12] 1348 	addc	a,r7
      00252B FF               [12] 1349 	mov	r7,a
      00252C 8E 82            [24] 1350 	mov	dpl,r6
      00252E 8F 83            [24] 1351 	mov	dph,r7
      002530 8D F0            [24] 1352 	mov	b,r5
      002532 12 3A E7         [24] 1353 	lcall	__gptrget
      002535 FE               [12] 1354 	mov	r6,a
      002536 A3               [24] 1355 	inc	dptr
      002537 12 3A E7         [24] 1356 	lcall	__gptrget
      00253A FF               [12] 1357 	mov	r7,a
      00253B C0 07            [24] 1358 	push	ar7
      00253D C0 06            [24] 1359 	push	ar6
      00253F C0 05            [24] 1360 	push	ar5
      002541 C0 01            [24] 1361 	push	ar1
      002543 C0 00            [24] 1362 	push	ar0
      002545 C0 02            [24] 1363 	push	ar2
      002547 C0 03            [24] 1364 	push	ar3
      002549 C0 06            [24] 1365 	push	ar6
      00254B C0 07            [24] 1366 	push	ar7
      00254D 74 2A            [12] 1367 	mov	a,#___str_15
      00254F C0 E0            [24] 1368 	push	acc
      002551 74 3E            [12] 1369 	mov	a,#(___str_15 >> 8)
      002553 C0 E0            [24] 1370 	push	acc
      002555 12 2C 52         [24] 1371 	lcall	_printf_tiny
      002558 E5 81            [12] 1372 	mov	a,sp
      00255A 24 FA            [12] 1373 	add	a,#0xfa
      00255C F5 81            [12] 1374 	mov	sp,a
      00255E D0 00            [24] 1375 	pop	ar0
      002560 D0 01            [24] 1376 	pop	ar1
      002562 D0 05            [24] 1377 	pop	ar5
      002564 D0 06            [24] 1378 	pop	ar6
      002566 D0 07            [24] 1379 	pop	ar7
                                   1380 ;	uart.c:251: printf_tiny("\r\n\t\t-------------------------\r\n");
      002568 D0 07            [24] 1381 	pop	ar7
      00256A D0 06            [24] 1382 	pop	ar6
      00256C D0 05            [24] 1383 	pop	ar5
                                   1384 ;	uart.c:249: printf_tiny("\r\n\t\t|    %d    |\t%d\t|", buffers[i].buf_id, buffers[i].buf_size);
      00256E                       1385 00108$:
                                   1386 ;	uart.c:246: for (int i = 0; i < MAX_NUM_OF_BUFFERS; i++)
      00256E 08               [12] 1387 	inc	r0
      00256F B8 00 01         [24] 1388 	cjne	r0,#0x00,00133$
      002572 09               [12] 1389 	inc	r1
      002573                       1390 00133$:
      002573 02 24 7C         [24] 1391 	ljmp	00107$
      002576                       1392 00105$:
                                   1393 ;	uart.c:251: printf_tiny("\r\n\t\t-------------------------\r\n");
      002576 74 40            [12] 1394 	mov	a,#___str_16
      002578 C0 E0            [24] 1395 	push	acc
      00257A 74 3E            [12] 1396 	mov	a,#(___str_16 >> 8)
      00257C C0 E0            [24] 1397 	push	acc
      00257E 12 2C 52         [24] 1398 	lcall	_printf_tiny
      002581 15 81            [12] 1399 	dec	sp
      002583 15 81            [12] 1400 	dec	sp
                                   1401 ;	uart.c:252: }
      002585 22               [24] 1402 	ret
                                   1403 ;------------------------------------------------------------
                                   1404 ;Allocation info for local variables in function 'hexdump'
                                   1405 ;------------------------------------------------------------
                                   1406 ;sloc0                     Allocated with name '_hexdump_sloc0_1_0'
                                   1407 ;sloc1                     Allocated with name '_hexdump_sloc1_1_0'
                                   1408 ;nbytes                    Allocated with name '_hexdump_PARM_2'
                                   1409 ;loc                       Allocated with name '_hexdump_loc_65536_95'
                                   1410 ;loc_pointer               Allocated with name '_hexdump_loc_pointer_65536_96'
                                   1411 ;hex_byte                  Allocated with name '_hexdump_hex_byte_65536_96'
                                   1412 ;address_bytes             Allocated with name '_hexdump_address_bytes_65536_96'
                                   1413 ;num                       Allocated with name '_hexdump_num_65536_96'
                                   1414 ;total_chars_in_output_string Allocated with name '_hexdump_total_chars_in_output_string_65536_96'
                                   1415 ;i                         Allocated with name '_hexdump_i_131072_98'
                                   1416 ;j                         Allocated with name '_hexdump_j_327680_101'
                                   1417 ;------------------------------------------------------------
                                   1418 ;	uart.c:257: void hexdump(const void *loc, long nbytes)
                                   1419 ;	-----------------------------------------
                                   1420 ;	 function hexdump
                                   1421 ;	-----------------------------------------
      002586                       1422 _hexdump:
      002586 AF F0            [24] 1423 	mov	r7,b
      002588 AE 83            [24] 1424 	mov	r6,dph
      00258A E5 82            [12] 1425 	mov	a,dpl
      00258C 90 13 BC         [24] 1426 	mov	dptr,#_hexdump_loc_65536_95
      00258F F0               [24] 1427 	movx	@dptr,a
      002590 EE               [12] 1428 	mov	a,r6
      002591 A3               [24] 1429 	inc	dptr
      002592 F0               [24] 1430 	movx	@dptr,a
      002593 EF               [12] 1431 	mov	a,r7
      002594 A3               [24] 1432 	inc	dptr
      002595 F0               [24] 1433 	movx	@dptr,a
                                   1434 ;	uart.c:259: const char *loc_pointer = loc;
      002596 90 13 BC         [24] 1435 	mov	dptr,#_hexdump_loc_65536_95
      002599 E0               [24] 1436 	movx	a,@dptr
      00259A FD               [12] 1437 	mov	r5,a
      00259B A3               [24] 1438 	inc	dptr
      00259C E0               [24] 1439 	movx	a,@dptr
      00259D FE               [12] 1440 	mov	r6,a
      00259E A3               [24] 1441 	inc	dptr
      00259F E0               [24] 1442 	movx	a,@dptr
      0025A0 FF               [12] 1443 	mov	r7,a
                                   1444 ;	uart.c:260: char hex_byte[5] = "FF";
      0025A1 90 13 BF         [24] 1445 	mov	dptr,#_hexdump_hex_byte_65536_96
      0025A4 74 46            [12] 1446 	mov	a,#0x46
      0025A6 F0               [24] 1447 	movx	@dptr,a
      0025A7 90 13 C0         [24] 1448 	mov	dptr,#(_hexdump_hex_byte_65536_96 + 0x0001)
      0025AA F0               [24] 1449 	movx	@dptr,a
      0025AB 90 13 C1         [24] 1450 	mov	dptr,#(_hexdump_hex_byte_65536_96 + 0x0002)
      0025AE E4               [12] 1451 	clr	a
      0025AF F0               [24] 1452 	movx	@dptr,a
      0025B0 90 13 C2         [24] 1453 	mov	dptr,#(_hexdump_hex_byte_65536_96 + 0x0003)
      0025B3 F0               [24] 1454 	movx	@dptr,a
      0025B4 90 13 C3         [24] 1455 	mov	dptr,#(_hexdump_hex_byte_65536_96 + 0x0004)
      0025B7 F0               [24] 1456 	movx	@dptr,a
                                   1457 ;	uart.c:261: char address_bytes[7] = "0x0000";
      0025B8 90 13 C4         [24] 1458 	mov	dptr,#_hexdump_address_bytes_65536_96
      0025BB 74 30            [12] 1459 	mov	a,#0x30
      0025BD F0               [24] 1460 	movx	@dptr,a
      0025BE 90 13 C5         [24] 1461 	mov	dptr,#(_hexdump_address_bytes_65536_96 + 0x0001)
      0025C1 74 78            [12] 1462 	mov	a,#0x78
      0025C3 F0               [24] 1463 	movx	@dptr,a
      0025C4 90 13 C6         [24] 1464 	mov	dptr,#(_hexdump_address_bytes_65536_96 + 0x0002)
      0025C7 74 30            [12] 1465 	mov	a,#0x30
      0025C9 F0               [24] 1466 	movx	@dptr,a
      0025CA 90 13 C7         [24] 1467 	mov	dptr,#(_hexdump_address_bytes_65536_96 + 0x0003)
      0025CD F0               [24] 1468 	movx	@dptr,a
      0025CE 90 13 C8         [24] 1469 	mov	dptr,#(_hexdump_address_bytes_65536_96 + 0x0004)
      0025D1 F0               [24] 1470 	movx	@dptr,a
      0025D2 90 13 C9         [24] 1471 	mov	dptr,#(_hexdump_address_bytes_65536_96 + 0x0005)
      0025D5 F0               [24] 1472 	movx	@dptr,a
      0025D6 90 13 CA         [24] 1473 	mov	dptr,#(_hexdump_address_bytes_65536_96 + 0x0006)
      0025D9 E4               [12] 1474 	clr	a
      0025DA F0               [24] 1475 	movx	@dptr,a
                                   1476 ;	uart.c:268: if (nbytes == 0)
      0025DB 90 13 B8         [24] 1477 	mov	dptr,#_hexdump_PARM_2
      0025DE E0               [24] 1478 	movx	a,@dptr
      0025DF F9               [12] 1479 	mov	r1,a
      0025E0 A3               [24] 1480 	inc	dptr
      0025E1 E0               [24] 1481 	movx	a,@dptr
      0025E2 FA               [12] 1482 	mov	r2,a
      0025E3 A3               [24] 1483 	inc	dptr
      0025E4 E0               [24] 1484 	movx	a,@dptr
      0025E5 FB               [12] 1485 	mov	r3,a
      0025E6 A3               [24] 1486 	inc	dptr
      0025E7 E0               [24] 1487 	movx	a,@dptr
      0025E8 FC               [12] 1488 	mov	r4,a
      0025E9 90 13 B8         [24] 1489 	mov	dptr,#_hexdump_PARM_2
      0025EC E0               [24] 1490 	movx	a,@dptr
      0025ED F5 F0            [12] 1491 	mov	b,a
      0025EF A3               [24] 1492 	inc	dptr
      0025F0 E0               [24] 1493 	movx	a,@dptr
      0025F1 42 F0            [12] 1494 	orl	b,a
      0025F3 A3               [24] 1495 	inc	dptr
      0025F4 E0               [24] 1496 	movx	a,@dptr
      0025F5 42 F0            [12] 1497 	orl	b,a
      0025F7 A3               [24] 1498 	inc	dptr
      0025F8 E0               [24] 1499 	movx	a,@dptr
      0025F9 45 F0            [12] 1500 	orl	a,b
      0025FB 70 16            [24] 1501 	jnz	00102$
                                   1502 ;	uart.c:270: printf("\r\n\r\n\t\tNo stored characters in the buffer\r\n");
      0025FD 74 60            [12] 1503 	mov	a,#___str_19
      0025FF C0 E0            [24] 1504 	push	acc
      002601 74 3E            [12] 1505 	mov	a,#(___str_19 >> 8)
      002603 C0 E0            [24] 1506 	push	acc
      002605 74 80            [12] 1507 	mov	a,#0x80
      002607 C0 E0            [24] 1508 	push	acc
      002609 12 30 C5         [24] 1509 	lcall	_printf
      00260C 15 81            [12] 1510 	dec	sp
      00260E 15 81            [12] 1511 	dec	sp
      002610 15 81            [12] 1512 	dec	sp
                                   1513 ;	uart.c:271: return;
      002612 22               [24] 1514 	ret
      002613                       1515 00102$:
                                   1516 ;	uart.c:273: printf_tiny("\r\n\r\n\t\t|=======================================================");
      002613 C0 07            [24] 1517 	push	ar7
      002615 C0 06            [24] 1518 	push	ar6
      002617 C0 05            [24] 1519 	push	ar5
      002619 C0 04            [24] 1520 	push	ar4
      00261B C0 03            [24] 1521 	push	ar3
      00261D C0 02            [24] 1522 	push	ar2
      00261F C0 01            [24] 1523 	push	ar1
      002621 74 8B            [12] 1524 	mov	a,#___str_20
      002623 C0 E0            [24] 1525 	push	acc
      002625 74 3E            [12] 1526 	mov	a,#(___str_20 >> 8)
      002627 C0 E0            [24] 1527 	push	acc
      002629 12 2C 52         [24] 1528 	lcall	_printf_tiny
      00262C 15 81            [12] 1529 	dec	sp
      00262E 15 81            [12] 1530 	dec	sp
      002630 D0 01            [24] 1531 	pop	ar1
      002632 D0 02            [24] 1532 	pop	ar2
      002634 D0 03            [24] 1533 	pop	ar3
      002636 D0 04            [24] 1534 	pop	ar4
      002638 D0 05            [24] 1535 	pop	ar5
      00263A D0 06            [24] 1536 	pop	ar6
      00263C D0 07            [24] 1537 	pop	ar7
                                   1538 ;	uart.c:275: for (int i = 0; i < nbytes; i++)
      00263E E4               [12] 1539 	clr	a
      00263F F5 0B            [12] 1540 	mov	_hexdump_sloc0_1_0,a
      002641 F5 0C            [12] 1541 	mov	(_hexdump_sloc0_1_0 + 1),a
      002643                       1542 00111$:
      002643 C0 05            [24] 1543 	push	ar5
      002645 C0 06            [24] 1544 	push	ar6
      002647 C0 07            [24] 1545 	push	ar7
      002649 A8 0B            [24] 1546 	mov	r0,_hexdump_sloc0_1_0
      00264B E5 0C            [12] 1547 	mov	a,(_hexdump_sloc0_1_0 + 1)
      00264D FD               [12] 1548 	mov	r5,a
      00264E 33               [12] 1549 	rlc	a
      00264F 95 E0            [12] 1550 	subb	a,acc
      002651 FE               [12] 1551 	mov	r6,a
      002652 FF               [12] 1552 	mov	r7,a
      002653 C3               [12] 1553 	clr	c
      002654 E8               [12] 1554 	mov	a,r0
      002655 99               [12] 1555 	subb	a,r1
      002656 ED               [12] 1556 	mov	a,r5
      002657 9A               [12] 1557 	subb	a,r2
      002658 EE               [12] 1558 	mov	a,r6
      002659 9B               [12] 1559 	subb	a,r3
      00265A EF               [12] 1560 	mov	a,r7
      00265B 64 80            [12] 1561 	xrl	a,#0x80
      00265D 8C F0            [24] 1562 	mov	b,r4
      00265F 63 F0 80         [24] 1563 	xrl	b,#0x80
      002662 95 F0            [12] 1564 	subb	a,b
      002664 D0 07            [24] 1565 	pop	ar7
      002666 D0 06            [24] 1566 	pop	ar6
      002668 D0 05            [24] 1567 	pop	ar5
      00266A 40 03            [24] 1568 	jc	00142$
      00266C 02 28 A2         [24] 1569 	ljmp	00106$
      00266F                       1570 00142$:
                                   1571 ;	uart.c:277: if (i % 16 == 0) // 16 bytes per line
      00266F 90 13 E7         [24] 1572 	mov	dptr,#__modsint_PARM_2
      002672 74 10            [12] 1573 	mov	a,#0x10
      002674 F0               [24] 1574 	movx	@dptr,a
      002675 E4               [12] 1575 	clr	a
      002676 A3               [24] 1576 	inc	dptr
      002677 F0               [24] 1577 	movx	@dptr,a
      002678 85 0B 82         [24] 1578 	mov	dpl,_hexdump_sloc0_1_0
      00267B 85 0C 83         [24] 1579 	mov	dph,(_hexdump_sloc0_1_0 + 1)
      00267E C0 07            [24] 1580 	push	ar7
      002680 C0 06            [24] 1581 	push	ar6
      002682 C0 05            [24] 1582 	push	ar5
      002684 C0 04            [24] 1583 	push	ar4
      002686 C0 03            [24] 1584 	push	ar3
      002688 C0 02            [24] 1585 	push	ar2
      00268A C0 01            [24] 1586 	push	ar1
      00268C 12 2D 7B         [24] 1587 	lcall	__modsint
      00268F E5 82            [12] 1588 	mov	a,dpl
      002691 85 83 F0         [24] 1589 	mov	b,dph
      002694 D0 01            [24] 1590 	pop	ar1
      002696 D0 02            [24] 1591 	pop	ar2
      002698 D0 03            [24] 1592 	pop	ar3
      00269A D0 04            [24] 1593 	pop	ar4
      00269C D0 05            [24] 1594 	pop	ar5
      00269E D0 06            [24] 1595 	pop	ar6
      0026A0 D0 07            [24] 1596 	pop	ar7
      0026A2 45 F0            [12] 1597 	orl	a,b
      0026A4 60 03            [24] 1598 	jz	00143$
      0026A6 02 27 C1         [24] 1599 	ljmp	00105$
      0026A9                       1600 00143$:
                                   1601 ;	uart.c:280: uint_to_hexstr(address_bytes, sizeof(address_bytes), (uint16_t)loc_pointer + i, 16); // Converting offset address to hec string
      0026A9 C0 01            [24] 1602 	push	ar1
      0026AB C0 02            [24] 1603 	push	ar2
      0026AD C0 03            [24] 1604 	push	ar3
      0026AF C0 04            [24] 1605 	push	ar4
      0026B1 8D 00            [24] 1606 	mov	ar0,r5
      0026B3 8E 03            [24] 1607 	mov	ar3,r6
      0026B5 8F 04            [24] 1608 	mov	ar4,r7
      0026B7 AA 0B            [24] 1609 	mov	r2,_hexdump_sloc0_1_0
      0026B9 AC 0C            [24] 1610 	mov	r4,(_hexdump_sloc0_1_0 + 1)
      0026BB EA               [12] 1611 	mov	a,r2
      0026BC 28               [12] 1612 	add	a,r0
      0026BD F8               [12] 1613 	mov	r0,a
      0026BE EC               [12] 1614 	mov	a,r4
      0026BF 3B               [12] 1615 	addc	a,r3
      0026C0 FB               [12] 1616 	mov	r3,a
      0026C1 90 13 CB         [24] 1617 	mov	dptr,#_uint_to_hexstr_PARM_2
      0026C4 74 07            [12] 1618 	mov	a,#0x07
      0026C6 F0               [24] 1619 	movx	@dptr,a
      0026C7 E4               [12] 1620 	clr	a
      0026C8 A3               [24] 1621 	inc	dptr
      0026C9 F0               [24] 1622 	movx	@dptr,a
      0026CA A3               [24] 1623 	inc	dptr
      0026CB F0               [24] 1624 	movx	@dptr,a
      0026CC A3               [24] 1625 	inc	dptr
      0026CD F0               [24] 1626 	movx	@dptr,a
      0026CE 90 13 CF         [24] 1627 	mov	dptr,#_uint_to_hexstr_PARM_3
      0026D1 E8               [12] 1628 	mov	a,r0
      0026D2 F0               [24] 1629 	movx	@dptr,a
      0026D3 EB               [12] 1630 	mov	a,r3
      0026D4 A3               [24] 1631 	inc	dptr
      0026D5 F0               [24] 1632 	movx	@dptr,a
      0026D6 90 13 D1         [24] 1633 	mov	dptr,#_uint_to_hexstr_PARM_4
      0026D9 74 10            [12] 1634 	mov	a,#0x10
      0026DB F0               [24] 1635 	movx	@dptr,a
      0026DC 90 13 C4         [24] 1636 	mov	dptr,#_hexdump_address_bytes_65536_96
      0026DF 75 F0 00         [24] 1637 	mov	b,#0x00
      0026E2 C0 07            [24] 1638 	push	ar7
      0026E4 C0 06            [24] 1639 	push	ar6
      0026E6 C0 05            [24] 1640 	push	ar5
      0026E8 C0 04            [24] 1641 	push	ar4
      0026EA C0 03            [24] 1642 	push	ar3
      0026EC C0 02            [24] 1643 	push	ar2
      0026EE C0 01            [24] 1644 	push	ar1
      0026F0 12 28 B2         [24] 1645 	lcall	_uint_to_hexstr
                                   1646 ;	uart.c:281: printf("|\r\n\t\t| ");
      0026F3 74 CA            [12] 1647 	mov	a,#___str_21
      0026F5 C0 E0            [24] 1648 	push	acc
      0026F7 74 3E            [12] 1649 	mov	a,#(___str_21 >> 8)
      0026F9 C0 E0            [24] 1650 	push	acc
      0026FB 74 80            [12] 1651 	mov	a,#0x80
      0026FD C0 E0            [24] 1652 	push	acc
      0026FF 12 30 C5         [24] 1653 	lcall	_printf
      002702 15 81            [12] 1654 	dec	sp
      002704 15 81            [12] 1655 	dec	sp
      002706 15 81            [12] 1656 	dec	sp
      002708 D0 01            [24] 1657 	pop	ar1
      00270A D0 02            [24] 1658 	pop	ar2
      00270C D0 03            [24] 1659 	pop	ar3
      00270E D0 04            [24] 1660 	pop	ar4
      002710 D0 05            [24] 1661 	pop	ar5
      002712 D0 06            [24] 1662 	pop	ar6
      002714 D0 07            [24] 1663 	pop	ar7
                                   1664 ;	uart.c:283: for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
      002716 75 0D 02         [24] 1665 	mov	_hexdump_sloc1_1_0,#0x02
      002719 75 0E 00         [24] 1666 	mov	(_hexdump_sloc1_1_0 + 1),#0x00
                                   1667 ;	uart.c:297: printf_tiny("\r\n\t\t|=======================================================|\r\n");
      00271C D0 04            [24] 1668 	pop	ar4
      00271E D0 03            [24] 1669 	pop	ar3
      002720 D0 02            [24] 1670 	pop	ar2
      002722 D0 01            [24] 1671 	pop	ar1
                                   1672 ;	uart.c:283: for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
      002724                       1673 00108$:
      002724 C3               [12] 1674 	clr	c
      002725 E5 0D            [12] 1675 	mov	a,_hexdump_sloc1_1_0
      002727 94 06            [12] 1676 	subb	a,#0x06
      002729 E5 0E            [12] 1677 	mov	a,(_hexdump_sloc1_1_0 + 1)
      00272B 64 80            [12] 1678 	xrl	a,#0x80
      00272D 94 80            [12] 1679 	subb	a,#0x80
      00272F 50 5F            [24] 1680 	jnc	00103$
                                   1681 ;	uart.c:285: printf("%c", address_bytes[j]);
      002731 C0 01            [24] 1682 	push	ar1
      002733 C0 02            [24] 1683 	push	ar2
      002735 C0 03            [24] 1684 	push	ar3
      002737 C0 04            [24] 1685 	push	ar4
      002739 E5 0D            [12] 1686 	mov	a,_hexdump_sloc1_1_0
      00273B 24 C4            [12] 1687 	add	a,#_hexdump_address_bytes_65536_96
      00273D F5 82            [12] 1688 	mov	dpl,a
      00273F E5 0E            [12] 1689 	mov	a,(_hexdump_sloc1_1_0 + 1)
      002741 34 13            [12] 1690 	addc	a,#(_hexdump_address_bytes_65536_96 >> 8)
      002743 F5 83            [12] 1691 	mov	dph,a
      002745 E0               [24] 1692 	movx	a,@dptr
      002746 F8               [12] 1693 	mov	r0,a
      002747 7C 00            [12] 1694 	mov	r4,#0x00
      002749 C0 07            [24] 1695 	push	ar7
      00274B C0 06            [24] 1696 	push	ar6
      00274D C0 05            [24] 1697 	push	ar5
      00274F C0 04            [24] 1698 	push	ar4
      002751 C0 03            [24] 1699 	push	ar3
      002753 C0 02            [24] 1700 	push	ar2
      002755 C0 01            [24] 1701 	push	ar1
      002757 C0 00            [24] 1702 	push	ar0
      002759 C0 04            [24] 1703 	push	ar4
      00275B 74 D2            [12] 1704 	mov	a,#___str_22
      00275D C0 E0            [24] 1705 	push	acc
      00275F 74 3E            [12] 1706 	mov	a,#(___str_22 >> 8)
      002761 C0 E0            [24] 1707 	push	acc
      002763 74 80            [12] 1708 	mov	a,#0x80
      002765 C0 E0            [24] 1709 	push	acc
      002767 12 30 C5         [24] 1710 	lcall	_printf
      00276A E5 81            [12] 1711 	mov	a,sp
      00276C 24 FB            [12] 1712 	add	a,#0xfb
      00276E F5 81            [12] 1713 	mov	sp,a
      002770 D0 01            [24] 1714 	pop	ar1
      002772 D0 02            [24] 1715 	pop	ar2
      002774 D0 03            [24] 1716 	pop	ar3
      002776 D0 04            [24] 1717 	pop	ar4
      002778 D0 05            [24] 1718 	pop	ar5
      00277A D0 06            [24] 1719 	pop	ar6
      00277C D0 07            [24] 1720 	pop	ar7
                                   1721 ;	uart.c:283: for (int j = 2; j < 6; j++) // Adding offset in bytes from loc
      00277E 05 0D            [12] 1722 	inc	_hexdump_sloc1_1_0
      002780 E4               [12] 1723 	clr	a
      002781 B5 0D 02         [24] 1724 	cjne	a,_hexdump_sloc1_1_0,00145$
      002784 05 0E            [12] 1725 	inc	(_hexdump_sloc1_1_0 + 1)
      002786                       1726 00145$:
      002786 D0 04            [24] 1727 	pop	ar4
      002788 D0 03            [24] 1728 	pop	ar3
      00278A D0 02            [24] 1729 	pop	ar2
      00278C D0 01            [24] 1730 	pop	ar1
      00278E 80 94            [24] 1731 	sjmp	00108$
      002790                       1732 00103$:
                                   1733 ;	uart.c:288: printf(": ");
      002790 C0 07            [24] 1734 	push	ar7
      002792 C0 06            [24] 1735 	push	ar6
      002794 C0 05            [24] 1736 	push	ar5
      002796 C0 04            [24] 1737 	push	ar4
      002798 C0 03            [24] 1738 	push	ar3
      00279A C0 02            [24] 1739 	push	ar2
      00279C C0 01            [24] 1740 	push	ar1
      00279E 74 D5            [12] 1741 	mov	a,#___str_23
      0027A0 C0 E0            [24] 1742 	push	acc
      0027A2 74 3E            [12] 1743 	mov	a,#(___str_23 >> 8)
      0027A4 C0 E0            [24] 1744 	push	acc
      0027A6 74 80            [12] 1745 	mov	a,#0x80
      0027A8 C0 E0            [24] 1746 	push	acc
      0027AA 12 30 C5         [24] 1747 	lcall	_printf
      0027AD 15 81            [12] 1748 	dec	sp
      0027AF 15 81            [12] 1749 	dec	sp
      0027B1 15 81            [12] 1750 	dec	sp
      0027B3 D0 01            [24] 1751 	pop	ar1
      0027B5 D0 02            [24] 1752 	pop	ar2
      0027B7 D0 03            [24] 1753 	pop	ar3
      0027B9 D0 04            [24] 1754 	pop	ar4
      0027BB D0 05            [24] 1755 	pop	ar5
      0027BD D0 06            [24] 1756 	pop	ar6
      0027BF D0 07            [24] 1757 	pop	ar7
      0027C1                       1758 00105$:
                                   1759 ;	uart.c:290: num = *loc_pointer;
      0027C1 C0 01            [24] 1760 	push	ar1
      0027C3 C0 02            [24] 1761 	push	ar2
      0027C5 C0 03            [24] 1762 	push	ar3
      0027C7 C0 04            [24] 1763 	push	ar4
      0027C9 8D 82            [24] 1764 	mov	dpl,r5
      0027CB 8E 83            [24] 1765 	mov	dph,r6
      0027CD 8F F0            [24] 1766 	mov	b,r7
      0027CF 12 3A E7         [24] 1767 	lcall	__gptrget
      0027D2 F8               [12] 1768 	mov	r0,a
      0027D3 A3               [24] 1769 	inc	dptr
      0027D4 AD 82            [24] 1770 	mov	r5,dpl
      0027D6 AE 83            [24] 1771 	mov	r6,dph
      0027D8 7C 00            [12] 1772 	mov	r4,#0x00
                                   1773 ;	uart.c:291: uint_to_hexstr(hex_byte, sizeof(hex_byte), num, 8); // conveting each character to hex string
      0027DA 90 13 CB         [24] 1774 	mov	dptr,#_uint_to_hexstr_PARM_2
      0027DD 74 05            [12] 1775 	mov	a,#0x05
      0027DF F0               [24] 1776 	movx	@dptr,a
      0027E0 E4               [12] 1777 	clr	a
      0027E1 A3               [24] 1778 	inc	dptr
      0027E2 F0               [24] 1779 	movx	@dptr,a
      0027E3 A3               [24] 1780 	inc	dptr
      0027E4 F0               [24] 1781 	movx	@dptr,a
      0027E5 A3               [24] 1782 	inc	dptr
      0027E6 F0               [24] 1783 	movx	@dptr,a
      0027E7 90 13 CF         [24] 1784 	mov	dptr,#_uint_to_hexstr_PARM_3
      0027EA E8               [12] 1785 	mov	a,r0
      0027EB F0               [24] 1786 	movx	@dptr,a
      0027EC EC               [12] 1787 	mov	a,r4
      0027ED A3               [24] 1788 	inc	dptr
      0027EE F0               [24] 1789 	movx	@dptr,a
      0027EF 90 13 D1         [24] 1790 	mov	dptr,#_uint_to_hexstr_PARM_4
      0027F2 74 08            [12] 1791 	mov	a,#0x08
      0027F4 F0               [24] 1792 	movx	@dptr,a
      0027F5 90 13 BF         [24] 1793 	mov	dptr,#_hexdump_hex_byte_65536_96
      0027F8 75 F0 00         [24] 1794 	mov	b,#0x00
      0027FB C0 07            [24] 1795 	push	ar7
      0027FD C0 06            [24] 1796 	push	ar6
      0027FF C0 05            [24] 1797 	push	ar5
      002801 C0 04            [24] 1798 	push	ar4
      002803 C0 03            [24] 1799 	push	ar3
      002805 C0 02            [24] 1800 	push	ar2
      002807 C0 01            [24] 1801 	push	ar1
      002809 12 28 B2         [24] 1802 	lcall	_uint_to_hexstr
      00280C D0 01            [24] 1803 	pop	ar1
      00280E D0 02            [24] 1804 	pop	ar2
      002810 D0 03            [24] 1805 	pop	ar3
      002812 D0 04            [24] 1806 	pop	ar4
                                   1807 ;	uart.c:292: printf("%c", hex_byte[2]);
      002814 90 13 C1         [24] 1808 	mov	dptr,#(_hexdump_hex_byte_65536_96 + 0x0002)
      002817 E0               [24] 1809 	movx	a,@dptr
      002818 FC               [12] 1810 	mov	r4,a
      002819 7B 00            [12] 1811 	mov	r3,#0x00
      00281B C0 04            [24] 1812 	push	ar4
      00281D C0 03            [24] 1813 	push	ar3
      00281F C0 02            [24] 1814 	push	ar2
      002821 C0 01            [24] 1815 	push	ar1
      002823 C0 04            [24] 1816 	push	ar4
      002825 C0 03            [24] 1817 	push	ar3
      002827 74 D2            [12] 1818 	mov	a,#___str_22
      002829 C0 E0            [24] 1819 	push	acc
      00282B 74 3E            [12] 1820 	mov	a,#(___str_22 >> 8)
      00282D C0 E0            [24] 1821 	push	acc
      00282F 74 80            [12] 1822 	mov	a,#0x80
      002831 C0 E0            [24] 1823 	push	acc
      002833 12 30 C5         [24] 1824 	lcall	_printf
      002836 E5 81            [12] 1825 	mov	a,sp
      002838 24 FB            [12] 1826 	add	a,#0xfb
      00283A F5 81            [12] 1827 	mov	sp,a
      00283C D0 01            [24] 1828 	pop	ar1
      00283E D0 02            [24] 1829 	pop	ar2
      002840 D0 03            [24] 1830 	pop	ar3
      002842 D0 04            [24] 1831 	pop	ar4
                                   1832 ;	uart.c:293: printf("%c", hex_byte[3]);
      002844 90 13 C2         [24] 1833 	mov	dptr,#(_hexdump_hex_byte_65536_96 + 0x0003)
      002847 E0               [24] 1834 	movx	a,@dptr
      002848 FC               [12] 1835 	mov	r4,a
      002849 7B 00            [12] 1836 	mov	r3,#0x00
      00284B C0 04            [24] 1837 	push	ar4
      00284D C0 03            [24] 1838 	push	ar3
      00284F C0 02            [24] 1839 	push	ar2
      002851 C0 01            [24] 1840 	push	ar1
      002853 C0 04            [24] 1841 	push	ar4
      002855 C0 03            [24] 1842 	push	ar3
      002857 74 D2            [12] 1843 	mov	a,#___str_22
      002859 C0 E0            [24] 1844 	push	acc
      00285B 74 3E            [12] 1845 	mov	a,#(___str_22 >> 8)
      00285D C0 E0            [24] 1846 	push	acc
      00285F 74 80            [12] 1847 	mov	a,#0x80
      002861 C0 E0            [24] 1848 	push	acc
      002863 12 30 C5         [24] 1849 	lcall	_printf
      002866 E5 81            [12] 1850 	mov	a,sp
      002868 24 FB            [12] 1851 	add	a,#0xfb
      00286A F5 81            [12] 1852 	mov	sp,a
                                   1853 ;	uart.c:294: printf(" ");
      00286C 74 D8            [12] 1854 	mov	a,#___str_24
      00286E C0 E0            [24] 1855 	push	acc
      002870 74 3E            [12] 1856 	mov	a,#(___str_24 >> 8)
      002872 C0 E0            [24] 1857 	push	acc
      002874 74 80            [12] 1858 	mov	a,#0x80
      002876 C0 E0            [24] 1859 	push	acc
      002878 12 30 C5         [24] 1860 	lcall	_printf
      00287B 15 81            [12] 1861 	dec	sp
      00287D 15 81            [12] 1862 	dec	sp
      00287F 15 81            [12] 1863 	dec	sp
      002881 D0 01            [24] 1864 	pop	ar1
      002883 D0 02            [24] 1865 	pop	ar2
      002885 D0 03            [24] 1866 	pop	ar3
      002887 D0 04            [24] 1867 	pop	ar4
      002889 D0 05            [24] 1868 	pop	ar5
      00288B D0 06            [24] 1869 	pop	ar6
      00288D D0 07            [24] 1870 	pop	ar7
                                   1871 ;	uart.c:295: loc_pointer++;
                                   1872 ;	uart.c:275: for (int i = 0; i < nbytes; i++)
      00288F 05 0B            [12] 1873 	inc	_hexdump_sloc0_1_0
      002891 E4               [12] 1874 	clr	a
      002892 B5 0B 02         [24] 1875 	cjne	a,_hexdump_sloc0_1_0,00146$
      002895 05 0C            [12] 1876 	inc	(_hexdump_sloc0_1_0 + 1)
      002897                       1877 00146$:
      002897 D0 04            [24] 1878 	pop	ar4
      002899 D0 03            [24] 1879 	pop	ar3
      00289B D0 02            [24] 1880 	pop	ar2
      00289D D0 01            [24] 1881 	pop	ar1
      00289F 02 26 43         [24] 1882 	ljmp	00111$
      0028A2                       1883 00106$:
                                   1884 ;	uart.c:297: printf_tiny("\r\n\t\t|=======================================================|\r\n");
      0028A2 74 DA            [12] 1885 	mov	a,#___str_25
      0028A4 C0 E0            [24] 1886 	push	acc
      0028A6 74 3E            [12] 1887 	mov	a,#(___str_25 >> 8)
      0028A8 C0 E0            [24] 1888 	push	acc
      0028AA 12 2C 52         [24] 1889 	lcall	_printf_tiny
      0028AD 15 81            [12] 1890 	dec	sp
      0028AF 15 81            [12] 1891 	dec	sp
                                   1892 ;	uart.c:298: }
      0028B1 22               [24] 1893 	ret
                                   1894 ;------------------------------------------------------------
                                   1895 ;Allocation info for local variables in function 'uint_to_hexstr'
                                   1896 ;------------------------------------------------------------
                                   1897 ;sloc0                     Allocated with name '_uint_to_hexstr_sloc0_1_0'
                                   1898 ;sloc1                     Allocated with name '_uint_to_hexstr_sloc1_1_0'
                                   1899 ;sloc2                     Allocated with name '_uint_to_hexstr_sloc2_1_0'
                                   1900 ;sloc3                     Allocated with name '_uint_to_hexstr_sloc3_1_0'
                                   1901 ;size                      Allocated with name '_uint_to_hexstr_PARM_2'
                                   1902 ;num                       Allocated with name '_uint_to_hexstr_PARM_3'
                                   1903 ;nbits                     Allocated with name '_uint_to_hexstr_PARM_4'
                                   1904 ;str                       Allocated with name '_uint_to_hexstr_str_65536_103'
                                   1905 ;rem                       Allocated with name '_uint_to_hexstr_rem_65536_104'
                                   1906 ;total_chars               Allocated with name '_uint_to_hexstr_total_chars_65536_104'
                                   1907 ;i                         Allocated with name '_uint_to_hexstr_i_131072_107'
                                   1908 ;------------------------------------------------------------
                                   1909 ;	uart.c:303: int uint_to_hexstr(char *str, long size, uint16_t num, uint8_t nbits)
                                   1910 ;	-----------------------------------------
                                   1911 ;	 function uint_to_hexstr
                                   1912 ;	-----------------------------------------
      0028B2                       1913 _uint_to_hexstr:
      0028B2 AF F0            [24] 1914 	mov	r7,b
      0028B4 AE 83            [24] 1915 	mov	r6,dph
      0028B6 E5 82            [12] 1916 	mov	a,dpl
      0028B8 90 13 D2         [24] 1917 	mov	dptr,#_uint_to_hexstr_str_65536_103
      0028BB F0               [24] 1918 	movx	@dptr,a
      0028BC EE               [12] 1919 	mov	a,r6
      0028BD A3               [24] 1920 	inc	dptr
      0028BE F0               [24] 1921 	movx	@dptr,a
      0028BF EF               [12] 1922 	mov	a,r7
      0028C0 A3               [24] 1923 	inc	dptr
      0028C1 F0               [24] 1924 	movx	@dptr,a
                                   1925 ;	uart.c:309: if ((nbits != 4) && (nbits != 8) && (nbits != 16) && (nbits != 32))
      0028C2 90 13 D1         [24] 1926 	mov	dptr,#_uint_to_hexstr_PARM_4
      0028C5 E0               [24] 1927 	movx	a,@dptr
      0028C6 FF               [12] 1928 	mov	r7,a
      0028C7 BF 04 02         [24] 1929 	cjne	r7,#0x04,00150$
      0028CA 80 28            [24] 1930 	sjmp	00102$
      0028CC                       1931 00150$:
      0028CC BF 08 02         [24] 1932 	cjne	r7,#0x08,00151$
      0028CF 80 23            [24] 1933 	sjmp	00102$
      0028D1                       1934 00151$:
      0028D1 BF 10 02         [24] 1935 	cjne	r7,#0x10,00152$
      0028D4 80 1E            [24] 1936 	sjmp	00102$
      0028D6                       1937 00152$:
      0028D6 BF 20 02         [24] 1938 	cjne	r7,#0x20,00153$
      0028D9 80 19            [24] 1939 	sjmp	00102$
      0028DB                       1940 00153$:
                                   1941 ;	uart.c:311: str[0] = '\0';
      0028DB 90 13 D2         [24] 1942 	mov	dptr,#_uint_to_hexstr_str_65536_103
      0028DE E0               [24] 1943 	movx	a,@dptr
      0028DF FC               [12] 1944 	mov	r4,a
      0028E0 A3               [24] 1945 	inc	dptr
      0028E1 E0               [24] 1946 	movx	a,@dptr
      0028E2 FD               [12] 1947 	mov	r5,a
      0028E3 A3               [24] 1948 	inc	dptr
      0028E4 E0               [24] 1949 	movx	a,@dptr
      0028E5 FE               [12] 1950 	mov	r6,a
      0028E6 8C 82            [24] 1951 	mov	dpl,r4
      0028E8 8D 83            [24] 1952 	mov	dph,r5
      0028EA 8E F0            [24] 1953 	mov	b,r6
      0028EC E4               [12] 1954 	clr	a
      0028ED 12 2C 37         [24] 1955 	lcall	__gptrput
                                   1956 ;	uart.c:312: return -1;
      0028F0 90 FF FF         [24] 1957 	mov	dptr,#0xffff
      0028F3 22               [24] 1958 	ret
      0028F4                       1959 00102$:
                                   1960 ;	uart.c:315: total_chars = nbits / 4 + 3; // Every nibble requires 4 chars for representation AND +2 for 0x and +1 for \0
      0028F4 7E 00            [12] 1961 	mov	r6,#0x00
      0028F6 90 13 FB         [24] 1962 	mov	dptr,#__divsint_PARM_2
      0028F9 74 04            [12] 1963 	mov	a,#0x04
      0028FB F0               [24] 1964 	movx	@dptr,a
      0028FC E4               [12] 1965 	clr	a
      0028FD A3               [24] 1966 	inc	dptr
      0028FE F0               [24] 1967 	movx	@dptr,a
      0028FF 8F 82            [24] 1968 	mov	dpl,r7
      002901 8E 83            [24] 1969 	mov	dph,r6
      002903 12 2F 78         [24] 1970 	lcall	__divsint
      002906 85 82 18         [24] 1971 	mov	_uint_to_hexstr_sloc3_1_0,dpl
      002909 85 83 19         [24] 1972 	mov	(_uint_to_hexstr_sloc3_1_0 + 1),dph
      00290C 74 03            [12] 1973 	mov	a,#0x03
      00290E 25 18            [12] 1974 	add	a,_uint_to_hexstr_sloc3_1_0
      002910 F5 13            [12] 1975 	mov	_uint_to_hexstr_sloc1_1_0,a
      002912 E4               [12] 1976 	clr	a
      002913 35 19            [12] 1977 	addc	a,(_uint_to_hexstr_sloc3_1_0 + 1)
      002915 F5 14            [12] 1978 	mov	(_uint_to_hexstr_sloc1_1_0 + 1),a
                                   1979 ;	uart.c:318: if (total_chars > size)
      002917 90 13 CB         [24] 1980 	mov	dptr,#_uint_to_hexstr_PARM_2
      00291A E0               [24] 1981 	movx	a,@dptr
      00291B F5 0F            [12] 1982 	mov	_uint_to_hexstr_sloc0_1_0,a
      00291D A3               [24] 1983 	inc	dptr
      00291E E0               [24] 1984 	movx	a,@dptr
      00291F F5 10            [12] 1985 	mov	(_uint_to_hexstr_sloc0_1_0 + 1),a
      002921 A3               [24] 1986 	inc	dptr
      002922 E0               [24] 1987 	movx	a,@dptr
      002923 F5 11            [12] 1988 	mov	(_uint_to_hexstr_sloc0_1_0 + 2),a
      002925 A3               [24] 1989 	inc	dptr
      002926 E0               [24] 1990 	movx	a,@dptr
      002927 F5 12            [12] 1991 	mov	(_uint_to_hexstr_sloc0_1_0 + 3),a
      002929 A8 13            [24] 1992 	mov	r0,_uint_to_hexstr_sloc1_1_0
      00292B E5 14            [12] 1993 	mov	a,(_uint_to_hexstr_sloc1_1_0 + 1)
      00292D F9               [12] 1994 	mov	r1,a
      00292E 33               [12] 1995 	rlc	a
      00292F 95 E0            [12] 1996 	subb	a,acc
      002931 FA               [12] 1997 	mov	r2,a
      002932 FB               [12] 1998 	mov	r3,a
      002933 C3               [12] 1999 	clr	c
      002934 E5 0F            [12] 2000 	mov	a,_uint_to_hexstr_sloc0_1_0
      002936 98               [12] 2001 	subb	a,r0
      002937 E5 10            [12] 2002 	mov	a,(_uint_to_hexstr_sloc0_1_0 + 1)
      002939 99               [12] 2003 	subb	a,r1
      00293A E5 11            [12] 2004 	mov	a,(_uint_to_hexstr_sloc0_1_0 + 2)
      00293C 9A               [12] 2005 	subb	a,r2
      00293D E5 12            [12] 2006 	mov	a,(_uint_to_hexstr_sloc0_1_0 + 3)
      00293F 64 80            [12] 2007 	xrl	a,#0x80
      002941 8B F0            [24] 2008 	mov	b,r3
      002943 63 F0 80         [24] 2009 	xrl	b,#0x80
      002946 95 F0            [12] 2010 	subb	a,b
      002948 50 19            [24] 2011 	jnc	00107$
                                   2012 ;	uart.c:320: str[0] = '\0';
      00294A 90 13 D2         [24] 2013 	mov	dptr,#_uint_to_hexstr_str_65536_103
      00294D E0               [24] 2014 	movx	a,@dptr
      00294E F9               [12] 2015 	mov	r1,a
      00294F A3               [24] 2016 	inc	dptr
      002950 E0               [24] 2017 	movx	a,@dptr
      002951 FA               [12] 2018 	mov	r2,a
      002952 A3               [24] 2019 	inc	dptr
      002953 E0               [24] 2020 	movx	a,@dptr
      002954 FB               [12] 2021 	mov	r3,a
      002955 89 82            [24] 2022 	mov	dpl,r1
      002957 8A 83            [24] 2023 	mov	dph,r2
      002959 8B F0            [24] 2024 	mov	b,r3
      00295B E4               [12] 2025 	clr	a
      00295C 12 2C 37         [24] 2026 	lcall	__gptrput
                                   2027 ;	uart.c:321: return -1;
      00295F 90 FF FF         [24] 2028 	mov	dptr,#0xffff
      002962 22               [24] 2029 	ret
      002963                       2030 00107$:
                                   2031 ;	uart.c:324: str[0] = '0';
      002963 90 13 D2         [24] 2032 	mov	dptr,#_uint_to_hexstr_str_65536_103
      002966 E0               [24] 2033 	movx	a,@dptr
      002967 F9               [12] 2034 	mov	r1,a
      002968 A3               [24] 2035 	inc	dptr
      002969 E0               [24] 2036 	movx	a,@dptr
      00296A FA               [12] 2037 	mov	r2,a
      00296B A3               [24] 2038 	inc	dptr
      00296C E0               [24] 2039 	movx	a,@dptr
      00296D FB               [12] 2040 	mov	r3,a
      00296E 89 82            [24] 2041 	mov	dpl,r1
      002970 8A 83            [24] 2042 	mov	dph,r2
      002972 8B F0            [24] 2043 	mov	b,r3
      002974 74 30            [12] 2044 	mov	a,#0x30
      002976 12 2C 37         [24] 2045 	lcall	__gptrput
                                   2046 ;	uart.c:325: str[1] = 'x';
      002979 74 01            [12] 2047 	mov	a,#0x01
      00297B 29               [12] 2048 	add	a,r1
      00297C F8               [12] 2049 	mov	r0,a
      00297D E4               [12] 2050 	clr	a
      00297E 3A               [12] 2051 	addc	a,r2
      00297F FC               [12] 2052 	mov	r4,a
      002980 8B 05            [24] 2053 	mov	ar5,r3
      002982 88 82            [24] 2054 	mov	dpl,r0
      002984 8C 83            [24] 2055 	mov	dph,r4
      002986 8D F0            [24] 2056 	mov	b,r5
      002988 74 78            [12] 2057 	mov	a,#0x78
      00298A 12 2C 37         [24] 2058 	lcall	__gptrput
                                   2059 ;	uart.c:326: str[total_chars] = '\0';
      00298D E5 13            [12] 2060 	mov	a,_uint_to_hexstr_sloc1_1_0
      00298F 29               [12] 2061 	add	a,r1
      002990 F8               [12] 2062 	mov	r0,a
      002991 E5 14            [12] 2063 	mov	a,(_uint_to_hexstr_sloc1_1_0 + 1)
      002993 3A               [12] 2064 	addc	a,r2
      002994 FC               [12] 2065 	mov	r4,a
      002995 8B 05            [24] 2066 	mov	ar5,r3
      002997 88 82            [24] 2067 	mov	dpl,r0
      002999 8C 83            [24] 2068 	mov	dph,r4
      00299B 8D F0            [24] 2069 	mov	b,r5
      00299D E4               [12] 2070 	clr	a
      00299E 12 2C 37         [24] 2071 	lcall	__gptrput
                                   2072 ;	uart.c:329: for (int i = total_chars - 2; i > 1; i--)
      0029A1 E5 18            [12] 2073 	mov	a,_uint_to_hexstr_sloc3_1_0
      0029A3 24 01            [12] 2074 	add	a,#0x01
      0029A5 FC               [12] 2075 	mov	r4,a
      0029A6 E4               [12] 2076 	clr	a
      0029A7 35 19            [12] 2077 	addc	a,(_uint_to_hexstr_sloc3_1_0 + 1)
      0029A9 FD               [12] 2078 	mov	r5,a
      0029AA 89 0F            [24] 2079 	mov	_uint_to_hexstr_sloc0_1_0,r1
      0029AC 8A 10            [24] 2080 	mov	(_uint_to_hexstr_sloc0_1_0 + 1),r2
      0029AE 8B 11            [24] 2081 	mov	(_uint_to_hexstr_sloc0_1_0 + 2),r3
      0029B0                       2082 00113$:
      0029B0 C3               [12] 2083 	clr	c
      0029B1 74 01            [12] 2084 	mov	a,#0x01
      0029B3 9C               [12] 2085 	subb	a,r4
      0029B4 74 80            [12] 2086 	mov	a,#(0x00 ^ 0x80)
      0029B6 8D F0            [24] 2087 	mov	b,r5
      0029B8 63 F0 80         [24] 2088 	xrl	b,#0x80
      0029BB 95 F0            [12] 2089 	subb	a,b
      0029BD 40 03            [24] 2090 	jc	00155$
      0029BF 02 2A 74         [24] 2091 	ljmp	00111$
      0029C2                       2092 00155$:
                                   2093 ;	uart.c:331: rem = num % 16;
      0029C2 90 13 CF         [24] 2094 	mov	dptr,#_uint_to_hexstr_PARM_3
      0029C5 E0               [24] 2095 	movx	a,@dptr
      0029C6 F8               [12] 2096 	mov	r0,a
      0029C7 A3               [24] 2097 	inc	dptr
      0029C8 E0               [24] 2098 	movx	a,@dptr
      0029C9 74 0F            [12] 2099 	mov	a,#0x0f
      0029CB 58               [12] 2100 	anl	a,r0
      0029CC F5 13            [12] 2101 	mov	_uint_to_hexstr_sloc1_1_0,a
      0029CE 75 14 00         [24] 2102 	mov	(_uint_to_hexstr_sloc1_1_0 + 1),#0x00
                                   2103 ;	uart.c:332: if (rem < 10)
      0029D1 AE 13            [24] 2104 	mov	r6,_uint_to_hexstr_sloc1_1_0
      0029D3 AF 14            [24] 2105 	mov	r7,(_uint_to_hexstr_sloc1_1_0 + 1)
      0029D5 C3               [12] 2106 	clr	c
      0029D6 EE               [12] 2107 	mov	a,r6
      0029D7 94 0A            [12] 2108 	subb	a,#0x0a
      0029D9 EF               [12] 2109 	mov	a,r7
      0029DA 64 80            [12] 2110 	xrl	a,#0x80
      0029DC 94 80            [12] 2111 	subb	a,#0x80
      0029DE 50 20            [24] 2112 	jnc	00109$
                                   2113 ;	uart.c:334: str[i] = '0' + rem;
      0029E0 EC               [12] 2114 	mov	a,r4
      0029E1 29               [12] 2115 	add	a,r1
      0029E2 F5 15            [12] 2116 	mov	_uint_to_hexstr_sloc2_1_0,a
      0029E4 ED               [12] 2117 	mov	a,r5
      0029E5 3A               [12] 2118 	addc	a,r2
      0029E6 F5 16            [12] 2119 	mov	(_uint_to_hexstr_sloc2_1_0 + 1),a
      0029E8 8B 17            [24] 2120 	mov	(_uint_to_hexstr_sloc2_1_0 + 2),r3
      0029EA AE 13            [24] 2121 	mov	r6,_uint_to_hexstr_sloc1_1_0
      0029EC AF 14            [24] 2122 	mov	r7,(_uint_to_hexstr_sloc1_1_0 + 1)
      0029EE 74 30            [12] 2123 	mov	a,#0x30
      0029F0 2E               [12] 2124 	add	a,r6
      0029F1 FE               [12] 2125 	mov	r6,a
      0029F2 85 15 82         [24] 2126 	mov	dpl,_uint_to_hexstr_sloc2_1_0
      0029F5 85 16 83         [24] 2127 	mov	dph,(_uint_to_hexstr_sloc2_1_0 + 1)
      0029F8 85 17 F0         [24] 2128 	mov	b,(_uint_to_hexstr_sloc2_1_0 + 2)
      0029FB 12 2C 37         [24] 2129 	lcall	__gptrput
      0029FE 80 50            [24] 2130 	sjmp	00110$
      002A00                       2131 00109$:
                                   2132 ;	uart.c:338: str[i] = 'A' + (rem % 10);
      002A00 C0 01            [24] 2133 	push	ar1
      002A02 C0 02            [24] 2134 	push	ar2
      002A04 C0 03            [24] 2135 	push	ar3
      002A06 EC               [12] 2136 	mov	a,r4
      002A07 25 0F            [12] 2137 	add	a,_uint_to_hexstr_sloc0_1_0
      002A09 F8               [12] 2138 	mov	r0,a
      002A0A ED               [12] 2139 	mov	a,r5
      002A0B 35 10            [12] 2140 	addc	a,(_uint_to_hexstr_sloc0_1_0 + 1)
      002A0D FE               [12] 2141 	mov	r6,a
      002A0E AF 11            [24] 2142 	mov	r7,(_uint_to_hexstr_sloc0_1_0 + 2)
      002A10 AA 13            [24] 2143 	mov	r2,_uint_to_hexstr_sloc1_1_0
      002A12 AB 14            [24] 2144 	mov	r3,(_uint_to_hexstr_sloc1_1_0 + 1)
      002A14 90 13 E7         [24] 2145 	mov	dptr,#__modsint_PARM_2
      002A17 74 0A            [12] 2146 	mov	a,#0x0a
      002A19 F0               [24] 2147 	movx	@dptr,a
      002A1A E4               [12] 2148 	clr	a
      002A1B A3               [24] 2149 	inc	dptr
      002A1C F0               [24] 2150 	movx	@dptr,a
      002A1D 8A 82            [24] 2151 	mov	dpl,r2
      002A1F 8B 83            [24] 2152 	mov	dph,r3
      002A21 C0 07            [24] 2153 	push	ar7
      002A23 C0 06            [24] 2154 	push	ar6
      002A25 C0 05            [24] 2155 	push	ar5
      002A27 C0 04            [24] 2156 	push	ar4
      002A29 C0 01            [24] 2157 	push	ar1
      002A2B C0 00            [24] 2158 	push	ar0
      002A2D 12 2D 7B         [24] 2159 	lcall	__modsint
      002A30 AA 82            [24] 2160 	mov	r2,dpl
      002A32 D0 00            [24] 2161 	pop	ar0
      002A34 D0 01            [24] 2162 	pop	ar1
      002A36 D0 04            [24] 2163 	pop	ar4
      002A38 D0 05            [24] 2164 	pop	ar5
      002A3A D0 06            [24] 2165 	pop	ar6
      002A3C D0 07            [24] 2166 	pop	ar7
      002A3E 74 41            [12] 2167 	mov	a,#0x41
      002A40 2A               [12] 2168 	add	a,r2
      002A41 88 82            [24] 2169 	mov	dpl,r0
      002A43 8E 83            [24] 2170 	mov	dph,r6
      002A45 8F F0            [24] 2171 	mov	b,r7
      002A47 12 2C 37         [24] 2172 	lcall	__gptrput
                                   2173 ;	uart.c:343: return total_chars - 1;
      002A4A D0 03            [24] 2174 	pop	ar3
      002A4C D0 02            [24] 2175 	pop	ar2
      002A4E D0 01            [24] 2176 	pop	ar1
                                   2177 ;	uart.c:338: str[i] = 'A' + (rem % 10);
      002A50                       2178 00110$:
                                   2179 ;	uart.c:340: num = num / 16;
      002A50 90 13 CF         [24] 2180 	mov	dptr,#_uint_to_hexstr_PARM_3
      002A53 E0               [24] 2181 	movx	a,@dptr
      002A54 FE               [12] 2182 	mov	r6,a
      002A55 A3               [24] 2183 	inc	dptr
      002A56 E0               [24] 2184 	movx	a,@dptr
      002A57 C4               [12] 2185 	swap	a
      002A58 CE               [12] 2186 	xch	a,r6
      002A59 C4               [12] 2187 	swap	a
      002A5A 54 0F            [12] 2188 	anl	a,#0x0f
      002A5C 6E               [12] 2189 	xrl	a,r6
      002A5D CE               [12] 2190 	xch	a,r6
      002A5E 54 0F            [12] 2191 	anl	a,#0x0f
      002A60 CE               [12] 2192 	xch	a,r6
      002A61 6E               [12] 2193 	xrl	a,r6
      002A62 CE               [12] 2194 	xch	a,r6
      002A63 FF               [12] 2195 	mov	r7,a
      002A64 90 13 CF         [24] 2196 	mov	dptr,#_uint_to_hexstr_PARM_3
      002A67 EE               [12] 2197 	mov	a,r6
      002A68 F0               [24] 2198 	movx	@dptr,a
      002A69 EF               [12] 2199 	mov	a,r7
      002A6A A3               [24] 2200 	inc	dptr
      002A6B F0               [24] 2201 	movx	@dptr,a
                                   2202 ;	uart.c:329: for (int i = total_chars - 2; i > 1; i--)
      002A6C 1C               [12] 2203 	dec	r4
      002A6D BC FF 01         [24] 2204 	cjne	r4,#0xff,00157$
      002A70 1D               [12] 2205 	dec	r5
      002A71                       2206 00157$:
      002A71 02 29 B0         [24] 2207 	ljmp	00113$
      002A74                       2208 00111$:
                                   2209 ;	uart.c:343: return total_chars - 1;
      002A74 E5 18            [12] 2210 	mov	a,_uint_to_hexstr_sloc3_1_0
      002A76 24 02            [12] 2211 	add	a,#0x02
      002A78 FE               [12] 2212 	mov	r6,a
      002A79 E4               [12] 2213 	clr	a
      002A7A 35 19            [12] 2214 	addc	a,(_uint_to_hexstr_sloc3_1_0 + 1)
                                   2215 ;	uart.c:344: }
      002A7C 8E 82            [24] 2216 	mov	dpl,r6
      002A7E F5 83            [12] 2217 	mov	dph,a
      002A80 22               [24] 2218 	ret
                                   2219 	.area CSEG    (CODE)
                                   2220 	.area CONST   (CODE)
                                   2221 	.area CONST   (CODE)
      003C08                       2222 ___str_0:
      003C08 0D                    2223 	.db 0x0d
      003C09 0A                    2224 	.db 0x0a
      003C0A 09                    2225 	.db 0x09
      003C0B 09                    2226 	.db 0x09
      003C0C 20 2A 2A 20 54 75 72  2227 	.ascii " ** Turning PWM on ** "
             6E 69 6E 67 20 50 57
             4D 20 6F 6E 20 2A 2A
             20
      003C22 0D                    2228 	.db 0x0d
      003C23 0A                    2229 	.db 0x0a
      003C24 00                    2230 	.db 0x00
                                   2231 	.area CSEG    (CODE)
                                   2232 	.area CONST   (CODE)
      003C25                       2233 ___str_1:
      003C25 0D                    2234 	.db 0x0d
      003C26 0A                    2235 	.db 0x0a
      003C27 09                    2236 	.db 0x09
      003C28 09                    2237 	.db 0x09
      003C29 20 2A 2A 20 54 75 72  2238 	.ascii " ** Turning PWM off ** "
             6E 69 6E 67 20 50 57
             4D 20 6F 66 66 20 2A
             2A 20
      003C40 0D                    2239 	.db 0x0d
      003C41 0A                    2240 	.db 0x0a
      003C42 00                    2241 	.db 0x00
                                   2242 	.area CSEG    (CODE)
                                   2243 	.area CONST   (CODE)
      003C43                       2244 ___str_2:
      003C43 0D                    2245 	.db 0x0d
      003C44 0A                    2246 	.db 0x0a
      003C45 09                    2247 	.db 0x09
      003C46 09                    2248 	.db 0x09
      003C47 20 2A 2A 20 53 65 74  2249 	.ascii " ** Setting up minimum frequency ** "
             74 69 6E 67 20 75 70
             20 6D 69 6E 69 6D 75
             6D 20 66 72 65 71 75
             65 6E 63 79 20 2A 2A
             20
      003C6B 0D                    2250 	.db 0x0d
      003C6C 0A                    2251 	.db 0x0a
      003C6D 00                    2252 	.db 0x00
                                   2253 	.area CSEG    (CODE)
                                   2254 	.area CONST   (CODE)
      003C6E                       2255 ___str_3:
      003C6E 0D                    2256 	.db 0x0d
      003C6F 0A                    2257 	.db 0x0a
      003C70 09                    2258 	.db 0x09
      003C71 09                    2259 	.db 0x09
      003C72 20 2A 2A 20 53 65 74  2260 	.ascii " ** Setting up maximum frequency ** "
             74 69 6E 67 20 75 70
             20 6D 61 78 69 6D 75
             6D 20 66 72 65 71 75
             65 6E 63 79 20 2A 2A
             20
      003C96 0D                    2261 	.db 0x0d
      003C97 0A                    2262 	.db 0x0a
      003C98 00                    2263 	.db 0x00
                                   2264 	.area CSEG    (CODE)
                                   2265 	.area CONST   (CODE)
      003C99                       2266 ___str_4:
      003C99 0D                    2267 	.db 0x0d
      003C9A 0A                    2268 	.db 0x0a
      003C9B 09                    2269 	.db 0x09
      003C9C 09                    2270 	.db 0x09
      003C9D 20 2A 2A 20 45 6E 74  2271 	.ascii " ** Entering IDLE mode ** "
             65 72 69 6E 67 20 49
             44 4C 45 20 6D 6F 64
             65 20 2A 2A 20
      003CB7 0D                    2272 	.db 0x0d
      003CB8 0A                    2273 	.db 0x0a
      003CB9 00                    2274 	.db 0x00
                                   2275 	.area CSEG    (CODE)
                                   2276 	.area CONST   (CODE)
      003CBA                       2277 ___str_5:
      003CBA 0D                    2278 	.db 0x0d
      003CBB 0A                    2279 	.db 0x0a
      003CBC 09                    2280 	.db 0x09
      003CBD 09                    2281 	.db 0x09
      003CBE 20 2A 2A 20 45 6E 74  2282 	.ascii " ** Entering Power-down mode ** "
             65 72 69 6E 67 20 50
             6F 77 65 72 2D 64 6F
             77 6E 20 6D 6F 64 65
             20 2A 2A 20
      003CDE 0D                    2283 	.db 0x0d
      003CDF 0A                    2284 	.db 0x0a
      003CE0 00                    2285 	.db 0x00
                                   2286 	.area CSEG    (CODE)
                                   2287 	.area CONST   (CODE)
      003CE1                       2288 ___str_6:
      003CE1 0D                    2289 	.db 0x0d
      003CE2 0A                    2290 	.db 0x0a
      003CE3 0D                    2291 	.db 0x0d
      003CE4 0A                    2292 	.db 0x0a
      003CE5 09                    2293 	.db 0x09
      003CE6 20 45 72 72 6F 72 3A  2294 	.ascii " Error: Received invalid command '%c'"
             20 52 65 63 65 69 76
             65 64 20 69 6E 76 61
             6C 69 64 20 63 6F 6D
             6D 61 6E 64 20 27 25
             63 27
      003D0B 0D                    2295 	.db 0x0d
      003D0C 0A                    2296 	.db 0x0a
      003D0D 00                    2297 	.db 0x00
                                   2298 	.area CSEG    (CODE)
                                   2299 	.area CONST   (CODE)
      003D0E                       2300 ___str_7:
      003D0E 0D                    2301 	.db 0x0d
      003D0F 0A                    2302 	.db 0x0a
      003D10 2D 2D 2D 2D 2D 2D 2D  2303 	.ascii "------------------------------------------------------------"
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D
      003D4C 2D 2D 2D 2D 2D 2D 2D  2304 	.ascii "----------"
             2D 2D 2D
      003D56 0D                    2305 	.db 0x0d
      003D57 0A                    2306 	.db 0x0a
      003D58 0D                    2307 	.db 0x0d
      003D59 0A                    2308 	.db 0x0a
      003D5A 00                    2309 	.db 0x00
                                   2310 	.area CSEG    (CODE)
                                   2311 	.area CONST   (CODE)
      003D5B                       2312 ___str_8:
      003D5B 45 6E 74 65 72 20 63  2313 	.ascii "Enter command: "
             6F 6D 6D 61 6E 64 3A
             20
      003D6A 00                    2314 	.db 0x00
                                   2315 	.area CSEG    (CODE)
                                   2316 	.area CONST   (CODE)
      003D6B                       2317 ___str_10:
      003D6B 0D                    2318 	.db 0x0d
      003D6C 0A                    2319 	.db 0x0a
      003D6D 09                    2320 	.db 0x09
      003D6E 09                    2321 	.db 0x09
      003D6F 20 45 72 72 6F 72 3A  2322 	.ascii " Error: Re-enter the number: "
             20 52 65 2D 65 6E 74
             65 72 20 74 68 65 20
             6E 75 6D 62 65 72 3A
             20
      003D8C 00                    2323 	.db 0x00
                                   2324 	.area CSEG    (CODE)
                                   2325 	.area CONST   (CODE)
      003D8D                       2326 ___str_11:
      003D8D 0D                    2327 	.db 0x0d
      003D8E 0A                    2328 	.db 0x0a
      003D8F 09                    2329 	.db 0x09
      003D90 09                    2330 	.db 0x09
      003D91 20 45 72 72 6F 72 3A  2331 	.ascii " Error: Reading a number failed, Reached maximum length supp"
             20 52 65 61 64 69 6E
             67 20 61 20 6E 75 6D
             62 65 72 20 66 61 69
             6C 65 64 2C 20 52 65
             61 63 68 65 64 20 6D
             61 78 69 6D 75 6D 20
             6C 65 6E 67 74 68 20
             73 75 70 70
      003DCD 6F 72 74 65 64        2332 	.ascii "orted"
      003DD2 00                    2333 	.db 0x00
                                   2334 	.area CSEG    (CODE)
                                   2335 	.area CONST   (CODE)
      003DD3                       2336 ___str_12:
      003DD3 0D                    2337 	.db 0x0d
      003DD4 0A                    2338 	.db 0x0a
      003DD5 0D                    2339 	.db 0x0d
      003DD6 0A                    2340 	.db 0x0a
      003DD7 09                    2341 	.db 0x09
      003DD8 09                    2342 	.db 0x09
      003DD9 2D 2D 2D 2D 2D 2D 2D  2343 	.ascii "-------------------------"
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D
      003DF2 00                    2344 	.db 0x00
                                   2345 	.area CSEG    (CODE)
                                   2346 	.area CONST   (CODE)
      003DF3                       2347 ___str_13:
      003DF3 0D                    2348 	.db 0x0d
      003DF4 0A                    2349 	.db 0x0a
      003DF5 09                    2350 	.db 0x09
      003DF6 09                    2351 	.db 0x09
      003DF7 7C 20 62 75 66 66 65  2352 	.ascii "| buffer id |"
             72 20 69 64 20 7C
      003E04 09                    2353 	.db 0x09
      003E05 73 69 7A 65           2354 	.ascii "size"
      003E09 09                    2355 	.db 0x09
      003E0A 7C                    2356 	.ascii "|"
      003E0B 00                    2357 	.db 0x00
                                   2358 	.area CSEG    (CODE)
                                   2359 	.area CONST   (CODE)
      003E0C                       2360 ___str_14:
      003E0C 0D                    2361 	.db 0x0d
      003E0D 0A                    2362 	.db 0x0a
      003E0E 09                    2363 	.db 0x09
      003E0F 09                    2364 	.db 0x09
      003E10 2D 2D 2D 2D 2D 2D 2D  2365 	.ascii "-------------------------"
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D
      003E29 00                    2366 	.db 0x00
                                   2367 	.area CSEG    (CODE)
                                   2368 	.area CONST   (CODE)
      003E2A                       2369 ___str_15:
      003E2A 0D                    2370 	.db 0x0d
      003E2B 0A                    2371 	.db 0x0a
      003E2C 09                    2372 	.db 0x09
      003E2D 09                    2373 	.db 0x09
      003E2E 7C 20 20 20 20 25 64  2374 	.ascii "|    %d    |"
             20 20 20 20 7C
      003E3A 09                    2375 	.db 0x09
      003E3B 25 64                 2376 	.ascii "%d"
      003E3D 09                    2377 	.db 0x09
      003E3E 7C                    2378 	.ascii "|"
      003E3F 00                    2379 	.db 0x00
                                   2380 	.area CSEG    (CODE)
                                   2381 	.area CONST   (CODE)
      003E40                       2382 ___str_16:
      003E40 0D                    2383 	.db 0x0d
      003E41 0A                    2384 	.db 0x0a
      003E42 09                    2385 	.db 0x09
      003E43 09                    2386 	.db 0x09
      003E44 2D 2D 2D 2D 2D 2D 2D  2387 	.ascii "-------------------------"
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D 2D 2D 2D
             2D 2D 2D 2D
      003E5D 0D                    2388 	.db 0x0d
      003E5E 0A                    2389 	.db 0x0a
      003E5F 00                    2390 	.db 0x00
                                   2391 	.area CSEG    (CODE)
                                   2392 	.area CONST   (CODE)
      003E60                       2393 ___str_19:
      003E60 0D                    2394 	.db 0x0d
      003E61 0A                    2395 	.db 0x0a
      003E62 0D                    2396 	.db 0x0d
      003E63 0A                    2397 	.db 0x0a
      003E64 09                    2398 	.db 0x09
      003E65 09                    2399 	.db 0x09
      003E66 4E 6F 20 73 74 6F 72  2400 	.ascii "No stored characters in the buffer"
             65 64 20 63 68 61 72
             61 63 74 65 72 73 20
             69 6E 20 74 68 65 20
             62 75 66 66 65 72
      003E88 0D                    2401 	.db 0x0d
      003E89 0A                    2402 	.db 0x0a
      003E8A 00                    2403 	.db 0x00
                                   2404 	.area CSEG    (CODE)
                                   2405 	.area CONST   (CODE)
      003E8B                       2406 ___str_20:
      003E8B 0D                    2407 	.db 0x0d
      003E8C 0A                    2408 	.db 0x0a
      003E8D 0D                    2409 	.db 0x0d
      003E8E 0A                    2410 	.db 0x0a
      003E8F 09                    2411 	.db 0x09
      003E90 09                    2412 	.db 0x09
      003E91 7C 3D 3D 3D 3D 3D 3D  2413 	.ascii "|======================================================="
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
      003EC9 00                    2414 	.db 0x00
                                   2415 	.area CSEG    (CODE)
                                   2416 	.area CONST   (CODE)
      003ECA                       2417 ___str_21:
      003ECA 7C                    2418 	.ascii "|"
      003ECB 0D                    2419 	.db 0x0d
      003ECC 0A                    2420 	.db 0x0a
      003ECD 09                    2421 	.db 0x09
      003ECE 09                    2422 	.db 0x09
      003ECF 7C 20                 2423 	.ascii "| "
      003ED1 00                    2424 	.db 0x00
                                   2425 	.area CSEG    (CODE)
                                   2426 	.area CONST   (CODE)
      003ED2                       2427 ___str_22:
      003ED2 25 63                 2428 	.ascii "%c"
      003ED4 00                    2429 	.db 0x00
                                   2430 	.area CSEG    (CODE)
                                   2431 	.area CONST   (CODE)
      003ED5                       2432 ___str_23:
      003ED5 3A 20                 2433 	.ascii ": "
      003ED7 00                    2434 	.db 0x00
                                   2435 	.area CSEG    (CODE)
                                   2436 	.area CONST   (CODE)
      003ED8                       2437 ___str_24:
      003ED8 20                    2438 	.ascii " "
      003ED9 00                    2439 	.db 0x00
                                   2440 	.area CSEG    (CODE)
                                   2441 	.area CONST   (CODE)
      003EDA                       2442 ___str_25:
      003EDA 0D                    2443 	.db 0x0d
      003EDB 0A                    2444 	.db 0x0a
      003EDC 09                    2445 	.db 0x09
      003EDD 09                    2446 	.db 0x09
      003EDE 7C 3D 3D 3D 3D 3D 3D  2447 	.ascii "|=======================================================|"
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             3D 3D 3D 3D 3D 3D 3D
             7C
      003F17 0D                    2448 	.db 0x0d
      003F18 0A                    2449 	.db 0x0a
      003F19 00                    2450 	.db 0x00
                                   2451 	.area CSEG    (CODE)
                                   2452 	.area XINIT   (CODE)
      003F25                       2453 __xinit__buf_number:
      003F25 00 00                 2454 	.byte #0x00, #0x00	;  0
      003F27                       2455 __xinit__total_malloced_data:
      003F27 00 00                 2456 	.byte #0x00, #0x00	;  0
                                   2457 	.area CABS    (ABS,CODE)
