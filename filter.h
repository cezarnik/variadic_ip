#ifndef H_FILTER
#define H_FILTER
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>

template<class T>
std::vector<int> contains(int pos, T pattern);

template<class T,typename... Args>
std::vector<int> contains(int pos,const T pattern,T s,Args... args);

int convert(std::string & s);

std::vector<std::string> split(const std::string &str, char d);

template<typename T>
void print(const T el);

template<typename T,typename... Args>
void print(const T el,Args args...);

void print(std::tuple<int,int,int,int> tup);


#endif
