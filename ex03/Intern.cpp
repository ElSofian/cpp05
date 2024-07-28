#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &obj) {
	*this = obj;
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &obj) {
	(void)obj;
	return *this;
}

AForm *Intern::createPPF(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::createSCF(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRRF(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
	AForm *(Intern::*catalog[3])(std::string target);
    AForm *ret = NULL;
    int     i = 0;
    int     found = 0;

    catalog[0] = &Intern::createPPF;
    catalog[1] = &Intern::createSCF;
    catalog[2] = &Intern::createRRF;

    std::string request[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};

    for (i = 0; i < 3; i++)
	{
		if (request[i] == formName)
		{
            std::cout << "Intern creates " << formName << std::endl;
			ret = (this->*catalog[i])(target);
            found = 1;
			break ;
		}
	}
    if (!found)
    {
        std::cout << "I didn't find the form, don't hit me please 🙏" << std::endl;
        return NULL;
    }
    return ret;
}