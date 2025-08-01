











static const struct ScriptCommand s_gs107_g0_s0_station_sref_script[] = { /* 0x81ef538 */
    DEBUGINFO,
    SELECT_MAP(107),
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
    BGM_SWITCH(106),
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs107_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs107_g0_s0_station_sref_script }; /* 0x81ef7b4 */

static const struct ScriptCommand s_gs107_g0_s1_lives0_dlg0[] = { /* 0x81ef7c0 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs107_g0_s1_lives1_dlg0[] = { /* 0x81ef800 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs107_g0_s3_lives0_dlg0[] = { /* 0x81ef840 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs107_g0_s3_lives1_dlg0[] = { /* 0x81ef880 */
    DEBUGINFO,
    SELECT_ANIMATION(2),
    CALL_SCRIPT(WAIT_START_FUNC),
    RET,
};

static const struct ScriptCommand s_gs107_g0_s4_lives0_dlg0[] = { /* 0x81ef8c0 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE_FUNC),
    RET,
};

static const struct ScriptCommand s_gs107_g0_s4_lives1_dlg0[] = { /* 0x81ef8f0 */
    DEBUGINFO,
    CALL_SCRIPT(LIVES_WARP_ARRIVE2_FUNC),
    RET,
};

static const struct ScriptCommand s_gs107_g1_s0_lives0_dlg1[] = { /* 0x81ef920 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs107_g1_s0_lives0_dlg2[] = { /* 0x81ef950 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs107_g1_s0_lives1_dlg1[] = { /* 0x81ef970 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0002,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs107_g1_s0_lives1_dlg2[] = { /* 0x81ef9a0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs107_g1_s0_lives2_dlg1[] = { /* 0x81ef9c0 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0003,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs107_g1_s0_lives2_dlg2[] = { /* 0x81ef9f0 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct ScriptCommand s_gs107_g1_s0_lives3_dlg1[] = { /* 0x81efa10 */
    DEBUGINFO,
    { 0x51, 0x00,  0x0001,  0x00000000,  0x00000000, NULL },
    JUMP_SCRIPT(HABITAT_MOVE1),
};

static const struct ScriptCommand s_gs107_g1_s0_lives3_dlg2[] = { /* 0x81efa40 */
    DEBUGINFO,
    JUMP_SCRIPT(HABITAT_TALK),
};

static const struct GroundLivesData s_gs107_g0_s1_lives[] = { /* 0x81efa60 */
    /*  0 */ {   0,   4,   0,   0, {  33,   7, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs107_g0_s1_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  33,   3, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs107_g0_s1_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs107_g0_s3_lives[] = { /* 0x81efa90 */
    /*  0 */ {   0,   4,   0,   0, {  33,   7, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs107_g0_s3_lives0_dlg0,
    } },
    /*  1 */ {   4,   4,   0,   0, {  33,   3, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs107_g0_s3_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs107_g0_s4_lives[] = { /* 0x81efac0 */
    /*  0 */ {   0,   0,   0,   0, {  33,   7, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs107_g0_s4_lives0_dlg0,
    } },
    /*  1 */ {   4,   0,   0,   0, {  33,   3, CPOS_HALFTILE, CPOS_HALFTILE }, {
        [0] = s_gs107_g0_s4_lives1_dlg0,
    } },
};

static const struct GroundLivesData s_gs107_g1_s0_lives[] = { /* 0x81efaf0 */
    /*  0 */ {  14,   0,   0,   0, {  27,  16, 0, CPOS_HALFTILE }, {
        [1] = s_gs107_g1_s0_lives0_dlg1,
        [2] = s_gs107_g1_s0_lives0_dlg2,
    } },
    /*  1 */ {  15,   0,   0,   0, {  29,  25, 0, CPOS_HALFTILE }, {
        [1] = s_gs107_g1_s0_lives1_dlg1,
        [2] = s_gs107_g1_s0_lives1_dlg2,
    } },
    /*  2 */ {  16,   0,   0,   0, {  18,  31, 0, CPOS_HALFTILE }, {
        [1] = s_gs107_g1_s0_lives2_dlg1,
        [2] = s_gs107_g1_s0_lives2_dlg2,
    } },
    /*  3 */ {  17,   0,   0,   0, {  49,  33, 0, CPOS_HALFTILE }, {
        [1] = s_gs107_g1_s0_lives3_dlg1,
        [2] = s_gs107_g1_s0_lives3_dlg2,
    } },
};

static const struct GroundEventData s_gs107_g0_s0_evts[] = { /* 0x81efb50 */
    /*  0 */ {  66,   3,   0,   0, {   0,  42, 0, 0 }, &gFunctionScriptTable[358] },
    /*  1 */ {   3,  45,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  2 */ {   3,  45,   0,   0, {  63,   0, 0, 0 }, &gFunctionScriptTable[358] },
    /*  3 */ {  66,   3,   0,   0, {   0,   0, 0, 0 }, &gFunctionScriptTable[358] },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x81efb80 */
    &s_gs107_g0_s0_station_sref,
};

static const struct GroundScriptSector s_gs107_g0_sectors[] = { /* 0x81efb84 */
    { 0,NULL, 0,NULL, 0,NULL, LPARRAY(s_gs107_g0_s0_evts), 1,&sStationScripts[0], },
    { LPARRAY(s_gs107_g0_s1_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs107_g0_s3_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
    { LPARRAY(s_gs107_g0_s4_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptSector s_gs107_g1_sectors[] = { /* 0x81efc4c */
    { LPARRAY(s_gs107_g1_s0_lives), 0,NULL, 0,NULL, 0,NULL, 0,NULL, },
};

static const struct GroundScriptGroup s_gs107_groups[] = { /* 0x81efc74 */
    { LPARRAY(s_gs107_g0_sectors) },
    { LPARRAY(s_gs107_g1_sectors) },
    {},
};

static const struct GroundLink s_gs107_links[] = { /* 0x81efc8c */
    /* link   0 */ { { /*x*/  15, /*y*/  29, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   1 */ { { /*x*/  46, /*y*/  30, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   2 */ { { /*x*/  26, /*y*/  22, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
    /* link   3 */ { { /*x*/  24, /*y*/  13, /*flags*/ 0, 0 }, /*w*/  6, /*h*/  6, /*ret*/ 3, /*?*/ 2 },
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs107 = { LPARRAY(s_gs107_groups), s_gs107_links }; /* 0x81efcac */
