/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:38 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/22 18:45:38 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear(t_pipe **sp)
{
	t_pipe	*stmp;
	t_line	*ltmp;

	if (!sp)
		return ;
	while (*sp)
	{
		stmp = (*sp)->nxt;
		while ((*sp)->lin)
		{
			ltmp = (*sp)->lin->nxt;
			free((*sp)->lin->shx);
			free((*sp)->lin);
			(*sp)->lin = ltmp;
		}
		free((*sp)->pl);
		free(*sp);
		*sp = stmp;
	}
}
