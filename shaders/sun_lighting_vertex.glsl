//////////////////////////////////////////////////////////////////////////////////////////
///This code is the vertex shader for the lighting effects from the sun source
///We chose directional lighting because we felt that it was easier to implement
///to the scene as a whole
#version 120


attribute vec4 position;
attribute vec3 normal;
attribute vec2 uv;

varying vec2 frag_uv;
uniform mat4 matrix;

void main()
{

    gl_Position = matrix * position;
    frag_uv = uv;
}
