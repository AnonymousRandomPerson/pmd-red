#ifndef GUARD_DUNGEON_INFO_H
#define GUARD_DUNGEON_INFO_H

#include "structs/str_dungeon_location.h"

extern const u16 *const gRandomItemsSets[];
extern const u8 gUnknown_8108EC0[];

s32 GetDungeonFloorCount(u8 dungeon);
s32 GetDungeonStartingFloor(u8 dungeon);
const u8 *GetDungeonName1(u8 dungeon);
bool8 IsStairDirectionUp(u8 dungeon);
bool8 IsLevelResetDungeon(u8 dungeon);
u32 GetMaxItemsAllowed(u8 dungeon);
bool8 IsMoneyAllowed(u8 dungeon);
s8 GetRescuesAllowed(u8 dungeon);
bool8 HasCheckpoint(u8 dungeon);
s16 GetRandomMovementChance(u8 dungeon);
void PrintYellowDungeonNametoBuffer(u8 *buffer, DungeonLocation *dungeonLocation);
void PrintDungeonLocationtoBuffer(u8 *buffer, DungeonLocation *dungeonLocation);

void GeneralizeMazeDungeonLoc(DungeonLocation *dst, const DungeonLocation *src);

#define DUNGEON_REQUIREMENTS_PASS 0
#define DUNGEON_REQUIREMENTS_FAIL 1
#define DUNGEON_REQUIREMENTS_ASK 2

u32 BufferDungeonRequirementsText(u8 dungeonIndex, s32 speciesId_, u8 *buffer, bool32 param_4_, bool32 param_5_);
u32 GetDungeonLocMissionDifficulty(DungeonLocation *dungeon);
u8 GetRandomItemForValidDungeonLoc(DungeonLocation *dungeon, u32 param_2);
bool8 IsNotValidDungeon(u8 dungeon);
u8 IsRecruitingEnabled(u8 dungeon);

#endif // GUARD_DUNGEON_INFO_H
