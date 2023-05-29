/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:07:06 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/29 16:47:25 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_pipes(void)
{
	if (pipe(g_va.p1) == -1)
		print_error("pipe error", 1, 1);
	if (pipe(g_va.p2) == -1)
		print_error("pipe error", 1, 1);
}

void	close_opened(int i)
{
	if (i % 2 == 0)
	{
		close(g_va.p2[0]);
		close(g_va.p2[1]);
		if (pipe(g_va.p2) == -1)
			print_error("pipe error", 1, 1);
	}
	else if (i % 2 != 0)
	{
		close(g_va.p1[0]);
		close(g_va.p1[1]);
		if (pipe(g_va.p1) == -1)
			print_error("pipe error", 1, 1);
	}
}

void	set_pipes(int i)
{
	if (i % 2 != 0)
	{
		close(g_va.p1[1]);
		close(g_va.p2[0]);
		dup2(g_va.p1[0], 0);
		dup2(g_va.p2[1], 1);
		close(g_va.p1[0]);
		close(g_va.p2[1]);
	}
	else if (i % 2 == 0)
	{
		close(g_va.p2[1]);
		close(g_va.p1[0]);
		dup2(g_va.p2[0], 0);
		dup2(g_va.p1[1], 1);
		close(g_va.p2[0]);
		close(g_va.p1[1]);
	}
}

void	last_pipe(int i)
{
	if (i % 2 != 0)
	{
		close(g_va.p2[0]);
		close(g_va.p2[1]);
		close(g_va.p1[1]);
		dup2(g_va.p1[0], 0);
		close(g_va.p1[0]);
	}
	else if (i % 2 == 0)
	{
		close(g_va.p1[0]);
		close(g_va.p1[1]);
		close(g_va.p2[1]);
		dup2(g_va.p2[0], 0);
		close(g_va.p2[0]);
	}
}

void	which_pipe(int i)
{
	int	np;

	np = ft_pipesize(g_va.sp);
	if (np > 1)
	{
		if (i == 0)
		{
			close(g_va.p1[0]);
			dup2(g_va.p1[1], 1);
			close(g_va.p1[1]);
		}
		else if (i != 0 && i != np - 1)
			set_pipes(i);
		else if (i == np - 1)
			last_pipe(i);
	}
}
