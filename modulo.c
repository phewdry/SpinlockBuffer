#define __MODULO_C
/****************************************************************************/
/*    FILE: modulo.c                                                        */
/*                                                                          */
/****************************************************************************/
#include  "modulo.h"

unsigned int modulo_inc (const unsigned int value, const unsigned int modulus)
{
    unsigned int my_value = value + 1;
    if (my_value >= modulus)
    {
      my_value  = 0;
    }
    return (my_value);
}

unsigned int modulo_dec (const unsigned int value, const unsigned int modulus)
{
    unsigned int my_value = (0==value) ? (modulus - 1) : (value - 1);
    return (my_value);
}
