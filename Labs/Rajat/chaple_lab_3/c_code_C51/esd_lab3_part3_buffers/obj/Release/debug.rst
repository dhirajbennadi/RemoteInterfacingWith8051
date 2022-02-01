                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.9.0 #11195 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module debug
                                      6 	.optsdcc -mmcs51 --model-large
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _dataout_PARM_2
                                     12 	.globl _dataout
                                     13 ;--------------------------------------------------------
                                     14 ; special function registers
                                     15 ;--------------------------------------------------------
                                     16 	.area RSEG    (ABS,DATA)
      000000                         17 	.org 0x0000
                                     18 ;--------------------------------------------------------
                                     19 ; special function bits
                                     20 ;--------------------------------------------------------
                                     21 	.area RSEG    (ABS,DATA)
      000000                         22 	.org 0x0000
                                     23 ;--------------------------------------------------------
                                     24 ; overlayable register banks
                                     25 ;--------------------------------------------------------
                                     26 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                         27 	.ds 8
                                     28 ;--------------------------------------------------------
                                     29 ; internal ram data
                                     30 ;--------------------------------------------------------
                                     31 	.area DSEG    (DATA)
                                     32 ;--------------------------------------------------------
                                     33 ; overlayable items in internal ram 
                                     34 ;--------------------------------------------------------
                                     35 ;--------------------------------------------------------
                                     36 ; indirectly addressable internal ram data
                                     37 ;--------------------------------------------------------
                                     38 	.area ISEG    (DATA)
                                     39 ;--------------------------------------------------------
                                     40 ; absolute internal ram data
                                     41 ;--------------------------------------------------------
                                     42 	.area IABS    (ABS,DATA)
                                     43 	.area IABS    (ABS,DATA)
                                     44 ;--------------------------------------------------------
                                     45 ; bit data
                                     46 ;--------------------------------------------------------
                                     47 	.area BSEG    (BIT)
                                     48 ;--------------------------------------------------------
                                     49 ; paged external ram data
                                     50 ;--------------------------------------------------------
                                     51 	.area PSEG    (PAG,XDATA)
                                     52 ;--------------------------------------------------------
                                     53 ; external ram data
                                     54 ;--------------------------------------------------------
                                     55 	.area XSEG    (XDATA)
      001389                         56 _dataout_PARM_2:
      001389                         57 	.ds 1
      00138A                         58 _dataout_address_65536_2:
      00138A                         59 	.ds 3
                                     60 ;--------------------------------------------------------
                                     61 ; absolute external ram data
                                     62 ;--------------------------------------------------------
                                     63 	.area XABS    (ABS,XDATA)
                                     64 ;--------------------------------------------------------
                                     65 ; external initialized ram data
                                     66 ;--------------------------------------------------------
                                     67 	.area XISEG   (XDATA)
                                     68 	.area HOME    (CODE)
                                     69 	.area GSINIT0 (CODE)
                                     70 	.area GSINIT1 (CODE)
                                     71 	.area GSINIT2 (CODE)
                                     72 	.area GSINIT3 (CODE)
                                     73 	.area GSINIT4 (CODE)
                                     74 	.area GSINIT5 (CODE)
                                     75 	.area GSINIT  (CODE)
                                     76 	.area GSFINAL (CODE)
                                     77 	.area CSEG    (CODE)
                                     78 ;--------------------------------------------------------
                                     79 ; global & static initialisations
                                     80 ;--------------------------------------------------------
                                     81 	.area HOME    (CODE)
                                     82 	.area GSINIT  (CODE)
                                     83 	.area GSFINAL (CODE)
                                     84 	.area GSINIT  (CODE)
                                     85 ;--------------------------------------------------------
                                     86 ; Home
                                     87 ;--------------------------------------------------------
                                     88 	.area HOME    (CODE)
                                     89 	.area HOME    (CODE)
                                     90 ;--------------------------------------------------------
                                     91 ; code
                                     92 ;--------------------------------------------------------
                                     93 	.area CSEG    (CODE)
                                     94 ;------------------------------------------------------------
                                     95 ;Allocation info for local variables in function 'dataout'
                                     96 ;------------------------------------------------------------
                                     97 ;data                      Allocated with name '_dataout_PARM_2'
                                     98 ;address                   Allocated with name '_dataout_address_65536_2'
                                     99 ;------------------------------------------------------------
                                    100 ;	debug.c:17: void dataout(uint16_t* address, uint8_t data)
                                    101 ;	-----------------------------------------
                                    102 ;	 function dataout
                                    103 ;	-----------------------------------------
      002062                        104 _dataout:
                           000007   105 	ar7 = 0x07
                           000006   106 	ar6 = 0x06
                           000005   107 	ar5 = 0x05
                           000004   108 	ar4 = 0x04
                           000003   109 	ar3 = 0x03
                           000002   110 	ar2 = 0x02
                           000001   111 	ar1 = 0x01
                           000000   112 	ar0 = 0x00
      002062 AF F0            [24]  113 	mov	r7,b
      002064 AE 83            [24]  114 	mov	r6,dph
      002066 E5 82            [12]  115 	mov	a,dpl
      002068 90 13 8A         [24]  116 	mov	dptr,#_dataout_address_65536_2
      00206B F0               [24]  117 	movx	@dptr,a
      00206C EE               [12]  118 	mov	a,r6
      00206D A3               [24]  119 	inc	dptr
      00206E F0               [24]  120 	movx	@dptr,a
      00206F EF               [12]  121 	mov	a,r7
      002070 A3               [24]  122 	inc	dptr
      002071 F0               [24]  123 	movx	@dptr,a
                                    124 ;	debug.c:19: *address = data;
      002072 90 13 8A         [24]  125 	mov	dptr,#_dataout_address_65536_2
      002075 E0               [24]  126 	movx	a,@dptr
      002076 FD               [12]  127 	mov	r5,a
      002077 A3               [24]  128 	inc	dptr
      002078 E0               [24]  129 	movx	a,@dptr
      002079 FE               [12]  130 	mov	r6,a
      00207A A3               [24]  131 	inc	dptr
      00207B E0               [24]  132 	movx	a,@dptr
      00207C FF               [12]  133 	mov	r7,a
      00207D 90 13 89         [24]  134 	mov	dptr,#_dataout_PARM_2
      002080 E0               [24]  135 	movx	a,@dptr
      002081 FC               [12]  136 	mov	r4,a
      002082 7B 00            [12]  137 	mov	r3,#0x00
      002084 8D 82            [24]  138 	mov	dpl,r5
      002086 8E 83            [24]  139 	mov	dph,r6
      002088 8F F0            [24]  140 	mov	b,r7
      00208A EC               [12]  141 	mov	a,r4
      00208B 12 39 A1         [24]  142 	lcall	__gptrput
      00208E A3               [24]  143 	inc	dptr
      00208F EB               [12]  144 	mov	a,r3
                                    145 ;	debug.c:20: }
      002090 02 39 A1         [24]  146 	ljmp	__gptrput
                                    147 	.area CSEG    (CODE)
                                    148 	.area CONST   (CODE)
                                    149 	.area XINIT   (CODE)
                                    150 	.area CABS    (ABS,CODE)
