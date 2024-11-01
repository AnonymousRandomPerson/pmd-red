	#include "asm/constants/gba_constants.inc"
  	#include "asm/macros.inc"

  	.syntax unified

  	.text

	thumb_func_start sub_806EAF4
sub_806EAF4:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8C
	str r0, [sp, 0x70]
	mov r9, r1
	adds r7, r3, 0
	ldr r0, [sp, 0xB8]
	ldr r1, [sp, 0xBC]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x74]
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x78]
	ldr r0, [sp, 0x70]
	ldr r0, [r0, 0x70]
	mov r10, r0
	mov r1, r9
	ldr r1, [r1, 0x70]
	str r1, [sp, 0x7C]
	adds r0, r2, 0
	bl IsTypePhysical
	movs r2, 0
	str r2, [sp, 0x80]
	lsls r0, 24
	cmp r0, 0
	bne _0806EB3A
	movs r3, 0x1
	str r3, [sp, 0x80]
_0806EB3A:
	bl sub_806F500
	mov r6, r10
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0806EB72
	movs r0, 0x9E
	lsls r0, 1
	add r0, r10
	ldr r0, [r0]
	bl FixedPointToInt
	adds r1, r0, 0
	cmp r1, 0
	bne _0806EB72
	movs r0, 0x1
	ldr r2, [sp, 0xB0]
	str r0, [r2]
	str r1, [r2, 0x4]
	movs r0, 0x2
	str r0, [r2, 0x8]
	add r3, sp, 0x74
	ldrb r3, [r3]
	strb r3, [r2, 0xC]
	strb r1, [r2, 0xD]
	strb r1, [r2, 0xE]
	strb r1, [r2, 0xF]
	b _0806F294
_0806EB72:
	ldr r0, _0806EBA4
	cmp r4, r0
	bne _0806EBA8
	mov r0, r9
	movs r1, 0x35
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806EBA8
	movs r0, 0x1
	ldr r6, [sp, 0xB0]
	str r0, [r6]
	movs r1, 0
	str r1, [r6, 0x4]
	movs r0, 0x2
	str r0, [r6, 0x8]
	add r0, sp, 0x74
	ldrb r0, [r0]
	strb r0, [r6, 0xC]
	strb r1, [r6, 0xD]
	strb r1, [r6, 0xE]
	strb r1, [r6, 0xF]
	b _0806F294
	.align 2, 0
_0806EBA4: .4byte 0x00000163
_0806EBA8:
	add r1, sp, 0x74
	ldrb r2, [r1]
	ldr r1, [sp, 0xB0]
	strb r2, [r1, 0xC]
	ldr r1, _0806EDA4
	ldr r0, [r1]
	movs r2, 0x9A
	lsls r2, 1
	adds r0, r2
	add r3, sp, 0x74
	ldrb r3, [r3]
	strb r3, [r0]
	ldr r2, [r1]
	movs r6, 0x9C
	lsls r6, 1
	adds r0, r2, r6
	ldr r1, [sp, 0x80]
	str r1, [r0]
	lsls r1, 1
	mov r0, r10
	adds r0, 0x1C
	adds r0, r1
	movs r3, 0
	ldrsh r4, [r0, r3]
	mov r8, r1
	ldr r6, [sp, 0x78]
	cmp r6, 0
	beq _0806EBF8
	ldr r0, [sp, 0x74]
	cmp r0, 0x2
	bne _0806EBF8
	mov r1, r10
	movs r3, 0x28
	ldrsh r0, [r1, r3]
	adds r4, r0
	ldrh r1, [r1, 0x28]
	movs r6, 0xA2
	lsls r6, 1
	adds r0, r2, r6
	strh r1, [r0]
_0806EBF8:
	mov r0, r10
	movs r2, 0x4
	ldrsh r1, [r0, r2]
	ldr r0, _0806EDA8
	cmp r1, r0
	bne _0806EC06
	adds r4, 0x2
_0806EC06:
	movs r0, 0xD1
	lsls r0, 1
	cmp r1, r0
	bne _0806EC10
	subs r4, 0x2
_0806EC10:
	ldr r0, _0806EDAC
	cmp r1, r0
	bne _0806EC18
	subs r4, 0x2
