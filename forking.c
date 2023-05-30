/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:39:26 by agimi             #+#    #+#             */
/*   Updated: 2023/05/30 18:36:33 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	forking(void)
{
	t_pipe	*sp;
	int		i;

	sp = g_va.sp;
	g_va.pids = malloc(sizeof(pid_t) * ft_pipesize(sp));
	if (!g_va.pids)
		return ;
	open_pipes();
	i = -1;
	open_here();
	while (sp)
	{
		i++;
		g_va.pids[i] = fork();
		if (g_va.pids[i] == -1)
			print_error("fork ", 1, 1);
		if (!g_va.pids[i])
		{
			childs(sp, i);
			break ;
		}
		close_opened(i);
		sp = sp->nxt;
	}
}
