// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m京香[2;37;0m[2;37;0m", ({"julia"}));        
        set("gender", "女性");                
        set("long", "julia[2;37;0m
它是大白鯊的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "darkula");
        set("owner_name", "大白鯊");
        set_temp("owner", "darkula");
        set_temp("owner_name", "大白鯊");
        ::setup();
}
