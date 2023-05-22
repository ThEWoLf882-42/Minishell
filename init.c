/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:03:41 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/22 11:34:52 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(void)
{
	// g_va.sp = NULL;
	// g_va.sp->lin->dlr = 0;
	g_va.sp->lin->exp = -1;
	g_va.sp->lin->noexp = -1;
	// g_va.sp->lin->err = 0;
	// g_va.sp->lin->shx = NULL;
}