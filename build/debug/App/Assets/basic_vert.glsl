#version 410

in vec3 vertexPosition;
in vec3 vertexColor;

out vecc3 Color;

void main()
{
     Color = vertexColor;
     gl_position = vec4(vertexPosition, 1.0);
}
