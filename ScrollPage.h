//
//  ScrollPage.h
//  PortraitScroll
//
//  Created by student on 16-1-7.
//
//

#ifndef __PortraitScroll__ScrollPage__
#define __PortraitScroll__ScrollPage__

#include <stdio.h>
#include <cocos2d.h>
#include <cocos-ext.h>
USING_NS_CC;
using namespace extension;
class ScrollPage:public ScrollView
{
private:
    float beginOffset;

public:
    static ScrollPage* create(Size size, Node* container = nullptr);
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchMoved(Touch *touch, Event *event);
    void onTouchEnded(Touch *touch, Event *event);
    void onTouchCancelled(Touch *touch, Event *event);
    void setTouchEnabledPage(bool enabled);
    void setTouchEnabled(bool enabled);
    
};
#endif /* defined(__PortraitScroll__ScrollPage__) */
