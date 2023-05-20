/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:58:58 by agimi             #+#    #+#             */
/*   Updated: 2023/05/20 22:26:10 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_backpipe(t_pipe **sp, t_pipe *new)
{
	if (!sp || !new)
		return ;
	if ((*sp))
		ft_lastpipe((*sp))->nxt = new;
	else
		(*sp) = new;
}

void	ft_backline(t_line **lin, t_line *new)
{
	if (!lin || !new)
		return ;
	if ((*lin))
	{
		new->prv = ft_lastline((*lin));
		ft_lastline((*lin))->nxt = new;
	}
	else
		(*lin) = new;
}
