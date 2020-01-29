CFLAGS= -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES=-lm
CC?=gcc
OBJS = LUD.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) LUD-wrapper.c -o LUD $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) LUD-wrapper.c -o LUD.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) LUD_verify.o
	$(CC) LUD-wrapper.c -o LUD.verify $(OBJS) LUD_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) LUD_verify.o
	$(CC) LUD-wrapper.c -o LUD.verify-rand $(OBJS) LUD_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

LUD.o : LUD.c
	$(CC) LUD.c -o LUD.o $(CFLAGS) $(LIBRARIES) -c

LUD_verify.o : LUD_verify.c
	$(CC) LUD_verify.c -o LUD_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o LUD LUD.check LUD.verify LUD.verify-rand
