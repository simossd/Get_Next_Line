/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:50:20 by mjabri            #+#    #+#             */
/*   Updated: 2025/12/01 09:02:39 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	*ft_calloc(size_t nmemb);
int		ft_strnlen(char *str);
int		new_line_search(char *str);
char	*ft_strnjoin(char *src1, char *src2);
char	*ft_line(char *str);
char	*get_next_line(int fd);

#endif
