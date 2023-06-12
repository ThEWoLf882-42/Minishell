/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:39:26 by agimi             #+#    #+#             */
/*   Updated: 2023/06/10 16:51:51 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_them(void)
{
	close(g_va.p1[0]);
	close(g_va.p1[1]);
	close(g_va.p2[0]);
	close(g_va.p2[1]);
}

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
	close_them();
}
