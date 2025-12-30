// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "一隻黑白相間的老虎[2;37;0m
它是張三的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "wdgold");
        set("owner_name", "張三");
        set_temp("owner", "wdgold");
        set_temp("owner_name", "張三");
        ::setup();
}