_0806EC18:
	cmp r4, 0
	bge _0806EC1E
	movs r4, 0
_0806EC1E:
	cmp r4, 0x14
	ble _0806EC24
	movs r4, 0x14
_0806EC24:
	ldr r6, _0806EDA4
	ldr r0, [r6]
	movs r3, 0x9F
	lsls r3, 1
	adds r0, r3
	strb r4, [r0]
	ldr r1, [r6]
	mov r5, r10
	adds r5, 0x14
	ldr r0, [sp, 0x80]
	adds r2, r5, r0
	ldrb r0, [r2]
	adds r0, r7
	adds r3, 0x2
	adds r1, r3
	strh r0, [r1]
	ldrb r0, [r2]
	adds r0, r7
	lsls r0, 8
	ldr r2, _0806EDB0
	lsls r1, r4, 2
	adds r1, r2
	ldr r1, [r1]
	bl s24_8_mul
	adds r2, r0, 0
	ldr r0, [sp, 0x80]
	lsls r4, r0, 2
	mov r0, r10
	adds r0, 0x2C
	adds r0, r4
	ldr r1, [r0]
	adds r0, r2, 0
	bl s24_8_mul
	adds r2, r0, 0
	str r5, [sp, 0x88]
	cmp r2, 0
	bge _0806EC74
	adds r0, 0xFF
_0806EC74:
	asrs r0, 8
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x7C]
	adds r0, 0x20
	add r0, r8
	movs r1, 0
	ldrsh r3, [r0, r1]
	ldr r2, [sp, 0x80]
	cmp r2, 0
	bne _0806ECA0
	ldr r0, [sp, 0x7C]
	adds r0, 0xC0
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _0806ECA0
	ldr r0, [r6]
	movs r6, 0xBD
	lsls r6, 1
	adds r1, r0, r6
	movs r0, 0x1
	strb r0, [r1]
	adds r3, 0x1
_0806ECA0:
	ldr r0, [sp, 0x7C]
	movs r2, 0x4
	ldrsh r1, [r0, r2]
	ldr r0, _0806EDA8
	cmp r1, r0
	bne _0806ECAE
	subs r3, 0x2
_0806ECAE:
	movs r0, 0xD1
	lsls r0, 1
	cmp r1, r0
	bne _0806ECB8
	adds r3, 0x2
_0806ECB8:
	ldr r0, _0806EDAC
	cmp r1, r0
	bne _0806ECC0
	subs r3, 0x2
_0806ECC0:
	cmp r3, 0
	bge _0806ECC6
	movs r3, 0
_0806ECC6:
	cmp r3, 0x14
	ble _0806ECCC
	movs r3, 0x14
_0806ECCC:
	ldr r5, _0806EDA4
	ldr r0, [r5]
	ldr r6, _0806EDB4
	adds r0, r6
	strb r3, [r0]
	ldr r2, [r5]
	ldr r0, [sp, 0x7C]
	adds r0, 0x16
	ldr r1, [sp, 0x80]
	adds r0, r1
	ldrb r1, [r0]
	adds r6, 0x3
	adds r2, r6
	strh r1, [r2]
	ldrb r0, [r0]
	lsls r0, 8
	ldr r2, _0806EDB8
	lsls r1, r3, 2
	adds r1, r2
	ldr r1, [r1]
	bl s24_8_mul
	adds r2, r0, 0
	ldr r0, [sp, 0x7C]
	adds r0, 0x34
	adds r0, r4
	ldr r1, [r0]
	adds r0, r2, 0
	bl s24_8_mul
	cmp r0, 0
	bge _0806ED0E
	adds r0, 0xFF
_0806ED0E:
	asrs r0, 8
	str r0, [sp, 0xC]
	movs r0, 0x64
	bl DungeonRandInt
	str r0, [sp, 0x84]
	ldr r0, [sp, 0x80]
	cmp r0, 0
	bne _0806EDC8
	ldr r0, [sp, 0x70]
	movs r1, 0x13
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _0806ED4A
	ldr r2, _0806EDBC
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
	ldr r1, [r5]
	movs r6, 0xB0
	lsls r6, 1
	adds r1, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
