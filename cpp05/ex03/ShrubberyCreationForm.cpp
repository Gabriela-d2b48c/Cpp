/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 12:27:14 by gabriela          #+#    #+#             */
/*   Updated: 2023/12/28 10:58:31 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void) other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void
ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	AForm::execute(executor);
	std::ofstream ofs(_target + "_shrubbery");
	if (ofs)
	{
		ofs << "       ###" << std::endl;
		ofs << "      #o###" << std::endl;
		ofs << "    #####o###" << std::endl;
		ofs << "  #o#\\#|#/###" << std::endl;
		ofs << "   ###\\|/#o###" << std::endl;
		ofs << "     # }|{  #" << std::endl;
		ofs << "       }|{" << std::endl;
		ofs.close();
		std::cout << "Shrubbery named " << _target << "_shrubbery was created." << std::endl;
	}
	else 
		std::cerr << "Error! Could not open file " << _target << "_shrubbery" << std::endl;
}
