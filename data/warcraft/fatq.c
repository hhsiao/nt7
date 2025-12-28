// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸九[2;37;0m[2;37;0m", ({"aaq"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是名藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatq");
        set("owner_name", "名藥");
        set_temp("owner", "fatq");
        set_temp("owner_name", "名藥");
        ::setup();
}
