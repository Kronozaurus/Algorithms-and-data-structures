#include <iostream>

class House : public Building {
    public:
        House(int, float, std::string, float, float, std::string);
        House() = default;
        ~House() = default;

        bool operator>(const House&);
        bool operator==(const House&);
        friend std::ostream& operator<<(std::ostream&, const House&);
        friend class HouseCatalogue;

    private:
        int roomCount_;
        float fieldArea_;
        std::string number_;

};

House :: House(int roomCount, float fieldArea, std::string number, 
                float price, float usableArea, std::string street)
                : Building(price, usableArea, street),
                roomCount_(roomCount), fieldArea_(fieldArea), number_(number) {

} 

bool House :: operator>(const House& toCompare){
    if (usableArea_ > toCompare.usableArea_ )
        return true;
    else if (usableArea_ == toCompare.usableArea_)
        if (fieldArea_ > toCompare.fieldArea_)
            return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& stream, const House& toDisp){
    return stream << toDisp.street_ << " " << toDisp.number_ << " " 
        << toDisp.fieldArea_ << " " << toDisp.usableArea_;
}

bool House :: operator==(const House& toCompare) {
    if(number_ == toCompare.number_ and street_ == toCompare.street_)
        return true;
    else
        return false;
}