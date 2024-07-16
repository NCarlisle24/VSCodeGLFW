#version 330 core
out vec4 FragColor;

uniform float time;

in vec3 inColor;

void main() {
    FragColor = vec4(inColor, 1.0);
}