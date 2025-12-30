// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("拉布拉多[2;37;0m[2;37;0m", ({"kwride"}));        
        set("gender", "男性");                
        set("long", "這是一條純種拉布拉多[2;37;0m
它是王戰貳號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kingwarb");
        set("owner_name", "王戰貳號");
        set_temp("owner", "kingwarb");
        set_temp("owner_name", "王戰貳號");
        ::setup();
}
