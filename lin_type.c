/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:37:08 by agimi             #+#    #+#             */
/*   Updated: 2023/05/22 22:48:55 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	set_red(t_line	*lm)
{
	if (ft_strcmp(lm->shx, ">>"))
	{
		lm->typ = "out append";
		lm->nxt->typ = "out file";
	}
	if (ft_strcmp(lm->shx, ">"))
	{
		lm->typ = "out";
		lm->nxt->typ = "out file";
	}
	if (ft_strcmp(lm->shx, "<"))
	{
		lm->typ = "in";
		lm->nxt->typ = "in file";
	}
	if (ft_strcmp(lm->shx, "<<"))
	{
		lm->typ = "herdoc";
		lm->nxt->typ = "delimiter";
	}
}

void	check_file(void)
{
	t_pipe	*sm;
	t_line	*lm;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			set_red(lm);
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
}

void	lin_type(void)
{
	check_file();
}
