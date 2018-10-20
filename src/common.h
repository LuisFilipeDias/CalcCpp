#pragma once
#include <iostream>
#include <string>

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
