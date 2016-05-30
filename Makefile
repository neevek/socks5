CC=gcc
CFLAGS=-c -Wall -O0 -g -DLOG_VERBOSE -std=c99
LDFLAGS=-luv

SRCS=alloc.c server.c socks5.c util.c cli.c
OBJS=$(SRCS:.c=.o)
EXECUTABLE=socks5

all: $(EXECUTABLE) $(EXECUTABLE_REMOTE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -f $(OBJS) $(EXECUTABLE)
