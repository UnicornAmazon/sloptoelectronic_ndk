package com.afscope.sloptoelectronic;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.opengl.GLSurfaceView;
import android.os.Environment;
import android.os.Handler;
import android.os.SystemClock;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.bumptech.glide.Glide;
import com.google.gson.Gson;

import java.io.File;
import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import static android.opengl.GLES20.glViewport;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    JfGLSurfaceView surfaceView;
    private OptoelecJinV2 optoelecJinV2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        optoelecJinV2 = new OptoelecJinV2();
        // Example of a call to a native method
        surfaceView = (JfGLSurfaceView) findViewById(R.id.gl);
//        Bugly.init(getApplicationContext(), "15b78da4a1", true);
        optoelecJinV2.sdkInit();
        Gson gson = new Gson();
        String s = gson.toJson(new LoginBean());
        int code = optoelecJinV2.login(s);
        int i = optoelecJinV2.decOpen();
        int i1 = optoelecJinV2.decBind();
        optoelecJinV2.streamRequest();
//        int lis = optoelecJinV2.mediaListener();
        File file = new File(Environment.getExternalStorageDirectory(), "test.h264");
//        int lis = optoelecJinV2.startRecord(file.getPath());
        Log.i("lixiang", "onCreate: " + code + i + i1);
//        surfaceView.setEGLContextClientVersion(2);
//
//        surfaceView.setRenderer(new GLSurfaceViewEx.Renderer() {
//            @Override
//            public void onSurfaceCreated(GL10 gl, EGLConfig config) {
//                int i = optoelecJinV2.openWnd();
//                Log.i("lixiang", "onSurfaceCreated: " + i);
//            }
//
//            @Override
//            public void onSurfaceChanged(GL10 gl, int width, int height) {
//                glViewport(0, 0, width, height);
//            }
//
//            @Override
//            public boolean onDrawFrame(GL10 gl) {
//                int render = optoelecJinV2.render();
//                return render == 0 ? true : false;
//            }
//        });

//        JfPlayer jfPlayer = new JfPlayer();
//        jfPlayer.setJfGLSurfaceView(surfaceView);
        Timer timer = new Timer();
        TimerTask task = new TimerTask() {
            @Override
            public void run() {
                synchronized (this) {
                    if (null != surfaceView)
                        surfaceView.getYuvMediaData();
                }
            }
        };
        timer.schedule(task, 0, 15);

    }

    public void click(View view) {
        Intent intent = new Intent(Intent.ACTION_GET_CONTENT);
        intent.setType("*/*");//无类型限制
        intent.addCategory(Intent.CATEGORY_OPENABLE);
        startActivityForResult(intent, 1);

    }

    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (resultCode == Activity.RESULT_OK) {
            if (requestCode == 1) {
                Uri uri = data.getData();
                String path = FileUtils.getFilePathByUri(this, uri);
                UpdateClient updateClient = new UpdateClient();
//                File file = new File(Environment.getExternalStorageDirectory(), "f701w_update_v1.0.7.lpk");
//                if (file.exists()) {
//                    Log.i("lixiang", "click: " + file.getPath());
//                }
                updateClient.path = path;
                int i = optoelecJinV2.clientRequestUpdate(new Gson().toJson(updateClient));
                Log.i("lixiang", "onClick: " + i);
            }
        }

    }
}
