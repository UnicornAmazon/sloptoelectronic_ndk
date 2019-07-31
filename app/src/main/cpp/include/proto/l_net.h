///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2018, All Rights Reserved
//  Created: 2018/11/22
//
/// @file    l_net.h
/// @brief   ���粿�ֹ�������,���������
/// @version 0.1
/// @author  ������
/// @history �޸���ʷ
///  \n    2018/11/22    0.1    �����ļ�
/// @warning û�о���
///////////////////////////////////////////////////////////////////////////
#ifndef __L_NET_H__
#define __L_NET_H__

#include "proto/l_type.h"

#if defined(__cplusplus)
extern "C" {
#endif

/// @def   L_NET_TAIL
/// @brief ���绺�����ٿ����ֽ�
#define L_NET_TAIL            4


/// @def   L_NET_MIN_BUF
/// @brief ������ջ�����Сֵ
#define L_NET_MIN_BUF        4 * 1024


/// @def   L_NET_MD_BUF
/// @brief ý�����ݽ��ջ���
#define L_NET_MD_BUF        64 * 1024


/// @def   L_NET_TIME_OUT
/// @brief �������ӳ�ʱ 20S
/// \n �Ƽ�:�ɿͻ��˷�����������ݼ�� 10S
#define L_NET_TIME_OUT        20000


/// @def   L_NET_SMALL_HT_MAX
/// @brief ����ʹ�õ���hashtableͰ��С
///  \ ����ht_u32_t, ����: L_NET_HT_MAX * 4 + N * 12
///  \ 1000 ԼΪ 4K + N * 12 + N * Key
#define L_NET_SMALL_HT_MAX  1000


/// @def   L_NET_HT_MAX
/// @brief ����ʹ�õ���hashtableͰ��С
///  \ ����ht_u32_t, ����: L_NET_HT_MAX * 4 + N * 12
///  \ 10000 ԼΪ 40K + N * 12 + N * Key
#define L_NET_HT_MAX        10000


/// @def   L_NET_HT_MAX
/// @brief ����ʹ�õ��Ľϴ�hashtableͰ��С
///  \ ����ht_u32_t, ����: L_NET_HT_MAX * 4 + N * 12
///  \ 20000 ԼΪ 80K + N * 12 + N * Key
#define L_NET_LARGE_HT_MAX  20000


/// @enum  l_net_def_e
/// @brief ����״̬ OR ��׼���̲����Ĵ���, ��������ϸ��
typedef enum l_net_def_e_
{
    L_NET_OK       = 0x0000,   ///< ����һ������
    L_NET_CLOSE,               ///< �����ر�����, �����Է��Ͳ�������
    L_NET_ERR,                   ///< ��·����(��дsocket����-1����),l_socket_param_t.err_code���¼������
    L_NET_DISCONN,               ///< �Ͽ�����(��дsocket����0����)
    L_NET_TIMEOUT,               ///< ���糬ʱ(��ʱ�������ݶ�д����)
    L_NET_OUT_MEM,               ///< �ڴ���������ݰ����������ڴ��������
    L_NET_ERR_PROTO,           ///< ���ݵ�Э���ʽ��������
    L_NET_ERR_REPEAT,          ///< �����ظ����Ѵ���key��

    L_NET_NO_P_ENV = 0x0100,   ///< û��Э�����ӻ���
    L_NET_NO_PARSER,           ///< δ�ҵ�����Э��

    L_NET_CONNECT  = 0x0E00,   ///< �����Ӽ���

    L_NET_DEF_END  = 0x0FFF    ///< �������

}l_net_def_e;


/// @enum  l_net_flag_e
/// @brief ���糣�ñ��
typedef enum l_net_flag_e_
{
    L_NET_WRITE    = 0x0001,    ///< ������ �ȴ�д
}l_net_flag_e;


/// @enum  l_net_protocol_e
/// @brief ����Э������
///  \n L_NET_NSPP��Э�鶨��: l_nspp_sub_proto_e
typedef enum l_net_protocol_e_
{
    L_NET_P_NULL = 0,    ///< ��δ�ҵ�Э��
    L_NET_UNKNOWN,       ///< ��ȷ��δ֪Э��
    L_NET_HTTP,          ///< http[TCP]
    L_NET_RTSP,          ///< rtsp[TCP]
    L_NET_WS,            ///< websocket[TCP]

    L_NET_NSPP = 20,     ///< nspp[TCP]: v1˽��Э��
    L_NET_NSPP_MULTICAST,///< nspp�鲥[UDP]: v1˽���鲥, �������緢��,�����ı�Э��,���ö���ҵ��Э��, ���ô���ý����
    L_NET_NSPP_BROADCAST,///< nspp�㲥[UDP]: v1˽�й㲥, �������緢��ʹ��, ��������������;

    L_NET_P_USER = 1000, ///< �û��Զ�Э��

    L_NET_P_END  = 0x7FFF   ///< ��Э�����
}l_net_protocol_e;


/// @def   L_NET_PROTO_MAIN
/// @brief ��ȡ��Э��
#define L_NET_PROTO_MAIN(proto_)    ((int)(proto_) & 0xFFFF)


/// @def   L_NET_PROTO_SUB
/// @brief ��ȡ��Э��
#define L_NET_PROTO_SUB(proto_)     (((int)(proto_) >> 16) & 0xFFFF)


/// @def   L_NET_PROTO
/// @brief ����Э����ֵ
#define L_NET_PROTO(main_, sub_)    (((int)(sub_) << 16) | ((int)(main_)))



#if defined(__cplusplus)
}
#endif

#endif // __L_NET_H__
//end
