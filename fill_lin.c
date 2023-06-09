/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:20:23 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/08 10:22:48 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
i-- for somethisn fbgfh quotes piece of shitygimikfkfkf
*/
void	finish_it(t_pipe *sm, char *line, int *i, int *j)
{
	(*i)--;
	line[++(*j)] = '\0';
	ft_backline(&sm->lin, new_lin(line, NULL, 1));
}

/*
if j == -1 means that there is one redirection 
search for redirection to join them like this >>> in one
*/
void	check(t_pipe *sm, char *line, int *i, int *j)
{
	if (*j != -1)
		finish_it(sm, line, i, j);
	else if (*j == -1 && (!sm->pl[*i] || ft_isred(sm->pl[*i])))
	{
		while (sm->pl[*i] && ft_isred(sm->pl[*i]))
			line[++(*j)] = sm->pl[(*i)++];
		finish_it(sm, line, i, j);
	}
}

/*
loop until reaching a special character after the quote
and the quote must be pair to finish it
*/
void	quote_sep(t_pipe *sm, char *line, int *i, int *j)
{
	char	quote;
	int		n;

	quote = sm->pl[*i];
	n = 0;
	while (sm->pl[*i])
	{
		if (sm->pl[*i] == quote)
			n++;
		if (ft_isspec(sm->pl[*i + 1]))
		{
			line[++(*j)] = sm->pl[(*i)++];
			if (n % 2 == 0)
				break ;
		}
		line[++(*j)] = sm->pl[(*i)++];
	}
	finish_it(sm, line, i, j);
}

/*
copy until reaching a quote or space or redirection and stop to check
if its quote stop to go to the quote_sep
if its not quote check if redirection or normal str
*/
void	creat_line(t_pipe *sm, char *line, int *i, int *j)
{
	*j = -1;
	if (!ft_isquot(sm->pl[*i]))
	{
		while (sm->pl[*i] && !ft_isspace(sm->pl[*i])
			&& !ft_isred(sm->pl[*i]) && !ft_isquot(sm->pl[*i]))
			line[++(*j)] = sm->pl[(*i)++];
		if (!ft_isquot(sm->pl[*i]))
			check(sm, line, i, j);
	}
	if (ft_isquot(sm->pl[*i]))
		quote_sep(sm, line, i, j);
}

void	fill_lin(void)
{
	t_pipe	*sm;
	char	*line;
	int		i;
	int		j;

	sm = g_va.sp;
	while (sm)
	{
		i = -1;
		line = malloc(sizeof(char) * (ft_strlen(sm->pl) + 1));
		if (!line)
			return ;
		while (sm->pl[++i])
			creat_line(sm, line, &i, &j);
		free(line);
		sm = sm->nxt;
	}
}
