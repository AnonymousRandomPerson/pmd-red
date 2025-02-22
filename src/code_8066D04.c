#include "global.h"
#include "code_8045A00.h"
#include "dungeon_message.h"
#include "code_807CD9C.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_music.h"
#include "dungeon_util.h"
#include "items.h"
#include "string_format.h"

extern u8 *gUnknown_80F8BE0[];
extern u8 *gItemStickyCannotMove1[];
extern u8 *gItemStickyCannotMove2[];
extern u8 *gItemStickyCannotEquip[];
extern u8 *gMonTookAndReturnedItem[];
extern u8 *gUnknown_80F8CE4[];
extern u8 *gUnknown_80F8CE8[];
extern u8 *gUnknown_80F8D04[];
extern u8 *gUnknown_80F8D20[];
extern u8 *gUnknown_80F8D44[];
extern u8 *gUnknown_80F8D60[];
extern u8 *gUnknown_80F8D7C[];
extern u8 *gUnknown_80F8DB4[];
extern u8 *gUnknown_80F8DE0[];
extern u8 *gUnknown_80F8E04[];
extern u8 *gUnknown_80F8E28[];

extern Item *sub_8044D90(Entity *, s32, u32);
void sub_8045BF8(u8 *, Item *);
u8 sub_80460F8(DungeonPos *, Item *, u32);
extern void sub_807AB38(Entity *, u32);
extern Entity * sub_8044DA4(Entity *param_1,int param_2);
extern void sub_806A6E8(Entity *);
extern void sub_8044DF0(Entity *, u32, u32);
extern void sub_8045DB4(DungeonPos *, u32);

void HandlePickUpPlayerAction(Entity *entity)
{
  GetEntInfo(entity)->action.actionParameters[0].actionUseIndex = 1;
  sub_8045DB4(&entity->pos,0);
}

void HandleSetItemAction(Entity *param_1, bool8 param_2)
{
  Item *item;
  Item *itemPtr;
  s32 index;

  item = sub_8044D90(param_1,0,0xfe);
  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    itemPtr = &gTeamInventoryRef->teamItems[index];
    if (((itemPtr->flags & ITEM_FLAG_EXISTS)) && ((itemPtr->flags & ITEM_FLAG_SET))) {
      if ((itemPtr->flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatBuffer_Items[0],itemPtr);
        LogMessageByIdWithPopupCheckUser(param_1,*gItemStickyCannotEquip);
        return;
      }
      itemPtr->flags &= ~(ITEM_FLAG_SET);
    }
  }
  sub_8045BF8(gFormatBuffer_Items[0],item);
  PlaySoundEffect(0x133);
  if (param_2 != 0) {
    if ((item->flags & ITEM_FLAG_STICKY)) {
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8D04);
    }
    else {
      if (GetItemCategory(item->id) == CATEGORY_THROWN_LINE) {
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8CE4);
      }
      else
      {
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8CE8);
      }
    }
  }
  item->flags |= ITEM_FLAG_SET;
  if (((item->flags & ITEM_FLAG_STICKY)) && (param_2 != 0)) {
    sub_8045BF8(gFormatBuffer_Items[0],item);
    LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8BE0);
  }
}


void HandleUnsetItemAction(Entity *entity,bool8 enableMessage)
{
  Item *item;
  int index;

  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    item = &gTeamInventoryRef->teamItems[index];
    if (((item->flags & ITEM_FLAG_EXISTS)) && ((item->flags & ITEM_FLAG_SET))) {
      if ((item->flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatBuffer_Items[0],item);
        LogMessageByIdWithPopupCheckUser(entity,*gItemStickyCannotEquip);
        return;
      }
      item->flags &= ~(ITEM_FLAG_SET);
      sub_8045BF8(gFormatBuffer_Items[0],item);
      PlaySoundEffect(0x133);
      if (enableMessage) {
        LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8D20);
      }
    }
  }
}


void HandleGiveItemAction(Entity *param_1)
{
  Entity *entity;
  Item *item;
  EntityInfo *info1;
  EntityInfo *info2;
  bool8 bVar3;
  Item item1;
  Item item2;
  Item item3;

  entity = sub_8044DA4(param_1,1);
  info1 = GetEntInfo(param_1);
  info2 = GetEntInfo(entity);
  item = sub_8044D90(param_1,0,2);

  if((info1->action).actionParameters[0].actionUseIndex == 0x80)
      bVar3 = TRUE;
  else
      bVar3 = FALSE;

  if ((!bVar3) && ((item->flags & (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) == (ITEM_FLAG_STICKY | ITEM_FLAG_SET))) {
    sub_8045BF8(gFormatBuffer_Items[1],item);
    LogMessageByIdWithPopupCheckUser(param_1,*gItemStickyCannotMove2);
  }
  else
  {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],entity,0);
    if (((info2->heldItem).flags & ITEM_FLAG_EXISTS)) {
     if (((info2->heldItem).flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatBuffer_Items[1],&info2->heldItem);
        LogMessageByIdWithPopupCheckUser(param_1,*gItemStickyCannotMove1);
        return;
      }
      item1 = (info2->heldItem);
      item2 = *item;
      item1.flags &= ~(ITEM_FLAG_SET);
      item2.flags &= ~(ITEM_FLAG_SET);
      sub_8044DF0(param_1,0,100);
      if (bVar3) {
        sub_80460F8(&param_1->pos,&item1,1);
      }
      else {
        AddItemToInventory(&item1);
      }
      info2->heldItem = item2;
      sub_8045BF8(gFormatBuffer_Items[0],&item2);
      sub_8045BF8(gFormatBuffer_Items[1],&item1);
      PlaySoundEffect(0x14d);
      LogMessageByIdWithPopupCheckUser(param_1,*gMonTookAndReturnedItem);
      if ((item2.flags & ITEM_FLAG_STICKY)) {
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8BE0);
      }
    }
    else {
      item3 = *item;
      item3.flags &= ~(ITEM_FLAG_SET);
      sub_8044DF0(param_1, 0, 101);
      info2->heldItem = item3;
      sub_8045BF8(gFormatBuffer_Items[0],&item3);
      PlaySoundEffect(0x14d);
      LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8D44);
      if ((item3.flags & ITEM_FLAG_STICKY)) {
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8BE0);
      }
    }
    sub_806A6E8(entity);
    if (sub_80706A4(entity,&entity->pos) != 0) {
      WarpTarget(param_1,entity,0,0);
    }
    if (!info2->isTeamLeader) {
      info2->flags = info2->flags | MOVEMENT_FLAG_UNK_14;
    }
    sub_807AB38(param_1,gDungeon->forceMonsterHouse);
  }
}


