#include "global.h"
#include "globaldata.h"
#include "move_orb_actions_1.h"
#include "dungeon_move_util.h"
#include "dungeon_vram.h"
#include "code_803E724.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "code_807CD9C.h"
#include "dungeon_random.h"
#include "constants/ability.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_logic.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_move.h"
#include "move_effects_target.h"
#include "moves.h"
#include "number_util.h"
#include "pokemon.h"
#include "status.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "weather.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_strings.h"

extern void sub_806A5B8(Entity *entity);
void sub_8075900(Entity *pokemon, u8 r1);
extern void sub_807EC28(bool8);
extern void sub_806F370(Entity *r0, Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void CalcDamage(Entity *, Entity *, u8, u32, u32, s32 *, u32, u16, u32);
extern void MudWaterSportEffect(u32);
extern void CalcDamage(Entity *, Entity *, u8, u32, u32, s32 *, u32, u16, u32);
extern void sub_806A6E8(Entity *);

extern void EndAbilityImmuneStatus(Entity *, Entity *);
extern u8 sub_806F4A4(Entity *, u32);
extern void HandleExplosion(Entity *pokemon, Entity *target, DungeonPos *pos, u32, u8 moveType, s16);
extern void nullsub_92(Entity *);
extern u8 sub_807EAA0(u32, u32);

// move_util.h
extern bool8 sub_805727C(Entity *, Entity *, s32);
bool8 RollSecondaryEffect(Entity *pokemon, s32 chance);
bool8 sub_80571F0(Entity * pokemon, Move *move);

extern void sub_806F370(Entity *r0, Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern void DealDamageToEntity(Entity *, s32, u32, u32);
extern s16 sub_8057600(Move *move, s32 itemID);

// Note: For some reason I have to define these as an array of 1 to match asm.
const s32 gUnknown_8106A4C[1] = {0};
const s32 gUnknown_8106A50[1] = {1};

bool8 IronTailMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;
    if (HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0) {
        flag = TRUE;
        if (sub_805727C(pokemon, target, gIronTailSecondaryChance)) {
            LowerDefenseStageTarget(pokemon, target, gUnknown_8106A4C[0], 1, 1, FALSE);
        }
    }
    return flag;
}

static const s24_8 sRolloutModifiers[] = {
    IntToF248_2(1.0), IntToF248_2(1.0), IntToF248_2(1.5), IntToF248_2(2.0), IntToF248_2(2.5), IntToF248_2(3.0), IntToF248_2(3.5), IntToF248_2(4.0), IntToF248_2(4.5), IntToF248_2(5.0)
};

bool8 sub_805768C(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    bool8 flag;

    flag = FALSE;
    gUnknown_202F21C++;

    if (HandleDamagingMove(pokemon, target, move, sRolloutModifiers[gUnknown_202F21C], param_4) == 0)
        gUnknown_202F220 = 1;
    else
        flag = TRUE;
    return flag;
}

bool8 YawnMoveAction(Entity * pokemon, Entity *target, Move *move, s32 param_4)
{
    YawnedStatusTarget(pokemon, target, CalculateStatusTurns(target,gYawnTurnRange,TRUE) + 1);
    return TRUE;
}

// NOTE: Is there a better name for this?
bool8 BasicSleepMoveAction(Entity * pokemon, Entity *target, Move *move, s32 param_4)
{
    SleepStatusTarget(pokemon, target, CalculateStatusTurns(target, gSleepTurnRange, TRUE), TRUE);
    return TRUE;
}

bool8 NightmareMoveAction(Entity * pokemon, Entity *target, Move *move, s32 param_4)
{
    NightmareStatusTarget(pokemon, target, CalculateStatusTurns(target,gNightmareTurnRange,TRUE));
    return TRUE;
}

bool8 MorningSunMoveAction(Entity * pokemon,Entity * target, Move *move, s32 param_4)
{
    HealTargetHP(pokemon, target, gMorningSunHealValueByWeather[GetApparentWeather(pokemon)], 0, TRUE);
    return TRUE;
}

bool8 VitalThrowMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    VitalThrowStatusTarget(pokemon, target);
    return TRUE;
}

