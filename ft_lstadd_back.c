/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:58:58 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 18:45:47 by zouaraqa         ###   ########.fr       */
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

void	ft_backenv(t_env **env, t_env *new)
{
	if (!env || !new)
		return ;
	if ((*env))
		ft_lastenv((*env))->nxt = new;
	else
		(*env) = new;
}
