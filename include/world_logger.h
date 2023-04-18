/*
 * Filename: include/world_logger.h
 * Path: include
 * Created Date: Monday, April 17th 2023, 11:33:09 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#ifndef WORLD_LOGGER_H
#define WORLD_LOGGER_H

#include <stdio.h>

enum world_log_level {
    WORLD_LOG_LEVEL_DEBUG,
    WORLD_LOG_LEVEL_INFO,
    WORLD_LOG_LEVEL_WARN,
    WORLD_LOG_LEVEL_ERROR,
    WORLD_LOG_LEVEL_FATAL,
};

#define log_debug(...) world_log(WORLD_LOG_LEVEL_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define log_info(...) world_log(WORLD_LOG_LEVEL_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(...) world_log(WORLD_LOG_LEVEL_WARN, __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) world_log(WORLD_LOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define log_fatal(...) world_log(WORLD_LOG_LEVEL_FATAL, __FILE__, __LINE__, __VA_ARGS__)

int world_log_init(FILE *f);
int world_log(enum world_log_level level, const char *filename, int line, const char *fmt, ...);
void world_log_destroy(void);

#endif /* WORLD_LOGGER_H */