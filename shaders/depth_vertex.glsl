#version 120

layout (location = 0) in vec3 aPos;

uniform mat4 lightSpaceMatrix; //matrix to make the transform
uniform mat4 model;

void main(){

	lightspace_position = lightSpaceMatrix * model *vec4(aPos, 1.0); //create a position vector with w = 1.0

}

