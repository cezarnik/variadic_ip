#define BOOST_TEST_MODULE test
#include <boost/test/unit_test.hpp>
#include "filter.h"

BOOST_AUTO_TEST_SUITE(test)
	
	BOOST_AUTO_TEST_CASE(split_fun){

		BOOST_CHECK(split("",'/t')==std::vector<std::string>({""}));
		BOOST_CHECK(split("  ",' ')==std::vector<std::string>({"","",""}));
	}

	BOOST_AUTO_TEST(convert_fun){

		BOOST_CHECK(convert("111")==111);
		BOOST_CHECK(convert("0")==0);
		BOOST_CHECK(convert("01")==1);
	}
BOOST_AUTO_TEST_SUITE_END()
