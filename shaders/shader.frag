#version 330 core
out vec4 FragColor;

uniform float time;
uniform sampler2D texture1;

in vec3 inColor;
in vec2 inTexCoord;

void main() {
    FragColor = mix(texture(texture1, inTexCoord), vec4(inColor, 1.0), 0.2);
}