#include "process.h"
#include <functional>
std::vector<std::string> strings;

int main(){
	std::string s;
	while(getline(std::cin,s)){
        	auto strs=split(s,'\t');
        	strings.push_back(strs[0]);    	
	}
	auto result=process(strings);
	for(auto ip:result)
		print(ip);
}
