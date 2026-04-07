#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
using namespace std;
class Item {
    protected:
     string titulo;
     int ano;
    public:
     Item(string t, int a); 
     virtual void exibirInfo(); 

};
#endif