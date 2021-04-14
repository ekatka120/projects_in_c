/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskittri <patutinaek@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 14:40:59 by dskittri          #+#    #+#             */
/*   Updated: 2020/07/26 15:03:19 by dskittri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(char *string, ...);

char	*ft_parser(char *string, va_list argptr);
void	ft_parser_p1(char *string, va_list argptr, char *parser, int i);
int		ft_parser_p2(char *string, va_list argptr, char *parser, int i);

int		ft_spec(char *string, va_list argptr);
int		ft_spec_int(va_list argptr, char *parser);
int		ft_spec_string(va_list argptr, char *parser);
int		ft_spec_unsig(va_list argptr, char *parser);
int		ft_spec_char(va_list argptr, char *parser);
int		ft_spec_hex_sm(va_list argptr, char *parser);
int		ft_spec_hex_bg(va_list argptr, char *parser);
int		ft_spec_pnt(va_list argptr, char *parser);
int		ft_spec_per(char *parser);

int		ft_printf_p1(char *string, va_list argptr, int count, int i);
int		ft_spec_p1(char *string, va_list argptr, char *parser, int i);
int		ft_spec_string_2(char *parser, int len, char *str);
void	ft_spec_int_p2(char *parser, int number, char *my_numb, int len);
void	ft_spec_int_p3(char *parser, int number, char *my_numb, int len);
void	ft_spec_int_p4(char *parser, int number, char *my_numb, int len);
void	ft_spec_unsig_p2(char *parser, char *my_numb, int len);

int		ft_atoi(const char *str);
char	*ft_itoa(int num);
char	*ft_itoa_unsigned(unsigned int num);
char	*ft_itoa_hex_sm(long unsigned int num);
char	*ft_itoa_hex_bg(unsigned int num);

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(unsigned int c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_put_n_char_fd(char c, int n, int fd);
void	ft_put_n_str_fd(char *str, int n, int fd);

size_t	ft_strlen(char *str);
int		len_unsign(size_t i);
int		len16(long unsigned int i);
int		len_num(int i);

char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalpha(int c);
char	*ft_strchr(const char *str, int c);
int		ft_strchr_sp1(const char *s, int c, char sp);

int		find_spec(char *string);
void	ft_hex_char(long unsigned int tmp, int place, char *res, int plus);

#endif
