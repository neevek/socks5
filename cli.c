#include <stdio.h>
#include <stdint.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>

void local_server_usage(const char *cmd, int exit_code) {
  fprintf(stderr, 
      "Usage: %s <options>\n"
      "    -h, --local_host    the host this server is running on\n"
      "    -p, --local_port    the port this server to be bound\n"
      "    -u, --user          run as user\n"
      "    -l, --log_file      path to log file, stderr if absent\n"
      "    -D, --daemon        run the process in the background\n"
      "    --help          print this help message\n"
      , cmd);
  exit(exit_code);
}

void check_option_value(void *value, const char *msg, const char *cmd) {
  if (value == NULL) {
    fprintf(stderr, "%s\n", msg);
    local_server_usage(cmd, 0);
  }
}

void handle_local_server_args(
    int argc, 
    const char **argv, 
    char **local_host,
    int *local_port,
    char **user,
    char **log_file,
    int *daemon_flag
    ) {

  *local_host = NULL;
  *local_port = 0;
  *log_file = NULL;
  *user = NULL;

  static struct option long_options[] = {
    {"help",          no_argument,       0, 1},
    {"local_host",    required_argument, 0, 'h'},
    {"local_port",    required_argument, 0, 'p'},
    {"user",          required_argument, 0, 'u'},
    {"log_file",      required_argument, 0, 'l'},
    {"daemon",        no_argument,       0, 'D'},
    {0, 0, 0, 0}
  };

  int optind = 0;
  char c;
  while((c = getopt_long(argc, (char **)argv, "h:p:u:l:D",
          long_options, &optind)) != -1) {
    switch(c) {
      case 0:
        if (strcmp(long_options[optind].name, "help") == 0) {
          local_server_usage(argv[0], 0);
        }
        break;
      case 'h':
        *local_host = optarg;
        break;
      case 'p':
        *local_port = atoi(optarg);
        check_option_value((void *)(intptr_t)*local_port, 
            "invalid value for <-p, --local_port>", argv[0]);
        break;
      case 'u':
        *user = optarg;
        break;
      case 'l':
        *log_file = optarg;
        break;
      case 'D':
        *daemon_flag = 1;
        break;
      default:
        local_server_usage(argv[0], 1);
    }
  }
  check_option_value(*local_host, "<-h, --local_host> is required", argv[0]);
  check_option_value((void *)(intptr_t)*local_port, "<-p, --local_port> is required", argv[0]);
}
