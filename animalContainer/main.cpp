#include <iostream>
#include <vector>
#include "animal.h"
#include "building.h"
#include "container.h"

void checkAnimal(std::string& name, float& weight, int& birthYear, std::string& id){
    bool wrong;
    do {
        wrong = false;
        std::cin >> name;
        for(int i = 0; i < name.size(); i++){
            if(name[i] == ' ')
                wrong = true;
        }
    } while(wrong);
    
    while(!(std::cin >> weight)){
        std::cin.clear();
        std::cin.ignore();
    }
    
    while(!(std::cin >> birthYear)){
        std::cin.clear();
        std::cin.ignore();
    }
    
    std::cin >> id;
    
}

void checkBuilding(std::string& name, float& gpsX, float& gpsY, float& height){
    bool wrong;
    do {
        wrong = false;
        std::cin >> name;
        for(int i = 0; i < name.size(); i++){
            if(name[i] == ' ')
                wrong = true;
        }
    } while(wrong);
    
    while(!(std::cin >> gpsX)){
        std::cin.clear();
        std::cin.ignore();
    }
    
    while(!(std::cin >> gpsY)){
        std::cin.clear();
        std::cin.ignore();
    }
    
    while(!(std::cin >> height)){
        std::cin.clear();
        std::cin.ignore();
    }
}

void sortDispAnimal(std::vector<Animal> array){
    for(int i = 0; i < array.size(); i++){
        int minimumIndex = i;
        for(int j = i+1; j < array.size(); j++){
            if(array[j].birthYear_ == array[minimumIndex].birthYear_){
                if(array[j].weight_ < array[minimumIndex].weight_){
                    minimumIndex = j;
                }
            }
            else if(array[j].birthYear_ > array[minimumIndex].birthYear_){
                minimumIndex = j;
            }
        }
        std::swap(array[i], array[minimumIndex]);
    }
    
    for(int i = 0; i < array.size(); i++){
        array[i].dispData();
    }
}

void sortDispBuilding(std::vector<Building> array){
    for(int i = 0; i < array.size(); i++){
        int minimumIndex = i;
        for(int j = i+1; j < array.size(); j++){
            if((array[j].gpsX_ + array[j].gpsY_) < (array[minimumIndex].gpsX_ + array[minimumIndex].gpsY_)){
                minimumIndex = j;
            }
        }
        std::swap(array[i], array[minimumIndex]);
    }
    
    for(int i = 0; i < array.size(); i++){
        array[i].dispData();
    }
}

int main() {
    std::string name;
    float weight;
    int birthYear;
    std::string id;
    
    int position;
    float gpsX;
    float gpsY;
    float height;
    
    Container<Animal> animalContainer;
    Container<Building> buildingContainer;
    
    for(int i = 0; i < 4; i++){
        checkAnimal(name, weight, birthYear, id);
        Animal myAnimal(name, weight, birthYear, id);
        animalContainer.addElement(myAnimal);
    }
    
    for(int i = 0; i < 4; i++){
        checkBuilding(name, gpsX, gpsY, height);
        Building myBuilding(name, gpsX, gpsY, height);
        buildingContainer.addElement(myBuilding);
    }
    
    std::cin >> position;
    animalContainer.removeElement(position);
    
    sortDispAnimal(animalContainer.getElements());
    sortDispBuilding(buildingContainer.getElements());
    
    return 0;
}