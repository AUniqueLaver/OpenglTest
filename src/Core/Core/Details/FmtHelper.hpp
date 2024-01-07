#pragma once

#include "Core/Common.hpp"

inline void appendStringView(string_view_t st, memory_buf_t& dest)
{
    auto buf_ptr = st.data();
     dest.append(buf_ptr, buf_ptr + st.size());
}
