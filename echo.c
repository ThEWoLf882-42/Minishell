/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:38:53 by agimi             #+#    #+#             */
/*   Updated: 2023/05/25 22:04:03 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
	{
		while (arg[++i] && arg[i] == 'n')
			;
		if (!arg[i])
			return (1);
	}
	return (0);
}

void	echo_cmd(t_line *lm, int x)
{
	int	n;

	n = 0;
	while (lm && check_arg(lm->shx))
	{
		if (check_arg(lm->shx))
			n = 1;
		lm = lm->nxt;
	}
	while (lm)
	{
		if (!ft_strcmp(lm->typ, "arg"))
		{
			printf("%s", lm->shx);
		}
		lm = lm->nxt;
	}
	if (!n)
		printf("\n");
	if (x)
		exit(0);
}
