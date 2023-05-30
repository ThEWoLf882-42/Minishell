/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:32:51 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/30 11:10:59 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipesize(t_pipe *sp)
{
	int	i;

	i = 0;
	while (sp)
	{
		i++;
		sp = sp->nxt;
	}
	return (i);
}

int	ft_linesize(t_line *lin)
{
	int	i;

	i = 0;
	while (lin)
	{
		i++;
		lin = lin->nxt;
	}
	return (i);
}
