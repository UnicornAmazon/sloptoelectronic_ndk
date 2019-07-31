///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2018, All Rights Reserved
//  Created: 2018/12/29
//
/// @file    l_md_buf.h
/// @brief   ý�����ݹ����ڴ�; �������ڴ���Դ�ḻ��ƽ̨: pc,�ֻ���
/// @version 0.1
/// @author  ������
/// @history �޸���ʷ
///  \n 2018/12/29 0.1 �����ļ�
/// @warning û�о���
///////////////////////////////////////////////////////////////////////////
#ifndef __L_MD_BUF_H__
#define __L_MD_BUF_H__

#include "proto/l_type.h"
#include "proto/l_media.h"


#if defined(__cplusplus)
extern "C" {
#endif

#pragma pack(4)


/// @struct l_buf_t
/// @brief  ��������ṹ����
typedef struct l_buf_t_
{
    char*   p_buf;          ///< ����ָ��
    int     buf_len;        ///< ���泤��

    int     start;          ///< ������ʼλ��
    int     end;            ///< ���ݽ���λ��
}l_buf_t;


/// @struct l_md_buf_t
/// @brief  �����ü���,����滺��ṹ
typedef struct l_md_buf_t_
{
    uint32  tc;                     ///< ϵͳ�δ���[�����߶�д,������ֻ��]
    uint32  md_id;                  ///< ý��id[�����߶�д,������ֻ��]

    uint8   ver;                    ///< frameͷ�汾[�����߶�д,������ֻ��]
    uint8   resv1;
    uint16  resv2;

    union
    {
        l_frame_t   f_v1;           ///< ver = L_MD_F_VERʱ, ��Ч[�����߶�д,������ֻ��]
    };

    struct
    {
        char*       p_buf;          ///< ����ָ��[�����߶�д,������ֻ��]
        int         buf_len;        ///< ���泤��[�����߶�д,������ֻ��]

        int         start;          ///< ������ʼλ��[�����߶�д,������ֻ��]
        int         end;            ///< ���ݽ���λ��[�����߶�д,������ֻ��]
    };

    struct
    {
        void*       p_count;        ///< ���ü�����; [�����߲��ɼ�]
    };
}l_md_buf_t;

#pragma pack()


#if defined(__cplusplus)
}
#endif

#endif // __L_MD_BUF_H__
//end
