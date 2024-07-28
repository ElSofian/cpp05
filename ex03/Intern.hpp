#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern const &obj);
		virtual ~Intern();

		Intern &operator=(Intern const &obj);

		AForm *makeForm(std::string const &formName, std::string const &target);
		AForm *createPPF(std::string target);
        AForm *createSCF(std::string target);
        AForm *createRRF(std::string target);
};

#endif