_0806ED4A:
	ldr r0, [sp, 0x70]
	movs r1, 0x2B
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _0806ED74
	ldr r2, _0806EDC0
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
	ldr r1, [r5]
	movs r6, 0xB0
	lsls r6, 1
	adds r1, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
_0806ED74:
	ldr r3, [sp, 0x78]
	cmp r3, 0
	beq _0806EE4A
	mov r0, r9
	movs r1, 0x1E
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _0806EE4A
	ldr r2, _0806EDC4
	movs r6, 0
	ldrsh r1, [r2, r6]
	ldr r0, [sp, 0xC]
	adds r0, r1
	str r0, [sp, 0xC]
	ldr r0, [r5]
	movs r3, 0xB1
	lsls r3, 1
	adds r1, r0, r3
	ldrb r0, [r2]
	ldrb r6, [r1]
	adds r0, r6
	b _0806EE48
	.align 2, 0
_0806EDA4: .4byte gDungeon
_0806EDA8: .4byte 0x000001a1
_0806EDAC: .4byte 0x000001a3
_0806EDB0: .4byte gUnknown_80F504C
_0806EDB4: .4byte 0x0000013f
_0806EDB8: .4byte gUnknown_80F50A0
_0806EDBC: .4byte gUnknown_810AC60
_0806EDC0: .4byte gUnknown_810AC68
_0806EDC4: .4byte gUnknown_810AC64
_0806EDC8:
	ldr r0, [sp, 0x78]
	cmp r0, 0
	beq _0806EDF6
	mov r0, r9
	movs r1, 0x22
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _0806EDF6
	ldr r2, _0806EEF8
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0xC]
	adds r0, r1
	str r0, [sp, 0xC]
	ldr r0, [r5]
	ldr r6, _0806EEFC
	adds r1, r0, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
_0806EDF6:
	ldr r0, [sp, 0x70]
	movs r1, 0x21
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _0806EE20
	ldr r2, _0806EF00
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
	ldr r0, _0806EF04
	ldr r0, [r0]
	ldr r6, _0806EF08
	adds r1, r0, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
_0806EE20:
	ldr r0, [sp, 0x70]
	movs r1, 0x2B
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _0806EE4A
	ldr r2, _0806EF0C
	movs r3, 0
	ldrsh r1, [r2, r3]
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
	ldr r0, _0806EF04
	ldr r0, [r0]
	ldr r6, _0806EF08
	adds r1, r0, r6
	ldrb r0, [r2]
	ldrb r2, [r1]
	adds r0, r2
_0806EE48:
	strb r0, [r1]
_0806EE4A:
	ldr r0, _0806EF04
	ldr r2, [r0]
	movs r3, 0xA3
	lsls r3, 1
	adds r1, r2, r3
	add r0, sp, 0x8
	ldrh r0, [r0]
	strh r0, [r1]
	movs r6, 0xA4
	lsls r6, 1
	adds r1, r2, r6
	add r4, sp, 0xC
	ldrh r0, [r4]
	strh r0, [r1]
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bge _0806EE70
	movs r0, 0
	str r0, [sp, 0x8]
_0806EE70:
	ldr r1, _0806EF10
	ldr r0, [sp, 0x8]
	cmp r0, r1
	ble _0806EE7C
	ldr r0, _0806EF14
	str r0, [sp, 0x8]
_0806EE7C:
	movs r3, 0xA8
	lsls r3, 1
	add r3, r10
	ldrh r2, [r3]
	ldr r1, _0806EF18
	adds r0, r1, 0
	ands r0, r2
	strh r0, [r3]
	movs r2, 0xA7
	lsls r2, 1
	add r2, r10
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	str r4, [sp]
	ldr r0, [sp, 0x84]
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x70]
	mov r1, r9
	ldr r2, [sp, 0x74]
	add r3, sp, 0x8
	bl sub_806E8B0
	add r5, sp, 0x10
	ldr r1, [sp, 0x8]
	ldr r0, [sp, 0xC]
	subs r1, r0
	adds r0, r5, 0
	bl sub_800A020
	add r4, sp, 0x18
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_800A020
	adds r0, r5, 0
	adds r1, r5, 0
	adds r2, r4, 0
	bl sub_800A3F0
	mov r1, r10
	ldrb r6, [r1, 0x6]
	mov r8, r5
	adds r7, r4, 0
	cmp r6, 0
	bne _0806EF20
	ldrb r1, [r1, 0x9]
	adds r0, r7, 0
	bl sub_800A020
	str r6, [sp, 0x20]
	ldr r0, _0806EF1C
	add r2, sp, 0x20
	str r0, [r2, 0x4]
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_800A34C
	mov r2, r10
	ldrb r0, [r2, 0x9]
	lsls r0, 1
	b _0806EF60
	.align 2, 0
