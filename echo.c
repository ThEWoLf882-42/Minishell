/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:38:53 by agimi             #+#    #+#             */
/*   Updated: 2023/06/12 20:13:24 by agimi            ###   ########.fr       */
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

void	skip_n(t_line **lm, int *n)
{
	if (!lm || !*lm || !(*lm)->shx)
		return ;
	while ((*lm) && check_arg((*lm)->shx))
	{
		if (check_arg((*lm)->shx))
			*n = 1;
		(*lm) = (*lm)->nxt;
	}
}

void	echo_loop(t_line *lm)
{
	while (lm)
	{
		if (!ft_strcmp(lm->typ, "arg"))
		{
			ft_putstr_fd(lm->shx, 1);
			if (lm->nxt && (!ft_strcmp(lm->nxt->typ, "arg")
					|| !ft_strcmp(lm->nxt->typ, "ex")))
				ft_putchar_fd(' ', 1);
		}
		lm = lm->nxt;
	}
}

void	echo_cmd(t_line *lm, int x)
{
	int	n;

	if (!x)
	{
		open_here();
		if (open_file(g_va.sp, x))
			return ;
	}
	n = 0;
	skip_n(&lm, &n);
	echo_loop(lm);
	if (!n)
		ft_putchar_fd('\n', 1);
	if (x)
		exit(0);
	close_fd();
	g_va.exit_s = 0;
}
