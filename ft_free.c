/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:51:08 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/24 22:01:57 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(void)
{
	free(g_va.line);
	free(g_va.pids);
	free_fin(g_va.sp);
	free_fout(g_va.sp);
	ft_lstclear(&g_va.sp);
}
