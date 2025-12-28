// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "幼年白虎 萌呆萌呆[2;37;0m
它是遊蝣遊蝣的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "youyou");
        set("owner_name", "遊蝣遊蝣");
        set_temp("owner", "youyou");
        set_temp("owner_name", "遊蝣遊蝣");
        ::setup();
}
