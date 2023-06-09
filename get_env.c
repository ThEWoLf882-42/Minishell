/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:59:40 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:20:29 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char *sen)
{
	t_env	*env;

	env = g_va.env;
	while (env)
	{
		if (!ft_strncmp(env->arg, sen, ft_strlen(sen)))
		{
			if (env->arg[ft_strlen(sen)] == '=')
				return (&env->arg[ft_strlen(sen) + 1]);
		}
		env = env->nxt;
	}
	return (NULL);
}
