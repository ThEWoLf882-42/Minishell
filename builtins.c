/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:24:34 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/26 12:40:00 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins(t_line *lm, int x)
{
	while (ft_strcmp(lm->typ, "cmd"))
		lm = lm->nxt;
	if (!ft_strcmp(lm->shx, "cd"))
		cd_cmd(lm, x);
	else if (!ft_strcmp(lm->shx, "pwd"))
		pwd_cmd(x);
	else if (!ft_strcmp(lm->shx, "echo") && x == 1)
		echo_cmd(lm->nxt, x);
	// else if (!ft_strcmp(lm->shx, "export"))
	// 	export_cmd();
	else if (!ft_strcmp(lm->shx, "unset"))
		unset_cmd(lm, x);
	else if (!ft_strcmp(lm->shx, "env"))
		env_cmd(x);
	else if (!ft_strcmp(lm->shx, "exit"))
		exit_cmd();
	else
		return (0);
	return (1);
}