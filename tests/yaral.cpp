#include <iostream>
#include <iomanip>

using namespace std;

class Date{
        public:
        friend ostream &operator<<(ostream &,const Date&);
        friend istream &operator>>(istream &,Date&);
        string hr,min,sec,ap;
    };

    ostream &operator<<( ostream &output, const Date &date){
        output <<date.hr<<":"<<date.min<<":"<<date.sec;
        return output;
        }
    istream &operator>>(istream &input,Date &date){
        input>>setw(2)>>date.hr;
        input.ignore(1);
        input>>setw(2)>>date.min;
        input.ignore(1);
        input>>setw(2)>>date.sec;
        input>>setw(2)>>date.ap;
        return input;
    }

void timeConversion(string s) {

    Date inputdate;
    cin>>inputdate;
    if(inputdate.ap=="AM")
    cout<<inputdate;
    else {
    stringstream temp(inputdate.hr);
    int hour=0;
    temp>>hour;
    hour+=12;
    inputdate.hr=to_string(hour);
    cout<<inputdate;
    }
}

int main()
{
    string x;
    timeConversion(x);
}
