/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcody <gcody@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:47:32 by gcody             #+#    #+#             */
/*   Updated: 2019/11/26 21:04:49 by gcody            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		has_huge(char **options, int size)
{
	int	i;

	i = 0;
	while (i < size)
		if (ft_strncmp(options[i++], HUGE_OPT, ft_strlen(HUGE_OPT)) == 0)
			return (1);
	return (0);
}
