#ifndef GUARD_SPRITE_H
#define GUARD_SPRITE_H

#include "structs/axdata.h"
#include "structs/sprite_oam.h"
#include "structs/str_position.h"

// size: 0x8
typedef struct UnkSpriteLink
{
    struct UnkSpriteLink *unk0;
    SpriteOAM *unk4;
} UnkSpriteLink;

// size: 0x808
typedef struct SpriteList
{
    UnkSpriteLink sprites[256];
    u32 unk800;
    u32 unk804;
} SpriteList;

// size: 0xC
typedef struct unkStruct_20266B0
{
    /* 0x0 */ s32 byteCount;
    /* 0x4 */ const void *src;
    /* 0x8 */ void *dest;
} unkStruct_20266B0;

void AddAxSprite(const ax_pose *axPose, const axdata1 *axData, const ax_sprite *axSprite, unkStruct_2039DB0 *spriteMasks);
void AddSprite(SpriteOAM *, s32, ax_sprite *, unkStruct_2039DB0 *spriteMasks);
void AxResInit(axdata *, axmain *, u32, u32 direction, u32, u32 spriteAnimIndex, bool8);
void AxResInitFile(axdata *, OpenedFile *, u32, u32, u32, u32 spriteAnimIndex, bool8);
void AxResInitUnorientedFile(axdata *, OpenedFile *, u32, u32, u32 spriteAnimIndex, bool8);
void BlinkSavingIcon(void);
void CopySpritesToOam(void);
void DoAxFrame_800558C(axdata *, s32 spriteX, s32 spriteY, u32, u32 paletteNum, unkStruct_2039DB0 *spriteMasks);
void InitSprites(void);
void nullsub_7(DungeonPos *);
void nullsub_8(u32);
void nullsub_9(void);
void nullsub_10(bool8);
void nullsub_11(SpriteOAM *, s32, ax_sprite *, unkStruct_2039DB0 *);
void nullsub_12(void);
void nullsub_13(void);
void nullsub_14(void);
void ResetSprites(bool8);
void RunAxAnimationFrame(axdata *);
void SetSavingIconCoords(DungeonPos *pos);
void sub_8004E8C(unkStruct_2039DB0 *);
void sub_8005180(void);
void sub_8005304(void);
void sub_8005610(OpenedFile *, s32 vramIdx, s32 brightness, const RGB *ramp);
const RGB *sub_8005674(const EfoFileData *, s32 vramIdx);
void sub_800569C(DungeonPos *, axdata *, u8);
void sub_8005700(DungeonPos *dstPos, axdata *axData);
void sub_8005770(s32, const RGB *color, s32 brightness, const RGB *ramp);

static inline bool8 AxFlag8000(axdata *ax)
{
    return (ax->flags & 0x8000) != 0;
}

static inline bool8 AxFlag8000_Not2000(axdata *ax)
{
    if (ax->flags & 0x2000)
        return FALSE;
    else
        return (ax->flags & 0x8000) != 0;
}

#endif // GUARD_SPRITE_H
