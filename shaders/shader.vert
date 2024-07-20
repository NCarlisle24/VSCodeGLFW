#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform float time;

out vec3 inColor;
out vec2 wallTexCoord;
out vec2 smileTexCoord;

void main() {
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    inColor = aColor;
    wallTexCoord = aTexCoord;
    smileTexCoord = aTexCoord;
}