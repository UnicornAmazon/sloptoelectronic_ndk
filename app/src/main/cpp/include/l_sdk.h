///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2018, All Rights Reserved
//  Created: 2018/12/22
//
/// @file    l_sdk.h
/// @brief   sdk�ӿ�; Ŀ��֧��PC,�ֻ����ڴ�,CPU��Դ�����ƽ̨
///  \n ����������������ϸ�ڲμ�: ˽��Э���ĵ�, SDK�ĵ�
///  \n sdk�ӿ����ԭ��: 1.���ݹ�˾�����豸; 2.�����������ӿ�; 3.sdk�汾���������; 4.����ӿ�
/// @version 0.2
/// @author  ������
/// @history �޸���ʷ
///  \n 2018/12/22 0.1 �����ļ�
///  \n 2019/04/13 0.2 ���������������������޳�, ��Ϊ������������ģ��
///  \n  ����ģ��Ԥ��֧�� nspp�㲥, onvif�鲥�ȵ���������
/// @warning û�о���
///////////////////////////////////////////////////////////////////////////
#ifndef __L_SDK_H__
#define __L_SDK_H__


#include "proto/l_type.h"
#include "l_sdk_define.h"
#include "l_sdk_err.h"
#include "l_sdk_discover.h"
#include "l_sdk_media.h"
#include "l_sdk_dec.h"

#if defined(__cplusplus)
extern "C" {
#endif


/// @brief sdk��ʼ��
/// @param [in] *p_config json��ʽ��sdk��ʼ������Ϣ
/// @return int 0.�ɹ�; ��0.������
/// @note ������μ�SDK������
L_SDK_API int l_sdk_init(const char* p_config);


/// @brief sdk�˳�
L_SDK_API void l_sdk_quit();


/// @brief ���뵽ĳ���豸
/// @param [out] *p_id   ����ɹ�֮��ĵ�¼id
/// @param [in] *p_param json��ʽ�Ĳ�����Ϣ: ����ϸ�ڲο�sdk�ĵ�
/// \n ����: {"ip"="127.0.0.1","port"=3456,"login"={"username"="admin","passwd"="123456"}}
/// @return int 0.�ɹ�; ��0.������
L_SDK_API int l_sdk_login(int* p_id, const char* p_param);


/// @brief �ǳ�ĳ���豸
/// @param [in] id ��¼id
/// @return int 0.�ɹ�; ��0.������
L_SDK_API int l_sdk_logout(int id);


/// @brief ���豸��������
/// @param [in]  id      ��¼id
/// @param [in]  *p_req  ���������(json��ʽ)
/// @param [out] **p_res �������ɹ�,����豸�ظ���Э������(json��ʽ) 
/// @return int 0.�ɹ�; ��0.������
/// @note ���������,�ظ����ݸ�ʽ�μ� Э���ĵ�
L_SDK_API int l_sdk_request(int id, const char* p_req, char** p_res);


/// @brief �ͷ�ͨ��"l_sdk"�����õ��ַ���
/// @param [in] *p_res  ���ͷŵ��ַ����ڴ�
L_SDK_API void l_sdk_free(char* p_res);


#if defined(__cplusplus)
}
#endif

#endif // __L_SDK_H__
//end
