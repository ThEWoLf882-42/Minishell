/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_q.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:45:18 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:17:53 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	between_dq(char *shx, int end)
{
	int	n;
	int	i;
	int	count;

	n = 0;
	count = 0;
	i = -1;
	while (shx[++i] && i < end)
	{
		if (shx[i] == '"')
			n++;
		if (shx[i] == 31 && n % 2 != 0)
		{
			count++;
			return (1);
		}
	}
	return (0);
}

void	cpy_bf(t_line *lm, char *line, int start, int *j)
{
	int	i;

	i = 0;
	while (lm->shx[i] && i < start)
		line[(*j)++] = lm->shx[i++];
}

void	cpy_mid(char *line, char *found, int *j)
{
	int	i;

	i = 0;
	if (!found)
		return ;
	while (found[i])
		line[(*j)++] = found[i++];
}

void	cpy_af(t_line *lm, char *line, int end, int *j)
{
	while (lm->shx[end])
		line[(*j)++] = lm->shx[end++];
}

void	exp_no_split(t_line *lm, char *found, int start, int end)
{
	char	*line;
	int		len;
	int		j;

	j = 0;
	len = (int)ft_strlen(lm->shx) - (end - start) + (int)ft_strlen(found) + 1;
	line = malloc(sizeof(char) * len);
	if (!line)
		return ;
	cpy_bf(lm, line, start, &j);
	cpy_mid(line, found, &j);
	cpy_af(lm, line, end, &j);
	line[j] = '\0';
	free(lm->shx);
	lm->shx = NULL;
	lm->shx = line;
	free(found);
}
