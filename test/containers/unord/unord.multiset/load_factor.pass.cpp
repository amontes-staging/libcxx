//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <unordered_set>

// template <class Value, class Hash = hash<Value>, class Pred = equal_to<Value>,
//           class Alloc = allocator<Value>>
// class unordered_multiset

// float load_factor() const

#include <unordered_set>
#include <cassert>

int main()
{
    {
        typedef std::unordered_multiset<int> C;
        typedef int P;
        P a[] =
        {
            P(10),
            P(20),
            P(30),
            P(40),
            P(50),
            P(60),
            P(70),
            P(80)
        };
        const C c(std::begin(a), std::end(a));
        assert(c.load_factor() == (float)c.size() / c.bucket_count());
    }
    {
        typedef std::unordered_multiset<int> C;
        typedef int P;
        const C c;
        assert(c.load_factor() == 0);
    }
}
