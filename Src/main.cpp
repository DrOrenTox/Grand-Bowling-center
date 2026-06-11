#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(GrandBowlingManager, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto* bottomMenu = this->getChildByID("bottom-menu");
        if (bottomMenu) {
            auto* bowlingSprite = CCSprite::createWithSpriteFrameName("GJ_everyplayBtn_001.png");
            if (bowlingSprite) {
                bowlingSprite->setColor({ 0, 255, 180 }); 
            }

            auto* bowlingButton = CCMenuItemSpriteExtra::create(
                bowlingSprite,
                this,
                menu_selector(GrandBowlingManager::onGrandBowlingTap)
            );

            if (bowlingButton) {
                bowlingButton->setID("grand-bowling-shortcut"_spr);
                bottomMenu->addChild(bowlingButton);
                bottomMenu->updateLayout();
            }
        }
        return true;
    }

    void onGrandBowlingTap(CCObject* sender) {
        FLAlertLayer::create(
            "Grand Bowling Center",
            "Welcome to the Grand Lanes. Project active and verified.",
            "Proceed"
        )->show();
    }
};
