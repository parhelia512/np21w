/*
 * QEMU Cirrus CLGD 54xx VGA Emulator.
 *
 * Copyright (c) 2004 Fabrice Bellard
 * Copyright (c) 2004 Makoto Suzuki (suzu)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
/*
 * Reference: Finn Thogersons' VGADOC4b
 *   available at http://home.worldonline.dk/~finth/
 */

#pragma once

#define CIRRUS_VRAM_SIZE	(4096 * 1024)

typedef	signed char		int8_t;
typedef	unsigned char	uint8_t;
typedef	signed short	int16_t;
typedef	unsigned short	uint16_t_;
typedef	signed int		int32_t;
typedef	unsigned int	uint32_t_;
#if defined(WIN32) || defined(WIN64)
typedef	signed __int64	int64_t;
typedef	unsigned __int64	uint64_t;
#else
typedef	signed long long	int64_t;
typedef	unsigned long long	uint64_t;
#endif

typedef uint32_t_ ram_addr_t;
typedef uint32_t_ target_phys_addr_t;

typedef void CPUWriteMemoryFunc(void *opaque, target_phys_addr_t addr, uint32_t_ value);
typedef uint32_t_ CPUReadMemoryFunc(void *opaque, target_phys_addr_t addr);

extern CPUWriteMemoryFunc *g_cirrus_linear_write[3];

uint32_t_ cirrus_vga_mem_readb(void *opaque, target_phys_addr_t addr);
uint32_t_ cirrus_vga_mem_readw(void *opaque, target_phys_addr_t addr);
uint32_t_ cirrus_vga_mem_readl(void *opaque, target_phys_addr_t addr);
void cirrus_vga_mem_writeb(void *opaque, target_phys_addr_t addr, uint32_t_ val);
void cirrus_vga_mem_writew(void *opaque, target_phys_addr_t addr, uint32_t_ val);
void cirrus_vga_mem_writel(void *opaque, target_phys_addr_t addr, uint32_t_ val);

uint32_t_ cirrus_linear_readb(void *opaque, target_phys_addr_t addr);
uint32_t_ cirrus_linear_readw(void *opaque, target_phys_addr_t addr);
uint32_t_ cirrus_linear_readl(void *opaque, target_phys_addr_t addr);
void cirrus_linear_writeb(void *opaque, target_phys_addr_t addr, uint32_t_ val);
void cirrus_linear_writew(void *opaque, target_phys_addr_t addr, uint32_t_ val);
void cirrus_linear_writel(void *opaque, target_phys_addr_t addr, uint32_t_ val);

uint32_t_ cirrus_linear_bitblt_readb(void *opaque, target_phys_addr_t addr);
uint32_t_ cirrus_linear_bitblt_readw(void *opaque, target_phys_addr_t addr);
uint32_t_ cirrus_linear_bitblt_readl(void *opaque, target_phys_addr_t addr);
void cirrus_linear_bitblt_writeb(void *opaque, target_phys_addr_t addr, uint32_t_ val);
void cirrus_linear_bitblt_writew(void *opaque, target_phys_addr_t addr, uint32_t_ val);
void cirrus_linear_bitblt_writel(void *opaque, target_phys_addr_t addr, uint32_t_ val);

uint32_t_ cirrus_linear_memwnd_readb(void *opaque, target_phys_addr_t addr);
uint32_t_ cirrus_linear_memwnd_readw(void *opaque, target_phys_addr_t addr);
uint32_t_ cirrus_linear_memwnd_readl(void *opaque, target_phys_addr_t addr);
void cirrus_linear_memwnd_writeb(void *opaque, target_phys_addr_t addr, uint32_t_ val);
void cirrus_linear_memwnd_writew(void *opaque, target_phys_addr_t addr, uint32_t_ val);
void cirrus_linear_memwnd_writel(void *opaque, target_phys_addr_t addr, uint32_t_ val);

uint32_t_ cirrus_mmio_readb(void *opaque, target_phys_addr_t addr);
uint32_t_ cirrus_mmio_readw(void *opaque, target_phys_addr_t addr);
uint32_t_ cirrus_mmio_readl(void *opaque, target_phys_addr_t addr);
void cirrus_mmio_writeb(void *opaque, target_phys_addr_t addr, uint32_t_ val);
void cirrus_mmio_writew(void *opaque, target_phys_addr_t addr, uint32_t_ val);
void cirrus_mmio_writel(void *opaque, target_phys_addr_t addr, uint32_t_ val);

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	UINT32	VRAMWindowAddr;
	UINT32	VRAMWindowAddr2;
	REG8	mmioenable;
} NP2CLVGA;

extern UINT8	cirrusvga_statsavebuf[CIRRUS_VRAM_SIZE + 1024 * 1024];

extern void		*cirrusvga_opaque;
extern NP2CLVGA	np2clvga;
	
void cirrusvga_drawGraphic();

// 無理矢理外から呼べるように
void pc98_cirrus_vga_init(void);
void pc98_cirrus_vga_reset(const NP2CFG *pConfig);
void pc98_cirrus_vga_bind(void);
void pc98_cirrus_vga_shutdown(void);

void pc98_cirrus_vga_save(void);
void pc98_cirrus_vga_load(void);

#ifdef __cplusplus
}
#endif

