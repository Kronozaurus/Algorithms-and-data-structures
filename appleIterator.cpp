#include <iostream>
#include <cassert>

using namespace std;

template <class T> class Link;
template <class T> class Iterator;

// ======================================================================
//                    Class Template List
// ======================================================================
template <class T>
class List {
protected:
    Link <T> *first;

public:
    List() : first(nullptr) {}
    List(const List &source);
    virtual ~List() {};

    virtual void add(T value);
    virtual void deleteAll();
    T firstElement() const;
    virtual bool includes(T value) const;
    bool isEmpty() const;
    virtual void removeFirst();

    friend class Iterator <T>;
};
// ======================================================================
//                    Class Template Link
// ======================================================================
template <class T>
class Link {
private:
    T value;
    Link <T> *next;
   
    Link(T val, Link *ptr) : value(val), next(ptr) { }
public:
    Link <T> *insert(T value);

    friend class List <T>;
    friend class Iterator <T>;
};


// ======================================================================

//                    Class Template Iterator
// ======================================================================
template <class T> class Iterator {
public:
    Iterator(List <T> &aList);
    virtual bool init();
    virtual T operator()();
    virtual bool operator !();
    virtual bool operator++(); // for prefix, for postfix add dummy int
    virtual bool operator++(int);
    virtual void operator=(T value);
    void removeCurrent();
    void addBefore(T new_value);
    void addAfter(T new_value);
 protected:
    List <T> &myList;   // data fields
    Link <T> *previous;
    Link <T> *current;
 };

// ======================================================================
//                    Class Template Link - attributes
// ======================================================================
template <class T> Link <T> * Link <T> :: insert(T value) {
    next = new Link <T>(value, next);
    return next;
}

// ======================================================================
//                    Class Template List - attributes
// ======================================================================
template <class T> void List <T> :: add(T value) {
    first = new Link <T>(value, first);
}

template <class T> T List <T> :: firstElement() const {
    assert(first != nullptr);
    return first->value;
}


template <class T> bool List <T> :: isEmpty() const {
    return first == nullptr;
}


template <class T> bool List <T> :: includes(T value) const {
    for (Link <T> *p = first; p; p = p->next)
        if (value == p->value)return true;
    return false;
}

template <class T> void List <T> :: removeFirst() {
    assert(first != nullptr);
    Link <T> *ptr = first;
    first = ptr->next;
    delete ptr;
}

template <class T> void List <T> :: deleteAll() {
    Link <T> *next;
    for (Link <T> *p = first; p; p = next) {
        next = p->next;
        delete p;
    }
    first = nullptr;
}

// ======================================================================
//                    Class Template Iterator - attributes
// ======================================================================
template <class T> Iterator <T> ::
    Iterator(List <T> &aList) : myList(aList) {
    init();
}
template <class T> bool Iterator <T> :: init() {
    previous = nullptr;
    current = myList.first;
    return current != nullptr;
}
template <class T> T Iterator <T> :: operator()() {
    assert(current != nullptr);
    return current->value;
}
template <class T> void Iterator <T> :: operator=(T val) {
    assert(current != nullptr);
    current->value = val;
}

template <class T> bool Iterator <T> :: operator++() {
    if (current == nullptr){    // move current pointer
        if (previous == nullptr) // to next element
            current = myList.first;
        else
            current = previous->next;
    }
    else {
        previous = current;
        current = current->next;
    }
    return current != nullptr;
} // valid for prefix operator only

template <class T> bool Iterator <T> :: operator++(int){
    return operator++();
}

template <class T> bool Iterator <T> :: operator !() {
    if (current == nullptr and previous != nullptr)
        current = previous->next;
    return current != nullptr;
}

template <class T> void Iterator <T> :: removeCurrent() {
    assert(current != nullptr);
    if (previous == nullptr)
        myList.first = current->next;
    else
        previous->next = current->next;
    delete current;
    current = nullptr;
}

template <class T> void Iterator <T> :: addBefore(T val) {
    if (previous) previous = previous->insert(val);
    else {
        myList.List<T>::add(val);     // to avoid subclass
        previous = myList.first;
        current = previous->next;      // if current is NULL
    }
}

template <class T> void Iterator <T> :: addAfter(T val) {
    if (current){current->insert(val); return;}  // not shown
    if (previous)current = previous->insert(val);
    else myList.List<T>::add(val);
}

// ======================================================================
//                            Apple
// ======================================================================

class Apple {
    public:
        string type_;
        int weight_;
    
        Apple(string type, int weight) : type_(type), weight_(weight) {}
        Apple() = default;
        ~Apple() = default;
        
        void setParameter(string type, int weight) {
            type_ = type;
            weight_ = weight;
        }
        
        bool operator==(Apple toCompare) {
            if(weight_ == toCompare.weight_ && type_ == toCompare.type_)
                return true;
            return false;
        }
};
        
// ======================================================================
//                            main
// ======================================================================

int main() {
    
    string type; int weight;
    
    List<Apple> myList;
    Apple myApple; 
    
    for(int i = 0; i < 4; i++){
        cin >> type >> weight;
        myApple.setParameter(type, weight);
        myList.add(myApple);
    }
    
    Iterator<Apple> it(myList);
    auto currentApple = it();
    std::cout << currentApple.type_ << " " << currentApple.weight_ << " ";
    
    for(it.init(); !it; ++it){
        auto currentApple = it();
        std::cout << currentApple.type_ << " " << currentApple.weight_ << " ";
    }
    
    it.init();
    ++it;
    it++;
    
    std::cin >> type >> weight;
    myApple.setParameter(type, weight);
    myList.add(myApple);
    
    currentApple = it();
    std::cout << currentApple.type_ << " " << currentApple.weight_ << " ";
    
    for(it.init(); !it; ++it){
        auto currentApple = it();
        std::cout << currentApple.type_ << " " << currentApple.weight_ << " ";
    }
    
    return 0;
}
// ======================================================================