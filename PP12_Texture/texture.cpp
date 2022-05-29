#define _CRT_SECURE_NO_WARNINGS

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#include "MMath.hpp"
#include "Player.hpp"

#pragma comment(lib, "OpenGL32")

static GLuint texName[2];
//Player* p = new Player(0.1f, 0.9f, 0.9f, MuSeoun::vec3(1.0f, 0.0f, 0.0f));
//Player* e = new Player(-0.3f, 0.0f, 0.0f, MuSeoun::vec3(0.0f, 0.0f, 1.0f));
//��Ʈ�� ����� �� �������� �ٽ� ����ü�� �������. �Լ�ó���� ���ϰ� �Ϸ�����.
typedef struct tagBITMAPHEADER {
    BITMAPFILEHEADER bf;
    BITMAPINFOHEADER bi;
    RGBQUAD hRGB[256];
}BITMAPHEADER;

BYTE* LoadBitmapFile(BITMAPHEADER* bitmapHeader, int * imgSize, const char* filename2, int number)
{
    FILE* fp = fopen(filename2, "rb");	//������ �����б���� ����
    if (fp == NULL)
    {
        printf("���Ϸε��� �����߽��ϴ�.\n");	//fopen�� �����ϸ� NULL���� ����
        return NULL;
    }
    else
    {
        fread(&bitmapHeader->bf, sizeof(BITMAPFILEHEADER), 1, fp);	//��Ʈ��������� �б�
        fread(&bitmapHeader->bi, sizeof(BITMAPINFOHEADER), 1, fp);	//��Ʈ��������� �б�
        fread(&bitmapHeader->hRGB, sizeof(RGBQUAD), 256, fp);	//�����ȷ�Ʈ �б�

        int imgSizeTemp = bitmapHeader->bi.biWidth * bitmapHeader->bi.biHeight;	//�̹��� ������ ���
        *imgSize = imgSizeTemp;	// �̹��� ����� ���� ������ �Ҵ�

        BYTE* image = (BYTE*)malloc(sizeof(BYTE) * imgSizeTemp);	//�̹���ũ�⸸ŭ �޸��Ҵ�
        fread(image, sizeof(BYTE), imgSizeTemp, fp);//�̹��� ũ�⸸ŭ ���Ͽ��� �о����
        fclose(fp);

        return image;
    }
}




void init(int number2, const char* filename,int width,int height)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    BITMAPHEADER originalHeader;	//��Ʈ���� ����κ��� ���Ͽ��� �о� ������ ����ü
    int imgSize;			//�̹����� ũ�⸦ ������ ����
    BYTE* image = LoadBitmapFile(&originalHeader, &imgSize,filename,number2); //��Ʈ�������� �о� ȭ�������� ����
    if (image == NULL) {
        printf("��ºҰ�2");
        return;        //���� �б⿡ �����ϸ� ���α׷� ����
    }
    glPixelStorei(GL_UNPACK_ALIGNMENT, number2);

    glGenTextures(number2, &texName[number2-1]);
    glBindTexture(GL_TEXTURE_2D, texName[number2-1]);

    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);
        
    glTexImage2D(GL_TEXTURE_2D,0 ,GL_RGBA, width, height,0,GL_RED, GL_BYTE, image);

}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    
    init(1, "cocato.bmp", 1280, 841);
    init(2, "lena_gray.bmp", 512, 512);

    while (!glfwWindowShouldClose(window))
    {
   
      //  p->Render(texName[0]);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glBindTexture(GL_TEXTURE_2D, texName[0]);
        glBegin(GL_TRIANGLES);
        glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
        glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
        glTexCoord2f(0.5, 1.0); glVertex3f(0.0, 1.0, 0.0);

        glEnd();
      //  glFlush();
       // glDisable(GL_TEXTURE_2D);
 
        //e->Render(texName[1]);
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     //   glEnable(GL_TEXTURE_2D);
       //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glBindTexture(GL_TEXTURE_2D, texName[1]);
        glBegin(GL_TRIANGLES);
        glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 1.0, 0.0);
        glTexCoord2f(1.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
        glTexCoord2f(0.5, 1.0); glVertex3f(1.0, 1.0, 0.0);

        glEnd();
      //  glFlush();
        glDisable(GL_TEXTURE_2D);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
  
    glfwDestroyWindow(window);
    glfwTerminate();
    //delete(p);
   // delete(e);
    exit(EXIT_SUCCESS);
}