_0806EEF8: .4byte gUnknown_810AC66
_0806EEFC: .4byte 0x00000163
_0806EF00: .4byte gUnknown_810AC62
_0806EF04: .4byte gDungeon
_0806EF08: .4byte 0x00000161
_0806EF0C: .4byte gUnknown_810AC68
_0806EF10: .4byte 0x000003e6
_0806EF14: .4byte 0x000003e7
_0806EF18: .4byte 0x0000feff
_0806EF1C: .4byte 0x0000aaaa
_0806EF20:
	ldr r3, [sp, 0x88]
	ldr r6, [sp, 0x80]
	adds r0, r3, r6
	ldrb r0, [r0]
	str r0, [sp, 0x28]
	movs r0, 0x1
	str r0, [sp, 0x2C]
	add r3, sp, 0x28
	add r0, sp, 0x2C
	str r0, [sp]
	ldr r0, [sp, 0x84]
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x70]
	mov r1, r9
	ldr r2, [sp, 0x74]
	bl sub_806E8B0
	ldr r1, [sp, 0x28]
	adds r0, r7, 0
	bl sub_800A020
	add r4, sp, 0x20
	adds r0, r4, 0
	movs r1, 0x3
	bl sub_800A020
	adds r0, r7, 0
	adds r1, r7, 0
	adds r2, r4, 0
	bl sub_800A3F0
	ldr r0, [sp, 0x28]
_0806EF60:
	movs r1, 0x3
	bl __divsi3
	adds r6, r0, 0
	add r5, sp, 0x30
	adds r0, r5, 0
	mov r1, r8
	adds r2, r7, 0
	bl sub_800A6D0
	ldr r4, _0806F098
	ldr r0, [r4]
	movs r1, 0xA5
	lsls r1, 1
	adds r0, r1
	movs r2, 0
	mov r8, r2
	strh r6, [r0]
	adds r0, r5, 0
	bl sub_800A048
	ldr r1, [r4]
	movs r3, 0xA6
	lsls r3, 1
	adds r1, r3
	strh r0, [r1]
	ldr r0, [sp, 0x30]
	ldr r1, [sp, 0x34]
	str r0, [sp, 0x38]
	str r1, [sp, 0x3C]
	str r0, [sp, 0x48]
	str r1, [sp, 0x4C]
	add r6, sp, 0x38
	adds r0, r6, 0
	adds r1, r6, 0
	adds r2, r6, 0
	bl sub_800A34C
	mov r0, r8
	str r0, [sp, 0x40]
	ldr r0, _0806F09C
	add r5, sp, 0x40
	str r0, [r5, 0x4]
	adds r0, r6, 0
	adds r1, r6, 0
	adds r2, r5, 0
	bl sub_800A34C
	adds r0, r5, 0
	movs r1, 0x2
	bl sub_800A020
	add r4, sp, 0x48
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800A34C
	ldr r1, [sp, 0xC]
	adds r0, r5, 0
	bl sub_800A020
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800A6F0
	adds r0, r5, 0
	movs r1, 0xA
	bl sub_800A020
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_800A6D0
	add r5, sp, 0x50
	adds r0, r5, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl sub_800A6D0
	ldr r4, _0806F0A0
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_800A2F0
	lsls r0, 24
	mov r8, r5
	cmp r0, 0
	beq _0806F01E
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
_0806F01E:
	ldr r4, _0806F0A4
	mov r0, r8
	adds r1, r4, 0
	bl sub_800A2F0
	lsls r0, 24
	cmp r0, 0
	beq _0806F036
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [sp, 0x50]
	str r1, [sp, 0x54]
