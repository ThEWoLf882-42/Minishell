/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:51:13 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:20:14 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i] != c)
	{
		if (!s[i])
			return (NULL);
	}
	return ((char *)s + i);
}

int	ft_strchr1(const char *s, int c)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i] != c)
	{
		if (!s[i])
			return (0);
	}
	return (i);
}
