/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:38:18 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/05 14:43:07 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_arg(void)
{
	t_pipe	*sm;
	t_line	*lm;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			if (!lm->typ)
				lm->typ = "arg";
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
}
