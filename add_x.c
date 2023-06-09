/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:48:32 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:15:18 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env(char *narg)
{
	t_env	*em;
	int		i;

	i = 0;
	em = g_va.env;
	if (!ft_strchr(narg, '='))
		return ;
	while (narg[i] && narg[i] != '=')
		i++;
	while (em)
	{
		if (!ft_strncmp(em->arg, narg, i))
		{
			change_envarg(em, narg);
			break ;
		}
		em = em->nxt;
	}
	if (!em)
		ft_backenv(&g_va.env, new_env(narg));
}

void	add_exp(char *narg)
{
	t_exp	*xm;
	int		len;
	char	*dec_x;

	len = 0;
	xm = g_va.xport;
	while (narg[len] && narg[len] != '=')
		len++;
	while (xm)
	{
		if (!ft_strncmp(xm->xarg, narg, len))
		{
			change_xarg(xm, narg);
			break ;
		}
		xm = xm->nxt;
	}
	if (!xm)
	{
		dec_x = copy_exp(narg);
		ft_backexp(&g_va.xport, new_exp(dec_x));
		free(dec_x);
	}
}
