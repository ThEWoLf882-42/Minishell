/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:16:25 by agimi             #+#    #+#             */
/*   Updated: 2023/05/20 17:49:06 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_sp(char *line)
{
	char	*pl;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	pl = malloc(sizeof(char) * ft_strlen(line) + 1);
	if (!pl)
		return ;
	while (line[i])
	{
		while (line[++i] != '|')
			pl[++j] = line[i];
		pl[++j] = '\0';
		ft_backpipe(g_va.sp, new_sp(pl));
		j = -1;
	}
	free(pl);
}
