#include <iostream>

class List;

class Link {
    public:
        Link(double, Link* = nullptr);
        friend class List;

    private:
        Link* next_;
        double val_;
};

Link :: Link(double val, Link* next) : val_(val), next_(next) {

}

class List {
    public:
        List(Link* = nullptr);

        void disp();
        void add(double);
        void remove(double);

    private:
        Link* first_;
};

List :: List(Link* first) : first_(first) {

}

void List :: disp () {
    Link* tmp = first_;
    while(tmp) {
        std::cout << tmp->val_ << " ";
        tmp = tmp->next_;
    }
    std::cout << std::endl;
    delete tmp;
}

void List :: add (double toAdd) {

    Link* tmp = first_;

    if(first_ == nullptr or toAdd > first_->val_) {

        first_ = new Link(toAdd, first_);

    }

    else {

        while(tmp->next_ != nullptr and toAdd < tmp->next_->val_) {
            tmp = tmp->next_;
        }
        
        tmp->next_ = new Link(toAdd, tmp->next_);
   }

}

void List :: remove (double toRemove) {

    Link* tmp = first_;

    if(tmp->val_ == toRemove){
        if(first_->next_ == nullptr) {
            //tylko jeden element na liscie
            first_ = nullptr;

        }
        else {
            first_ = first_->next_;
        }
    }

    else {
        while(tmp->next_) {
            if(tmp->next_->val_ == toRemove ) {
                tmp->next_ = tmp->next_->next_;
                break;
            }
            tmp = tmp->next_;
        }
    }
    //delete tmp;//?? nie wiem czy dziala
}

int main() {
    List MyList;
    int M;
    double val;

    std::cin >> M;

    for(int i = 0; i < M; i++) {
        std::cin >> val;
        MyList.add(val);
    }
    MyList.disp();

    std::cin >> val;
    
    MyList.remove(val);

    MyList.disp();
    return 0;
}