/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huge_sender.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcody <gcody@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:06:48 by gcody             #+#    #+#             */
/*   Updated: 2019/11/26 20:07:29 by gcody            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	gen_byte(int index)
{
	return ('a' + (index % ('z' - 'a' + 1)));
}

static void	send_bytes(int number)
{
	char	*str;
	int		idx;
	int		jdx;

	str = (char *)malloc(LOCAL_BUF_SIZE);
	if (!str)
		return ;
	idx = 0;
	while (idx < number)
	{
		jdx = 0;
		while (jdx < LOCAL_BUF_SIZE && idx < number)
			str[jdx++] = gen_byte(idx++);
		write(1, str, jdx);
	}
}

int			main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(av[0]);
		ft_putendl(" number_of_bytes");
		return (-1);
	}
	else
		send_bytes(ft_atoi(av[1]));
	return (0);
}
