/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdy_to_exp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:08 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:21:34 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	q_check(t_line *lm, char *line, int *i, int *j)
{
	if (lm->shx[*i] == '\'')
	{
		line[++(*j)] = lm->shx[(*i)];
		while (lm->shx[++(*i)] && lm->shx[*i] != '\'')
			line[++(*j)] = lm->shx[*i];
		line[++(*j)] = lm->shx[*i];
		return (1);
	}
	if (lm->shx[*i] == '"')
	{
		line[++(*j)] = lm->shx[*i];
		while (lm->shx[++(*i)] && lm->shx[*i] != '"')
		{
			if (lm->shx[*i] == '$')
				line[++(*j)] = 31;
			else
				line[++(*j)] = lm->shx[*i];
		}
		line[++(*j)] = lm->shx[*i];
		return (1);
	}
	return (0);
}

void	rdy_exp(t_line *lm, char *line, int *i, int *j)
{
	line = malloc(sizeof(char) * (ft_strlen(lm->shx) + 1));
	*j = -1;
	while (lm->shx[++(*i)])
	{
		if (q_check(lm, line, i, j))
			continue ;
		if (lm->shx[*i] == '$')
		{
			line[++(*j)] = 31;
			continue ;
		}
		line[++(*j)] = lm->shx[*i];
	}
	line[++(*j)] = '\0';
	free(lm->shx);
	lm->shx = NULL;
	lm->shx = line;
}

void	rdy_to_exp(void)
{
	t_pipe	*sm;
	t_line	*lm;
	int		i;
	int		j;
	char	*line;

	line = NULL;
	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			i = -1;
			rdy_exp(lm, line, &i, &j);
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
}
