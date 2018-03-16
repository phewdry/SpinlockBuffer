/****************************************************************************/
/*  FILE: ringBufS_test.cpp                                                 */
/*                                                                          */
/****************************************************************************/
#include  <stdio.h>
#include <pthread.h>
#include  "ringBufS.h"

void thread_func(ringBufS *my_ringBuffer) {

  int my_status, i;
  printf("\nfifo empty status = %d", ringBufS_empty (my_ringBuffer));

  puts ("\nThe following is the FIFO FULL status");
  for (i=0;i<RBUF_SIZE;i++)
  {
    ringBufS_put (my_ringBuffer, (unsigned char)i);
    my_status = ringBufS_full(my_ringBuffer);
    if (0==(i%16))
    {
      putchar ('\n');
    }
    printf("%2d ", my_status);
  }

  printf("\nfifo empty status = %d", ringBufS_empty (my_ringBuffer));
  puts ("\nThe following is the contents of the FIFO");
  for (i=0;i<RBUF_SIZE;i++)
  {
    int my_datum = ringBufS_get(my_ringBuffer);
    if (0==(i%16))
    {
      putchar ('\n');
    }
    printf("%02X ",my_datum);
  }
  printf("\nfifo empty status = %d", ringBufS_empty (my_ringBuffer));

  putchar ('\n');



}


int main(int argc, char* argv[])
{
  ringBufS my_ringBuffer;
  ringBufS_init (&my_ringBuffer);

  thread_func(&my_ringBuffer);
  
  return 0;
}
