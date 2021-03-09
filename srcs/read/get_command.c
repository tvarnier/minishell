/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_command.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 03:47:20 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 17:54:57 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	init_read(t_read *r)
{
	r->cursor = 0;
	r->cursor_max = 0;
	r->ansi = -1;
	r->last = 0;
}

void	ansi_char(t_read *r, char *line, char c)
{
	if (r->cursor > 0 && c == 68)
	{
		ft_putstr("\033[D");
		r->cursor--;
	}
	else if (r->cursor < r->cursor_max && c == 67)
	{
		ft_putstr("\033[C");
		r->cursor++;
	}
	else if (c == 51)
		r->ansi = 0;
	else if (r->cursor < r->cursor_max && r->last == 51 && c == 126)
		delete_char(r, line);
}

void	treat_char(t_read *r, char *line, char c)
{
	if (c == 27)
		r->ansi = 1;
	else if (r->ansi == 1 && c == 91)
		r->ansi = 0;
	else if (r->ansi == 0)
	{
		r->ansi = -1;
		ansi_char(r, line, c);
	}
	else if ((c >= 32 && c <= 126))
	{
		r->ansi = -1;
		insert_char(r, line, c);
	}
	else if (r->cursor > 0 && c == 127)
	{
		r->ansi = -1;
		r->cursor--;
		ft_putstr("\033[D");
		delete_char(r, line);
	}
	r->last = c;
}

char	*get_command(t_shell *s)
{
	char	*line;
	char	c;
	t_read	r;

	(void)s;
	if (!(line = ft_strnew(BUFFER)))
		return (NULL);
	init_read(&r);
	c = 0;
	while (c != '\n')
	{
		if (r.cursor_max >= BUFFER)
		{
			ft_strdel(&line);
			return (NULL);
		}
		if (read(0, &c, 1))
			treat_char(&r, line, c);
	}
	ft_putchar(c);
	line[r.cursor_max] = 0;
	return (line);
}
