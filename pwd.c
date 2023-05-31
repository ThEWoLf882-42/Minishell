/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:54:41 by agimi             #+#    #+#             */
/*   Updated: 2023/05/31 11:48:54 by zouaraqa         ###   ########.fr       */
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
	ft_putstr_fd(pwd, 1);
	ft_putchar_fd('\n', 1);
	free(pwd);
	if (x)
		exit(0);
	close_fd();
}
