/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:16:25 by agimi             #+#    #+#             */
/*   Updated: 2023/05/22 19:11:07 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fill_sp(char *line)
{
	char	*pl;
	int		i;
	int		j;

	i = -1;
	if (line[ft_strlen(line) - 1] == '|')
	{
		write(2, "Error pipe | at end of line\n", 28);
		return (1);
	}
	pl = malloc(sizeof(char) * ft_strlen(line) + 1);
	if (!pl)
		return (1);
	while (line[++i])
	{
		j = -1;
		while (line[i] && line[i] != '|')
			pl[++j] = line[i++];
		pl[++j] = '\0';
		ft_backpipe(&g_va.sp, new_sp(pl));
	}
	free(pl);
	return (0);
}
