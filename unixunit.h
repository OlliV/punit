#ifndef UNIXUNIT_H
#define UNIXUNIT_H

/* Stdin writer */
void uu_open_pipe();
void uu_open_stdin_writer();
void uu_write_stdin(char * str);
void uu_close_stdin_writer();
void uu_close_pipe();

#endif
