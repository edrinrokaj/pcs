#pragma once

#include <string>

struct Component {
    std::string name;
    double value;
    char type;            
    int positive_node;    
    int negative_node;    
};
