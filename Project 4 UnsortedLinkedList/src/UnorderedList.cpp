//
//  UList.cpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2020 Eugene Lymar. All rights reserved.
//

#include "UnorderedList.hpp"


std::ostream& operator<<(std::ostream& os, UnorderedList& o){
	o.ResetList();
    os << "List: [";
	for(int i = 0; i < o.GetLength(); ++i){
		os << "(" << o.GetNextItem() << ")";
		if (i < o.GetLength() - 1) os << ", ";
	}
	os << "]";
	return os;
}
