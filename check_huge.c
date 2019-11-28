/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_huge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcody <gcody@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:30:57 by gcody             #+#    #+#             */
/*   Updated: 2019/11/26 21:15:34 by gcody            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_huge(int expected)
{
	char	*line;
	int		stat;

	stat = get_next_line(0, &line);
	if (stat < 1)
		return (1);
	if (ft_strlen(line) != (size_t)expected)
		return (2);
	free(line);
	return (0);
}
