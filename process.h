#ifndef H_PROCESS
#define H_PROCESS
#include <functional>
#include "filter.h"
std::vector<IP> process(std::vector<std::string>& input){
    std::vector<IP> IPs;
    for(auto to:input){
	auto one=split(to,'.');
	int size=(int)one.size();
       	if (size!=4)
		continue;
	auto tup=std::make_tuple(std::stoi(one[0]),std::stoi(one[1]),std::stoi(one[2]),std::stoi(one[3]));
	IPs.push_back(tup);
    }

    std::vector<IP> result;
    std::sort(IPs.begin(),IPs.end(),std::greater<IP>());
    for(auto ip:IPs){
    	result.push_back(ip);    
    }
    for(auto ip:IPs){
        auto good=contains(ip,1);
        if (!good.empty() && good[0]==1){
            result.push_back(ip);
        }
    }
    for(auto ip:IPs){
        auto good_46=contains(ip,46);
        auto good_70=contains(ip,70);
	auto it_46=find(good_46.begin(),good_46.end(),1);
        auto it_70=find(good_70.begin(),good_70.end(),2);
        if (it_46!=good_46.end() && it_70!=good_70.end())
            result.push_back(ip);
    }
    for(auto ip:IPs){
        auto good=contains(ip,46);
        if (!good.empty())
            result.push_back(ip);
    }
    return result;
}
#endif
