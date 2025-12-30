// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("漫畫書[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "一本蠟筆小新一本蠟筆小新[2;37;0m
它是書中仙的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "book");
        set("owner_name", "書中仙");
        set_temp("owner", "book");
        set_temp("owner_name", "書中仙");
        ::setup();
}
