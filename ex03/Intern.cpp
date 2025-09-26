/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:45:47 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/26 14:53:07 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)other; return *this;
}

AForm* Intern::createShrubbery(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    static FormEntry forms[] =
	{
        {"shrubbery creation", &createShrubbery},
        {"robotomy request", &createRobotomy},
        {"presidential pardon", &createPresidential},
        { "", NULL }
    };

    for (int i = 0; forms[i].creator; ++i)
	{
        if (formName == forms[i].name)
		{
            std::cout << "Intern creates " << formName << std::endl;
            return (forms[i].creator(target));
        }
    }
    std::cout << "Error: Form " << formName << " does not exist." << std::endl;
    return (NULL);
}
