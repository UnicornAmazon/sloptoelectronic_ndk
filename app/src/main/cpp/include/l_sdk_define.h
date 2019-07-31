///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2018, All Rights Reserved
//  Created: 2018/12/22
//
/// @file    l_sdk_define.h
/// @brief   �⵼���ȶ���
/// @version 0.1
/// @author  ������
/// @history �޸���ʷ
///  \n 2018/12/22 0.1 �����ļ�
/// @warning û�о���
///////////////////////////////////////////////////////////////////////////
#ifndef __L_SDK_DEFINE_H__
#define __L_SDK_DEFINE_H__


#include "proto/l_type.h"

#if defined(__cplusplus)
extern "C" {
#endif


#if defined(__L_WIN__)
    #if defined(__L_SDK_BUILD_DLL__)
        #define L_SDK_API extern "C" __declspec(dllexport)
    #elif defined(__L_SDK_USE_DLL__)
        #define L_SDK_API extern "C" __declspec(dllimport)
    #else
        #define L_SDK_API
    #endif
#else
    #ifdef __cplusplus
        #define L_SDK_API extern "C"
    #else
        #define L_SDK_API extern
    #endif
#endif

#if defined(__cplusplus)
}
#endif

#endif // __L_SDK_DEFINE_H__
//end
