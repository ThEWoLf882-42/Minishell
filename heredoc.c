/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:26:39 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:20:38 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_herdoc(char *li, int her)
{
	ft_putstr_fd(li, her);
	ft_putchar_fd('\n', her);
}

void	heredoc(t_fin *fin, int h[])
{
	char	*li;
	int		at;

	li = NULL;
	at = dup(0);
	dup2(g_va.stdi, 0);
	g_va.x = 1;
	while (1 && !g_va.y)
	{
		li = readline("> ");
		if (!ft_strcmp(li, fin->del) || !li)
			break ;
		if (ft_strchr(fin->bex, '\'') || ft_strchr(fin->bex, '"'))
			print_herdoc(li, h[1]);
		else
			here_exp(li, h[1]);
		free(li);
		li = NULL;
	}
	free(li);
	g_va.x = 0;
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
