# TempOS

## Welcome to TempOS

Website: http://tempos-project.org

Sources: git clone git@github.com:rene/tempos.git

### ABOUT

	TempOS = TempOS is an educational and multi purpose Operating System

	TempOS was born for an undergraduate work and has it's your main goal
	to be not only another Operating System, but a complete toolkit
	designed to help students on their O.S. courses.

	TempOS it's under a true development stage, which means that it's
	not complete functional yet. The parts currently done are:

		- Multiboot implementation to Boot TempOS with GRUB
		- Page system working with 4Kb pages
		- Re-allocable kernel to 3GB on virtual space
		- A simple memory manager
		- A simple keyboard driver
		- IRQ system with shared IRQs support
		- Alarm timers
		- A poor video (text mode) driver
		- System calls support
		- Generic ATA driver
		- Kernel Multithreading

### HISTORY
	TempOS was born as an undergraduate project designed by
	Renê de Souza Pinto (computer engineering student) at
	University of São Paulo - USP, at São Carlos, from Brazil.
	The principal goal it's build a O.S. as a toolkit to help
	students at their O.S. courses, providing a real and not so
	complex project that students can put their hands on,
	understanding the principles and theories of Operating Systems
	in a pratical way.


### AUTHOR
	TempOS was written by Renê de Souza Pinto and supervised by
	the PhD professor Francisco José Monaco, at University of
	São Paulo - USP, from São Carlos - Brazil.

	Author E-mail: rene@renesp.com.br
                   rene@icmc.usp.br
                   http://renesp.com.br (in portuguese)

	PhD professor: Francisco José Monaco
                   monaco@icmc.usp.br
                   http://www.icmc.usp.br/~monaco


### PROJECT'S DIRECTORY ORGANIZATION

- kernel: Source code of the kernel. 
- rootfs: Root file system (files, directories, scripts, etc).
- apps:   Applications to run on TempOS.

