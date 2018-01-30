//////////////////////////////////////////////////////////////////////////////////////////
//  Project Euler #19: Counting Sundays                                                 //
//                                                                                      //
//  Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler019/problem  //
//  Difficulty: Easy                                                                    //
//  Language: C++14                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include <tuple>

using Date = std::tuple<long, int, int>;

bool operator< (const Date& lhs, const Date& rhs){
    return (std::get<0>(lhs) < std::get<0>(rhs))?true:(
           (std::get<0>(rhs) < std::get<0>(lhs))?false:(
               (std::get<1>(lhs) < std::get<1>(rhs))?true:(
               (std::get<1>(rhs) < std::get<1>(lhs))?false:(
                   (std::get<2>(lhs) < std::get<2>(rhs))?true:false
            ))));
}

bool operator== (const Date& lhs, const Date& rhs){
    return std::get<0>(lhs) == std::get<0>(rhs) &&
           std::get<1>(lhs) == std::get<1>(rhs) &&
           std::get<2>(lhs) == std::get<2>(rhs);
}

bool operator<= (const Date& lhs, const Date& rhs){
    return lhs<rhs || lhs==rhs;
}

bool is_leap_year(unsigned long y){
    return y%4==0 && (y%400==0 || y%100!=0);
}

int get_day_by_date(const Date& d){
    std::tm time_in = { 0, 0, 0, std::get<2>(d), std::get<1>(d)-1, static_cast<int>(std::get<0>(d)-1900)};
    std::time_t time_temp = std::mktime( & time_in );
    std::tm const *time_out = std::localtime( & time_temp );

    return time_out->tm_wday;
}

void advance_to_next_month(Date& d){
    if (std::get<1>(d)==12){
        ++std::get<0>(d);
        std::get<1>(d) = 1;
    }
    else
        ++std::get<1>(d);
}

int main() {
    int T, sundays, diff; std::cin >> T;
    Date starting, ending;

    for (int i=0; i<T; ++i){
        std::cin >> std::get<0>(starting) >> std::get<1>(starting) >> std::get<2>(starting);
        std::cin >> std::get<0>(ending) >> std::get<1>(ending) >> std::get<2>(ending);

        diff = std::get<0>(ending) - std::get<0>(starting);
        std::get<0>(starting) = 1900 + (std::get<0>(starting)-1900)%400;
        std::get<0>(ending) = std::get<0>(starting) + diff;

        if (std::get<2>(starting)==1){
            if (get_day_by_date(starting) == 0)
                sundays = 1;
            else
                sundays = 0;
        }
        else{
            std::get<2>(starting) = 1;
            advance_to_next_month(starting);

            if (starting <= ending)
                if (get_day_by_date(starting) == 0)
                    sundays = 1;
            else
                sundays = 0;
        }

        advance_to_next_month(starting);

        while (starting <= ending){
            if (get_day_by_date(starting) == 0)
                ++sundays;

            advance_to_next_month(starting);
        }

        std::cout << sundays << std::endl;
    }
}
