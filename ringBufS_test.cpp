/****************************************************************************/
/*  FILE: ringBufS_test.cpp                                                 */
/*                                                                          */
/****************************************************************************/
#include  <stdio.h>
#include <pthread.h>
#include  "ringBufS.h"
#include <stdint.h>
#include <cstring>

static const int thread_ct = 2;

void* thread_func(void * args) {
  ringBufS *my_ringBuffer = (ringBufS*)args; 
  for (int i = 0; i < RBUF_SIZE; i++) {
      my_ringBuffer->buf[i] = 0;
  }
  
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
  struct thread_data data_arr[2];
  pthread_t thread_arr[2];
  void *void_ring = std::memcpy(&void_ring ,&my_ringBuffer,sizeof(void_ring));

  for (int i = 0; i < 2; i++) {
      data_arr[i].id  = i;
      pthread_create( &thread_arr[i],NULL,&thread_func, (void*)&void_ring);
  }

  for (int i = 0; i < 2; i++) {
      pthread_join(thread_arr[i],NULL);
  }


  
  return 0;
}
