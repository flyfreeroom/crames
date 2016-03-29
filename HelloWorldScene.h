#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	virtual void playBackgroundMusic(const char* pszFilePath, bool bLoop); //播放背景音乐，bLoop表示是否要循环播放
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void startGame();
};

#endif // __HELLOWORLD_SCENE_H__
