/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:20:23 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/20 19:54:42 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	fill_lin(void)
{
	char	*line;
	t_line	*lin;
	t_pipe	*sp;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	sp = g_va.sp;
	lin = g_va.sp->lin;
	line = malloc(sizeof(ft_strlen(sp->pl) + 1));
	if (!line)
		return ;
	while (sp->pl[++i])
	{
		j = -1;
		while (sp->pl[i] && sp->pl[i] != ' ')
		{
			line[++j] = sp->pl[i++];
		// printf("line = %c    %c =lin\n",line[j], sp->pl[i]);
			// if (sp->pl[i] != '\'' || sp->pl[i] != '"')
			// 	quote_func();
		}
		line[++j] = '\0';
		ft_backline(&g_va.sp->lin, new_lin(line));
	}
	while (g_va.sp->lin)
	{
		printf("lin = %s\n",g_va.sp->lin->shx);
		g_va.sp->lin = g_va.sp->lin->nxt;
	}
	free(line);
}