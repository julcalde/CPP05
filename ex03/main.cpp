/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:03:05 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/26 14:57:47 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	std::srand(std::time(0));
    Intern intern;
    Bureaucrat bob("Bob", 5);
    AForm* form;

    form = intern.makeForm("robotomy request", "Bender");
    if (form)
	{
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }
	std::cout << std::endl;
    form = intern.makeForm("shrubbery creation", "home");
    if (form)
	{
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }
	std::cout << std::endl;
    form = intern.makeForm("presidential pardon", "Ford");
    if (form)
	{
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }
	std::cout << std::endl;
    form = intern.makeForm("invalid form", "Nobody"); // Should print error
    if (form)
        delete form;

	return (0);
}
