/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:24:34 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/25 19:09:13 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins(t_line *lm, int x)
{
	// if (!ft_strcmp(lm->shx, "echo"))
	// 	echo_cmd();
	if (!ft_strcmp(lm->shx, "cd"))
		cd_cmd(lm, x);
	if (!ft_strcmp(lm->shx, "pwd"))
		pwd_cmd(x);
	// if (!ft_strcmp(lm->shx, "export"))
	// 	export_cmd();
	// if (!ft_strcmp(lm->shx, "unset"))
	// 	unset_cmd();
	// if (!ft_strcmp(lm->shx, "env"))
	// 	env_cmd();
	// if (!ft_strcmp(lm->shx, "exit"))
	// 	exit_cmd();
}
