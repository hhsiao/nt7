// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m赤焰[5m[1;34m閃電獸[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹馬全身火炭般赤紅，追風逐電、神駿非常。[2;37;0m
它是尉遲恭的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yuchi");
        set("owner_name", "尉遲恭");
        set_temp("owner", "yuchi");
        set_temp("owner_name", "尉遲恭");
        ::setup();
}
