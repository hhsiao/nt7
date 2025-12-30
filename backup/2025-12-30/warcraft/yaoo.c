// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸[2;37;0m[2;37;0m", ({"yaoos"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是師份的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yaoo");
        set("owner_name", "師份");
        set_temp("owner", "yaoo");
        set_temp("owner_name", "師份");
        ::setup();
}
