/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Thomas Otto <tommi@viadmin.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/f1/dma.h>

void dma_enable_mem2mem_mode(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) |= DMA_CCR1_MEM2MEM;
		DMA_CCR1(dma) &= ~DMA_CCR1_CIRC;
		break;
	case 2:
		DMA_CCR2(dma) |= DMA_CCR2_MEM2MEM;
		DMA_CCR2(dma) &= ~DMA_CCR2_CIRC;
		break;
	case 3:
		DMA_CCR3(dma) |= DMA_CCR3_MEM2MEM;
		DMA_CCR3(dma) &= ~DMA_CCR3_CIRC;
		break;
	case 4:
		DMA_CCR4(dma) |= DMA_CCR4_MEM2MEM;
		DMA_CCR4(dma) &= ~DMA_CCR4_CIRC;
		break;
	case 5:
		DMA_CCR5(dma) |= DMA_CCR5_MEM2MEM;
		DMA_CCR5(dma) &= ~DMA_CCR5_CIRC;
		break;
	case 6:
		if (dma == DMA1) {
			DMA_CCR6(dma) |= DMA_CCR6_MEM2MEM;
			DMA_CCR6(dma) &= ~DMA_CCR6_CIRC;
		}
		break;
	case 7:
		if (dma == DMA1) {
			DMA_CCR7(dma) |= DMA_CCR7_MEM2MEM;
			DMA_CCR7(dma) &= ~DMA_CCR7_CIRC;
		}
		break;
	}
}

void dma_set_priority(u32 dma, u8 channel, u8 prio)
{
	if (prio > 3)
		return;

	switch (channel) {
	case 1:
		DMA_CCR1(dma) &= ~(0x3 << DMA_CCR1_PL_LSB);
		DMA_CCR1(dma) |= (prio << DMA_CCR1_PL_LSB);
		break;
	case 2:
		DMA_CCR2(dma) &= ~(0x3 << DMA_CCR2_PL_LSB);
		DMA_CCR2(dma) |= (prio << DMA_CCR2_PL_LSB);
		break;
	case 3:
		DMA_CCR3(dma) &= ~(0x3 << DMA_CCR3_PL_LSB);
		DMA_CCR3(dma) |= (prio << DMA_CCR3_PL_LSB);
		break;
	case 4:
		DMA_CCR4(dma) &= ~(0x3 << DMA_CCR4_PL_LSB);
		DMA_CCR4(dma) |= (prio << DMA_CCR4_PL_LSB);
		break;
	case 5:
		DMA_CCR5(dma) &= ~(0x3 << DMA_CCR5_PL_LSB);
		DMA_CCR5(dma) |= (prio << DMA_CCR5_PL_LSB);
		break;
	case 6:
		if (dma == DMA1) {
			DMA_CCR6(dma) &= ~(0x3 << DMA_CCR6_PL_LSB);
			DMA_CCR6(dma) |= (prio << DMA_CCR6_PL_LSB);
		}
		break;
	case 7:
		if (dma == DMA1) {
			DMA_CCR7(dma) &= ~(0x3 << DMA_CCR7_PL_LSB);
			DMA_CCR7(dma) |= (prio << DMA_CCR7_PL_LSB);
		}
		break;
	}
}

void dma_set_memory_size(u32 dma, u8 channel, u8 mem_size)
{
	if (mem_size > 2)
		return;

	switch (channel) {
	case 1:
		DMA_CCR1(dma) &= ~(0x3 << DMA_CCR1_MSIZE_LSB);
		DMA_CCR1(dma) |= (mem_size << DMA_CCR1_MSIZE_LSB);
		break;
	case 2:
		DMA_CCR2(dma) &= ~(0x3 << DMA_CCR2_MSIZE_LSB);
		DMA_CCR2(dma) |= (mem_size << DMA_CCR2_MSIZE_LSB);
		break;
	case 3:
		DMA_CCR3(dma) &= ~(0x3 << DMA_CCR3_MSIZE_LSB);
		DMA_CCR3(dma) |= (mem_size << DMA_CCR3_MSIZE_LSB);
		break;
	case 4:
		DMA_CCR4(dma) &= ~(0x3 << DMA_CCR4_MSIZE_LSB);
		DMA_CCR4(dma) |= (mem_size << DMA_CCR4_MSIZE_LSB);
		break;
	case 5:
		DMA_CCR5(dma) &= ~(0x3 << DMA_CCR5_MSIZE_LSB);
		DMA_CCR5(dma) |= (mem_size << DMA_CCR5_MSIZE_LSB);
		break;
	case 6:
		if (dma == DMA1) {
			DMA_CCR6(dma) &= ~(0x3 << DMA_CCR6_MSIZE_LSB);
			DMA_CCR6(dma) |= (mem_size << DMA_CCR6_MSIZE_LSB);
		}
		break;
	case 7:
		if (dma == DMA1) {
			DMA_CCR7(dma) &= ~(0x3 << DMA_CCR7_MSIZE_LSB);
			DMA_CCR7(dma) |= (mem_size << DMA_CCR7_MSIZE_LSB);
		}
		break;
	}
}

