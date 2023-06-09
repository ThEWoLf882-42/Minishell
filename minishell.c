/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:25:26 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:21:09 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	init(env);
	while (1)
	{
		g_va.line = readline("minishell-69$ ");
		add_history(g_va.line);
		if (!g_va.line)
			exit_cmd(NULL, 0);
		if (!*g_va.line)
			free(g_va.line);
		if (fill_check())
			continue ;
		forking();
		wait_pid();
		ft_free();
		g_va.y = 0;
	}
}
