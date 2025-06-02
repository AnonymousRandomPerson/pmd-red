#include "global.h"
#include "structs/str_wonder_mail.h"
#include "dungeon.h"
#include "event_flag.h"
#include "pokemon.h"

extern u8 *gMissionRankText[];
extern s32 gUnknown_80E80A0[];
void sub_803C37C(DungeonLocation *, u8, u8 *);

s32 sub_803C1B4(DungeonLocation *dungeon, u8 missionType)
{
    s32 temp;
    temp = sub_80908D8(dungeon);
    if(missionType == 2)
    {
        temp += 2;
    }
    if(temp > 0xF)
        temp = 0xF;
    return temp;
}

u8 sub_803C1D0(struct DungeonLocation *dungeon, u8 missionType)
{
    s32 a = sub_803C1B4(dungeon, missionType);
    a /= 2;
    if ((u8)a >= 7) {
        a = 6;
        return a;
    }
    return a;
}

u8 *GetMissionRankText(u8 index)
{
    return gMissionRankText[index];
}

u32 GetDungeonTeamRankPts(DungeonLocation *dungeon, u8 r1)
{
    u32 index = sub_803C1B4(dungeon, r1);
    return gUnknown_80E80A0[index];
}

void sub_803C21C(WonderMail *param_1, unkStruct_802F204 *param_2)
{
    int index;
    u32 uVar2;

    uVar2 = sub_803C1D0(&param_1->dungeonSeed.location,param_1->missionType);
    param_2->moneyReward = 0;

    for(index = 0; index < MAX_ITEM_REWARDS; index++)
    {
        param_2->itemRewards[index] = ITEM_NOTHING;
    }
    param_2->friendAreaReward = 0;
    param_2->quantity = 10;
    switch(param_1->rewardType) {
        case MONEY:
            param_2->rewardType = 0;
            param_2->moneyReward = (uVar2 + 1) * 100;
            break;
        case MONEY_EXTRA:
            param_2->rewardType = 1;
            param_2->moneyReward = (uVar2 + 1) * 100;
            param_2->itemRewards[0] = param_1->itemReward;
            break;
        case ITEM:
            param_2->rewardType = 2;
            param_2->itemRewards[0] = param_1->itemReward;
            break;
        case ITEM_EXTRA:
            param_2->rewardType = 3;
            param_2->itemRewards[0] = param_1->itemReward;
            do {
                sub_803C37C(&param_1->dungeonSeed.location,param_1->missionType,&param_2->itemRewards[1]);
            } while (param_2->itemRewards[0] == param_2->itemRewards[1]);
            break;
        case MONEY1:
            param_2->rewardType = 0;
            param_2->moneyReward = (uVar2 + 1) * 200;
            break;
        case MONEY1_EXTRA:
            param_2->rewardType = 1;
            param_2->moneyReward = (uVar2 + 1) * 200;
            param_2->itemRewards[0] = param_1->itemReward;
            break;
        case ITEM1: // ITEM1
            param_2->rewardType = 2;
            param_2->itemRewards[0] = param_1->itemReward;
            break;
        case ITEM1_EXTRA:
            param_2->rewardType = 3;
            param_2->itemRewards[0] = param_1->itemReward;
            do {
                sub_803C37C(&param_1->dungeonSeed.location,param_1->missionType,&param_2->itemRewards[1]);
            } while (param_2->itemRewards[0] == param_2->itemRewards[1]);
            do {
                do {
                    sub_803C37C(&param_1->dungeonSeed.location,param_1->missionType,&param_2->itemRewards[2]);
                } while (param_2->itemRewards[0] == param_2->itemRewards[2]);
            } while (param_2->itemRewards[1] == param_2->itemRewards[2]);
            break;
        case FRIEND_AREA:
            param_2->rewardType = 4;
            param_2->friendAreaReward = param_1->friendAreaReward;
            break;
        default:
            param_2->rewardType = 5;
            break;
    }
    CopyYellowMonsterNametoBuffer(param_2->clientName, param_1->clientSpecies);
    param_2->clientSpecies = param_1->clientSpecies;
    param_2->teamRankPtsReward = GetDungeonTeamRankPts(&param_1->dungeonSeed.location,param_1->missionType);
}

void sub_803C37C(DungeonLocation *location, u8 r1, u8 *itemReward)
{
    s32 r7;
    bool8 flag;
    u8 r4;

    r7 = sub_803C1B4(location, r1);
    sub_8090910(location, r7);

    do {
        flag = FALSE;
        r4 = sub_8090910(location, r7);
        if(r4 == ITEM_WEAVILE_FIG)
            flag = GetScriptVarArrayValue(0, EVENT_B01P01, 1) ? TRUE : FALSE;
        if(r4 == ITEM_MIME_JR_FIG)
            if(GetScriptVarArrayValue(0, EVENT_B01P01, 0)) flag = TRUE;
    } while(flag != FALSE);

    *itemReward = r4;
}

