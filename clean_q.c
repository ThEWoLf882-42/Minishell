/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_q.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:41:38 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:17:14 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rep_q(t_line *lm, int *i)
{
	if (lm->shx[(*i)] == '\'')
	{
		lm->shx[(*i)] = 30;
		while (lm->shx[++(*i)] && lm->shx[(*i)] != '\'')
			;
		if (lm->shx[*i] == '\'')
			lm->shx[(*i)] = 30;
		return ;
	}
	if (lm->shx[(*i)] == '"')
	{
		lm->shx[(*i)] = 30;
		while (lm->shx[++(*i)] && lm->shx[(*i)] != '"')
			;
		if (lm->shx[*i] == '"')
			lm->shx[(*i)] = 30;
	}
}

void	start_rm_q(t_line *lm)
{
	int	i;

	i = 0;
	if (!lm || !lm->shx)
		return ;
	while (lm->shx[i])
	{
		if (lm->shx[i] == '"' || lm->shx[i] == '\'')
			rep_q(lm, &i);
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
			start_rm_q(lm);
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
}
