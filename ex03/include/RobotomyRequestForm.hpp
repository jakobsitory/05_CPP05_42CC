/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:41:44 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 09:54:27 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string _target;

		RobotomyRequestForm();
		
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm& origin);
		RobotomyRequestForm& operator = (RobotomyRequestForm& origin);
		~RobotomyRequestForm();

		void execute(Bureaucrat& bureaucrat) const;
		std::string getTarget() const;
};

std::ostream& operator << (std::ostream& os, RobotomyRequestForm const & form);

#endif