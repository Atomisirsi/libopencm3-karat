/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
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

/* Generic linker script for LM3S targets using libopencm3. */

/* Memory regions must be defined in the ld script which includes this one. */

/* Enforce emmition of the vector table. */
EXTERN (vector_table)

/* Define sections. */
SECTIONS
{
	. = ORIGIN(rom);

	.text : {
		*(.vectors)	/* Vector table */
		*(.text*)	/* Program code */
		*(.rodata*)	/* Read-only data */
		_etext = .;
	} >rom

	. = ORIGIN(ram);

	.data : {
		_data = .;
		*(.data*)	/* Read-write initialized data */
		_edata = .;
	} >ram AT >rom

	.bss : {
		*(.bss*)	/* Read-write zero initialized data */
		*(COMMON)
		_ebss = .;
	} >ram AT >rom

	/*
	 * The .eh_frame section appears to be used for C++ exception handling.
	 * You may need to fix this if you're using C++.
	 */
	/DISCARD/ : { *(.eh_frame) }

	/*
	 * Another section used by C++ stuff, appears when using newlib with
	 * 64bit (long long) printf support - discard it for now.
	 */
	/DISCARD/ : { *(.ARM.exidx) }

	end = .;
}

PROVIDE(_stack = ORIGIN(ram) + LENGTH(ram));

