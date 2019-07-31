///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2018, All Rights Reserved
//  Created: 2018/11/22
//
/// @file    l_media.h
/// @brief   ý����,�ı�ͨ����Э��: L_NSPP_MEDIA
///  \n һ.����Э��Ŀ��:
///  \n  1.�ı�ͨ��
///  \n  2.��ý�����
///  \n ��.�����ʽ:
///  \n  1.�ı�Э��(F��):     l_nspp_t + json < 2M
///  \n  2.��Ƶ֡��ʽ(B,F��): l_nspp_t + l_frame_t + [0001 xxx] + [001 xxx] + [0001 xxx] < 64K
///  \n  3.��Ƶ֡��ʽ(B,F��): l_nspp_t + l_frame_t + [xxx] < 64K
///  \n  4.JPEG֡��ʽ(B,F��): l_nspp_t + l_frame_t + jpeg < 64K
///  \n  5.��Ƶ֡,��Ƶ֡,JPEG֡(C,E��): l_nspp_t + [data] < 64K
///  \n ��.����WebSocketЭ��: ��l_nspp_tͷ���滻Ϊwsͷ��
/// @version 0.2
/// @author  ������
/// @history �޸���ʷ
///  \n    2018/11/22    0.1    �����ļ�
///  \n 2019/4/17   0.2 Լ������Э��ϸ��
/// @warning û�о���
///////////////////////////////////////////////////////////////////////////
#ifndef __L_MEDIA_H__
#define __L_MEDIA_H__

#include "proto/l_type.h"

