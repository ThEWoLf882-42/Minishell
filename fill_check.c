/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:58:15 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/11 13:04:53 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(char **env)
{
	sig_handel();
	g_va.envp = env;
	g_va.exit_s = 0;
	set_env(env);
	set_xport(g_va.env);
	g_va.stdi = dup(0);
	g_va.stdo = dup(1);
	g_va.x = 0;
	g_va.y = 0;
}

void	others(void)
{
	rdy_to_exp();
	lin_type();
	expand();
	clean_q();
	clean();
	set_cmd();
	set_arg();
	set_file();
	set_ex();
}

int	fill_check(void)
{
	trim_space(g_va.line);
	if (fill_sp(g_va.line))
	{
		ft_free();
		return (1);
	}
	fill_lin();
	if (check_error())
	{
		ft_free();
		g_va.exit_s = 258;
		return (1);
	}
	others();
	if (ft_pipesize(g_va.sp) == 1)
	{
		if (builtins(g_va.sp->lin, 0))
		{
			ft_free();
			return (1);
		}
	}
	return (0);
}
