//
//  Order.hpp
//  Ques1
//
//  Created by Akshit Sharma on 03/05/21.
//

#ifndef Order_hpp
#define Order_hpp

#include <iostream>
#include <fstream>


/*
 Order
 intelligence system of minimizing cost of manufacturing plant
 
 @feilds
 daily = list of daily requirement of nitrogen gas in litres
 numDays = number of days after which the factory is closed
 
 G = maximum storage capacity
 p = storage cost per liter of a day
 S = delivery charge per order
 
 observed  = list of preorders
 
 Order(std::string fileName)
 // defined constructor
 @params
 fileName - file that consists of list of daily requirement of nitrogen gas in litres
 
 process() - calculates the list of preorders
 present() - display function for user
 
 */

class Order {
    
    
private:
    
    int *daily = nullptr;
    int numDays = 0;
    
    int G = 0;
    int p = 0;
    int S = 0;
    
    int *observed = nullptr;
    
public:
    
    Order(std::string fileName);
    
    
    void process();
    void present();
};



#endif /* Order_hpp */
