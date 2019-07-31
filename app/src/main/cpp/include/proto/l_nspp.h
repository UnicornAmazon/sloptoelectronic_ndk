///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2018, All Rights Reserved
//  Created: 2018/11/28
//
/// @file    l_nspp.h
/// @brief   net slice packet protocol ����ְ�Э��
/// @version 0.3 
/// @note �����������ݸ�ʽ��Ҫע�����µ�
///  \n 1. Э�������, ע��汾����
///  \n 2. ע����WebsocketЭ��ԽӼ�����, ����Э����Բ��޸Ļ������޸�ת��ΪWebsocketЭ��ʵ��
///  \n 3. Э�����ʵ��Ϊ������,������
///  \n 4. Э�麭���ı�, ������(����Ƶ, �ļ���)����
///  \n 5. �����Э�����: ����Э�����÷�Χ, ����ҵ������, ѡ��������Э��
/// @history �޸���ʷ
/// @author  ������
///  \n 2018/11/28 0.1  �����ļ�
///  \n 2019/3/5   0.2  ��ӱ�Э���ת��ΪWebSocketʵ�ֵĻ���������
///  \n 2019/4/17  0.3  �����Э�����
///  \n     -- NSPP             ����Э����
///  \n     --------- MEDIA     ý����,�ı�ͨ����Э��
///  \n     --------- UPGRADE   (�ͻ������豸���������)������Э��
///  \n     --------- FTP       �ļ�������Э��
/// @warning û�о���
///////////////////////////////////////////////////////////////////////////
#ifndef __L_NSPP_H__
#define __L_NSPP_H__

#include "proto/l_type.h"


#if defined(__cplusplus)
extern "C" {
#endif


/// @def   L_NSPP_FLAG
/// @brief ����ְ�Э��ħ�����
#define L_NSPP_FLAG         0xFA5A5F


/// @def   L_NSPP_VER
/// @brief ����ְ�Э��汾
#define L_NSPP_VER          0x1


/// @enum  l_nspp_opt_e
/// @brief �ְ���ϰ����
///   ��������ʽ: F
///   �ְ���ʽ:   B [C] [C] E
typedef enum l_nspp_opt_e_
{
    L_NSPP_F = 0x0,     ///< FULL ������
    L_NSPP_B = 0x1,     ///< BEGIN ��ʼ��
    L_NSPP_C = 0x2,     ///< CONTINUE �м��
    L_NSPP_E = 0x3      ///< END ������
}l_nspp_opt_e;


/// @enum  l_nspp_type_e
/// @brief ����ְ�����; ������Ҫ���Ǽ��� WebSocket
///  \n WebSocket��Ҫ����Ϊ: �ı�,������,PING,PONG
///  \n ��������������ȷ������Websocket����, ����ֻ�ɶ����ı�, ������, ����������
typedef enum l_nspp_type_e_
{
    L_NSPP_NULL = 0x0, ///< NULL
    L_NSPP_MD   = 0x1, ///< ����������;(ý��֡, �ļ���)(����nspp+dataС��64K)
    L_NSPP_TXT  = 0x2, ///< �ı��Ự(����nspp+dataС��2M)

    L_NSPP_HEART= 0xE, ///< ����: �������ݳ���Ϊ0;��������TXT�а��������ҪΪ���ִ��Ч��; �ͻ��˷�������,����˻�Ӧ
    L_NSPP_END  = 0xF  ///< ����
}l_nspp_type_e;


/// @enum  l_nspp_sub_proto_e
/// @brief nspp��Э��
typedef enum l_nspp_sub_proto_e_
{
    L_NSPP_MEDIA        = 0,        ///< ý����,�ı�ͨ����Э��
    L_NSPP_UPGRADE      = 1,        ///< (�ͻ������豸���������)������Э��
    L_NSPP_FTP          = 2,        ///< �ļ�������Э��

    L_NSPP_SUB_P_END    = 0x7FFF    ///< ��Э�����
}l_nspp_sub_proto_e;


#pragma pack(4)


/// @struct l_nspp_t
/// @brief  ���紫��ý��ְ���ʽͷ
///  \n 1.�κΰ汾���ɱ��
///  \n 2.���紫������ư�(ý�����)��ʽ: l_nspp_t + [l_frame_t] + [0001 xxx 0001] < 64K
///  \n 3.���紫���ı�����ʽ: l_nspp_t + [txt] < 2M
///  \n 4.���紫����������ʽ: l_nspp_t = 12�ֽ�
typedef struct l_nspp_h_t_
{
    uint32 flag : 24;       ///< ħ�����: L_NSPP_FLAG   
    uint32 ver : 4;         ///< ����Э��汾: L_NSPP_VER
    uint32 opt : 4;         ///< �ְ����: l_nspp_opt_e: F,B,C,E

    uint32 len : 24;        ///< ���ݰ�����(���������ṹ��): [type = L_NSPP_MD, len < 64K][type = L_NSPP_TXT, len < 2M]
    uint32 type : 4;        ///< ����ְ�����: l_nspp_type_e
    uint32 resv : 4;        ///< 0
    ///- 8�ֽ�

    uint16 resv2;           ///< 0
    uint16 sub_proto;       ///< ��Э��: l_nspp_sub_proto_e
    ///- [8] + 4�ֽ� = 12�ֽ�
}l_nspp_t;

#pragma pack()


//////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG
#define L_NSPP_CHECK(p_nspp_)    ((void)0)
#else
#define L_NSPP_CHECK(p_nspp_) \
{ \
    assert(L_NSPP_FLAG == (p_nspp_)->flag); \
    assert(L_NSPP_VER == (p_nspp_)->ver); \
    assert((p_nspp_)->opt <= L_NSPP_E); \
}
#endif


#ifdef __cplusplus
}
#endif

#endif // __L_NSPP_H__
//end
