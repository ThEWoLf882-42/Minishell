/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:20:23 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/21 12:43:27 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	skip_space(t_pipe *mv, char *line, int *i, int *j)
{
	if (*j != -1 /*&& (!mv->pl[*i] || ft_isspace(mv->pl[*i]))*/)
	{
		(*i)--;
		line[++(*j)] = '\0';
		ft_backline(&mv->lin, new_lin(line));
	}
	else if (*j == -1 && (!mv->pl[*i] || ft_isredir(mv->pl[*i])))
	{
		while (mv->pl[*i] && ft_isredir(mv->pl[*i]))
			line[++(*j)] = mv->pl[(*i)++];
		(*i)--;
		line[++(*j)] = '\0';
		ft_backline(&mv->lin, new_lin(line));
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
		{
			j = -1;
			while (mv->pl[i] && !ft_isspace(mv->pl[i]) && !ft_isredir(mv->pl[i]))
				line[++j] = mv->pl[i++];
			skip_space(mv, line, &i, &j);
		}
		free(line);
		mv = mv->nxt;
	}
}
