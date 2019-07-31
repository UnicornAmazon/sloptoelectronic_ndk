///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2018, All Rights Reserved
//  Created: 2018/12/22
//
/// @file    l_sdk_discover.h
/// @brief   ���緢��ģ��: 1.���緢��; 2.�㲥Э������
/// @version 0.2
/// @author  ������
/// @history �޸���ʷ
///  \n 2018/12/22 0.1 �����ļ�
///  \n 2019/04/13 0.2 ����ǩ���޸�Ϊ *_discover_* ϵ��, �Ա�֧��onvif�����������豸����
/// @warning û�о���
///////////////////////////////////////////////////////////////////////////
#ifndef __L_SDK_DISCOVER_H__
#define __L_SDK_DISCOVER_H__

#include "proto/l_type.h"
#include "l_sdk_define.h"

#if defined(__cplusplus)
extern "C" {
#endif


/// @brief �򿪹㲥����ģ��
/// @return int ������
L_SDK_API int l_sdk_discover_open(const char* p_param);


/// @brief �رչ㲥����ģ��
/// @return int ������
L_SDK_API int l_sdk_discover_close();


/// @brief ��/�رճ�������
/// @return int ������
L_SDK_API int l_sdk_discover_run(bool8 b_open);


/// @brief ������֮��, ��ȡ��ǰ�����е��豸
/// @param [out] **p_devs   �豸�б�
/// @return int ������
L_SDK_API int l_sdk_discover_get_devs(char** p_devs);


/// @brief ��ĳ��sn�豸���͹㲥����
/// @param [in] *p_req     ��������
/// @param [out] **p_res   �ظ�������
/// @return int ������
L_SDK_API int l_sdk_discover_request(const char* p_req, char** p_res);


#if defined(__cplusplus)
}
#endif

#endif // __L_SDK_DISCOVER_H__
//end
