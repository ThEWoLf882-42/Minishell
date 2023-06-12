/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:07:45 by agimi             #+#    #+#             */
/*   Updated: 2023/06/12 16:31:25 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <dirent.h>

typedef struct file_in
{
	int				fd;
	int				herdoc;
	int				flag;
	char			*file;
	char			*del;
	char			*bex;
	struct line		*lm;
	struct file_in	*nxt;
}	t_fin;

typedef struct file_out
{
	int				fd;
	int				flag;
	char			*file;
	struct line		*lm;
	mode_t			perm;
	struct file_out	*nxt;
}	t_fout;

typedef struct pipe
{
	char		*pl;
	struct line	*lin;
	struct pipe	*nxt;
	t_fin		*fin;
	t_fout		*fout;
}	t_pipe;

typedef struct line
{
	char		*shx;
	char		*bex;
	char		*del;
	int			space;
	char		*typ;
	char		*path;
	struct line	*nxt;
	struct line	*prv;
}	t_line;

typedef struct envir
{
	char			*arg;
	struct envir	*nxt;
}	t_env;

typedef struct export
{
	char			*xarg;
	struct export	*nxt;
}	t_exp;

typedef struct exp_utl
{
	t_line	*newlm;
	char	*found;
	char	*typ;
	int		bf;
	int		af;
}	t_exp_utl;

typedef struct vars
{
	char				**envp;
	char				*line;
	int					err;
	int					x;
	int					y;
	int					exit_s;
	int					p1[2];
	int					p2[2];
	t_pipe				*sp;
	t_exp				*xport;
	t_env				*env;
	pid_t				*pids;
	struct sigaction	sa;
	int					stdi;
	int					stdo;
}	t_vars;

t_vars	g_va;

/***********************LIBFT***********************/
void	ft_backpipe(t_pipe **sp, t_pipe *new);
void	ft_backline(t_line **lin, t_line *new);
void	ft_backfin(t_fin **fin, t_fin *new);
void	ft_backfout(t_fout **fout, t_fout *new);
void	ft_lstclear(t_pipe **sp);
t_pipe	*ft_lastpipe(t_pipe *sp);
t_line	*ft_lastline(t_line *lin);
t_fin	*ft_lastfin(t_fin *fin);
t_fout	*ft_lastfout(t_fout *fout);
t_pipe	*new_sp(char *str);
t_fin	*new_fin(t_line *lm, char *file, int her, char *del);
t_fout	*new_fout(t_line *lm, char *file, int app);
t_line	*new_lin(char *str, char *ty, int i);
t_env	*new_env(char *str);
t_env	*ft_lastenv(t_env *env);
void	ft_backenv(t_env **env, t_env *new);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isspace(char c);
int		ft_isred(char c);
int		ft_isquot(char c);
int		ft_iss(int c);
int		ft_isspec(char c);
int		ft_isdlr(char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_pipesize(t_pipe *sp);
int		ft_linesize(t_line *lin);
void	ft_free(void);
char	*ft_strchr(const char *s, int c);
int		ft_strchr1(const char *s, int c);
char	*ft_substr(char *s, int start, int len);
void	ft_backexp(t_exp **exp, t_exp *new);
t_exp	*ft_lastexp(t_exp *exp);
t_exp	*new_exp(char *str);
char	*ft_itoa(int n);
char	**ft_split(char *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin2fr(char *s1, char *s2);
int		ft_atoi(const char *str);
/***********************LIBFT***********************/

int		fill_sp(char *line);
void	fill_lin(void);
void	trim_space(char *line);
void	rdy_to_exp(void);
int		check_error(void);
int		check_pipe(void);
int		check_q_nb(void);
int		check_red(void);
void	lin_type(void);
void	expand(void);
int		charloc(char *str, int n);
void	clean(void);
void	set_cmd(void);
void	set_env(char **env);
void	set_arg(void);
void	forking(void);
void	set_file(void);
int		open_fin(t_pipe *sp, int x);
int		open_fout(t_pipe *sp, int x);
int		open_file(t_pipe *sp, int x);
void	print_error(char *str, int exn, int x);
void	childs(t_pipe *sp, int i);
void	free_env(t_env **env);
void	free_fin(t_pipe *sp);
void	free_fout(t_pipe *sp);
void	ha_sig(int sig);
void	sig_handel(void);
void	set_pipes(int i);
void	last_pipe(int i);
void	which_pipe(int i);
void	open_pipes(void);
void	close_opened(int i);
void	wait_pid(void);
int		builtins(t_line *lm, int x);
void	pwd_cmd(int x);
void	cd_cmd(t_line *lm, int x);
void	exit_cmd(t_line *lm, int x);
void	env_cmd(t_line *lm, int x);
void	echo_cmd(t_line *lm, int x);
void	unset_cmd(t_line *lm, int x);
void	close_fd(void);
void	export_cmd(t_line *lm, int x);
void	set_xport(t_env *em);
void	heredoc(t_fin *fin, int h[]);
void	open_here(void);
void	free_exp(t_exp **exp);
void	redirect_error(char *str, int x);
void	put_dlr_bex(t_line *lm);
int		char_bf(int start);
int		char_af(char *shx, int end);
void	join_bf(t_exp_utl *exp, char *shx, char *found, int start);
void	join_af(t_exp_utl *exp, char *shx, char *found, int end);
char	*sp_dlr(char *get, int *bf, int *af);
void	creat_expnod(t_exp_utl *exp, char *found, int bf);
void	exit_print(char *str);
char	*which_env(char *get, int *bf, int *af);
char	*copy_exp(char *arg);
void	add_env(char *narg);
void	change_envarg(t_env *em, char *narg);
void	add_exp(char *narg);
void	here_exp(char *li, int fd);
void	change_xarg(t_exp *xm, char *narg);
char	*get_env(char *env);
int		check_q(void);
void	clean_q(void);
void	exp_no_split(t_line *lm, char *found, int start, int end);
int		between_dq(char *shx, int end);
void	set_ex(void);
int		ambiguis(char *found);
void	check_bef(t_exp_utl *exp, t_line *lm, int start);
void	check_af(t_exp_utl *exp, t_line *lm, size_t s, int end);
void	init(char **env);
int		fill_check(void);
int		valid_exp(char *shx);
int		nargs(t_line *lm);
void	is_dir(char *cmd);
char	**join_arg(t_line *lm);
void	if_nopath(t_line *lm);
void	change_pwd_exp(t_exp *xp, char *cd);
void	change_pwd_env(t_env *em, char *cd);

#endif