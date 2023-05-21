/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_lin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:35:08 by agimi             #+#    #+#             */
/*   Updated: 2023/05/21 22:54:10 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sq_clean(t_line *lv, char *line, int *i, int *j)
{
	line = malloc(sizeof(char) * (ft_strlen(lv->shx) + 1));
	*j = -1;
	while (lv->shx[++(*i)])
	{
		if (lv->shx[*i] != '\'')
			line[++(*j)] = lv->shx[*i];
	}
	free(lv->shx);
	lv->shx = line;
}

void	clean_lin(void)
{
	t_pipe	*pv;
	t_line	*lv;
	int		i;
	int		j;
	char	*line;

	pv = g_va.sp;
	while (pv)
	{
		lv = pv->lin;
		while (lv)
		{
			i = -1;
			if (ft_strchr(lv->shx, '\''))
				sq_clean(lv, line, i, j);
			lv = lv->nxt;
		}
		pv = pv->nxt;
	}
}