void dma_set_peripheral_size(u32 dma, u8 channel, u8 peripheral_size)
{
	if (peripheral_size > 2)
		return;

	switch (channel) {
	case 1:
		DMA_CCR1(dma) &= ~(0x3 << DMA_CCR1_PSIZE_LSB);
		DMA_CCR1(dma) |= (peripheral_size << DMA_CCR1_PSIZE_LSB);
		break;
	case 2:
		DMA_CCR2(dma) &= ~(0x3 << DMA_CCR2_PSIZE_LSB);
		DMA_CCR2(dma) |= (peripheral_size << DMA_CCR2_PSIZE_LSB);
		break;
	case 3:
		DMA_CCR3(dma) &= ~(0x3 << DMA_CCR3_PSIZE_LSB);
		DMA_CCR3(dma) |= (peripheral_size << DMA_CCR3_PSIZE_LSB);
		break;
	case 4:
		DMA_CCR4(dma) &= ~(0x3 << DMA_CCR4_PSIZE_LSB);
		DMA_CCR4(dma) |= (peripheral_size << DMA_CCR4_PSIZE_LSB);
		break;
	case 5:
		DMA_CCR5(dma) &= ~(0x3 << DMA_CCR5_PSIZE_LSB);
		DMA_CCR5(dma) |= (peripheral_size << DMA_CCR5_PSIZE_LSB);
		break;
	case 6:
		if (dma == DMA1) {
			DMA_CCR6(dma) &= ~(0x3 << DMA_CCR6_PSIZE_LSB);
			DMA_CCR6(dma) |=
			    (peripheral_size << DMA_CCR6_PSIZE_LSB);
		}
		break;
	case 7:
		if (dma == DMA1) {
			DMA_CCR7(dma) &= ~(0x3 << DMA_CCR7_PSIZE_LSB);
			DMA_CCR7(dma) |=
			    (peripheral_size << DMA_CCR7_PSIZE_LSB);
		}
		break;
	}
}

void dma_enable_memory_increment_mode(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) |= DMA_CCR1_MINC;
		break;
	case 2:
		DMA_CCR2(dma) |= DMA_CCR2_MINC;
		break;
	case 3:
		DMA_CCR3(dma) |= DMA_CCR3_MINC;
		break;
	case 4:
		DMA_CCR4(dma) |= DMA_CCR4_MINC;
		break;
	case 5:
		DMA_CCR5(dma) |= DMA_CCR5_MINC;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CCR6(dma) |= DMA_CCR6_MINC;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CCR7(dma) |= DMA_CCR7_MINC;
		break;
	}
}

void dma_enable_peripheral_increment_mode(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) |= DMA_CCR1_PINC;
		break;
	case 2:
		DMA_CCR2(dma) |= DMA_CCR2_PINC;
		break;
	case 3:
		DMA_CCR3(dma) |= DMA_CCR3_PINC;
		break;
	case 4:
		DMA_CCR4(dma) |= DMA_CCR4_PINC;
		break;
	case 5:
		DMA_CCR5(dma) |= DMA_CCR5_PINC;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CCR6(dma) |= DMA_CCR6_PINC;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CCR7(dma) |= DMA_CCR7_PINC;
		break;
	}
}

void dma_enable_circular_mode(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) |= DMA_CCR1_CIRC;
		DMA_CCR1(dma) &= ~DMA_CCR1_MEM2MEM;
		break;
	case 2:
		DMA_CCR2(dma) |= DMA_CCR2_CIRC;
		DMA_CCR2(dma) &= ~DMA_CCR2_MEM2MEM;
		break;
	case 3:
		DMA_CCR3(dma) |= DMA_CCR3_CIRC;
		DMA_CCR3(dma) &= ~DMA_CCR3_MEM2MEM;
		break;
	case 4:
		DMA_CCR4(dma) |= DMA_CCR4_CIRC;
		DMA_CCR4(dma) &= ~DMA_CCR4_MEM2MEM;
		break;
	case 5:
		DMA_CCR5(dma) |= DMA_CCR5_CIRC;
		DMA_CCR5(dma) &= ~DMA_CCR5_MEM2MEM;
		break;
	case 6:
		if (dma == DMA1) {
			DMA_CCR6(dma) |= DMA_CCR6_CIRC;
			DMA_CCR6(dma) &= ~DMA_CCR6_MEM2MEM;
		}
		break;
	case 7:
		if (dma == DMA1) {
			DMA_CCR7(dma) |= DMA_CCR7_CIRC;
			DMA_CCR7(dma) &= ~DMA_CCR7_MEM2MEM;
		}
		break;
	}
}