bool8 DigMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    Tile *tile;
    bool8 flag;

    flag = FALSE;
    tile = GetTileAtEntitySafe(pokemon);
    if ((!IsTileGround(tile)) || ((tile->terrainFlags & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) != 1)) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD14C); // It can only be used on land!
    }
    else {
        if (MoveMatchesBideClassStatus(pokemon,move)) {
            HandleDamagingMove(pokemon,target,move,gDigModifier,param_4);
            sub_8079764(pokemon);
        }
        else {
            SetChargeStatusTarget(pokemon,pokemon,STATUS_DIGGING,move,gUnknown_80FAD4C); // $m0 burrowed underground!
        }
        flag = TRUE;
    }
    return flag;
}

bool8 SweetScentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  LowerAccuracyStageTarget(pokemon,target,gUnknown_8106A50[0],TRUE);
  return TRUE;
}

bool8 CharmMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  ChangeAttackMultiplierTarget(pokemon,target,gUnknown_8106A4C[0],FloatToF248(0.5),TRUE);
  return TRUE;
}

bool8 RainDanceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  gDungeon->weather.unkE267[WEATHER_RAIN] = gMoveWeatherDuration;
  if (sub_807EAA0(1,0) == 0) {
    // The weather remains unchanged
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCF74);
  }
  return TRUE;
}

bool8 HailMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  gDungeon->weather.unkE267[WEATHER_HAIL] = gMoveWeatherDuration;
  if (sub_807EAA0(1,0) == 0) {
    // The weather remains unchanged
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCF80);
  }
  return TRUE;
}

bool8 sub_80578EC(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    sub_8079F20(pokemon, target, 1, 0);
    return TRUE;
}

bool8 BubbleMoveAction(Entity *pokemon, Entity *target, Move * move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,target, gBubbleSecondaryChance)) {
      LowerMovementSpeedTarget(pokemon, target, 1, FALSE);
    }
  }
  return flag;
}

bool8 EncoreMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    EncoreStatusTarget(pokemon, target);
    return TRUE;
}

bool8 RageMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  // {POKEMON_0} is enraged
  SetChargeStatusTarget(pokemon,target,STATUS_ENRAGED,move,gUnknown_80FAC88);
  return TRUE;
}

bool8 SuperFangMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  s32 newHP;
  bool8 local_24;

  newHP = GetEntInfo(target)->HP / 2;
  local_24 = FALSE;
  if (newHP != 0) {
    sub_806F370(pokemon,target,newHP,1,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_24 = local_24 == 0;
  }
  else
  {
    // The target's HP can't be halved anymore
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD018);
  }
  return local_24;
}

bool8 PainSplitMoveAction(Entity *attacker, Entity *target, Move *move, s32 param_4)
{
    EntityInfo *attackerInfo = GetEntInfo(attacker);
    EntityInfo *targetInfo = GetEntInfo(target);
    s32 newHP = (attackerInfo->HP + targetInfo->HP) / 2;

    attackerInfo->HP = newHP;
    targetInfo->HP = newHP;
    if (attackerInfo->HP > attackerInfo->maxHPStat) {
        attackerInfo->HP = attackerInfo->maxHPStat;
    }
    if (targetInfo->HP > targetInfo->maxHPStat) {
        targetInfo->HP = targetInfo->maxHPStat;
    }
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],attacker,0);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],target,0);
    SetExpMultplier(attackerInfo);

    // $m0 and $m1 shared their HP
    TryDisplayDungeonLoggableMessage3(attacker,target,gUnknown_80FC7EC);
    return TRUE;
}

