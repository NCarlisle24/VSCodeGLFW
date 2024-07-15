#version 330 core
out vec4 FragColor;

uniform float time;

void main() {
    FragColor = vec4(0.5 * sin(time * 3), 0.5f, 0.2f, 1.0f);
}