#include <shader/shader.hpp>
#include <fstream>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Shader::Shader(const char* vertexFilePath, const char* fragmentFilePath) {
    std::string vertexShaderSourceText;
    std::string currentLine;
    std::ifstream vertexFile(vertexFilePath);

    if (!vertexFile.is_open()) {
        std::cout << "ERROR: Vertex file at path '" << vertexFilePath << "' not found." << std::endl;
    }

    while (std::getline(vertexFile, currentLine)) {
        vertexShaderSourceText += currentLine;
        vertexShaderSourceText.push_back('\n');
    }

    const char* vertexShaderSource = vertexShaderSourceText.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR: Vertex shader compilation failed.\n" << infoLog << std::endl;
    }

    vertexFile.close();


    std::string fragmentShaderSourceText;
    std::ifstream fragmentFile(fragmentFilePath);

    if (!fragmentFile.is_open()) {
        std::cout << "ERROR: Fragment file at path '" << fragmentFilePath << "' not found." << std::endl;
    }

    while (std::getline(fragmentFile, currentLine)) {
        fragmentShaderSourceText += currentLine;
        fragmentShaderSourceText.push_back('\n');
    }

    const char* fragmentShaderSource = fragmentShaderSourceText.c_str();

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR: Fragment shader compilation failed.\n" << infoLog << std::endl;
    }

    fragmentFile.close();


    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);

    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR: Shader program link failed.\n" << infoLog << std::endl;
    }

    glDeleteProgram(vertexShader);
    glDeleteProgram(fragmentShader);
}

void Shader::use() {
    glUseProgram(id);
}

void Shader::unuse() {
    glUseProgram(0);
}

void Shader::setUniform1f(const char* name, const float val) {
    glUniform1f(glGetUniformLocation(id, name), val);
}

void Shader::setUniform2f(const char* name, const float val1, const float val2) {
    glUniform2f(glGetUniformLocation(id, name), val1, val2);
}

void Shader::setUniform3f(const char* name, const float val1, const float val2, const float val3) {
    glUniform3f(glGetUniformLocation(id, name), val1, val2, val3);
}

void Shader::setUniform4f(const char* name, const float val1, const float val2, const float val3, const float val4) {
    glUniform4f(glGetUniformLocation(id, name), val1, val2, val3, val4);
}