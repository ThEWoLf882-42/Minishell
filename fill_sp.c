/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:16:25 by agimi             #+#    #+#             */
/*   Updated: 2023/05/31 22:08:08 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop_sp(char *line, char *pl)
{
	int		i;
	int		j;
	int		q;

	i = 0;
	q = 0;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
			q = !q;
		else if (line[i] == '|' && !q)
		{
			pl[j] = '\0';
			ft_backpipe(&g_va.sp, new_sp(pl));
			j = -1;
		}
		else
			pl[j] = line[i];
		i++;
		j++;
	}
	pl[j] = '\0';
	ft_backpipe(&g_va.sp, new_sp(pl));
}


int	fill_sp(char *line)
{
	char	*pl;

	if (!*line)
		return (1);
	if (line[ft_strlen(line) - 1] == '|')
		return (write(2, " syntax error near unexpected token `|'\n", 40), 1);
	pl = malloc(sizeof(char) * ft_strlen(line) + 1);
	if (!pl)
		return (1);
	loop_sp(line, pl);
	free(pl);
	return (0);
}
