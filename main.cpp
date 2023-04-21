#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <windows.h>
#include <SFML/Audio.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include "Movement.h"
#pragma comment(lib, "winmm.lib")

// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,	0.0f, 0.0f, // Lower left corner
	-0.5f,  0.5f, 0.0f,     0.0f, 1.0f, 0.0f,	0.0f, 1.0f, // Upper left corner
	 0.5f,  0.5f, 0.0f,     0.0f, 0.0f, 1.0f,	1.0f, 1.0f, // Upper right corner
	 0.5f, -0.5f, 0.0f,     1.0f, 1.0f, 1.0f,	1.0f, 0.0f  // Lower right corner
};

GLuint indices[] =
{
	0, 2, 1, // Upper triangle
	0, 3, 2 // Lower triangle
};

Movement character;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	character.key_cb(window, key, action);
}

void PlaySound()
{

	sf::Music music;
	music.openFromFile("C:/Users/Angel/source/repos/RockTheStick/fullBattleTheme.wav");
		
	music.play();
}


int main()
{
	char buffer[MAX_PATH];
	DWORD len = GetCurrentDirectoryA(MAX_PATH, buffer);
	if (len == 0) {
		std::cerr << "Failed to get current directory" << std::endl;
		return 1;
	}

	std::cout << "Current Directory: " << buffer << std::endl;
	//GLFW initialize
	glfwInit();

	//glfw Version set
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//using Core Profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Create a window
	GLFWwindow* window = glfwCreateWindow(800, 800, "RockTheStick", NULL, NULL);
	//Window error check
	if (window == NULL)
	{
		std::cout << "Failed to create a GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, 800, 800);

	glClearColor(0.07f, 0.13f, 0.17, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);


	//int widthImg, heightImg, numColch;
	//unsigned char* bytes = stbi_load("bg.jpg", &widthImg, &heightImg, &numColch, 0);

	//GLuint texture;
	//glGenTextures(1, &texture);
	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, texture);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
	//glGenerateMipmap(GL_TEXTURE_2D); 

	//stbi_image_free(bytes);
	//glBindTexture(GL_TEXTURE_2D, 0);

	//While events are going on in window, show the window
	
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window))
	{
		PlaySound();
		float delta = 0.01f;
		character.update(delta);
		glClearColor(0.07f, 0.13f, 0.17, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
		
	}

	/*glDeleteTextures(1, &texture);*/
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}