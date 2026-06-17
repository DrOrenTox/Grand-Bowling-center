#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(GrandBowlingManager, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Safely cast to CCMenu to avoid layout and node crashes on Android
        auto* bottomMenu = typeinfo_cast<CCMenu*>(this->getChildByID("bottom-menu"));
        if (bottomMenu) {
            auto* bowlingSprite = CCSprite::createWithSpriteFrameName("GJ_playBtn_001.png");
            
            if (bowlingSprite) {
                bowlingSprite->setColor({ 0, 255, 180 }); // Custom neon green/cyan
                bowlingSprite->setScale(0.4f); // Scale it down so it fits the bottom bar neatly

                auto* bowlingButton = CCMenuItemSpriteExtra::create(
                    bowlingSprite,
                    this,
                    menu_selector(GrandBowlingManager::onGrandBowlingTap)
                );

                if (bowlingButton) {
                    // Removed the broken _spr extension, using a safe string registration
                    bowlingButton->setID("grand-bowling-shortcut");
                    bottomMenu->addChild(bowlingButton);
                    bottomMenu->updateLayout();
                }
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

