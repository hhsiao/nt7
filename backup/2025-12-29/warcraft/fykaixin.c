// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "一個睡袋，江湖人士用來在野外睡覺用的。[2;37;0m
它是靈郭的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "fykaixin");
        set("owner_name", "靈郭");
        set_temp("owner", "fykaixin");
        set_temp("owner_name", "靈郭");
        ::setup();
}
