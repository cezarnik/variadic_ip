#define BOOST_TEST_MODULE filter_test
#include <boost/test/unit_test.hpp>
#include "filter.h"

BOOST_AUTO_TEST_SUITE(filter_test)
	
	BOOST_AUTO_TEST_CASE(split_fun){

		BOOST_CHECK(split("",'\t')==std::vector<std::string>({""}));
		BOOST_CHECK(split("  ",' ')==std::vector<std::string>({"","",""}));
	}

	BOOST_AUTO_TEST_CASE(convert_fun){
		std::string s1="111";
		std::string s2="0";
		std::string s1="01";
		BOOST_CHECK(convert(s1)==111);
		BOOST_CHECK(convert(s2)==0);
		BOOST_CHECK(convert(s3)==1);
	}
BOOST_AUTO_TEST_SUITE_END()
