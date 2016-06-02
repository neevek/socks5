#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>

void server_usage(const char *cmd, int exit_code) {
  fprintf(stderr, 
      "Usage: %s <options>\n"
      "    --help          print this help message\n"
      "    --host    the host this server is running on\n"
      "    --port    the port this server to be bound\n"
      , cmd);
  exit(exit_code);
}

void check_option_value(void *value, const char *msg) {
  if (value == NULL) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
  }
}

void check_port(int port, const char *msg) {
  if (port == 0) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
  }
}

void handle_server_args(
    int argc, 
    const char **argv, 
    char **host,
    int *port) {

  *host = NULL;
  *port = 0;

  static struct option long_options[] = {
    {"help",          no_argument,       0, 1},
    {"host",    required_argument, 0, 'a'},
    {"port",    required_argument, 0, 'b'},
    {0, 0, 0, 0}
  };

  int optind = 0;
  char c;
  while((c = getopt_long(argc, (char **)argv, "a:b:",
          long_options, &optind)) != -1) {
    switch(c) {
      case 0:
        if (strcmp(long_options[optind].name, "help") == 0) {
          server_usage(argv[0], 0);
        }
        break;
      case 'a':
        *host = optarg;
        break;
      case 'b':
        *port = atoi(optarg);
        check_port(*port, "invalid --port");
        break;
      default:
        server_usage(argv[0], 1);
    }
  }
  check_option_value(*host, "--host is required");
  check_port(*port, "--port is required");
}
