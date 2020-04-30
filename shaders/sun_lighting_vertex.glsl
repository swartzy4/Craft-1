//////////////////////////////////////////////////////////////////////////////////////////
///This code is the vertex shader for the sun source
///We chose directional lighting because we felt that it was easier to implement
///to the scene as a whole. This directional lighting will be impletented in time
///as well as a shader program for the shadow map.
#version 120


attribute vec4 position;
attribute vec3 normal;
attribute vec2 uv;
//Keeping these 2 for now, will delete if not needed
uniform vec4 timerPos;
uniform int timer;


varying vec2 frag_uv;
uniform mat4 matrix;

void main()
{
  gl_Position = matrix * position;
  frag_uv = uv;

/*
    if(position.y == -1) {
    gl_Position = matrix * (position + timerPos + angleVector);
    frag_uv = uv;
  } else {
    gl_Position = matrix * (position + timerPos);
    frag_uv = uv;
  }
  */
}
