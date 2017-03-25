/*
 * Copyright (C) 2017 Renê de Souza Pinto
 * Tempos - Tempos is an Educational and multi purpose Operating System
 *
 * File: sort.c
 * Desc: Implements C functions from sort.h
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

#include <sort.h>

static void u32_swap(void *a, void *b, int size)
{
        uint32_t t = *(uint32_t *)a;
        *(uint32_t *)a = *(uint32_t *)b;
        *(uint32_t *)b = t;
}

static void generic_swap(void *a, void *b, int size)
{
        char t;

        do {
                t = *(char *)a;
                *(char *)a++ = *(char *)b;
                *(char *)b++ = t;
        } while (--size > 0);
}

/**
 * sort - sort an array of elements
 * @base: pointer to data to sort
 * @num: number of elements
 * @size: size of each element
 * @cmp_func: pointer to comparison function
 * @swap_func: pointer to swap function or NULL
 *
 * This function does a heapsort on the given array. You may provide a
 * swap_func function optimized to your element type.
 *
 * Sorting time is O(n log n) both on average and worst-case. While
 * qsort is about 20% faster on average, it suffers from exploitable
 * O(n*n) worst-case behavior and extra memory requirements that make
 * it less suitable for kernel use.
 */

void sort(void *base, size_t num, size_t size,
          int (*cmp_func)(const void *, const void *),
          void (*swap_func)(void *, void *, int size))
{
        /* pre-scale counters for performance */
        int i = (num/2 - 1) * size, n = num * size, c, r;

        if (!swap_func)
		swap_func = (size == 4 ? u32_swap : generic_swap);

        /* heapify */
        for ( ; i >= 0; i -= size) {
                for (r = i; r * 2 + size < n; r  = c) {
                        c = r * 2 + size;
                        if (c < n - size &&
                                        cmp_func(base + c, base + c + size) < 0)
                                c += size;
                        if (cmp_func(base + r, base + c) >= 0)
                                break;
                        swap_func(base + r, base + c, size);
                }
        }

        /* sort */
        for (i = n - size; i > 0; i -= size) {
                swap_func(base, base + i, size);
                for (r = 0; r * 2 + size < i; r = c) {
                        c = r * 2 + size;
                        if (c < i - size &&
                                        cmp_func(base + c, base + c + size) < 0)
                                c += size;
                        if (cmp_func(base + r, base + c) >= 0)
                                break;
                        swap_func(base + r, base + c, size);
                }
        }
}

