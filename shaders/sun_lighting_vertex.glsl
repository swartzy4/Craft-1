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
  ///
  ///checks if game time is after noon. Using 2 if statement because direct change to position
  /// is not allowed.
  ///
  vec4 afterNoonPos = vec4(0.0, 0.0, -768.0, 1.0);
  if(timer > 6)
  {
    if(position.y != -384)
      gl_Position = matrix * (position + afterNoonPos);
      frag_uv = uv;
  }
  gl_Position = matrix * position;
  frag_uv = uv;
}
