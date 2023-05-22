/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_lin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:08 by agimi             #+#    #+#             */
/*   Updated: 2023/05/22 12:57:18 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rdy_exp(t_line *lm, char *line, int *i, int *j)
{
	line = malloc(sizeof(char) * (ft_strlen(lm->shx) + 1));
	*j = -1;
	while (lm->shx[++(*i)])
	{
		if (lm->shx[*i] == '"')
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
	lm->shx = line;
}

void	sq_clean(t_line *lm, char *line, int *i, int *j)
{
	line = malloc(sizeof(char) * (ft_strlen(lm->shx) + 1));
	*j = -1;
	while (lm->shx[++(*i)])
	{
		if (lm->shx[*i] == '\'')
			while (lm->shx[++(*i)] && lm->shx[*i] != '\'')
				line[++(*j)] = lm->shx[*i];
		if (lm->shx[*i] != '\'')
		{
			if (ft_isdlr(lm->shx[*i]))
			{
				line[++(*j)] = 31;
				(*i)++;
			}
			line[++(*j)] = lm->shx[*i];
		}
	}
	line[++(*j)] = '\0';
	free(lm->shx);
	lm->shx = line;
}

void	clean_lin(void)
{
	t_pipe	*pm;
	t_line	*lm;
	int		i;
	int		j;
	char	*line;

	line = NULL;
	pm = g_va.sp;
	while (pm)
	{
		lm = pm->lin;
		while (lm)
		{
			i = -1;
			if (ft_strchr(lm->shx, '\'') && !ft_strchr(lm->shx, '"'))
				sq_clean(lm, line, &i, &j);
			else
				rdy_exp(lm, line, &i, &j);
			lm = lm->nxt;
		}
		pm = pm->nxt;
	}
}
