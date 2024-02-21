/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:10:06 by jschott           #+#    #+#             */
/*   Updated: 2024/02/21 13:01:55 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: _name("_generic_form_"), _signed(false), _grade2sign(150), _grade2exec(150){
}

Form::Form(std::string name, bool is_signed, int grade2sign, int grade2exec)
	: _name(name), _signed(is_signed), _grade2sign(grade2sign), _grade2exec(grade2exec) {
}

Form::Form(Form& origin)
	: _name(origin.getName()),
		_signed(origin.getSigned()),
		_grade2sign(origin.getGrade2Sign()), 
		_grade2exec(origin.getGrade2Exec()){
}

Form& Form::operator = (Form& origin){
	if (this == &origin)
		return *this;
	this->_signed = origin.getSigned();
	// this->_grade2sign = origin.getGrade2Sign();
	// this->_grade2exec = origin.grade2exec();
	return *this;
}

Form::~Form(){
}

std::string Form::getName() const{
	return (this->_name);
}

bool Form::getSigned() const{
	return (this->_signed);
}

int Form::getGrade2Sign() const {
	return (this->_grade2sign);
}

int Form::getGrade2Exec() const{
	return (this->_grade2exec);
}

void Form::beSigned(Bureaucrat& bureaucrat){
	if (this->_grade2sign < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	if (this->getSigned())
		throw Form::AlreadySignedException();
	else
		this->_signed = true;
}


std::ostream& operator <<(std::ostream& os, const Form& form){
	os << "Form:\t\t" << form.getName() << std::endl
		<< "Signed:\t\t" << std::boolalpha << form.getSigned() << std::endl
		<< "Sign grade:\t" << form.getGrade2Sign() << std::endl
		<< "Execute grade:\t" << form.getGrade2Exec() << std::endl;
	return os;
}