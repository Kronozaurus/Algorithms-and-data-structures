#include <iostream>
#include <vector>

class HouseCatalogue {
    public:
        HouseCatalogue() { objectCount = 0; }
        ~HouseCatalogue() = default;

        void addHouse(House);
        void removeHouse(std::string, std::string);

        //House houseArray[5];
        std::vector<House> houseArray;

        friend std::ostream& operator<<(std::ostream&, const HouseCatalogue&);

    private:
        int objectCount;

};

void HouseCatalogue :: addHouse (House toAdd){
    if(objectCount < 5) {
        int insertIndex = 0;
        for(int i = 0; i < objectCount; i++){
            if(toAdd > houseArray[i])
               insertIndex = i + 1;
        }
        houseArray.insert(houseArray.begin() + insertIndex, toAdd);
        objectCount++;
    }
}

void HouseCatalogue :: removeHouse(std::string street, std::string number){
    for(int i = 0; i < objectCount; i++) {
        if(street == houseArray[i].street_ and number == houseArray[i].number_) {
            houseArray.erase(houseArray.begin() + i);
            objectCount--;
            break;
        }
    }
}

std::ostream& operator<<(std::ostream& stream, const HouseCatalogue& toDisp) {
    for(int i = 0; i < toDisp.objectCount; i++){
        return stream << toDisp.houseArray[i] << " ";
    }
}