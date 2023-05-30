/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:52:15 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/30 22:31:03 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_pid(void)
{
	int	i;
	int	np;
	int	status;

	i = -1;
	np = ft_pipesize(g_va.sp);
	while (++i < np)
	{
		if (waitpid(g_va.pids[i], &status, 0) == -1)
			ft_putstr_fd("wait Error\n", 1);
		if (i + 1 == np)
			g_va.exit_s = (status >> 8) & 0x0000ffff;
	}
}
