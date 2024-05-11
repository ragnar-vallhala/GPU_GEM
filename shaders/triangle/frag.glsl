#version 460 core

out vec4 color;
in vec4 colorOut;
void main()
{
	color = colorOut;
}