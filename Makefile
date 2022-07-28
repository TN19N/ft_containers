# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 17:37:59 by mannouao          #+#    #+#              #
#    Updated: 2022/07/28 15:35:50 by mannouao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	c++ -std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3 main.cpp  -o run
clean :
	rm run