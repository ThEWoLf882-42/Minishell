/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:25:26 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 18:19:07 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	while (1)
	{
		g_va.line = readline("minishell-69$ ");
		add_history(g_va.line);
		trim_space(g_va.line);
		if (fill_sp(g_va.line))
		{
			ft_free();
			continue ;
		}
		fill_lin();
		if (check_error())
		{
			ft_free();
			continue ;
		}
		clean_lin();
		lin_type();
		expand();
		clean();
		
		while (g_va.sp)
		{
			printf("sp: [%s]\n", g_va.sp->pl);
			while (g_va.sp->lin)
			{
				printf("	lin: (%s) -->typ: (%s)\n", g_va.sp->lin->shx, g_va.sp->lin->typ);
				g_va.sp->lin = g_va.sp->lin->nxt;
			}
			g_va.sp = g_va.sp->nxt;
		}
	}
}
