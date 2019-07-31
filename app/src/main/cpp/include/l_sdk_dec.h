///////////////////////////////////////////////////////////////////////////
//  Copyright(c) 2019, All Rights Reserved
//  Created: 2019/01/07
//
/// @file    l_sdk_dec.h
/// @brief   单路解码显示
/// @version 0.1
/// @author  李绍良
/// @history 修改历史
///  \n 2019/01/07 0.1 创建文件
/// @warning 没有警告
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


/// @brief 打开一个解码器
/// @param [in] dec_id      用户自定义解码器id: [1-N]
/// @param [in] *p_param    打开参数
/// @return int 返回错误码
L_SDK_API int l_sdk_dec_open(int dec_id, const char* p_param);


/// @brief 关闭解码器
/// @param [in] dec_id      解码器id
/// @return int 返回错误码
L_SDK_API int l_sdk_dec_close(int dec_id);


/// @brief 绑定解码器到某个登录id的特定流上
/// @param [in] dec_id      解码器id
/// @param [in] chnn        通道
/// @param [in] idx         流序号,主子码流
/// @param [in] md_id       媒体自定义id
/// @return int 返回错误码
L_SDK_API int l_sdk_dec_bind(int dec_id, int login_id, int chnn, int idx, int md_id);


/// @brief 解除解码器的绑定
/// @param [in] dec_id      解码器id
/// @return int 返回错误码
L_SDK_API int l_sdk_dec_unbind(int dec_id);


/// @brief 获取解码控制之后的原始媒体数据: 例如,L_MDDT_YUV420P_SEPARATE格式
/// @param [in] dec_id          解码器id
/// @param [out] **p_md_data    输出媒体数据指针
/// @return int 返回错误码
/// @note 返回0.表示取到了数据, p_md_data有效
///  \n 返回非0.表示没有取到数据的错误信息
///  \n 如果为25-30帧, 则理论调用此函数频率为60, 否则会导致数据积压, 解码器会丢弃部分数据
///  \n 如果为60帧, 则理论调用此函数频率为120, 否则会导致数据积压, 解码器会丢弃部分数据
///  \n 调用函数表示调用者自行处理数据
///  \n 与函数l_sdk_dec_open_wnd()存在竞争数据关系
L_SDK_API int l_sdk_dec_get_md_data(int dec_id, l_md_data_t** p_md_data);


/// @brief 释放原始媒体数据
/// @param [in] dec_id          解码器id
/// @param [out] **p_md_data    输出媒体数据指针
/// @return int 返回错误码
L_SDK_API int l_sdk_dec_free_md_data(l_md_data_t* p_md_data);


/// @brief 在opengl环境中打开一个窗口
/// @param [in] dec_id          解码器id
/// @return int 返回错误码
/// @note 此函数必须在opengl线程下执行
///  \n 推荐使用于 android, ios
///  \n 与函数l_sdk_dec_get_md_data()存在竞争关系
L_SDK_API int l_sdk_dec_open_wnd(int dec_id);


/// @brief 在opengl环境中关闭窗口
/// @param [in] dec_id          解码器id
/// @return int 返回错误码
/// @note 此函数必须在opengl线程下执行
L_SDK_API int l_sdk_dec_close_wnd(int dec_id);


/// @brief 渲染视频图像
/// @param [in] dec_id          解码器id
/// @return int 返回错误码
/// @note 此函数必须在opengl线程下执行
///  \n 返回0.表示有数据渲染, 调用者需 再调用glFlush或SwapBuffers(hdc)等与系统相关函数刷新到物理显存
///  \n 返回非0.表示没有新数据
L_SDK_API int l_sdk_dec_render(int dec_id);


#if defined(__cplusplus)
}
#endif

#endif // __L_SDK_DEC_H__
//end
