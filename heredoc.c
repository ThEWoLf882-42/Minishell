/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:26:39 by agimi             #+#    #+#             */
/*   Updated: 2023/05/27 14:47:33 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(t_fin	*fin)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!ft_strcmp(line, fin->del))
			break ;
		else
		{
			printf("%s", line);
		}
	}
}
