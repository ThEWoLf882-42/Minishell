/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:50:52 by agimi             #+#    #+#             */
/*   Updated: 2023/05/20 22:48:15 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			if (ft_strcmp(lin->shx, " ") && lin->nxt)
			{
				printf("ok\n");
				lin->prv->nxt = lin->nxt;
				lin->nxt->prv = lin->prv;
				free(lin->shx);
				free(lin);
			}
			lin = lin->nxt;
		}
		sp = sp->nxt;
	}
}
