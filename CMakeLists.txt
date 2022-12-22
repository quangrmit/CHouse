cmake_minimum_required(VERSION 3.2)
project(CHouse)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CHouse
        Test/draft.cpp
        Admin.cpp
        Admin.h
        Authorization.cpp
        Authorization.h
        CLI.cpp
        CLI.h
        Database.cpp
        Database.h
        Date.cpp
        Date.h
        Guest.cpp
        Guest.h
        House.cpp
        House.h
        HouseDatabase.cpp
        HouseDatabase.h
        main.cpp
        Member.cpp
        Member.h
        MemberDatabase.cpp
        MemberDatabase.h
        Request.cpp
        Request.h
        RequestDatabase.cpp
        RequestDatabase.h
        utils.cpp
        utils.h)
