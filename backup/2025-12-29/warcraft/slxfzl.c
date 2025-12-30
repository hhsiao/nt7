// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"wmm"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是紫楓殘雲的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "slxfzl");
        set("owner_name", "紫楓殘雲");
        set_temp("owner", "slxfzl");
        set_temp("owner_name", "紫楓殘雲");
        ::setup();
}
