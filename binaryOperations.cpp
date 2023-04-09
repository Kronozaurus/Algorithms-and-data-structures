#include <iostream>

using namespace std;

//szukamy liczby z najwieksza liczba jedynek w postaci binarnej
int mostBinaryOnes (int array[], const int size){
    
    int mostCountedOnes = 0;
    int mostOnes;
    
    for(int i = 0; i < size; i++){
        int countOnes = 0;
        for (unsigned int mask = ; mask > 0; mask >>= 1){ //32 bitowa maska z jedynka z przodu, przesuwamy z kazda iteracja w prawo
            if (mask & array[i]){ // jezeli na obecnej pozycji jedynki w masce tez jest jeden czyli logiczny AND zwiekszamy licznik jedynek
                countOnes++;
            }
        }
        if(countOnes > mostCountedOnes){ //ustalamy liczbe z najwieksza liczba binarnych jedynek
            
            mostOnes = array[i];
            mostCountedOnes = countOnes;
        }
    }
    return mostOnes;
}

//zliczamy liczbe wystapien tej samej sekwencji zer i jedynek
int howManySequences (unsigned int sequence, unsigned int number){
    int count = 0;
    bool isEqual;

    for(number; number > 0; number >>= 1){ //przesuwamy binarnie number w prawo z kazda iteracja poki jest rozny od 0
        for(unsigned int mask = 0x00000001; mask < sequence; mask <<= 1){ //przesuwamy maske w lewo dopoki jest mniejsza niz binarna postac szukanej sekwencji
									  //czyli szukamy od najmniej znaczacych bitow czy wystapila sekwencja, a w glownej petli przesuwamy wszystko w prawo
            if((mask & number) == (mask & sequence)){ //sprawdzamy czy najmlodsze bity number o dlugosci takiej jak sekwencja maja taka sama wartosc jak sekwencja
                isEqual = true;
            }
            else{ //jezeli chociaz jeden z nich jest inny
                isEqual = false; 
                break;
            }
        }
        if(isEqual){ //notujemy ze wystapila sekwencja i przesuwamy binarnie number w prawo zeby szukac kolejnej sekwencji
            count++;
        }
    }
    return count;
}

//zliczamy jedynki w postaci binarnej ze zlozonoscia o(n)
int countBinaryOnesN (long int variable){ //o(n) - wykonuje sie tyle razy ile bitowa liczba

    int count = 0; 

    for(variable; variable > 0; variable >>= 1){ //przesuwa zmienną w prawo poki rozna od 0
	
	count += variable & 1; //jezeli ostatni bit to 1 to count + 1 potem przesuwamy i kolejny bit

    }

    return count;
} 
// z maska wykonywaloby sie zawsze np 32 razy? więc nie o(n)

//szukamy najdluzszej sekwencji binarnych jedynek
int longestSeriesOfOnes(int value){
    
    int longestStreak = 0;
    int currentStreak = 0;
    
    for(unsigned int mask = 0x80000000; mask > 0; mask >>= 1){
        bool condition = false;
        if(mask & value){ //jezeli znalezlismy jedynke maska to zwiekszamy streak
            condition = true;
            currentStreak++;
        }
        if(condition && (currentStreak > longestStreak)){ //jezeli mielismy poprzednio jedynke to sprawdzamy czy obecny streak jest najdluzszy
            longestStreak = currentStreak;
        }
        else{ //jezeli nie bylo jedynki to resetujemy streak
            currentStreak = 0;
        }
    }
    return longestStreak;
}


//funkcja zwraca dla podanej zmiennej liczbe jedynek i zer w postaci binarnej i najdluzsza serie jedynek
int BinarySeriesZerosAndOnes (long int variable, int &maxSeries, int &numberOfZeros){

    int seriesCount = 0;
    int numberOfOnes = 0;
    for(unsigned int mask = 0x80000000; mask > 0; mask >>= 1){
        if(mask & variable){
            seriesCount++;
	    numberOfOnes++;
            if(seriesCount > maxSeries){
                maxSeries = seriesCount;
            }
        }
        else {
            seriesCount = 0;
	    numberOfZeros++;
        }
    }
    return numberOfOnes;
}



int main() {


	const int size = 10;
	int array[size];
            
	for(int i = 0; i < size; i++){
		cin >> array[i];
	}
            
	cout << mostBinaryOnes(array, size);


	unsigned int sequence, number;
        cin >> sequence >> number;
            
        cout << howManySequences(sequence, number);

	
	return 0;
}
