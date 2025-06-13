#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include "structs/sprite_oam.h"
#include "structs/str_text.h"
#include "structs/str_position.h"

// size: R=0xC | NDS=0xA?
typedef struct TouchScreenMenuInput
{
    /* R=0x0 | B=0x0 */ u8 unk0;
    /* R=0x1 | B=0x1 */ u8 a_button;
    /* R=0x2 | B=0x2 */ u8 b_button;
    /* R=0x3 | B=0x3 */ u8 dpad_right;
    /* R=0x4 | B=0x4 */ u8 dpad_left;
    /* R=0x5 | B=0x5 */ u8 unk5;
    /* R=0x8 | B=0x6 */ DungeonPos unk8;
} TouchScreenMenuInput;

#define DEFAULT_MENU_ENTRY_HEIGHT   12
#define TWO_LINES_MENU_ENTRY_HEIGHT 24

// size: R=0x34 | NDS=0x32?
typedef struct MenuInputStruct
{
    /* 0x0  */ s32 windowId;
    /* 0x4  */ u16 unk4;
    /* 0x6  */ s16 firstEntryY;
    /* 0x8  */ DungeonPos cursorArrowPos;
    /* 0xC  */ DungeonPos leftRightArrowsPos;
    /* 0x10 */ s32 entryHeight; // Either 12, or 24 when each entry has text on two lines.
    /* 0x14 */ DungeonPos unk14;
    /* 0x18 */ s16 menuIndex;
    /* 0x1A */ s16 currPageEntries;
    /* 0x1C */ s16 entriesPerPage;
    /* 0x1E */ s16 currPage;
    /* 0x20 */ s16 pagesCount;
    /* 0x22 */ s16 totalEntriesCount;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u16 unk26;
    /* 0x28 */ TouchScreenMenuInput touchScreen; // For obvious reason unused on GBA
} MenuInputStruct;

// size: 0x8
typedef struct MenuItem
{
    const u8 *text;
    s32 menuAction;
} MenuItem;

// size: R=0x50 | B=0x4C?
typedef struct MenuStruct
{
    /* 0x0 */ const u8 *unk0; // header text?
    /* 0x4 */ const MenuItem *menuItems;
    /* 0x8 */ const u32 *menuTextColorArray;
    /* 0xC */ u16 *unkC;
    /* 0x10 */ s32 index;
    /* 0x14 */ MenuInputStruct input;
    /* 0x48 */ s32 menuAction;
    /* 0x4C */ bool8 unk4C;
    /* 0x4D */ bool8 unk4D;
    /* 0x4E */ bool8 unk4E;
} MenuStruct;

// size: 0x30. Seems to be info for a NumericUpDown
typedef struct unkStructFor8013AA0
{
    s32 unk0; // chosenValue?
    s32 unk4; // curValue or initialValue
    s32 unk8; // minInclusive?
    s32 unkC; // maxInclusive?
    s32 unk10;
    s32 unk14; // index of unk18? But read as chosenValue..?
    WindowTemplate *unk18;
    s32 unk1C; // width of prompt?
    s32 unk20; // height of prompt?
    u8 unk24; // related to unk10
    u8 unk25; // related to unk10
    u8 unk26;
    SpriteOAM unk28;
} unkStructFor8013AA0;

// Used for creating windows with an input menu.
// size: R=0x9C | B=?
typedef struct MenuWindow
{
    /* 0x0 */ MenuInputStruct input;
    /* 0x34 */ u32 menuWinId;
    /* 0x38 */ WindowTemplate *menuWindow;
    /* 0x3C */ WindowTemplates windows;
} MenuWindow;

// Same as above, but has one additional WindowHeader field.
// size: R=0xA0 | B=0x9C?
typedef struct MenuHeaderWindow
{
    /* 0x0 */ MenuWindow m; // short name so it's easier to write. 'm' standing for 'menu' or 'menuWindow'
    /* 0x9C */ WindowHeader header;
} MenuHeaderWindow;

// These macros are used for updating menu windows, as the last page can have less entries than other pages, so the window's height needs to reflect that.
// Note: In order to get matching ASM, this macro had to be created.
// It's probable the code below is not exactly how it was originally written, but it generates the same asm.
#define UPDATE_MENU_WINDOW_HEIGHT_INTERNAL(ptr, _newHeight)                             \
{                                                                                       \
    UNUSED s32 new10;                                                                   \
    s16 newHeight;                                                                      \
    s16 newHeightVal = (_newHeight);                                                    \
    UNUSED s32 dummyMatch = newHeightVal;                                               \
    UNUSED s16 oldHeight = (ptr).windows.id[(ptr).menuWinId].height;                    \
    dummyMatch = 0;                                                                     \
    new10 = newHeightVal + 2;                                                           \
    newHeight = newHeightVal;                                                           \
                                                                                        \
    (ptr).windows.id[(ptr).menuWinId].height = newHeight;                               \
    (ptr).windows.id[(ptr).menuWinId].unk10 = newHeightVal + 2;                         \
                                                                                        \
    ResetUnusedInputStruct();                                                           \
    ShowWindows(&(ptr).windows, TRUE, TRUE);                                            \
}

#define UPDATE_MENU_WINDOW_HEIGHT(ptr)                                                  \
{                                                                                       \
    UPDATE_MENU_WINDOW_HEIGHT_INTERNAL(ptr, CalcEntriesTotalHeight((ptr).input.currPageEntries, DEFAULT_MENU_ENTRY_HEIGHT) + 2) \
}

// For Windows where height is the same as entries height.
#define UPDATE_MENU_WINDOW_HEIGHT_2(ptr)                                                \
{                                                                                       \
    s32 newHeightVal = CalcEntriesTotalHeight((ptr).input.currPageEntries, DEFAULT_MENU_ENTRY_HEIGHT) + 2;                \
    UNUSED s16 oldHeight = (ptr).windows.id[(ptr).menuWinId].height;                    \
    s16 newHeight = newHeightVal;                                                       \
                                                                                        \
    (ptr).windows.id[(ptr).menuWinId].height = newHeight;                               \
    (ptr).windows.id[(ptr).menuWinId].unk10 = newHeight;                                \
                                                                                        \
    ResetUnusedInputStruct();                                                           \
    ShowWindows(&(ptr).windows, TRUE, TRUE);                                            \
}

// For menu windows with two lines entries(for example job mail)
#define UPDATE_TWO_LINES_MENU_WINDOW_HEIGHT(ptr)                                        \
{                                                                                       \
    UPDATE_MENU_WINDOW_HEIGHT_INTERNAL(ptr, CalcTwoLinesEntriesTotalHeight((ptr).input.currPageEntries, TWO_LINES_MENU_ENTRY_HEIGHT) + 2) \
}

#endif // GUARD_MENU_H
