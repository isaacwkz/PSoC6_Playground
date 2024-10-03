/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

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

#ifdef RTOS_TRACE
#define TX_TRACE_TIME_SOURCE ++_tx_trace_simulated_time
// #define TX_TRACE_TIME_SOURCE ((unsigned long)0x13000004)
#define TX_TRACE_TIME_MASK 0xFFFFFFFFUL
#define TX_ENABLE_EVENT_TRACE
#endif

#define TX_TIMER_TICKS_PER_SECOND (1000UL)

#define TX_MAX_PRIORITIES 12
#define TX_TIMER_PROCESS_IN_ISR
#define TX_REACTIVATE_INLINE
#define TX_DISABLE_STACK_FILLING
#define TX_ENABLE_STACK_CHECKING
#define TX_INLINE_THREAD_RESUME_SUSPEND
// #define TX_BLOCK_POOL_ENABLE_PERFORMANCE_INFO
// #define TX_BYTE_POOL_ENABLE_PERFORMANCE_INFO
// #define TX_EVENT_FLAGS_ENABLE_PERFORMANCE_INFO
// #define TX_MUTEX_ENABLE_PERFORMANCE_INFO
// #define TX_QUEUE_ENABLE_PERFORMANCE_INFO
// #define TX_SEMAPHORE_ENABLE_PERFORMANCE_INFO
// #define TX_THREAD_ENABLE_PERFORMANCE_INFO
// #define TX_TIMER_ENABLE_PERFORMANCE_INFO

// #define TX_ENABLE_RANDOM_NUMBER_STACK_FILLING
// #define TX_DISABLE_PREEMPTION_THRESHOLD
// #define TX_DISABLE_REDUNDANT_CLEARING
// #define TX_NO_TIMER
// #define TX_DISABLE_NOTIFY_CALLBACKS
// #define TX_NO_FILEX_POINTER
// #define TX_NOT_INTERRUPTABLE
// #define TX_BYTE_POOL_MULTIPLE_BLOCK_SEARCH    20
// #define TX_BYTE_POOL_DELAY_VALUE              3

#endif