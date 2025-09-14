/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:03:05 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/14 21:45:45 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::srand(std::time(0)); // this line is to seed the random number generator for robotomy requests
	try
	{
		Bureaucrat tizio("Tizio", 5);
		ShrubberyCreationForm shrub("npc");
		RobotomyRequestForm robot("Terminator");
		PresidentialPardonForm cavalier("Silvio");
		std::cout << std::endl;

		std::cout << tizio << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << cavalier << "\n" << std::endl;
		
		tizio.signForm(shrub);
		tizio.signForm(robot);
		tizio.signForm(cavalier);
		std::cout << std::endl;

		tizio.executeForm(shrub);
		tizio.executeForm(robot);
		tizio.executeForm(cavalier);
		std::cout << std::endl;

		Bureaucrat caio("Caio", 140);
		caio.executeForm(shrub); // should fail because grade too low
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return (0);
}
