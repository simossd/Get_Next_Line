/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:57:35 by mjabri            #+#    #+#             */
/*   Updated: 2025/11/25 13:59:57 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*str;
	ssize_t		i;
	static char	*to_next;

	if (!to_next)
		str = ft_strdup("");
	else
		str = ft_strdup(to_next);
	if (!str)
		return (NULL);
	to_next = malloc(BUFFER_SIZE + 1);
	if (!to_next)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[i] = '\0';
		i = 0;
		str = ft_strnjoin(str, buffer);
		if (!str)
			return (NULL);
		while (str[i])
			if (str[i++] == '\n')
				return (n_line_check(str, to_next, i));
	}
	free(str);
	free(buffer);
	return (str);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	// printf("%s", get_next_line(fd));

	

	return (0);
}
