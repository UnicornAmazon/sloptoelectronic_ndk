package com.afscope.sloptoelectronic;

public class LoginBean {
    String ip = "192.168.3.160";
    int port = 80;
    Login login=new Login();

    class Login {
        String username = "admin";
        String passwd = "123456";
    }

}