_0806F036:
	add r4, sp, 0x58
	ldr r1, [sp, 0xB0]
	str r1, [sp]
	adds r0, r4, 0
	ldr r1, [sp, 0x70]
	mov r2, r9
	ldr r3, [sp, 0x74]
	bl sub_806E100
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, r4, 0
	ldr r2, [sp, 0x74]
	cmp r2, 0x2
	bne _0806F0BC
	mov r0, r9
	bl GetFlashFireStatus
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0806F0BC
	ldr r3, [sp, 0x7C]
	movs r6, 0xA9
	lsls r6, 1
	adds r1, r3, r6
	ldrb r0, [r1]
	cmp r0, 0
	bne _0806F0BC
	ldr r0, [sp, 0x78]
	cmp r0, 0
	beq _0806F118
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, _0806F0A8
	mov r1, r9
	movs r2, 0
	bl SetMessageArgument
	cmp r4, 0x1
	bne _0806F0B0
	ldr r0, _0806F0AC
	ldr r2, [r0]
	ldr r0, [sp, 0x70]
	mov r1, r9
	bl TryDisplayDungeonLoggableMessage3
	b _0806F0BC
	.align 2, 0
_0806F098: .4byte gDungeon
_0806F09C: .4byte 0x00000ccc
_0806F0A0: .4byte gUnknown_8106F24
_0806F0A4: .4byte gUnknown_8106F04
_0806F0A8: .4byte gFormatBuffer_Monsters + 0x50
_0806F0AC: .4byte gUnknown_80FAE00
_0806F0B0:
	ldr r0, _0806F15C
	ldr r2, [r0]
	ldr r0, [sp, 0x70]
	mov r1, r9
	bl TryDisplayDungeonLoggableMessage3
_0806F0BC:
	ldr r1, [sp, 0x78]
	cmp r1, 0
	beq _0806F118
	ldr r2, [sp, 0x80]
	cmp r2, 0
	bne _0806F0EE
	ldr r0, [sp, 0x7C]
	adds r0, 0xC4
	ldrb r4, [r0]
	cmp r4, 0x1
	bne _0806F0EE
	mov r0, r9
	bl sub_8041B74
	ldr r2, _0806F160
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_800A34C
	ldr r0, _0806F164
	ldr r0, [r0]
	movs r3, 0xB3
	lsls r3, 1
	adds r0, r3
	strb r4, [r0]
_0806F0EE:
	ldr r6, [sp, 0x80]
	cmp r6, 0x1
	bne _0806F118
	ldr r0, [sp, 0x7C]
	adds r0, 0xC4
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _0806F118
	mov r0, r9
	bl sub_8041B5C
	ldr r2, _0806F160
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_800A34C
	ldr r0, _0806F164
	ldr r0, [r0]
	ldr r1, _0806F168
	adds r0, r1
	strb r6, [r0]
_0806F118:
	mov r0, r9
	movs r1, 0xC
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _0806F1F4
	mov r0, r9
	movs r1, 0x13
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	bne _0806F1F4
	mov r3, r10
	ldrb r0, [r3, 0x6]
	ldr r4, [sp, 0xAC]
	cmp r0, 0
	beq _0806F140
	movs r4, 0
_0806F140:
	mov r0, r10
	adds r0, 0xDC
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0806F170
	ldr r4, _0806F16C
	ldr r0, _0806F164
	ldr r0, [r0]
	movs r6, 0xB4
	lsls r6, 1
	adds r0, r6
	movs r1, 0x1
	strb r1, [r0]
	b _0806F1DA
	.align 2, 0
_0806F15C: .4byte gUnknown_80FADD8
_0806F160: .4byte gUnknown_8106F1C
_0806F164: .4byte gDungeon
_0806F168: .4byte 0x00000167
_0806F16C: .4byte 0x000003e7
_0806F170:
	ldr r0, [sp, 0x70]
	movs r1, 0xC
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _0806F194
	ldr r0, _0806F2A4
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r4, r0
	ldr r0, _0806F2A8
	ldr r0, [r0]
	movs r2, 0xB2
	lsls r2, 1
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
_0806F194:
	mov r0, r9
	movs r1, 0xD
	bl HasHeldItem
	lsls r0, 24
	cmp r0, 0
	beq _0806F1B6
	ldr r0, _0806F2A4
	movs r3, 0
	ldrsh r0, [r0, r3]
	adds r4, r0
	ldr r0, _0806F2A8
	ldr r0, [r0]
	ldr r6, _0806F2AC
	adds r1, r0, r6
	movs r0, 0x1
	strb r0, [r1]
