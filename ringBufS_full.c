#define __RINGBUFS_FULL_C
/****************************************************************************/
/*    FILE: ringBufS_full.c                                                 */
/****************************************************************************/
#include  "ringBufS.h"

int ringBufS_full (ringBufS *_this)
{

    // return 1 if true , 0 if false 
    return (_this->count >= RBUF_SIZE);
}
