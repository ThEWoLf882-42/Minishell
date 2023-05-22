/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:15:28 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/22 21:55:08 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe(void)
{
	t_pipe	*mv;

	mv = g_va.sp;
	while (mv)
	{
		if (!mv->lin)
		{
			write(2, "Error empty pipe line\n", 22);
			return (1);
		}
		mv = mv->nxt;
	}
	return (0);
}

static	void	qu_au(char c, int *sq, int *dq)
{
	if (c == '\'')
		(*sq)++;
	else if (c == '"')
		(*dq)++;
}

int	check_quote(void)
{
	t_pipe	*sm;
	t_line	*lm;
	int		dq;
	int		sq;
	int		i;

	sm = g_va.sp;
	while (sm)
	{
		sq = 0;
		dq = 0;
		lm = sm->lin;
		while (lm)
		{
			i = -1;
			while (lm->shx[++i])
				qu_au(lm->shx[i], &sq, &dq);
			lm = lm->nxt;
		}
		if (sq % 2 != 0 || dq % 2 != 0)
			return (write(2, "Syntax Error quote\n", 19), 1);
		sm = sm->nxt;
	}
	return (0);
}

int	check_red(void)
{
	t_pipe	*sm;
	t_line	*lm;
	int		i;
	int		q;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			q = 1;
			i = 0;
			if (ft_isred(lm->shx[0]))
			{
				while (lm->shx[++i] && lm->shx[i] == lm->shx[i - 1])
					q++;
				if (ft_isred(lm->shx[i]) || q > 2)
					return (write(2, "Error wrong redirections\n", 25), 1);
			}
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
	return (0);
}

int	check_error(void)
{
	if (check_pipe() || check_quote() || check_red())
		return (1);
	return (0);
}
