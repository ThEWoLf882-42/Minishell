/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:26:39 by agimi             #+#    #+#             */
/*   Updated: 2023/06/06 12:24:41 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(t_fin *fin, int h[])
{
	char	*li;
	int		at;

	g_va.x = 0;
	at = dup(0);
	dup2(g_va.stdi, 0);
	sigaction(SIGINT, &g_va.child_sa, NULL);
	while (1)
	{
		if (g_va.x)
			break ;
		li = readline("> ");
		if (!ft_strcmp(li, fin->del) || !li)
			break ;
		if (ft_strchr(fin->bex, '\'') || ft_strchr(fin->bex, '"'))
		{
			ft_putstr_fd(li, h[1]);
			ft_putchar_fd('\n', h[1]);
		}
		else
			here_exp(li, h[1]);
		free(li);
	}
	free(li);
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
