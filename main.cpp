#include "filter.h"
std::vector<std::tuple<int,int,int,int>> IPs;


int main(){
    std::string s;
    while(getline(std::cin,s)){
        auto strs=split(s,'\t');
        auto one=split(strs[0],'.');
        auto tup=std::make_tuple(convert(one[0]),convert(one[1]),convert(one[2]),convert(one[3]));
        IPs.push_back(tup);
    }
    std::sort(IPs.begin(),IPs.end());
    std::reverse(IPs.begin(),IPs.end());
    for(auto it:IPs){
        print(it);
    }
    for(int i=0; i<(int)IPs.size(); ++i){
        auto good=contains(1,1,std::get<0>(IPs[i]));
        if (!good.empty() && good[0]==1){
            print(IPs[i]);
        }
    }
    for(int i=0; i<(int)IPs.size(); ++i){
        auto good_46=contains(1,46,std::get<0>(IPs[i]),std::get<1>(IPs[i]));
        auto good_70=contains(1,70,std::get<0>(IPs[i]),std::get<1>(IPs[i]));
        auto it_46=find(good_46.begin(),good_46.end(),1);
        auto it_70=find(good_70.begin(),good_70.end(),2);
        if (it_46!=good_46.end() && it_70!=good_70.end())
            print(IPs[i]);
    }
    for(int i=0; i<(int)IPs.size(); ++i){
        auto good=contains(1,46,std::get<0>(IPs[i]),std::get<1>(IPs[i]),std::get<2>(IPs[i]),std::get<3>(IPs[i]));
        if (!good.empty())
            print(IPs[i]);
    }
}

