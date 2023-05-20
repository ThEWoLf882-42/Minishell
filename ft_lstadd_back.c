/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:58:58 by agimi             #+#    #+#             */
/*   Updated: 2023/05/20 19:12:27 by zouaraqa         ###   ########.fr       */
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
		ft_lastline((*lin))->nxt = new;
	else
		(*lin) = new;
}
