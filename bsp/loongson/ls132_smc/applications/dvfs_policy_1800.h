/* SPDX-License-Identifier: MIT OR Apache-2.0 */
/*
 * Copyright (C) 2019, 2020 Jiaxun Yang <jiaxun.yang@flygoat.com>
 */

#define BASEFREQ	1500	//MHz
#define BOOT_VID	1150	//mv
#define BOOT_DIV	1
#define BOOT_LOOPC	15
#define BOOT_REFC	1

#define BOOSTFREQ	1800
#define BOOST_VID	1250	//mv
#define BOOST_DIV	1
#define BOOST_LOOPC	18
#define BOOST_REFC	1

#if defined(MIKU_INDVFS) && !defined(__ASSEMBLY__)
#define NUM_PLL_LEVEL	3

struct pll_level pll_levels[NUM_PLL_LEVEL] = 
{{/* Idle: Max 750MHz */
	.refc = BOOT_REFC,
	.loopc = BOOT_LOOPC,
	.div = BOOT_DIV,
	.vid = 1000, /* FIXME: Low down it later */
	.highest_scale = (4 - 1), /* 4 / 8 */
	.lowest_scale = 0, /* 1 / 8 */
	.stable_scale = (8 - 1), /* 8/8, 1500MHz */
	.node_scale = (4 - 1), /* 4 / 8 */
	.ht_scale = (4 - 1), /* 4 / 8 */
	.min_time = 5000, /* 5s */
	.max_temp = 120,
	.sram_val = 0x1f156f
},{/* Normal: Max 1500MHz */
	.refc = BOOT_REFC,
	.loopc = BOOT_LOOPC,
	.div = BOOT_DIV,
	.vid = BOOT_VID,
	.highest_scale = (8 - 1), /* 8 / 8 */
	.lowest_scale = (5 - 1), /* 5 / 8 */
	.stable_scale = (8 - 1), /* 8/8, 1500MHz */
	.node_scale = (8 - 1), /* 8 / 8 */
	.ht_scale = (4 - 1), /* 4 / 8 */
	.min_time = 5000, /* 5s */
	.max_temp = 100,
	.sram_val = 0x2be10fa
},{/* Boost: Max 1800MHz */
	.refc = BOOST_REFC,
	.loopc = BOOST_LOOPC,
	.div = BOOST_DIV,
	.vid = BOOST_VID,
	.highest_scale = (8 - 1), /* 8 / 8 */
	.lowest_scale = (7 - 1), /* 7 / 8 */
	.stable_scale = (7 - 1), /* 7/8, 1575MHz */
	.node_scale = (8 - 1), /* 8 / 8 */
	.ht_scale = (4 - 1), /* 4 / 8 */
	.min_time = 5000, /* 5s */
	.max_temp = 80,
	.sram_val = 0x2be10fa
}};

/* Shadow means what we tell kernel */
#define SHADOW_LEVEL_NUM	10
#define BASEFREQ_SHADOW_LEVEL	7
rt_uint16_t	shadow_level_freq[SHADOW_LEVEL_NUM] = {BASEFREQ/8*1,
												   BASEFREQ/8*2,
												   BASEFREQ/8*3,
												   BASEFREQ/8*4,
												   BASEFREQ/8*5,
												   BASEFREQ/8*6,
												   BASEFREQ/8*7,
												   BASEFREQ,
												   BOOSTFREQ/8*7,
												   BOOSTFREQ};
rt_uint32_t	core_scale_min = 3000;
#endif