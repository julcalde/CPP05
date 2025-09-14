/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:42:35 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/14 20:05:19 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _name("DefaultName"), _signGrade(150), _execGrade(150), _isSigned(false)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	std::cout << "AForm " << _name << " constructor called with sign grade " << _signGrade << " and exec grade " << _execGrade << std::endl;
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "Form " << _name << " destructor called" << std::endl;
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _isSigned(other._isSigned)
{
	std::cout << "AForm " << _name << " copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm " << _name << " copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return(*this);
}

const std::string& AForm::getName() const
{
	return (_name);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form not signed!");
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm " << form.getName() << ", is " << (form.getIsSigned() ? "signed" : "not signed") 
	   << ", sign grade: " << form.getSignGrade() 
	   << ", exec grade: " << form.getExecGrade();
	return (os);
}
