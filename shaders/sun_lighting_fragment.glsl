////////////////////////////////////////////////////////////////////////////////////////
///This code is setting up our sun fragment shader
/// Update 03/27: Need to change this file and frag files variables and/or way to
///access them. Or if the right attributes were asigned to the attrib struct variables then
///it would work but the confusion would suck. Possibly add more variable to struct Attrib?
///Use those and bind them to values on creation
///might not need viewPos or even Material struct. For now just focus on the block in the
///sky, the rest will come later, hopefully, not sure if running this with the light
///aspects in would work, possibly comment them out until needed? End update 03/27
#version 120

uniform sampler2D sampler;
//uniform float frag_timer;

varying vec2 frag_uv;

void main()
{
    vec4 color = texture2D(sampler, frag_uv);
    ///
    ///Sun is now a circle rather than a cube
    ///checking alpha value in vector color to see if it is a dark color. If it is, discard it.
    ///
    if(color.a < 0.1)
      discard;
    gl_FragColor = color;


}
