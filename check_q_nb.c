/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_q_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:49:08 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:16:52 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	qu_nb(char *shx, int *i, int *sq, int *dq)
{
	char	q;

	q = shx[*i];
	if (q == '"')
	{
		(*dq)++;
		while (shx[*i] && shx[*i] != '"')
			(*i)++;
		if (shx[*i] == '"')
			(*dq)++;
	}
	else if (q == '\'')
	{
		(*sq)++;
		while (shx[*i] && shx[*i] != '\'')
			(*i)++;
		if (shx[*i] == '\'')
			(*sq)++;
	}
}

int	check_q_nb(void)
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
				qu_nb(lm->shx, &i, &sq, &dq);
			lm = lm->nxt;
		}
		if (sq % 2 != 0 || dq % 2 != 0)
			return (write(2, "Syntax Error quote\n", 19), 1);
		sm = sm->nxt;
	}
	return (0);
}
