CFLAGS= -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES=-lm
CC?=gcc
OBJS = Sched0.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) Sched0-wrapper.c -o Sched0 $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) Sched0-wrapper.c -o Sched0.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) Sched0_verify.o
	$(CC) Sched0-wrapper.c -o Sched0.verify $(OBJS) Sched0_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) Sched0_verify.o
	$(CC) Sched0-wrapper.c -o Sched0.verify-rand $(OBJS) Sched0_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

Sched0.o : Sched0.c
	$(CC) Sched0.c -o Sched0.o $(CFLAGS) $(LIBRARIES) -c

Sched0_verify.o : Sched0_verify.c
	$(CC) Sched0_verify.c -o Sched0_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o Sched0 Sched0.check Sched0.verify Sched0.verify-rand
