/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 11:54:36 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/07 19:11:50 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>

# define BUFFER 1000

typedef struct	s_shell
{
	char		**env;
	int			exit;
	int			res;
}				t_shell;

typedef struct	s_read
{
	int			cursor;
	int			cursor_max;
	int			ansi;
	char		last;
}				t_read;

char			*get_command(t_shell *s);
void			insert_char(t_read *r, char *line, char c);
void			delete_char(t_read *r, char *line);

char			**split_args(t_shell *s, char *line);
void			alloc_args(t_shell *s, char **args, char *line);
char			check_quote(char *line, int i, char quote);
void			free_args(char ***args);
int				args_len(char **args);

void			launch_command(t_shell *s, char *line);
int				command_builtins(t_shell *s, char **args);
int				b_cd(t_shell *s, char **av, int ac);
int				b_echo(t_shell *s, char **av, int ac);
int				b_env(t_shell *s, char **av, int ac);
int				b_exit(t_shell *s, char **av, int ac);
int				b_env(t_shell *s, char **av, int ac);
int				b_setenv(t_shell *s, char **av, int ac);
int				b_unsetenv(t_shell *s, char **av, int ac);
int				command_system(t_shell *s, char **args);

void			print_prompt(t_shell *s);
int				print_quote(char c);

void			error_cmd_not_found(char *cmd);

void			init_shell(t_shell *s);
void			free_shell(t_shell *s);

void			print_env(char **env);
void			free_env(char **env);
char			*get_env(char **env, char *search);
int				get_env_index(char **env, char *search);
char			**get_paths(char **env);
int				set_env(char ***env, char *var, char *value);
int				unset_env(char ***env, char *var);
int				env_len(char **env);

int				ft_ispath(int c);

#endif
