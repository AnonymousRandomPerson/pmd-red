







static const struct ScriptCommand s_gs177_g0_s0_station_sref_script[] = { /* 0x822bde8 */
    DEBUGINFO,
    SELECT_MAP(177),
    BGM_STOP,
    JUMP_SCRIPT(COMMON_ENTER),
};

static const struct ScriptRef s_gs177_g0_s0_station_sref = { 404, 1, NULL /* ENTER_CONTROL */, s_gs177_g0_s0_station_sref_script }; /* 0x822be54 */

static const struct ScriptCommand s_gs177_g1_s0_station_sref_script[] = { /* 0x822be60 */
    DEBUGINFO,
    SELECT_MAP(177),
    SELECT_ENTITIES(-1, -1),
    { 0x22, 0x01,  0x001e,  0x00000000,  0x00000000, NULL },
    { 0xe0, 0x00,  0x002d,  0x00000000,  0x00000000, NULL },
    WAIT(240),
    TEXTBOX_AUTO_PRESS(-1, -1),
    MSG_ON_BG2(_("\n")),
    TEXTBOX_CLEAR,
    WAIT(1),
    { 0x23, 0x01,  0x0078,  0x00000000,  0x00000000, NULL },
    WAIT(90),
    { 0x2d, 0x09,  0x0000,  0x00000001,  0x00000000, NULL },
    { 0x2d, 0x09,  0x0001,  0x00000022,  0x00000000, NULL },
    { 0x26, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    MSG_ON_BG_AUTO(30, _("{CENTER_ALIGN}The story of {NAME_0} and\n{CENTER_ALIGN}{NAME_1} ends here.")),
    MSG_ON_BG_AUTO(30, _("{CENTER_ALIGN}But {TEAM_NAME} isn't done yet!\n{CENTER_ALIGN}There are many rescues to be done!")),
    MSG_ON_BG_AUTO(30, _("{CENTER_ALIGN}A new adventure begins!")),
    MSG_ON_BG_AUTO(30, _("{CENTER_ALIGN}The legendary Pokémon are set\n{CENTER_ALIGN}to make their appearance!")),
    MSG_ON_BG_AUTO(30, _("{CENTER_ALIGN}Don't go away!")),
    TEXTBOX_CLEAR,
    WAIT(1),
    { 0x25, 0x01,  0x0000,  0x00000000,  0x00000000, NULL },
    WAIT(60),
    { 0x3b, 0x09,  0x0000,  0x00000000,  0x00000000, NULL },
    UPDATE_VARINT(CALC_SET, GROUND_PLACE, 11),
    ASK1(FALSE, /*default*/ -1, /* speaker */ -1, _("Would you like to save your adventure?")),
    CHOICE(/* label */  0, _("Yes.")),
    CHOICE(/* label */  1, _("No.")),
    JUMP_LABEL(1),
  LABEL(0), /* = 0x00 */
    SPECIAL_TEXT(SPECIAL_TEXT_SAVE_1, 0, 0),
  LABEL(1), /* = 0x01 */
    TEXTBOX_CLEAR,
    WAIT(60),
    RET,
};

static const struct ScriptRef s_gs177_g1_s0_station_sref = { 400, 7, NULL /* EVENT_CONTROL */, s_gs177_g1_s0_station_sref_script }; /* 0x822c1ac */
static const struct GroundEffectData s_gs177_g1_s0_effs[] = { /* 0x822c1b8 */
    /*  0 */ {   0,   0,   1,   1, {  21,  15, CPOS_HALFTILE, CPOS_HALFTILE }, NULL },
};

static const struct ScriptRef * const (sStationScripts[]) = { /* 0x822c1c4 */
    &s_gs177_g0_s0_station_sref,
    &s_gs177_g1_s0_station_sref,
};

static const struct GroundScriptSector s_gs177_g0_sectors[] = { /* 0x822c1cc */
    { 0,NULL, 0,NULL, 0,NULL, 0,NULL, 1,&sStationScripts[0], },
};

static const struct GroundScriptSector s_gs177_g1_sectors[] = { /* 0x822c1f4 */
    { 0,NULL, 0,NULL, LPARRAY(s_gs177_g1_s0_effs), 0,NULL, 1,&sStationScripts[1], },
};

static const struct GroundScriptGroup s_gs177_groups[] = { /* 0x822c21c */
    { LPARRAY(s_gs177_g0_sectors) },
    { LPARRAY(s_gs177_g1_sectors) },
};

static const struct GroundLink s_gs177_links[] = { /* 0x822c22c */
    {},
};

/*extern*/ const struct GroundScriptHeader gGroundScript_gs177 = { LPARRAY(s_gs177_groups), s_gs177_links }; /* 0x822c234 */
