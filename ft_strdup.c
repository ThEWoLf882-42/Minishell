/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:52:39 by agimi             #+#    #+#             */
/*   Updated: 2023/05/20 17:16:23 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*du;

	i = -1;
	du = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!du)
		return (NULL);
	while (s1[++i])
		du[i] = s1[i];
	du[i] = '\0';
	return (du);
}
