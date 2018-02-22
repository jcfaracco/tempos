/*
 * Copyright (C) 2009 Renê de Souza Pinto
 * Tempos - Tempos is an Educational and multi purpose Operating System
 *
 * File: kgdb.c
 * Desc: Implements kgdb methods.
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
#include <x86/atomic.h>

static unsigned int kgdb_break_asap;
int32_t kgdb_setting_breakpoint;

static inline void arch_kgdb_breakpoint(void)
{
        asm("   int $3");
}

void kgdb_breakpoint(void)
{
        atomic_incl(&kgdb_setting_breakpoint);
//        wmb(); /* Sync point before breakpoint */
        arch_kgdb_breakpoint();
//        wmb(); /* Sync point after breakpoint */
        atomic_decl(&kgdb_setting_breakpoint);
}

void kgdb_initial_breakpoint(void)
{
        /* TODO add early kgdb load.
        if (!kgdb_break_asap)
                return;
	*/

        kgdb_break_asap = 0;
	kprintf(KERN_INFO "kgdb: Waiting for connection from remote gdb...\n");
        kgdb_breakpoint();
}
