/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:06:33 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/24 20:07:27 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_env **env)
{
    t_env	*tenv;

	while (*env)
	{
		tenv = (*env)->nxt;
		free((*env)->arg);
		free(*env);
		*env = tenv;
	}
}
