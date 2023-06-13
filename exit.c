/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:24:34 by agimi             #+#    #+#             */
/*   Updated: 2023/06/13 09:46:51 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!str[i])
		return (1);
	return (0);
}

void	exit_pr(t_line *lm, int *st)
{
	ft_putstr_fd("minishell-69: exit: ", 2);
	ft_putstr_fd(lm->nxt->shx, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	*st = 255;
}

int	exit_arg(t_line *lm, int *st)
{
	if (lm)
	{	
		if (lm->nxt)
		{
			if (check_num(lm->nxt->shx))
			{
				if (!lm->nxt->nxt)
					*st = ft_atoi(lm->nxt->shx);
				else
				{
					printf("exit\n");
					ft_putstr_fd("minishell-69: exit: too many arguments\n", 2);
					g_va.exit_s = 1;
					ft_free();
					return (1);
				}
			}
			else
				exit_pr(lm, st);
		}
	}
	return (0);
}

void	exit_cmd(t_line *lm, int x)
{
	int	st;

	st = g_va.exit_s;
	if (exit_arg(lm, &st))
		return ;
	if (!x)
	{
		printf("exit\n");
		free_env(&g_va.env);
		free_exp(&g_va.xport);
	}
	ft_free();
	exit(st);
}
