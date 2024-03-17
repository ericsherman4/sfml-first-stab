#version 460

out vec4 FragColor

// input from the vertex shader
in vec4 vertexColor;

void main()
{
	FragColor = vertexColor;
}