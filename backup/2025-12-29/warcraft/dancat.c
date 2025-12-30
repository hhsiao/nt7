// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小雞[2;37;0m[2;37;0m", ({"jinhu"}));        
        set("gender", "男性");                
        set("long", "小雞[2;37;0m
它是蛋藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dancat");
        set("owner_name", "蛋藥");
        set_temp("owner", "dancat");
        set_temp("owner_name", "蛋藥");
        ::setup();
}
