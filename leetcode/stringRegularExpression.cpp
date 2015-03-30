#include <regex>
#include <iostream>
#include <string>

using namespace std;

std::string format_date(const std::string& date){
   // regular expression
   const std:: regex pattern("(\\d{1,2})(\\.|-|/)(\\d{1,2})(\\.|-|/)(\\d{4})");
   // transformation pattern, reverses the position of all capture groups
   std::string replacer = "$5$4$3$2$1";
   // apply the tranformation
   return std:: regex_replace(date, pattern, replacer);
}

string format_string(const std::string& test){
   // regular expression
   const std:: regex pattern("(\\pP|\\pZ|\\pS| |    )");
   // transformation pattern, reverses the position of all capture groups
   std::string replacer = "";
   // apply the tranformation
   return std:: regex_replace(test, pattern, replacer);
}

int main(){
    /*
   std::string date1 = "1/2/2008";
   std::string date2 = "12.08.2008";
   std::cout << date1 << " -> " << format_date(date1) << std::endl;
   std::cout << date2 << " -> " << format_date(date2) << std::endl;
   std::cout << std::endl;
   */
    //c++ 11 new feature, but it doesn't work well on linux
   string test1 = "今日上映：7月25日《我就是我》没人懂！";
   string test2 = "                            这个视频，我发定了。看完我相信你肯定哭的！                       ";
   string test3 = "a b c d          ";
    string test4 = "字";

   string test = test3;
   cout << format_string(test) << endl;

   //change regex to find and replace function of string
    string ctest = test4;

    string::size_type found = ctest.find_first_of(" ");
    while (found != string::npos){
        ctest.replace(found, 1, "");
        found=ctest.find_first_of(" ",found);
    }
    cout << ctest << ctest.size() << endl;

    string str = test4;
    signed char bit;
    int result = 0;
    for (int i=0; i<str.size(); i++){
        bit = str[i];

        if( (i+1) % 3 == 0){
            cout << result << endl;
            result = 0;
        }
        else{
            result = result << 8 | bit;
        }
    }
    cout << str << str.size() << endl;
   return 0;
}
