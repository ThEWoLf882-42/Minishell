/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:25:26 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 21:14:06 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
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
		set_env(env);
		set_cmd();
		set_arg();
		set_file();
		while (g_va.sp)
		{
			printf("sp: [%s]\n", g_va.sp->pl);
			while (g_va.sp->lin)
			{
				printf("	lin: (%s)   -->typ: (%s)  ===> path = (%s)\n", g_va.sp->lin->shx, g_va.sp->lin->typ, g_va.sp->lin->path);
				g_va.sp->lin = g_va.sp->lin->nxt;
			}
			g_va.sp = g_va.sp->nxt;
		}
	}
}
