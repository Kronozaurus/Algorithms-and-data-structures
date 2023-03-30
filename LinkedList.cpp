#include <iostream>

//LINKED LIST 

template <class Type> class List;
template <class Type> class Link;

template <class Type> class Link {
    public:
        Link(Type, Link* = nullptr);
        Link() = default;
        ~Link() = default;

        Type value_;

        friend class List <Type>;
        friend std::ostream& operator<<(std::ostream&, const List <std::string>&); //overloaded << operator

    protected:
        Link <Type>* next_; //pointer to the next element
};

//CONSTRUCTOR
template <class Type> Link <Type> :: Link (Type value, Link <Type>* next) 
                                    : value_(value), next_(next) {

}

template <class Type> class List {
    public:
        List(Link <Type>* = nullptr);
        ~List() = default;

        void add(Type);
        void remove();
        void check(std::string);

        friend std::ostream& operator<<(std::ostream&, const List <std::string>&);

    private:
        Link <Type>* first_; //pointer to the first element
};


//CONSTRUCTOR
template <class Type> List <Type> :: List (Link <Type>* first) 
                                            : first_(first) {

}

template <class Type> void List <Type> :: add (Type toAdd) {

    //dodajemy na początek
    //toAdd staje sie pierwszym elementem na liscie, a poprzedni pierwszy nastepnym
    //czyli dla pierwszego elementu dodajemy dana wartosc, a wskaznik next to nullptr bo jest tylko element
    //kolejny element staje sie nowym firstem a poprzedni first zostaje wskazany jako next
    //czyli jest to kolejka First In Last Out (w zwiazku z tym co znajduje sie w metodzie remove)
    first_ = new Link <Type> (toAdd, first_); 

    // dodajemy na koniec, w tym wypadku bylaby to kolejka First In First Out
    /*
    if(Link<Type>->next_ == nullptr){
        Link<Type>->next_ = new Link <Type> (toAdd);
        toAdd->next_ = nullptr;
    }
    */
}

template <class Type> void List <Type> :: remove () {
    
    //jezeli lista nie jest pusta
    if(first_ != nullptr){
        //zmienna pomocnicza przechowujaca pierwszy element
        Link <Type>* ptr = first_;
	//nowym pierwszym elementem staje sie nastepny z perspektywy poprzedniego pierwszego elementu czyli 2 na oryginalnej liscie
        first_ = ptr->next_;  
	//usuwamy poprzedni pierwszy element kolejki     
        delete ptr;
    }
    //czyli usuwamy najnowszy element z listy, bo dodajemy na poczatek
}

//metoda wypisujaca stringi z listy, ktore sa takie same jak podany string
template <class Type> void List <Type> :: check (std::string toCheck) {

    Link<std::string>* tmp = first_; //zmienna pomocnicza na 1 element do iterowania po liscie
    
    while(tmp){ //dopoki tmp nie jest nullptr, czyli az do konca naszej listy

        int count = 0;
        for(int i = 0; i < toCheck.size(); i++){
            if(tmp->value_[i] == toCheck[i])
                count++; //zliczamy ile jest takich samych znakow 
        }

        if(count == toCheck.size()){
            count = 0;
            std::cout << tmp->value_ << " "; //wypisujemy ten element listy, ktory zawiera w sobie toCheck
        } 
        tmp = tmp -> next_; // przejscie na kolejny element listy
    }
}

//przeciazenie operatora << dla zmiennych typu string

std::ostream& operator<<(std::ostream& stream, const List <std::string>& myList){
    Link <std::string> *tmp = myList.first_; //wskaznik na pierwszy element listy stringow
    while(tmp){ //dopoki nie dotrzemy na koniec listy
        stream << tmp -> value_ << " ";  //wypisujemy pierwszy element
        tmp = tmp -> next_; //przechodzimy do nastepnego elementu
    }
    return stream; //zwracamy strumien zawierajacy wszystkie elementy listy po kolei
}

int main() {

    List <std::string> myList;
    std::string test;

    for(int i = 0; i < 5; i++){
        std::cin >> test;
        myList.add(test);
    }


    std::cout << myList << std::endl;

    std::cin >> test;

    myList.check(test);

    for(int i = 0; i < 2; i++){
        myList.remove();
    }

    std::cout << myList;

}