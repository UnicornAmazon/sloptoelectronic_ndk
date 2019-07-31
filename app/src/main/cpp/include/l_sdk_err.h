///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2018, All Rights Reserved
//  Created: 2018/12/24
//
/// @file    l_sdk_err.h
/// @brief   �����붨��; �������������,��������
/// @version 0.1
/// @author  ������
/// @history �޸���ʷ
///  \n 2018/12/24 0.1 �����ļ�
/// @warning û�о���
///////////////////////////////////////////////////////////////////////////
#ifndef __L_SDK_ERR_H__
#define __L_SDK_ERR_H__


#if defined(__cplusplus)
extern "C" {
#endif


/// @enum  l_sdk_err_t
/// @brief sdk���������
typedef enum l_sdk_err_t_
{
    L_SDK_OK = 0,
    L_SDK_ERR_INIT,             ///< SDKδ��ʼ��, ���ʼ������
    L_SDK_ERR_TIME_OUT,         ///< �ȴ���ʱ
    L_SDK_ERR_PARAM,            ///< ��������
    L_SDK_ERR_OPEN,             ///< ��ʧ��,��û�д򿪶�Ӧ�Ķ���
    L_SDK_ERR_NO_DATA,          ///< ������,��û��������ˢ��

    L_SDK_ERR_END = 0x0FFF
}l_sdk_err_t;


/// @enum  l_sdk_proto_err_t
/// @brief ����Э�������: ע��� lua���ֱ���һ��
typedef enum l_sdk_proto_err_t_
{
    L_SDK_PERR_B = 0x1000,                      ///< Э������뿪ʼ
    L_SDK_PERR_UNSUPPORT = L_SDK_PERR_B + 1,    ///< ��֧�ֵ�Э������
    L_SDK_PERR_NOTFOUND = L_SDK_PERR_B + 2,     ///< δ�ҵ�; û�ҵ�����,������,��ҳ��
    L_SDK_PERR_PARAM = L_SDK_PERR_B + 3,        ///< Э���������

    L_SDK_PERR_E = 0x7FFF                       ///< Э����������
}l_sdk_proto_err_t;


#if defined(__cplusplus)
}
#endif


#endif // __L_SDK_ERR_H__
//end
