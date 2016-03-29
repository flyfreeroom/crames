#ifndef  _PLAYERLAYER_H_
#define  _PLAYERLAYER_H_
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "PlayerLayer.h"
USING_NS_CC;
using namespace CocosDenshion;

class PlayerLayer :public cocos2d::Layer
{
public:
	PlayerLayer();
	~PlayerLayer();

	//初始化当前层
	virtual bool init();
	CREATE_FUNC(PlayerLayer);
	//重载绘制函数
	virtual void draw(Renderer* renderer, const Mat4 &transform, uint32_t flags);

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

protected:

	Sprite3D* _player;
	Animate3D* _idle; //闲散动作

	Vec2 startpoint; //开始运动触点

};



#endif