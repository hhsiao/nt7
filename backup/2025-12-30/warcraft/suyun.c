// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("情獸[2;37;0m[2;37;0m", ({"qing"}));        
        set("gender", "女性");                
        set("long", "情獸[2;37;0m
它是上官雲的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "suyun");
        set("owner_name", "上官雲");
        set_temp("owner", "suyun");
        set_temp("owner_name", "上官雲");
        ::setup();
}
