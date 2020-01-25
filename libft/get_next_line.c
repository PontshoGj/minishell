/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmogwere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:42:58 by pmogwere          #+#    #+#             */
/*   Updated: 2019/07/11 14:44:22 by pmogwere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			nline(char **s, char **line, int fd)
{
	int				i;
	char			*temp;

	i = 0;
	if (s[fd][0] == 0)
		return (-1);
	while (s[fd][i] != '\n' && s[fd][i] != 0)
		i++;
	*line = ft_strsub(s[fd], 0, i);
	temp = s[fd];
	if (s[fd][i] == '\n')
	{
		s[fd] = ft_strdup(temp + i + 1);
		free(temp);
		return (1);
	}
	s[fd] = ft_strdup(temp + i);
	free(temp);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*s[1024];
	char			*temp;

	if (!(line) || read(fd, *line, 0) < 0 || \
				fd < 0 || BUFF_SIZE <= 0 || !(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while (!(ft_strchr(s[fd], '\n')) && \
				((ret = read(fd, *line, BUFF_SIZE)) > 0))
	{
		if (s[fd] == 0)
			s[fd] = ft_strnew(BUFF_SIZE + 1);
		temp = ft_strjoin(s[fd], *line);
		ft_strdel(&s[fd]);
		s[fd] = temp;
		ft_strclr(*line);
	}
	free(*line);
	if (nline(s, line, fd) > 0)
		return (1);
	if (ret == 0)
		return (0);
	return (-1);
}
