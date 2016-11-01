//
//  boyerMoore.h
//  boyerMoore
//
//  Created by Wang Yi on 30/10/16.
//  Copyright (c) 2016 Wang Yi. All rights reserved.
//

#ifndef __boyerMoore__boyerMoore__
#define __boyerMoore__boyerMoore__

// https://isocpp.org/wiki/faq/mixing-c-and-cpp
#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
size_t boyer_moore(const char* txt, size_t l, const char* pttn, size_t pttn_len);

#ifdef __cplusplus
}
#endif

#endif /* defined(__boyerMoore__boyerMoore__) */
