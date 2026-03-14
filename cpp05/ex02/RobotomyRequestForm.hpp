#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class   RobotomyRequestForm : public AForm {
        private:
                std::string     target_;
        protected:
                void    execute2() const;
        public:
                RobotomyRequestForm(std::string target);
                RobotomyRequestForm(const RobotomyRequestForm &Another);
                RobotomyRequestForm     &operator=(const RobotomyRequestForm &Another);
                ~RobotomyRequestForm();
};

#endif
