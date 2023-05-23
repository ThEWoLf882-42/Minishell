/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:37:08 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 18:16:38 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	test_31(t_line *lm)
{
	int	i;

	i = -1;
	if (ft_strchr(lm->shx, 31))
	{
		while (lm->shx[++i])
			if (lm->shx[i] == 31)
				lm->shx[i] = '$';
	}
}

static void	fill_type(t_line *lm, char *typ, char *ntyp)
{
	lm->typ = typ;
	if (lm->nxt)
		lm->nxt->typ = ntyp;
}

static void	set_red(t_line *lm)
{
	if (!ft_strcmp(lm->shx, ">>"))
		fill_type(lm, "out append", "out file");
	if (!ft_strcmp(lm->shx, ">"))
		fill_type(lm, "out", "out file");
	if (!ft_strcmp(lm->shx, "<"))
		fill_type(lm, "in", "in file");
	if (!ft_strcmp(lm->shx, "<<"))
	{
		lm->typ = "herdoc";
		if (lm->nxt)
		{
			lm->nxt->typ = "delimiter";
			test_31(lm->nxt);
		}
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
