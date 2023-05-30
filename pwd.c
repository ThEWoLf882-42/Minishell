/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:54:41 by agimi             #+#    #+#             */
/*   Updated: 2023/05/30 18:39:28 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_cmd(int x)
{
	char	*pwd;

	if (!x)
	{
		open_here();
		if (open_file(g_va.sp, x))
			return ;
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
		print_error(pwd, 1, x);
	printf("%s\n", pwd);
	free(pwd);
	if (x)
		exit(0);
	close_fd();
}
