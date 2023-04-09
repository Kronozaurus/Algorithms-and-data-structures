#include <iostream>

class Animal {
    public:
        Animal(std::string, float, int, std::string);
        Animal() = default;
        ~Animal() = default;
        
        void dispData();
        
        friend void sortDispAnimal(std::vector<Animal>);
        
    private:
        std::string name_;
        float weight_;
        int birthYear_;
        std::string id_;
};

Animal :: Animal (std::string name, float weight, int birthYear, std::string id)
                : name_(name), weight_(weight), birthYear_(birthYear), id_(id) {
                    
}

void Animal :: dispData () {
    std::cout << name_ << " " << weight_ << " " << birthYear_ << " " << id_ << " ";
}