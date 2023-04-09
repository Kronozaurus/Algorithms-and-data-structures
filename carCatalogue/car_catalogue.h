#include <iostream>

class CarCatalogue{
    public:
        CarCatalogue() { m_counter = 0; }
        
        void addCar(Car);
        void removeCar(Car);
        void dispCatalogue();
        
        static constexpr int HEAP_SIZE = 6;
        Car m_catalogue[HEAP_SIZE];
        
    private:
        int m_counter;
        
};

void CarCatalogue :: addCar (Car toADD){
    if(m_counter <= HEAP_SIZE)
        m_catalogue[m_counter++] = toADD;
        
    for(int i = 0; i < m_counter; i++){
        int minIndex = i;
        for(int j = i + 1; j < m_counter; j++){
            if(m_catalogue[j].m_power < m_catalogue[minIndex].m_power)
                minIndex = j;
        }
        std::swap(m_catalogue[i], m_catalogue[minIndex]);
    }
    return;    
}

void CarCatalogue :: dispCatalogue (){
    for(int i = 0; i < m_counter; i++){
        std::cout << m_catalogue[i].m_register << " " << m_catalogue[i].m_power;
        if(i != m_counter - 1) std::cout << " ";
    }
}

void CarCatalogue :: removeCar (Car toSUB){
    for(int i = 0; i < m_counter; i++){
        if(m_catalogue[i] == toSUB){ //przeciazone == zeby tu porownac
            std::swap(m_catalogue[i], m_catalogue[m_counter - 1]);
            m_counter--;
        }
    }
    for(int i = 0; i < m_counter; i++){
        int minIndex = i;
        for(int j = i + 1; j < m_counter; j++){
            if(m_catalogue[j].m_power < m_catalogue[minIndex].m_power)
                minIndex = j;
        }
        std::swap(m_catalogue[i], m_catalogue[minIndex]);
    }
}