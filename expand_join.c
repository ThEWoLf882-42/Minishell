/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:03:29 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/30 15:04:05 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_dlr_bex(t_line *lm)
{
	int	i;

	i = -1;
	lm->bex = ft_strdup(lm->shx);
	while (lm->bex[++i])
		if (lm->bex[i] == 31)
			lm->bex[i] = '$';
}

int	char_bf(int start)
{
	int	i;

	i = 0;
	if (i == start)
		return (0);
	else
		while (i < start)
			i++;
	return (i);
}

int	char_af(char *shx, int end)
{
	end++;
	if (shx[end] != '\0' && shx[end] != ' ' && shx[end] != '\t')
		return (1);
	return (0);
}

void	join_bf(t_line **newlm, char *shx, char *found, int start)
{
	char	**str;
	int		i;

	if (!found)
	{
		ft_backline(newlm, new_lin(ft_substr(shx, 0, start)));
		return ;
	}
	str = ft_split(found, ' ');
	ft_backline(newlm, new_lin(ft_strjoin(ft_substr(shx, 0, start), str[0])));
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	join_af(t_line **newlm, char *shx, char *found, int end)
{
	char	**str;
	int		i;

	str = ft_split(found, ' ');
	i = 0;
	while (str[i])
		i++;
	ft_backline(newlm, new_lin(ft_strjoin(str[i - 1], ft_substr(shx, end + 2, ft_strlen(shx) - end))));
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
