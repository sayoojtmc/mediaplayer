package com.example.sayooj.mediaplayer;

import android.media.MediaPlayer;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        Button play=findViewById(R.id.play);
        Button pause=findViewById(R.id.pause);
        Button stop=findViewById(R.id.stop);
        final MediaPlayer media=MediaPlayer.create(this, R.raw.song);

        play.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                media.start();
            }
        });
        pause.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                media.pause();

            }
        });
        stop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                media.seekTo(0);
                media.pause();
            }
        });
    }
}
