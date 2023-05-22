/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:15:28 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/22 19:17:28 by zouaraqa         ###   ########.fr       */
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
			{
				if (lm->shx[i] == '\'')
					sq++;
				else if (lm->shx[i] == '"')
					dq++;
			}
			lm = lm->nxt;
		}
		if (sq % 2 != 0 || dq % 2 != 0)
		{
			write(2, "Syntax Error quote\n", 19);
			return (1);
		}
		sm = sm->nxt;
	}
	return (0);
}

int	check_error(void)
{
	if (check_pipe() || check_quote())
		return (1);
	return (0);
}
