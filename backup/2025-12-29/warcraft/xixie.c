// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("誒飛翔[2;37;0m[2;37;0m", ({"xixieee"}));        
        set("gender", "女性");                
        set("long", "自由的飛翔[2;37;0m
它是習誒的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xixie");
        set("owner_name", "習誒");
        set_temp("owner", "xixie");
        set_temp("owner_name", "習誒");
        ::setup();
}
