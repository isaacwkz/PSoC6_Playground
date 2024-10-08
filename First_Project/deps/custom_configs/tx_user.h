/***************************************************************************
 * Copyright (c) 2024 Microsoft Corporation
 *
 * This program and the accompanying materials are made available under the
 * terms of the MIT License which is available at
 * https://opensource.org/licenses/MIT.
 *
 * SPDX-License-Identifier: MIT
 **************************************************************************/

/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** ThreadX Component                                                     */
/**                                                                       */
/**   User Specific                                                       */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

/**************************************************************************/
/*                                                                        */
/*  PORT SPECIFIC C INFORMATION                            RELEASE        */
/*                                                                        */
/*    tx_user.h                                           PORTABLE C      */
/*                                                           6.3.0        */
/*                                                                        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    William E. Lamie, Microsoft Corporation                             */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This file contains user defines for configuring ThreadX in specific */
/*    ways. This file will have an effect only if the application and     */
/*    ThreadX library are built with TX_INCLUDE_USER_DEFINE_FILE defined. */
/*    Note that all the defines in this file may also be made on the      */
/*    command line when building ThreadX library and application objects. */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  05-19-2020      William E. Lamie        Initial Version 6.0           */
/*  09-30-2020      Yuxin Zhou              Modified comment(s),          */
/*                                            resulting in version 6.1    */
/*  03-02-2021      Scott Larson            Modified comment(s),          */
/*                                            added option to remove      */
/*                                            FileX pointer,              */
/*                                            resulting in version 6.1.5  */
/*  06-02-2021      Scott Larson            Added options for multiple    */
/*                                            block pool search & delay,  */
/*                                            resulting in version 6.1.7  */
/*  10-15-2021      Yuxin Zhou              Modified comment(s), added    */
/*                                            user-configurable symbol    */
/*                                            TX_TIMER_TICKS_PER_SECOND   */
/*                                            resulting in version 6.1.9  */
/*  04-25-2022      Wenhui Xie              Modified comment(s),          */
/*                                            optimized the definition of */
/*                                            TX_TIMER_TICKS_PER_SECOND,  */
/*                                            resulting in version 6.1.11 */
/*  10-31-2023      Xiuwen Cai              Modified comment(s),          */
/*                                            added option for random     */
/*                                            number stack filling,       */
/*                                            resulting in version 6.3.0  */
/*                                                                        */
/**************************************************************************/

#ifndef TX_USER_H
#define TX_USER_H

#define TX_TIMER_TICKS_PER_SECOND (1000UL)
#define TX_MAX_PRIORITIES         32
#define TX_MINIMUM_STACK          128
// #define TX_DISABLE_PREEMPTION_THRESHOLD
// #define TX_DISABLE_REDUNDANT_CLEARING
// #define TX_DISABLE_NOTIFY_CALLBACKS
// #define TX_NOT_INTERRUPTABLE
// #define TX_TIMER_PROCESS_IN_ISR
#define TX_REACTIVATE_INLINE
#define TX_DISABLE_STACK_FILLING
#define TX_ENABLE_STACK_CHECKING
#define TX_INLINE_THREAD_RESUME_SUSPEND

// #define __NVIC_PRIO_BITS 3
// #define TX_PORT_USE_BASEPRI
// #define TX_PORT_BASEPRI (14 << (8 - __NVIC_PRIO_BITS))
// #define TX_PORT_USE_BASEPRI

/* Determine whether or not stack checking is enabled. By default, ThreadX stack checking is
   disabled. When the following is defined, ThreadX thread stack checking is enabled.  If stack
   checking is enabled (TX_ENABLE_STACK_CHECKING is defined), the TX_DISABLE_STACK_FILLING
   define is negated, thereby forcing the stack fill which is necessary for the stack checking
   logic.  */

/*
#define TX_ENABLE_STACK_CHECKING
*/

/* Determine if the trace event logging code should be enabled. This causes slight increases in
   code size and overhead, but provides the ability to generate system trace information which
   is available for viewing in TraceX.  */

/*
#define TX_ENABLE_EVENT_TRACE
*/

/* Determine if block pool performance gathering is required by the application. When the following is
   defined, ThreadX gathers various block pool performance information. */

/*
#define TX_BLOCK_POOL_ENABLE_PERFORMANCE_INFO
*/

/* Determine if byte pool performance gathering is required by the application. When the following is
   defined, ThreadX gathers various byte pool performance information. */

/*
#define TX_BYTE_POOL_ENABLE_PERFORMANCE_INFO
*/

/* Determine if event flags performance gathering is required by the application. When the following is
   defined, ThreadX gathers various event flags performance information. */

/*
#define TX_EVENT_FLAGS_ENABLE_PERFORMANCE_INFO
*/

/* Determine if mutex performance gathering is required by the application. When the following is
   defined, ThreadX gathers various mutex performance information. */

/*
#define TX_MUTEX_ENABLE_PERFORMANCE_INFO
*/

/* Determine if queue performance gathering is required by the application. When the following is
   defined, ThreadX gathers various queue performance information. */

/*
#define TX_QUEUE_ENABLE_PERFORMANCE_INFO
*/

/* Determine if semaphore performance gathering is required by the application. When the following is
   defined, ThreadX gathers various semaphore performance information. */

/*
#define TX_SEMAPHORE_ENABLE_PERFORMANCE_INFO
*/

/* Determine if thread performance gathering is required by the application. When the following is
   defined, ThreadX gathers various thread performance information. */

/*
#define TX_THREAD_ENABLE_PERFORMANCE_INFO
*/

/* Determine if timer performance gathering is required by the application. When the following is
   defined, ThreadX gathers various timer performance information. */

/*
#define TX_TIMER_ENABLE_PERFORMANCE_INFO
*/

/*  Override options for byte pool searches of multiple blocks. */

/*
#define TX_BYTE_POOL_MULTIPLE_BLOCK_SEARCH    20
*/

/*  Override options for byte pool search delay to avoid thrashing. */

/*
#define TX_BYTE_POOL_DELAY_VALUE              3
*/

#endif
