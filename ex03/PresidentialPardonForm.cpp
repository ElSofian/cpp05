# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("random") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj) : AForm(obj), _target(obj._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj) {
	if (this != &obj)
	    setSignatureStatus(obj.getSigned());
	return (*this);	
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() >= getExecGradeRequired())
		throw Bureaucrat::GradeTooLowException();
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl << std::endl;
}