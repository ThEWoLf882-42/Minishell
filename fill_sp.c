/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:46:46 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:19:07 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_pipe(char *line, char *pl, int *i, int *j)
{
	char	q;

	q = line[*i];
	pl[++(*j)] = q;
	while (line[++(*i)] && line[*i] != q)
		pl[++(*j)] = line[(*i)];
	pl[++(*j)] = line[(*i)++];
}

void	start_cpy(char *line, char *pl, int *i, int *j)
{
	(*j) = -1;
	while (line[(*i)])
	{
		if (line[(*i)] == '"' || line[(*i)] == '\'')
			skip_pipe(line, pl, i, j);
		else if (line[(*i)] && line[(*i)] != '|')
			pl[++(*j)] = line[(*i)++];
		if (line[(*i)] == '|' && !line[(*i) + 1])
			g_va.err = 1;
		if (line[(*i)] == '|')
			break ;
	}
	pl[++(*j)] = '\0';
	ft_backpipe(&g_va.sp, new_sp(pl));
}

int	fill_sp(char *line)
{
	char	*pl;
	int		i;
	int		j;

	i = -1;
	g_va.err = 0;
	if (!*line)
		return (1);
	pl = malloc(sizeof(char) * ft_strlen(line) + 2);
	if (!pl)
		return (1);
	while (line[++i])
	{
		start_cpy(line, pl, &i, &j);
		if (!line[i])
			break ;
	}
	free(pl);
	free(line);
	if (g_va.err)
	{
		g_va.exit_s = 258;
		return (ft_putstr_fd("syntax error near unexpected token `|'\n", 2), 1);
	}
	return (0);
}
