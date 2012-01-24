/*******************************************************************************
 *
 * Copyright 2012 Drakenclimber, LLC.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/
/**
 * Doxygen comment block
 * @file
 *
 * @brief   Assert interface
 *
 * @note    run-time asserts are disabled in release builds
 */
#ifndef UTL_ASSERT_IF_H
#define UTL_ASSERT_IF_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>

/*******************************************************************************
 * Defines
 ******************************************************************************/

/* macro trickery to make compile-time asserts report the file and line number
 * that caused the assert to trip.  DO NOT INVOKE THESE!
 */ 
#define __UTL_CompilerAssert(_condition, _line)                                \
            typedef int CompilerAssertOnLine##_line[1 - 2 * !(_condition)]
#define _UTL_CompilerAssert(_condition, _line)                                 \
            __UTL_CompilerAssert(_condition, _line)


/* Compile-Time Asserts */
#define UTL_CompilerAssert(_condition)                                         \
            _UTL_CompilerAssert(_condition, __LINE__)
#define UTL_CompilerAssertAlways()           UTL_CompilerAssert(0)


/* Run-Time Asserts */
#if defined(ENABLE_ASSERTS)
   #define UTL_Assert(_condition)                                              \
      if(!(_condition))                                                        \
      {                                                                        \
         UTL_AssertFailed(__FILE__, __LINE__);                                 \
      }

   #define UTL_AssertAlways()          UTL_AssertFailed(__FILE__, __LINE__)

#else
   /* asserts are not defined */
   #define UTL_Assert(_condition)
   #define UTL_AssertAlways()

#endif /* #if defined(ENABLE_ASSERTS) */

/*******************************************************************************
 * Typedefs, Enums, Structs, and Unions
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*******************************************************************************
 * Function Prototypes
 ******************************************************************************/

/**
 * Handles a failed assert
 *
 * @param[in]  fileName    name of the file where the assert occurred
 * @param[in]  lineNumber  line number of the offending assert
 */
void UTL_AssertFailed(
         char const * const fileName,
         uint32_t           lineNumber);

#endif /* #ifndef UTL_ASSERT_IF_H */
