/* Copyright © 2023 Noah Santer <n.ed.santer@gmail.com>
 *
 * This file is part of cards.
 *
 * cards is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cards is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with cards.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#include "ini/opts.h"

struct settings {
    char * title;
    size_t width;
    size_t height;
    bool fullscreen;
} settings = {
    .title = NULL,
    .width = 800,
    .height = 600,
    .fullscreen = false
};

void dummy() { }

static int set_string(const char * key, const char * value, void * data)
{
    const char ** str = data;
    *str = strdup(value);
    return 0;
}

static int set_bool(const char * key, const char * value, void * data)
{
    bool * b = data;
    if (!value) return 0;

    if (!strcmp(value, "true")) {
        *b = true;
        return 0;
    } else if (!strcmp(value, "false")) {
        *b = false;
        return 0;
    }

    fprintf(stderr, "settings: error parsing bool value of key %s\n", key);
    return 1;
}

static int set_int(const char * key, const char * value, void * data)
{
    int * i = data;
    if (!value) return 0;
    char * eptr;
    long n = strtol(value, &eptr, 0);
    if (*eptr || n > INT_MAX) {
        fprintf(stderr, "settings: error parsing long value of key %s\n", key);
        return 1;
    }
    *i = (int)n;
    return 0;
}

static int load_settings(const char * filename)
{ 
    FILE * cfgf = fopen(filename, "r");
    if (!cfgf) {
        fprintf(stderr, "settings: file \"%s\" not found\n", filename);
        return 1;
    }

    int result = ini_handle(
            cfgf,
            "settings: ",
            NULL,
            INI_STRICT,
            "", INI_STRICT | INI_SKIP,
                NULL,
            "window", INI_STRICT | INI_SKIP,
                "title", INI_SKIP, set_string, &settings.title,
                "width", INI_SKIP, set_int, &settings.width,
                "height", INI_SKIP, set_int, &settings.height,
                "fullscreen", INI_SKIP, set_bool, &settings.fullscreen,
                NULL,
            NULL
        );

    fclose(cfgf);
    return result;
}

static void free_settings()
{
    free(settings.title);
}

int main(int argc, char ** argv)
{
    if (load_settings("settings.ini")) {
        fprintf(stderr, "error loading settings\n");
        return 1;
    }

    printf("title: %s\n", settings.title);

    free_settings();
}
