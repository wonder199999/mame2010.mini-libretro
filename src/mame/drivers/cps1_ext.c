
static INPUT_PORTS_START( sfzch )
	/* "IN0" */
	PORT_START("IN0")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_BUTTON5 ) PORT_PLAYER(2)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SERVICE ) PORT_NAME(DEF_STR(Pause)) PORT_CODE(KEYCODE_F1)	/* Pause */
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_SERVICE )							/* Pause */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_START ) PORT_PLAYER(1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_START ) PORT_PLAYER(2)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON6 ) PORT_PLAYER(2)

	PORT_START("DSWA")
	PORT_DIPNAME( 0xff, 0xff, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0xff, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSWB")
	PORT_DIPNAME( 0xff, 0xff, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0xff, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	PORT_START("DSWC")
	PORT_DIPNAME( 0xff, 0xff, DEF_STR( Unknown ) )
	PORT_DIPSETTING(    0xff, DEF_STR( Off ) )
	PORT_DIPSETTING(    0x00, DEF_STR( On ) )

	/* Player 1 */
	PORT_START("IN1")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT )	PORT_8WAY	PORT_PLAYER(1)
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT )	PORT_8WAY 	PORT_PLAYER(1)
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )	PORT_8WAY 	PORT_PLAYER(1)
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_JOYSTICK_UP )	PORT_8WAY 	PORT_PLAYER(1)
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_BUTTON1 )	PORT_PLAYER(1)
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_BUTTON2 )	PORT_PLAYER(1)
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_BUTTON3 )	PORT_PLAYER(1)
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_BUTTON4 )	PORT_PLAYER(1)
	/* Player 2 */
	PORT_BIT( 0x0100, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT )	PORT_8WAY	PORT_PLAYER(2)
	PORT_BIT( 0x0200, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT )	PORT_8WAY	PORT_PLAYER(2)
	PORT_BIT( 0x0400, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN )	PORT_8WAY	PORT_PLAYER(2)
	PORT_BIT( 0x0800, IP_ACTIVE_LOW, IPT_JOYSTICK_UP )	PORT_8WAY	PORT_PLAYER(2)
	PORT_BIT( 0x1000, IP_ACTIVE_LOW, IPT_BUTTON1 )	PORT_PLAYER(2)
	PORT_BIT( 0x2000, IP_ACTIVE_LOW, IPT_BUTTON2 )	PORT_PLAYER(2)
	PORT_BIT( 0x4000, IP_ACTIVE_LOW, IPT_BUTTON3 )	PORT_PLAYER(2)
	PORT_BIT( 0x8000, IP_ACTIVE_LOW, IPT_BUTTON4 )	PORT_PLAYER(2)
	/* Player 3 - not used */
	PORT_START("IN2")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_START("IN3")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END