bool8 TormentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  Move *movePtr;
  s32 iVar4;
  Move struggleMove;
  EntityInfo *entityInfo;
  bool8 isTormented;

  entityInfo = GetEntInfo(target);
  isTormented = FALSE;

  for(iVar4 = 0; iVar4 < MAX_MON_MOVES; iVar4++)
  {
    movePtr = &entityInfo->moves.moves[iVar4];
    if ((movePtr->moveFlags & MOVE_FLAG_EXISTS) != 0) {
      if ((movePtr->moveFlags & MOVE_FLAG_DISABLED) == 0) {
        if ((movePtr->moveFlags & MOVE_FLAG_LAST_USED) != 0) {
          BufferMoveName(gFormatBuffer_Items[0],movePtr,0);
          // $i0 was tormented
          TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCFBC);
          movePtr->moveFlags |= MOVE_FLAG_DISABLED;
          isTormented = TRUE;
        }
      }
      else if ((movePtr->moveFlags & MOVE_FLAG_LAST_USED) == 0) {
        movePtr->moveFlags &= ~(MOVE_FLAG_DISABLED);
      }
    }
  };

  if ((entityInfo->moves.struggleMoveFlags & MOVE_FLAG_DISABLED) == 0) {
    if ((entityInfo->moves.struggleMoveFlags & MOVE_FLAG_LAST_USED) != 0) {
      InitPokemonMove(&struggleMove, MOVE_STRUGGLE);
      entityInfo->moves.struggleMoveFlags |= MOVE_FLAG_DISABLED;
      isTormented = TRUE;
      BufferMoveName(gFormatBuffer_Items[0],&struggleMove,0);
      // $i0 was tormented
      TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCFBC);
    }
  }
  else if ((entityInfo->moves.struggleMoveFlags & MOVE_FLAG_LAST_USED) == 0) {
    entityInfo->moves.struggleMoveFlags &= ~(MOVE_FLAG_DISABLED);
  }
  if (isTormented)
  {
    if(entityInfo->bideClassStatus.status == STATUS_BIDE) {
        entityInfo->bideClassStatus.status = STATUS_NONE;
    }
  }
  else
  {
    // The target couldn't be tormented
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FCFE4);
  }
  return isTormented;
}

bool8 StringShotMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    LowerMovementSpeedTarget(pokemon, target, 1, TRUE);
    return TRUE;
}

bool8 SwaggerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C[0], 2);
    return TRUE;
}

bool8 SnoreMoveAction(Entity *pokemon, Entity *target, Move * move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (IsSleeping(pokemon)) {
    if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
      flag = TRUE;
      if (sub_805727C(pokemon,target,gSnoreSecondaryChance)) {
        CringeStatusTarget(pokemon,target,FALSE);
      }
    }
  }
  else {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FC734);
  }
  return flag;
}

bool8 ScreechMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    ChangeDefenseMultiplierTarget(pokemon, target, gUnknown_8106A4C[0], FloatToF248(0.25), 1);
    return TRUE;
}

bool8 RockSlideMoveAction(Entity *pokemon, Entity *target, Move * move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,target,gRockSlideSecondaryChance)) {
      CringeStatusTarget(pokemon,target,FALSE);
    }
  }
  return flag;
}

bool32 WeatherBallMoveAction(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
  u32 weather;
  s32 flag;

  weather = GetApparentWeather(pokemon);
  flag = sub_80556BC(pokemon,target,gWeatherBallTypes[weather],move,
                      gWeatherBallModifiers[weather],param_4);
  if (flag) {
    flag = TRUE;
  }
  return flag;
}

bool8 WhirlpoolMoveAction(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
  s24_8 modifier;
  bool8 flag;
  u8 chargeStatus;

  flag = FALSE;
  chargeStatus = GetEntInfo(target)->bideClassStatus.status;
  modifier = IntToF248_2(1);
  if (chargeStatus == STATUS_DIVING) {
    modifier = IntToF248_2(2);
  }
  if (HandleDamagingMove(pokemon,target,move,modifier,param_4) != 0) {
    flag = TRUE;
    if (sub_805727C(pokemon,target,gMovesConstrictionChance)) {
      SqueezedStatusTarget(pokemon,target,0x3b,FALSE);
    }
  }
  return flag;
}

