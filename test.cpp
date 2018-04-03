#define BOOST_TEST_MODULE filter_test
#include <boost/test/unit_test.hpp>
#include "process.h"

BOOST_AUTO_TEST_SUITE(filter_test)
	
	BOOST_AUTO_TEST_CASE(split_fun){

		BOOST_CHECK(split("",'\t')==std::vector<std::string>({""}));
		BOOST_CHECK(split("  ",' ')==std::vector<std::string>({"","",""}));
	}

	BOOST_AUTO_TEST_CASE(overall_fun){
		std::string input{"121.222.132.213\n"
				  "223.123.46.70\n"
				  "1.1.1.1\n"
				  "46.46.46.46\n"
				  "70.70.70.70\n"};
		std::vector<IP> expected_output{
			std::make_tuple(223,123,46,70),
			std::make_tuple(121,222,231,213),
			std::make_tuple(70,70,70,70),
			std::make_tuple(46,46,46,46),
			std::make_tuple(1,1,1,1),
			std::make_tuple(1,1,1,1),
			std::make_tuple(223,123,46,70),
			std::make_tuple(46,46,46,46)		
		};
		std::vector<IP> result=process(input); 
		BOOST_CHECK(result.size()==expected_output.size());
		int iterator=0;	
		for(auto ip:result){
			BOOST_CHECK(ip==expected_output[iterator]);
			++iterator;
		}
	}
BOOST_AUTO_TEST_SUITE_END()
