/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:26:39 by agimi             #+#    #+#             */
/*   Updated: 2023/05/30 10:07:24 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(t_fin *fin, int i)
{
	(void)i;
	char	*line;
	int at;
	at = dup(0);
	dup2(g_va.stdi, 0);
	while (1)
	{
		line = readline("> ");
		//line[ft_strlen(line) - 1] = '\0';
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