@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_846_grp, bank_026
	.equ	seq_846_pri, 127
	.equ	seq_846_rev, 0
	.equ	seq_846_mvl, 127
	.equ	seq_846_key, 0

	.section .rodata
	.global	seq_846
	.align	2

@*********************** Track 01 ***********************@

seq_846_0:
	.byte	KEYSH , seq_846_key+0
	.byte	TEMPO , 140/2
	.byte		VOICE , 29
	.byte		VOL   , 50*seq_846_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MOD   , 80
	.byte	W02
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 54*seq_846_mvl/mxv
	.byte		N24   , En0 , v032
	.byte		N24   , Fn1 , v127
	.byte	W01
	.byte		BEND  , c_v-17
	.byte	W01
	.byte		        c_v-24
	.byte	W01
	.byte		VOL   , 61*seq_846_mvl/mxv
	.byte		BEND  , c_v-31
	.byte	W01
	.byte		        c_v-38
	.byte	W01
	.byte		VOL   , 69*seq_846_mvl/mxv
	.byte		BEND  , c_v-34
	.byte	W01
	.byte		        c_v-27
	.byte	W01
	.byte		VOL   , 78*seq_846_mvl/mxv
	.byte		BEND  , c_v-19
	.byte	W01
	.byte		VOL   , 93*seq_846_mvl/mxv
	.byte		BEND  , c_v-12
	.byte	W01
	.byte		VOL   , 101*seq_846_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 112*seq_846_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 127*seq_846_mvl/mxv
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v-19
	.byte	W01
	.byte		        c_v-26
	.byte	W01
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v+3
	.byte	W01
	.byte		        c_v+15
	.byte	W01
	.byte		        c_v+26
	.byte	W01
	.byte		        c_v+38
	.byte	W01
	.byte		        c_v+43
	.byte	W01
	.byte	W02
	.byte		VOICE , 39
	.byte	W01
	.byte		N01   , Cn3 
	.byte	W03
	.byte		        Fn3 , v072
	.byte	W03
	.byte		        Cn4 , v044
	.byte	W03
	.byte		        Cn5 , v012
	.byte	W01
	.byte	FINE

@******************************************************@

	.align	2

seq_846:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_846_pri	@ Priority
	.byte	seq_846_rev	@ Reverb

	.word	seq_846_grp

	.word	seq_846_0

	.end