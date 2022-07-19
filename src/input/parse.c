#include "parse.h"
#include "exit.h"

t_parse	*get_parse_data(void)
{
	static t_parse	data;

	return (&data);
}

int	check_filename(char *name)
{
	char	**strs;
	int		i;

	strs = ft_split(name, '.');
	if (!strs || !strs[0] || !strs[1])
		return (FALSE);
	i = 1;
	while (strs[i + 1])
		i++;
	if (ft_strncmp(strs[i], "rt", 5) == 0)
		return (TRUE);
	return (FALSE);
}

void	check_input(int argc, char **argv)
{
	t_parse	*parse_data;

	parse_data = get_parse_data();
	if (argc != 2)
		exit_msg("pass a file containing the scene");
	if (check_filename(argv[1]) == FALSE)
		exit_msg("not a valid filename");
	parse_data->in_fd = open(argv[1], O_RDONLY);
	if (parse_data->in_fd == -1)
		exit_error("opening infile failed");
}

void	input_parse(int argc, char **argv)
{
	check_input(argc, argv);
	read_infile();
}
