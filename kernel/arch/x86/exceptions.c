/*
 * Copyright (C) 2009 Renê de Souza Pinto
 * Tempos - Tempos is an Educational and multi purpose Operating System
 *
 * File: exceptions.c
 * Desc: Functions to handle processor exceptions
 *
 * This file is part of TempOS.
 *
 * TempOS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * TempOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <tempos/kernel.h>
#include <x86/x86.h>
#include <x86/exceptions.h>


void ex_div(pt_regs regs)
{
	dump_cpu_regs(&regs);
	panic("Division by ZERO!");
}


void ex_debug()
{
        gdb_exception_enter();
	kprintf("EXCEP: DEBUG\n");
}


void ex_nmi()
{
	kprintf("EXCEP: NMI\n");
}


void ex_break()
{
	kprintf("EXCEP: BRK\n");
}


void ex_overflow()
{
	kprintf("EXCEP: OVERFLOW\n");
}


void ex_bounds()
{
	kprintf("EXCEP: BOUNDS\n");
}


void ex_inv_op()
{
	kprintf("EXCEP: INVALID OP\n");
}


void ex_device()
{
	kprintf("EXCEP: DEVICE\n");
}


void ex_dfault(int code)
{
	panic("EXCEP: DEFAULT\n");
}


void ex_coproc(int code)
{
	kprintf("EXCEP: COPROC\n");
}


void ex_inv_tss(int code)
{
	panic("EXCEP: INVALID TSS\n");
}


void ex_segnp(int code)
{
	panic("EXCEP: SEGNP\n");
}


void ex_stack(int code)
{
	panic("EXCEP: STACK\n");
}


void ex_gp(int code, pt_regs regs)
{
	dump_cpu_regs(&regs);
	panic("GENERAL PROTECTION FAULT: code %d", code);
}


/**
 * Page fault - This fault should be handle by mm 
 */
void ex_pfault(int code, pt_regs regs)
{
	dump_cpu_regs(&regs);
	panic("PAGE FAULT");
}


void ex_floatp()
{
	kprintf("EXCEP: FLOATP\n");
}


void ex_align(int code)
{
	panic("EXCEP: ALIGN\n");
}


void ex_machine()
{
	kprintf("EXCEP: MACHINE\n");
}


void ex_simd()
{
	kprintf("EXCEP: SIMD\n");
}


