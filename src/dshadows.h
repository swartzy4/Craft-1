
/*
Created by: Sean Gabringer
4/16/2020

Declaration of dynamic shadow rendering helper functions

Modified 4/23/2020
Created file and declared generateDepthMapFBO() and initDShadowDepthMap()



*/


#ifndef DSHADOWS_H_INCLUDED
#define DSHADOWS_H_INCLUDED

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <curl/curl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "auth.h"
#include "client.h"
#include "config.h"
#include "cube.h"
#include "db.h"
#include "item.h"
#include "map.h"
#include "matrix.h"
#include "noise.h"
#include "sign.h"
#include "tinycthread.h"
#include "util.h"
#include "world.h"


public:

    void generateDepthMapFBO(const unsigned int depthMapFBO);
    void initDShadowDepthMap( unsigned int& depthMap, const int SHADOW_DEPTH, const int SHADOW_HEIGHT);
	//void depthTest(unsigned int& depthMap);
	unsigned int createRenderBuffer(const int SHADOW_DEPTH, const int SHADOW_HEIGHT);
	void BindFramebufferAndRenderbuffer(unsigned int& frameBuffer, unsigned int& renderBuffer);


#endif // DSHADOWS_H_INCLUDED
