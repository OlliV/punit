#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "unixunit.h"

/* Stdin writer variables */
static FILE * uu_stdin_writer;
static int uu_pipe[2];

void uu_open_pipe()
{
    /* Open pipe */
    if (pipe(uu_pipe) == -1) {
        fprintf(stderr, "Pipe failed.");
        exit(1);
    }
}

void uu_open_stdin_writer()
{
    dup2(uu_pipe[0], STDIN_FILENO);
    uu_stdin_writer = fdopen(uu_pipe[1], "w");
}

void uu_write_stdin(char * str)
{
    fwrite(str, 1, strlen(str), uu_stdin_writer);
}

void uu_close_stdin_writer()
{
    fclose(uu_stdin_writer);
}

void uu_close_pipe()
{
    /* Close pipe */
    close(uu_pipe[0]);
    close(uu_pipe[1]);
}
