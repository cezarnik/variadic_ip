#ifndef H_FILTER 
#define H_FILTER
template<class T>
std::vector<int> contains(int pos,T pattern){
    	std::vector<int> res=std::vector<int>();
	return res;
}

//return vector of positions of matches
template<class T,typename... Args>
std::vector<int> contains(int pos,T pattern,T s,Args... args){
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
#endif
