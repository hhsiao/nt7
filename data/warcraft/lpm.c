// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m輸出文字中[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "bmw[2;37;0m
它是涼皮饃饃的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lpm");
        set("owner_name", "涼皮饃饃");
        set_temp("owner", "lpm");
        set_temp("owner_name", "涼皮饃饃");
        ::setup();
}
