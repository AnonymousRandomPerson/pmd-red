#include "global.h"
#include "debug.h"

extern void Hang();
static void FatalErrorHang(void) __attribute__((noreturn));

EWRAM_INIT bool32 gNDS_DebugEnabled = {0};
EWRAM_INIT u8 gUnknown_203B150 = {0};

ALIGNED(4) const char gFuncFileLineString[] = "func = '%s'\nfile = '%s'  line = %5d";

ALIGNED(4) const char gNotEntryText[] = "--- not entry ---";
ALIGNED(4) const char gFuncFileLineStringWPrefix[] = "%sfunc = '%s'\nfile = '%s'  line = %5d\n";

ALIGNED(4) const char gFuncFileLineString2[] = "func = '%s'\nfile = '%s'  line = %5d\n";

ALIGNED(4) const char debug_fill14[] = "pksdir0";
ALIGNED(4) const char gDebugPrintPrefix[] = "  Print  ";
ALIGNED(4) static const char debug_fill13[] = "pksdir0";

static UNUSED EWRAM_INIT const char *sUnusedEwramDebugStrings[] =
{
    "Ground",
    "GroundScript",
    "Dungeon",
    "Sound",
    "Bgm",
    "Se",
    "Flag",
    "Memory",
    "Memory Card",
    "Performance",
};

ALIGNED(4) const char gNotMountText[] = "not mount log system";
ALIGNED(4) static const char debug_fill9[] = "pksdir0";
ALIGNED(4) static const char debug_fill10[] = "pksdir0";
ALIGNED(4) static const char debug_fill11[] = "pksdir0";
ALIGNED(4) static const char debug_fill12[] = "pksdir0";

ALIGNED(4) const char gFatalText[] = "!!!!! Fatal !!!!!\n";
ALIGNED(4) const char gFatalErrorBufferPlaceholder[] = "%s\n";

ALIGNED(4) static const char debug_fill0[] = "pksdir0";
ALIGNED(4) static const char debug_fill1[] = "pksdir0";
ALIGNED(4) static const char debug_fill2[] = "pksdir0";
ALIGNED(4) static const char debug_fill3[] = "pksdir0";
ALIGNED(4) static const char debug_fill4[] = "pksdir0";
ALIGNED(4) static const char debug_fill5[] = "pksdir0";
ALIGNED(4) static const char debug_fill6[] = "pksdir0";
ALIGNED(4) static const char debug_fill7[] = "pksdir0";

void NDS_DebugInit(void)
{
    nullsub_26();
    nullsub_27();
    nullsub_29();
    nullsub_30();
    nullsub_31();
    nullsub_32();
    nullsub_28();
    gNDS_DebugEnabled = TRUE;
}

void nullsub_25(void)
{
}

void nullsub_26(void)
{
}

UNUSED static void PrintFuncFileLineOrNotEntry(u8 *buf, DebugLocation *debug)
{
    if (debug != NULL)
        sprintf(buf, gFuncFileLineString, debug->func, debug->file, debug->line);
    else
        sprintf(buf, gNotEntryText);
}

void PrintFuncFileLine(u8 *buf, const DebugLocation *loc, const u8* prefix)
{
    sprintf(buf, gFuncFileLineStringWPrefix, prefix, loc->func, loc->file, loc->line);
}

void PrintMessageWithFuncFileLine(u8 *buffer, const DebugLocation *debug, const u8 *text, ...)
{
    va_list vArgv;
    u32 length;

    va_start(vArgv, text);
    vsprintf(buffer, text, vArgv);
    length = strlen(buffer);
    sprintf(&buffer[length], gFuncFileLineString2, debug->func, debug->file, debug->line);
    va_end(vArgv);
}

void nullsub_199(void)
{
}

void nullsub_27(void)
{
}

// Unused
void sub_8011B08(void)
{
    gUnknown_203B150 = 1;
}

// Unused
void sub_8011B14(void)
{
    gUnknown_203B150 = 0;
}

// Unused
u8 sub_8011B20(void)
{
    gUnknown_203B150 = !gUnknown_203B150;
    return gUnknown_203B150;
}

// unused
u8 sub_8011B3C(void)
{
    return gUnknown_203B150;
}

// unused
void nullsub_137(void)
{

}

static void FatalErrorPrintFuncFileLine(const char *prefix, const DebugLocation *debug)
{
    char buf[0x100];
    if(prefix != NULL){
        PrintFuncFileLine(buf, debug, prefix);
    }
    else
    {
        PrintFuncFileLine(buf, debug, gDebugPrintPrefix);
    }
}

static void FatalErrorFormatMessage(const char *text, ...)
{
    char bufPrint[0x100];
    va_list vArgv;
    va_start(vArgv, text);
    vsprintf(bufPrint, text, vArgv);
    va_end(vArgv);
}


void sub_8011B88(const u8 *text, ...)
{
    char bufPrint[0x100];
    va_list vArgv;
    va_start(vArgv, text);
    vsprintf(bufPrint, text, vArgv);
    va_end(vArgv);
}

void nullsub_28(void)
{
}

s8 ScriptLoggingEnabled(bool8 unused)
{
    return 0;
}

// Unused
u32 sub_8011BA8(void)
{
    return 0;
}

// Unused
const char *GetNotMountText(void)
{
    return gNotMountText;
}

// Unused
void UnusedHang(void)
{
    Hang();
}

void Log(u8 num, const u8 *text, ...)
{
    va_list vArgv;
    va_start(vArgv, text);
    va_end(vArgv);
}

// Unused
void sub_8011BC8(u32 r0, u32 r1, u32 r2, ...)
{
    va_list vArgv;
    va_start(vArgv, r2);
    va_end(vArgv);
}

void nullsub_29()
{
}

void nullsub_30()
{
}

void nullsub_31()
{
}

void nullsub_32()
{
}

static void FatalErrorHang()
{
    Hang();
}

void FatalError(const DebugLocation *debug, const char *text, ...)
{
    char buf[0x100];
    va_list vArgv;

    FatalErrorPrintFuncFileLine(gFatalText, debug);
    va_start(vArgv, text);
    vsprintf(buf, text, vArgv);
    va_end(vArgv);
    FatalErrorFormatMessage(gFatalErrorBufferPlaceholder, buf);
    FatalErrorHang();
}
