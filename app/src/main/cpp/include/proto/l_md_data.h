///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2018, All Rights Reserved
//  Created: 2019/01/03
//
/// @file    l_md_data.h
/// @brief   解码之后的原始媒体数据: 图片,音频
/// @version 0.1
/// @author  李绍良
/// @history 修改历史
///  \n 2019/01/03 0.1 创建文件
/// @warning 没有警告
///////////////////////////////////////////////////////////////////////////
#ifndef __L_MD_DATA_H__
#define __L_MD_DATA_H__

#include "proto/l_type.h"
#include "proto/l_md_buf.h"

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum l_md_data_type_e_
{
    L_MDDT_NULL = 0,
    L_MDDT_ARGB8888 = 1,        ///< [ARGB][ARGB][ARGB]
    L_MDDT_ARGB8888_SEPARATE,   ///< [AAAA][RRRR][GGGG][BBBB]

    L_MDDT_RGB888,              ///< [RGB][RGB][RGB]
    L_MDDT_RGB888_SEPARATE,     ///< [RRR][GGG][BBB]

    L_MDDT_YUV420P,             ///< [YUV][YUV][YUV]...[Y00][Y00][Y00]
    L_MDDT_YUV420P_SEPARATE,    ///< [YYY][UUU][VVV]

    L_MDDT_ARGB1555,            ///< [ARGB][ARGB][ARGB]
}l_md_data_type_e;

#pragma pack(4)

typedef struct l_md_data_t_
{
    int             type;
    int64           time;

    union
    {
        struct
        {
            int     w;
            int     h;
        };
    };

    union
    {
        struct
        {
            char*   p_y;
            int     pitch_y;

            char*   p_u;
            int     pitch_u;

            char*   p_v;
            int     pitch_v;
        };

        struct
        {
            char*   p_a;
            char*   p_r;
            char*   p_g;
            char*   p_b;
        };

        char*       p_argb;
        char*       p_rgb;
        char*       p_yuv;
    };

    l_buf_t         data;
}l_md_data_t;

#pragma pack()


#if defined(__cplusplus)
}
#endif

#endif // __L_MD_DATA_H__
//end
