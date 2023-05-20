/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:16:25 by agimi             #+#    #+#             */
/*   Updated: 2023/05/20 20:24:56 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_sp(char *line)
{
	char	*pl;
	size_t	i;
	size_t	j;

	i = -1;
	pl = malloc(sizeof(char) * ft_strlen(line) + 1);
	if (!pl)
		return ;
	// trim space in the end
	while (line[++i])
	{
		j = -1;
		while (line[i] && line[i] != '|')
			pl[++j] = line[i++];
		pl[++j] = '\0';
		ft_backpipe(&g_va.sp, new_sp(pl));
	}
	free(pl);
}
