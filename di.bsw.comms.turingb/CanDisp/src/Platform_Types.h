
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/** \brief AUTOSAR Platforms types header
 **
 ** This file contains platform specific declarations for the
 ** platform Spansion microcontroller.
 **
 ** Do not edit this file manually.
 ** Any change might compromise the safety integrity level of
 ** the software partition it is contained in.
 **
 ** Product: SW-MCAL40-DRV
 **
 ** (c) Copyright Spansion LLC, All Rights Reserved 2014-2015
 **
 ** ALL RIGHTS RESERVED. No part of this publication may be copied and provided
 ** to any third party in any form or by any means, unless expressly agreed to
 ** in written form by Spansion. All trademarks used in this document are the
 ** property of their respective owners.
 **
 ** For further provisions please refer to the respective License Agreement.
*/


/*==================[inclusions]=============================================*/
#include <Platform_Types_Common.h> /* include common autosar header */

/*==================[macros]=================================================*/

/*------------------[type identifiers]-------------------------------*/

#if (!defined CPU_TYPE) /* guard to prevent double definition */
#define CPU_TYPE CPU_TYPE_32 /** \brief 32-bit registers */
#endif /* if (defined CPU_TYPE) */

#if (defined CPU_BIT_ORDER) /* guard to prevent double definition */
#error CPU_BIT_ORDER already defined
#endif /* if (defined CPU_BIT_ORDER) */

#define CPU_BIT_ORDER LSB_FIRST /** \brief LSB bit order */

#if (defined CPU_BYTE_ORDER) /* guard to prevent double definition */
#error CPU_BYTE_ORDER already defined
#endif /* if (defined CPU_BYTE_ORDER) */

#define CPU_BYTE_ORDER LOW_BYTE_FIRST /** \brief low byte order */

/*==================[type definitions]=======================================*/

                                       
typedef unsigned char boolean;         /** \brief Autosar boolean type */

typedef signed char sint8;             /** \brief 8-bit signed integer */
typedef unsigned char uint8;           /** \brief 8-bit unsigned integer */
typedef signed short sint16;           /** \brief 16-bit signed integer */
typedef unsigned short uint16;         /** \brief 16-bit unsigned integer */
typedef signed long sint32;            /** \brief 32-bit signed integer */
typedef unsigned long uint32;          /** \brief 32-bit unsigned integer */
typedef signed long long sint64;       /** \brief 64-bit signed integer */ /* MISRA-1 */ /* PRQA S 1027 */ /* 64bit is supported by the long long in ARM. */
typedef unsigned long long uint64;     /** \brief 64-bit unsigned integer */ /* MISRA-1 */ /* PRQA S 1027 */ /* 64bit is supported by the long long in ARM. */

typedef unsigned char uint8_least;     /** \brief fast 8-bit unsigned integer */
typedef unsigned short uint16_least;   /** \brief fast 16-bit unsigned integer */
typedef unsigned long uint32_least;    /** \brief fast 32-bit unsigned integer */
                                       
typedef signed char sint8_least;       /** \brief fast 8-bit signed integer */
typedef signed short sint16_least;     /** \brief fast 16-bit signed integer */
typedef signed long sint32_least;      /** \brief fast 32-bit signed integer */

typedef float float32;                 /** \brief 32-bit single-precision floating number */
typedef double float64;                /** \brief 64-bit double-precision floating number */

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

/****************************HISTORY*****************************************/
/****************************************************************************
Date              : 11/21/2016
By                : cmurali1
Change Description: Migrated to BAIC requirements
*****************************************************************************/

#endif /* ifndef PLATFORM_TYPES_H */
