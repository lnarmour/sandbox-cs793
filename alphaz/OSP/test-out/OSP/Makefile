CFLAGS= -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES=-lm
CC?=gcc
OBJS = OSP.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) OSP_verify.o
	$(CC) OSP-wrapper.c -o OSP.verify $(OBJS) OSP_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) OSP_verify.o
	$(CC) OSP-wrapper.c -o OSP.verify-rand $(OBJS) OSP_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

OSP.o : OSP.c
	$(CC) OSP.c -o OSP.o $(CFLAGS) $(LIBRARIES) -c

OSP_verify.o : OSP_verify.c
	$(CC) OSP_verify.c -o OSP_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o OSP OSP.check OSP.verify OSP.verify-rand
