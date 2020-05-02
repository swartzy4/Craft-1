/*
Created by: Sean Gabringer
4/16/2020

Definition of helper functions for dynamic shadow rendering


Last Modified 4/23/2020
- Created file
- Created and written generateDepthMapFBO() and initDShadowDepthMap()




*/




#include "dshadows.h"

void generateDepthMapFBO(const unsigned int depthMapFBO){

    glGenFramebuffers(1, &depthMapFBO);

};

void initDShadowDepthMap(unsigned int& depthMap, unsigned int& depthMapFBO const int SHADOW_DEPTH, const int SHADOW_HEIGHT)(){

    glGenTexture(1, &depthMap);
    glBindTexture(GL_TEXTURE_2D, depthMap);
    glTexImage2D(GL_TEXTURE_2D, 0 ,GL_DEPTH_COMPONENT, SHADOW_DEPTH, SHADOW_HEIGHT,GL_DEPTH_COMPONENT, GL_FLOAT, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

unsigned int createRenderBuffer(const int SHADOW_DEPTH, const int SHADOW_HEIGHT){
		
	unsigned int RBO;
	
	glGenRenderbuffers(1, &RBO);
	glBindRenderbuffer(GL_RENDERBUFFER, RBO);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, SHADOW_DEPTH, SHADOW_HEIGHT); //if framebuffer errors, internalformat change?
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	
	// malloc(RBO)?
	
	return RBO;
}

void BindFramebufferAndRenderbuffer(unsigned int& frameBuffer, unsigned int& renderBuffer){
	
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderBuffer);
	
	//check if framebuffer is complete
	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
		//inform whoever that there is an issue with the framebuffer
		std::cout << "ERROR: Framebuffer for depth map rendering incomplete. dshadows.c for framebuffer generation" << std::endl;
	}
	
	glBindFrameBuffer(GL_FRAMEBUFFER, frameBuffer);
	
}