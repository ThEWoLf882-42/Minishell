/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_q.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:35:21 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/02 16:47:04 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_q(t_line *lm, int *i)
{
	if (lm->shx[(*i)] == '\'')
	{
		lm->shx[(*i)] = 30;
		while (lm->shx[++(*i)] && lm->shx[(*i)] != '\'')
			;
		lm->shx[(*i)] = 30;
		return (1);
	}
	if (lm->shx[(*i)] == '"')
	{
		lm->shx[(*i)] = 30;
		while (lm->shx[++(*i)] && lm->shx[(*i)] != '"')
			;
		lm->shx[(*i)] = 30;
		return (1);
	}
	return (0);
}

void	q_rm(t_line *lm)
{
	int	i;

	i = 0;
	if (!lm || !lm->shx)
		return ;
	while (lm->shx[i])
	{
		if (lm->shx[i] == '\'' || lm->shx[i] == '"')
			is_q(lm, &i);
		i++;
	}
}

void	clean_q(void)
{
	t_pipe	*sm;
	t_line	*lm;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			q_rm(lm);
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
}
