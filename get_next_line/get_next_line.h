/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/06/30 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *str, int c);
size_t			ft_strlen_sp(char *str, char sp);
size_t			assign(size_t len_s1, char *s1, char *pointer);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup_sp(char *s1, char sp);
int				joining(char *buffer, int count, char **residue);
int				lining(char **residue, char **line, char *x);
int				after_reading(char **residue, char **line);
int				error_pr(char **line, char **residue);

#endif
