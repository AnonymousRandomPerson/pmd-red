@ File generated by m4a2s Song-Module
	.include "MPlayDef.s"

	.equ	seq_908_grp, bank_027
	.equ	seq_908_pri, 127
	.equ	seq_908_rev, 0
	.equ	seq_908_mvl, 127
	.equ	seq_908_key, 0

	.section .rodata
	.global	seq_908
	.align	2

@*********************** Track 01 ***********************@

seq_908_0:
	.byte	KEYSH , seq_908_key+0
	.byte	TEMPO , 140/2
	.byte		VOICE , 4
	.byte		VOL   , 100*seq_908_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N12   , Cn6 , v100
	.byte	W11
	.byte	W01
	.byte		VOICE , 1
	.byte		N01   , An3 , v040
	.byte	W01
	.byte		        Fs3 , v032
	.byte	W01
	.byte		        Ds3 , v020
	.byte	W01
	.byte		        Fs3 , v032
	.byte	W01
	.byte		        Ds3 , v020
	.byte	W01
	.byte	FINE

@******************************************************@

	.align	2

seq_908:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	seq_908_pri	@ Priority
	.byte	seq_908_rev	@ Reverb

	.word	seq_908_grp

	.word	seq_908_0

	.end