#include <string>
#include <iostream>
using namespace std;
#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

using std::string;



TEST_CASE("Test replacement of p and b") {   //10 tests
    string text = "boris is happy , he got the puppy he wanted so much";
            CHECK(find(text, "happy") == string("happy"));
            CHECK(find(text, "habby") == string("happy"));
            CHECK(find(text, "hapby") == string("happy"));
            CHECK(find(text, "habpy") == string("happy"));
            CHECK(find(text, "HABBY") == string("happy"));
            CHECK(find(text, "HAPPY") == string("happy"));
            CHECK(find(text, "poris") == string("boris"));
            CHECK(find(text, "bubpy") == string("puppy"));
            CHECK(find(text, "buBBy") == string("puppy"));
            //CHECK(find(text, "bupp") == string("puppy")); //need to throw an error
}

TEST_CASE("Test replacement of i and y") {    //13 tests
    string text = "Happi xxx yyy";
            CHECK(find(text, "happi") == string("Happi"));
            CHECK(find(text, "Happi") == string("Happi"));
            CHECK(find(text, "HAPPI") == string("Happi"));
            CHECK(find(text, "HaPpI") == string("Happi"));
            CHECK(find(text, "iii") == string("yyy"));
            CHECK(find(text, "iyy") == string("yyy"));
            CHECK(find(text, "yiy") == string("yyy"));
            CHECK(find(text, "III") == string("yyy"));
            CHECK(find(text, "Iyi") == string("yyy"));
            CHECK(find(text, "yIY") == string("yyy"));
            CHECK(find(text, "Yyi") == string("yyy"));
            CHECK(find(text, "IyI") == string("yyy"));
            CHECK(find(text, "IIy") == string("yyy"));
}

TEST_CASE("Test replacement of i and y") {   //11 tests
    string text = "always smile and be happy";
            CHECK(find(text, "smyle") == string("smile"));
            CHECK(find(text, "SMILE") == string("smile"));
            CHECK(find(text, "happy") == string("happy"));
            CHECK(find(text, "happi") == string("happy"));
            CHECK(find(text, "happy") == string("happy"));
            CHECK(find(text, "habpi") == string("happy"));
            CHECK(find(text, "smYle") == string("smile"));
            CHECK(find(text, "alwais") == string("always"));
            CHECK(find(text, "ALWAiS") == string("always"));
            CHECK(find(text, "habPi") == string("happy"));
}

TEST_CASE("Test replacement of c and k and q") {   //9 tests
    string text = "i love cooking";
            CHECK(find(text, "COOKING") == string("cooking"));
            CHECK(find(text, "kooking") == string("cooking"));
            CHECK(find(text, "Koocing") == string("cooking"));
            CHECK(find(text, "cooking") == string("cooking"));
           // CHECK(find(text, "cook") == string("KooKing"));     //need to throw error
            CHECK(find(text, "qooking") == string("cooking"));
            CHECK(find(text, "QooKing") == string("cooking"));
            CHECK(find(text, "kooqing") == string("cooking"));
            CHECK(find(text, "kooking") == string("cooking"));
}

TEST_CASE("Test replacement of g and j and c and k") {   //15 tests
    string text = "in google you may find jokes and juggling";
            CHECK(find(text, "google") == string("google"));
            CHECK(find(text, "Gokes") == string("jokes"));
            CHECK(find(text, "joogle") == string("google"));
            CHECK(find(text, "joces") == string("jokes"));
            CHECK(find(text, "joojle") == string("google"));
            CHECK(find(text, "GOOGLE") == string("google"));
            CHECK(find(text, "JOCes") == string("jokes"));

            CHECK(find(text, "juggling") == string("juggling"));
            CHECK(find(text, "guggling") == string("juggling"));
            CHECK(find(text, "jujjling") == string("juggling"));
            CHECK(find(text, "jugglinj") == string("juggling"));
            CHECK(find(text, "gujjling") == string("juggling"));
            CHECK(find(text, "JUGGLING") == string("juggling"));
            CHECK(find(text, "GUJJLING") == string("juggling"));
            CHECK(find(text, "GugglinJ") == string("juggling"));

}

TEST_CASE("Test replacement of d and t") {   //18 tests
    string text = "dont worry be happy and dance like no one waching dir tim";
            CHECK(find(text, "dond") == string("dont"));
            CHECK(find(text, "tont") == string("dont"));
            CHECK(find(text, "TONT") == string("dont"));
            CHECK(find(text, "DONT") == string("dont"));
            CHECK(find(text, "be") == string("be"));
            CHECK(find(text, "ant") == string("and"));
            CHECK(find(text, "TANCE") == string("dance"));
            CHECK(find(text, "Tance") == string("dance"));
            CHECK(find(text, "ANT") == string("and"));
            //CHECK(find(text, "B") == string("be")); //need to throw an error
            CHECK(find(text, "tir") == string("dir"));
            CHECK(find(text, "DIR") == string("dir"));
            CHECK(find(text, "Tir") == string("dir"));
            CHECK(find(text, "dir") == string("dir"));
            CHECK(find(text, "dim") == string("tim"));
            CHECK(find(text, "TIM") == string("tim"));
            CHECK(find(text, "DIM") == string("tim"));
            CHECK(find(text, "dIM") == string("tim"));


}

TEST_CASE("Test replacement of w and v") {   //8 tests
    string text = "the view from outside my window was amazing.i saw it was windy , but still very nice";
            CHECK(find(text, "windY") == string("windy"));
            CHECK(find(text, "Wiew") == string("view"));
            CHECK(find(text, "WindoV") == string("window"));
            CHECK(find(text, "VINDOv") == string("window"));
            CHECK(find(text, "viNdy") == string("windy"));
            CHECK(find(text, "wery") == string("very"));
            CHECK(find(text, "WIEV") == string("view"));
            CHECK(find(text, "wiev") == string("view"));


}

TEST_CASE("Test replacement of u and o") {   //6 tests
    string text = "my name is luci and i love to dance and luve to eat oou";
            CHECK(find(text, "LUve") == string("love"));
            CHECK(find(text, "loci") == string("luci"));
            CHECK(find(text, "luve") == string("love"));
            CHECK(find(text, "uuu") == string("oou"));
            CHECK(find(text, "OoU") == string("oou"));
            CHECK(find(text, "lucia") == string("luci")); // should print an error !
}

TEST_CASE("Test replacement of s and z") {   //19 tests
    string text = "Suzi likes to see Zebras in the zoo";
            CHECK(find(text, "SUZI") == string("Suzi"));
            CHECK(find(text, "zuzi") == string("Suzi"));
            CHECK(find(text, "ZUZI") == string("Suzi"));
            CHECK(find(text, "SUZI") == string("Suzi"));
            CHECK(find(text, "zusi") == string("Suzi"));
            CHECK(find(text, "soo") == string("zoo"));
            CHECK(find(text, "Zoo") == string("zoo"));
            CHECK(find(text, "SOO") == string("zoo"));
            CHECK(find(text, "zoo") == string("zoo"));
            CHECK(find(text, "zee") == string("see"));
            CHECK(find(text, "see") == string("see"));
            CHECK(find(text, "ZEE") == string("see"));
            CHECK(find(text, "ZEBRAS") == string("Zebras"));
            CHECK(find(text, "sebraz") == string("Zebras"));
            CHECK(find(text, "SEBRAS") == string("Zebras"));
            CHECK(find(text, "ZEBRAZ") == string("Zebras"));
            CHECK(find(text, "sebras") == string("Zebras"));
            CHECK(find(text, "zebras") == string("Zebras"));

}