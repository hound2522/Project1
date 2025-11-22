/*
   ========================================
   hash_fn.hpp ¡X declare your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation

   Developer: li yun <oomayoo2522@gmail.com>
 */
#ifndef HASH_FN_H
#define HASH_FN_H

#include <string>

    int myHashString(const std::string& str, int m);
int myHashInt(int key, int m);

#endif
