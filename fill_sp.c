/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:16:25 by agimi             #+#    #+#             */
/*   Updated: 2023/06/04 16:21:43 by zouaraqa         ###   ########.fr       */
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

int	start_cpy(char *line, char *pl, int *i, int *j)
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
			return (1);
	}
	pl[++(*j)] = '\0';
	ft_backpipe(&g_va.sp, new_sp(pl));
	if (line[(*i)] == '\0')
		return (1);
	return (0);
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
	pl = malloc(sizeof(char) * ft_strlen(line) + 1);
	if (!pl)
		return (1);
	while (line[++i])
		if (start_cpy(line, pl, &i, &j))
			break ;
	free(pl);
	if (g_va.err)
	{
		ft_lstclear(&g_va.sp);
		return (write(2, "syntax error near unexpected token `|'\n", 40), 1);
	}
	return (0);
}
