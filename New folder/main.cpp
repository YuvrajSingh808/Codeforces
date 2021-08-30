//
//  main.cpp
//  Ques1
//
//  Created by Akshit Sharma on 03/05/21.
//

#include <iostream>
#include "Order.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    Order test("order.txt");
    test.process();
    test.present();
    
    std::cout << std::endl;
    return 0;
}
