#pragma once

#include <atomic>
#include <utility>

struct NullMutex
{
   void load() {}
   void unlock() {}
};

struct null_atomic_int
{
  null_atomic_int() = default;
   explicit null_atomic_int(int new_value) : value{new_value} { }
  
   int load(std::memory_order = std::memory_order_relaxed) const { return value; }
   void store(int val, std::memory_order = std::memory_order_relaxed) { value = val; }

   int exchange(int val, std::memory_order = std::memory_order_relaxed)
    {
       std::swap(val, value);
        return val;
    }
   
   public:
    int value;
};
