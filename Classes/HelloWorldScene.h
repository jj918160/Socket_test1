#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
//#include "cocos-ext.h"
#include "network/HttpClient.h"

USING_NS_CC;
//USING_NS_CC_EXT;
using namespace cocos2d::ui;

class HelloWorld : public cocos2d::Layer
{
public:
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    void menuHandler(Ref*);
    void httpResponse(cocos2d::network::HttpClient* client,cocos2d::network::HttpResponse*response);
    
    EditBox*edit_userName;
    bool 是否正确();
    EditBox*edit_userPassWord;
    Label*label3;
    Label*Label4;
    char strName[256];
    char strPassWOrd[256];
};

#endif // __HELLOWORLD_SCENE_H__
