/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:14:15 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:22:02 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	test(t_pipe *sm, t_line *lm)
{
	if (lm->nxt)
	{
		if (!ft_strcmp(lm->typ, "out append"))
			ft_backfout(&sm->fout, new_fout(lm, lm->nxt->shx, 1));
		else if (!ft_strcmp(lm->typ, "out"))
			ft_backfout(&sm->fout, new_fout(lm, lm->nxt->shx, 0));
		else if (!ft_strcmp(lm->typ, "in"))
			ft_backfin(&sm->fin, new_fin(lm, lm->nxt->shx, 0, NULL));
		else if (!ft_strcmp(lm->typ, "herdoc"))
			ft_backfin(&sm->fin, new_fin(lm, NULL, 1, lm->nxt->shx));
	}
	else
		if (!ft_strcmp(lm->typ, "herdoc"))
			perror("syntax error near unexpected token `newline'");
}

void	set_file(void)
{
	t_pipe	*sm;
	t_line	*lm;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			test(sm, lm);
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
}
