/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:22:22 by agimi             #+#    #+#             */
/*   Updated: 2023/06/07 19:40:03 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	trim_space(char *line)
{
	size_t	i;

	i = ft_strlen(line);
	if (!i)
		return ;
	while (i > 0 && (line[--i] == ' ' || line[i] == '\t'))
		line[i] = '\0';
	line[i + 1] = '\0';
}
