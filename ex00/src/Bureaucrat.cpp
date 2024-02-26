/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:35:36 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 09:19:26 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("_generic_bureaucrat"), _grade(75){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;	
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) 
				: _name(copy.getName()), _grade(copy.getGrade()){
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& copy){
	if (this == &copy)
		return *this;
	this->_grade = copy.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat Bureaucrat::operator ++(int){
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	Bureaucrat tmp;
	tmp._grade = this->_grade--;
	return tmp;
}

Bureaucrat& Bureaucrat::operator ++(void){
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	--this->_grade;
	return *this;
	
}

Bureaucrat Bureaucrat::operator --(int){
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	Bureaucrat tmp;
	tmp._grade = this->_grade++;
	return tmp;
	
}

Bureaucrat& Bureaucrat::operator --(void){
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	++this->_grade;
	return *this;
	
}

std::string Bureaucrat::getName() const{
	return (this->_name);	
}

int			Bureaucrat::getGrade() const{
	return (this->_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
				return ("Bureaucrat::GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
				return ("Bureaucrat::GradeTooLowException");
}

std::ostream& operator <<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
