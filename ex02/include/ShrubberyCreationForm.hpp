/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:33:41 by jschott           #+#    #+#             */
/*   Updated: 2024/02/21 19:35:03 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string _target;
		ShrubberyCreationForm();
		
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm& origin);
		ShrubberyCreationForm& operator = (ShrubberyCreationForm& origin);
		~ShrubberyCreationForm();

		void execute(Bureaucrat& bureaucrat) const;
		std::string getTarget() const;
};

std::ostream& operator << (std::ostream& os, ShrubberyCreationForm const & form);

#endif