package com.hehu.ctrl;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import com.google.android.material.bottomnavigation.BottomNavigationView;
import androidx.appcompat.app.AppCompatActivity;
import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.navigation.ui.NavigationUI;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.net.ServerSocket;
import java.util.Scanner;


import java.io.IOException;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;



public class MainActivity extends AppCompatActivity {

    //String IP="192.168.0.101";
    int PORT=23333;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        BottomNavigationView navView = findViewById(R.id.nav_view);
        // Passing each menu ID as a set of Ids because each
        // menu should be considered as top level destinations.
        AppBarConfiguration appBarConfiguration = new AppBarConfiguration.Builder(
                R.id.navigation_home, R.id.navigation_dashboard, R.id.navigation_notifications)
                .build();
        NavController navController = Navigation.findNavController(this, R.id.nav_host_fragment);
        NavigationUI.setupActionBarWithNavController(this, navController, appBarConfiguration);
        NavigationUI.setupWithNavController(navView, navController);

       // new Thread(new Runnable() {
            //@Override
          //  public void run() {
         //       Waitting(tv);
         //   }
     //   }).start();

    }

    public void MUSICNEXTonClick(View view)
    {
        new Thread(new Runnable() {
            @Override
            public void run() {
                NEXT();
            }
        }).start();
    }

    public void LIGHTonClick(View view)
    {
        new Thread(new Runnable() {
            @Override
            public void run() {
                LIGHT();
            }
        }).start();
    }

    public void MUSICUPonClick(View view)
    {
        new Thread(new Runnable() {
            @Override
            public void run() {
                UP();
            }
        }).start();
    }

    public void REPLAYonClick(View view)
    {
        new Thread(new Runnable() {
            @Override
            public void run() {
                Replay();
            }
        }).start();
    }





    private EditText input;

    public void UP()
    {

        input=(EditText) findViewById(R.id.SongName);
        String IP=input.getText().toString();

        try {
            Socket socket = new Socket(IP, PORT);
            OutputStream os=socket.getOutputStream();
            PrintWriter pw=new PrintWriter(os);
            String info="up";
            pw.write(info);
            pw.flush();
            socket.shutdownOutput();
        }
        catch (UnknownHostException e) {
            //e.printStackTrace();
            return;
        } catch (IOException e) {
            //e.printStackTrace();
            return;
        }
    }

    public void LIGHT()
    {
        input=(EditText) findViewById(R.id.SongName);
        String IP=input.getText().toString();
        try {
            Socket socket = new Socket(IP, PORT);
            OutputStream os=socket.getOutputStream();
            PrintWriter pw=new PrintWriter(os);
            String info="light";
            pw.write(info);
            pw.flush();
            socket.shutdownOutput();
        }
        catch (UnknownHostException e) {
            //e.printStackTrace();
            return;
        } catch (IOException e) {
            //e.printStackTrace();
            return;
        }
    }


    public void NEXT()
    {        input=(EditText) findViewById(R.id.SongName);
        String IP=input.getText().toString();
        String back;
        try {
            Socket socket = new Socket(IP, PORT);
            OutputStream os=socket.getOutputStream();
            PrintWriter pw=new PrintWriter(os);
            InputStream is = socket.getInputStream();//字节输入流
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            String info="next";
            pw.write(info);
            pw.flush();
            socket.shutdownOutput();

        }
     catch (UnknownHostException e) {
        //e.printStackTrace();
         return;
    } catch (IOException e) {
        //e.printStackTrace();
            return;
    }


    }


    public void Replay()
    {        input=(EditText) findViewById(R.id.SongName);
        String IP=input.getText().toString();
        String back;
        try {
            Socket socket = new Socket(IP, PORT);
            OutputStream os=socket.getOutputStream();
            PrintWriter pw=new PrintWriter(os);
            InputStream is = socket.getInputStream();//字节输入流
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            String info="replay";
            pw.write(info);
            pw.flush();
            socket.shutdownOutput();

        }
        catch (UnknownHostException e) {
            //e.printStackTrace();
            return;
        } catch (IOException e) {
            //e.printStackTrace();
            return;
        }


    }

    public void Waitting(TextView tv)
    {

        while(true) {
            try {
                ServerSocket server;
                server = new ServerSocket(23333);
                Socket socket = server.accept();

                while (true) {
                    InputStream in;
                    try {
                        in = socket.getInputStream();
                        byte[] b = new byte[1024];
                        int len = 0;
                        StringBuffer sb = new StringBuffer();
                        String s = null;
                        if ((len = in.read(b)) != -1) {
                            s = new String(b);
                            sb.append(s);
                        }
                        OutputStream out = socket.getOutputStream();
                        String Main=sb.toString();



                        setContentView(R.layout.fragment_home);
                        tv.setText("Main2");

                    } catch (IOException e) {
                        // TODO Auto-generated catch block
                        e.printStackTrace();
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }



}
