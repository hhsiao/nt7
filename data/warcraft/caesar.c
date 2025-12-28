// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("克利奧帕特拉[2;37;0m[2;37;0m", ({"axx"}));        
        set("gender", "男性");                
        set("long", "sadasdas[2;37;0m
它是凱撒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "caesar");
        set("owner_name", "凱撒");
        set_temp("owner", "caesar");
        set_temp("owner_name", "凱撒");
        ::setup();
}
