///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2018, All Rights Reserved
//  Created: 2018/10/18
//
/// @file    l_type.h
/// @brief   �����������Ͷ���:win,linux,ios,android,emscripten
/// @version 0.1
/// @author  ������
/// @history �޸���ʷ
///  \n 2018/10/18    0.1    �����ļ�
/// @warning û�о���
///////////////////////////////////////////////////////////////////////////
#ifndef __L_TYPE_H__
#define __L_TYPE_H__

/*
    8,16,32,64 �������ݶ���
    __L_WIN32__,        __L_WIN64__,            //x86
    __L_LINUX32__,        __L_LINUX64__,            //x86
    __L_LINUX32_ARM__,    __L_LINUX64_ARM__,        //arm
    __L_IOS__,        // ios
    __L_ANDROID__,    // android

    __L_MEM_D__,    // �����ڴ�й¶
    NDEBUG,            //���а汾
*/
#if defined(__L_WIN32__) || defined(__L_WIN64__)
    #ifndef __L_WIN__
        #define __L_WIN__
    #endif
#elif defined(__L_LINUX32__) || defined(__L_LINUX64__) || defined(__L_LINUX32_ARM__) || defined(__L_LINUX64_ARM__)
    #ifndef __L_LINUX__    
        #define __L_LINUX__
    #endif
#elif defined(__L_IOS__) || defined(__L_ANDROID__)
    #ifndef __L_LINUX__    
        #define __L_LINUX__
    #endif
#elif defined(__L_EMCC__)
    #ifndef __L_LINUX__    
        #define __L_LINUX__
    #endif
#else
    #error Not Suport Platform
#endif

#if defined(__L_WIN32__) || defined(__L_LINUX32__) || defined(__L_LINUX32_ARM__) || defined(__L_EMCC__)
    typedef unsigned char        bool8;
    typedef char                int8;
    typedef unsigned char        uint8;
    typedef unsigned short        bool16;
    typedef short                int16;
    typedef unsigned short        uint16;
    typedef int                    int32;
    typedef unsigned int        uint32;
    typedef unsigned int        bool32;
    typedef long long            int64;
    typedef unsigned long long    uint64;

    typedef int                 bool_t;
    typedef int                    int_t;        //����,������ֳ��仯
    typedef unsigned int        uint_t;        //�޷�������,������ֳ��仯
    typedef long                long_t;        //����,������ֳ��仯
    typedef unsigned long        ulong_t;    //����,������ֳ��仯
#elif defined(__L_WIN64__) || defined(__L_LINUX64__) || defined(__L_LINUX64_ARM__)
    typedef unsigned char        bool8;
    typedef char                int8;
    typedef unsigned char        uint8;
    typedef unsigned short        bool16;
    typedef short                int16;
    typedef unsigned short        uint16;
    typedef int                    int32;
    typedef unsigned int        uint32;
    typedef unsigned int        bool32;
    typedef long long            int64;
    typedef unsigned long long    uint64;

    typedef long long           bool_t;
    typedef long long            int_t;        //����,������ֳ��仯
    typedef unsigned long long    uint_t;        //�޷�������,������ֳ��仯
    typedef long long            long_t;        //����,������ֳ��仯
    typedef unsigned long long    ulong_t;    //����,������ֳ��仯
#elif defined(__L_IOS__) || defined(__L_ANDROID__)
    typedef unsigned char        bool8;
    typedef char                int8;
    typedef unsigned char        uint8;
    typedef unsigned short        bool16;
    typedef short                int16;
    typedef unsigned short        uint16;
    typedef int                    int32;
    typedef unsigned int        uint32;
    typedef unsigned int        bool32;
    typedef long long            int64;
    typedef unsigned long long    uint64;

    typedef long long           bool_t;
    typedef long long            int_t;        //����,������ֳ��仯
    typedef unsigned int        uint_t;     //�޷�������,������ֳ��仯
    typedef long long            long_t;        //����,������ֳ��仯
    typedef unsigned int        ulong_t;    //����,������ֳ��仯
#else
    #error Not Suport Platform
#endif

#if defined(__L_WIN__)
    #if defined(__L_BUILD_DLL__) || defined(__L_CORE_API__)
        #define L_API extern "C" __declspec(dllexport)
    #elif defined(__L_USE_DLL__)
        #define L_API extern "C" __declspec(dllimport)
    #else
        #define L_API
    #endif
#else
    #ifdef __cplusplus
        #define L_API extern "C"
    #else
        #define L_API extern
    #endif
#endif

// false
#ifndef L_FALSE
    #define L_FALSE        0
#endif

// true
#ifndef L_TRUE
    #define L_TRUE        1
#endif

// void*: NULL
#ifndef NULL
    #define NULL        0
#endif

// int: �ɹ�
#ifndef L_SUCC
    #define L_SUCC        0
#endif

// int: ʧ��
#ifndef L_FAIL
    #define L_FAIL        1
#endif

// int32: ����
#ifndef L_ERR
    #define L_ERR        (-1)
#endif

#endif // __L_TYPE_H__
//end