void dma_set_read_from_peripheral(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) &= ~DMA_CCR1_DIR;
		break;
	case 2:
		DMA_CCR2(dma) &= ~DMA_CCR2_DIR;
		break;
	case 3:
		DMA_CCR3(dma) &= ~DMA_CCR3_DIR;
		break;
	case 4:
		DMA_CCR4(dma) &= ~DMA_CCR4_DIR;
		break;
	case 5:
		DMA_CCR5(dma) &= ~DMA_CCR5_DIR;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CCR6(dma) &= ~DMA_CCR6_DIR;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CCR7(dma) &= ~DMA_CCR7_DIR;
		break;
	}
}

void dma_set_read_from_memory(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) |= DMA_CCR1_DIR;
		break;
	case 2:
		DMA_CCR2(dma) |= DMA_CCR2_DIR;
		break;
	case 3:
		DMA_CCR3(dma) |= DMA_CCR3_DIR;
		break;
	case 4:
		DMA_CCR4(dma) |= DMA_CCR4_DIR;
		break;
	case 5:
		DMA_CCR5(dma) |= DMA_CCR5_DIR;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CCR6(dma) |= DMA_CCR6_DIR;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CCR7(dma) |= DMA_CCR7_DIR;
		break;
	}
}

void dma_enable_transfer_error_interrupt(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) |= DMA_CCR1_TEIE;
		break;
	case 2:
		DMA_CCR2(dma) |= DMA_CCR2_TEIE;
		break;
	case 3:
		DMA_CCR3(dma) |= DMA_CCR3_TEIE;
		break;
	case 4:
		DMA_CCR4(dma) |= DMA_CCR4_TEIE;
		break;
	case 5:
		DMA_CCR5(dma) |= DMA_CCR5_TEIE;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CCR6(dma) |= DMA_CCR6_TEIE;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CCR7(dma) |= DMA_CCR7_TEIE;
		break;
	}
}

void dma_disable_transfer_error_interrupt(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) &= ~DMA_CCR1_TEIE;
		break;
	case 2:
		DMA_CCR2(dma) &= ~DMA_CCR2_TEIE;
		break;
	case 3:
		DMA_CCR3(dma) &= ~DMA_CCR3_TEIE;
		break;
	case 4:
		DMA_CCR4(dma) &= ~DMA_CCR4_TEIE;
		break;
	case 5:
		DMA_CCR5(dma) &= ~DMA_CCR5_TEIE;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CCR6(dma) &= ~DMA_CCR6_TEIE;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CCR7(dma) &= ~DMA_CCR7_TEIE;
		break;
	}
}

void dma_enable_half_transfer_interrupt(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) |= DMA_CCR1_HTIE;
		break;
	case 2:
		DMA_CCR2(dma) |= DMA_CCR2_HTIE;
		break;
	case 3:
		DMA_CCR3(dma) |= DMA_CCR3_HTIE;
		break;
	case 4:
		DMA_CCR4(dma) |= DMA_CCR4_HTIE;
		break;
	case 5:
		DMA_CCR5(dma) |= DMA_CCR5_HTIE;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CCR6(dma) |= DMA_CCR6_HTIE;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CCR7(dma) |= DMA_CCR7_HTIE;
		break;
	}
}

void dma_disable_half_transfer_interrupt(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) &= ~DMA_CCR1_HTIE;
		break;
	case 2:
		DMA_CCR2(dma) &= ~DMA_CCR2_HTIE;
		break;
	case 3:
		DMA_CCR3(dma) &= ~DMA_CCR3_HTIE;
		break;
	case 4:
		DMA_CCR4(dma) &= ~DMA_CCR4_HTIE;
		break;
	case 5:
		DMA_CCR5(dma) &= ~DMA_CCR5_HTIE;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CCR6(dma) &= ~DMA_CCR6_HTIE;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CCR7(dma) &= ~DMA_CCR7_HTIE;
		break;
	}
}

