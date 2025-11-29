/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 05:50:04 by mjabri            #+#    #+#             */
/*   Updated: 2025/11/29 10:04:09 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL
# define GNL

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

void *ft_calloc(size_t nmemb);
int ft_strnlen(char *str);
int new_line_search(char *str);
char *ft_strnjoin(char *src1, char *src2);
char *ft_line(char *str);
char    *get_next_line(int fd);

#endif
