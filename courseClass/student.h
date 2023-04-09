#include <iostream>
#include <vector>


class Student : public Person {
    public:
        Student() = default;
        Student(std::string, std::string, float, float, int, gender, 
        std::string, int);
        ~Student() = default;
        
        double meanCalc();
        friend class Course;
        
        bool operator==(const Student&);
        
    private:
        std::string index_;
        int year_;
        std::vector<double> grades_;
};

Student :: Student (std::string name, std::string surname, float weight, float height, int age, gender sex, 
                std::string index, int year) : Person(name, surname, weight, height, age, sex),
                index_(index), year_(year) {
    for(int i = 0; i < 5; i++){
        double grade;
        std::cin >> grade;
        grades_.emplace_back(grade);
    }
}

double Student :: meanCalc(){
    double result = 0;
    for(int i = 0; i < grades_.size(); i++)
        result += grades_[i];
    return result / grades_.size();
}

bool Student :: operator==(const Student& toCompare){
    if(index_ == toCompare.index_)
        return true;
    else
        return false;
}