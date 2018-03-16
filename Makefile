

all:
	mkdir obj_dir
	gcc -g -c ringBufS_test.cpp ringBufS_get.c  ringBufS_put.c  ringBufS_full.c  ringBufS_empty.c  ringBufS_init.c ringBufS.h modulo.c
	gcc -g -o ringBufS_test ringBufS_test.o ringBufS_get.o  ringBufS_put.o  ringBufS_full.o  ringBufS_empty.o  ringBufS_init.o modulo.o
	mv *.o ./obj_dir
	mv *.gch ./obj_dir

clean:
	rm -rf obj_dir
