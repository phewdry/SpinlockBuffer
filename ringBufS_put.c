#define __RINGBUFS_PUT_C
/****************************************************************************/
/*    FILE: ringBufS_put.c                                                  */
/*                                                                          */
/****************************************************************************/
#include  "modulo.h"
#include  "ringBufS.h"

void ringBufS_put (ringBufS *_this, const unsigned char c)
{
    if (_this->count < RBUF_SIZE)
    {
      _this->buf[_this->head] = c;
      _this->head = modulo_inc (_this->head, RBUF_SIZE);
      ++_this->count;
    }
}
