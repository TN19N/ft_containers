# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 17:37:59 by mannouao          #+#    #+#              #
#    Updated: 2022/07/31 12:30:37 by mannouao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	c++ -std=c++98 -Wall -Wextra -Werror main.cpp -o run
std :
	c++ -std=c++98 -Wall -Wextra -Werror my_test.cpp -o run -D STD
ft :
	c++ -std=c++98 -Wall -Wextra -Werror my_test.cpp -o run -D FT
clean :
	rm run