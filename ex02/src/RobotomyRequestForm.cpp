/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:28:34 by jschott           #+#    #+#             */
/*   Updated: 2024/02/21 19:34:49 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", false, 72, 45){
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("RobotomyRequestForm", false, 72, 45),
	_target(target){
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& origin)
	: Form(origin){
		this->_target = origin.getTarget();
		this->_signed = origin.getSigned();
}

RobotomyRequestForm& RobotomyRequestForm::operator = (RobotomyRequestForm& origin){
	if (this == &origin)
		return *this;
	this->_signed = origin.getSigned();
	this->_target = origin.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

void RobotomyRequestForm::execute(Bureaucrat& bureaucrat) const{
	Form::execute(bureaucrat);
	std::cout << ">Some Drilling Noises<" << std::endl 
		<< this->_target << " has been robotomized sucessfully 50%% of the time." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const{
	return this->_target;
}

std::ostream& operator <<(std::ostream& os, const RobotomyRequestForm& form){
	os << "Form:\t\t" << form.getName() << std::endl
		<< "Signed:\t\t" << std::boolalpha << form.getSigned() << std::endl
		<< "Sign grade:\t" << form.getGrade2Sign() << std::endl
		<< "Execute grade:\t" << form.getGrade2Exec() << std::endl
		<< "Target:\t\t" << form.getTarget() << std::endl;
	return os;
}