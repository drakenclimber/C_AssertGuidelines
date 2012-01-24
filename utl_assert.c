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

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <assert.h>
#include <stdint.h>

/*******************************************************************************
 * Defines
 ******************************************************************************/

/*******************************************************************************
 * Typedefs, Enums, Structs, and Unions
 ******************************************************************************/

/*******************************************************************************
 * Global Variables
 ******************************************************************************/

/*******************************************************************************
 * Local Variables
 ******************************************************************************/

/*******************************************************************************
 * Function Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Functions
 ******************************************************************************/

/*******************************************************************************
 * Function:      UTL_AssertFailed()
 *
 * Description:   Handles a failed assert.
 ******************************************************************************/
void UTL_AssertFailed(
         char const * const fileName,
         uint32_t           lineNumber)
{

   (void)fileName;
   (void)lineNumber;

#if defined(ANDROID)
   __assert(fileName, lineNumber, "");

#else
   _assert(0, fileName, lineNumber);

#endif

   return;

}  /* UTL_AssertFailed() */
