/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:03:05 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/12 14:31:25 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
		bob.incrementGrade(); // should throw exception (too high grade or "< 1")
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n" << std::endl;
	}

	try
	{
		Bureaucrat noob("Noob", 149);
		std::cout << noob << std::endl;
		noob.decrementGrade();
		std::cout << noob << std::endl;
		noob.decrementGrade(); // should throw exception (too high grade or "< 1")
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n" << std::endl;
	}

	try
	{
		Bureaucrat invalidHugh("InvalidHugh", 0);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n" << std::endl;
	}

	try
	{
		Bureaucrat invalidLowe("InvalidLowe", 0);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n" << std::endl;
	}


	return (0);
}