bool8 FakeTearsMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
  LowerDefenseStageTarget(pokemon, target, gUnknown_8106A50[0], 2, 1, TRUE);
  return TRUE;
}

bool8 SpiteMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    s32 i;
    EntityInfo *targetInfo = GetEntInfo(target);
    bool8 flag = FALSE;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        Move *move = &targetInfo->moves.moves[i];
        if (MoveFlagExists(move) && MoveFlagLastUsed(move)) {
            move->PP = 0;
            flag = TRUE;
        }
    }

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], target, 0);
    if (flag) {
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FD350);
    }
    else {
        TryDisplayDungeonLoggableMessage3(pokemon, target, gUnknown_80FD370);
    }

    return flag;
}

bool8 FocusEnergyMoveAction(Entity * pokemon, Entity * target, Move *move, s32 param_4)
{
    FocusEnergyStatusTarget(pokemon, target);
    return TRUE;
}

bool8 SmokescreenMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    WhifferStatusTarget(pokemon, target, CalculateStatusTurns(target, gWhifferTurnRange, TRUE));
    return TRUE;
}

bool8 MirrorMoveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    SendThawedMessage(pokemon, target);
    MirrorMoveStatusTarget(pokemon, target);
    return TRUE;
}

bool8 OverheatMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  EntityInfo *entityInfo;
  bool8 flag;

  flag = FALSE;
  entityInfo = GetEntInfo(pokemon);
  SendThawedMessage(pokemon,target);
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if (RollSecondaryEffect(pokemon, 0)) {
      entityInfo->unk155 = 1;
    }
  }
  return flag;
}

bool8 AuroraBeamMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gAuroraBeamAtkLowerChance))
    {
        ChangeAttackMultiplierTarget(pokemon, target, gUnknown_8106A4C[0], FloatToF248(0.5), FALSE);
    }
  }
  return flag;
}

bool8 MementoMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  EntityInfo *entityInfo;

  entityInfo = GetEntInfo(pokemon);
  entityInfo->HP = 1;
  ChangeAttackMultiplierTarget(pokemon,target,gUnknown_8106A4C[0],FloatToF248(0.25),TRUE);
  ChangeAttackMultiplierTarget(pokemon,target,gUnknown_8106A50[0],FloatToF248(0.25),TRUE);
  entityInfo->unk154 = 1;
  return TRUE;
}

bool8 OctazookaMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gOctazookaAccLowerChance))
    {
        LowerAccuracyStageTarget(pokemon, target, gUnknown_8106A4C[0], FALSE);
    }
  }
  return flag;
}

bool8 FlatterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A50[0], 1);
    return TRUE;
}

bool8 WillOWispMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  u8 flashFireStatus;

  flashFireStatus = GetFlashFireStatus(target);
  if (flashFireStatus != FLASH_FIRE_STATUS_NONE) {
    if (GetEntInfo(target)->unk152 == 0) {
      GetEntInfo(target)->unk152 = 1;
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],target,0);
      if (flashFireStatus == FLASH_FIRE_STATUS_MAXED) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FAE00); // Fire moves won't become stronger
      }
      else {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FADD8); // $m0 used flash fire to absorb fire
      }
    }
  }
  else {
    BurnedStatusTarget(pokemon,target, 0, TRUE);
  }
  return TRUE;
}

bool8 ReturnMoveAction(Entity * pokemon,Entity * target,Move * move,s32 param_4)
{
    s32 i;
    bool8 local_24;
    EntityInfo *entityInfo = GetEntInfo(pokemon);
    s32 dmg = 1;

    for (i = 0; i < 999 && gReturnDmgData[i].minIq >= 0; i++) {
        if (entityInfo->IQ < gReturnDmgData[i].minIq) {
            dmg = gReturnDmgData[i].dmgVal;
            break;
        }
    }

    sub_806F370(pokemon,target,dmg,1,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);
    local_24 = (local_24 == 0);
    return local_24;
}

