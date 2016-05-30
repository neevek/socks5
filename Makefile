CC=gcc
CFLAGS=-c -Wall -O0 -g -DLOG_VERBOSE -std=c99
LDFLAGS=-luv

SRCS=alloc.c local.c socks5.c util.c cli.c
OBJS=$(SRCS:.c=.o)
EXECUTABLE=socks5

$(info $(OBJS_REMOTE))

all: $(EXECUTABLE) $(EXECUTABLE_REMOTE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -f $(OBJS) $(EXECUTABLE)
