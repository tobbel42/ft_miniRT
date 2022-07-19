#ifndef EXIT_H
# define EXIT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"

void	exit_system_fail(void);
void	exit_msg(char *msg);
void	exit_error(char *msg);
void	exit_wrong_infile(char *line);
void	exit_end(char *msg);

#endif