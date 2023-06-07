/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:20:23 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/06 20:37:12 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
i-- for somethisn fbgfh quotes piece of shitygimikfkfkf
*/
void	finish_it(t_pipe *mv, char *line, int *i, int *j)
{
	(*i)--;
	line[++(*j)] = '\0';
	ft_backline(&mv->lin, new_lin(line, NULL, 1));
}

/*
if j == -1 means that there is one redirection 
search for redirection to join them like this >>> in one
*/
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

/*
loop until reaching a special character after the quote
and the quote must be pair to finish it
*/
void	quote_sep(t_pipe *mv, char *line, int *i, int *j)
{
	char	quote;
	int		n;

	quote = mv->pl[*i];
	n = 0;
	while (mv->pl[*i])
	{
		if (mv->pl[*i] == quote)
			n++;
		if (ft_isspec(mv->pl[*i + 1]))
		{
			line[++(*j)] = mv->pl[(*i)++];
			if (n % 2 == 0)
				break ;
		}
		line[++(*j)] = mv->pl[(*i)++];
	}
	finish_it(mv, line, i, j);
}

/*
copy until reaching a quote or space or redirection and stop to check
if its quote stop to go to the quote_sep
if its not quote check if redirection or normal str
*/
void	creat_line(t_pipe *mv, char *line, int *i, int *j)
{
	*j = -1;
	if (!ft_isquot(mv->pl[*i]))
	{
		while (mv->pl[*i] && !ft_isspace(mv->pl[*i])
			&& !ft_isred(mv->pl[*i]) && !ft_isquot(mv->pl[*i]))
			line[++(*j)] = mv->pl[(*i)++];
		if (!ft_isquot(mv->pl[*i]))
			check(mv, line, i, j);
	}
	if (ft_isquot(mv->pl[*i]))
		quote_sep(mv, line, i, j);
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
