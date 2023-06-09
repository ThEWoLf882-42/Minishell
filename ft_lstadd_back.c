/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:58:58 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:19:38 by agimi            ###   ########.fr       */
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

void	ft_backfin(t_fin **fin, t_fin *new)
{
	if (!fin || !new)
		return ;
	if ((*fin))
		ft_lastfin((*fin))->nxt = new;
	else
		(*fin) = new;
}

void	ft_backfout(t_fout **fout, t_fout *new)
{
	if (!fout || !new)
		return ;
	if ((*fout))
		ft_lastfout((*fout))->nxt = new;
	else
		(*fout) = new;
}
