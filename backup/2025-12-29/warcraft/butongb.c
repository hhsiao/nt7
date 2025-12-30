// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("避水金晶獸[2;37;0m[2;37;0m", ({"mos"}));        
        set("gender", "女性");                
        set("long", "一頭避水金晶獸[2;37;0m
它是週日月的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "butongb");
        set("owner_name", "週日月");
        set_temp("owner", "butongb");
        set_temp("owner_name", "週日月");
        ::setup();
}
