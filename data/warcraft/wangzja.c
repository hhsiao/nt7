// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛啊飛[2;37;0m[2;37;0m", ({"kalayo"}));        
        set("gender", "男性");                
        set("long", "飛啊飛[2;37;0m
它是懶哥米哦的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wangzja");
        set("owner_name", "懶哥米哦");
        set_temp("owner", "wangzja");
        set_temp("owner_name", "懶哥米哦");
        ::setup();
}
