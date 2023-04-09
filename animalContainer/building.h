#include <iostream>

class Building {
    public:
        Building(std::string, float, float, float);
        Building() = default;
        ~Building() = default;
        
        void dispData();
        
        friend void sortDispBuilding(std::vector<Building>);
        
    private:
        std::string name_;
        float gpsX_;
        float gpsY_;
        float height_;
};

Building :: Building (std::string name, float gpsX, float gpsY, float height) 
                    : name_(name), gpsX_(gpsX), gpsY_(gpsY), height_(height) {
                        
}

void Building :: dispData () {
    std::cout << name_ << " " << gpsX_ << " " << gpsY_ << " " << height_ << " ";
}