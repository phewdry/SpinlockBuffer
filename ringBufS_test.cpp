/****************************************************************************/
/*  FILE: ringBufS_test.cpp                                                 */
/*                                                                          */
/****************************************************************************/
#include  <stdio.h>
#include <pthread.h>
#include  "ringBufS.h"

int main(int argc, char* argv[])
{
  int i;
  ringBufS my_ringBuffer;
  int my_status;
  ringBufS_init (&my_ringBuffer);

  printf("\nfifo empty status = %d", ringBufS_empty (&my_ringBuffer));

  puts ("\nThe following is the FIFO FULL status");
  for (i=0;i<RBUF_SIZE;i++)
  {
    ringBufS_put (&my_ringBuffer, (unsigned char)i);
    my_status = ringBufS_full(&my_ringBuffer);
    if (0==(i%16))
    {
      putchar ('\n');
    }
    printf("%2d ", my_status);
  }

  printf("\nfifo empty status = %d", ringBufS_empty (&my_ringBuffer));
  puts ("\nThe following is the contents of the FIFO");
  for (i=0;i<RBUF_SIZE;i++)
  {
    int my_datum = ringBufS_get(&my_ringBuffer);
    if (0==(i%16))
    {
      putchar ('\n');
    }
    printf("%02X ",my_datum);
  }
  printf("\nfifo empty status = %d", ringBufS_empty (&my_ringBuffer));

  putchar ('\n');
  return 0;
}
