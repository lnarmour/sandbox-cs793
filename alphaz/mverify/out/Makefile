CFLAGS= -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES=-lm
CC?=gcc
OBJS = Jax.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) Jax-wrapper.c -o Jax $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) Jax-wrapper.c -o Jax.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) Jax_verify.o
	$(CC) Jax-wrapper.c -o Jax.verify $(OBJS) Jax_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) Jax_verify.o
	$(CC) Jax-wrapper.c -o Jax.verify-rand $(OBJS) Jax_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

Jax.o : Jax.c
	$(CC) Jax.c -o Jax.o $(CFLAGS) $(LIBRARIES) -c

Jax_verify.o : Jax_verify.c
	$(CC) Jax_verify.c -o Jax_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o Jax Jax.check Jax.verify Jax.verify-rand
