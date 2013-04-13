/*
 * Table Print utilities
 * Copyright (C) 2012-2013 Paul Ionkin <paul.ionkin@gmail.com>
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */
#ifndef _T_PRINT_H_
#define _T_PRINT_H_

#include <stdio.h>
#include <glib.h>

typedef struct _TPrint TPrint;

typedef enum {
    TPAlign_left = 0,
    TPAlign_center = 1,
    TPAlign_right = 2,
} TPrintAlign;

// create TPrint object
// fout: FILE to write table to. Must be opened with write permissions. Can specify stdout / stderr
// borders: set to TRUE to draw inner and outer borders
// show_header: set to TRUE to display table header row
// spaces_left: spaces on the left side of the table
// spaces_between: spaces between columns
TPrint *tprint_create (FILE *fout, gboolean borders, gboolean show_header, gint spaces_left, gint spaces_between);
// destroy TPrint object
void tprint_free (TPrint *tprint);

// Append column to the table
// caption: label of the column, can be NULL
// caption_align: how to align column caption
// data_align: how to align data in the column
void tprint_column_add (TPrint *tprint, const gchar *caption, TPrintAlign caption_align, TPrintAlign data_align);

// set table format for double numbers
void tprint_set_double_fmt (TPrint *tprint, const gchar *fmt);
// set table format for int32 numbers
void tprint_set_int32_fmt (TPrint *tprint, const gchar *fmt);

void tprint_data_add_int32 (TPrint *tprint, gint col, gint32 data);
void tprint_data_add_uint64 (TPrint *tprint, gint col, guint64 data);
void tprint_data_add_str (TPrint *tprint, gint col, const gchar *data);
void tprint_data_add_double (TPrint *tprint, gint col, gdouble data);

// output table to the specified FILE
void tprint_print (TPrint *tprint);

#endif
