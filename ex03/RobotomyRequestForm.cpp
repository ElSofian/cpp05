# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("random") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj) : AForm(obj), _target(obj._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &obj) {
	if (this != &obj)
	    setSignatureStatus(obj.getSigned());
	return (*this);	
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() >= getExecGradeRequired())
		throw Bureaucrat::GradeTooLowException();
	else
	{
		std::cout << "*drilling noises*" << std::endl;
		if (rand() % 2)
			std::cout << _target << " has been robotomized successfully" << std::endl << std::endl;
		else
			std::cout << "Robotomized failed" << std::endl << std::endl;
	}
}