/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:25:26 by agimi             #+#    #+#             */
/*   Updated: 2023/05/26 19:26:11 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	// sig_handel();
	g_va.envp = env;
	g_va.exit_s = 0;
	set_env(env);
	set_xport(g_va.env);
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
		set_cmd();
		set_arg();
		set_file();
		if (ft_pipesize(g_va.sp) == 1)
		{
			if (builtins(g_va.sp->lin, 0))
			{
				ft_free();
				continue ;
			}
		}
		forking();
		wait_pid();
		// printf("exstatus [%d]\n", g_va.exit_s);
		ft_free();
		// while (g_va.sp)
		// {
		// 	printf("sp:[%s]\n", g_va.sp->pl);
		// 	while (g_va.sp->lin)
		// 	{
		// 		printf("	lin: (%s) ->typ: (%s) =>path = (%s)\n",
		// 			g_va.sp->lin->shx, g_va.sp->lin->typ, g_va.sp->lin->path);
		// 		g_va.sp->lin = g_va.sp->lin->nxt;
		// 	}
		// 	// printf(" ->fil= (%s) \n", g_va.sp->fin->file);
		// 	g_va.sp = g_va.sp->nxt;
		// }
	}
}
