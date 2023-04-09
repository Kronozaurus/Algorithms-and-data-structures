#include <iostream>

enum gender {K, M};

class Person{
    public:
        Person() = default;
        Person(std::string, std::string, float, float, int, gender);
        ~Person() = default;
        
        void disp();
        float calcBMI();
        
        friend class Employee;
        friend class Student;
        friend class Course;
        
    protected:
        gender gender_;
        
    private:
        std::string name_;
        std::string surname_;
        float weightKG_;
        float heightCM_;
        int age_;
};

Person :: Person (std::string name, std::string surname, float weight, float height, int age, gender sex)
                : name_(name), surname_(surname), weightKG_(weight), heightCM_(height), age_(age), gender_(sex) {
    
}

void Person :: disp(){
    std::cout << name_ << " " << surname_ << " " << weightKG_ << " " 
    << heightCM_ << " " << age_ << " " << gender_ << std::endl;
}

float Person :: calcBMI(){
    return weightKG_ / (heightCM_ / 100) * (heightCM_ / 100);
}