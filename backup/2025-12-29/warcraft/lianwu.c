// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("碰碰車[2;37;0m[2;37;0m", ({"peng"}));        
        set("gender", "女性");                
        set("long", "遊樂設施[2;37;0m
它是蓮務的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lianwu");
        set("owner_name", "蓮務");
        set_temp("owner", "lianwu");
        set_temp("owner_name", "蓮務");
        ::setup();
}
