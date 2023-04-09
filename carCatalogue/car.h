class Car{
    public:
        Car(std::string, int, double, char);
        Car() = default;
        
    private:
        std::string m_register;
        int m_power;
        double m_weight;
        char m_engine;
        
        friend class CarCatalogue;
        friend bool operator== (const Car& a, const Car& b);
};

Car :: Car (std::string m_register, int power, double weight, char productEngine) :
            m_register(m_register), m_power(power), m_weight(weight), m_engine(productEngine){
    
}

bool operator==(const Car& a, const Car& b){
    return (a.m_register == b.m_register && a.m_power == b.m_power && 
            a.m_weight == b.m_weight && a.m_engine == b.m_engine);
}