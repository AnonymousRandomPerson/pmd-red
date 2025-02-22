#include "global.h"
#include "dungeon_visibility.h"

#include "constants/status.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_range.h"
#include "dungeon_util.h"

bool8 CanSeeTarget(Entity *entity, Entity *targetEntity)
{
    if (!EntityIsValid(entity) || !EntityIsValid(targetEntity) || !targetEntity->isVisible)
    {
        return FALSE;
    }
    if (targetEntity->type == ENTITY_MONSTER)
    {
        if (entity->type == ENTITY_MONSTER)
        {
            if (!CanSeeInvisibleMonsters(entity) && GetEntInfo(targetEntity)->invisibleClassStatus.status == STATUS_INVISIBLE)
            {
                return FALSE;
            }
            if (GetEntInfo(entity)->blinkerClassStatus.status == STATUS_BLINKER)
            {
                return FALSE;
            }
        }
        else if (GetEntInfo(targetEntity)->invisibleClassStatus.status == STATUS_INVISIBLE)
        {
            return FALSE;
        }
    }
    return IsPositionActuallyInSight(&entity->pos, &targetEntity->pos);
}

bool8 CanTargetEntity(Entity *entity, Entity *targetEntity)
{
    if (!EntityIsValid(entity) || !EntityIsValid(targetEntity) || !targetEntity->isVisible)
    {
        return FALSE;
    }
    if (targetEntity->type == ENTITY_MONSTER)
    {
        if (entity->type == ENTITY_MONSTER)
        {
            if (!CanSeeInvisibleMonsters(entity) && GetEntInfo(targetEntity)->invisibleClassStatus.status == STATUS_INVISIBLE)
            {
                return FALSE;
            }
            if (GetEntInfo(entity)->blinkerClassStatus.status == STATUS_BLINKER)
            {
                return FALSE;
            }
        }
        else if (GetEntInfo(targetEntity)->invisibleClassStatus.status == STATUS_INVISIBLE)
        {
            return FALSE;
        }
    }
    return IsPositionInSight(&entity->pos, &targetEntity->pos);
}

bool8 sub_8045A70(Entity *entity, Entity *targetEntity)
{
    if (EntityIsValid(entity) && EntityIsValid(targetEntity) && targetEntity->isVisible)
    {
         return IsPositionActuallyInSight(&entity->pos, &targetEntity->pos);
    }
   return FALSE;
}

bool8 sub_8045AAC(Entity *entity, DungeonPos *pos)
{
    return IsPositionActuallyInSight(&entity->pos, pos);
}

bool8 CanTargetPosition(Entity *entity, DungeonPos *pos)
{
    return IsPositionInSight(&entity->pos, pos);
}

