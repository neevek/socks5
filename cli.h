#ifndef CLI_H_
#define CLI_H_

int handle_local_server_args(
    int argc, 
    const char **argv, 
    char **local_host,
    int *local_port,
    char **user,
    char **log_file,
    int *daemon_flag
    );

#endif /* end of include guard: CLI_H_ */
