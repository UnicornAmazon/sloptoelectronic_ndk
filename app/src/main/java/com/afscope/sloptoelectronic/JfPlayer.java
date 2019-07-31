package com.afscope.sloptoelectronic;

import android.util.Log;

public class JfPlayer {
    private JfGLSurfaceView jfGLSurfaceView;

    public void setJfGLSurfaceView(JfGLSurfaceView jfGLSurfaceView) {
        this.jfGLSurfaceView = jfGLSurfaceView;
    }

    /**
     *
     * @param width
     * @param height
     * @param y
     * @param u
     * @param v
     */
    public void onCallRenderYUV(int width,int height,byte[] y,byte[] u,byte[] v){
        JfLog.d("获取到视频的数据");
        if (jfGLSurfaceView != null) {
            jfGLSurfaceView.setYUVData(width, height, y, u, v);
        }
    }
}
