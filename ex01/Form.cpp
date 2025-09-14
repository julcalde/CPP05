/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:42:35 by julcalde          #+#    #+#             */
/*   Updated: 2025/09/14 18:57:47 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Default constructor
	Note: it will prioritize GradeTooHighException over GradeTooLowException
	      if both grades are invalid.
*/
Form::Form(const std::string& name, int signGrade, int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	std::cout << "Form " << _name << " constructor called with sign grade " << _signGrade << " and exec grade " << _execGrade << std::endl;
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Form " << _name << " destructor called" << std::endl;
}

Form::Form(const Form& other)
	: _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _isSigned(other._isSigned)
{
	std::cout << "Form " << _name << " copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form " << _name << " copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return(*this);
}

const std::string Form::getName() const
{
	return (_name);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() << ", is " << (form.getIsSigned() ? "signed" : "not signed") 
	   << ", sign grade: " << form.getSignGrade() 
	   << ", exec grade: " << form.getExecGrade();
	return (os);
}