_0806F1B6:
	cmp r5, 0
	beq _0806F1DA
	ldr r0, [sp, 0x70]
	movs r1, 0x1
	bl IQSkillIsEnabled
	lsls r0, 24
	cmp r0, 0
	beq _0806F1DA
	ldr r0, _0806F2B0
	movs r1, 0
	ldrsh r4, [r0, r1]
	ldr r0, _0806F2A8
	ldr r0, [r0]
	ldr r2, _0806F2B4
	adds r1, r0, r2
	movs r0, 0x1
	strb r0, [r1]
_0806F1DA:
	movs r0, 0x64
	bl DungeonRandInt
	cmp r0, r4
	bge _0806F1F4
	ldr r2, _0806F2B8
	adds r0, r7, 0
	adds r1, r7, 0
	bl sub_800A34C
	movs r0, 0x1
	ldr r3, [sp, 0xB0]
	strb r0, [r3, 0xD]
_0806F1F4:
	mov r0, r8
	bl sub_800A048
	ldr r5, _0806F2A8
	ldr r1, [r5]
	movs r6, 0xAA
	lsls r6, 1
	adds r1, r6
	str r0, [r1]
	mov r0, r8
	mov r1, r8
	adds r2, r7, 0
	bl sub_800A34C
	ldr r0, [r5]
	movs r1, 0xAE
	lsls r1, 1
	adds r0, r1
	ldr r2, [sp, 0xB4]
	str r2, [r0]
	add r4, sp, 0x60
	adds r0, r4, 0
	adds r1, r2, 0
	bl sub_800A088
	mov r0, r8
	mov r1, r8
	adds r2, r4, 0
	bl sub_800A34C
	mov r0, r8
	bl sub_800A048
	ldr r1, [r5]
	movs r3, 0xA8
	lsls r3, 1
	adds r1, r3
	str r0, [r1]
	movs r0, 0x80
	lsls r0, 7
	bl DungeonRandInt
	movs r6, 0
	str r6, [sp, 0x58]
	movs r1, 0xE0
	lsls r1, 8
	adds r0, r1
	str r0, [r7, 0x4]
	mov r0, r8
	mov r1, r8
	adds r2, r7, 0
	bl sub_800A34C
	add r4, sp, 0x68
	adds r0, r4, 0
	movs r1, 0x64
	bl sub_800A020
	adds r0, r7, 0
	adds r1, r4, 0
	adds r2, r7, 0
	bl sub_800A34C
	adds r0, r7, 0
	bl sub_800A048
	ldr r1, [r5]
	movs r2, 0xAC
	lsls r2, 1
	adds r1, r2
	str r0, [r1]
	mov r0, r8
	bl sub_800A048
	ldr r3, [sp, 0xB0]
	str r0, [r3]
	str r6, [r3, 0x4]
	cmp r0, 0
	bne _0806F294
	strb r0, [r3, 0xD]
_0806F294:
	add sp, 0x8C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F2A4: .4byte gUnknown_80F4DAE
_0806F2A8: .4byte gDungeon
_0806F2AC: .4byte 0x00000165
_0806F2B0: .4byte gUnknown_80F4DB0
_0806F2B4: .4byte 0x00000169
_0806F2B8: .4byte gUnknown_8106F14
	thumb_func_end sub_806EAF4

	thumb_func_start sub_806F2BC
sub_806F2BC:
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	adds r5, r0, 0
	mov r12, r1
	ldr r7, [sp, 0x2C]
	lsls r2, 24
	lsrs r4, r2, 24
	adds r6, r3, 0
	cmp r6, 0
	bgt _0806F2D6
	movs r6, 0x1
_0806F2D6:
	ldr r0, _0806F320
	cmp r6, r0
	ble _0806F2DE
	adds r6, r0, 0
