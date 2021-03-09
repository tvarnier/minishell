/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 13:06:01 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 01:08:37 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	enable_raw_mode(void)
{
	struct termios raw;

	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int		main(void)
{
	t_shell		s;
	char		*line;

	enable_raw_mode();
	init_shell(&s);
	while (42)
	{
		print_prompt(&s);
		s.res = 0;
		line = NULL;
		if ((line = get_command(&s)))
			launch_command(&s, line);
		else
			ft_putendl_fd("\ntoo many characters in the command", 2);
		if (s.exit)
			break ;
	}
	free_shell(&s);
	return (s.res);
}
