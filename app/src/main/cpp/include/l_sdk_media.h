///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2018, All Rights Reserved
//  Created: 2018/12/22
//
/// @file    l_sdk_media.h
/// @brief   ý��������
/// @version 0.1
/// @author  ������
/// @history �޸���ʷ
///  \n 2018/12/22 0.1 �����ļ�
/// @warning û�о���
///////////////////////////////////////////////////////////////////////////
#ifndef __L_SDK_MEDIA_H__
#define __L_SDK_MEDIA_H__

#include "proto/l_type.h"
#include "proto/l_media.h"
#include "proto/l_md_buf.h"
#include "proto/l_net.h"
#include "l_sdk_define.h"

#if defined(__cplusplus)
extern "C" {
#endif


/// @brief ����ý�����ݵĻص�����
/// @note ��ֹ�ڻص�������ʹ�ú�ʱ����, �������������ý������߳�
typedef int(*l_sdk_media_cb)(void* p_obj, int protocol, int id, int chnn, int idx, int md_id, l_md_buf_t* p_data);


/// @brief ���ý�����ݼ�����
/// @return int 0.�ɹ�; ��0.������
L_SDK_API int l_sdk_md_add_listener(char* p_name, l_sdk_media_cb cb_media, void* p_obj);


/// @brief �Ƴ�ý�����ݼ�����
/// @return int 0.�ɹ�; ��0.������
L_SDK_API int l_sdk_md_remove_listener(char* p_name);


/// @brief ������ڴ滺���еĲ�����ý������; ����ȷ��ʹ��l_sdk_md_get�õ����µ�����
/// @param [in] id        ��¼id
/// @param [in] chnn      ͨ��
/// @param [in] idx       �����
/// @param [in] md_id     ý��id
/// @return int 0.�ɹ��������; L_SDK_ERR_NO_DATA.�������Ա����
L_SDK_API int l_sdk_md_clear(int id, int chnn, int idx, int md_id);




/// @brief ���ڴ滺���л�ȡ���µ�ý������
/// @param [in] id        ��¼id
/// @param [in] chnn      ͨ��
/// @param [in] idx       �����
/// @param [in] md_id     ý��id
/// @param [out] **p_data ý������
/// @return int 0.�ɹ�; ��0.������
/// @note �������0, ��p_data�����ü����Ѿ�����1, ��������Ҫ����l_sdk_md_buf_sub�����ͷ�����
L_SDK_API int l_sdk_md_get(int id, int chnn, int idx, int md_id, l_md_buf_t** p_data);


/// @brief ý�����ݿ����ü�����1
/// @param [in] *p_data ý������
/// @return int 0.�ɹ�; ��0.������
L_SDK_API int l_sdk_md_buf_add(l_md_buf_t* p_data);


/// @brief ý�����ݿ����ü�����1
/// @param [in] *p_data ý������
/// @return int 0.�ɹ�; ��0.������
L_SDK_API int l_sdk_md_buf_sub(l_md_buf_t* p_data);


#if defined(__cplusplus)
}
#endif

#endif // __L_SDK_MEDIA_H__
//end
