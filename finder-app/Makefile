
GCC = gcc

CFLAGS = -Wall

writer: writer.c
	"${CROSS_COMPILE}${GCC}" $(CFLAGS) writer.c -o writer

all:
	@echo ${CROSS_COMPILE}
clean:
	rm -f *.o writer