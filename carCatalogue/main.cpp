#include <iostream>
#include "car.h"
#include "car_catalogue.h"

void insertAndCheck(std::string& reg, int& power, double& weight, char& engine){

    for(int i = 0; i < 1; i++){
        std::cin >> reg;
        if(reg.length() != 4){
            i--;
            continue;
        }
        for(int j = 0; j < 4; j++){
            if(!((reg[j] >= '0' and reg[j] <= '9') or 
              (reg[j] >= 'a' and reg[j] <= 'z') or 
              (reg[j] >= 'A' and reg[j] <= 'Z'))){
                  i--;
                  break;
              }
        }
    }
    
    std::cin >> power;
    
    std::cin >> weight;
    
    std::cin >> engine;
    while(!(engine != 'B' or engine != 'D' or engine != 'E' or engine != 'H')) 
       std::cin >> engine;
}

int main() {
    CarCatalogue catalogue;
    
    std::string reg;
    int power;
    double weight;
    char engine;
    
    insertAndCheck(reg, power, weight, engine);
    Car car1(reg, power, weight, engine);
    
    insertAndCheck(reg, power, weight, engine);
    Car car2(reg, power, weight, engine);
    
    insertAndCheck(reg, power, weight, engine);
    Car car3(reg, power, weight, engine);
    
    insertAndCheck(reg, power, weight, engine);
    Car car4(reg, power, weight, engine);
    
    insertAndCheck(reg, power, weight, engine);
    Car car5(reg, power, weight, engine);
    
    insertAndCheck(reg, power, weight, engine);
    Car car6(reg, power, weight, engine);
    
    catalogue.addCar(car1);
    catalogue.addCar(car2);
    catalogue.addCar(car3);
    catalogue.addCar(car4);
    catalogue.addCar(car5);
    catalogue.addCar(car6);
    
    catalogue.dispCatalogue();
    
    return 0;
}