/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:20:23 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/21 19:17:19 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	finish_it(t_pipe *mv, char *line, int *i, int *j)
{
	(*i)--;
	line[++(*j)] = '\0';
	ft_backline(&mv->lin, new_lin(line));
}

void	check(t_pipe *mv, char *line, int *i, int *j)
{
	if (*j != -1)
		finish_it(mv, line, i, j);
	else if (*j == -1 && (!mv->pl[*i] || ft_isred(mv->pl[*i])))
	{
		while (mv->pl[*i] && ft_isred(mv->pl[*i]))
			line[++(*j)] = mv->pl[(*i)++];
		finish_it(mv, line, i, j);
	}
}

void	quote_sep(t_pipe *mv, char *line, int *i, int *j)
{
	char	quote;

	quote = mv->pl[*i];
	while (mv->pl[*i])
	{
		if (mv->pl[*i] == quote && ft_isspec(mv->pl[*i + 1]))
		{
			line[++(*j)] = mv->pl[(*i)++];
			break ;
		}
		line[++(*j)] = mv->pl[(*i)++];
	}
	finish_it(mv, line, i, j);
}

void	creat_line(t_pipe *mv, char *line, int *i, int *j)
{
	*j = -1;
	if (ft_isquot(mv->pl[*i]))
		quote_sep(mv, line, i, j);
	else
	{
		while (mv->pl[*i] && !ft_isspace(mv->pl[*i]) && !ft_isred(mv->pl[*i]))
			line[++(*j)] = mv->pl[(*i)++];
		check(mv, line, i, j);
	}
}

void	fill_lin(void)
{
	t_pipe	*mv;
	char	*line;
	int		i;
	int		j;

	mv = g_va.sp;
	while (mv)
	{
		i = -1;
		line = malloc(sizeof(char) * (ft_strlen(mv->pl) + 1));
		if (!line)
			return ;
		while (mv->pl[++i])
			creat_line(mv, line, &i, &j);
		free(line);
		mv = mv->nxt;
	}
}
