#define __RINGBUFS_GET_C
/****************************************************************************/
/*    FILE: ringBufS_get.c                                                  */
/*                                                                          */
/*    These files contain the attributes and methods needed to manage a     */
/*    256-byte ring buffer. It turns out that we do this so much, that it   */
/*    may be a good idea to just make a library that does this.             */
/*                                                                          */
/****************************************************************************/
#include  "modulo.h"
#include  "ringBufS.h"

int ringBufS_get (ringBufS *_this)
{
    int c;
    if (_this->count>0)
    {
      c = _this->buf[_this->tail];
      _this->tail = modulo_inc (_this->tail, RBUF_SIZE);
      --_this->count;
    }
    else
    {
      c = -1;
    }
    return (c);
}
