/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:26:39 by agimi             #+#    #+#             */
/*   Updated: 2023/05/30 18:37:01 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(t_fin *fin, int h[])
{
	char	*line;
	int		at;

	at = dup(0);
	dup2(g_va.stdi, 0);
	while (1)
	{
		line = readline("> ");
		if (!ft_strcmp(line, fin->del))
			break ;
		else
		{
			ft_putstr_fd(line, h[1]);
			ft_putchar_fd('\n', h[1]);
		}
	}
	close(h[1]);
	dup2(at, 0);
}

void	open_here(void)
{
	t_pipe	*sp;
	t_fin	*fin;
	int		h[2];

	sp = g_va.sp;
	while (sp)
	{
		fin = sp->fin;
		while (fin)
		{
			if (fin->herdoc)
			{
				if (pipe(h) == -1)
					print_error("pipe", 1, 1);
				fin->fd = h[0];
				heredoc(fin, h);
			}
			fin = fin->nxt;
		}
		sp = sp->nxt;
	}
}
