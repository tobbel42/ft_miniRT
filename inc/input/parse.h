#ifndef PARSE_H
# define PARSE_H

# include "../mini_rt.h"
# include "create_nodes.h"

typedef struct s_parse
{
	int	in_fd;
}	t_parse;

t_parse	*get_parse_data(void);

void	check_input(int argc, char **argv);
void	read_infile(void);

#endif