void HandleTakeItemAction(Entity *param_1)
{
  Entity *entity;
  EntityInfo *info;
  Item *heldItem;
  Item item;

  entity = sub_8044DA4(param_1,0);
  info = GetEntInfo(entity);
  heldItem = &info->heldItem;
  if (ItemExists(&gTeamInventoryRef->teamItems[ITEM_POWER_BAND])) {
    LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8D60);
  }
  else
  {
    if (ItemSticky(heldItem)) {
        sub_8045BF8(gFormatBuffer_Items[0],heldItem);
        LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8BE0);
    }
    else
    {
      item = *heldItem;
      item.flags &= ~(ITEM_FLAG_SET);
      sub_8045BF8(gFormatBuffer_Items[0],&item);
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],entity,0);
      ZeroOutItem(heldItem);
      AddItemToInventory(&item);
      PlaySoundEffect(0x14d);
      LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8D7C);
      sub_806A6E8(entity);
      if (sub_80706A4(entity,&entity->pos) != 0) {
        WarpTarget(param_1,entity,0,0);
      }
      if (!info->isTeamLeader) {
        info->flags |= MOVEMENT_FLAG_UNK_14;
      }
      sub_807AB38(param_1,gDungeon->forceMonsterHouse);
    }
  }
}

void sub_8066BD4(Entity *param_1)
{
  Entity *entity;
  EntityInfo *info;
  Item *item;
  Item *heldItem;
  Item temp;

  entity = sub_8044DA4(param_1,0);
  info = GetEntInfo(entity);
  heldItem = &info->heldItem;
  item = sub_8044D90(param_1,1,0x1565);
  if (heldItem->flags & ITEM_FLAG_STICKY)
  {
    sub_8045BF8(gFormatBuffer_Items[0],heldItem);
    LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8BE0);
  }
  else if ((item->flags & (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) == (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) {
    sub_8045BF8(gFormatBuffer_Items[0],item);
    LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8BE0);
  }
  else
  {
    heldItem->flags &= ~(ITEM_FLAG_SET);
    item->flags &= ~(ITEM_FLAG_SET);
    sub_8045BF8(gFormatBuffer_Items[0],heldItem);
    sub_8045BF8(gFormatBuffer_Items[1],item);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],entity,0);
    temp = info->heldItem;
    info->heldItem = *item;
    *item = temp;
    PlaySoundEffect(0x14d);
    LogMessageByIdWithPopupCheckUser(param_1,*gUnknown_80F8DB4);
    if (sub_80706A4(entity,&entity->pos) != 0) {
      WarpTarget(param_1,entity,0,0);
    }
    if (!info->isTeamLeader) {
      info->flags = info->flags | MOVEMENT_FLAG_UNK_14;
    }
    sub_807AB38(param_1,gDungeon->forceMonsterHouse);
  }
}

void HandleUseItemAction(Entity *param_1)
{
  Entity *entity;

  entity = sub_8044DA4(param_1,0);
  GetEntInfo(entity)->useHeldItem = TRUE;
}

void HandlePlaceItemAction(Entity *entity)
{
    EntityInfo *info = GetEntInfo(entity);
    Item *item = sub_8044D90(entity,0,4);

    sub_8045BF8(gFormatBuffer_Items[0],item);
    if (info->action.actionParameters[0].actionUseIndex == 0x80) {
        LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8DE0);
    }
    else if (info->action.actionParameters[0].actionUseIndex < 0x15 && (item->flags & (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) == (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) {
        LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8BE0);
    }
    else if (info->action.actionParameters[0].actionUseIndex == 0x81 && (item->flags & ITEM_FLAG_STICKY)) {
        LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8BE0);
    }
    else {
        const Tile *tile = GetTile(entity->pos.x, entity->pos.y);
        if ((tile->terrainType & TERRAIN_TYPE_STAIRS)) {
            LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8E04);
        }
        else if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL) {
            LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8E04);
        }
        else if (tile->object != NULL) {
            LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8E04);
        }
        else {
            item->flags &= ~(ITEM_FLAG_SET);
            sub_8045BF8(gFormatBuffer_Items[0],item);
            if (sub_80460F8(&entity->pos,item,1) == 0) {
                LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8E04);
            }
            else {
                ZeroOutItem(item);
                FillInventoryGaps();
                PlaySoundEffect(0x14d);
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],entity,0);
                LogMessageByIdWithPopupCheckUser(entity,*gUnknown_80F8E28);
                sub_807AB38(entity,gDungeon->forceMonsterHouse);
            }
        }
    }
}
