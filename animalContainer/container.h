#include <iostream>
#include <vector>


template <class Type> class Container{
    public:
        Container() { elementsCount_ = 0; };
        ~Container() = default;
        void addElement(Type);
        void removeElement(int);
        std::vector<Type> getElements();
        
    private:
        std::vector<Type> elements_;
        int elementsCount_;
};

template <class Type> void Container <Type> :: addElement (Type toAdd) {
    if(elements_.size() < 6){
        //elements_.insert(elements_.begin(), toAdd); //niby od najmniejszego a jednak nie
        elements_.emplace_back(toAdd);
        elementsCount_++; 
    }
}

template <class Type> void Container <Type> :: removeElement (int position) {
    if(position >= 0 and position < elements_.size()){
        elements_.erase(elements_.begin() + (position));
        elementsCount_--;
    }
}

template <class Type> std::vector<Type> Container <Type> :: getElements(){
    return elements_;
}