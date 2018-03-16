#define __RINGBUFS_INIT_C
/****************************************************************************/
/*    FILE: ringBufS_init.c                                                 */
/****************************************************************************/
#include  <string.h>
#include  "ringBufS.h"

void ringBufS_init (ringBufS *_this)
{
    /*****
      The following clears:
        -> buf
        -> head
        -> tail
        -> count
      and sets head = tail
    ***/
    memset (_this, 0, sizeof (*_this));
}
