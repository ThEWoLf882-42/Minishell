/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:32:51 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:20:02 by agimi            ###   ########.fr       */
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
