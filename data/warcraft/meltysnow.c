// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀[2;37;0m[2;37;0m", ({"vermiliion"}));        
        set("gender", "女性");                
        set("long", "這就是傳說中的南方守護神獸朱雀。[2;37;0m
它是段融雪的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "meltysnow");
        set("owner_name", "段融雪");
        set_temp("owner", "meltysnow");
        set_temp("owner_name", "段融雪");
        ::setup();
}
