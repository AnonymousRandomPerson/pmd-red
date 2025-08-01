#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "constants/wonder_mail.h"
#include "structs/str_802C39C.h"
#include "code_800D090.h"
#include "music_util.h"
#include "code_8094F88.h"
#include "dungeon_info.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "pokemon_mail.h"
#include "text_1.h"
#include "text_3.h"

struct unkStruct_203B324
{
    // size: 0x78
    TouchScreenMenuInput unk0;
    u8 mailIndex;
    u32 windowID;
    WindowTemplate *unk14;
    WindowTemplates unk18;
};

static EWRAM_INIT struct unkStruct_203B324 *gUnknown_203B324 = {NULL};

extern unkStruct_203B480 *gUnknown_203B480;


const WindowTemplate gUnknown_80E0900 = {
    0,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const WindowHeader gUnknown_80E0918 = {0x01, 0x00, 0x12, 0x00};

const WindowTemplate gUnknown_80E091C = {
    0,
    0x06,
    0x02, 0x02,
    0x1A, 0x10,
    0x10, 0x00,
    &gUnknown_80E0918
};

const u8 gUnknown_80E0934[] = "ID:";
const u8 gUnknown_80E0938[] = "%-4d";

extern void sub_8030DD4(void);

void sub_8030E2C(void);
void sub_8030E48(void);

bool8 sub_8030D40(u8 mailIndex, s32 windowID)
{
  gUnknown_203B324 = MemoryAlloc(sizeof(struct unkStruct_203B324), 8);
  gUnknown_203B324->mailIndex = mailIndex;
  ResetTouchScreenMenuInput(&gUnknown_203B324->unk0);
  gUnknown_203B324->windowID = windowID;
  gUnknown_203B324->unk14 = &gUnknown_203B324->unk18.id[windowID];
  RestoreSavedWindows(&gUnknown_203B324->unk18);
  gUnknown_203B324->unk18.id[gUnknown_203B324->windowID] = gUnknown_80E091C;
  sub_8030DD4();
  return TRUE;
}

u32 sub_8030DA0(void)
{
  switch(sub_8012A64(&gUnknown_203B324->unk0, gUnknown_203B324->windowID))
  {
    case INPUT_B_BUTTON:
        PlayMenuSoundEffect(1);
        return 2;
    case INPUT_A_BUTTON:
        PlayMenuSoundEffect(0);
        return 3;
    default:
        return 0;
  }
}

void sub_8030DD4(void)
{
    sub_8030E2C();
    sub_8030E48();
}

void sub_8030DE4(void)
{
  if(gUnknown_203B324 != NULL)
  {
      gUnknown_203B324->unk18.id[gUnknown_203B324->windowID] = gUnknown_80E0900;
      ResetUnusedInputStruct();
      ShowWindows(&gUnknown_203B324->unk18, TRUE, TRUE);
      MemoryFree(gUnknown_203B324);
      gUnknown_203B324 = NULL;
  }
}

void sub_8030E2C(void)
{
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B324->unk18, TRUE, TRUE);
}

void sub_8030E48(void)
{
  u16 uVar2;
  unkStruct_203B480 *mail;
  unkStruct_802C39C stack;
  u8 buffer [256];

  mail = &gUnknown_203B480[gUnknown_203B324->mailIndex];
  sub_80073B8(gUnknown_203B324->windowID);
  stack.unk0[0] = gUnknown_203B324->windowID;
  stack.mailTitleType = 7;
  stack.mailMissionType = MISSION_TYPE_FRIEND_RESCUE;
  stack.mailStatus = MAIL_STATUS_SUSPENDED;
  stack.dungeonSeed = &mail->dungeonSeed;
  stack.playerName = mail->playerName;
  stack.clientSpecies = mail->clientSpecies;
  stack.targetSpecies = mail->clientSpecies;
  stack.targetItem = ITEM_NOTHING;
  if (mail->item.id == ITEM_NOTHING) {
    stack.unk18.rewardType = MONEY1;
  }
  else {
    stack.unk18.rewardType = ITEM;
    stack.unk18.itemRewards[0] = mail->item.id;
  }
  switch(mail->mailType)
  {
    case WONDER_MAIL_TYPE_SOS_1:
    case WONDER_MAIL_TYPE_AOK:
        stack.mailDescriptionType = 10;
        break;
    case WONDER_MAIL_TYPE_THANK_YOU:
        stack.mailDescriptionType = 11;
        break;
    case WONDER_MAIL_TYPE_NONE:
    default:
        stack.mailDescriptionType = 9;
        break;
  }
  CreateRescueDescription(&stack);
  uVar2 = mail->unk10.unk10_u16 % 10000;
  PrintStringOnWindow(10,0x68,gUnknown_80E0934,gUnknown_203B324->windowID,0); // ID:
  sprintfStatic(buffer,gUnknown_80E0938,uVar2); // %-4d
  PrintStringOnWindow(0x44,0x68,buffer,gUnknown_203B324->windowID,0);
  sub_80073E0(gUnknown_203B324->windowID);
}
