/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:26:39 by agimi             #+#    #+#             */
/*   Updated: 2023/05/30 16:02:29 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(t_fin *fin, int i)
{
	char	*line;
	int		at;

	(void)i;
	at = dup(0);
	dup2(g_va.stdi, 0);
	while (1)
	{
		line = readline("> ");
		if (!ft_strcmp(line, fin->del))
			break ;
		else
		{
			ft_putstr_fd(line, 0);
			ft_putchar_fd('\n', 0);
		}
	}
	dup2(at, 0);
}

void	open_here(t_pipe *sp, int i)
{
	t_fin	*fin;

	fin = sp->fin;
	while (fin)
	{
		if (fin->herdoc)
			heredoc(fin, i);
		fin = fin->nxt;
	}
}
