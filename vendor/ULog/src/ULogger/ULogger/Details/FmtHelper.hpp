#pragma once

#include "uLogger/Common.hpp"

namespace uLog 
{

namespace details
{
  
inline void appendStringView(string_view_t st, memory_buf_t& dest)
{
    auto buf_ptr = st.data();
     dest.append(buf_ptr, buf_ptr + st.size());
}

}  //namespace details

}  //namespace uLog
