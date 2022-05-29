#pragma once

class Player {
public:
   // MuSeoun::vec2 coord;
    MuSeoun::vec2 quad[4];
    float size;
    MuSeoun::vec3 color;

    Player(float size_, float x_, float y_, MuSeoun::vec3 col)
    {
        size = 0.2;
        color = col;

        quad[0] = MuSeoun::vec2(-size, size);
        quad[1] = MuSeoun::vec2(size, size);
        quad[2] = MuSeoun::vec2(-size, -size);
        quad[3] = MuSeoun::vec2(size, -size);
    }
    ~Player()
    {

    }


    void Render(GLuint gluint)
    {
        if (gluint == NULL) {
            printf("출력불가");
            return;        //파일 읽기에 실패하면 프로그램 종료
        }
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

        glBindTexture(GL_TEXTURE_2D, gluint);
        glBegin(GL_TRIANGLES);
        glTexCoord2f(0.0, 0.0); glVertex3f(-quad[0].x,- quad[0].y, 0.0f);
        glTexCoord2f(1.0, 0.0); glVertex3f(-quad[1].x, -quad[1].y, 0.0f);
        glTexCoord2f(0.5, 1.0); glVertex3f(-quad[2].x, -quad[2].y, 0.0f);
     
        glEnd();
        //glFlush();
     
       
    }

};
