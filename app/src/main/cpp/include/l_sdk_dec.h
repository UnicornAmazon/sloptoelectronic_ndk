///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2019, All Rights Reserved
//  Created: 2019/01/07
//
/// @file    l_sdk_dec.h
/// @brief   ��·������ʾ
/// @version 0.1
/// @author  ������
/// @history �޸���ʷ
///  \n 2019/01/07 0.1 �����ļ�
/// @warning û�о���
///////////////////////////////////////////////////////////////////////////
#ifndef __L_SDK_DEC_H__
#define __L_SDK_DEC_H__

#include "proto/l_type.h"
#include "proto/l_media.h"
#include "proto/l_md_buf.h"
#include "proto/l_md_data.h"
#include "l_sdk_define.h"


#if defined(__cplusplus)
extern "C" {
#endif


/// @brief ��һ��������
/// @param [in] dec_id      �û��Զ��������id: [1-N]
/// @param [in] *p_param    �򿪲���
/// @return int ���ش�����
L_SDK_API int l_sdk_dec_open(int dec_id, const char* p_param);


/// @brief �رս�����
/// @param [in] dec_id      ������id
/// @return int ���ش�����
L_SDK_API int l_sdk_dec_close(int dec_id);


/// @brief �󶨽�������ĳ����¼id���ض�����
/// @param [in] dec_id      ������id
/// @param [in] chnn        ͨ��
/// @param [in] idx         �����,��������
/// @param [in] md_id       ý���Զ���id
/// @return int ���ش�����
L_SDK_API int l_sdk_dec_bind(int dec_id, int login_id, int chnn, int idx, int md_id);


/// @brief ����������İ�
/// @param [in] dec_id      ������id
/// @return int ���ش�����
L_SDK_API int l_sdk_dec_unbind(int dec_id);


/// @brief ��ȡ�������֮���ԭʼý������: ����,L_MDDT_YUV420P_SEPARATE��ʽ
/// @param [in] dec_id          ������id
/// @param [out] **p_md_data    ���ý������ָ��
/// @return int ���ش�����
/// @note ����0.��ʾȡ��������, p_md_data��Ч
///  \n ���ط�0.��ʾû��ȡ�����ݵĴ�����Ϣ
///  \n ���Ϊ25-30֡, �����۵��ô˺���Ƶ��Ϊ60, ����ᵼ�����ݻ�ѹ, �������ᶪ����������
///  \n ���Ϊ60֡, �����۵��ô˺���Ƶ��Ϊ120, ����ᵼ�����ݻ�ѹ, �������ᶪ����������
///  \n ���ú�����ʾ���������д�������
///  \n �뺯��l_sdk_dec_open_wnd()���ھ������ݹ�ϵ
L_SDK_API int l_sdk_dec_get_md_data(int dec_id, l_md_data_t** p_md_data);


/// @brief �ͷ�ԭʼý������
/// @param [in] dec_id          ������id
/// @param [out] **p_md_data    ���ý������ָ��
/// @return int ���ش�����
L_SDK_API int l_sdk_dec_free_md_data(l_md_data_t* p_md_data);


/// @brief ��opengl�����д�һ������
/// @param [in] dec_id          ������id
/// @return int ���ش�����
/// @note �˺���������opengl�߳���ִ��
///  \n �Ƽ�ʹ���� android, ios
///  \n �뺯��l_sdk_dec_get_md_data()���ھ�����ϵ
L_SDK_API int l_sdk_dec_open_wnd(int dec_id);


/// @brief ��opengl�����йرմ���
/// @param [in] dec_id          ������id
/// @return int ���ش�����
/// @note �˺���������opengl�߳���ִ��
L_SDK_API int l_sdk_dec_close_wnd(int dec_id);


/// @brief ��Ⱦ��Ƶͼ��
/// @param [in] dec_id          ������id
/// @return int ���ش�����
/// @note �˺���������opengl�߳���ִ��
///  \n ����0.��ʾ��������Ⱦ, �������� �ٵ���glFlush��SwapBuffers(hdc)����ϵͳ��غ���ˢ�µ������Դ�
///  \n ���ط�0.��ʾû��������
L_SDK_API int l_sdk_dec_render(int dec_id);


#if defined(__cplusplus)
}
#endif

#endif // __L_SDK_DEC_H__
//end
