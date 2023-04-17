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

enum world_log_level {
    WORLD_LOG_LEVEL_DEBUG,
    WORLD_LOG_LEVEL_INFO,
    WORLD_LOG_LEVEL_WARN,
    WORLD_LOG_LEVEL_ERROR,
    WORLD_LOG_LEVEL_FATAL,
};

int world_log_init(void);
int world_log(enum world_log_level level, const char *fmt, ...);

#endif /* WORLD_LOGGER_H */