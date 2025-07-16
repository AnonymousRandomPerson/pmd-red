#ifndef GUARD_RGB_H
#define GUARD_RGB_H

typedef struct RGB
{
    u8 r;
    u8 g;
    u8 b;
    u8 unk4; // Never read, always 0x80. Unused transparency/alpha flag?
} RGB;

#define RGB_R 0
#define RGB_G 1
#define RGB_B 2
#define RGB_UNK 3
#define RGB_FIELDS_COUNT 4

typedef struct RGB_Array
{
    u8 c[RGB_FIELDS_COUNT];
} RGB_Array;

typedef union RGB_Union
{
    RGB_Array asArr;
    RGB separate;
} RGB_Union;

#define RGB_TO_GBA(r, g, b) RGB2(((u32)(r) & 0xF8) >> 3, ((g) & 0xF8) >> 3, ((b) & 0xF8) >> 3)
// Needed to match, functionally equivalent to the above.
#define RGB_TO_GBA2(r, g, b)(((u32)((b) & 0xF8) >> 2 << 9) | (((u32)(g) & 0xF8) >> 3 << 5) | (((u32)(r) & 0xF8) >> 3))

#endif // GUARD_RGB_H