bool8 GrudgeMoveAction(Entity *pokemon, Entity * target, Move *move, s32 param_4)
{
  EntityInfo *entityInfo;
  bool8 hasGrudge;

  hasGrudge = FALSE;
  entityInfo = GetEntInfo(target);
  SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],target,0);
  if (entityInfo->grudge) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD2B4);
  }
  else {
    entityInfo->grudge = TRUE;
    hasGrudge = TRUE;
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD294);
  }
  return hasGrudge;
}

bool8 CounterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    CounterStatusTarget(pokemon, target, STATUS_COUNTER);
    return TRUE;
}

bool8 FlameWheelMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  SendThawedMessage(pokemon, target);
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gFlameWheelSecondaryChance))
    {
        BurnedStatusTarget(pokemon, target, 0, FALSE);
    }
  }
  return flag;
}

// NOTE: Do we have a better name for this??
bool8 BasicFireMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  SendThawedMessage(pokemon, target);
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gFireMoveBurnSecondaryChance))
    {
        BurnedStatusTarget(pokemon, target, 0, FALSE);
    }
  }
  return flag;
}

bool8 ExposeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    u16 uVar1;
    uVar1 = (move->id == MOVE_FORESIGHT) ? 0x7A : 0x51;
    ExposeStatusTarget(pokemon, target, uVar1);
    return TRUE;
}

bool8 DoubleTeamMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    RaiseAccuracyStageTarget(pokemon, target, gUnknown_8106A50[0]);
    return TRUE;
}

bool8 GustMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 flag;
  s32 modifierInt;
  EntityInfo *targetInfo;

  modifierInt = 1;
  targetInfo = GetEntInfo(target);
  if(targetInfo->bideClassStatus.status == STATUS_FLYING || targetInfo->bideClassStatus.status == STATUS_BOUNCING)
    modifierInt = 2;
  flag =  HandleDamagingMove(pokemon,target,move,IntToF248_2(modifierInt),param_4) ? TRUE : FALSE;
  return flag;
}

// NOTE: Is there a better name for this?
bool8 BasicRaiseDefenseMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A4C[0], 1);
    return TRUE;
}

bool8 DisableMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    ParalyzeStatusTarget(pokemon, target, TRUE);
    return TRUE;
}

// NOTE: Is there a better name for this?
bool8 BasicRaiseAttackMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    RaiseAttackStageTarget(pokemon, target, gUnknown_8106A4C[0], 1);
    return TRUE;
}

bool8 RazorWindMoveAction(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
  bool8 flag;

  if (MoveMatchesBideClassStatus(pokemon,move)) {
    flag = HandleDamagingMove(pokemon,target,move,gRazorWindModifier,param_4) ? TRUE : FALSE;
    sub_8079764(pokemon);
  }
  else {
    SetChargeStatusTarget(pokemon,pokemon,STATUS_RAZOR_WIND,move,gUnknown_80FAC54);
    flag = TRUE;
  }
  return flag;
}

bool8 BideMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
   SetChargeStatusTarget(pokemon, target, STATUS_BIDE, move, gUnknown_80FAC74);
   return TRUE;
}

bool8 Bide2MoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  s32 iVar2;
  bool8 local_18;

  local_18 = FALSE;
  iVar2 = GetEntInfo(pokemon)->unkA0 * 2;
  if (999 < iVar2) {
    iVar2 = 999;
  }
  sub_806F370(pokemon,target,iVar2,1,&local_18, GetMoveType(move),0x1ff,0,1,0);

  local_18 = local_18 == 0;
  return local_18;
}

bool8 ShadowBallMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gShadowBallSecondaryChance))
    {
        LowerDefenseStageTarget(pokemon, target, gUnknown_8106A50[0], 1, 1, FALSE);
    }
  }
  return flag;
}

bool8 BiteMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gBiteSecondaryChance))
    {
        CringeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 ThunderMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gThunderSecondaryChance))
    {
        ParalyzeStatusTarget(pokemon, target, FALSE);
    }
  }
  return flag;
}

