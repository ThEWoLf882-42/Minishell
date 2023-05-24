/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:38 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/24 17:01:27 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lin_clear(t_pipe *sp)
{
	t_line	*ltmp;

	while (sp->lin)
	{
		ltmp = sp->lin->nxt;
		free(sp->lin->shx);
		free(sp->lin->path);
		free(sp->lin);
		sp->lin->shx = NULL;
		sp->lin->path = NULL;
		sp->lin = NULL;
		sp->lin = ltmp;
	}
}

void	ft_lstclear(t_pipe **sp)
{
	t_pipe	*stmp;

	if (!sp)
		return ;
	while (*sp)
	{
		stmp = (*sp)->nxt;
		lin_clear(*sp);
		free((*sp)->pl);
		(*sp)->pl = NULL;
		free(*sp);
		(*sp) = NULL;
		*sp = stmp;
	}
}
