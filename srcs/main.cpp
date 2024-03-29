/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:41:22 by esafar            #+#    #+#             */
/*   Updated: 2022/12/12 15:24:17 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <string.h>

#define	BUF_SIZE 10000

#include "../inc/server.hpp"

extern bool	run;

void	signalCheck(int signum)
{
	(void)signum;
	run = false;
}

bool	checkPort(std::string port)
{
	for (size_t i = 0; i < port.length(); i++)
	{
		if (port[i] < '0' || port[i] > '9')
			return (false);
		// std::cout << YELLOW "Port: -> " << port[i] << END << std::endl;
	}
	return (true);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (!checkPort(av[1]))
		{
			std::cerr << "Error: Invalid port number" << std::endl;
			return (EXIT_FAILURE);
		}
		else
		{
			//start running server here
			run = true;
			signal(SIGINT, signalCheck);
			try {
				Server server(av[1], av[2]);
			}
			catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
				return (EXIT_FAILURE);
			}
		}
	}
	else
	{
		std::cerr << "Error: usage: ./ircserv <port> <password>" << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}