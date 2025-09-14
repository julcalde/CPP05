/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:03:05 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/14 19:00:07 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		// this section will work without exceptions
		
		Bureaucrat aref("Aref", 50);
		Form taxForm("TaxForm", 60, 40);
		std::cout << aref << std::endl;
		std::cout << taxForm << std::endl;
		aref.signForm(taxForm);
		std::cout << taxForm << std::endl;
		std::cout << std::endl;
		
		// this section will throw GradeTooLowException when signing
		
		Bureaucrat khaled("Khaled", 70);
		khaled.signForm(taxForm);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	// will throw exceptions when creating forms with invalid grades
	try
	{
		Form invalidForm1("InvalidForm1", 0, 151);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		Form invalidForm2("InvalidForm2", 151, 0);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		Form invalidForm3("InvalidForm3", 40, 151);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		Form invalidForm4("InvalidForm4", 151, 40);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	return (0);
}
