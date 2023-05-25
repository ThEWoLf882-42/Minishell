/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:51:08 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/25 12:50:42 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(void)
{
	free(g_va.line);
	if(g_va.pids)
	{
		free(g_va.pids);
		g_va.pids = NULL;
	}
	free_fin(g_va.sp);
	free_fout(g_va.sp);
	ft_lstclear(&g_va.sp);
}
