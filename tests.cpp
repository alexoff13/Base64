#include <string>
#include "gtest/gtest.h"
#include "libBase64.h"

using namespace std;

TEST(CodeBase64,SimpleTest){
    string line="Man is distinguished, not only by his reason, but by this singular passion from other "
                "animals, which is a lust of the mind, that by a perseverance of delight in the continued"
                " and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.";
    string expectedLine="TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpb"
                        "md1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQs"
                        "IHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0"
                        "aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgY"
                        "W55IGNhcm5hbCBwbGVhc3VyZS4";
    cout<<CodeBase64(line,Base64);
    ASSERT_TRUE(expectedLine==CodeBase64(line,Base64));
}

TEST(DecodeBase64,SimpleTest){
    string line="QmFzZSA2NCBlbmNvZGluZyBzaGFtZXMgYXJlIGNvbW1vbmx5IHVzZWQgd2hlbiB0aGVyZSBpcyBhIG5lZWQgdG8gZW5jb2Rl"
                "IGJpbmFyeSBkYXRhIHRoYXQgbmVlZHMgYmUgc3RvcmVkIGFuZCB0cmFuc2ZlcnJlZCBvdmVyIG1lZGlhIHRoYXQgYXJlIGRlc"
                "2lnbmVkIHRvIGRlYWwgd2l0aCB0ZXh0dWFsIGRhdGEu";
    string expectedLine="Base 64 encoding shames are commonly used when there is a need to encode binary data that "
                        "needs be stored and transferred over media that are designed to deal with textual data.";
    cout<<CodeBase64(line,ASCII);
    ASSERT_TRUE(expectedLine==CodeBase64(line,ASCII));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
