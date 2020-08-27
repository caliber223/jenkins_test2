#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <iomanip>
#include <cstring>
#include "repeat_check.h"


DS_mTime::DS_mTime() {
    month = 0; // 0 ... 11
    dom = 0;   // 1 ... 31
    dow = 0;   // 0 ... 6
    woy = 0;   // 1 ... 53
    wdom = 0;  // 1 ... 5 
    hour = 0;  // 0 ... 23
    minute = 0;// 0 ... 59
}

DS_mTime::DS_mTime(uint16_t month_new, uint32_t dom_new, uint8_t dow_new, int64_t woy_new, 
             uint8_t wdom_new, uint32_t hour_new, int64_t minute_new) {
    month = month_new;  // 0 ... 11
    dom = dom_new;      // 1 ... 31
    dow = dow_new;      // 0 ... 6
    woy = woy_new;      // 1 ... 53
    wdom = wdom_new;    // 1 ... 5 
    hour = hour_new;    // 0 ... 23
    minute = minute_new;// 0 ... 59
}

void DS_mTime::SetBit(uint64_t &src, uint8_t index, bool val){
    if (val)
        src|=(static_cast<uint64_t>(1)<<index);
    else
        src&=~(static_cast<uint64_t>(1)<<index);
}
bool DS_mTime::GetBit(int64_t src, uint8_t index){
    return src&=(static_cast<uint64_t>(1)<<index);
}

template <typename TypeVal>
    std::vector<TypeVal> DS_mTime::GetNumberBits(TypeVal subject, uint8_t firstbit, uint8_t endbit) {
        std::vector<TypeVal> arr;
        size_t n = 0;
        for(size_t i = 0; i < (sizeof(subject) * 8); ++i) {
            if((i < firstbit) && (GetBit(subject, i))) {
                arr.clear();
                return arr;
            }
            if(i <= endbit) {
                if(GetBit(subject, i)) {
                    n++;
                    arr.push_back(i);
                    std::cout<<std::setw(5) << i;
                }
            } else {
                if(GetBit(subject, i)) {
                    arr.clear();
                    return arr;
                }
            }
        }
        std::cout<<"\n";
        return arr;
}

template <typename TypeValue>
    void DS_mTime::PrintLineBits(TypeValue subject) {
        std::cout<<std::setw(3) <<sizeof(subject) <<"  ";
        for(size_t i = 0; i < (sizeof(subject) * 8); ++i) {
            std::cout<<(GetBit(subject, ((sizeof(subject) * 8) - i - 1))) ? 1 : 0;
        }
        std::cout<<"\n";
}

uint64_t DS_mTime::BitlineToInt(char* bitline) {
    uint8_t strsize = strlen(bitline);
    if(strsize > 63) {
        std::cout<<"\nError: invalid input value\n";
        return 0;
    }
    char* bptr = bitline;
    uint64_t result = 0;
    uint64_t tmp = 0;
    uint8_t n = 0;
    
    while(*bptr != '\0') {
        if(*bptr != '0' && *bptr != '1') {
            std::cout<<"\nError: invalid input value\n";
            return false;
        }
        if(*bptr == '1') {
            tmp = 2;
            if(n == 0) {
                tmp = 1;
            } else if(n == 1) {
                tmp = 2;
            } else {
                for(uint8_t i = 2; i <= n; ++i) {
                    tmp *= 2;
                }
            }
        }
        std::cout<<"--- tmp =  " <<tmp <<"\n";
        result += tmp;
        ++bptr;
        ++n;
        tmp = 0;
    }

    return result;
}

bool DS_mTime::CheckValid() {
   
    if(!GetNumberBits(month, 0, 11).size()) return false;
    if(!GetNumberBits(dom, 1, 31).size()) return false;
    if(!GetNumberBits(dow, 0, 6).size()) return false;
    if(!GetNumberBits(woy, 1, 53).size()) return false;
    if(!GetNumberBits(wdom, 1, 5).size()) return false;
    if(!GetNumberBits(hour, 0, 23).size()) return false;
    if(1 != GetNumberBits(minute, 0, 59).size()) return false;

    return true;
}

int main(int argc, char** argv) {
    char s[65] = "10010001";
    DS_mTime t (1543, 1255936, 68, 42, 6, 22, 32768);
    bool tt = t.CheckValid();
    std::cout<< std::endl << tt <<std::endl;
    t.PrintLineBits(t.GetMonth());
    t.PrintLineBits(t.GetDom());
    t.PrintLineBits(t.GetDow());
    t.PrintLineBits(t.GetWoy());
    t.PrintLineBits(t.GetWdom());
    t.PrintLineBits(t.GetHour());
    t.PrintLineBits(t.GetMinute());
    std::cout<<"\nresult: " <<t.BitlineToInt(s) <<"\n";

    std::cin.get();
return 0;
}

