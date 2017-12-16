#version 460

out vec4 color;

in vec2 passTextureCoords;

uniform sampler2D ourTexture;

void main()
{
	color = texture(ourTexture, passTextureCoords);
}