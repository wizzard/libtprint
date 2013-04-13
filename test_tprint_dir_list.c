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

// Example how to use libtprint to display directory listing

#include "tprint.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

const gchar *get_perm_str (mode_t st_mode)
{
    static gchar out[11];

    out[0] = (S_ISDIR (st_mode)) ? 'd' : '-';
    out[1] = (st_mode & S_IRUSR) ? 'r' : '-';
    out[2] = (st_mode & S_IWUSR) ? 'w' : '-';
    out[3] = (st_mode & S_IXUSR) ? 'x' : '-';
    out[4] = (st_mode & S_IRGRP) ? 'r' : '-';
    out[5] = (st_mode & S_IWGRP) ? 'w' : '-';
    out[6] = (st_mode & S_IXGRP) ? 'x' : '-';
    out[7] = (st_mode & S_IROTH) ? 'r' : '-';
    out[8] = (st_mode & S_IWOTH) ? 'w' : '-';
    out[9] = (st_mode & S_IXOTH) ? 'x' : '-';

    out[10] = '\0';

    return out;
}

const gchar *time_to_str (time_t t)
{
    struct tm *tmp;
    static gchar out[50];

    tmp = localtime (&t);
    strftime (out, sizeof (out), "%b %d %H:%M", tmp);

    return out;
}

int main (int argc, char *argv[])
{
    DIR *dir;
	struct dirent *ent;
    TPrint *tp;
    gchar path[1024];
    gchar dir_name[1024];

    tp = tprint_create (stdout, FALSE, FALSE, 0, 2);

    tprint_column_add (tp, "Permissions", TPAlign_center, TPAlign_left);
    tprint_column_add (tp, "Owner", TPAlign_center, TPAlign_left);
    tprint_column_add (tp, "Size", TPAlign_center, TPAlign_right);
    tprint_column_add (tp, "Time", TPAlign_center, TPAlign_left);
    tprint_column_add (tp, "Name", TPAlign_center, TPAlign_left);

    strncpy (dir_name, argc > 1 ? argv[1] : ".", sizeof (dir_name));
    dir = opendir (dir_name);
    if (!dir) {
        g_fprintf (stderr, "Failed to open directory %s for reading !", dir_name);
        return 1;
    }

    while ((ent = readdir (dir)) != NULL) {
        struct stat stbuf;

        g_snprintf (path, sizeof (path), "%s/%s", dir_name, ent->d_name);

        if (lstat (path, &stbuf)) {
            g_fprintf (stderr, "Failed to open %s for reading !", path);
            continue;
        }

        tprint_data_add_str (tp, 0, get_perm_str (stbuf.st_mode));
        tprint_data_add_int32 (tp, 1, stbuf.st_uid);
        tprint_data_add_uint64 (tp, 2, stbuf.st_size);
        tprint_data_add_str (tp, 3, time_to_str (stbuf.st_mtime));
        tprint_data_add_str (tp, 4, ent->d_name);
    }

    closedir (dir);

    tprint_print (tp);
    tprint_free (tp);

    return 0;
}
