/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:39:26 by agimi             #+#    #+#             */
/*   Updated: 2023/05/24 16:27:04 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	forking(void)
{
	t_pipe	*sp;
	// int		p1[2];
	// int		p2[2];
	int		i;

	sp = g_va.sp;
	g_va.pids = malloc(sizeof(pid_t) * ft_pipesize(sp));
	if (!g_va.pids)
		return ;
	i = -1;
	while (sp)
	{
		i++;
		g_va.pids[i] = fork();
		if (g_va.pids[i] == -1)
		{
			printf("error fork\n");
			return ;
		}
		if (!g_va.pids[i])
		{
			childs(sp);
			break ;
		}
		// close_open();
		sp = sp->nxt;
	}
}