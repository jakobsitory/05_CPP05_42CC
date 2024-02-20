/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:35:36 by jschott           #+#    #+#             */
/*   Updated: 2024/02/20 11:58:53 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(75), _name("_generic_bureaucrat"){
}

Bureaucrat::Bureaucrat(std::string name, int grade){
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_name = name;
	this->_grade = grade;	
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy){
	*this = copy;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& copy){
	if (this == &copy)
		return *this;
	this->_name = copy.getName();
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

std::ostream& operator <<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
