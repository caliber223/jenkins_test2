#ifndef REPEAT_CHECK_H
#define REPEAT_CHECK_H
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdint>
#include <vector>

class DS_mTime {
public:
    DS_mTime();
    DS_mTime(uint16_t month_new, uint32_t dom_new, uint8_t dow_new, int64_t woy_new, 
             uint8_t wdom_new, uint32_t hour_new, int64_t minute_new);
    virtual ~DS_mTime() {} 

    void SetBit(uint64_t &src, uint8_t index, bool val);
    bool GetBit(int64_t src, uint8_t index);  
    bool CheckValid();
    
    template <typename TypeVal>
        std::vector<TypeVal> GetNumberBits(TypeVal subject, uint8_t firstbit, uint8_t endbit);

    template <typename TypeValue>
        void PrintLineBits(TypeValue subject);
    
    uint64_t BitlineToInt(char* bitline);

    uint16_t GetMonth()  {return month;}
    uint32_t GetDom()    {return dom;}
    uint8_t  GetDow()    {return dow;}
    uint64_t GetWoy()    {return woy;}
    uint8_t  GetWdom()   {return wdom;}
    uint32_t GetHour()   {return hour;}
    uint64_t GetMinute() {return minute;}

private:
    uint16_t month;
    uint32_t dom;
    uint8_t  dow;
    uint64_t woy;
    uint8_t  wdom;
    uint32_t hour;
    uint64_t minute;
};

#endif // REPEAT_CHECK_H

