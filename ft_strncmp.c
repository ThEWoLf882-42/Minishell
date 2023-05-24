/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:41:24 by agimi             #+#    #+#             */
/*   Updated: 2023/05/24 14:50:24 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	a;

	a = -1;
	if (!s1 || !s2)
		return (1);
	while (s1[++a] || s2[a])
		if (s1[a] != s2[a])
			return (1);
	return (0);
}