_0806F2DE:
	movs r0, 0
	mov r8, r0
	strb r4, [r7, 0xC]
	str r7, [sp]
	add r0, sp, 0x4
	adds r1, r5, 0
	mov r2, r12
	adds r3, r4, 0
	bl sub_806E100
	add r4, sp, 0xC
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_800A020
	adds r0, r4, 0
	adds r1, r4, 0
	add r2, sp, 0x4
	bl sub_800A34C
	adds r0, r4, 0
	bl sub_800A048
	str r0, [r7]
	mov r0, r8
	str r0, [r7, 0x4]
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F320: .4byte 0x000003e7
	thumb_func_end sub_806F2BC

	thumb_func_start DealDamageToEntity
DealDamageToEntity:
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x94
	mov r8, r0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, r3, 16
	asrs r4, 16
	add r0, sp, 0x10
	bl sub_80457DC
	add r2, sp, 0x84
	str r5, [sp, 0x84]
	movs r0, 0x2
	str r0, [r2, 0x8]
	movs r0, 0
	strb r0, [r2, 0xC]
	str r6, [r2, 0x4]
	strb r0, [r2, 0xD]
	strb r0, [r2, 0xE]
	strb r0, [r2, 0xF]
	str r0, [sp]
	str r4, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	add r0, sp, 0x10
	mov r1, r8
	movs r3, 0
	bl HandleDealingDamage
	add sp, 0x94
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end DealDamageToEntity

	thumb_func_start sub_806F370
sub_806F370:
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	mov r10, r0
	adds r7, r1, 0
	mov r9, r3
	ldr r0, [sp, 0x50]
	ldr r1, [sp, 0x54]
	ldr r3, [sp, 0x58]
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 16
	asrs r1, 16
	mov r8, r1
	adds r5, r2, 0
	movs r0, 0x2
	str r0, [sp, 0x18]
	str r3, [sp, 0x14]
	add r0, sp, 0x10
	movs r1, 0
	strb r4, [r0, 0xC]
	strb r1, [r0, 0xD]
	strb r1, [r0, 0xE]
	cmp r4, 0
	beq _0806F3FC
	ldr r1, [r7, 0x70]
	movs r2, 0
	lsls r0, r4, 3
	mov r3, sp
	adds r3, 0x20
	str r3, [sp, 0x28]
	ldr r6, _0806F408
	mov r12, r6
	adds r1, 0x5C
	adds r0, r4
	lsls r3, r0, 2
	ldr r4, [sp, 0x28]
_0806F3C0:
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r3
	add r0, r12
	movs r6, 0
	ldrsh r0, [r0, r6]
	stm r4!, {r0}
	adds r2, 0x1
	cmp r2, 0x1
	ble _0806F3C0
	adds r0, r7, 0
	movs r1, 0x35
	bl HasAbility
	lsls r0, 24
	cmp r0, 0
	beq _0806F3FC
	ldr r2, _0806F40C
	ldr r1, [sp, 0x28]
	ldr r0, [r1, 0x4]
	lsls r0, 2
	ldr r1, [sp, 0x20]
	lsls r1, 4
	adds r0, r1
	adds r0, r2
	ldr r0, [r0]
	cmp r0, 0x3
	beq _0806F3FC
	movs r5, 0
_0806F3FC:
	str r5, [sp, 0x10]
	cmp r5, 0
	bne _0806F410
	add r1, sp, 0x10
	movs r0, 0x1
	b _0806F414
	.align 2, 0
_0806F408: .4byte gTypeEffectivenessChart
_0806F40C: .4byte gUnknown_80F54B4
_0806F410:
	add r1, sp, 0x10
	movs r0, 0
_0806F414:
	strb r0, [r1, 0xF]
	mov r3, r9
	str r3, [sp]
	mov r6, r8
	str r6, [sp, 0x4]
	ldr r0, [sp, 0x5C]
	str r0, [sp, 0x8]
	ldr r0, [sp, 0x60]
	str r0, [sp, 0xC]
	mov r0, r10
	adds r1, r7, 0
	add r2, sp, 0x10
	movs r3, 0
	bl HandleDealingDamage
	ldr r0, [sp, 0x4C]
	cmp r0, 0
	beq _0806F440
	add r0, sp, 0x10
	ldrb r0, [r0, 0xF]
	ldr r1, [sp, 0x4C]
	strb r0, [r1]
_0806F440:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806F370

    .align 2,0
