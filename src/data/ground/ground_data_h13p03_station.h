











static const struct ScriptCommand s_gs139_g0_s0_station_sref_script[] = { /* 0x8201cc0 */
    DEBUGINFO,
    SELECT_MAP(139),
    CJUMP_SCENARIO_0(SCENARIO_MAIN),
    COND(JUDGE_EQ, 3, /* to label */ 0),
    JUMP_LABEL(1),
    JUMP_LABEL(2),
  LABEL(0), /* = 0x00 */
    CJUMP_SCENARIO_1(SCENARIO_MAIN),
    COND(JUDGE_LE, 2, /* to label */ 3),
    JUMP_LABEL(2),
  LABEL(3), /* = 0x03 */
    JUMP_LABEL(2),
  LABEL(1), /* = 0x01 */
    SELECT_ENTITIES(1, 0),
    JUMP_LABEL(2),
  LABEL(2), /* = 0x02 */
    JUMPIF_EQUAL(START_MODE, 1, /* to label */ 4),
    JUMPIF_EQUAL(START_MODE, 3, /* to label */ 5),
    JUMPIF_EQUAL(START_MODE, 2, /* to label */ 6),
    JUMPIF_EQUAL(START_MODE, 9, /* to label */ 6),
    JUMP_LABEL(4),
  LABEL(6), /* = 0x06 */
    CJUMP_VAR(GROUND_GETOUT),
    COND_EQUAL(1, /* to label */ 7),
    JUMP_LABEL(7),
  LABEL(4), /* = 0x04 */
    SELECT_LIVES(0, 3),
    JUMP_LABEL(8),
  LABEL(5), /* = 0x05 */
    SELECT_LIVES(0, 4),
    JUMP_LABEL(8),
  LABEL(7), /* = 0x07 */
    SELECT_LIVES(0, 1),
    JUMP_LABEL(8),
  LABEL(8), /* = 0x08 */
    BGM_SWITCH(3),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs139_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs139_g0_s0_station_sref_script }; /* 0x8201f3c */

static const struct ScriptCommand s_gs139_g0_s1_lives0_dlg0[] = { /* 0x8201f48 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs139_g0_s1_lives1_dlg0[] = { /* 0x8201f88 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs139_g0_s3_lives0_dlg0[] = { /* 0x8201fc8 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs139_g0_s3_lives1_dlg0[] = { /* 0x8202008 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs139_g0_s4_lives0_dlg0[] = { /* 0x8202048 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs139_g0_s4_lives1_dlg0[] = { /* 0x8202078 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs139_g1_s0_lives0_dlg1[] = { /* 0x82020a8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs139_g1_s0_lives0_dlg2[] = { /* 0x82020d8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs139_g1_s0_lives1_dlg1[] = { /* 0x82020f8 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs139_g1_s0_lives1_dlg2[] = { /* 0x8202128 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs139_g1_s0_lives2_dlg1[] = { /* 0x8202148 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs139_g1_s0_lives2_dlg2[] = { /* 0x8202178 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs139_g1_s0_lives3_dlg1[] = { /* 0x8202198 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0000,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs139_g1_s0_lives3_dlg2[] = { /* 0x82021c8 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs139_g0_s1_lives[] = { /* 0x82021e8 */
    /*  0 */ {   0,   4,   0,   0, {  29,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs139_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs139_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs139_g0_s3_lives[] = { /* 0x8202218 */
    /*  0 */ {   0,   4,   0,   0, {  29,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs139_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs139_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs139_g0_s4_lives[] = { /* 0x8202248 */
    /*  0 */ {   0,   0,   0,   0, {  29,  32, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs139_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  29,  35, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs139_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs139_g1_s0_lives[] = { /* 0x8202278 */
    /*  0 */ {  14,   0,   0,   0, {  29,  27, 0, CPOS_HALFTILE }, {
        [1] = s_gs139_g1_s0_lives0_dlg1,
        [2] = s_gs139_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  19,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs139_g1_s0_lives1_dlg1,
        [2] = s_gs139_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  39,  26, 0, CPOS_HALFTILE }, {
        [1] = s_gs139_g1_s0_lives2_dlg1,
        [2] = s_gs139_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  29,  18, 0, CPOS_HALFTILE }, {
        [1] = s_gs139_g1_s0_lives3_dlg1,
        [2] = s_gs139_g1_s0_lives3_dlg2,
    } },
};

static const struct GroundEventData s_gs139_g0_s0_evts[] = { /* 0x82022d8 */
    /*  0 */ {  58,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {  58,   1,   0,   0, {   0,  38, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   3,  40,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {   3,  40,   0,   0, {  54,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x8202308 */
    &s_gs139_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs139_g0_sectors[] = { /* 0x820230c */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs139_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs139_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs139_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs139_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs139_g1_sectors[] = { /* 0x82023d4 */
    { LPARRAY(s_gs139_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs139_groups[] = { /* 0x82023fc */
    { LPARRAY(s_gs139_g0_sectors) },
    { LPARRAY(s_gs139_g1_sectors) },
    {},
};

static const struct GroundLink s_gs139_links[] = { /* 0x8202414 */
    /* link   0 */ { { /*x*/  26, /*y*/  16, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  36, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  16, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  26, /*y*/  24, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs139 = { LPARRAY(s_gs139_groups), s_gs139_links }; /* 0x8202434 */
