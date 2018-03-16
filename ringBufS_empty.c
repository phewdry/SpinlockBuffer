#define __RINGBUFS_EMPTY_C
/****************************************************************************/
/*    FILE: ringBufS_empty.c                                                */
/****************************************************************************/
#include  "ringBufS.h"

int ringBufS_empty (ringBufS *_this)
{
    return (0==_this->count);
}
