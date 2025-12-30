// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雲霄飛車[2;37;0m[2;37;0m", ({"yunxiao"}));        
        set("gender", "女性");                
        set("long", "好玩的遊樂設施[2;37;0m
它是留連的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "liulian");
        set("owner_name", "留連");
        set_temp("owner", "liulian");
        set_temp("owner_name", "留連");
        ::setup();
}
