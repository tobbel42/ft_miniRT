#include "exit.h"

void	exit_wrong_infile(char *line)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("wrong input file\n", STDERR_FILENO);
	if (line)
	{
		ft_putstr_fd("error at: ", STDERR_FILENO);
		ft_putstr_fd(line, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}

void	exit_system_fail(void)
{
	exit_msg("sorry, something went wrong");
}

void	exit_msg(char *msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	exit_error(char *msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (msg)
	{
		ft_putstr_fd(msg, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	exit_end(char *msg)
{
	if (msg)
	{
		ft_putstr_fd(msg, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	exit(EXIT_SUCCESS);
}
