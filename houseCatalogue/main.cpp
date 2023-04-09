#include <iostream>
#include <vector>
#include "building.h"
#include "house.h"
#include "house_catalogue.h"

int main(){

	std::vector<int> array = {1,3,5,7,9};
	int insert;
	std::cin >> insert;
	int insertIndex = 0;
        for(int i = 0; i < 5; i++){
            if(insert > array[i])
                insertIndex = i + 1;
        }
	std::cout << insertIndex;

	return 0;
}