static INPUT_PORTS_START( wofch )
	PORT_INCLUDE( sfzch)

	PORT_START( "EEPROMIN" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_SPECIAL ) PORT_READ_LINE_DEVICE("eeprom", eeprom_read_bit)

	PORT_START( "EEPROMOUT" )
	PORT_BIT( 0x01, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE("eeprom", eeprom_write_bit)
	PORT_BIT( 0x40, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE("eeprom", eeprom_set_clock_line)
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE("eeprom", eeprom_set_cs_line)
INPUT_PORTS_END

ROM_START( sfzch )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )      /* 68000 code */
	ROM_LOAD16_WORD_SWAP( "sfzch23",  0x000000, 0x080000, NO_DUMP )
	ROM_LOAD16_WORD_SWAP( "sfza22",  0x080000, 0x080000, NO_DUMP )
	ROM_LOAD16_WORD_SWAP( "sfzch21",  0x100000, 0x080000, NO_DUMP )
	ROM_LOAD16_WORD_SWAP( "sfza20",  0x180000, 0x080000, NO_DUMP )

	ROM_REGION( 0x800000, "gfx", 0 )
	ROMX_LOAD( "sfz_01.3a",     0x000000, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_02.4a",     0x000002, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_03.5a",     0x000004, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_04.6a",     0x000006, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_05.7a",     0x200000, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_06.8a",     0x200002, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_07.9a",     0x200004, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_08.10a",    0x200006, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_10.3c",     0x400000, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_11.4c",     0x400002, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_12.5c",     0x400004, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_13.6c",     0x400006, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_14.7c",     0x600000, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_15.8c",     0x600002, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_16.9c",     0x600004, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "sfz_17.10c",    0x600006, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x08000, "stars", 0 )
	ROM_COPY( "gfx", 0x000000, 0x000000, 0x8000 )	/* stars */

	ROM_REGION( 0x028000, "audiocpu", 0 ) /* 64k for the audio CPU (+bank) */
	ROM_LOAD( "sfz_09.12a", 0x000000, 0x08000, NO_DUMP )
	ROM_CONTINUE(	   0x010000, 0x08000 )

	ROM_REGION( 0x040000, "oki", 0 ) /* Samples */
	ROM_LOAD( "sfz_18.11c", 0x000000, 0x020000, NO_DUMP )
	ROM_LOAD( "sfz_19.12c", 0x020000, 0x020000, NO_DUMP )
ROM_END

ROM_START( wofch )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )      /* 68000 code */
	ROM_LOAD16_WORD_SWAP( "tk2(ch)_23.8f",  0x000000, 0x080000, NO_DUMP )
	ROM_LOAD16_WORD_SWAP( "tk2(ch)_22.7f",  0x080000, 0x080000, NO_DUMP )

	ROM_REGION( 0x400000, "gfx", 0 )
	ROMX_LOAD( "tk2-1m.3a",     	0x000000, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2-3m.5a",     	0x000002, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2-2m.4a",     	0x000004, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2-4m.6a",     	0x000006, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2(ch)_05.7a",	0x200000, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2(ch)_06.8a",     0x200002, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2(ch)_07.9a",    	0x200004, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2(ch)_08.10a",   	0x200006, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x028000, "audiocpu", 0 ) /* 64k for the audio CPU (+bank) */
	ROM_LOAD( "tk2_qa.5k",  0x000000, 0x08000, NO_DUMP )
	ROM_CONTINUE(	 	0x010000, 0x18000 )

	ROM_REGION( 0x200000, "qsound", 0 )	 /* QSound Samples */
	ROM_LOAD( "tk2-q1.1k", 0x000000, 0x080000, NO_DUMP )
	ROM_LOAD( "tk2-q2.2k", 0x080000, 0x080000, NO_DUMP )
	ROM_LOAD( "tk2-q3.3k", 0x100000, 0x080000, NO_DUMP )
	ROM_LOAD( "tk2-q4.4k", 0x180000, 0x080000, NO_DUMP )

	ROM_REGION( 0x0200, "aboardplds", 0 )
	ROM_LOAD( "buf1", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "ioa1", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "prg2", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "rom1", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "sou1", 	0x0000, 0x0117, NO_DUMP )

	ROM_REGION( 0x0200, "bboardplds", 0 )
	ROM_LOAD( "tk263b.1a", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "iob1.12d",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "bprg1.11d",	0x0000, 0x0117, NO_DUMP )

	ROM_REGION( 0x0200, "cboardplds", 0 )
	ROM_LOAD( "ioc1.ic7",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "c632.ic1",	0x0000, 0x0117, NO_DUMP )

	ROM_REGION( 0x0200, "dboardplds", 0 )
	ROM_LOAD( "d7l1.7l",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "d8l1.8l",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "d9k1.9k",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "d10f1.10f",	0x0000, 0x0117, NO_DUMP )
ROM_END

ROM_START( wofches )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )      /* 68000 code */
	ROM_LOAD16_WORD_SWAP( "tk2(ch)_23.bin",  0x000000, 0x080000, NO_DUMP )
	ROM_LOAD16_WORD_SWAP( "tk2(ch)_22.bin",  0x080000, 0x080000, NO_DUMP )

	ROM_REGION( 0x400000, "gfx", 0 )
	ROMX_LOAD( "tk2-1m.3a",     	0x000000, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2-3m.5a",     	0x000002, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2-2m.4a",     	0x000004, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2-4m.6a",     	0x000006, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2(ch)_05.7a",	0x200000, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2(ch)_06.8a",     0x200002, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2(ch)_07.9a",    	0x200004, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2(ch)_08.10a",   	0x200006, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x028000, "audiocpu", 0 ) /* 64k for the audio CPU (+bank) */
	ROM_LOAD( "tk2_qa.5k",  0x000000, 0x08000, NO_DUMP )
	ROM_CONTINUE(	 	0x010000, 0x18000 )

	ROM_REGION( 0x200000, "qsound", 0 )	 /* QSound Samples */
	ROM_LOAD( "tk2-q1.1k", 0x000000, 0x080000, NO_DUMP )
	ROM_LOAD( "tk2-q2.2k", 0x080000, 0x080000, NO_DUMP )
	ROM_LOAD( "tk2-q3.3k", 0x100000, 0x080000, NO_DUMP )
	ROM_LOAD( "tk2-q4.4k", 0x180000, 0x080000, NO_DUMP )

	ROM_REGION( 0x0200, "aboardplds", 0 )
	ROM_LOAD( "buf1", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "ioa1", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "prg2", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "rom1", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "sou1", 	0x0000, 0x0117, NO_DUMP )

	ROM_REGION( 0x0200, "bboardplds", 0 )
	ROM_LOAD( "tk263b.1a", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "iob1.12d",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "bprg1.11d",	0x0000, 0x0117, NO_DUMP )

	ROM_REGION( 0x0200, "cboardplds", 0 )
	ROM_LOAD( "ioc1.ic7",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "c632.ic1",	0x0000, 0x0117, NO_DUMP )

	ROM_REGION( 0x0200, "dboardplds", 0 )
	ROM_LOAD( "d7l1.7l",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "d8l1.8l",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "d9k1.9k",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "d10f1.10f",	0x0000, 0x0117, NO_DUMP )
ROM_END

ROM_START( wofchdx )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )      /* 68000 code */
	ROM_LOAD16_WORD_SWAP( "tk2(ch)dx_23.8f",  0x000000, 0x080000, NO_DUMP )
	ROM_LOAD16_WORD_SWAP( "tk2(ch)dx_22.7f",  0x080000, 0x080000, NO_DUMP )

	ROM_REGION( 0x400000, "gfx", 0 )
	ROMX_LOAD( "tk2-1m.3a",     	0x000000, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2-3m.5a",     	0x000002, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2-2m.4a",     	0x000004, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2-4m.6a",     	0x000006, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2(ch)_05.7a",	0x200000, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2(ch)_06.8a",     0x200002, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2(ch)_07.9a",    	0x200004, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "tk2(ch)_08.10a",   	0x200006, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x028000, "audiocpu", 0 ) /* 64k for the audio CPU (+bank) */
	ROM_LOAD( "tk2_qa.5k",  0x000000, 0x08000, NO_DUMP )
	ROM_CONTINUE(	 	0x010000, 0x18000 )

	ROM_REGION( 0x200000, "qsound", 0 )	 /* QSound Samples */
	ROM_LOAD( "tk2-q1.1k", 0x000000, 0x080000, NO_DUMP )
	ROM_LOAD( "tk2-q2.2k", 0x080000, 0x080000, NO_DUMP )
	ROM_LOAD( "tk2-q3.3k", 0x100000, 0x080000, NO_DUMP )
	ROM_LOAD( "tk2-q4.4k", 0x180000, 0x080000, NO_DUMP )

	ROM_REGION( 0x0200, "aboardplds", 0 )
	ROM_LOAD( "buf1", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "ioa1", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "prg2", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "rom1", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "sou1", 	0x0000, 0x0117, NO_DUMP )

	ROM_REGION( 0x0200, "bboardplds", 0 )
	ROM_LOAD( "tk263b.1a", 	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "iob1.12d",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "bprg1.11d",	0x0000, 0x0117, NO_DUMP )

	ROM_REGION( 0x0200, "cboardplds", 0 )
	ROM_LOAD( "ioc1.ic7",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "c632.ic1",	0x0000, 0x0117, NO_DUMP )

	ROM_REGION( 0x0200, "dboardplds", 0 )
	ROM_LOAD( "d7l1.7l",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "d8l1.8l",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "d9k1.9k",	0x0000, 0x0117, NO_DUMP )
	ROM_LOAD( "d10f1.10f",	0x0000, 0x0117, NO_DUMP )
ROM_END

ROM_START( wofhfh )
	ROM_REGION( CODE_SIZE, "maincpu", 0 )      /* 68000 code */
	ROM_LOAD16_WORD_SWAP( "23",  0x000000, 0x080000, NO_DUMP )
	ROM_LOAD16_WORD_SWAP( "22",  0x080000, 0x080000, NO_DUMP )

	ROM_REGION( 0x400000, "gfx", 0 )
	ROMX_LOAD( "1",     	0x000000, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "2",     	0x000002, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "3",     	0x000004, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "4",     	0x000006, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "5",		0x200000, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "6",     	0x200002, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "7",    	0x200004, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )
	ROMX_LOAD( "8",   	0x200006, 0x080000, NO_DUMP, ROM_GROUPWORD | ROM_SKIP(6) )

	ROM_REGION( 0x028000, "audiocpu", 0 )
	ROM_LOAD( "9",		0x000000, 0x08000, NO_DUMP )
	ROM_CONTINUE(	 	0x010000, 0x18000 )

	ROM_REGION( 0x040000, "oki", 0 )
	ROM_LOAD( "18",		0x000000, 0x020000, NO_DUMP )
	ROM_LOAD( "19",		0x020000, 0x020000, NO_DUMP )
ROM_END