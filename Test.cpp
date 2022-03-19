#include "mat.hpp"
#include<iostream>
#include<string>
#include<stdexcept>
#include "doctest.h"
#include <algorithm>
/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Ariel Zidon
 * 
 * Date: 2021-02
 */
using namespace ariel;

using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
    
	CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));

	CHECK(nospaces(mat(3, 3, '@', '-')) == nospaces("@@@\n"
													 "@-@\n"
													 "@@@"));

	CHECK(nospaces(mat(3, 2, '@', '-')) == nospaces("@@@\n"
													"@@@"));

	CHECK(nospaces(mat(2, 3, '@', '-')) == nospaces("@@\n"
													"@@"
													"@@"));
	
}

TEST_CASE("Bad input") {
    for(int i = 0; i <50 ; i += 2){
        CHECK_THROWS(mat(i, i, '$', '%'));
    }

     for(int i = -50; i <=0; i++){
        CHECK_THROWS(mat(i, i, '$', '%'));
    }

    CHECK_THROWS(mat(10, 5, '$', '%'));
    /* Add more test here */
}





