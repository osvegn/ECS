/*
 * Filename: source/world_logger.c
 * Path: source
 * Created Date: Monday, April 17th 2023, 11:32:33 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "world_logger.h"
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

FILE *file = NULL;

int world_log_init(FILE *f)
{
    char buffer[26] = {0};
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char filename[40] = {0};

    if (f != NULL) {
        file = f;
    } else {
        if (access("log", F_OK) == -1) {
            if (mkdir("log", 0777) == -1) {
                return -1;
            }
        }
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", t);
        sprintf(filename, "log/world-%s.log", buffer);
        file = fopen(filename, "a");
        if (file == NULL)
            return -1;
    }
    return 0;
}

static int print_log_time(void)
{
    char buffer[26] = {0};
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S\t", t);
    fprintf(file, "%s", buffer);
    fflush(file);
    return 0;
}

static int print_log_level(enum world_log_level level)
{
    switch (level) {
    case WORLD_LOG_LEVEL_DEBUG:
        fprintf(file, "DEBUG\t");
        break;
    case WORLD_LOG_LEVEL_INFO:
        fprintf(file, "INFO\t");
        break;
    case WORLD_LOG_LEVEL_WARN:
        fprintf(file, "WARN\t");
        break;
    case WORLD_LOG_LEVEL_ERROR:
        fprintf(file, "ERROR\t");
        break;
    case WORLD_LOG_LEVEL_FATAL:
        fprintf(file, "FATAL\t");
        break;
    default:
        fprintf(file, "UNKNOWN\t");
        break;
    }
    fflush(file);
    return 0;
}

int world_log(enum world_log_level level, const char *filename, int line, const char *fmt, ...)
{
    va_list args;
    int rvalue = 0;
    char *buf = NULL;

    if (file == NULL)
        return -1;
    print_log_time();
    print_log_level(level);
    buf = getcwd(NULL, 0);
    if (buf == NULL)
        return -1;
    if (buf != NULL) {
        buf = strstr(filename, buf);
        fprintf(file, "{cwd}%s:%d\t", buf + strlen(buf), line);
    } else {
        fprintf(file, "%s:%d\t", filename, line);
    }
    va_start(args, fmt);
    rvalue = vfprintf(file, fmt, args);
    fprintf(file, "\n");
    va_end(args);
    fflush(file);
    return rvalue;
}

void world_log_destroy(void)
{
    if (file)
        fclose(file);
}
