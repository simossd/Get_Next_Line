/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabri <mjabri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:20:41 by mjabri            #+#    #+#             */
/*   Updated: 2025/11/30 13:51:29 by mjabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_BNS
# define GNL_BNS

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100000
#endif

void *ft_calloc_bns(size_t nmemb);
int ft_strnlen_bns(char *str);
int new_line_search_bns(char *str);
char *ft_strnjoin_bns(char *src1, char *src2);
char *ft_line_bns(char *str);
char    *get_next_line_bonus(int fd);

#endif
