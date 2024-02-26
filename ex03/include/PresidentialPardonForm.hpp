/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:42:19 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 09:54:23 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string _target;

		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm& origin);
		PresidentialPardonForm& operator = (PresidentialPardonForm& origin);
		~PresidentialPardonForm();

		void execute(Bureaucrat& bureaucrat) const;
		std::string getTarget() const;
};

std::ostream& operator << (std::ostream& os, PresidentialPardonForm const & form);

#endif