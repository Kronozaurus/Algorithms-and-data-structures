#include <iostream>

class Building {
    public:
        Building(float, float, std::string);
        Building() = default;
        ~Building() = default;
    protected:
        float usableArea_;
        std::string street_;
    private:
        float price_;
};

Building :: Building (float price, float usableArea, std::string street)
                    : price_(price), usableArea_(usableArea), street_(street) {

}