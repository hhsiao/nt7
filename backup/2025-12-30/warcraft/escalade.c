// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m大力神運輸機[2;37;0m[2;37;0m", ({"plane"}));        
        set("gender", "男性");                
        set("long", "美製大力神運輸機[2;37;0m
它是凱雷德的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "escalade");
        set("owner_name", "凱雷德");
        set_temp("owner", "escalade");
        set_temp("owner_name", "凱雷德");
        ::setup();
}
