#ifndef GUARD_DUNGEON_MAP_ACCESS_H
#define GUARD_DUNGEON_MAP_ACCESS_H

#include "structs/map.h"

const Tile *GetTile(s32 x, s32 y);
Tile *GetTileMut(s32 x, s32 y);

void UpdateTrapsVisibility(void);
void DiscoverMinimap(DungeonPos *pos);

void sub_80495E4(void);
void LoadDungeonTilesetAssets(void);
void sub_8049820(void);
void sub_8049840(void);
void sub_8049884(void);
void sub_80498A8(s32 x, s32 y);
void sub_8049B8C(void);
void sub_8049BB0(s32 x, s32 y);
void sub_804A1F0(s32 a0, s32 a1);
void sub_804A49C(s32 a0, s32 a1);
void ChangeDungeonCameraPos(DungeonPos *pos, s32 a1, u8 a2, u8 a3);
void sub_804AA60(void);
void sub_804AAAC(void);
void sub_804AAD4(void);

#define DUNGEON_WATER_TYPE_NONE 0
#define DUNGEON_WATER_TYPE_LAVA 1
#define DUNGEON_WATER_TYPE_WATER 2

extern const u8 gDungeonWaterType[76];

bool8 sub_804AD34(DungeonPos *pos);
void sub_804AE84(DungeonPos *pos);
bool8 IsTileGround(Tile *tile);
bool8 IsWaterTileset(void);

#endif // GUARD_DUNGEON_MAP_ACCESS_H
