/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:47:21 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/10 17:13:09 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env(char **env)
{
	int	i;

	i = -1;
	if (!env || !*env)
	{
		ft_backenv(&g_va.env,new_env(ft_strdup("PATH=/usr/local/bin:\
			/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki")));
		return ;
	}
	while (env[++i])
		ft_backenv(&g_va.env, new_env(env[i]));
}