// TODO: Figure out if this is the right file
#include "random.h"
#include "pokemon_mail.h"
#include "pokemon_mail_pre.h"

bool8 sub_803C3E0(WonderMail *mail)
{
    const unkStruct_80E9920 *ptr;
    s32 counter, id;
    s32 stack[ARRAY_COUNT(gUnknown_80E9920)];

    counter = 0;
    for (ptr = gUnknown_80E9920, id = 0; id < ARRAY_COUNT_INT(gUnknown_80E9920); ptr++, id++) {
        if (sub_803C110(ptr->parentSpecies) && sub_803C110(ptr->childSpecies)) {
            stack[counter++] = id;
        }
    }

    if (counter != 0) {
        id = stack[RandInt(counter)];
        ptr = &gUnknown_80E9920[id];
        mail->clientSpecies = ptr->parentSpecies;
        mail->targetSpecies = ptr->childSpecies;
        mail->unk2 = 7;
        return TRUE;
    }

    return FALSE;
}

bool8 sub_803C45C(WonderMail *mail)
{
    s32 counter, id;
    s32 stack[ARRAY_COUNT(gUnknown_80E9F8C)];
    const unkStruct_80E9F8C *ptr;

    counter = 0;
    ptr = &gUnknown_80E9F8C[0];
    for (id = 0; id < ARRAY_COUNT_INT(gUnknown_80E9F8C); ptr++, id++) {
        if (sub_803C110(ptr->speciesA) && sub_803C110(ptr->speciesB)) {
            stack[counter++] = id;
        }
    }

    if (counter != 0) {
        id = stack[RandInt(counter)];
        ptr = &gUnknown_80E9F8C[id];

        if ((Rand32Bit() & 0x10)) {
            mail->clientSpecies = ptr->speciesA;
            mail->targetSpecies = ptr->speciesB;
        }
        else {
            mail->clientSpecies = ptr->speciesB;
            mail->targetSpecies = ptr->speciesA;
        }

        mail->unk2 = 8;
        return TRUE;
    }

    return FALSE;
}

bool8 sub_803C4F0(WonderMail *mail)
{
    s32 counter, id;
    s32 stack[ARRAY_COUNT(gUnknown_80E8168)];
    const struct PokemonPair *ptr;

    counter = 0;
    ptr = &gUnknown_80E8168[0];
    for (id = 0; id < ARRAY_COUNT_INT(gUnknown_80E8168); ptr++, id++) {
        if (sub_803C110(ptr->speciesA) && sub_803C110(ptr->speciesB)) {
            stack[counter++] = id;
        }
    }

    if (counter != 0) {
        id = stack[RandInt(counter)];
        ptr = &gUnknown_80E8168[id];

        if ((Rand32Bit() & 0x10)) {
            mail->clientSpecies = ptr->speciesA;
            mail->targetSpecies = ptr->speciesB;
        }
        else {
            mail->clientSpecies = ptr->speciesB;
            mail->targetSpecies = ptr->speciesA;
        }

        mail->unk2 = 9;
        return TRUE;
    }

    return FALSE;
}

bool8 sub_803C580(WonderMail *param_1)
{
    s32 counter, id;
    s32 array[ARRAY_COUNT(gUnknown_80E8180)];
    const struct PokemonItem *ptr;

    counter = 0;
    ptr = gUnknown_80E8180;

    if (!sub_80023E4(6))
        return FALSE;

    for (id = 0; id < ARRAY_COUNT_INT(gUnknown_80E8180); ptr++, id++) {
        if (sub_803C110(ptr->species) && xxx_bit_lut_lookup_8091E50(param_1->dungeonSeed.location.id, ptr->itemId)) {
            array[counter++] = id;
        }
    }

    if (counter != 0) {
        id = array[RandInt(counter)];
        ptr = &gUnknown_80E8180[id];
        param_1->clientSpecies = ptr->species;
        param_1->targetSpecies = ptr->species;
        param_1->targetItem = ptr->itemId;
        param_1->unk2 = 5;
        return TRUE;
    }

    return FALSE;
}

bool8 sub_803C610(WonderMail *param_1)
{
    s32 counter, id;
    s32 array[ARRAY_COUNT(gUnknown_80E81D4)];
    const struct PokemonItem *ptr;

    counter = 0;
    ptr = gUnknown_80E81D4;
    for (id = 0; id < ARRAY_COUNT_INT(gUnknown_80E81D4); ptr++, id++) {
        if (sub_803C110(ptr->species) && xxx_bit_lut_lookup_8091E50(param_1->dungeonSeed.location.id, ptr->itemId)) {
            array[counter++] = id;
        }
    }

    if (counter != 0) {
        id = array[RandInt(counter)];
        ptr = &gUnknown_80E81D4[id];
        param_1->clientSpecies = ptr->species;
        param_1->targetSpecies = ptr->species;
        param_1->targetItem = ptr->itemId;
        param_1->unk2 = 6;
        return TRUE;
    }

    return FALSE;
}