#if defined(__cplusplus)
extern "C" {
#endif


/// @def   L_MD_F_VER
/// @brief V1ý������֡�汾
#define L_MD_F_VER          0x01


#pragma pack(4)

///    @struct l_frame_t
///    @brief    V1ý��֡����
///        ������Ƶ��ʽ: l_frame_t + [0001 xxx] + [001 xxx] + [0001 xxx]
///     ��Ƶ,�������͸�ʽ: l_frame_t + [xxx]
///     �κΰ汾�ͷstruct��, ���ɱ��
typedef struct l_frame_t_
{
    struct
    {
        uint8    size;           ///< ���ṹ�峤�� <= 256
        uint8   ver;            ///< �汾:L_MD_F_VER
        uint8   fmt;            ///< ý���ʽ: [l_md_fmt_e], L_MF_H264, L_MF_H265
        uint8   v_type;         ///< ��Ƶ֡����: [l_mv_type_e] fmt = H264, H265ʱ ��Ч

        uint32    len;            ///< ý�������: ���������ṹ��
    };
    ///- 8�ֽ�

    union {
        struct {
            uint32  w;          ///< (��Ч)��Ƶ��
            uint32  h;          ///< (��Ч)��Ƶ��
        };

        struct {
            uint16 track;       ///< ��Ƶ,������: 1������, 2˫����
            uint16 bit_wide;    ///< ��Ƶ,����λ��: 8, 16, 32
            uint32 sample;      ///< ��Ƶ,������: 8,000 Hz, 44,100 Hz, 96,000 Hz, 192,000 Hz
        };
    };
    ///- [8] + 8�ֽ�

    int64    time;               ///< ʱ��� (΢��)
    uint16  chnn;               ///< ͨ��
    uint16  idx;                ///< �����
    ///- [8 + 8] + 12�ֽ�

    uint32  resv2;              ///< Ԥ��2: Ĭ��0
    ///- [8 + 8 + 12] + 4�ֽ� = 32�ֽ�
}l_frame_t;

#pragma pack()


/// @enum  l_md_idx_e
/// @brief ͨ��ý�������
typedef enum l_md_idx_e_
{
    L_MDIDX_V1      = 0x0000,   ///< ��Ƶ������
    L_MDIDX_V2      = 0x0001,   ///< ��Ƶ������
    L_MDIDX_V3      = 0x0002,   ///< ������Ƶ��

    L_MDIDX_A1      = 0x0020,   ///< ��һ��Ƶ��
    L_MDIDX_A2      = 0x0021,   ///< �ڶ���Ƶ��
    L_MDIDX_A3      = 0x0022,   ///< ������Ƶ��

    L_MDIDX_P1      = 0x0040,   ///< ��һͼƬ��
    L_MDIDX_P2      = 0x0041,   ///< �ڶ�ͼƬ��


    L_MDIDX_PB_V1   = 0x1000,   ///< �ؿ�(��ʷ)��Ƶ������
    L_MDIDX_PB_V2   = 0x1001,   ///< �ؿ�(��ʷ)��Ƶ������
    L_MDIDX_PB_V3   = 0x1002,   ///< �ؿ�(��ʷ)������Ƶ��

    L_MDIDX_PB_A1   = 0x1020,   ///< �ؿ�(��ʷ)��һ��Ƶ��
    L_MDIDX_PB_A2   = 0x1021,   ///< �ؿ�(��ʷ)�ڶ���Ƶ��
    L_MDIDX_PB_A3   = 0x1022,   ///< �ؿ�(��ʷ)�ڶ���Ƶ��

    L_MDIDX_PB_P1   = 0x1040,   ///< �ؿ�(��ʷ)��һͼƬ��
    L_MDIDX_PB_P2   = 0x1041,   ///< �ؿ�(��ʷ)�ڶ�ͼƬ��

    L_MDIDX_END     = 0xFFFF    ///< ����
}l_md_idx_e;


/// @enum  l_md_fmt_e
/// @brief ý��������ʽ(uint8)
typedef enum l_md_fmt_e_
{
    L_FMT_NULL      = 0x00, ///< NULL

    L_FMT_VIDEO_B   = 0x01, ///< ��Ƶ���忪ʼ
    L_FMT_H264      = 0x02, ///< ��Ƶh264��ʽ
    L_FMT_H265      = 0x03, ///< ��Ƶh265��ʽ
    L_FMT_VIDEO_E   = 0x0F, ///< ��Ƶ�������

    L_FMT_AUDIO_B   = 0x10, ///< ��Ƶ���忪ʼ
    L_FMT_G711A     = 0x11, ///< ��Ƶg711.a��ʽ
    L_FMT_G711U     = 0x12, ///< ��Ƶg711.u��ʽ
    L_FMT_ADPCM     = 0x13, ///< ��Ƶadpcm
    L_FMT_LPCM      = 0x14, ///< ��Ƶ�����ʽLPCM
    L_FMT_G726      = 0x15, ///< ��Ƶ�����ʽG726
    L_FMT_AAC       = 0x16, ///< ��Ƶaac��ʽ
    L_FMT_AUDIO_E   = 0x2F, ///< ��Ƶ�������

    L_FMT_TXT_B     = 0x30, ///< �ı����忪ʼ
    L_FMT_TXT_E     = 0x3F, ///< �ı��������

    L_FMT_PIC_B     = 0x40, ///< ͼƬ���忪ʼ
    L_FMT_JPEG      = 0x41, ///< ͼƬJPEG��ʽ
    L_FMT_PIC_E     = 0x5F, ///< ͼƬ�������

    L_FMT_END       = 0xFF  ///< ����
}l_md_fmt_e;


/// @enum  l_mv_type_e
/// @brief ��Ƶ������
typedef enum l_mv_type_e_
{
    L_MVT_NULL  = 0x0, ///< NULL
    L_MVT_I     = 0x1, ///< I֡
    L_MVT_P     = 0x2, ///< P֡
    L_MVT_B     = 0x3, ///< B֡

    L_MVT_END   = 0xF  ///< ����
}l_mv_type_e;


//////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG
#define L_NSPP_CHECK_MPB(p_mpb_) ((void)0)
#else
#define L_NSPP_CHECK_MPB(p_mpb_) \
{ \
    l_nspp_t* p_nspp_tmp_ = (l_nspp_t*)((p_mpb_)->data.p_buf + (p_mpb_)->data.start); \
    L_NSPP_CHECK(p_nspp_tmp_); \
    if (L_NSPP_F == p_nspp_tmp_->opt || L_NSPP_B == p_nspp_tmp_->opt) \
    { \
        l_frame_t* p_frame_tmp_ = (l_frame_t*)((p_mpb_)->data.p_buf + (p_mpb_)->data.start + sizeof(l_nspp_t)); \
        assert(sizeof(l_frame_t) == p_frame_tmp_->size); \
        assert(L_MD_F_VER == p_frame_tmp_->ver); \
        assert(p_frame_tmp_->v_type <= L_MVT_B);\
        assert(p_frame_tmp_->len <= 4 * 1024 * 1024);\
    } \
}
#endif


#ifdef __cplusplus
}
#endif

#endif // __L_MEDIA_H__
//end
