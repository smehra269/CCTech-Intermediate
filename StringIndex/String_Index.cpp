#include<iostream>
#include <string>
#include<algorithm>
#include<cassert>


using namespace std;


string eliminate_Slash(string const& file_path, string const& d_slash = "/\\")
{
    size_t slash_index = file_path.find_last_of(d_slash);
    string file_name = file_path.substr(slash_index + 1);
    return file_name;
}


string eliminate_extension(string const& file_name)
{
    size_t position = file_name.find_last_of('.');
    string file_without_extension = file_name.substr(0, position);
    return file_without_extension;
}


string eliminate_separator(string file_name)
{
    char chars[] = {'_','-','.'};
    for(char ch:chars)
    {
    auto t = remove(file_name.begin(),file_name.end(),ch);
    file_name.erase(t,file_name.end());
    }
    return file_name;
}


string eliminate_word(string file_name)
{
    string words[] = {"tests","test","Tests","Test","spec","Spec","steps","step"};
    for(string w : words)
    {
        size_t pos = file_name.find(w,0);
        if(pos != string::npos)
            file_name.erase(pos,w.length());
    }
    return file_name;
}


string getIndex(const string& file_path, const string& file_name)
{
    int array_index[2];
    size_t pos = file_path.find(file_name,0);
    array_index[0]=pos;
    array_index[1]=pos+file_name.length();
    return to_string(array_index[0]) + " " + to_string(array_index[1]);
}


string fileName(string file_Path)
{
    string file_address = eliminate_word(eliminate_separator(eliminate_extension(eliminate_Slash(file_Path))));
    return getIndex(file_Path,file_address);
}


void test_case()
{
 assert(fileName("src/Hiker_spec.re")=="4 9");
    assert(fileName("test/hiker_test.exs")=="5 10");
    assert(fileName("wibble/test/hiker_spec.rb")=="12 17");
    assert(fileName("hiker_steps.rb")=="0 5");
    assert(fileName("hiker_spec.rb")=="0 5");
    assert(fileName("test_hiker.rb")=="5 10");
    assert(fileName("test_hiker.py")=="5 10");
    assert(fileName("test_hiker.sh")=="5 10");
    assert(fileName("tests_hiker.sh")=="6 11");
    assert(fileName("test_hiker.coffee")=="5 10");
    assert(fileName("hiker_spec.coffee")=="0 5");
    assert(fileName("hikerTest.chpl")=="0 5");
    assert(fileName("hiker.tests.c")=="0 5");
    assert(fileName("hiker_tests.c")=="0 5");
    assert(fileName("hiker_test.c")=="0 5");
    assert(fileName("hiker_Test.c")=="0 5");
    assert(fileName("HikerTests.cpp")=="0 5");
    assert(fileName("hikerTests.cpp")=="0 5");
    assert(fileName("HikerTest.cs")=="0 5");
    assert(fileName("HikerTest.java")=="0 5");
    assert(fileName("DiamondTest.kt")=="0 7");
    assert(fileName("HikerTest.php")=="0 5");
    assert(fileName("hikerTest.js")=="0 5");
    assert(fileName("hiker-test.js")=="0 5");
    assert(fileName("hiker-spec.js")=="0 5");
    assert(fileName("hiker.test.js")=="0 5");
    assert(fileName("hiker.tests.ts")=="0 5");
    assert(fileName("hiker_tests.erl")=="0 5");
    assert(fileName("hiker_test.clj")=="0 5");
    assert(fileName("fizzBuzz_test.d")=="0 8");
    assert(fileName("hiker_test.go")=="0 5");
    assert(fileName("hiker.tests.R")=="0 5");
    assert(fileName("hikertests.swift")=="0 5");
    assert(fileName("HikerSpec.groovy")=="0 5");    
    assert(fileName("hikerSpec.feature")=="0 5");
    assert(fileName("hiker.feature")=="0 5");
    assert(fileName("hiker.fun")=="0 5");
    assert(fileName("hiker.t")=="0 5");
    assert(fileName("hiker.plt")=="0 5");
    assert(fileName("hiker")=="0 5");
    cout << "Test Cases Passed" << endl;
}
 
int main() {
    test_case();
    return 0;
}
 