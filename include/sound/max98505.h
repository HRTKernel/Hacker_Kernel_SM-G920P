/*
 * Platform data for MAX98505
 *
 * Copyright 2011-2012 Maxim Integrated Products
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 */

#ifndef __SOUND_MAX98505_PDATA_H__
#define __SOUND_MAX98505_PDATA_H__

#define MAX98505_I2C_ADDRESS	(0x62 >> 1)

struct max98505_dsp_cfg {
	const char *name;
	u8 tx_dither_en;
	u8 rx_dither_en;
	u8 meas_dc_block_en;
	u8 rx_flt_mode;
};

/*
 * codec platform data.
 * This definition should be changed,
 * if platform_info of device tree is changed.
 */
#define MAX98505_PINFO_SZ	6
#define MAX98505_BINFO_SZ   26

struct max98505_pdata {
	int sysclk;
	u32 spk_vol;
	u32 vmon_slot;
	u32 capture_active;
	u32 playback_active:1;
	bool i2c_pull_up;
#ifdef USE_MAX98505_IRQ
	int irq;
#endif
	uint32_t pinfo[MAX98505_PINFO_SZ];
	uint32_t binfo[MAX98505_BINFO_SZ];
};
#endif
