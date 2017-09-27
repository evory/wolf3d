/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:27:51 by bbrandt           #+#    #+#             */
/*   Updated: 2017/04/25 22:47:47 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_join(char *stock, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(stock, buff);
	ft_memdel((void **)&stock);
	return (tmp);
}

char	*ft_delete(char *stock)
{
	int		i;
	char	*tmp;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	tmp = ft_strsub(stock, i + 1, ft_strlen(stock) - i);
	ft_strdel(&stock);
	return (tmp);
}

char	*ft_fill_line(char *stock)
{
	int		i;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	return (ft_strsub(stock, 0, i));
}

int		get_next_line(const int fd, char **line)
{
	static char *stock;
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (!stock)
		stock = ft_strnew(1);
	while (!ft_strchr(stock, '\n'))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		stock = ft_free_join(stock, buff);
		if (ret == 0 && *(stock) == '\0')
			return (0);
		if (ret == 0)
			break ;
	}
	*line = ft_fill_line(stock);
	stock = ft_delete(stock);
	return (1);
}
