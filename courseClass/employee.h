#include <iostream>

class Employee : public Person {
    public:
        Employee() = default;
        Employee(std::string, std::string, float, float, int, gender, 
        std::string, std::string, float, float);
        ~Employee() = default;
        
        int leftToRetirement();
    
    private:
        std::string company_;
        std::string position_;
        float salary_;
        float experience_;
};

Employee :: Employee (std::string name, std::string surname, float weight, float height, int age, gender sex, 
        std::string company, std::string position, float salary, float experience) :
        Person(name, surname, weight, height, age, sex),
        company_(company), position_(position), salary_(salary), experience_(experience) {
    
}

int Employee :: leftToRetirement(){
    if(gender_ == M)
        return 65 - age_;
    else
        return 60 - age_;
}