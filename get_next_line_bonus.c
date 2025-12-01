/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:50:22 by mjabri            #+#    #+#             */
/*   Updated: 2025/12/01 09:01:05 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl(char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	str = ft_calloc(i + 2);
	if (!str)
		return (free(src), NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		str[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		str[i++] = '\n';
	}
	str[i] = '\0';
	return (str);
}

char	*ft_rread(char *str, int fd)
{
	char	*buffer;
	int		i;

	if (!str)
		if (!(str = ft_calloc(1)))
			return (free(str), NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(str), NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(buffer), NULL);
		buffer[i] = '\0';
		str = ft_strnjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
		if (new_line_search(buffer) == 1)
			break ;
	}
	if (str[0] == '\0')
		return (free(str), free(buffer), NULL);
	return (free(buffer), str);
}

char	*get_next_line(int fd)
{
	static char	*folder[1024];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	folder[fd] = ft_rread(folder[fd], fd);
	if (!folder[fd])
		return (NULL);
	str = gnl(folder[fd]);
	if (!str)
		return (free(folder[fd]), NULL);
	folder[fd] = ft_line(folder[fd]);
	if (!folder[fd])
		return (free(str), NULL);
	return (str);
}
