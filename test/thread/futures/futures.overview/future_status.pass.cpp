//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <future>

// enum class future_status
// {
//     ready,
//     timeout,
//     deferred
// };

#include <future>

int main()
{
    static_assert(std::future_status::ready == 0, "");
    static_assert(std::future_status::timeout == 1, "");
    static_assert(std::future_status::deferred == 2, "");
}
