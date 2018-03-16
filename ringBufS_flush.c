#define __RINGBUFS_FLUSH_C
/****************************************************************************/
/*    FILE: ringBufS_flush.c                                                */
/****************************************************************************/
#include  <string.h>
#include  "ringBufS.h"

void ringBufS_flush (ringBufS *_this, const int clearBuffer)
{
  _this->count  = 0;
  _this->head   = 0;
  _this->tail   = 0;
  if (clearBuffer)
  {
    memset (_this->buf, 0, sizeof (_this->buf));
  }
}
