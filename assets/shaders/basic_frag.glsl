#version 410 core
out vec4 FragColor;

in vec3 Normal;
in vec2 TexCoord;

void main()
{
    // Simple color based on normal
    vec3 color = Normal * 0.5 + 0.5;
    FragColor = vec4(color, 1.0);
}