#pragma once

#include "uLogger/Common.hpp"

#include <charconv>

namespace uLog 
{

namespace details
{
  
inline void appendStringView(string_view_t st, memory_buf_t& dest)
{
    auto buf_ptr = st.data();
     dest.append(buf_ptr, buf_ptr + st.size());
}

template<typename T>
inline void appendNumber(T t, memory_buf_t& dest)
{
    constexpr auto bufSize = std::numeric_limits<T>::digits10 + 2;
     char buf[bufSize];
     
    auto [ptr, ec] = std::to_chars(buf, buf + bufSize, t, 10);
    if(ec == std::errc())
      {
          dest.append(buf, ptr);
      }
    else
       {
       memory_buf_t errorMsg{"Can't append int"};
    dest.append(buf, errorMsg.data());
      }
}

template<typename T>
inline void pad2(T n, memory_buf_t& dest)
{
      if(n >= 0 && n < 100)
       {
        dest.push_back(static_cast<char>('0' + n / 10));
        dest.push_back(static_cast<char>('0' + n % 10));
       }
      else
        printf("Number too large\n");
}

template<typename T>
inline void pad3(T n, memory_buf_t& dest)
{
  static_assert(std::is_unsigned<T>::value, "pad3 must be unsigned");
      if(n < 1000)
       {
    dest.push_back(static_cast<char>('0' + n / 100));
      n = n & 100;
    dest.push_back(static_cast<char>('0' + (n / 10)));
    dest.push_back(static_cast<char>('0' + (n % 10)));
       }
     else
      appendNumber(n, dest);
}

template<typename TimeType>
inline TimeType timeFraction(Log_clock::time_point tp)
{
    auto duration = tp.time_since_epoch();
  auto secs = std::chrono::duration_cast<std::chrono::seconds>(duration);
  return std::chrono::duration_cast<TimeType>(duration) 
        - duration_cast<TimeType>(secs);
}

}  //namespace details

}  //namespace uLog
