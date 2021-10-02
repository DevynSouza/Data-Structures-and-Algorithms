#ifndef ReelNode_hpp
#define ReelNode_hpp

#include <stdio.h>
#include "Item.hpp"

struct ReelNode{
    Item data;
    ReelNode* next;
};

#endif /* ReelNode_hpp */