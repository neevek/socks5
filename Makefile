CC=gcc
# https://github.com/libuv/libuv/issues/891
CFLAGS=-c -Wall -O0 -g -DLOG_VERBOSE -std=c99 -D_GNU_SOURCE -Wno-deprecated-declarations -DNO_TERM_COLOR
LDFLAGS=-luv

SRCS=alloc.c server.c socks5.c util.c cli.c
OBJS=$(SRCS:.c=.o)
EXECUTABLE=socks5

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)
