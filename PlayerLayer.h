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

	//��ʼ����ǰ��
	virtual bool init();
	CREATE_FUNC(PlayerLayer);
	//���ػ��ƺ���
	virtual void draw(Renderer* renderer, const Mat4 &transform, uint32_t flags);

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

protected:

	Sprite3D* _player;
	Animate3D* _idle; //��ɢ����

	Vec2 startpoint; //��ʼ�˶�����

};



#endif