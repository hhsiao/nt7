// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸十[2;37;0m[2;37;0m", ({"aar"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是由藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatr");
        set("owner_name", "由藥");
        set_temp("owner", "fatr");
        set_temp("owner_name", "由藥");
        ::setup();
}
