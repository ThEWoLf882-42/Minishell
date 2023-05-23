/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:39:26 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 22:41:56 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	forking(void)
{
	t_pipe	*sp;
	int		i;

	sp = g_va.sp;
	g_va.pids = malloc(sizeof(pid_t) * ft_pipesize(sp));
	i = -1;
	while (sp && ++i)
	{
		g_va.pids[i] = fork();
		open_fin(sp);
		open_fout(sp);
		sp = sp->nxt;
	}
}
