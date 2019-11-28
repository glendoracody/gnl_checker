/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcody <gcody@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:59:11 by gcody             #+#    #+#             */
/*   Updated: 2019/11/26 21:14:44 by gcody            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_stdin(void)
{
	char	*line;
	int		status;
	int		len;
	int		count;

	count = 1;
	while ((status = get_next_line(0, &line)))
	{
		len = ft_strlen(line);
		if (count != len)
			return (count);
		count++;
		free(line);
	}
	return (0);
}
