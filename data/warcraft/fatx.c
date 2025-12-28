// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸柳[2;37;0m[2;37;0m", ({"aax"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是船藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatx");
        set("owner_name", "船藥");
        set_temp("owner", "fatx");
        set_temp("owner_name", "船藥");
        ::setup();
}
