/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:38 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:19:45 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lin_clear(t_pipe *sp)
{
	t_line	*ltmp;

	while (sp->lin)
	{
		ltmp = sp->lin->nxt;
		if (sp->lin->shx)
			free(sp->lin->shx);
		if (sp->lin->bex)
			free(sp->lin->bex);
		if (sp->lin->del)
			free(sp->lin->del);
		free(sp->lin->path);
		free(sp->lin);
		sp->lin = ltmp;
	}
}

void	ft_lstclear(t_pipe **sp)
{
	t_pipe	*stmp;

	while (*sp)
	{
		stmp = (*sp)->nxt;
		lin_clear(*sp);
		free((*sp)->pl);
		free(*sp);
		*sp = stmp;
	}
}
