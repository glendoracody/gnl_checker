/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcody <gcody@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:45:36 by gcody             #+#    #+#             */
/*   Updated: 2019/11/26 21:06:52 by gcody            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "get_next_line.h"
# define LOCAL_BUF_SIZE 2048
# define HUGE_OPT "-huge"

int	check_single(char *name);
int	check_multi(int count, char **names);
int	check_stdin(void);
int	check_huge(int expected);
int	get_options(int ac, char **av, char ***opts, char ***args);
int	has_huge(char **options, int size);

#endif
