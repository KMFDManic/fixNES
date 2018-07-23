/*
 * Copyright (C) 2017 - 2018 FIX94
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "mapper_h/mmc1.h"
#include "mapper_h/mmc2_4.h"
#include "mapper_h/mmc3.h"
#include "mapper_h/mmc3add.h"
#include "mapper_h/mmc5.h"
#include "mapper_h/m13.h"
#include "mapper_h/m15.h"
#include "mapper_h/m28.h"
#include "mapper_h/m31.h"
#include "mapper_h/m32.h"
#include "mapper_h/m33.h"
#include "mapper_h/m34.h"
#include "mapper_h/m48.h"
#include "mapper_h/m65.h"
#include "mapper_h/m137.h"
#include "mapper_h/m156.h"
#include "mapper_h/m193.h"
#include "mapper_h/m206.h"
#include "mapper_h/m225.h"
#include "mapper_h/m228.h"
#include "mapper_h/m237.h"
#include "mapper_h/namco.h"
#include "mapper_h/p16c8.h"
#include "mapper_h/p32c8.h"
#include "mapper_h/vrc1.h"
#include "mapper_h/vrc2_4.h"
#include "mapper_h/vrc3.h"
#include "mapper_h/vrc6.h"
#include "mapper_h/vrc7.h"
#include "mapper_h/s1.h"
#include "mapper_h/s3.h"
#include "mapper_h/s4.h"
#include "mapper_h/s5b.h"
#include "mapper_h/common.h"
#include "mapper.h"
#include "mapperList.h"
#include "audio_mmc5.h"
#include "vrc_irq.h"

mapperList_t mapperList[256] = {
	{ p32c8RAMinit,	p32c8RAMinitGet8,	m0_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ mmc1init,		mmc1initGet8,		mmc1initSet8,	chr4initPPUGet8,	chr4initPPUSet8,	NULL, NULL },
	{ p16c8init,	prg16initGet8,		m2_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ p32c8init,	prg32initGet8,		m3_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ mmc3init,		mmc3initGet8,		mmc3initSet8,	mmc3initPPUGet8,	mmc3initPPUSet8,	NULL, NULL },
	{ mmc5init,		mmc5initGet8,		mmc5initSet8,	mmc5initPPUGet8,	mmc5initPPUSet8,	mmc5AudioClockTimers, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m7_init,		prg32initGet8,		m7_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ mmc2_4init,	mmc2initGet8,		mmc2initSet8,	mmc2initPPUGet8,	mmc2_4initPPUSet8,	NULL, NULL },
	{ mmc2_4init,	mmc4initGet8,		mmc4initSet8,	mmc4initPPUGet8,	mmc2_4initPPUSet8,	NULL, NULL },
	{ p32c8init,	prg32initGet8,		m11_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m12init,		mmc3initGet8,		m12initSet8,	mmc3initPPUGet8,	mmc3initPPUSet8,	NULL, NULL },
	{ m13init,		m13initGet8,		m13initSet8,	m13initPPUGet8,		m13initPPUSet8,		NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m15init,		m15initGet8,		m15initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m15reset },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ namco_init,	namco_initGet8,		namco_initSet8,	namco_initPPUGet8,	namco_initPPUSet8,	namco_cycle, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ vrc2_4_init,	vrc2_4_initGet8,	m21_initSet8,	chr1initPPUGet8,	chr1initPPUSet8,	vrc_irq_cycle, NULL },
	{ vrc2_4_init,	vrc2_4_initGet8,	m22_initSet8,	chr1initPPUGet8,	chr1initPPUSet8,	vrc_irq_cycle, NULL },
	{ vrc2_4_init,	vrc2_4_initGet8,	m23_initSet8,	chr1initPPUGet8,	chr1initPPUSet8,	vrc_irq_cycle, NULL },
	{ vrc6init,		vrc6initGet8,		m24_initSet8,	chr1initPPUGet8,	chr1initPPUSet8,	vrc6cycle, NULL },
	{ vrc2_4_init,	vrc2_4_initGet8,	m25_initSet8,	chr1initPPUGet8,	chr1initPPUSet8,	vrc_irq_cycle, NULL },
	{ vrc6init,		vrc6initGet8,		m26_initSet8,	chr1initPPUGet8,	chr1initPPUSet8,	vrc6cycle, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m28init,		m28initGet8,		m28initSet8,	m28initPPUGet8,		m28initPPUSet8,		NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m31init,		prg4initGet8,		m31initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m32init,		m32initGet8,		m32initSet8,	chr1initPPUGet8,	chr1initPPUSet8,	NULL, NULL },
	{ m33init,		prg8initGet8,		m33initSet8,	chr1initPPUGet8,	chr1initPPUSet8,	NULL, NULL },
	{ m34init,		m34initGet8,		m34initSet8,	chr4initPPUGet8,	chr4initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m36_init,		m36_initGet8,		m36_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m37_init,		mmc3NoRAMInitGet8,	m37_initSet8,	mmc3initPPUGet8,	mmc3initPPUSet8,	NULL, m37_reset },
	{ p32c8init,	prg32initGet8,		m38_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m41_init,		prg32initGet8,		m41_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m41_reset },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m44_init,		mmc3initGet8,		m44_initSet8,	mmc3initPPUGet8,	mmc3initPPUSet8,	NULL, m44_reset },
	{ m45_init,		mmc3initGet8,		m45_initSet8,	mmc3initPPUGet8,	mmc3initPPUSet8,	NULL, m45_reset },
	{ m46_init,		prg32initGet8,		m46_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m46_reset },
	{ m47_init,		mmc3NoRAMInitGet8,	m47_initSet8,	mmc3initPPUGet8,	mmc3initPPUSet8,	NULL, m47_reset },
	{ m48init,		prg8initGet8,		m48initSet8,	m48initPPUGet8,		m48initPPUSet8,		m48cycle, NULL },
	{ m49_init,		m49_initGet8,		m49_initSet8,	mmc3initPPUGet8,	mmc3initPPUSet8,	NULL, m49_reset },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m52_init,		mmc3initGet8,		m52_initSet8,	mmc3initPPUGet8,	mmc3initPPUSet8,	NULL, m52_reset },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m57_init,		prg16initGet8,		m57_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m58_init,		prg16initGet8,		m58_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m58_reset },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m60_init,		prg16initGet8,		m60_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m60_reset },
	{ p1632c8init,	prg16initGet8,		m61_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m62_init,		prg16initGet8,		m62_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m62_reset },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m65init,		prg8initGet8,		m65initSet8,	chr1initPPUGet8,	chr1initPPUSet8,	m65cycle, NULL },
	{ p32c8init,	prg32initGet8,		m66_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ s3init,		prg16initGet8,		s3initSet8,		chr2initPPUGet8,	chr2initPPUSet8,	s3cycle, NULL },
	{ s4init,		s4initGet8,			s4initSet8,		s4initPPUGet8,		s4initPPUSet8,		NULL, NULL },
	{ s5Binit,		s5BinitGet8,		s5BinitSet8,	chr1initPPUGet8,	chr1initPPUSet8,	s5Bcycle, NULL },
	{ p16c8init,	prg16initGet8,		m70_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ p16c8init,	prg16initGet8,		m71_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ vrc3init,		vrc3initGet8,		vrc3initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	vrc3cycle, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ vrc1init,		prg8initGet8,		vrc1initSet8,	chr4initPPUGet8,	chr4initPPUSet8,	NULL, NULL },
	{ m206init,		prg8initGet8,		m76initSet8,	m76initChrGet8,		m206initChrSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ p16c8init,	prg16initGet8,		m78_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ p32c8init,	prg32initGet8,		m79_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ vrc7init,		vrc7initGet8,		vrc7initSet8,	chr1initPPUGet8,	chr1initPPUSet8,	vrc_irq_cycle, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ p32c8init,	prg32initGet8,		m87_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m206init,		prg8initGet8,		m88initSet8,	m206initChrGet8,	m206initChrSet8,	NULL, NULL },
	{ p16c8init,	prg16initGet8,		m89_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ p16c8init,	prg16initGet8,		m93_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ p16c8init,	prg16initGet8,		m94_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m95init,		prg8initGet8,		m95initSet8,	m206initChrGet8,	m206initChrSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m97_init,		prg16initGet8,		m97_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ p32c8init,	prg32initGet8,		m101_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ p32c8init,	prg32initGet8,		m107_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m112init,		m112initGet8,		m112initSet8,	m206initChrGet8,	m206initChrSet8,	NULL, NULL },
	{ p32c8init,	prg32initGet8,		m113_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m118init,		mmc3initGet8,		m118initSet8,	mmc3initPPUGet8,	mmc3initPPUSet8,	NULL, NULL },
	{ m119init,		mmc3initGet8,		m119initSet8,	mmc3initPPUGet8,	m119initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m36_init,		m132_initGet8,		m132_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ p32c8init,	prg32initGet8,		m133_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m36_init,		m136_initGet8,		m136_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m137init,		prg32initGet8,		m137initSet8,	chr1initPPUGet8,	chr1initPPUSet8,	NULL, NULL },
	{ m138init,		prg32initGet8,		m138initSet8,	chr2initPPUGet8,	chr2initPPUSet8,	NULL, NULL },
	{ m139init,		prg32initGet8,		m139initSet8,	chr2initPPUGet8,	chr2initPPUSet8,	NULL, NULL },
	{ p32c8init,	prg32initGet8,		m140_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m141init,		prg32initGet8,		m141initSet8,	chr2initPPUGet8,	chr2initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ p32c8init,	prg32initGet8,		m144_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ p32c8init,	prg32initGet8,		m145_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ p32c8init,	prg32initGet8,		m79_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ p32c8init,	prg32initGet8,		m147_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ p32c8init,	prg32initGet8,		m148_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ p32c8init,	prg32initGet8,		m149_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ p16c8init,	prg16initGet8,		m152_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m206init,		prg8initGet8,		m154initSet8,	m206initChrGet8,	m206initChrSet8,	NULL, NULL },
	{ mmc1init,		mmc1initGet8,		mmc1initSet8,	chr4initPPUGet8,	chr4initPPUSet8,	NULL, NULL },
	{ m156init,		m156initGet8,		m156initSet8,	chr1initPPUGet8,	chr1initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m36_init,		m172_initGet8,		m172_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m36_init,		m132_initGet8,		m173_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m174_init,	prg16initGet8,		m174_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m180_init,	prg16initGet8,		m180_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ s1init,		prg16initGet8,		s1initSet8,		chr4initPPUGet8,	chr4initPPUSet8,	NULL, NULL },
	{ m185_init,	prg32initGet8,		m185_initSet8,	m185_initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m193init,		prg8initGet8,		m193initSet8,	chr2initPPUGet8,	chr2initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m200_init,	prg16initGet8,		m200_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ p32c8init,	prg32initGet8,		m201_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m174_init,	prg16initGet8,		m202_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m200_init,	prg16initGet8,		m203_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m205_init,	mmc3NoRAMInitGet8,	m205_initSet8,	mmc3initPPUGet8,	mmc3initPPUSet8,	NULL, m205_reset },
	{ m206init,		prg8initGet8,		m206initSet8,	m206initChrGet8,	m206initChrSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ namco_init,	namco_initGet8,		namco_initSet8,	namco_initPPUGet8,	namco_initPPUSet8,	namco_cycle, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m174_init,	m212_initGet8,		m212_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m221_init,	prg16initGet8,		m221_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m221_reset },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m225init,		m225initGet8,		m225initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m225reset },
	{ m226_init,	prg16initGet8,		m226_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m226_reset },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m228init,		m228initGet8,		m228initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ p1632c8init,	prg16initGet8,		m229_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m230_init,	prg16initGet8,		m230_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m230_reset },
	{ m231_init,	prg16initGet8,		m231_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ m232_init,	prg16initGet8,		m232_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m235_init,	prg16initGet8,		m235_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m235_reset },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ m237init,		m237initGet8,		m237initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m237reset },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ p32c8RAMinit,	p32c8RAMinitGet8,	m240_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ p32c8RAMinit,	p32c8RAMinitGet8,	m242_initSet8,	chr8initPPUGet8,	chr8initPPUSet8,	NULL, m242_reset },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
	{ NULL,			NULL,				NULL,			NULL,				NULL,				NULL, NULL },
};
