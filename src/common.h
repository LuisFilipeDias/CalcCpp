#pragma once
#include <iostream>
#include <string>

#define TRACE TRACE_WARNING

typedef enum{
    ERR_NONE = 0,
    ERR_INVALID_MODE
} t_Error;

typedef enum{
    MODE_BASIC = '1',
    MODE_SCIENTIFIC,
    MODE_PROGRAMMER,

    MODE_Exit = 'x',
    MODE_EXIT = 'X',

    MODE_NONE = -1
} t_Mode;

typedef enum{
    TRACE_DEBUG = 0,
    TRACE_WARNING,
    TRACE_ERROR,
    TRACE_FATAL,
    TRACE_INFO
} t_Trace;
