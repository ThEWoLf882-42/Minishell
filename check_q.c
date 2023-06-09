/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_q.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:35:21 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:16:57 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_q(t_line *lm, int *i, int *dq, int *sq)
{
	if (lm->shx[(*i)] == '\'')
	{
		(*sq)++;
		while (lm->shx[++(*i)] && lm->shx[(*i)] != '\'')
			;
		if (lm->shx[*i] == '\'')
			(*sq)++;
		return (1);
	}
	if (lm->shx[(*i)] == '"')
	{
		(*dq)++;
		while (lm->shx[++(*i)] && lm->shx[(*i)] != '"')
			;
		if (lm->shx[*i] == '"')
			(*dq)++;
		return (1);
	}
	return (0);
}

int	check_start(t_line *lm)
{
	int	i;
	int	dq;
	int	sq;

	i = 0;
	if (!lm || !lm->shx)
		return (0);
	while (lm->shx[i])
	{
		dq = 0;
		sq = 0;
		if (lm->shx[i] == '\'' || lm->shx[i] == '"')
			is_q(lm, &i, &dq, &sq);
		if (dq % 2 != 0 || sq % 2 != 0)
			return (write(2, "Syntax Error quote\n", 19), 1);
		i++;
	}
	return (0);
}

int	check_q(void)
{
	t_pipe	*sm;
	t_line	*lm;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			if (check_start(lm))
				return (1);
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
	return (0);
}
