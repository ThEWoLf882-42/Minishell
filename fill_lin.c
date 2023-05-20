/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:20:23 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/20 20:20:15 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	fill_lin(void)
{
	char	*line;
	size_t	i;
	size_t	j;
	int 	n;

	n = 1;
	while (g_va.sp)
	{
		i = -1;
		line = malloc(sizeof(char) * (ft_strlen(g_va.sp->pl) + 1));
		if (!line)
			return ;
		while (g_va.sp->pl[++i])
		{
			j = -1;
			while (g_va.sp->pl[i] && g_va.sp->pl[i] != ' ')
				line[++j] = g_va.sp->pl[i++];
			line[++j] = '\0';
			ft_backline(&g_va.sp->lin, new_lin(line));
		}
		while (g_va.sp->lin)
		{
			printf("lin[%d] = %s\n", n,g_va.sp->lin->shx);
			g_va.sp->lin = g_va.sp->lin->nxt;
		}
		free(line);
		g_va.sp = g_va.sp->nxt;
		n++;
	}
}