void dma_enable_transfer_complete_interrupt(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) |= DMA_CCR1_TCIE;
		break;
	case 2:
		DMA_CCR2(dma) |= DMA_CCR2_TCIE;
		break;
	case 3:
		DMA_CCR3(dma) |= DMA_CCR3_TCIE;
		break;
	case 4:
		DMA_CCR4(dma) |= DMA_CCR4_TCIE;
		break;
	case 5:
		DMA_CCR5(dma) |= DMA_CCR5_TCIE;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CCR6(dma) |= DMA_CCR6_TCIE;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CCR7(dma) |= DMA_CCR7_TCIE;
		break;
	}
}

void dma_disable_transfer_complete_interrupt(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) &= ~DMA_CCR1_TCIE;
		break;
	case 2:
		DMA_CCR2(dma) &= ~DMA_CCR2_TCIE;
		break;
	case 3:
		DMA_CCR3(dma) &= ~DMA_CCR3_TCIE;
		break;
	case 4:
		DMA_CCR4(dma) &= ~DMA_CCR4_TCIE;
		break;
	case 5:
		DMA_CCR5(dma) &= ~DMA_CCR5_TCIE;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CCR6(dma) &= ~DMA_CCR6_TCIE;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CCR7(dma) &= ~DMA_CCR7_TCIE;
		break;
	}
}

void dma_enable_channel(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) |= DMA_CCR1_EN;
		break;
	case 2:
		DMA_CCR2(dma) |= DMA_CCR2_EN;
		break;
	case 3:
		DMA_CCR3(dma) |= DMA_CCR3_EN;
		break;
	case 4:
		DMA_CCR4(dma) |= DMA_CCR4_EN;
		break;
	case 5:
		DMA_CCR5(dma) |= DMA_CCR5_EN;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CCR6(dma) |= DMA_CCR6_EN;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CCR7(dma) |= DMA_CCR7_EN;
		break;
	}
}

void dma_disable_channel(u32 dma, u8 channel)
{
	switch (channel) {
	case 1:
		DMA_CCR1(dma) &= ~DMA_CCR1_EN;
		break;
	case 2:
		DMA_CCR2(dma) &= ~DMA_CCR2_EN;
		break;
	case 3:
		DMA_CCR3(dma) &= ~DMA_CCR3_EN;
		break;
	case 4:
		DMA_CCR4(dma) &= ~DMA_CCR4_EN;
		break;
	case 5:
		DMA_CCR5(dma) &= ~DMA_CCR5_EN;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CCR6(dma) &= ~DMA_CCR6_EN;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CCR7(dma) &= ~DMA_CCR7_EN;
		break;
	}
}

void dma_set_peripheral_address(u32 dma, u8 channel, u32 address)
{
	switch (channel) {
	case 1:
		DMA_CPAR1(dma) = (u32) address;
		break;
	case 2:
		DMA_CPAR2(dma) = (u32) address;
		break;
	case 3:
		DMA_CPAR3(dma) = (u32) address;
		break;
	case 4:
		DMA_CPAR4(dma) = (u32) address;
		break;
	case 5:
		DMA_CPAR5(dma) = (u32) address;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CPAR6(dma) = (u32) address;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CPAR7(dma) = (u32) address;
		break;
	}
}

void dma_set_memory_address(u32 dma, u8 channel, u32 address)
{
	switch (channel) {
	case 1:
		DMA_CMAR1(dma) = (u32) address;
		break;
	case 2:
		DMA_CMAR2(dma) = (u32) address;
		break;
	case 3:
		DMA_CMAR3(dma) = (u32) address;
		break;
	case 4:
		DMA_CMAR4(dma) = (u32) address;
		break;
	case 5:
		DMA_CMAR5(dma) = (u32) address;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CMAR6(dma) = (u32) address;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CMAR7(dma) = (u32) address;
		break;
	}
}

void dma_set_number_of_data(u32 dma, u8 channel, u16 number)
{
	switch (channel) {
	case 1:
		DMA_CNDTR1(dma) = number;
		break;
	case 2:
		DMA_CNDTR2(dma) = number;
		break;
	case 3:
		DMA_CNDTR3(dma) = number;
		break;
	case 4:
		DMA_CNDTR4(dma) = number;
		break;
	case 5:
		DMA_CNDTR5(dma) = number;
		break;
	case 6:
		if (dma == DMA1)
			DMA_CNDTR6(dma) = number;
		break;
	case 7:
		if (dma == DMA1)
			DMA_CNDTR7(dma) = number;
		break;
	}
}
