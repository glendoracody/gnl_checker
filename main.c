/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcody <gcody@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:46:07 by gcody             #+#    #+#             */
/*   Updated: 2019/11/28 15:57:11 by gcody            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	test_single(char *name)
{
	int		fd;
	char	*line;
	int		stat;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Can't open ");
		ft_putendl(name);
		return ;
	}
	while (1)
	{
		stat = get_next_line(fd, &line);
		ft_putnbr(fd);
		ft_putchar(' ');
		ft_putnbr(stat);
		if (stat < 1)
			break ;
		ft_putendl(line);
		free(line);
	}
	close(fd);
}

static void	print_test(int stat)
{
	if (stat == 0)
		ft_putendl("test OK");
	else
		ft_putendl("test FAIL");
}

static void	test_gnl(int ac, char **av)
{
	char	**opts;
	char	**args;
	int		oco;
	int		stat;

	oco = get_options(ac, av, &opts, &args);
	if (oco == 0 && ac == 2)
		test_single(av[1]);
	else if (oco > 0)
	{
		if (has_huge(opts, oco))
			stat = check_huge(ft_atoi(args[0]));
		else
			stat = check_stdin();
		print_test(stat);
	}
}

int			main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(av[0]);
		ft_putendl(" file_name_1 [additional file names]");
		return (-1);
	}
	else
		test_gnl(ac, av);
	return (0);
}
