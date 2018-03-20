#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>

template<class T>
std::vector<int> contains(int pos,T pattern){
    return std::vector<int>();
}

//return vector of positions of matches
template<class T,typename... Args>
std::vector<int> contains(int pos,const T pattern,T s,Args... args){
    std::vector<int> res=contains(pos+1,pattern,args...);
    if (s==pattern){
        res.push_back(pos);
    }
    return res;
}

//convert string to int
int convert(std::string & s){
    int res=0;
    for(int i=0; i<(int)s.size(); ++i){
        res=res*10+s[i]-'0';
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


template<typename T>
void print(const T el){
    std::cout<<el<<std::endl;
}

template<typename T,typename... Args>
void print(const T el,Args... args){
    std::cout<<el<<".";
    print(args...);
}
void print(std::tuple<int,int,int,int> tup){
    print(std::get<0>(tup),std::get<1>(tup),std::get<2>(tup),std::get<3>(tup));
}
std::vector<std::tuple<int,int,int,int>> IPs;

int main(){
    std::string s;
    #ifdef __kolya
        freopen("input.txt","r",stdin);
    #endif
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

