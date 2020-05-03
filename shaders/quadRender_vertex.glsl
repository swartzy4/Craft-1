#version 120

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

void main(){

	gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0); //no z coordinate, w scaling = 1.0
	TexCoord = a TexCoord;

}

