/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:58:36 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/21 17:32:15 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * + checks whether c is a 7-bit unsigned char value
 *   that fits into the ASCII character set
 * + returns a nonzero value if character c is a 7-bit unsigned char value
 *   (that fits into the ASCII character set) and zero if not
 * + man isascii
 */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
