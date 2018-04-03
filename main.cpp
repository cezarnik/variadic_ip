#include "filter.h"
#include <functional>
std::vector<IP> IPs;

int main(){
    std::string s;
    while(getline(std::cin,s)){
        auto strs=split(s,'\t');
        auto one=split(strs[0],'.');
        auto tup=std::make_tuple(std::stoi(one[0]),std::stoi(one[1]),std::stoi(one[2]),std::stoi(one[3]));
        IPs.push_back(tup);
    }
    std::sort(IPs.begin(),IPs.end(),std::greater<IP>());
    for(auto ip:IPs){
        print(ip);
    }
    for(auto ip:IPs){
        auto good=contains(ip,1);
        if (!good.empty() && good[0]==1){
            print(ip);
        }
    }
    for(auto ip:IPs){
        auto good_46=contains(ip,46);
        auto good_70=contains(ip,70);
	auto it_46=find(good_46.begin(),good_46.end(),1);
        auto it_70=find(good_70.begin(),good_70.end(),2);
        if (it_46!=good_46.end() && it_70!=good_70.end())
            print(ip);
    }
    for(auto ip:IPs){
        auto good=contains(ip,46);
        if (!good.empty())
            print(ip);
    }
}

