/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:20:23 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/20 21:41:04 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_lin(void)
{
	char	*line;
	t_pipe	*sp;
	size_t	i;
	size_t	j;

	sp = g_va.sp;
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
		free(line);
		g_va.sp = g_va.sp->nxt;
	}
	g_va.sp = sp;
}
