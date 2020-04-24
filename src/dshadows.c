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

    glGenFramebuffers(1, &depthMap);

};

unsigned int initDShadowDepthMap(unsigned int& depthMap, unsigned int& depthMapFBO const int SHADOW_DEPTH, const int SHADOW_HEIGHT)(){

    glGenTexture(1, &depthMap);
    glBindTexture(GL_TEXTURE_2D, depthMap);
    glTexImage2D(GL_TEXTURE_2D, 0 ,GL_DEPTH_COMPONENT, SHADOW_DEPTH, SHADOW_HEIGHT,GL_DEPTH_COMPONENT, GL_FLOAT, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
    glFramebufferTExture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
