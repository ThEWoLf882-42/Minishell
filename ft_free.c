/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:51:08 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:19:23 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(void)
{
	if (g_va.pids)
	{
		free(g_va.pids);
		g_va.pids = NULL;
	}
	free_fin(g_va.sp);
	free_fout(g_va.sp);
	ft_lstclear(&g_va.sp);
}
