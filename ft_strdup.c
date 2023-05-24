/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:52:39 by agimi             #+#    #+#             */
/*   Updated: 2023/05/24 20:03:22 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*du;

	i = -1;
	du = malloc(sizeof(char) * ft_strlen(s1) + 2);
	if (!du)
		return (NULL);
	while (s1[++i])
		du[i] = s1[i];
	du[i] = '\0';
	return (du);
}
