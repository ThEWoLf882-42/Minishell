/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:18:11 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/22 11:19:40 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_isred(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

int	ft_isquot(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

int	ft_isspec(char c)
{
	if(ft_isspace(c) || ft_isred(c) || c == '|')
		return (1);
	return (0);
}

int	ft_isdlr(char c)
{
	if (c == '$')
		return (1);
	return (0);
}

int	count_dlr(char *line)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (line[++i])
		if (line[i] == '$')
			count++;
	return (count);
}