bool8 EndeavorMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  s32 diffHP;
  bool8 local_24;
  EntityInfo *entityInfo;
  EntityInfo *entityInfo1;


  local_24 = 0;
  entityInfo = GetEntInfo(pokemon);
  entityInfo1 = GetEntInfo(target);
  diffHP = entityInfo1->HP - entityInfo->HP;
  if (diffHP < 0) {
    diffHP = 0;
  }
  sub_806F370(pokemon,target,diffHP,0,&local_24,GetMoveType(move),sub_8057600(move,param_4),0,1,0);

  local_24 = local_24 == 0;
  return local_24;
}

bool8 FacadeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 flag;
  s24_8 modifier;

  modifier = IntToF248_2(1);
  if((GetEntInfo(pokemon)->burnClassStatus.status) != STATUS_NONE)
    modifier = gFacadeModifier;
  flag =  HandleDamagingMove(pokemon,target,move,modifier,param_4) ? TRUE : FALSE;
  return flag;
}

bool8 sub_8058580(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, gConstrictBubblebeamSecondaryChance))
    {
        LowerMovementSpeedTarget(pokemon, target, 1, FALSE);
    }
  }
  return flag;
}

bool8 BrickBreakMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if ((GetEntInfo(target)->reflectClassStatus.status == STATUS_REFLECT) || (GetEntInfo(target)->reflectClassStatus.status == STATUS_LIGHT_SCREEN)) {
    TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80FD104); // The barrier was shattered
    EndReflectClassStatus(pokemon,target);
    flag = TRUE;
  }

  flag |= (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0);
  return flag;
}

bool8 RockTombMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
  bool8 flag;

  flag = FALSE;
  if (HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) != 0) {
    flag = TRUE;
    if(sub_805727C(pokemon, target, 0))
    {
        LowerMovementSpeedTarget(pokemon, target, 1, FALSE);
    }
  }
  return flag;
}

bool8 FocusPunchMoveAction(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
  bool8 flag;

  if (MoveMatchesBideClassStatus(pokemon,move)) {
    flag = HandleDamagingMove(pokemon,target,move,gFocusPunchModifier,param_4) ? TRUE : FALSE;
    sub_8079764(pokemon);
  }
  else {
    SetChargeStatusTarget(pokemon,pokemon,STATUS_FOCUS_PUNCH,move,gUnknown_80FACA4);
    flag = TRUE;
  }
  return flag;
}

bool8 GigaDrainMoveAction(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
  bool8 hasLiquidOoze;
  s32 uVar3;
  s32 newHP;
  bool8 flag;
  EntityInfo *entityInfo;

  hasLiquidOoze = AbilityIsActive(target, ABILITY_LIQUID_OOZE);
  uVar3 = HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4);
  flag = uVar3 != 0 ? TRUE : FALSE;
  if (flag && RollSecondaryEffect(pokemon, 0)) {
    newHP = uVar3 / 2;
    entityInfo = GetEntInfo(pokemon);
    flag = TRUE;
    if (newHP < 1) {
      newHP = 1;
    }
    SetExpMultplier(entityInfo);
    if (hasLiquidOoze) {
        DealDamageToEntity(pokemon, newHP, 0xd, 0x1fa);
    }
    else {
        HealTargetHP(pokemon, pokemon, newHP, 0, TRUE);
    }
  }
  return flag;
}

bool8 ReversalMoveAction(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
    s32 index;
    bool8 flag;
    EntityInfo *entityInfo = GetEntInfo(pokemon);
    s32 maxHp = entityInfo->maxHPStat;
    if (entityInfo->HP <= entityInfo->maxHPStat / 4) {
        index = 0;
    }
    else if (entityInfo->HP <= maxHp / 2) {
        index = 1;
    }
    else if (entityInfo->HP <= (maxHp * 3) / 4) {
        index = 2;
    }
    else {
        index = 3;
    }

    flag = HandleDamagingMove(pokemon,target,move,gReversalModifiers[index],param_4) ? TRUE : FALSE;
    return flag;
}

