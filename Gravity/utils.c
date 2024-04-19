//
//  utils.c
//  Gravity
//
//  Created by Yusuf Jaafar on 19/04/2024.
//

#include "utils.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int randnum(int min, int max)
{
    static bool initialised = false;
    if (!initialised) {
        initialised = true;
        srand((unsigned) time(NULL));
    }
    return rand() % (min + max);
}

int randcolor(void)
{
    return randnum(0, 255);
}
