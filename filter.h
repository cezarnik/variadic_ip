#ifndef H_FILTER 
#define H_FILTER
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>

typedef std::tuple<int,int,int,int> IP;
std::vector<int> contains(IP ip,int element){
	std::vector<int> res;
	std::vector<int> els(4);
	std::tie(els[0],els[1],els[2],els[3])=ip;
	for(int i=0; i<4; ++i){
		if (element==els[i])
			res.push_back(i+1);
	}
	return res;
}

//split the string using delimeter
std::vector<std::string> split(const std::string &str, char d){
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    r.push_back(str.substr(start));
    return r;
}


void print(IP tup){
std::cout<<std::get<0>(tup)<<"."<<std::get<1>(tup)<<"."<<std::get<2>(tup)<<"."<<std::get<3>(tup)<<std::endl;
}
#endif
