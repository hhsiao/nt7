// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸八[2;37;0m[2;37;0m", ({"aap"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是大藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatp");
        set("owner_name", "大藥");
        set_temp("owner", "fatp");
        set_temp("owner_name", "大藥");
        ::setup();
}
