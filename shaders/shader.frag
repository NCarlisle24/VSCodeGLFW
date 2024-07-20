#version 330 core
out vec4 FragColor;

uniform float time;
uniform sampler2D wallTexture;
uniform sampler2D smileTexture;

in vec3 inColor;
in vec2 wallTexCoord;
in vec2 smileTexCoord;

void main() {
    FragColor = mix(texture(wallTexture, wallTexCoord), texture(smileTexture, smileTexCoord), 0.2);
}