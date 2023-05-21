/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:50:52 by agimi             #+#    #+#             */
/*   Updated: 2023/05/21 10:56:53 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	space_del(t_pipe *sp, t_line *lin)
{
	if (ft_strcmp(lin->shx, " ") && lin->nxt)
	{
		if (!lin->prv)
		{
			sp->lin = lin->nxt;
			sp->lin->prv = NULL;
		}
		else
		{
			lin->prv->nxt = lin->nxt;
			lin->nxt->prv = lin->prv;
		}
		free(lin->shx);
		free(lin);
	}
}

void	delete_space(void)
{
	t_line	*lin;
	t_pipe	*sp;

	sp = g_va.sp;
	while (sp)
	{
		lin = sp->lin;
		while (lin)
		{
			space_del(sp, lin);
			lin = lin->nxt;
		}
		sp = sp->nxt;
	}
}