bool8 SmellingSaltMoveAction(Entity * pokemon, Entity * target, Move * move, s32 param_4)
{
  bool8 flag;

  if (GetEntInfo(target)->burnClassStatus.status == STATUS_PARALYSIS) {
    flag = HandleDamagingMove(pokemon,target,move,IntToF248_2(2),param_4) ? TRUE : FALSE;
    EndBurnClassStatus(pokemon, target);
  }
  else {
    flag = HandleDamagingMove(pokemon,target,move,IntToF248_2(1),param_4) ? TRUE : FALSE;
  }
  return flag;
}

bool8 MetalSoundMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    LowerDefenseStageTarget(pokemon, target, gUnknown_8106A50[0], 3, 1, TRUE);
    return TRUE;
}

bool8 TickleMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    s32 index = gUnknown_8106A4C[0];
    LowerAttackStageTarget(pokemon, target, index, 1, 1, TRUE);
    LowerDefenseStageTarget(pokemon, target, index, 1, 1, TRUE);
    return TRUE;
}

bool8 sub_805889C(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    ImmobilizedStatusTarget(pokemon, target);
    return TRUE;
}

bool8 HazeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    sub_8079E34(pokemon, target, TRUE);
    return TRUE;
}

bool8 OutrageMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    bool8 flag = FALSE;
    if(HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0)
    {
        flag = TRUE;
        if(RollSecondaryEffect(pokemon, 0))
        {
            gUnknown_202F219 = 1;
        }
    }
    return flag;
}

bool8 LowKickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    s24_8 weight;
    bool8 flag;
    EntityInfo *entityInfo = GetEntInfo(target);

    weight.raw = GetWeight(entityInfo->apparentID);
    flag = HandleDamagingMove(pokemon, target, move, weight, param_4) != 0 ? TRUE: FALSE;
    return flag;
}

bool8 AncientPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    bool8 flag = FALSE;
    EntityInfo *entityInfo;
    s32 index1;
    s32 index2;
    if(HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0)
    {
        flag = TRUE;
        if(RollSecondaryEffect(pokemon, gAncientPowerSecondaryChance))
        {
            entityInfo = GetEntInfo(pokemon);
            RaiseMovementSpeedTarget(pokemon, pokemon, 0, TRUE);
            index1 = gUnknown_8106A4C[0];
            RaiseAttackStageTarget(pokemon, pokemon, index1, 1);
            index2 = gUnknown_8106A50[0];
            RaiseAttackStageTarget(pokemon, pokemon, index2, 1);
            RaiseDefenseStageTarget(pokemon, pokemon, index1, 1);
            RaiseDefenseStageTarget(pokemon, pokemon, index2, 1);
            SetExpMultplier(entityInfo);
        }
    }
    return flag;
}

bool8 SynthesisMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    HealTargetHP(pokemon, target, gSynthesisHealValueByWeather[GetApparentWeather(pokemon)], 0, TRUE);
    return TRUE;
}

bool8 AgilityMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    RaiseMovementSpeedTarget(pokemon, target, 0, TRUE);
    return TRUE;
}

bool8 RapidSpinMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    bool8 flag = FALSE;
    if(HandleDamagingMove(pokemon, target, move, IntToF248_2(1), param_4) != 0)
    {
        flag = TRUE;
        if(RollSecondaryEffect(pokemon, 0))
        {
            gUnknown_202F21A = 1;
        }
    }
    return flag;
}

bool8 SureShotMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    SureShotStatusTarget(pokemon, target, CalculateStatusTurns(target, gSureShotTurnRange, FALSE));
    return TRUE;
}

bool8 CosmicPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4)
{
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A4C[0], 1);
    RaiseDefenseStageTarget(pokemon, target, gUnknown_8106A50[0], 1);
    return TRUE;
}

