/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcody <gcody@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:46:37 by gcody             #+#    #+#             */
/*   Updated: 2019/11/26 18:23:25 by gcody            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_option(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '-')
		return (0);
	while (str[i])
		if (!ft_isalpha(str[i++]))
			return (0);
	return (1);
}

static int	count_options(int ac, char **av)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (i < ac)
		if (is_option(av[i++]))
			res++;
	return (res);
}

static void	make_options(int ac, char **av, char **opts, char **args)
{
	int	i;
	int	opco;
	int	arco;

	i = 1;
	opco = 0;
	arco = 0;
	while (i < ac)
	{
		if (is_option(av[i]))
			opts[opco++] = av[i++];
		else
			args[arco++] = av[i++];
	}
}

int			get_options(int ac, char **av, char ***opts, char ***args)
{
	int	op_cnt;

	op_cnt = count_options(ac, av);
	*opts = (char **)malloc(op_cnt * sizeof(char *));
	if (!*opts)
		return (-1);
	*args = (char **)malloc((ac - op_cnt - 1) * sizeof(char *));
	if (!*args)
	{
		free(opts);
		return (-1);
	}
	make_options(ac, av, *opts, *args);
	return (op_cnt);
}
