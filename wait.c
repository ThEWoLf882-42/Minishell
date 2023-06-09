/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:52:15 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:22:18 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_pid(void)
{
	unsigned char	*stat;
	int				status;
	int				np;
	int				i;

	i = -1;
	np = ft_pipesize(g_va.sp);
	while (++i < np)
	{
		if (waitpid(g_va.pids[i], &status, 0) == -1)
			ft_putstr_fd("wait Error\n", 1);
		stat = (unsigned char *)&status;
		if (stat[0])
			g_va.exit_s = stat[0] + 128;
		else
			g_va.exit_s = stat[1];
	}
}
