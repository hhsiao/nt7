// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸四[2;37;0m[2;37;0m", ({"aal"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是您藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatl");
        set("owner_name", "您藥");
        set_temp("owner", "fatl");
        set_temp("owner_name", "您藥");
        ::setup();
}
